# TEX format (Freedom Fighters PC): full layout

Decoder: `decoders/tex.py` (stdlib only). Contact sheet: `decoders/tex_c01a_contact.png`, made from C01A texIds 399, 313, 300, 207, 200, 715 and 734, each shown with its whole mip chain.

Status: the whole PC TEX layout is now known: header, both LUTs, every record field, mip chains, NLAP palettes, the OLAP variant and animation tables. All three sample files parse to EOF, and every mip, palette, LUT entry and animation table is accounted for (§6). Two fields stay partly open: `+32` (`unk32`) and the TEX flag `0x100` (§7).

Sampler and blend state is **not in TEX**. It comes from a render-flags word in the PRM entry header (§5).

## Conventions

- Sample paths (container):
 - `C01A=<extracted>/C01A/SCENES/Singleplayer/C01A/FF-C01A_MAIN`
 - `C05A=<extracted>/C05A/SCENES/Singleplayer/C05A/FF-C05A_MAIN`
 - `SU=<extracted>/SU/SCENES/FF-StartUp`
- FourCCs. The file stores the engine's MSVC multi-char constants little-endian, so the bytes read backwards:

 | File bytes | Engine constant | Class |
 |---|---|---|
 | `1TXD` | `'DXT1'` (0x44585431) | `ZBitmapDXT1` |
 | `3TXD` | `'DXT3'` (0x44585433) | `ZBitmapDXT3` |
 | `ABGR` | `'RGBA'` (0x52474241) | `ZBitmap32` |
 | `NLAP` | `'PALN'` (0x50414c4e) | `ZBitmapPal` |
 | `OLAP` | `'PALO'` (0x50414c4f) | `ZBitmapPalOpac` |

- Class names come from MSVC RTTI. The vtable slot that holds the loader is `[17]` for every `ZBitmap*` class.
- Key functions:
 - Loader: `ZTextureManagerD3D[2]` = `FUN_00613380`.
 - Record parser: `ZBitmap::Load` = `FUN_00638f20`.

## 1. File layout

```
+0 u32 lut1Off -> 2048 x u32: record offset for texId i (0 = empty)
+4 u32 lut2Off -> 2048 x u32: animation-table offset for texId i (0 = none)
+8 u32 3 (constant in samples; not read by the PC loader)
+12 u32 4 (constant in samples; not read by the PC loader)
+16 content area texture records, back to back; animation tables sit inline
                     at the offsets LUT2 names
lut1Off LUT1 (8192 bytes)
lut2Off LUT2 (8192 bytes), then EOF
```

To walk the content area, start at 16. If the current offset is a LUT2 target, skip `4 + 4*count`. Otherwise read a record and advance by its `size`. The walk must land exactly on `lut1Off`.

## 2. Texture record

| Off | Type | Field | Notes |
|---|---|---|---|
| +0 | u32 | size | Whole record, including this field. The next record starts at `off + size`. Always `8 + 0x1d + strlen(name) + Σ(4 + mipSize) [+ 4 + 4*palCount] [+ w*h]` |
| +4 | 4cc | type | The loader dispatches on this field |
| +8 | 4cc | type again | `ZBitmap::Load` checks it against the class's own type. The parser's body pointer starts here |
| +12 | u32 | texId | The renderer registers the texture under this id, not under the LUT1 slot. LUT1 index == texId in every sample |
| +16 | u16 | height | |
| +18 | u16 | width | |
| +20 | u32 | mipCount | Number of stored levels. In the samples it is either 1 or the full chain to 1x1 |
| +24 | u32 | flags | `0x80` animated (LUT2 table). `0x10` bump/EMBM upload path. `0x100` seen once and not read by the loader |
| +28 | u32 | materialTypeId | Surface type. The renderer copies it to a byte at texture entry `+2`, where bullet impacts read it (§4) |
| +32 | u32 | unk32 | 0 on every non-NLAP record. Unknown on NLAP (§7) |
| +36 | char[] | name | NUL-terminated. Paths for UI/font textures, e.g. `Fonts\GFB_____.TTF-14#28` |
| … | | mips | `mipCount` × `{u32 byteCount; u8 data[byteCount]}`. Level 0 is `width`×`height`. Each later level halves both sides (floor, min 1) |
| … | | NLAP/OLAP only | `u32 palCount; u32 palette[palCount]` |
| … | | OLAP only | `u8 opacity[width*height]` (base level only) |

**Mip payload size per level (w×h):**

| Format | Bytes per level |
|---|---|
| DXT1 | `max(1,⌈w/4⌉) * max(1,⌈h/4⌉) * 8`. Levels of 2×2 and 1×1 still take one 8-byte block |
| DXT3 | Same block count × 16 |
| RGBA8 (`ABGR`) | `w*h*4`. Byte order **R,G,B,A** |
| PAL8 (`NLAP`) | `w*h` one-byte indices. Palette entries are 4 bytes: **R,G,B,A** |

Rows run top to bottom. All dimensions in the samples are powers of two, up to 512.

### Animation table (at `LUT2[texId]`)

```
u32 count; u32 frameTexId[count]
```

- `frameTexId[0]` is the owning texture.
- Example from C05A: `253 FF_C05a_Rain_02a_0000` has 8 frames: 253…260.
- Only the first frame carries flag `0x80`. The other frames are ordinary records.

## 3. Formats in the samples

| File | Records | DXT1 | DXT3 | RGBA8 | PAL8 | Mip levels | Full chain / single level / partial | Anim tables |
|---|---|---|---|---|---|---|---|---|
| C01A | 602 | 369 | 49 | 121 | 63 | 3459 | 395 / 207 / 0 | 0 |
| C05A | 444 | 252 | 24 | 105 | 63 | 2385 | 278 / 166 / 0 | 1 |
| StartUp | 515 | 55 | 19 | 93 | 348 | 1065 | 85 / 430 / 0 | 0 |

- PAL8 (`NLAP`) records are all UI art: font glyph pages, borders, load bars, the cursor. Palette sizes run from 1 to 256 entries.
- Every PAL8 record has a single level.
- No `OLAP` records appear in any sample.

## 4. materialTypeId (`+28`) values, fitted on texture names

| Id | Surface | Example textures |
|---|---|---|
| 0 | none / effects / UI | |
| 1 | effects (smoke, glass impacts) | |
| 10 | asphalt / tarroad | `FF_Effects_BulletHole_Asphalt_02a` |
| 20 | carpet / fabric | `BulletHole_Carpet` |
| 40 | ceramic | |
| 50 | fabric | |
| 60 | flesh / characters | |
| 70 | glass | `BulletHole_Glass` |
| 80 | glass (C05A) | |
| 100 | ground | |
| 110 | metal | |
| 120 | metal (C05A) | |
| 130 | paper / posters | |
| 140 | plastic | `BulletHole_Plastic` |
| 150 | snow | `BulletHole_Snow` |
| 160 | soil | `BulletHole_Soil` |
| 170 | stone / facade | |
| 180 | rain / water | |
| 190 | wood | |
| 240 | van | |
| 250 | ground / rain (C05A) | |

The engine matches the id against `ZMaterialDesc+0x34` (`GetTextureTypeId`). The names, sounds and decals come from the material-descriptor geoms, not from TEX.

## 5. Sampler and material state (outside TEX)

TEX holds no wrap, filter or blend state.

- **Filtering.** MIN/MAG/MIP filter and anisotropy are global renderer settings (globals `0x6efc70..0x6efc7c`). They are not set per texture.
- **Everything else.** It comes from three PRM entry header fields. Every draw path passes them to `ZRenderWintelD3D[167]` = `FUN_006113d0` (vtable byte offset `0x29c`):

 | PRM entry field | Argument | Meaning |
 |---|---|---|
 | `+0x20` | flags | Render-state bits, table below |
 | `+0x38` | colour | ARGB colour. Used as `TEXTUREFACTOR` in one renderer mode |
 | `+0x44` | alphaRef | Alpha-test reference |

**Bits of PRM `+0x20`** (D3D8 enums in brackets):

| Bit | Effect in `FUN_006113d0` | Typical textures (C01A) |
|---|---|---|
| any of `0x402607` | `ALPHABLENDENABLE=1`. When none of these bits is set: blend off, alpha test off | |
| `0x2000` | Multiply: `SRC=ZERO`, `DEST=SRCCOLOR`. Fog colour slot 3 | `FF_Vehicles_Shadowmap_01a` (8/8) |
| `0x2` without `0x400` | Additive: `SRC=SRCALPHA`, `DEST=ONE`. Fog colour slot 2 | glows, flashes |
| otherwise (blend on) | Normal: `SRC=SRCALPHA`, `DEST=INVSRCALPHA` | |
| alphaRef ≠ 0 (blend branch only) | `ALPHATESTENABLE=1`, `ALPHAFUNC=GREATER`, `ALPHAREF=alphaRef` | `FF_C01A_Paper_03a` (ref 128) |
| `0x4000` | `ADDRESSU = CLAMP`, else WRAP | smoke, explosions |
| `0x8000` | `ADDRESSV = CLAMP`, else WRAP | smoke, explosions |
| `0x20000` | `ZFUNC = ALWAYS`, else `LESSEQUAL` | crosshairs, sky |
| `0x40000` | `ZWRITEENABLE = 0` | effects, decals |
| `0x80000` | `CULLMODE = NONE` (two-sided), else `CW` | foliage/effects, wheels |
| `0x100000` | `FOGENABLE = 0` | crosshairs, HUD-in-world |

Other bits occur but `FUN_006113d0` does not test them: `0x10`, `0x80`, `0x800` and `0x200000` are very common, plus `0x1000`, `0x800000` and `0x8000000`. They are probably consumed by other renderer code (lighting/env-map) and are not yet mapped.

## 6. Validation (`tex.py validate`)

**Checks.** For each record:
- the type is known and the two type fields match;
- the payload ends exactly at `off + size`;
- `size == 8 + serialized size`;
- `1 ≤ mipCount ≤ full chain`;
- every mip's byte count matches its format and size;
- PAL8 indices are below `palCount`;
- `LUT1[texId] == off`;
- flag `0x80` is set exactly when `LUT2[texId] != 0`.

Global checks:
- the content walk lands on `lut1Off`;
- every LUT1 entry hits a record of the matching texId;
- the LUT1 count equals the record count;
- every LUT2 table is met in the walk, starts with its own texId, and names existing texIds;
- the file size equals `lut2Off + 8192`.

**Results.** All three files pass with 0 errors:

```
$ python3 -I decoders/tex.py validate $C01A.TEX $C05A.TEX $SU.TEX
OK FF-C01A_MAIN.TEX: records=602 mips=3459 (full chain 395, single level 207, partial 0) mipBytes=14583760 formats={'RGBA8': 121, 'DXT1': 369, 'DXT3': 49, 'PAL8': 63} animTables=0 flags={'0x100': 1, '0x0': 601}
OK FF-C05A_MAIN.TEX: records=444 mips=2385 (full chain 278, single level 166, partial 0) mipBytes=8628528 formats={'DXT1': 252, 'RGBA8': 105, 'DXT3': 24, 'PAL8': 63} animTables=1 flags={'0x0': 443, '0x80': 1}
OK FF-StartUp.TEX: records=515 mips=1065 (full chain 85, single level 430, partial 0) mipBytes=5324160 formats={'DXT1': 55, 'DXT3': 19, 'RGBA8': 93, 'PAL8': 348} animTables=0 flags={'0x0': 515}
```

- A corrupted copy (one mip size overwritten) fails, with exit code 1.
- Exporting every level of C01A writes 3459 PNGs in about 9 s.

## 7. Open questions

1. **`unk32` (`+32`), NLAP only.** The value looks random. Single-colour fills are 0. Two identical `Border_A_01#0` records differ by 1 (`0x3f3f0779` / `0x3f3f077a`), so it is not a pure content hash. It may be a UI-generator id or a hash that includes a counter. It is stored at `ZBitmap+0x24`, and the loader never uses it. Rendering can ignore it.
2. **TEX flag `0x100`.** It appears only on `FF_Vehicles_Shadowmap_01a`. No PC load or upload path tests it: the only tested bits are `0x10` (upload) and `0x80` (install). It is probably a tool-side flag.
3. **Animated-texture frame rate.** The rate and the playback mode are not in TEX. `ZPrimDrawEntry::GetTextureFrame(i)` (PC `0x658f10`) returns `table[1+i]` for i > 0. Who advances `i` is not traced. Candidates: `ZTextureAnim` geoms in GMS, or `ZDrawBuffer::DrawSpriteArray`.
4. **PRM `+0x20` bits not mapped** (see the list under the §5 table).
5. **Header `+8`/`+12` (3, 4).** Their meaning is unknown and the loader does not read them. They may be a version and a ZBitmap class count, or similar.

## 8. Evidence records

Each record gives:
- **Claim**
- **Source**
- **Recheck:** a command and its expected output
- **Confidence:** proven | fitted on data | inferred | guess

**E1. Header: `+0` = LUT1 offset, `+4` = LUT2 offset, 2048 slots each.**
- Source: `FUN_00613380`:
 - `6133c7 mov eax,[ebx]; add eax,ebx` gives the LUT1 base.
 - `6133d1 lea eax,[ebx+ecx]` (ecx = `[ebx+4]`) gives the LUT2 base.
 - The loop bound is `61362a cmp eax,0x800`.
 - `mov ecx, dword ptr [ebx + 4]`
 - `mov eax, dword ptr [ebx]`
 - `lea eax, [ebx + ecx]`
 - `cmp eax, 0x800`
- Data: `tex.py validate` reports "file size == lut2Off+8192" with no error on all 3 files.
- Confidence: **proven**.

**E2. LUT1[i] is a record offset (0 = empty). The type is read at record `+4`, and the parser body starts at record `+8`.**
- Source: `613440 mov eax,[ecx+eax*4]`; `613445 je` (skip on 0); `613450 mov eax,[eax+ebx+4]`; `61344b lea ecx,[ebx+8]; add ecx,eax`.
- Confidence: **proven**.

**E3. Type dispatch: `'PALN'`→`ZBitmapPal`, `'DXT1'`, `'DXT3'`, `'PALO'`→`ZBitmapPalOpac`, `'RGBA'`→`ZBitmap32`. Any other type traps.**
- Source: the cmp chain at `613454` / `613461` / `613468` / `6134fe` / `613505`, then `int3` at `613519`. The class names come from the vtable slots of the callees: `639240` = `ZBitmapPal[17]`, `639270` = `ZBitmapPalOpac[17]`.
- Confidence: **proven**.

**E4. Record fields `+8`…`+36` as in §2.**
- Source: `ZBitmap::Load` `FUN_00638f20` (`ZBitmap[17]`) reads the body (record `+8`) in order:
 - `+0` type, checked `638f72 cmp edx,[ebx+4]`
 - `+4` → `[this+0x1c]` (`638fc7`)
 - `+8` hi16 → vfunc `+0x74`, lo16 → vfunc `+0x78` (`639011`–`639022`)
 - `+0xc` → vfunc `+0x5c`
 - `+0x10` → vfunc `+0x4c`
 - `+0x14` → vfunc `+0x2c`
 - `+0x18` → vfunc `+0x24`
 - `+0x1c` = name (`639156 mov [ebx+0x18],esi`)
- Slot targets, from the `ZBitmap` vtable:
 - `[29]=4870b0` set `+8`; `[30]=650dc0` set `+0xc`; `[7]=5f2de0` get `+8`; `[8]=64a6f0` get `+0xc`
 - `[23]=639c50` SetMipCount (`[this+0x10]`, allocates 0x14-byte mip slots); `[13]=49d6b0` get `+0x10`
 - `[19]=6106d0` set flags `+0x20`; `[18]=638ce0` get flags
 - `[11]=639c40` set `+0x29`; `[12]=638c80` get `+0x29`
 - `[9]=639ba0` set `+0x24`; `[10]=6387c0` get `+0x24`
 - `[20]=452e10` get texId `+0x1c`
- Recheck (slot table):
 ```
 python3 -I -c "import sys;sys.path.insert(0,'decoders/tools');import ffre;v=ffre.PC.vtables['ZBitmap'][1];print([hex(v[i]) for i in (7,8,9,10,11,12,13,18,19,20,23,29,30)])"
 ```
 Expected: `['0x5f2de0','0x64a6f0','0x639ba0','0x6387c0','0x639c40','0x638c80','0x49d6b0','0x638ce0','0x6106d0','0x452e10','0x639c50','0x4870b0','0x650dc0']`.
- Confidence: **proven**.

**E5. Record `+18` is width and `+16` is height.**
- Source: `FUN_00612e70` (`ZTextureManagerD3D[4]`, replacement-image path). It calls `GdipBitmapGetPixel(bmp, x=[ebx+8]+i, y=[ebx+0xc]+row)` with the inner loop `i < vfunc+0x1c` (= `[this+8]` = record `+18`) and the row stride `width*4`.
- Data: `FF_ITM_Binoculars_01a` (SU) is 256×128 and its mip 0 is 16384 bytes, which is DXT1 64×32 blocks. The facade in the contact sheet renders correctly as 256 wide.
- Confidence: **proven**.

**E6. Mip chain: `mipCount` × `{u32 size; data}`. w and h are halved per level with `if (v>1) v>>=1`. Each level goes to vfunc `+0x58` (data, size, w, h, level, 0).**
- Source: `FUN_00638f20` loop `6391a0`–`639224`:
 - `6391f5 call [eax+0x58]`
 - `6391fb add edi,esi` (advance by size)
 - `639202 sar eax,1` / `63920f sar esi,1` (halving)
- Data: on all 3 files every level's byte count equals the format formula (6909 levels, 0 mismatches).
- Confidence: **proven** (layout) and **fitted on data** (size formula).

**E7. `size = 8 + 0x1d + strlen(name) + Σ(4+mipBytes) [+4+4*palCount]`.**
- Source: `ZBitmap[15]` = `FUN_00638610` (serialized size):
 - start `0x1d + strlen`
 - `+ (mip.size + 4)` per level
- `ZBitmapPal[15]` = `FUN_00638670` adds `4*palCount + 4`.
- Data: `tex.py validate` checks this for every record: 0 errors.
- Confidence: **proven**.

**E8. `ABGR` texels are bytes R,G,B,A.**
- Source: `ZBitmap32[5]` = `FUN_006387d0` builds its source pixel-format masks R=`0xff`, G=`0xff00`, B=`0xff0000`, A=`0xff000000` (little-endian u32). The upload path in `FUN_00612c00` uses the D3D side `A8R8G8B8` masks.
- Confidence: **proven**.

**E9. NLAP: one index byte per texel, then `u32 palCount` and `palCount` × u32 colours (bytes R,G,B,A).**
- Source, PC:
 - `ZBitmapPal::Load` `FUN_00639240`: `63924e mov edx,[eax]` (count after the mips); `639253 [esi+0x2d]=palette`; `639256 [esi+0x32]=count`; returns `eax+edx*4`.
 - The texel conversion `FUN_00638b80` (`ZBitmapPal[5]`) does `movzx ecx, byte [esi+ebx]` then `push [palette+ecx*4]`, with the same R=`0xff` mask set.
- Data: palette sizes 1…256. All indices are below `palCount` (validate). Font pages decode to legible glyphs (contact sheet, row 6).
- Confidence: **proven**.

**E10. OLAP (`'PALO'`) = NLAP + `u8 opacity[width*height]`.**
- Source: `FUN_00639270`:
 - `63928d edi = palette end`
 - `[ebx+0x36]=edi`
 - returns `edi + vfunc1c*vfunc20` (`6392a1 imul`, `6392a4 add`)
- No OLAP records in the samples.
- Confidence: **proven** (code). Not exercised on data.

**E11. Flag `0x80`: the record owns an animation table at `LUT2[texId]`, laid out `u32 count; u32 texId[count]`.**
- Source, PC: `FUN_00613380` `613586 call [eax+0x48]` (get flags) → `test al,al; jns` (bit 7). Then `[eax+0x50]` (texId) → `ebx=[lut2+texId*4]+base`, copy `count+1` dwords, stored at texture entry `+0x3c`.
- Consumer: `ZPrimDrawEntry::GetTextureFrame` (PC `0x658f10`) reads `[entry+0x3c] + 4 + i*4`.
- Recheck: `python3 -I decoders/tex.py anims $C05A.TEX` prints `253 FF_C05a_Rain_02a_0000: 8 frames [253, 254, 255, 256, 257, 258, 259, 260]`.
- Data: tables sit inline in the content area (the walk must skip them). Frame 0 is the owner.
- Confidence: **proven** (code) and **fitted on data** (placement, frame 0 = self).

**E12. Flag `0x10` selects the bump-map upload path `FUN_00612a20` (when the device supports it). The `'EMBM'` type takes the same path.**
- Source: `FUN_006130c0` `61319b test al,0x10; jne 613257`; `6131a3 cmp edi,0x454d424d`.
- Not present in the samples.
- Confidence: **proven**.

**E13. Texture flag `0x100` has no PC load-time effect.**
- Source: the only flag tests on the load/upload path are `0x80` (`613589`) and `0x10` (`61319b`). `FUN_00612900` and `FUN_00612c00` (upload) do not call the flags getter (`+0x48`).
- Confidence: **inferred**. Other code could read the flags through the bitmap before it is freed. Not found.

**E14. `+28` is the surface `materialTypeId`.**
- Source, PC:
 - `ZBitmap::Load` → vfunc `+0x2c` = `[this+0x29]`.
 - `FUN_006130c0`: `6130dc call [eax+0x30]` (`ZBitmap[12]` = `638c80`, get `+0x29`) → `6130df mov [edi+2],al` (texture entry byte `+2`).
- Source, PC:
 - `ZProjectile::ShotImpact` → `ZProjectile::GetMaterialDesc(uint)` → `ZEngineDataBase::GetMaterialDesc`, which compares `desc+0x34` (`ZMaterialDesc::GetTextureTypeId`).
- Data: the values in §4 match surface names, e.g. every `BulletHole_<Surface>` texture. Check with:
 ```
 python3 -I -c "import sys;sys.path.insert(0,'decoders');import tex;[print(t.material,t.name) for t in tex.TexFile('$C01A.TEX').textures if 'BulletHole' in t.name]"
 ```
- Confidence: **proven** (field path, both builds). The value→surface table is **fitted on data**.

**E15. `unk32` (`+32`) is nonzero only on NLAP records, and the loader only stores it.**
- Source: vfunc `+0x24` = `639ba0` (`mov [ecx+0x24],eax`). The getter `[10]` = `6387c0` has no caller on the load path.
- Recheck: `python3 -I decoders/tex.py list $C01A.TEX --fields | grep -v PAL8 | grep -vc " 0x00000000 "` prints `2` (the two header lines).
- Confidence: **proven** for "stored, unused at load". The meaning is a **guess** (§7.1).

**E16. Header `+8`/`+12` are not read by the loader.**
- Source: `FUN_00613380` touches only `[ebx]` and `[ebx+4]` of the header.
- Data: 3 and 4 in all samples (`tex.py list` header line).
- Confidence: **proven** (not read). The meaning is unknown.

**E17. At load the renderer may skip the top mip levels (texture-quality setting `[0x70039c]+0x93`). For DXT it never starts on a level under 4×4.**
- Source: `FUN_00612900` loop `612960`–`612993`, then `CreateTexture(w, h, levels=mipCount-start, 0, fmt, MANAGED)` at `6129b1` and one memcpy per level (`6129e9`).
- Confidence: **proven**. The browser can upload all levels.

**E18. DXT1 blocks with `c0 <= c1` use 3-colour mode, and index 3 is transparent black.**
- Source: D3D8 DXT1 semantics. The textures are uploaded raw as `D3DFMT_DXT1` (`612933`).
- Confidence: **inferred** (standard hardware behaviour, not engine code).

**E19. In the samples LUT1 index == texId, and every texId is below 2048.**
- Source: validate. The renderer itself registers by the record texId (`6134a5`–`6134bc`: `[obj+0x1c]*0x44`).
- Data:
 ```
 python3 -I -c "import sys;sys.path.insert(0,'decoders');import tex;f=tex.TexFile('$C01A.TEX');print(max(t.tex_id for t in f.textures))"
 ```
 prints `2007` (C01A; the range is 200..2007).
- Confidence: **fitted on data**. The old note "C01A texIds exceed 2047" concerned PRM material IDs, which carry high bits. Those still need `& 0x7ff`.

**E20. Sampler and blend state comes from PRM entry `+0x20` / `+0x38` / `+0x44` through `ZRenderWintelD3D[167]`.**
- Source, call site (`ZRObjectInstanceStripD3D[1]` = `FUN_00619c20`): `619c6c mov eax,[eax+4]; mov eax,[eax+8]; push [eax+0x44]; push [eax+0x38]; push [eax+0x20]; call [edx+0x29c]`.
- The same chain in the skinned draw `FUN_00617400` (`617481`) leads to the object whose `+0x98`/`+0x9c` are the PRM entry's palette runs (see `skinning-format.md`). So the object is the PRM entry.
- Source, `FUN_006113d0`. It calls `SetRenderState` (vtable `+0xc8`) and `SetTextureStageState` (`+0xfc`):
 - `61144e test ebx,0x402607` (blend)
 - `61147f and eax,0x2000` → `60fdd0(1,3)` (SRC/DESTBLEND)
 - `6114c4 test ebx,0x400` / `6114d1 test bl,2` → DEST 2 or 6
 - `6114e5 test edi,edi` → ALPHATEST plus `60fd70(5,edi)` (ALPHAFUNC/ALPHAREF)
 - `61159a 0x40000` → RS 14
 - `6115de 0x20000` → RS 23
 - `611622 0x80000` → RS 22
 - `611666 0x100000` → RS 28
 - `6116c4 shr eax,0xe` → TSS 13 (ADDRESSU)
 - `6116e2 shr ebx,0xf` → TSS 14 (ADDRESSV)
- Data: `0x2000` appears only on the 8 `FF_Vehicles_Shadowmap_01a` entries (multiply = shadow). Clamp bits sit on smoke and explosions. `0x20000` sits on crosshairs and sky. Of the entries with alphaRef ≠ 0, 46 of 47 across the 3 scenes also carry a blend-mask bit, as the code requires.
- Confidence: **proven** (bit → D3D state). The PRM field identity is **inferred** (pointer chain) plus **fitted on data**.

**E21. Texture filtering is global, not per texture.**
- Source: `MINFILTER`/`MAGFILTER`/`MIPFILTER`/`MAXANISOTROPY` are set from the globals `[0x6efc74]`, `[0x6efc70]`, `[0x6efc78]`, `[0x6efc7c]` at `0x608a9b`…`0x608ae6` and `0x611049`….
- Confidence: **proven**.

## 9. What the browser loader must change

1. **Parse mips.** After the name, read `mipCount` × `{u32 size; data}`, halving w and h (floor, min 1). Upload every level, with DXT block size `max(1, ⌈w/4⌉)`. In WebGL2 with `WEBGL_compressed_texture_s3tc`:
 - DXT1 upload: `COMPRESSED_RGBA_S3TC_DXT1_EXT`. Use the RGBA variant so 3-colour blocks become transparent.
 - DXT3 upload: `COMPRESSED_RGBA_S3TC_DXT3_EXT`.
 - Without the extension: decode on the CPU (see `tex.py decode_dxt`) or use `generateMipmap` on the base level.
2. **Single-level textures.** `mipCount == 1` (430 in StartUp, mostly UI) needs either `generateMipmap` or `minFilter = LINEAR` (no mipmap). A mipmapped min filter on an incomplete chain makes the texture black.
3. **Decode NLAP.** Read indices (`w*h` bytes) at mip 0, then `u32 palCount` and RGBA palette entries; expand to RGBA. Optionally handle OLAP: palette, then `w*h` alpha bytes.
4. **Walk the content area correctly.** Before reading a record, skip any LUT2 target (`u32 n; n*u32`). Never rely on "records are contiguous": C05A has one inline table. The simplest fix is to resolve textures only through LUT1 (`lut1[texId]`), which never points at a table.
5. **Animated textures.** If flags & `0x80`, read `lut2[texId]` → frame texIds; cycle frames (rate unknown; §7.3).
6. **Material state.** Take blend, alpha-test, wrap, cull and depth state from PRM entry `+0x20`/`+0x44` (§5), not from the texture format:
 - additive for bit `0x2` (without `0x400`);
 - multiply for `0x2000`;
 - alpha test `> alphaRef/255` only when a blend bit is set;
 - `CLAMP_TO_EDGE` per axis for `0x4000`/`0x8000`;
 - `depthMask(false)` for `0x40000`;
 - `depthFunc(ALWAYS)` for `0x20000`;
 - no culling for `0x80000`;
 - no fog for `0x100000`.

 Today's viewer presumably treats any alpha-capable format as blended. That is wrong for opaque DXT3/RGBA surfaces.
7. **Keep texId registration.** Register by record `+12` texId, not by LUT1 slot. They are equal in every sample, but the engine uses `+12`. Keep `& 0x7ff` on PRM material IDs.
8. **Optional.** Expose `materialTypeId` (`+28`) for impact effects and footstep sounds later.
