# Verified C++ ports (first step)

- `<folder>/src/`: C++ port sources, one batch file per folder. Each `PCREG(address, name)` line registers a port.
- `<folder>/harness/`: Python specs (`S(address, ...)`) that describe each call: argument shapes, stubs and hooks.
- `shared-ff.h`, `shared-wkit.py`: shared helpers used by the sources and specs.

To check a port you need your own copy of the game and the checker in `tooling/`. The specs read the executable's path
from the environment (see `tooling/HOWTO.md`). Nothing here runs without that copy.
