> Note: the name map (`decoders/gc_pc_namemap.tsv`) is not in this public copy. Rebuild it with `namemap.py` from your own GameCube and PC copies; the tools below expect it at the same path.

# decoders/tools — reverse-engineering tools for both builds

## Origin of the GameCube material

The GameCube release of Freedom Fighters (2003) ships its main executable, `startup_release.elf`, with the symbol table
left in. Every GameCube name in this folder (the `gc_name` and `gc_demangled` columns of `../gc_pc_namemap.tsv`, and
the GameCube addresses in `gc_addr`) comes from that symbol table. The PC addresses, the pairings, the confidence levels
and the evidence column are our own work: `namemap.py` matches the two builds by strings, call graphs, vtables and code
shape. No GameCube or PC executable bytes are included. To rebuild the map, extract `startup_release.elf` from your own
GameCube disc image (`rvz.py` reads Dolphin's RVZ format) and run `namemap.py`. `xiso.py` is a separate reader for
Xbox disc images (XDVDFS); the Xbox build has no symbols and is not used by the name map.

Stdlib + `capstone` + `pefile` only.
Run everything with `python3 -I`.

| File | What it is |
|---|---|
| `re.py` | Lookup CLI for the PC exe and the GameCube ELF: `fn`, `xrefs`, `strings`, `sym`, `map`. |
| `namemap.py` | Builds `decoders/gc_pc_namemap.tsv` (GameCube name → PC address). |
| `ffre.py` | Shared library: loaders, x86/PPC analysis, GCC 2.x demangler, MSVC RTTI vtables, GC vtables, compilation units. |
| `ghidra_apply_names.py` | Ghidra script (Jython or PyGhidra, GUI or headless) that renames PC functions from the TSV. |
| `namemap_report.txt` | Report of the last `namemap.py` run: coverage, ground truth, consistency. |
| `../gc_pc_namemap.tsv` | The name map: 8604 rows. |

## Paths

| Variable | Default | What it points to |
|---|---|---|
| `FF_RE_ROOT` | `~/freedom-fighters-re`, falling back to the current directory | Must contain `bin/Freedom.Exe.orig`, `out/functions.jsonl` and `samples/gamecube/files/startup_release.elf` |
| `FF_NAMEMAP` | `decoders/gc_pc_namemap.tsv` | The name map |
| `FF_RE_CACHE` | `~/.cache/ff-re` | Pickled analysis. Delete it to rebuild. The key includes each file's size and mtime. |

- First run: about 4 s.
- Cached run: under 1 s.
- `namemap.py`: about 25 s.

## re.py

```
python3 -I decoders/tools/re.py fn <name|addr> [--build pc|gc] [--no-dis] [--max-ins N] [--lines N]
python3 -I decoders/tools/re.py xrefs <addr|exact string> [--build pc|gc]
python3 -I decoders/tools/re.py strings <regex> [--build pc|gc] [--all]
python3 -I decoders/tools/re.py sym <regex>              # GC symbols, mangled or demangled
python3 -I decoders/tools/re.py map <pc_addr|gc_addr|gc_name>
```

**Address forms**
- PC: `0x4edb80`, `4edb80` or `FUN_004edb80`.
- GC: `80216e8c` (8 hex digits starting with 8).
- Anything else is taken as a GC symbol: a mangled name, a demangled `Class::method`, or a regex.

**What `fn` prints**
- Size, ranges and the compilation unit (GC).
- The matched function in the other build, with confidence and evidence.
- Callers, callees and the vtable slots that point at the function.
- Referenced strings and float literals.
- Annotated disassembly. Calls carry names from the map, string loads show the string, and GC `lis/addi` pairs are resolved.

Example:

```
$ re.py fn 0x490a90 --no-dis
PC 0x490a90  FUN_00490a90  size 148  ranges 490a90-490b24
  match: GC 801fc81c ZEngineDataBase::GetRoomColiTreeData(void*, unsigned int)  [medium] str-group:2-way "rmc" ...
callers (0):
vtable slots (1): ZEngineDataBase[129]
callees (4):
  0x48c4b0  FUN_0048c4b0 = ZEngineDataBase::CalcCacheFileName [high]
  ...
strings (1):
  0x490ac6 -> 0x68d830  'rmc'

$ re.py strings 'No graph data'
== PC: 0x6a2bb8 'ERROR: ZSoundGraph::Initialize() - No graph data loaded'  FUN_0053c280 = ZSoundGraph::Initialize [high]
== GC: 803fad98 'ERROR: ZSoundGraph::Initialize() - No graph data loaded'  801f4d00 ZSoundGraph::Initialize

$ re.py map 0x5f56f0
PC 0x5f56f0  <->  GC 801bcdc8 Process_t::runProcess()   [high] str:8u/11.2 sim=0.86 ...
```

**Demangler.** The GCC 2.x demangler handles:
- methods, const methods, constructors (`__5ZGEOM`) and destructors (`_._5ZGEOM`);
- operators, `Q` nesting, class templates (`t10CBaseEvent1Z7ZWINDOW`) and template functions (`__H`);
- `T`/`N` repeats, arrays, function pointers and member pointers;
- vtables (`_vt.5ZGEOM`).

It leaves 20 of 18028 GC function names unparsed. These are local classes such as `inc__Q37ZFFHERO27UpdateFollowers__7ZFFHERO.0_5idx_t.6164`.

## namemap.py

Run `python3 -I decoders/tools/namemap.py [--report FILE] [-v]`. It writes the TSV with these columns:

| Column | Content |
|---|---|
| `gc_name` | Mangled name |
| `gc_demangled` | Demangled name |
| `gc_addr` | GC address |
| `pc_addr` | PC address |
| `confidence` | `high`, `medium` or `low` |
| `evidence` | Which signals matched |

`--holdout F --seed N` runs the validation described under Accuracy and writes no TSV.

### Signals, in order

1. **Strings.** The two builds share 3639 string literals: asserts, errors, format strings, short extensions like `"sgp"`, and `.cpp` paths reduced to their last two parts.
   - A string used by exactly one function on each side pairs those functions.
   - Score: shared unique strings and the Jaccard similarity of the two functions' shared-vocabulary strings.
   - Groups of 2–3 functions that share one string are resolved by unit order (see 4).
2. **Vtables.** PC classes come from MSVC RTTI (716 classes) and GC classes from `_vt.<class>` symbols (702). There are 622 common classes, plus 29 platform pairs such as `ZCollisionGC~ZCollisionWintel`.
   - GC entries are 8 bytes; slot *i* is at `vt+0xc+8i`.
   - GC slots are aligned to PC slots with Needleman–Wunsch. Already-matched functions act as anchors, and function size is part of the score.
   - MSVC puts overloads of one name in reverse order. Adjacent GCC overload runs are reversed before aligning.
   - A class is used only if no aligned slot contradicts an anchor.
   - A GC function must land on the same PC function in every class it appears in.
3. **Call graph.** This runs iteratively.
   - For each matched pair, the ordered callee lists are aligned on matched callees. A 1:1 gap between two anchors votes for a pair. Equal-length gaps of up to 4 give weak votes.
   - Callers vote the same way.
   - Neighbour signature: the matched callers (or callees) of a GC function map onto the callers (callees) of exactly one free PC function.
   - CRT helpers are removed from the PC lists (`__security_check_cookie`, `__alloca_probe`, `_ftol`, ...), and thunks are resolved. GCC runtime helpers and ≤8-byte stubs are removed from the GC lists.
4. **Link order.** GC compilation units are known from the `gcc2_compiled.` labels, giving 602 units.
   - Inside one unit, the PC linker laid out functions **sorted by MSVC decorated name** (`?Init2@X@@` < `?Init@X@@`). This holds for about 80% of units; a few keep source order.
   - Two matched functions of one unit that are adjacent in PC address space bracket the free functions between them.
   - If the same number of free GC functions of that unit fall in the bracket (by name key or by source order, whichever the nearby anchors follow), they are paired in order.
5. **Constants.** 32-bit immediates and float literals that are unique to one function in each build. This only adds a handful of pairs.

**Checks applied to every pair**
- Size: log2(GC/PC) must lie in −0.50..1.68. The band is calibrated on 323 multi-string pairs, where GC code is about 1.5× larger.
- No contradiction:
  - the two functions use shared strings but none in common;
  - fewer than 1/3 of the matched callees or callers agree;
  - their float literals are disjoint.

**Final re-check**
- Medium pairs whose matched neighbours all agree (at least 3 edges) become high.
- Low pairs with full graph agreement become medium.
- Pairs that now contradict are demoted (49).

**Confidence levels**
- **high**: two independent signals; or ≥2 unique strings with similarity ≥0.5; or ≥3 unique strings; or a clean, anchored vtable slot passing the size check; or ≥2 call-graph votes from high pairs.
- **medium**: one clean signal plus the size check.
- **low**: one of the following:
  - weak evidence;
  - a size outlier;
  - a PC function shared by several GC functions (identical-code folding, `icf/stub`);
  - a platform vtable slot that fails the size check.

  Low rows are not applied in Ghidra by default.

## Accuracy

Numbers are from the run that wrote the current TSV (`namemap_report.txt`).

- Claim: Coverage is 8604 of 18028 GC functions matched. By confidence:
  - high: 4152
  - medium: 1825
  - low: 2627

  The 15088 functions in game `.cpp` units are 51% matched (4115 / 1648 / 1998). Most of the other 2940 are Dolphin SDK, MSL and THP code, which has no PC counterpart.

  high+medium rows name 5977 distinct PC functions, out of 12955 Ghidra functions.

  By signal (high / medium / low):

  | Signal | high | medium | low |
  |---|---|---|---|
  | strings | 775 | 205 | 147 |
  | vtables | 2663 | 1049 | 2181 |
  | call graph | 648 | 440 | 283 |
  | link order | 66 | 127 | 14 |
  | constants | 0 | 4 | 2 |

  Source: `namemap_report.txt`
  Recheck: `python3 -I decoders/tools/namemap.py --out /tmp/x.tsv | head -14` prints "Matched GC functions: 8604 (high 4152, medium 1825, low 2627)".
  Confidence: proven (count).

- Claim: Ground truth is 23 of 23 exact pairs correct, none wrong, none missing. Two more pairs from the docs are "related", not 1:1 pairs, and are explained below.
  - 16 of the 23 are high or medium.
  - Low: `ZEngineDataBase::LoadBoundTrees` (order bracket of 3) and `ZCollisionGC::GetPrimFromStripUniqueId`. The latter's PC function is folded with `ZDrawArrayBlocks::GetBlock`.
  - Explained: PC `0x4e3c20` is `ZOctreeCompiled::CheckPoint` with `ConvToOCS` inlined; the map says CheckPoint, which is right. PC `0x6616f0` (strip walker) is not the counterpart of `GetStripsFromId`; the map leaves both unpaired.

  Spot checks against the PPO script notes (`formats/opcodes.md`):
  - PC `0x5f56f0` (script VM) → `Process_t::runProcess` [high, 8 shared unique strings].
  - PC `0x5ff2b0` (PPO loader) → `VMImageInfo_t::fromDisk` [medium, "Invalid .ppo version" string, callers agree].

  Source: `GROUND_TRUTH` in `namemap.py`, taken from `formats/oct-format.md`, `formats/rooms-sgp-format.md` and the PPO script notes.
  Recheck: `python3 -I decoders/tools/namemap.py --out /tmp/x.tsv | grep "correct 23"`
  Confidence: proven.

- Claim: **The docs swap sizer and reader** for rmc, rmi, oct and sgp.
  - In each documented pair, the first function is the reader `Get…Data(void*, unsigned)`: it ends in `ret 8` and reads `[ebp+8]`/`[ebp+0xc]`. Examples: `0x490a90`, `0x490bc0`, `0x4912a0`, `0x490e70`.
  - The second is the sizer `Get…Size()`, which ends in a plain `ret`: `0x490b30`, `0x490c60`, `0x491340`, `0x490f10`.
  - This unit is name-sorted, and "Data" sorts before "Size".
  - Ground truth is listed corrected. oct-format.md lines 38, 170 and 173 and rooms-sgp-format.md line 107 need the fix; they were not edited here.

  Source: PC disassembly.
  Recheck: `re.py fn 0x490a90 --max-ins 0 | grep ret` prints `ret 8`; `re.py fn 0x490b30 --max-ins 0 | grep ret` prints `ret`.
  Confidence: proven.

- Claim: The estimated precision is high ≈ 99.7%, medium ≈ 98.5%, low ≈ 77%. This is a hold-out test: 30% of the 762 high string pairs are hidden from the string phase, and the other signals have to find them again. Totals over 5 seeds:

  | Confidence | Correct / matched | Precision |
  |---|---|---|
  | high | 670 / 672 | 99.7% |
  | medium | 201 / 204 | 98.5% |
  | low | 44 / 57 | 77% |

  Of the hidden pairs, 33–46 per seed are not re-matched.

  Bias: functions with strings are larger and better connected than average, so the true precision for propagated pairs is probably somewhat lower. The string phase itself is checked another way: 422 of 422 high string pairs that another signal also proposed agree.

  Source: `namemap.py --holdout`
  Recheck: `python3 -I decoders/tools/namemap.py --holdout 0.3 --seed 1` prints "ALL high correct 117 wrong 0".
  Confidence: fitted on data.

- Claim: Inside most compilation units, the PC exe lays out functions in MSVC decorated-name order.

  Source: of 225 units with at least 3 anchor steps, 179 are fully name-sorted, 4 are in source order and 40 are mixed. (Taken from the high pairs of an earlier run.)
  Recheck: `phase_order` mode counts (`Matcher.order_modes`).
  Confidence: fitted on data.

## ghidra_apply_names.py

1. Copy or point the Script Manager at `decoders/tools`.
2. Run `ghidra_apply_names.py`. In the GUI it asks for the TSV and the minimum confidence. Headless:

```
analyzeHeadless <projdir> <proj> -process Freedom.Exe.orig -noanalysis -scriptPath <repo>/decoders/tools \
  -postScript ghidra_apply_names.py tsv=<repo>/decoders/gc_pc_namemap.tsv min=medium mode=namespace dry=0
```

**Naming**
- Functions are named `GC::<Class>::<method>`, e.g. `GC::ZCollisionBase::InstallCollisionBuffer`.
- `mode=flat` gives `gc_ZCollisionBase__InstallCollisionBuffer` instead; `root=` changes the prefix.
- Duplicate names (overloads) get `_<addr>` appended.
- The full GC signature, address, confidence and evidence go into a plate comment line starting with `[gc_pc_namemap]`.

**Safe to re-run**
- Only `FUN_…` / `thunk_FUN_…` names are touched, or names this script set before (under `GC::` or with the flat prefix). `force=1` overrides this.
- The `[gc_pc_namemap]` line is replaced, not duplicated.
- A PC function that several GC functions map to only gets the comment, not a new name.
- `dry=1` lists changes without making them.
- Outside Ghidra, `python3 -I ghidra_apply_names.py [tsv] [min]` prints the plan: 5977 renames at medium, 4152 at high.
- Applied to our Ghidra project on 2026-10-09: 5957 renamed, 15 kept, 0 failures.

**Running it under Ghidra 12 (PyGhidra).** Ghidra 12.1.4 ships without Jython, so on 2026-10-09 the header was changed from `@runtime Jython` to `@runtime PyGhidra` (no other change; the code already runs on Python 3). PyGhidra lives in a venv made from Ghidra's bundled wheels (offline):

```
/Library/Frameworks/Python.framework/Versions/3.11/bin/python3 -m venv tools/pyghidra-venv
tools/pyghidra-venv/bin/pip install --no-index -f tools/ghidra/ghidra_12.1.4_PUBLIC/Ghidra/Features/PyGhidra/pypkg/dist pyghidra
```

Then run headless with that venv active, so `pyghidraRun` does not try to install into the system Python 3.14 (no jpype wheel for 3.14):

```
export JAVA_HOME=/Library/Java/JavaVirtualMachines/jdk-21.jdk/Contents/Home
export VIRTUAL_ENV=$PWD/tools/pyghidra-venv PATH=$PWD/tools/pyghidra-venv/bin:$JAVA_HOME/bin:$PATH
tools/ghidra/ghidra_12.1.4_PUBLIC/support/pyghidraRun -H "$PWD/ghidra" FF -process Freedom.Exe.orig -noanalysis \
  -scriptPath "$PWD/decoders/tools" -postScript ghidra_apply_names.py "tsv=$PWD/decoders/gc_pc_namemap.tsv" min=medium mode=namespace dry=1
```

Plain `analyzeHeadless` cannot run `.py` scripts in Ghidra 12. For the GUI, start Ghidra with `support/pyghidraRun` (same venv).

## Limitations / open issues

- **Destructors:**
  - A PC vtable slot holds the *scalar deleting destructor* (`??_G`), while the GC slot holds the real destructor (GCC 2 dtors take an in-charge flag). These rows carry `dtor-slot(PC: scalar deleting dtor)`.
  - The separate PC `??1` destructor is usually unmatched.
- **Identical-code folding:** many tiny PC functions (`ret`, `xor eax,eax; ret`, `return this+4`) are shared by dozens of GC names. Those rows are `low … icf/stub`. Do not trust them for naming.
- **Platform classes** (`…GC` ↔ `…Wintel/D3D/X86/PC`): slot pairs are "same virtual, different platform implementation". They are capped at medium.
- **Inlining differs.** MSVC inlines more, as in `ConvToOCS` inside `CheckPoint`, and GCC 2 keeps small helpers out of line. One GC function can then correspond to part of a PC function. Call-graph consistency of high string and vtable pairs is about 87–88%, largely because of this.
- **Unmatched PC code:**
  - ZEngineDataBase is virtual only on PC: 138 PC slots, 7 on GC. Its GC-only non-virtual methods are matched only through strings, unit order or the call graph.
  - Wintel/D3D code and CRT have no GC counterpart.
- **Link order** relies on the observed name sort. The sort key (`msvc_key`) approximates MSVC decoration: it ignores argument encoding, so overloads in one bracket are skipped.
- **GC data references** are found with a linear, per-function register tracker (`lis/addi/ori`, `r13`/`r2` small-data bases), not a CFG. A rare clobber can be missed. Jump tables and indirect calls are not followed on either side.
- **Low rows are not validated** beyond the hold-out estimate (≈77%). Treat them as hints.
- **Not done:** Ghidra pseudocode in `re.py fn` (doc 13 says "later"). Using constants/field offsets as a stronger signal. Parameter-count checks (e.g. `ret N` against the GC signature), which would have caught the sizer/reader ambiguity directly.
