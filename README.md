# STICH v0 - PoC
## Secure Thread Integration & Canonical Communication Hub

STICH is an experimental edge-native runtime designed for coordinating heterogeneous systems through canonical operational communication. This is a Proof of Concept version.

The project focuses on:
- protocol abstraction
- event routing
- runtime coordination
- edge-native interoperability

across:
- embedded systems
- industrial devices
- telemetry pipelines
- operational services
- cyber-physical infrastructure

---

# Overview

Modern operational environments often consist of:
- multiple communication protocols
- fragmented device ecosystems
- tightly coupled integrations
- inconsistent operational interfaces

STICH explores a runtime-oriented approach where communication is normalized into canonical operational events at the edge.

The runtime acts as an intermediary layer between:
- devices
- protocols
- operational services
- external applications

without coupling those systems to specific implementations.

---

# Architecture

```text
  ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
  
   ┌─────────────────┐       ┌─────────────────┐       ┌─────────────────┐       ┌─────────────────┐       ┌─────────────────┐
   │ DEVICES / SYST. │       │   PROTOCOL      │       │  STICH RUNTIME  │       │ CANONICAL OPER. │       │ EXT. SERVICES / │
   │ ─── ─── ─── ─── │       │   ADAPTERS      │       │ ─── ─── ─── ─── │       │     EVENTS      │       │  APPLICATIONS   │
   │  [📟] Sensors   │      │  [🔌] MQTT       │      │  [⚙️] Ingest     │      │ [📑] Normalized │       │  [📊] Analytics │
   │  [🏭] PLCs      │ ───> │  [📡] Modbus     │ ───> │  [🔄] Normalize  │ ───> │ [🏷️] Schema-Fit │ ───>  │  [🖥️] Dashboards│
   │  [🌐] Edge Node │      │  [📶] BLE        │      │  [🔀] Route      │      │ [📦] Structured │       │  [🔔] Alarms    │
   └─────────────────┘       └─────────────────┘       └─────────────────┘       └─────────────────┘       └─────────────────┘
  
  ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
```
---

# Inbound/Outbound Flow

```text

     INBOUND TELEMETRY FLOW                          OUTBOUND COMMAND FLOW  
                                             
       ┌──────────────────┐                           ┌──────────────────┐
       │ Sensors / Devices│                           │ User / Services  │
       └────────┬─────────┘                           │ Automation Logic │
                │                                     │ Operational APIs │
                ▼                                     └────────┬─────────┘
       ┌──────────────────┐                                    │
       │ Protocol Adapter │                                    ▼
       ┌──────────────────┐                           ┌──────────────────┐
       │ Protocol Adapter │                           │ Canonical Command│
       │ MQTT / Modbus    │                           │ Generation       │
       │ BLE / Serial     │                           └────────┬─────────┘
       └────────┬─────────┘                                    │
                │                                              ▼
                ▼                                     ┌──────────────────┐
       ┌──────────────────┐                           │  STICH Runtime   │
       │  STICH Runtime   │                           │ Command Routing  │
       │ Event Ingestion  │                           │ Runtime Handling │
       │ Normalization    │                           └────────┬─────────┘
       │ Routing          │                                    │
       └────────┬─────────┘                                    ▼
                │                                     ┌──────────────────┐
                ▼                                     │ Protocol Adapter │
       ┌──────────────────┐                           │ MQTT / Modbus    │
       │ Canonical Events │                           │ BLE / Serial     │
       └────────┬─────────┘                           └────────┬─────────┘
                │                                              │
                ▼                                              ▼
       ┌──────────────────┐                           ┌──────────────────┐
       │ Services / APIs  │                           │ Actuators / Edge │
       │ Analytics / UI   │                           │ Controllers      │
       │ Automation       │                           └──────────────────┘
       └──────────────────┘


	   
```

---

# Core Runtime Responsibilities

The STICH runtime is responsible for:
- event ingestion
- canonical normalization
- runtime routing
- command distribution
- node coordination
- runtime state handling
- operational observability

---

# Canonical Communication Model

STICH internally operates using normalized operational primitives rather than protocol-specific payloads.

Examples include:
- telemetry events
- actuator commands
- runtime state updates
- alerts
- node status events

This allows external systems to interact through a consistent operational model independent of transport or device implementation.

---

# Adapter Layer

STICH uses adapter-based communication boundaries.

Adapters are responsible for:
- protocol translation
- transport integration
- payload normalization
- runtime communication bridging

Initial reference implementations may include:
- MQTT
- Modbus
- BLE
- serial communication
- custom TCP transports

The runtime itself remains transport-independent.

---

# External Services

STICH does not define application or business logic.

Operational services may implement:
- automation
- analytics
- monitoring
- orchestration
- visualization
- machine learning
- domain-specific workflows

These services may be written using different languages and runtimes depending on deployment and operational requirements.

---

# Deployment Model

STICH is primarily designed for:
- edge-native operation
- local-first environments
- constrained infrastructure
- unreliable connectivity conditions

The runtime is intended to remain:
- lightweight
- portable
- observable
- minimally dependent on external infrastructure

---

# MVP Scope

The initial MVP focuses on validating:
- protocol adapter abstraction
- canonical event ingestion
- runtime event routing
- command distribution
- local runtime coordination
- operational telemetry handling

using:
- lightweight edge deployment
- minimal runtime complexity
- real operational environments

---

# Development Direction

Current development areas include:
- runtime core architecture
- canonical event systems
- protocol adapters
- telemetry routing
- runtime coordination
- operational observability
- edge deployment experimentation

Future exploration areas may include:
- stronger runtime security
- distributed coordination
- runtime observability systems
- industrial interoperability
- runtime extensibility

---

# Repository Status

The repository now contains the initial PoC scaffold described by the internal
file structure document.

Implemented first-pass runtime areas:
- `runtime/core`
- `runtime/events`
- `runtime/adapters/mqtt`
- `runtime/observability`
- `runtime/utils`

Scaffolded but intentionally lightweight:
- `runtime/transport`
- `runtime/runtime-state`
- `interfaces`
- `tests`
- `examples`
- `deployments`

---

# Quick Start

Build the runtime:

```bash
./scripts/build.sh
```

Run the runtime:

```bash
./scripts/run.sh
```

Execute the smoke test:

```bash
./scripts/test.sh
```

---

# Repository Boundary

`STICH/` is intended to be the public project root.

Project-facing assets stay inside this directory:
- source code
- build scripts
- tests
- deployment files
- public documentation

AI tooling metadata and private working notes should remain outside this
directory so the codebase can be published cleanly to a public GitHub
repository.

# Project Status

STICH is currently under active architectural development and experimental validation.

The current focus is on:
- runtime behavior
- operational simplicity
- deployment realism
- interoperability boundaries
- edge coordination patterns
