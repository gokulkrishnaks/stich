# STICH Roadmap

This repository is currently scoped as a small first public push.

## Current Status

- Minimal repository structure in place
- Runtime core skeleton implemented
- MQTT adapter skeleton implemented
- Smoke-test workflow available through `scripts/test.sh`

## Next Steps

1. Replace the simulated MQTT input path with a real broker-backed adapter flow.
2. Expand the canonical event model and serialization coverage.
3. Grow `tests/` from a smoke test into proper runtime and adapter tests.
4. Reintroduce additional runtime modules only when they are actively used.
