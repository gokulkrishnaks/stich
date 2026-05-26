# STICH

STICH is an experimental edge-native runtime for normalizing inbound telemetry
into canonical events and routing them through a small observable runtime core.

## Current First-Push Scope

This repository is intentionally trimmed to a small PoC surface:

- `runtime/core`
- `runtime/events`
- `runtime/adapters/mqtt`
- `runtime/observability`
- `runtime/utils`
- `docs`
- `tests`
- `scripts`

The current runtime validates one narrow path:

```text
MQTT Message
    ->
MQTT Adapter
    ->
Canonical Event
    ->
Runtime Router
    ->
Structured Log Output
```

## Quick Start

Build:

```bash
./scripts/build.sh
```

Run:

```bash
./scripts/run.sh
```

Test:

```bash
./scripts/test.sh
```

## Notes

- `STICH/` is the public project root.
- AI tooling metadata and private working notes stay outside this directory.
- The current test is a smoke test that validates the runtime flow without a
  real MQTT broker.

# Project Status

STICH is currently under active architectural development and experimental validation.

The current focus is on:
- runtime behavior
- operational simplicity
- deployment realism
- interoperability boundaries
- edge coordination patterns
