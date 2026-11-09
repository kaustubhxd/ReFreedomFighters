# ReFreedomFighters

<img width="1512" height="866" alt="image" src="https://github.com/user-attachments/assets/ed1d89b7-c228-4d1e-8a57-ba37a1935303" />

Reverse-engineering notes and file-format decoders for **Freedom Fighters** (IO Interactive, 2003, Glacier 1 engine),
written while porting the game to the browser. Much of it should also apply to the other Glacier 1
games of that era (Hitman 2: Silent Assassin, Hitman: Contracts, Hitman: Blood Money), which share the same file
families.

**No game data is included.** You need your own copy of the game (the Steam/GOG PC release). Nothing here contains
game files, extracted assets, game text, scripts, audio or executable bytes. The `ports/` folder holds C++ functions
derived from the executable (see "Verified C++ ports" below); they need your own copy of the game to run.

## What is here

| Format | What it is | Spec | Decoder |
|---|---|---|---|
| WHD / WAV / streams.wav / SND | Sound banks (IMA ADPCM, PCM, Ogg) and the named sound event table | `decoders/README.md` | `whd.py` |
| LOC | Localised text tree | `decoders/README.md` | `loc.py` |
| ZGF | TFGZ container: TrueType fonts plus compiled mission/AI scripts (.ppo) | `decoders/README.md` | `zgf.py` |
| PPO | Script bytecode: full VM opcode table (0x00-0x9e) | `formats/opcodes.md` | `ppo_dis.py`, `ppo_list.py` |
| GMS / BUF | Scene geom hierarchy, transforms, per-geom data blocks | `decoders/README.md` | `gms_world.py`, `gms_scripts.py` |
| TEX | Textures: DXT1/DXT3/RGBA/PALN/PALO, mip chains, palettes, animation tables | `formats/tex-format.md` | `tex.py` |
| PRM + ANM | Meshes, skeletons, animation tracks, skinning (matches the exe's skinner) | `formats/skinning-format.md` | `skin.py` |
| OCT | Collision octree | `formats/oct-format.md` | `oct.py` |
| RMC / RMI / SGP | Room trees and the sound graph | `formats/rooms-sgp-format.md` | `rooms.py`, `sgp.py` |
| Pathfinder3 (inside GMS) | AI navigation voxel octree with climb/jump links | `formats/pathfind-format.md` | `pathfind.py` |
| GameCube -> PC name map | Not in this public copy. `decoders/tools/namemap.py` rebuilds it from your own GameCube and PC copies (see below) | `decoders/tools/README.md` | `decoders/gc_pc_namemap.tsv`, `decoders/tools/` |

Also:

- `script-vm/`: a JavaScript VM that runs the game's compiled `.ppo` scripts (loader, interpreter, native registry,
  trace tool). You supply the scripts from your own install. See `script-vm/README.md`.
- `loaders/`: browser-ready JavaScript modules for textures (`tex.mjs`), meshes (`prm.mjs`), animation sampling, the
  skinned-character core and GMS world transforms. They mirror `decoders/tex.py`, `decoders/skin.py` and
  `decoders/gms_world.py`.
- `notes/`: how the browser port works (`how-the-port-works.md`), the PPO script format and VM notes
  (`ppo-scripts.md`).
- `names/ppo_natives.txt`: the engine functions the level scripts call, with call counts and argument counts.
- `decoders/tools/`: `event_classes.py` and `survey_all.py` (scan every scene for class/event usage), plus the RE
  tools for both builds: `re.py` (lookup CLI), `ffre.py` (loaders, x86/PPC analysis, GCC 2.x demangler, MSVC RTTI),
  `namemap.py` (builds the name map), `ghidra_apply_names.py` (applies it in Ghidra), `rvz.py` (GameCube RVZ disc reader) and `xiso.py` (Xbox disc reader).

Everything is Python 3, standard library only unless a tool says otherwise (the RE helpers use `capstone` and
`pefile`). Run scripts with `python3 -I`. The specs mention a few example renders (`*.png`, `*.obj`); those are not shipped because they show game assets. Re-create them with the decoders.

## Status

All file families used by the PC release decode. Open questions are listed at the end of each spec.

## Related work

ReGlacier (ReHitman, BMEdit, ReHitmanTools) covers Hitman: Blood Money; Glacier1AudioTool covers the audio of all
Glacier 1 Hitman games; minexew/Freedom is an earlier (2018) Freedom Fighters format exploration.

## Origin of the GameCube material

The GameCube release of Freedom Fighters ships its executable (`startup_release.elf`) with its symbol table, so its
function and class names are readable. The function names come from that symbol table. The pairing with PC addresses is held back from this public copy; `decoders/tools/namemap.py` rebuilds it from your own copies.
The pairing of those names with PC addresses is our own work (`decoders/tools/namemap.py`). No executable bytes from
either build are included; to rebuild or extend the map you need your own GameCube disc image and PC install.

## What is not here, and why

This repo holds our own documentation, decoders and tools, plus the symbol-name map described in the origin section above. It leaves out
anything that is the game's own content or a direct translation of it:

- **Game files and extracted data:** textures, models, audio, level files, the game's text, its compiled scripts and
  listings of them, collision meshes and renders. These belong to IO Interactive / Electronic Arts.
- **Executable bytes, extracted data and game assets.** None are included. The checked C++ ports in `ports/` are
  functions derived from the game's executable; they contain no executable bytes, and each one runs only with your own
  copy of the game (see `ports/README.md` and `RESULTS.tsv`).
- **The playable browser port.** It is not published here.

None of this is hard to regenerate if you own the game: run the decoders on your own install.

## Project type

A work-in-progress decompilation of Freedom Fighters (2003) for PC: verified C++ ports of 12,703 functions from the
executable (see "Verified C++ ports"), plus the tools and format documentation used to get there. It is not yet a complete
source tree that builds into a full executable: the remaining functions are still being decompiled and verified.

Live progress page: https://kaustubhxd.github.io/ReFreedomFighters/

## Progress

Of 12,955 functions in the PC executable (live numbers on the [progress page](https://kaustubhxd.github.io/ReFreedomFighters/)):

| | by count | by code size |
|---|---|---|
| Verified (checked against the original on two seeds) | ![](https://geps.dev/progress/98.6) 98.6% | ![](https://geps.dev/progress/91.0) 91.0% |
| Ported into the browser game | ![](https://geps.dev/progress/6.5) 6.5% | ![](https://geps.dev/progress/8.7) 8.7% |

## AI assistance

Parts of the documentation, decoders and tools were written with the help of an AI coding assistant (Claude), under the
direction of the maintainer. Every spec is checked against the game data the maintainer owns; please verify anything
you rely on.

## Contact

hello@kaustubh.app

## Legal

Freedom Fighters is (c) IO Interactive / Electronic Arts. This project is not affiliated with or endorsed by them.
The decoders, specs, tools and docs are independently written (MIT licence, see `LICENSE`). The C++ ports in `ports/`
are derived from the game's executable and are shared under the same MIT licence; that licence does not grant any rights
in the game itself.

## Verified C++ ports

`ports/` holds C++ ports of 12,703 functions from the PC executable, each checked against the original code by running
both on random inputs and comparing results, memory writes and faults. `RESULTS.tsv` lists every verified address with
its name and folder. Counting rule: a function counts only when both seed 1 and seed 2 ran 1000 cases each, with status
exact and zero faulting cases. Batch files that mixed verified and unverified functions are not in this copy (51 verified functions are held back for that reason);
thunks, SEH funclets and functions whose specs hook a callee by address are not separated out in this copy.

### Verification status (18 October 2026)

The local project has 12,929 functions with retained two-seed results; 12,703 have publishable source here. Another 51 verified functions are held back in mixed batches, and 175 have no matching source file in the export. The browser port links 841 verified functions.

A checker bug mapped the emulated thread environment block at address zero, which could hide null-pointer faults. A corrected shared harness was rolled out on 16 October 2026 and 6,293 of the verified functions that could be re-run were checked again: 6,090 are still exact with no faulting cases. The rest, 243 rows, are on a re-verify list (faulting cases, mismatches on null pointers, or stale builds) and still count in these totals until they are fixed; about 2,300 verified functions could not be re-run. Separately, the original game most likely runs its x87 floating-point code at 24-bit precision, while these ports were verified at 53-bit; a re-check of the x87 ports at 24-bit is pending.

**Known gap in the call stubs (reported 22 October 2026, issue #1).** When a port calls another function, the checker replaces the callee with a stub that takes its calling convention and argument count from the port's own declaration, ignores ECX/EDX on entry, and leaves ECX/EDX untouched on return. A port that forgets `this`, passes the wrong number of stack arguments, or declares a thiscall callee as stdcall can therefore still match its stub. Running the ports inside the real executable found 51 ports that crash the game although they are `exact-1000-faults0` on both seeds; a reversed argument order in `0x4cd180` was found independently in a WebAssembly build. Counts above were produced with the weaker stubs and may include such ports. The stricter checker now exists: `tooling/strict` (`FF_STRICT_STUBS=1`, see `tooling/STRICT.md`) checks ECX/EDX where the original callee reads them, leaves junk in ECX/EDX after returns and takes the pop count from the original. A re-run of 12,360 verified functions found 10,744 (86.9%) exact on both seeds under it; the 1,616 others are mostly false positives of the checker, with 194 lacking a completed seed-2 run and 618 not re-run at all (details and measured rates in `tooling/STRICT.md`). The counts above and the totals in `RESULTS.tsv` predate the strict stubs and the corrected TEB harness and have not been changed. The classes of defect found are written up in `docs/defect-classes.md`. The browser/WebAssembly port is not published.
