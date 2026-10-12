# ppo: Freedom Fighters script VM

This folder runs the game's own compiled mission scripts (`.ppo`, compiled SDL) in JavaScript.
It does not rewrite mission logic by hand. For the
bytecode format and listings, see `notes/ppo-scripts.md` and `decoders/ppo_list.py`.

## Architecture

| File | Role | Runs in |
|---|---|---|
| `loader.mjs` | `parsePpo(bytes)` parses one file: prefix, header, tables, data image, code, type trailer. `Program` links one inheritance chain (base `Generic` to leaf) into a single code/data space. `ScriptLibrary` resolves parents by name. | browser + node |
| `opcodes.mjs` | The opcode table (157 ops), `decodeAt`, `disassembleFile`, and variable-operand naming. | browser + node |
| `values.mjs` | Typed slots (`T.EMPTY/INT/FLOAT/PTR/OBJ`), object handles, `StringObject`, `StructObject` (value types and event payloads), `HostObject`. | browser + node |
| `vm.mjs` | `Process` (one script instance: data, stacks, state machine, event queue, interpreter) and `World` (scheduler, timers, messaging between processes, native dispatch, trace hooks). | browser + node |
| `natives.mjs` | `NativeRegistry`, the core bindings, and `bindActorSimulation` (optional fake movement, animation and sound). | browser + node |
| `natives-catalog.mjs` | Generated list of the 268 native methods the C01A and C05A scripts call, with class, args, rets, hint and count. | browser + node |
| `fsload.mjs` | `loadLibrary(dir)` reads every `.ppo` under a folder. | node |
| `trace.mjs` | CLI and `runTrace()`. It runs one script and prints states, events, sends and natives. | node |
| `catalog.mjs` | Rebuilds `natives-catalog.mjs`. | node |

In the browser, fetch the `.ppo` bytes yourself, then call `lib.add(relPath, bytes)` and
`lib.program(name)`.

### Execution model (as implemented, following the PC exe)

- **Variables.** An operand below `0x8000` is a data offset. `0xC000+` means `fp + (int16)v`.
  `0x8000..0xBFFF` is a state-local slot `g[0x3fff - (v & 0x3fff)]`. A substate keeps its parent
  state's variables first, then adds its own.
- **Calls.** `CALL fn#k` uses the most-derived vtable (`o6c`). `FRAME n>=0` saves fp. `FRAME n<0`
  drops the args and restores fp.
- **`CALL_NATIVE`.** The object is on top of the stack unless the call is static (flag bit
  `0x20000`). The args sit below the object. `nargs = (flags>>8)&0xff` and `nret = flags&0xff`.
- **`CALL_METHOD`.** The object comes from the variable operand.
- **States.** States come from table `o70`. Each state has an address, a name, a parent, an
  entry/exit block, typed state variables, and a handler record (event id to address). The last
  record is the class-level block, keyed by `vtable[13]`. `UnknownEvent` entries chain to parent
  records through `HANDLER_JMP` / `HANDLER_JMP_FN`.
- **`switchContext`** (PC `0x5f9130`) follows two paths:
  - Inside an event handler or a nested block, it only records a pending state.
  - Otherwise it runs the old state's exit block, clears the stacks, initialises the state
    variables, then runs the new state's entry block (or jumps to the state address).
- **Events** (PC `0x5f4ac0`) are dispatched like this:
  1. Look up the event id in the current state's handlers; fall back to `UnknownEvent`.
  2. Store the event object at `d[eventDataOff]`.
  3. Run the handler nested, then restore ip/fp.
  4. Apply the pending state and wake a waiting process.
- **Scheduler.** Each process gets 50 instructions per frame (PC `0x550f30`). The run states are
  ctor, run, sleep, sleep-continue, wait, and wait with timeout. When the constructor finishes
  (`CTOR_END` with an empty call stack), the process switches to the start state.

## Adding natives

```js
import { NativeRegistry, bindActorSimulation, I, F, S, B, O } from './natives.mjs';
const reg = new NativeRegistry();            // core bindings included
reg.bind('FFActor_If.IsDead', (c) => B(scene.actor(c.proc.ref).dead));
reg.bind('Engine_If.GetActor', (c) => I(scene.lookup(c.str(0))));
reg.bind('*.GetObjectPos', (c) => O(world.makeObject('Position', [x, y, z])), { quiet: true });
bindActorSimulation(reg);                    // optional: fake PATHFINISHED / LNKANIMEND / sound lengths
const world = new World({ natives: reg });
```

- The key is `Class.method`, matched case-insensitively. The class is the object's script type
  (from `o80`/`o84`, an exported variable type, or a state-variable type). `*.method` matches any
  class. Look up names and signatures in `natives-catalog.mjs`.
- `c` provides `world, proc, self, cls, method, hint, nargs, nret, args`, plus the readers
  `c.int(i)`, `c.float(i)`, `c.obj(i)` and `c.str(i)`.
- A binding returns a typed slot, a plain value, or an array of values when `nret > 1`.
- Unbound natives log once (`[natives] unimplemented X.m(...) -> default`) and return int 0 for
  each return slot. `reg.missingReport()` lists them with call counts.
- **Events into a script:** `world.send(procOrRef, 'StartAct', [2], from)` or
  `proc.post(name, args)`. The payload is typed from the script's event declaration.
- **Messages a script sends to a ref with no process** (`SendCommand*`) go to
  `world.externalCommands` and to `world.commandHandlers.get(ref)`. This is how a native object
  such as the caretaker plugs in.

## Running

Game files are not in the repo. Extract a level's scripts with
`python3 -I decoders/zgf.py <.../FF-C01A_MAIN.ZGF> <out>/C01A` (do the same for C05A).

```
node script-vm/trace.mjs <out>/C01A C01A/C01A_Jones.ppo --act 2 --ticks 150
node script-vm/trace.mjs <out>/C01A C01A/C01A_Jones.ppo --act 2,1,3,4 --ticks 900 --all-natives
FF_SCRIPTS_DIR=<out> node --test tests/ppo*.mjs     # <out> holds C01A/scripts and C05A/scripts
```

`FF_SCRIPTS_DIR` defaults to the engine-ppo scratch extraction of the 2026-10-08 session. If the
folder is missing, the tests skip and say why. Regenerate the catalog with
`node script-vm/catalog.mjs <out>/C01A <out>/C05A > script-vm/natives-catalog.mjs`.

Sample (`--act 2`, Jones): constructor runs, `StandAgainstWall.InitWall` -> `WallWait`; at t=1
`StartAct(2)` -> `ClimbTraining`, `PlaySound_Enum_On_Screen(44,"Jones",1)`,
`UseMoveSet("Run")`, `MoveToLocation(rClimbToPos)`; on `PATHFINISHED`,
`SendCommand_i(rCareTaker, "CompletedAct", 2)`.

## Evidence

In the recheck commands below, `$S` is the extraction root and commands run from this folder.
Each claim carries a source address, how to re-check it, and a confidence level.

- Claim: File prefix = decl line, parent `.sdl` path (empty for base scripts), own `.sdl`, u32 nVars plus var records, then one u32 equal to header A, then the header (A, f32 1.0, ...).
  Source: all 49 files of C01A+C05A parse with this layout.
  Recheck: `node --test tests/ppo.test.mjs` (test "every C01A and C05A .ppo parses ...": prefixOk for 49 files)
  Confidence: fitted on data.
- Claim: State table `o70` = header (size, a, nStates, firstStateId, nRecords, recordsSize, varBlobSize), addrs, ids, record offsets, (entry, exit) i32 pairs, name ids u16, var-init offsets u16, parent index i16, var blob, handler records `{u32 key, u16 n, u16 ids[n], pad4, u32 addrs[n]}`; records = states + 1 (the last record is the class block).
  Source: GC `MasterStateRecord_t::initializeFromBlock` 801c9510.
  Recheck: `node --test tests/ppo.test.mjs` (records = states+1 in all files; Jones `vtable[13]` = 0x4d51 = class-block key)
  Confidence: proven (layout read in code; matches all files).
- Claim: Jones chain is Generic <- GuideHero <- C01A_Jones, 17 states; StandAgainstWall @0x3d4b has an entry block, WallWait @0x3ed1; string 324 = StartAct, payload type [Int].
  Source: loader output.
  Recheck: `node -e "import('./script-vm/fsload.mjs').then(({loadLibrary})=>{const p=loadLibrary('$S/C01A').program('C01A/C01A_Jones.ppo');console.log(p.chainNames,p.states.length,p.vtable[13].toString(16),p.string(324),p.eventFields('StartAct'))})"` (prints `[Generic,GuideHero,C01A_Jones] 17 4d51 StartAct ["Int"]`)
  Confidence: proven.
- Claim: Event dispatch = lookup in the current state's record, else `UnknownEvent`, which chains via `HANDLER_JMP`/`HANDLER_JMP_FN`; the event object goes to `d[eventDataOff]` (h38[1] = 4); the handler runs nested; a state change inside it is deferred.
  Source: PC `handleEventsForProcess` 0x5f4ac0, `switchContext` 0x5f9130.
  Recheck: `node script-vm/trace.mjs $S/C01A C01A/C01A_Jones.ppo --act 2 --ticks 150` (shows `WallWait -> ClimbTraining` at t=1.03; this goes WallWait record -> HANDLER_JMP 0x3d61 -> fn#13)
  Confidence: proven for the flow; ordering details of exit/entry are fitted on data.
- Claim: Host objects `o80` and value objects `o84` = `u32 n, {u32 offset, u16 typeStrId}`; Generic has 8 Engine_If, c Scene_If, 10 FFTools_If, 14 Item_If, 18 FFActor_If, 24 String.
  Source: loader + catalog class resolution (all 268 catalog entries get a class).
  Recheck: `node --test tests/ppo.test.mjs` (test "C01A_Jones links Generic <- GuideHero <- C01A_Jones ...")
  Confidence: fitted on data.
- Claim: `o8c` is a u32 size plus the initial data image; each file's slice starts at its dataStart and the slices are contiguous across the chain. Code ranges (`o90`) are contiguous too.
  Source: loader checks.
  Recheck: `node --test tests/ppo.test.mjs` (test "every C01A and C05A .ppo parses ...")
  Confidence: fitted on data.
- Claim: The type trailer is `u32 nTypes, i32 base, {u32 size, u32 n, u32 fieldTypeIds[n]}`. It can be cut short because `decoders/zgf.py` strips trailing NULs (`rec[:cut].rstrip(b'\0')`), so the loader reads zeros past EOF.
  Source: zgf.py source; Jones type 31 = [Int] matches StartAct usage.
  Recheck: as the Jones record above (`eventFields('StartAct')` = `["Int"]`)
  Confidence: fitted on data.
- Claim: Native call stack layout: object on top (none if static, flag 0x20000), args below it, nargs = (flags>>8)&0xff, nret = flags&0xff.
  Source: decompile of the CALL_NATIVE handler; scripts run without stack drift.
  Recheck: `node --test tests/ppo.test.mjs` (smoke test: every C01A/C05A script runs 20 s with no VM error)
  Confidence: proven.
- Claim: The `hint` operand of CALL_METHOD is per class, not per method name (Geom_If.SendCommand 0x17, FFActor_If.SendCommand 0xc0), so it is probably a method slot in that class's table.
  Source: `natives-catalog.mjs`.
  Recheck: `grep -n '"SendCommand"' script-vm/natives-catalog.mjs`
  Confidence: inferred.
- Claim: Quota is 50 instructions per process per frame; PUSH_STR adds 1 to the budget.
  Source: PC scheduler 0x550f30.
  Recheck: none in data; read the address with `decoders/tools/re.py fn 0x550f30`.
  Confidence: proven (code), not checked against timing.
- Claim: A substate's variables are its parent state's variables followed by its own.
  Source: max g index used in each substate = parentVars + own - 1, across all files.
  Recheck: `node --test tests/ppo.test.mjs` (smoke test; Jones InitWall reads parent vars correctly in the act-2 trace)
  Confidence: fitted on data.
- Claim: Jones runs the act loop 2 -> 1 -> 3 -> 4, sending CompletedAct [2,1,3,4] to rCareTaker, ending in AimTraining and sending Activate to rOpenEscapeDoorAction.
  Source: VM run with the scenario bindings IsDead -> 1, GetActor -> 7, GetOwner -> 7.
  Recheck: `node --test tests/ppo.test.mjs` (test "act loop: a stand-in caretaker ...")
  Confidence: proven (for the VM; game behaviour not compared side by side).
- Claim: Opcode coverage: 157 opcodes defined, 86 used in C01A+C05A code, 57 executed by the smoke run.
  Source: disassembly of every file + op trace.
  Recheck: the scratch script `engine-ppo/cov.mjs $S` (prints `opcodes 157 used statically 86 executed 57`)
  Confidence: proven.

## Open questions and what is next

1. **Caretaker.** `ZFFCareTaker_C01A` is a native engine class, not a script, and it drives the
   acts. It must be ported natively next. Hook it in through
   `world.commandHandlers.set(rCareTaker, cmd => ...)`, which receives CompletedAct and similar
   commands, and answer with `world.send(proc, 'StartAct', [n])`. `trace.mjs` has a stand-in that
   only sequences acts.
2. **Low-confidence opcodes.**
   - `0x7c` (FUN_005fbb00): meaning unknown. No script uses it; the VM ignores it.
   - `0x99`/`0x9a`: read as push current state name / push current event name (PC 0x5f90a0 / 0x5f9010 through the low-confidence name map). This fits their use in Generic's debug print. Inferred, and never executed in the smoke run.
   - `0x9b`/`0x9c`: set/clear flag 0x9000. Implemented from the decompile but unused.
   - Also unused, so their semantics are untested: EVLOCK/EVUNLOCK, WAITFOREVENT, WAITFORNAMEDEVENT, TERMINATE, NEWDEFAULT, JSV1/JNSV1, SET_QUOTA/SET_BUDGET.
3. **Unknown header fields.** Still unexplained: the state-table `a` field and the use of
   `firstStateId`, the header u16s and the two 16-byte blobs. A global opcode budget, if the engine
   has one, is not modelled.
4. **Engine natives.** About 200 engine natives are still stubbed, among them movement, combat,
   inventory, scene queries and sound. Bind them against the browser scene as the level code
   grows. `bindActorSimulation` is only a stand-in for tests.
5. **Act 5 (UseHealth)** needs SelectedItem events and medkit ownership changes from an inventory
   model.
6. `decoders/zgf.py` should cut `.ppo` records by their data length instead of stripping trailing
   NULs. The loader works around the stripping already.
