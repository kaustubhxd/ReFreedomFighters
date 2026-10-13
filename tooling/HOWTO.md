# Shared harness: serialisation stubs

`serial_stubs.py` is used by any spec that runs save, load, ReadInput or CopyEventDataBlock code. Import it from a
spec in `inline-*/harness/` like this (the module is found from either folder layout):

```python
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
```

## What to call
- Save side (ZSaveGame, slot 0x60 for bytes, 0x3c for dwords, ...): `ss.save_obj(c, {0x60: ss.rec(c, 1), 0x3c: ss.rec(c, 1)})`.
  Only the call count is kept; the calls are not logged per argument.
- Load side (ZLoadGame, slot 0x68 for bytes, 0x40 for dwords): `ss.load_obj(c, {0x68: ss.wr(c, 1, 0, 1, imm), ...})`.
  The stub writes imm into the pointer argument, so the exe and the port must both write the same field.
- DBREAD reads: `ss.dbread_patch(c, rets_u32, rets_u16, counts)` patches the operators, GetRefTab, REFTAB::Count and
  GetInput for the run. Each sequence returns its values in order (wrapping after eight). Call it once per gen.
- CCheckInside's render manager: `ss.rm_object(c, imm)` sets global 0x70039c and returns the object whose slot 0x88
  writes imm through its out pointer.
- Any other exe callee: `ss.patch(c, addr, stub)`. The image is marked dirty so the next run restores it.

Every gen ends with `c.emu.mu.ctl_flush_tb()`, as in the other specs.

## Limits
- The stubs are thiscall. A stdcall or cdecl callee needs its own stub.
- `wr` writes a fixed value. A function that expects a different width must get the right width.
- `patch` must run in each gen, because the counters live in the image.
- The stubs do not log arguments, so the call logs only show call counts.

## Who uses it
Batch 81 (save/load of CCheckInside and ZShotActivate, CCheckInside ReadInput). Pathfinding, vehicles and sound timers
need the same DBREAD and save/load stubs for their own save and load functions.

<!-- Checker rules added 2026-10-12; they apply to every folder. -->

## NaN words: raw bits unless the spec says float (2026-10-11)
`nan_only()` in pilot.py used to accept any heap-word difference where both words were NaN bit patterns. A stored
integer such as -1 (0xffffffff) could then be swapped for another NaN pattern and still pass (found in area 18).
Now heap words compare as raw bits. A spec whose output words are floats says so with `nan_heap=True` in `S(...)`,
and only then is a NaN-vs-NaN heap difference excused. ST0 and XMM0 keep the NaN exemption (the float return
type makes them float by definition). The float exemption shows as `nan_payload_cases` in the JSON.
Example: ZParamParticle::GetPos (0x4e71b0) and velocity (0x4e7330) write float positions; the original stores
0x7fc00000 where the port stores 0xffc00000 (NaN sign from operand order). Both are `nan_heap=True`, and both are exact.

## .data writes are compared as values (2026-10-11)
The check used to compare only the addresses of changed .data bytes (first 16), so a wrong value written at a right address passed (ZVehicleIf::addMethodDefinitions 0x51aba0, area 23, had a surviving mutant for this). `data_writes()` now records each changed run as (address, new bytes) and the whole list is compared. A .data-writing spec is exact only when the same bytes land at the same addresses as the original. The JSON field `data` holds the runs. Nothing to change in a spec.

## Mutant runs: keep PILOT_BUILD unset (2026-10-11)
`mutate.py` with `PILOT_BUILD` exported makes the mutant rebuild the REAL build directory, so later "exact" results reflect a mutant binary (found by area 19/26). Run `mutate.py` with `PILOT_BUILD` unset. After any mutant run, do a clean build before trusting an "exact" result, and re-verify the folder.

## Checklist before you trust "exact" (2026-10-12)
1. .data: the whole changed value is compared (data_writes), not only which addresses changed. A wrong constant written to a global now fails.
2. Stack pop count per call site: a stub must pop what the real callee pops. Read the callee's `ret N` (or the caller's epilogue balance). Do not assume the same count for every call through one vtable slot: slot 0x114 is per class (RegisterZMsg is ret 0x10; SetVisLightMultiplier is ret 0x14).
3. Bool returns: declare `ret='al'` on the spec. With `ret=None` or `'eax'` a bool result is not compared at all, so a wrong value passes. pilot.py masks eax to AL on both sides for `ret='al'`.
4. NaN: heap words compare as raw bits; a spec that writes float heap words sets `nan_heap=True`.
5. faulting_cases == 0 for every exact result, on both seeds.
6. PILOT_BUILD unset when running mutate.py; clean-rebuild a folder after any mutant run before trusting its results.

## Heap words that hold a stack address: heap_mask (2026-10-12)
Some functions store a pointer to their own stack local in the object (CRigidBody::Setup2 0x540bc0 stores a pointer at this+0x14e). The port's frame layout differs, so the stored pointer differs by the frame offset and the raw heap compare fails even when the logic is right.
- Spec option: `heap_mask=fn(ctx) -> [(abs_addr, nbytes), ...]`. Each named range is zeroed on both the original and the port before the heap compare. `ctx.args` gives the object address for the case.
- A masked word is NOT verified by that spec. Write a second spec for what the pointer points to, or state in the docs that the word was masked.
- Use it only for words that really hold a stack address. Never mask a word just to make a mismatch go away.

## Bool and void returns: only declare ret='al' for a bool (2026-10-12)
`ret='al'` compares AL only. Declare it only when the C++ return type is bool. A void function leaves AL as scratch, so `ret='al'` on a void function gives a false mismatch. Three specs were changed to `ret='al'` by mistake (ZProjectile::ReadInput 0x4b9570, ZLNKWHANDS::SetDialog 0x475910, ZItemSpawn::CopyEventDataBlock 0x46d290). All three ports are void, and they are back to `ret=None`. A setcc before a `ret` is not proof of a bool return: check the source's return type first.

## Hooks, instruction budget, and per-spec cleanup (added 2026-10-12)
- `e.hook(addr, handler)` (pilot.py, inherited from pe_emu) replaces the exe function at `addr` with `handler(emu, r)` through a
  code hook, so the exe side and any callee of it can be stubbed by address without re-linking. The port side runs its own
  blob code and is not affected unless it calls that address. Hooks persist on the emulator until `e.unhook(addr)`.
- `verify()` clears every hook before a spec starts, so a hook set by one spec's `gen`/`setup` cannot leak into the next spec
  run in the same process. Before this rule, a bool-return function next to a hooked one showed false call-log mismatches.
- `S(..., max_insns=N)` sets the instruction budget per call (default 2,000,000). Use it for long functions. A run that hits
  the budget is recorded as `instruction limit` on both sides.
- Checked on 2026-10-12 (seed 1, n 300, faulting_cases 0): ZParamParticle::GetPos (float, nan_heap), CFFCoverList::Init
  (heap writes), ZFFActor::CanSee and CCheckVisible::CanSee (bool, ret='al').

## Killing runs: only your own PID (rule, 2026-10-12)
- Never use `pkill -f`, `killall`, or any kill by command-line pattern. Many threads' `pilot.py` runs share one machine,
  so a pattern kill also stops other areas' runs.
- Kill only the PID you started: keep `$!` or write a pidfile when you launch a run, and `kill "$pid"` with that value.
- A run that ended with exit code 143 (SIGTERM), or that vanished without a result file, was probably killed by someone
  else's pattern kill. Rerun it. Do not record it as a result.

## Float arguments must be wrapped (rule, 2026-10-12)
- `run()` truncates a bare Python float argument to an integer, so the spec tests the wrong values. Wrap every float
  argument as `F(x)` (single precision) or `D(x)` (double).
- `pilot.py` now raises `ValueError: ... bare float argument` for a bare float in a spec's arguments (also from `gen`), so
  the run stops instead of testing the wrong values. A batch that ran before this check with bare floats must be rerun.
