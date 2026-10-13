# shared-harness: the decomp pilot checker, runnable on a Mac

Made 2026-10-11 by the ladder thread. The cloud pilot (decomp-pilot/harness/pilot.py) needs ld.lld, llvm-nm and
llvm-objcopy, which the Mac does not have. This folder holds:

| File | What |
|---|---|
| `pilot.py` | The cloud pilot.py (trial copy, with the 64 KB 0xcc stack fill), unchanged except paths: spec folder from `PILOT_SPECS`, pe_emu from this folder, build through `build.sh` here. |
| `pe_emu.py` | The trial copy of exe-verify's pe_emu.py (fake TEB, so fs:[0] works). |
| `build.sh` | Apple clang `--target=i686-linux-gnu` with the cloud flags, then `mini_ld.py`. |
| `mini_ld.py` | ~150-line static linker for i386 ELF objects: lays out sections at 0x31000000, binds `ext_<hex>` to the exe address, applies R_386_32/PC32/PLT32, writes pilot.bin and an nm-style pilot.syms. |
| `ff.h` | Copy of the shared ff.h (build.sh adds this folder to the include path; a thread's own src/ff.h wins). |

Use (a thread folder has `harness/specs_*.py` and `src/*.cpp`):

```
cd ~/freedom-fighters-re
export FF_RE_ROOT=$PWD PILOT_SPECS=$PWD/decomp-pilot/inline-ladder/harness
tools/venv/bin/python3 -I decomp-pilot/shared-harness/pilot.py 45fe90 -n 1000 --seed 1
```

2026-10-11 (ladder thread): pe_emu.py host writes (w8/w16/w32/wf32/wbytes) into the exe image now mark it dirty, so
globals a spec sets (0x70039c, 0x7003b0, ...) are restored before the next case. pilot.py already resets FPCW/MXCSR/
FPSW/FPTAG before each run, fills 64 KB of stack with 0xcc, and reports all-fault functions as not-exercisable.
