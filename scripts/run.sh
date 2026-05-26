#!/usr/bin/env bash
set -euo pipefail

# Build first so the runtime always starts from the current source tree.
./scripts/build.sh

# Launch the PoC runtime. The current implementation simulates one MQTT-derived
# telemetry event so the full ingestion-to-routing path is observable.
./build/stich
