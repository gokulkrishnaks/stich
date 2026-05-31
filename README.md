# STICH
**Secure Thread Integration and Canonical Communication Hub**

STICH is a canonical integration runtime for edge-native environments. It receives data from heterogeneous hardware protocols, transforms that data into a common canonical representation, moves it through a controlled internal fabric, and delivers it to higher-level software — without interpreting what that data means in a business or domain context.

STICH is infrastructure. It is not an application, a workflow engine, or an analytics platform. Domain decisions belong in the consuming system.

> STICH translates heterogeneous protocols into a canonical frame representation, moves that representation through a controlled transport fabric, and delivers it to external consumers without interpreting domain meaning.

---

## Quick Start

| Action | Command |
|--------|---------|
| Build  | `make` |
| Run    | `make run` |
| Test   | `make test` |
| Clean  | `make clean` |

**Branches**
- `main` — v0 PoC, reference only, do not modify
- `v0.1` — first running runtime, active development

---

## What STICH Is Not

Understanding what STICH explicitly refuses to be is as important as understanding what it is.

| STICH is not... | Why this matters |
|---|---|
| A workflow engine | STICH does not make decisions based on data values. That logic lives in the consumer. |
| An event broker | STICH owns no frame history, no replay, no retention. Consumers own their own state. |
| A message queue | STICH is a transport fabric, not a persistence layer. |
| A domain model | STICH does not understand temperature, RPM, pressure, or any domain-specific concept. |
| An application platform | The moment STICH makes domain decisions, it has become a different product. |

The test for any proposed feature:

> Does this require STICH to know what the data means? If yes — it does not belong in STICH.

---

## Architecture

Three principles govern every design decision in STICH:

| Principle | Owner |
|---|---|
| Meaning is governed by Canonical | `canonical/` |
| Movement is governed by Thread | `thread/` |
| Translation is governed by Adapters | `adapters/` |

The frame journey:

```
External Protocols
        │
        ▼
    Adapters      — translate protocol bytes into candidate frames
        │
        ▼
    Canonical     — validate and normalize into sealed canonical frames
        │
        ▼
     Thread       — route and deliver frames to registered sinks
        │
        ▼
      Sinks        — deliver frames to consuming systems
        │
        ▼
    Consumers     — interpret payload; domain meaning lives here
```

---

## The Frame

A frame is the atomic unit of canonical meaning inside STICH. It is a fully self-describing data object with structural identity and an opaque payload. Once a frame exits normalization, it is sealed and immutable.

```c
typedef struct {
    uint32_t            id;            /* unique within runtime session  */
    stich_frame_kind_t  kind;          /* telemetry, command, ack, error */
    stich_frame_state_t state;         /* lifecycle state                */
    uint64_t            timestamp_us;  /* UTC microseconds at ingress    */
    uint32_t            source;        /* identity ref                   */
    uint32_t            schema;        /* schema ref                     */
    uint8_t             payload[STICH_PAYLOAD_MAX];
    size_t              payload_len;
} stich_frame_t;
```

Thread reads `kind`, `schema`, `source`, and `state`. Thread never reads `payload`. Payload meaning belongs to the consumer.

---

## Frame Lifecycle

```
CANDIDATE    — adapter constructs frame; mutable
    │
    │  validation
    ▼
CANONICAL    — frame sealed; immutable from this point forward
    │
    │  thread/router
    ▼
ROUTING      — destination resolved
    │
    │  thread/delivery
    ▼
DELIVERING   — in-flight to sink
    │
    ├── success ──▶ DELIVERED ──▶ released
    └── failure ──▶ DEAD      ──▶ dead-lettered, released
```

---

## Repository Structure

```
STICH-runtime/
│
├── canonical/
│   ├── envelope/         ← stich_frame_t, enums, frame init helper
│   ├── validation/       ← schema check, field check, state guard
│   └── normalization/    ← timestamp, seal frame as CANONICAL
│
├── thread/
│   └── router/           ← resolve (source, kind, schema) → sink
│
├── adapters/
│   └── fake/             ← deterministic test frame emitter
│
├── sinks/
│   └── stdout/           ← v0.1 delivery sink
│
├── tests/                ← end-to-end frame journey test
│
├── Makefile
└── main.c                ← wires all subsystems, runs frame journey
```

---

## Architectural Laws

These are not guidelines. They are containment boundaries. A proposed change that requires qualifying any of these with "except when" is an architectural change proposal, not an implementation decision.

| # | Law | Statement |
|---|---|---|
| L1 | Canonical defines truth | No subsystem outside `canonical/` defines what constitutes a valid frame |
| L2 | Canonical is domain-agnostic | Canonical knows schema refs and frame kinds; it never knows any domain concept |
| L3 | Normalization is deterministic | Same input always produces the same output; no external state dependency |
| L4 | Thread moves truth | `thread/` reads kind, schema, source, state — never payload |
| L5 | Orchestration is transport-semantic | May branch on frame_kind and schema_ref; never on payload field values |
| L6 | Adapters translate only | Adapter responsibility ends at emitting a candidate frame |
| L7 | Sinks deliver only | Sinks never interpret payload meaning |
| L8 | STICH pushes; consumers own history | STICH owns no frame retention, replay, or query capability |
| L9 | Business logic stays external | Domain decisions live in consuming systems; STICH is infrastructure |

---

## Coding Style

- Module prefix on all public symbols: `stich_router_resolve()`, `stich_frame_init()`
- `_t` suffix on all typedefs: `stich_frame_t`, `stich_adapter_ops_t`
- `STICH_` prefix on all public macros and enum values
- `_MAX` suffix on buffer size constants: `STICH_PAYLOAD_MAX`
- Return `0` for success, `-1` for error — consistent everywhere
- NULL-check all pointer arguments at the top of every public function
- Zero-initialise frames before filling — always call `stich_frame_init()`
- No heap allocation in the frame path — fixed-size stack buffers only

---

## Versioning

| Tag | Branch | Description |
|---|---|---|
| `v0.0-poc` | `main` | PoC scaffold. MQTT adapter, event loop, structured logger. Proves vtable adapter pattern. Reference only — do not modify. |
| `v0.1` | `v0.1` | First running runtime. Canonical frame travels from fake adapter through validation, normalization, routing, and stdout sink. |

The definition of v0.1 complete:

> A frame moves from a fake adapter through canonical validation and normalization, is routed by thread, and is delivered to a stdout sink without violating any architectural law. When that works, STICH is a runtime — not just a specification.

---

## What Is Deferred

These are real concerns intentionally postponed beyond v0.1:

- Frame pool allocator (stack allocation in v0.1)
- Identity registry (hardcoded source constant in v0.1)
- Schema file loading (hardcoded schema constant in v0.1)
- Full routing table (one hardcoded route in v0.1)
- Security enforcement
- Multi-sink delivery
- Unix socket sink
- Retry and acknowledgement tracking
- Structured observability beyond stderr

---

## Project Status

STICH has completed its PoC phase (`v0.0-poc`) and is in active implementation of `v0.1` — the first running runtime.

| Component | Status |
|---|---|
| `canonical/envelope/` | complete |
| `canonical/validation/` | complete |
| `canonical/normalization/` | complete |
| `adapters/fake/` | in progress |
| `thread/router/` | pending |
| `sinks/stdout/` | pending |
| `main.c` | pending |
| `Makefile` | pending |
| End-to-end test | pending |