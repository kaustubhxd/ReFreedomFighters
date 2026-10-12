# PPO compiled scripts: format, VM and the C01A tutorial logic

Status 2026-10-08: **disassembly done.** All 49 `.ppo` files from the C01A and C05A
ZGFs decode cleanly, with no unknown opcodes and every byte of code consumed. State names, parents and
strings resolve automatically. What's not done yet: a high-level decompiler
(listings are assembly-level), the native method catalogue, and a few
enum mappings (see "Open questions").

## Tools (all in `~/freedom-fighters-re/decoders/`, Python 3 stdlib)

| File | What it does |
|---|---|
| `zgf.py` | Extracts `.ppo` scripts (and fonts) from a level's ZGF. |
| `ppo_dis.py` | Opcode table + linear disassembler. `python3 -I ppo_dis.py a.ppo ...` checks clean decode; `-l child.ppo parent.ppo ...` gives a raw listing. |
| `ppo_list.py` | Labelled listing: finds parents from the file, resolves strings, marks constructor, `STATE` entry points and own functions, and names `SETSTATE` targets. `python3 -I ppo_list.py <scripts_dir> C01A/C01A_Jones.ppo` or `--all <scripts_dir> <out_dir>`. |
| `ppo_probe.py` | Early header probe (kept for reference). |
| `opcodes.md` | **Full opcode table** (0x00–0x9e: operands, length, semantics, confidence) and the VM model. This is the reference to read. |
| `ppo_listings/C01A/`, `ppo_listings/C05A/` | Generated `.lst` for every script in those two levels. |
| `ppo_natives.txt` | Every native call name used in those scripts, with counts and signatures. |
| `re/exe.py`, `re/vm_fixed.c`, `re/loader.asm` | Reverse-engineering scratch: capstone/pefile helpers over Freedom.Exe (expects a `functions.jsonl` from the Ghidra dump), the VM interpreter decompile with integer case labels, and the loader disassembly. Ghidra output is in `freedom-fighters-re/out/ppo-vm-decomp.txt` and `ppo-loader-callers.txt`. |

To regenerate listings for another level: extract its ZGF with `zgf.py`, then run
`ppo_list.py --all <extracted>/scripts <out>`. Parents (e.g. `AllLevels/Generic`)
must be in the same scripts folder; every level ZGF ships its own copies.

## Where it lives in Freedom.Exe

- Source files named in asserts: `sdl_engine/scriptvm.cpp`, `vm_image_info.cpp`, `scriptdll.cpp`. Related classes: `FreedomScriptScheduler_t`, `ScriptEventManager_t`.
- Loader: `FUN_005ff2b0` (header + blob), only caller `FUN_005fc590`. GameCube name: `VMImageInfo_t::fromDisk` (name map, medium confidence).
- Interpreter: `FUN_005f56f0`, jump table at `0x5f8bf8`, 0x9f opcodes. GameCube name: `Process_t::runProcess` (name map, high: 8 shared unique strings).

## File layout

1. **Serialized prefix**: declaration line of exported variables (`ZGEOMREF rCareTaker;...`), then the source paths: **the parent `.sdl` first, then this script's own `.sdl`** (base scripts list only one path). Then per-variable records (offset, name, type, e.g. `List_If`). Variables are what level designers wire to scene objects in the GMS.
2. **Header** (found by the `1.0f` version float): `u32 A, f32 1.0, u32, u32, 4×u16, 16-byte blob, 16-byte blob, 6×u32 h38, 12×u32 table offsets (o68 o6c o70 o74 o78 o7c o80 o84 o88 o8c o90 size)`, then the blob of `size` bytes, then `u32, u32`.
3. **Blob regions** (offsets relative to the blob):
   - `o68`: own path string.
   - `o6c`: **vtable**, `u32 count` then absolute code addresses. `CALL fn#N` indexes it. Entries below the file's own code base point into parent code (inherited functions); entries inside are overrides or new functions.
   - `o70`: **state table**: `u32 size, u32 ?, u32 nStates, u32 ?, u32 ?, u32 ?, u32 ?`, then `nStates` entry addresses, then state ids, then offsets into per-state handler records. State *names* are the strings `<Script>.<State>` in string-id order, and they line up 1:1 with the address list (checked: Jones's `SETSTARTSTATE` target is `StandAgainstWall`).
   - `o74`/`o78`: message tables: `u16 id, u16 count`, then u32 pairs whose low half is a string id (message name, e.g. `StartAct`, `SelectedItem`, `OpeningSewer`, `PlaySynchronizedAnim`).
   - `o7c`: **string table**: `u32 first_id, u32 count, u32 offs[count]`, then chars. Ids are global across the inheritance chain (Generic 0–319, GuideHero 320–323, Jones 324–385).
   - `o90`: `u32 codeSize`, then code.
4. **Code addresses are global** across the chain: `h38[0]` is this file's code base (Generic 0, GuideHero 0x308e, Jones 0x387f). Jumps are absolute.

## VM model (summary; details in opcodes.md §2)

- Stack machine with typed 8-byte slots (1 int, 2 float, 3 pointer, 4 object).
- u16 variable operands: `< 0x8000` instance data `d[...]`, `0xC000+` frame slot, `0x8000–0xBFFF` state-local `g[...]`.
- Natives: `CALL_NATIVE class, method, hint, flags` and `CALL_METHOD objVar, method, hint, flags` (low byte of flags = returns, next byte = args). Method names are strings in the table, so the listings show calls like `d[0x18].SendCommand(...)`.
- States are coroutines: `SLEEP_IMM`, `YIELD`, `WAITFOREVENT` suspend; `SETSTATE` switches; `HANDLER_JMP(_FN)` registers message handlers; `CTOR_END` ends the constructor.

## Inheritance seen in C01A / C05A

- `BasicScript` (base) ← `MusicController_3` ← `C01A_MusicController`; `BasicScript` ← `CallFlybyAttack`, `Sound/Play_Random_Multi`.
- `Generic` (base, 12,430 bytes of code: shared actor behaviour) ← `GuideHero` ← `C01A_Jones`; `Generic` ← `C01A_Troy`, `C01A_Bagzton`, `C01A_CivilianWall`, `C01A_HeliDude`, `neutral2`; `Generic` ← `Soldier` ← `EnemySoldier` (67 states of AI) ← `EnemyPolice` ← `C01A_PunchMe`; `EnemySoldier` ← `C01A_WeakSoldier`.
- `GenericMoveOnSpline` (base) ← `GenericHelicopter` ← `HeliFlybyAttack` ← `C01A_HeliTroy`, `C01A_HeliWindow`; `GenericMoveOnSpline` ← `GenericVehicle` ← `GenericTank` ← `C01A_Tank`.

## C01A tutorial: what the bytecode says

`C01A_Jones` (listing: `ppo_listings/C01A/C01A/C01A_Jones.lst`) has 16 states:
Idle, StandAgainstWall (+ InitWall, PlaySynchAnim, WallWait), WallIdle,
PickupTraining, ClimbTraining, FirstShooting, AimTraining, UseHealth,
CrouchTraining, MolotovTraining, HealWounded, Sewer, OnFire.
Start state: **StandAgainstWall** (Jones is against the wall being beaten; matches the video at 2:40).

**The tutorial is driven by numbered acts.** The `StartAct` message handler
reads the act number and switches state:

| Act | Jones state | Video  |
|---|---|---|
| 1 | PickupTraining | 3:00–3:15 take the soldier's weapon ("Take his weapon!") |
| 2 | ClimbTraining | 2:55 rooftop climb |
| 3 | FirstShooting | 3:00–3:10 "More soldiers! Shoot them!" |
| 4 | AimTraining | 3:20–3:40 shoot the barrels |
| 5 | UseHealth | 3:45–3:55 medic kit at the ambulance |
| 6 | (not handled; message arg 6 on another slot triggers OnFire) | |
| 7 | CrouchTraining | not visible in the video |
| 8 | HealWounded | heal a wounded man (LOC `C01A_40/42_Jones`) |
| 9 | MolotovTraining | 4:50–5:10 |
| 10 | Sewer | 5:30 manhole |
| other | Idle | |

When a step finishes, Jones sends `CompletedAct(n)` with `SendCommand_i` to
the object in variable `rCareTaker` (`d[0x2d8]`). No script in C01A sends
`StartAct`, so **the act sequencer is the `rCareTaker` object in the scene,
handled natively or by GMS event wiring** (inferred; not yet found). Act numbers
are not in play order (2 Climb happens before 1 Pickup in the video), so the
caretaker decides the order. Bagzton has the same pattern (Idle,
MolotovTraining → ThrowMolotovs, HealWounded, Sewer, OnFire).

Example, PickupTraining: set team 0, pull weapon, play Jones line, open a door
(`SendCommand "Activate"` to a door action), aim at `rPickupSoldier` until it
is dead, then loop showing hint 20 and nagging every 10 s until the player owns
the dropped weapon, then `HideHint` and `CompletedAct(1)`.

## Open questions (next steps)

1. **`PlaySound_Enum_On_Screen(n, "Jones", 1)`**: `n` looks like the LOC line number (`44` in ClimbTraining = `C01A_44_Jones` "I think they have your brother in that helicopter"; `50` = "We must leave now!"), but some numbers (41, 47, 48) have no LOC text. Check against SND names.
2. **`ShowHint(n, 0)`**: `n` is an engine enum, not the alphabetical LOC hint index (Pickup uses 20; alphabetical 20 is FindFirstAid). Find the table in Freedom.Exe.
3. **The caretaker / act sequencer** (DONE 2026-10-08: ported in the unpublished browser port; whole-level trace there with `trace-c01a.mjs <scripts>/C01A --manifest <json from decoders/gms_scripts.py>` runs acts 0-10 to the sewer). Original note: native code. The GameCube symbols name `ZFFCareTaker_C01A` (`Command`, `BeamActor`, ...), one class per level with tutorial/story logic (C01A, C02A, C03A–C, C04B, C05A, C08C–D). Find its PC equivalent (via the GC ELF) and port it: it sends `StartAct n` and receives `CompletedAct n`.
4. **Native method catalogue**: first pass done, `decoders/ppo_natives.txt` lists all 224 native names used in C01A + C05A with use count, arg/return counts and the method slot (the `hint` operand, likely the index into the native class's method table). Still needed: which C++ class each object variable (`d[0x8]`, `d[0x10]`, `d[0x18]`, ...) is, and what each method does. That list is the API the browser runtime must implement.
5. Low-confidence opcodes: 0x7c, 0x99–0x9c (see opcodes.md).
6. A decompiler to structured pseudo-code (if/while from the JZ/JMP patterns) would make listings far easier to port; optional.

## How this feeds the browser port

**Update 2026-10-08: the JS VM exists** in `script-vm/` (loader, VM, native registry, trace tool; README there with 13 evidence records). All 49 C01A + C05A scripts load and run 20 s of game time without VM errors; the port's VM tests pass 9/9. Trace: `node script-vm/trace.mjs <scripts>/C01A C01A/C01A_Jones.ppo --act 2 --ticks 150` shows StandAgainstWall -> StartAct(2) -> ClimbTraining -> CompletedAct(2) to rCareTaker. With a fake caretaker Jones completes acts 2, 1, 3, 4; act 5 (UseHealth) needs an inventory model. Next: port `ZFFCareTaker_C01A` natively, bind ~200 stubbed engine natives to the browser scene. Opcode coverage: 86/157 used in these scripts, 57 executed so far. `zgf.py` should cut .ppo records by data length rather than stripping trailing zeros (the JS loader works around it).

Rather than rewriting mission logic by hand, the browser runtime can run these
scripts directly: a JS interpreter for the ~160 opcodes is small, and the work
moves to implementing the native methods (`SendCommand`, `ShowHint`,
`PlaySound_Enum_On_Screen`, `AimWeaponAtGeom`, ...) on top of the engine.
This is the route taken: no hand-rewriting of mission logic.
