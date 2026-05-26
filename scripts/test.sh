#!/usr/bin/env bash
set -euo pipefail

# Build the binary before testing so the smoke test exercises the latest code.
./scripts/build.sh

# Execute the runtime and capture its log stream. The PoC runtime emits a routed
# telemetry event when the scaffold is healthy.
runtime_output="$(./build/stich)"

# Assert that the router logged a telemetry event. This keeps the first test
# lightweight while still checking the most important end-to-end path.
printf '%s\n' "$runtime_output" | grep -q "kind:telemetry"

printf 'STICH smoke test passed\n'
