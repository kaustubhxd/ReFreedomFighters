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

Tools and format documentation for Freedom Fighters (2003), plus a set of verified C++ ports of 8,769 functions from the
PC executable (see "Verified C++ ports"). This is not a full decompilation of the game. The awesome-list entry type (tool or
decomp) is for the maintainer to choose.

Live progress page: https://kaustubhxd.github.io/ReFreedomFighters/

## Progress

Of 12,955 functions in the PC executable (live numbers on the [progress page](https://kaustubhxd.github.io/ReFreedomFighters/)):

| | by count | by code size |
|---|---|---|
| Verified (checked against the original on two seeds) | ![](https://geps.dev/progress/69.7) 69.7% | ![](https://geps.dev/progress/56.7) 56.7% |
| Ported into the browser game | ![](https://geps.dev/progress/3) 3.0% | ![](https://geps.dev/progress/4.9) 4.9% |

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

`ports/` holds C++ ports of 8,769 functions from the PC executable, each checked against the original code by running
both on random inputs and comparing results, memory writes and faults. `RESULTS.tsv` lists every verified address with
its name and folder. Counting rule: a function counts only when both seed 1 and seed 2 ran 1000 cases each, with status
exact and zero faulting cases. Batch files that mixed verified and unverified functions are not in this copy (95 verified functions are held back for that reason);
thunks, SEH funclets and functions whose specs hook a callee by address are not separated out in this copy.

### Verification status (15 October 2026)

The local project has 9,031 functions with retained two-seed results; 8,769 have publishable source here. Another 95 verified functions are held back in mixed batches, and 170 have no matching source file in the export. The browser port links 384 verified functions.

A checker bug mapped the emulated thread environment block at address zero, which could hide null-pointer faults. A corrected shared harness has been tested, but rollout and full re-verification are pending. These totals describe existing results and have not yet been recertified with that fix.
