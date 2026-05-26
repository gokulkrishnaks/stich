#!/usr/bin/env bash
set -euo pipefail

# Build the runtime binary using the repository Makefile.
# `make clean` removes old object files so the scaffold rebuild is repeatable.
make clean

# `make all` compiles every C source listed in the Makefile and links the final
# runtime executable into `build/stich`.
make all
