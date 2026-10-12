# Freedom Fighters character skinning (PRM skin + ANM pose)

Status: **solved**. The PC executable (`Freedom.Exe.orig`) proves the whole
chain from ANM keys to skinned vertices. Reference decoder:
`skin.py` (stdlib only). Renders: `skin_hero.png`, `skin_soldier.png`,
`skin_mapping_compare.png`.

Confidence levels:
- **PROVEN**: read directly from the PC disassembly at the address given, and
 confirmed numerically on the C01A/C05A data.
- **VERIFIED**: a data relationship that holds exactly on every sample, with no
 separate code proof.
- **INFERRED**: a reasonable assumption that the visual output supports but
 that no code proves.


## 1. The one convention that matters: stored matrices

The engine stores a 3x3 rotation as 9 floats `m` (row-major) related to the
ordinary column-vector rotation `R` (`p' = R p`) by

```
m = S * R^T R = m^T * S S = [[0,0,1],[0,1,0],[1,0,0]]
```

(**PROVEN**.) `FUN_004df1e0` (quat→matrix) writes
`m0=xz+wy, m1=yz-wx, m2=1-(xx+yy), m3=xy-wz, m4=1-(xx+zz), m5=yz+wx, m6=1-(yy+zz), m7=xy+wz, m8=xz-wy`
(times `s = 2/|q|²`, constant `2.0` at `0x680a60`). That is exactly `S·R(q)ᵀ`
for the standard Hamilton xyzw quaternion matrix. The engine's matrix helpers
are consistent with this storage:

| function | literal operation on stored data | meaning in real (column) terms |
|---|---|---|
| `FUN_004419f0(row r, B)` | `r ← r · S · B` | used for vector-by-matrix |
| `FUN_004de480(A, B)` | each row of A via 4419f0: `A ← A·S·B` | `R(A') = R(B)·R(A)` |
| `FUN_004dfd10(dst, m)` | `dst[r][c] = m[2-c][2-r]` | `R(dst) = R(m)ᵀ` (inverse) |
| `FUN_00459fc0(out, v, M)` | `out_i = v · M[2-i]` | `out = R(M)ᵀ·…`, see §4 |
| `FUN_00441940(a, b)` | `a += b` | translation add |

The GMS identity `0,0,1, 0,1,0, 1,0,0` (gms_world.py) is the same convention.
Positions, translations and normals are stored as plain `x,y,z`, with +Y up.
Characters face −Z, and the Hero is about 160 units tall.

## 2. Skeleton data in the skinned PRM entry (type/flags `0x00010100`)

All pointers are file-relative offsets into the PRM. In memory they are the same
offsets relative to the PRM base: renderer `+0x20`, resolved by
`ZPrimControlWintel` vslot `+0x0c` = `FUN_006566a0`, which returns `base + off`.

| entry field | content | status |
|---|---|---|
| `+0x08` | previous part of the same model (0 = first). A character is a chain of 2–7 parts that share one skeleton | VERIFIED |
| `+0x0e` u16, `+0x14` | vertex count, vertex offset (52-byte vertices) | known |
| `+0x3c`, `+0x40` | index block offset, word count (strips) | known |
| `+0x7c` | boneCount `n` (28 for body rigs, 70 for face rigs) | PROVEN (`0x65bea5`) |
| `+0x80` | n × 48 B: rest local, stored 3x3 + float3 | VERIFIED |
| `+0x84` | n × 28 B: rest local `quat xyzw, float3 t` | VERIFIED |
| `+0x88` | n × 48 B: **rest global** (stored 3x3 at +0, float3 translation at +0x24) = bind pose | PROVEN static palette input (vslot `+0xbc` = `FUN_00656f80` → `[entry+0x88]`) |
| `+0x8c` | n × 36 B basis block. **Not used by skinning** | (vslot `+0xc0`, `FUN_00656f60`) |
| `+0x90` | n × 48 B descriptors `{float3, int32 parent @+0x0c, float3, char16 name @+0x1c, u32}`. The floats are per-part bone boxes | parent PROVEN (`FUN_00659c40`, vslot `+0xc4`) |
| `+0x94` | 96 B map: ANM global joint ID → bone row (`0xff` = none) | VERIFIED (names match on every track) |
| `+0x98`, `+0x9c` | count, pointer of `{u32 floatCount, u32 floatStart}` **palette runs** | PROVEN (`FUN_00617400` `0x6175ec..0x617649`) |

The rest global really is the composition of the rest locals. For every bone,
`Rg[i] = Rg[p]·R(q_i)` and `Tg[i] = Rg[p]·t_i + Tg[p]`, and this matches the
stored `+0x88` to within 6e‑6 on all 15 C01A/C05A chains (`skin.py --check`).

### Correction: the vertex selector is not a bone row

The vertex byte at `+0x18` divided by 3 indexes a **local palette** that
`FUN_00617400` builds per part by concatenating float runs from the bone
palette:

```
local = []
for (cnt, start) in runs(entry+0x98, entry+0x9c): # both in floats, multiples of 12
    local += bonePalette[start/12 : start/12 + cnt/12]
paletteSlot(vertexLane) = local[selectorByte / 3]
```

For example, Hero part `0x54a850` has runs `(36,12),(276,60)`, so local slots
0..25 map to bones 1,2,3,5..27 (GROUND and NECK are skipped). An earlier version used
"local row = bone row", which assigns limbs to the wrong bones. See
`skin_mapping_compare.png`: on the left are the runs (correct), on the right
the direct-row mapping (torn mesh).

## 3. Vertex layout (52 bytes) and weights (PROVEN, `FUN_00617400` x87/SSE path `0x617992…`)

```
+0 float3 position (bind/rest space, same space as +0x88)
+12 float w0, +16 float w1, +20 float w2 w3 = 1 - w0 - w1 - w2 (0x617a03)
+24 u8 sel[4] local palette index = sel/3 (raw*16 = idx*48 bytes)
+28 float3 normal +40 u32 colour +44 float2 uv
```

Lanes with weight exactly 0 are skipped (`ucomiss` at `0x617a1d`). By
construction the weights sum to 1. On all characters there are no negative
lanes and no out-of-range selectors.

## 4. Palette construction (PROVEN, `FUN_0065be00`)

For each bone `b` (0..n-1), with `G`/`T` the animated global slot (stored
3x3 at +0, translation at +0x24, from `FUN_00659c40`) and `Rs`/`v` from
`entry+0x88`:

```
tmp = FUN_004dfd10(G) ; transpose in real terms
tmp = FUN_004de480(tmp, Rs) ; tmp·S·Rs
w = FUN_00459fc0(v, tmp)
out row0 = tmp row2, out[3] = T.x - w.x
out row1 = tmp row1, out[7] = T.y - w.y
out row2 = tmp row0, out[11] = T.z - w.z
```

The skinner applies `p' = Σ w_k (M_k p + t_k)` with `M` = the 3x3 rows and
`t` = column 3 (`0x617a32…`). Normals use `M` only. Worked through the storage
convention, this is exactly

```
M_b = Ganim_b · Rrest_bᵀ t_b = Tanim_b − M_b · Trest_b
```

which is the standard `animatedGlobal · inverse(bindGlobal)`, where the bind
global is PRM `+0x88`, decoded with `R = mᵀS`. `skin.py --check` compares a
literal emulation of the native code with this closed form; they agree to
3e‑14. Bind pose gives identity, so the skinned mesh equals the stored mesh
(max 9e‑6 on every character).

## 5. Animated global pose

The local pose per bone row (`FUN_00645c30` loops rows 1..n-1 →
`FUN_00645c90`) works as follows:

- The track for a row is the ANM track whose joint's global ID maps to that row
 through `+0x94`.
- It is sampled with `FUN_004e54c0` (§6).
- If there is a tag-15 fit record: `q ← q ⊗ fitQ` (`FUN_004def50`, Hamilton
 xyzw) and `t ← t + fitT`. Blending, cross-fades and layered upper-body clips
 are also handled here. `skin.py` does a single clip without blending.
- A row with no track keeps its default state. *INFERRED*: this is the `+0x84`
 rest local. All full-body clips (28 tracks) cover every row.

Hierarchy (`FUN_00659c40`, `0x659ef0…`, rows 1..n-1 only):

```
Rg[i] = Rg[parent]·R(q_i) Tg[i] = Rg[parent]·t_i + Tg[parent]
```

Row 0 (GROUND) is not propagated there. It is handled by the actor/root code
(`FUN_00647870`, not decoded) and carries root motion. *INFERRED/choice*:
`skin.py` uses identity for row 0 (an in-place character), or the sampled
GROUND transform with `--root`.

## 6. ANM: what the sampler needs (PROVEN, `FUN_004e5a10` init, `FUN_004e54c0` sample, vtable `0x6973a4`)

Pack object fields (tag payloads; a payload is at `hdr+8`, or at
`hdr+[hdr+8]` when `len & 0xc0000000`):
`+8` tag 4 (joint names), `+0xc` tag 5 (records/tracks), `+0x10` tag 6
(packed arrays), `+0x14` tag 7 (dynamic Q), `+0x18` tag 8 (dynamic T),
`+0x1c` tag 11 (static T float3), `+0x20` tag 13 (static Q float4), `+0x28`
tag 15 (fit). Tag 14 rows are `{groupOrdinal, prmEntry(last part), fit1Based}`.
The fit set is `tag15 + fit−1 + 28·row`.

Track (in tag 5), variable length:

```
+0 u32 joint (tag-4-relative -> u8 globalId, name)
+4 u16 staticT +6 u16 staticQ +8 u16 duration +0xa u16 flags
+0xc Q: dataOff(tag7), lookupOff(tag6), timesOff(tag6) if !(flags&0x10)
+0x18 T: dataOff(tag8), lookupOff(tag6), timesOff(tag6) if !(flags&0x08)
```

Sampling at time `τ` (local ticks):
1. `τ = max(0,τ)`. If loop, `τ = fmod(τ, dur)`; otherwise `τ = min(τ, dur)`.
 Then `f = int(τ)`.
2. T: if `flags&8`, take `tag11[staticT]`. Otherwise `k = look(lookup,f)` and
 `t0 = look(times,k)`, and the key is the float3 at `tag8+data+12k`. If
 `t0 ≠ dur`, lerp toward key `k+1` with `u = (τ−t0)/(look(times,k+1)−t0)`.
3. Q: if `flags&0x10`, take `tag13[staticQ]`. Otherwise use the same k/t0
 scheme with keys `int16×4 / 32512` (`flags&1`, 8 B) or `int8×4 / 127`
 (`flags&2`, 4 B), blended by `FUN_004df040`:
 - dot > 0.9: plain lerp (no renormalise).
 - otherwise: flip `a` if `|b−a|² > |b+a|²`, then slerp (`FUN_004dfb10`).
4. `look(off, i)` (`FUN_004e5de0`): returns 0 when `i==0`. Otherwise
 `b = tag6+off`, `w = (s8)b[0]`, `bit = (i−1)·w`, take 3 bytes at
 `b+1+bit/8` big-endian, `<<8`, then `>> (32−bit%8−w)` and mask with `w` bits.

## 7. How to implement in the browser (exact math)

Precompute per character (once):
```
for each bone i: restR[i] = mat3FromStored(prm[+0x88] + 48i) // R = mᵀS:
    // R[r][c] = m[3*(2-c)+r]  →  R = [[m6,m3,m0],[m7,m4,m1],[m8,m5,m2]]
    restT[i] = floats at +0x24 of that slot
    parent[i] = int32 at prm[+0x90] + 48i + 12
per part: localToBone = expand runs(+0x98,+0x9c) // slot k -> bone index
```

With `R = mᵀS` written out, `R[r][c] = m[3·(2−c) + r]`, that is
`R = [[m6,m3,m0],[m7,m4,m1],[m8,m5,m2]]`.

Per frame:
```
for each bone i (parents first):
 (q,t) = sampled track for gid→row i (or rest +0x84 if none); apply fit
 R = quatToMat3(q) // standard column-vector Hamilton
 if parent < 0: G[i] = I, T[i] = 0 // or root motion
 else: G[i] = G[p]*R ; T[i] = G[p]*t + T[p]
 M[i] = G[i] * transpose(restR[i]) ; tt[i] = T[i] - M[i]*restT[i]
upload per part: palette[k] = (M, tt)[localToBone[k]] (≤ 26 slots, mat3x4)
```

Vertex shader:
```
w = vec4(w0, w1, w2, 1.0 - w0 - w1 - w2); idx = sel / 3.0 // sel = 4 bytes @+24
pos = Σ_k w[k] * (pal[idx[k]] * vec4(p,1)); nrm = Σ_k w[k] * mat3(pal[idx[k]]) * n
```

Then apply the existing world transform. That includes the viewer's single Z
reflection: this math is in the file's native left-handed space, the same space
as the static meshes.

## 8. Validation

`skin.py --check` on all 11 C01A chains and the C05A chains:
- The rest global is reproduced (≤ 8e‑6).
- Selectors are valid, and no weights are negative.
- Bind-pose skinned == stored mesh (≤ 9e‑6).
- The native-emulation palette == the closed form (≤ 3e‑14).
- Animated bone lengths are preserved (≤ 0.01 units). The exception is the
 Hero's TOE, at 2.4: its ANM toe offset (11.97) differs from the PRM rest
 (14.96). The animation's translations are used as native does.

Renders (front + side per pose, red = skeleton):
- `skin_hero.png`: Hero: bind, Walk_Forward t6, Run_Forward t4,
 Climb_Wall_150_Right t20.
- `skin_soldier.png`: soldier `0x558aaa` (Reg_Male, fit set 1): bind,
 Walk_Forward t12, Crouch_Run_Forward t3, Jump_Back t10.

Limbs stay attached and proportions hold in every pose.

## 9. Open points

- Row 0 / root motion and actor placement (`FUN_00647870`) are not decoded.
 Neither are blending, cross-fades and layered `UB_*` clips (`FUN_00645c90`
 fields `+0xc..+0x14`, `FUN_00646430`).
- The default local for a row without a track is assumed to be PRM `+0x84`.
- The `+0x8c` basis block and the `+0x90` box floats are still uninterpreted;
 skinning does not need them.
- The `--list` chain detection uses a byte scan. (Fixed 2026-10-08: C05A
 chains `0x5f16ac` and `0x610b74` no longer show up as separate truncated
 chains; see the note below.)

2026-10-08: the `+0x3c` index block is not always stored right after the
`+0x14` vertex block. In C01A `0x5652d6`, and in C05A `0x5f160c`, `0x5f174c`
and `0x610c14`, `+0x3c` points to an earlier strip block elsewhere in the file.
These are small parts with 18 to 94 vertices. `skin.py` used to require
`+0x3c − +0x14 == 52·vc`, so it rejected characters `0x565556`, `0x5f17ec` and
`0x610c14`. It now bounds-checks the two blocks separately, the same way
the browser port's character renderer does. `--check` passes for all 11 C01A and
7 C05A tag-14 characters.
- The face-rig (70-bone) characters skin correctly in bind pose and with body
 clips, but face animation is untested.
