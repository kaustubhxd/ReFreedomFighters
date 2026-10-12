# ReFreedomFighters

Reverse-engineering notes and file-format decoders for **Freedom Fighters** (IO Interactive, 2003, Glacier 1 engine),
written while porting the game to the browser. Much of it should also apply to the other Glacier 1
games of that era (Hitman 2: Silent Assassin, Hitman: Contracts, Hitman: Blood Money), which share the same file
families.

**No game data is included.** You need your own copy of the game (the Steam/GOG PC release). Nothing here contains
game files, extracted assets, game text, scripts, audio, executable bytes or decompiled game code.

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
- **Executable bytes and disassembly or decompiled code of the game.** A function-by-function rebuild of the
  executable is a derivative of the copyrighted program, so we do not publish it. The decoders and specs here are
  independent descriptions of the formats and rebuild nothing from the exe.
- **The playable browser port.** It is not published here.

None of this is hard to regenerate if you own the game: run the decoders on your own install.

## Project type

Tools and format documentation for Freedom Fighters (2003). This is not a decompilation and contains no decompiled game
code. Entry type for the awesome-decomp-games list: `tool`.

## AI assistance

Parts of the documentation, decoders and tools were written with the help of an AI coding assistant (Claude), under the
direction of the maintainer. Every spec is checked against the game data the maintainer owns; please verify anything
you rely on.

## Contact

hello@kaustubh.app

## Legal

Freedom Fighters is (c) IO Interactive / Electronic Arts. This project is not affiliated with or endorsed by them.
It contains only independently written documentation and code (MIT licence, see `LICENSE`).
