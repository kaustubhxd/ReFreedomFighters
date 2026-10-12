# Decoders

The status table, findings and next steps for all formats live in `../formats/`. Update both files when anything changes.

## whd.py: scene sound banks (WHD + WAV + SND, and root streams.wav)

    python3 whd.py FF-C01A_MAIN.WHD FF-C01A_MAIN.WAV out/ streams.wav FF-C01A_MAIN.SND

- WHD = 16-byte header + 48-byte entries + 8 zero bytes.
- Formats: 0x11 IMA ADPCM (mono, 512-byte blocks), 0x01 PCM16, 0x1000 embedded Ogg Vorbis.
- Bit 0x80000000 on the format = data is in the root `streams.wav` (speech, music), otherwise in the scene `.WAV`.
- SND names entries: after `name\0file.wav\0` comes u32 1, u32 ?, u32 WHD byte offset + 1, f32 duration.
- Verified 2026-10-08 on C01A: all 3,051 entries decode; 2,989 get names from SND.
  ADPCM output matches ffmpeg's IMA decoder to within ~0.3% of full scale
  (the difference is the standard shift-sum vs. multiply step rounding).
  Ogg entries probe as valid Vorbis, 22,050 Hz stereo.

## loc.py: LOC text tree -> JSON

    python3 loc.py FF-C01A_MAIN.LOC out.json

Tree of named nodes; a leaf is a bare string. Strings are UTF-8 (cp1252 fallback).
C01A gives 2,309 strings: menus, hints, item names, stats, mission text and
voice-line subtitles. The subtitle keys match the SND sound names
(e.g. Civ_COMEWITHME_F1_01), so subtitles can be joined to audio directly.


## zgf.py: ZGF container -> files

    python3 zgf.py FF-C01A_MAIN.ZGF out/

ZGF is not just fonts. It's a TFGZ file container (raw-DEFLATE wrapped) holding:
- 7 TrueType fonts (Akzidenz Grotesk family), usable directly in the browser.
- The level's compiled scripts: `scripts\<level>\*.ppo` plus shared
  `scripts\AllLevels\*.ppo`, built from `.sdl` sources. C01A has 31.

The .ppo files are mission and AI logic as bytecode: declared ZGEOMREF
variables, named states (C01A_Jones.ClimbTraining, .MolotovTraining, ...),
native calls (AimWeaponAtGeom, FireWeapon, HideHint, GetTime, ...),
message names and a code section. Earlier notes said the Steam build had no
scripts; that was wrong. The bytecode is decoded: see the PPO section below.

## PPO scripts: ppo_dis.py, ppo_list.py, opcodes.md

    python3 -I zgf.py FF-C01A_MAIN.ZGF zgf_C01A/
    python3 -I ppo_list.py zgf_C01A/scripts C01A/C01A_Jones.ppo      # one labelled listing
    python3 -I ppo_list.py --all zgf_C01A/scripts ppo_listings/C01A   # every script
    python3 -I ppo_dis.py zgf_C01A/scripts/*/*.ppo                    # clean-decode check

- `../formats/opcodes.md`: the full VM opcode table (0x00-0x9e) and VM model, from Freedom.Exe `FUN_005f56f0`.
- Run `ppo_list.py --all` on your own extracted ZGF to get listings (not shipped here: they contain the game's scripts).
- `../names/ppo_natives.txt`: the 224 native calls those scripts use, with counts and arg/return counts.

(The ZGFs mix AllLevels/Alllevels/alllevels; ppo_list.py writes them all to one AllLevels/ folder. The duplicates are identical apart from the path line.)

## OCT collision: oct.py

    python3 -I oct.py FF-C01A_MAIN.OCT [-v] [--obj out.obj] [--all-instances] [--rooms N]

Reads the sibling PRM/GMS/BUF. Spec and evidence: `oct-format.md`.

## Rooms, sound graph, GMS world transforms: rooms.py, sgp.py, gms_world.py

    python3 -I rooms.py FILE.RMC|FILE.RMI|STEM [--gms FILE.GMS] [--oct FILE.OCT] [-v] [--json out.json]
    python3 -I sgp.py FILE.SGP [--gms FILE.GMS] [--oct FILE.OCT] [-v] [--json out.json]
    python3 -I gms_world.py FILE.GMS [--buf FILE.BUF] [--oct FILE.OCT --prm FILE.PRM]

Spec: `rooms-sgp-format.md`. Use `gms_world.py` for world matrices of GMS geoms (oct.py's own transform is wrong for non-vertical rotations; C01A_collision.obj was built with it and only includes the instances it verified).

## ANM skinning: skin.py (2026-10-08)

    python3 -I skin.py FF-C01A_MAIN.PRM --list                       # characters (PRM part chains) and clips
    python3 -I skin.py FF-C01A_MAIN.PRM --check                      # numeric checks, prints CHECKS PASS
    python3 -I skin.py FF-C01A_MAIN.PRM --clip Walk_Forward --tick 6 --png hero.png --obj hero.obj
    # options: --entry 0x.. (character, default = first tag-14 binding = Hero in C01A), --clip-id N, --root (apply GROUND root motion)

Stdlib only. Samples ANM tracks, applies fitting and hierarchy, builds the palette and skins the mesh exactly as the PC exe does. Spec with addresses, confidence and a browser vertex shader: `skinning-format.md`. Renders: `skin_hero.png`, `skin_soldier.png`, `skin_mapping_compare.png` (correct per-part palette vs the old wrong direct mapping). Not done: clip blending, upper-body layers, root motion placement.

## TEX textures: tex.py (2026-10-08)

    python3 -I tex.py list FF-C01A_MAIN.TEX
    python3 -I tex.py validate FF-C01A_MAIN.TEX      # prints OK with record/mip counts
    python3 -I tex.py export FF-C01A_MAIN.TEX out/    # one PNG per texture per mip
    python3 -I tex.py anims FF-C05A_MAIN.TEX          # animated-texture frame tables
    python3 -I tex.py sheet ...                       # contact sheet (see tex-format.md)

Full layout, evidence records and the list of browser-loader changes: `tex-format.md`.

## Pathfinding: pathfind.py (2026-10-08)

    python3 -I pathfind.py FF-C01A_MAIN.GMS                    # summary + checks, RESULT: PASS (exit 1 on failure)
    python3 -I pathfind.py FF-C01A_MAIN.GMS --png top.png --obj cells.obj   # also -v, --dump-dblk

The AI navigation data is inside the GMS, in the `Pathfinder3` geom's data block (a packed voxel octree with walkability, connectivity and climb/jump links). Spec: `pathfind-format.md`.
