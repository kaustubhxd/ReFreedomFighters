# RMC, RMI and SGP: room trees and the sound graph (Freedom Fighters, PC), plus GMS world transforms

This spec covers three files and a GMS finding they depend on:

- **RMC** ("Room Collision Tree") holds a box per room, plus extra boxes for some objects, for line and box queries.
- **RMI** ("Room Inside Tree") holds each room's "inside" volume, for point-in-room and box-in-room queries.
- **SGP** ("Sound Graph Data", `ZSoundGraph`) is the sound-propagation graph. Its nodes are rooms and its edges are portals (ZGATE pairs). It stores precomputed room-to-room paths.
- **GMS hierarchy.** The GMS instance table encodes a parent stack. Matrix and position are relative to the parent. The table walk also gives every geom's *static geom slot*, the "geom ref" `0x40000000|slot*0x70` that OCT, RMC, RMI and SGP all use. Section 6 covers this.

Decoders in this folder (Python 3, stdlib only):

- `rooms.py`: `python3 -I rooms.py STEM|FILE.RMC|FILE.RMI [-v] [--json out]`
- `sgp.py`: `python3 -I sgp.py FILE.SGP [-v] [--json out]`
- `gms_world.py`: `python3 -I gms_world.py FILE.GMS [--tree] [--find NAME]`. It can also be imported; `oct.py` could use it.

Each tool finds the sibling GMS, BUF, OCT and PRM files and cross-checks against them when they are present.


---

## 1. RMC / RMI file layout [H]

Both files have the same layout. Loaders:

- It allocates a buffer that it keeps (engine +0xbc8 / +0xbcc).
- It calls `ZCollisionBase::InstallCollisionBuffer` (RMC) or `InstallInsideBuffer` (RMI).
- Each does `new ZOctreeCompiled; Init(buffer)` and stores the result at ZCollision +0x1d4 (RMC) or +0x1d8 (RMI).
- PC: `FUN_004edb80` / `FUN_004edc50` (ZCollision vtable `0x697738` +0x08/+0x0c) store at +0x19d / +0x1a1. The ZOctreeCompiled vtable is `0x67d138` and `Init` is `FUN_004e3d60`.

```
+0x00 ZOctreeCompiled tree, exactly as in OCT (oct-format.md section 5):
                   u32 objOff, f32 origin[3], f32 scale, 6-byte nodes from +0x14 (padded to 16),
                   16-byte objects {u32 id, u16 min[3], u16 max[3]} at objOff
objOff+16*nObj SRoomTreeBox records, 0x54 bytes each, to EOF
```

**Object id** is the byte offset of the object's record from the start of the file. The tree is `Init`ed on the file buffer itself, so `base + id` is the record. The readers compute `chk->treeBase(+0x5c/+0x7c) + id`. Every object has its own record, and every record is referenced exactly once.

### SRoomTreeBox (0x54 bytes) [H unless noted]

The writer is `SRoomTreeBox::SetBox(room, boundGeom, M, meshPos, centre, half)` @ `` (editor code, still linked). The readers are:

- `InnerRoomFuncPoint`
- `InnerRoomFuncBox`
- `CalcRoomLineCallBack`
- PC `FUN_004ed840` (box callback, same offsets)

| Off | Type | Meaning | Proof |
|---|---|---|---|
| 0x00 | u32 | `axisAligned`. SetBox writes 0, then 1 if every row of M has exactly one non-zero entry; in that case it also permutes `half` into world axes. Readers: 1 means `\|p-c\| <= half` per world axis; 0 means rotate first (`vmtmul(d, M)` / `rectBoxColi`). | SetBox /; FuncPoint  |
| 0x04 | f32[9] | M, the orientation in ZBaseGeom/GMS matrix format. For oriented records, world half-extent `i = Σ_j \|M[3*(2-j)+i]\|·half[j]`. **[H]** by data: the object boxes equal this AABB for all 61 oriented C01A RMC records and all 13 oriented C05A RMI records. | SetBox `mcpy`  |
| 0x28 | f32[3] | box centre (world) | SetBox  |
| 0x34 | f32[3] | `meshPos`: world position of the bound geom, used as origin for the mesh test; 0 when SetBox got no position. | SetBox ; FuncPoint  |
| 0x40 | f32[3] | half extents | SetBox  |
| 0x4c | u32 | `roomRef`: static geom ref of the ZROOM (or of the scene root when there are no rooms). `GeomRefToPtr` gives the ZROOM, which is added to the output room list. | SetBox  (`GeomPtrToRef(room)`); FuncPoint  |
| 0x50 | u32 | `meshRef`: geom ref of the bound geom when it is *not* a plain box. Readers then test the point or box against that geom's PRM mesh via `ZCollision` vtable +0x28/+0x30, in local space `(p - meshPos)·M`. It is 0 when SetBox found the mesh's 8 vertices to be exactly ±half. | SetBox ; FuncPoint  |

Records with no rotation still store the identity matrix `1,0,0, 0,1,0, 0,0,1`, and some store a mirror such as `diag(1,1,-1)`.

### What the records are, per file

**RMC** (C01A: 126 records, C05A: 15, StartUp: 1):

- **[H]** The first record of each room is a world AABB of the whole room (`axisAligned=1`, identity M). It contains the union of the room's OCT slot-0 (static mesh) and slot-2 (gate) boxes: 21/21 C01A, 15/15 C05A. It equals that union on all axes for 10/21 and 6/15 rooms.
- **[H data / L rule]** C01A has 105 more records. Each is an OBB or AABB equal to the OCT slot-0 box of one static geom of the same room. All 105 geoms sit inside ZGROUPs: the parts of the exploding-car groups (`FF_Exploding_CarCivil*`, `Exploding_CarCivilFordPickup`, ...).
 - All 105 have bit `0x80000` set in their GMS record flags (+0x18).
 - 76 car parts with that bit get no box.
- C05A RMC has room AABBs only.

**RMI** (C01A: 33, C05A: 44, StartUp: 1):

- **[H]** If a room has `InsideBound_NN` geoms (class `0x20001c`, a ZBOUND-type class that `GetBaseGeomListType` puts in list 3 with ZGATE), it gets one record per InsideBound geom. `meshPos` equals that geom's world position: 24/24 C01A, 40/40 C05A.
- **[H]** Rooms with no InsideBound geom get one record identical to their RMC room AABB, with `meshPos` = 0 (9/9 C01A, 4/4 C05A).
- The set of rooms with InsideBound geoms equals the set of rooms with `meshPos` records: 12 and 11.
- **[H]** In C05A, 25 RMI records have `meshRef` set. All 25 point at the InsideBound geom at `meshPos`, so those inside volumes are general meshes and the box is only a bound. C01A has none.
- The Backdrop ZROOM has no record in either file (C01A, C05A). StartUp has no ZROOM; its single record points at the root group (`roomRef 0x40000000`, slot 0).

## 2. How RMC and RMI are used at runtime [H]

ZCollisionBase methods ( vtable `_vt.14ZCollisionBase`, 8-byte entries; PC vtable `0x697738`):

| Method | Tree | Callback | Use |
|---|---|---|---|
| `GetRoomsLst(point)` (vt+0x34) | given | `InnerRoomFuncPoint` | rooms containing a point |
| `GetRoomsLst(box)` (vt+0x3c; PC `FUN_004ed390` → callback `0x4ed840`) | given | `InnerRoomFuncBox` (`rectBoxColi` for OBBs) | rooms containing an oriented box |
| `GetInsideRoomsLst` (vt+0x44; PC `0x4ed340`) | RMI | box | e.g. `CCutSequenceList::Init2` |
| `GetColiRoomsLst` (vt+0x4c; PC `0x4ecb00`) | RMC | box | rooms touched by a box |
| `GetInnerRoomsLst` (vt+0x54) | RMI | point first (vt+0x30), then box | **the "which room am I in" query**. It removes every room that is an ancestor of another hit (parent vt+0x48, depth vt+0x4c0), so the innermost room wins. Callers: `ZBaseGeom::AutoAssignToRooms`, `ZItem::FindAttachRoom`, `ZFFFlak::FrameUpdate`, `ZViewBase::LocateRoomsAndGates` (camera room). |
| `CalcLineColi_` | RMC | `CalcRoomLineCallBack` | **static ray casts**. The RMC tree is the broad phase: line vs room boxes, then the hit room's OCT bound tree of the requested `eGlobalTreeType` (room vt+0x680), then `CalcGeomLineCallBack` and the prim and sub-strip trees from OCT. Up to 16 rooms are kept in a ring buffer. |

- `CalcRoomPcts` and `ExpandThroughGates` (also called from AutoAssignToRooms) do not touch RMC or RMI. They split a geom between rooms using the rooms' gates.
- `ZROOM::CalcBestRoom` is an assert stub in this build.

So RMC answers "which rooms might this line or box hit", and RMI answers "which room is this point or object inside".

## 3. SGP layout [H]

The load chain is:

1. `ZEngineDataBase::LoadSoundGraph`
2. `GetSoundGraphSize/Data` (ext `sgp`)
3. `ZDllSound::InstallSoundGraph` creates a `ZSoundGraph` (0x1270 bytes).
4. `ZSoundGraph::InstallLoadedGraph` only stores `(ptr, size)`.
5. `ZSoundGraph::Initialize` (PC `FUN_0053c280`, same field order; PC reader and sizer `FUN_00490e70` / `FUN_00490f10` (order corrected 2026-10-08, see oct-format.md)) parses the buffer. It copies the four arrays into new allocations, resolves the name table into the scene, and frees the file buffer.

```
+0x00 u32 nExits -> +0x1248, array +0x1258 (PC +0x11e9 / +0x11f9, packed struct)
+0x04 u32 nPairs -> +0x1250, array +0x125c
+0x08 u32 nRooms -> +0x124c, array +0x1260
+0x0c u32 nConns -> +0x1254, array +0x1264
SExit [nExits] 0xa4 bytes
SExitPair [nPairs] 12 bytes
RoomIdx [nRooms] 8 bytes
Conn [nConns] 4 bytes
name table to EOF: { char name[] NUL; u32 index }
```

### SExit (0xa4): a portal between two rooms

| Off | Type | Meaning | Proof / conf |
|---|---|---|---|
| 0x00 | u32[2] | `gateRef[k]`: static geom refs of the two ZGATE geoms, one per room. `GeomRefToPtr(ref)->parent` is the room, and its `+0xa0` holds the sound room index. | `GetGateVertices`, `GetRoomGate`, `GetRoomExit` [H] |
| 0x08 | f32 | `open`: transmission factor. Paths multiply it along their exits, `TestRooms` treats 0.0 (``) as blocked, and `TestGraph` keeps the path with the largest product. It is 1.0 in every sample (37/37, 43/43), so it presumably changes at runtime with door state. | `TestRooms`, `TestGraph` [H read / M meaning] |
| 0x0c | u32[2] | not read by any decoded function. It holds floats in some records (76.8, 100.0) and junk words in others. | [L] |
| 0x14 | f32[4][3] | `quad[0]`: gate 0's portal polygon, world space | `GetGateVertices`  (verts at +0x14/+0x20/+0x2c/+0x38) [H] |
| 0x44 | f32[4][3] | `quad[1]`: gate 1's polygon, usually the same points in another order | `GetGateVertices`  [H] |
| 0x74 | f32[3] | `centre[0]` = world position of gate 0 | ; data 37/37, 43/43 [H] |
| 0x80 | f32[3] | `centre[1]` = world position of gate 1 |  [H] |
| 0x8c | f32[3] | `normal[0]`: area vector of quad 0, i.e. (cross products)/2, so \|n\| is the area | ; data 37/37, 39/43 [H read / M meaning] |
| 0x98 | f32[3] | `normal[1]`, opposite to `normal[0]` (37/37, 43/43) |  [H] |

`GetGateVertices(exit, room, ...)` returns the side whose gate's room is `room`: point, normal and four vertices. A flag argument swaps the sides.

### SExitPair (12 bytes)

`u32 exit0, u32 exit1, f32 dist`. **[H]** for the two indices (`TestRooms` , `TestGraph` ). `dist` equals the distance between the nearest gate centres of the two exits in 179/189 (C01A) and 220/380 (C05A). Its exact definition is open **[L]**; it may be a path length.

### RoomIdx (8 bytes) and Conn (4 bytes): precomputed room-to-room paths [H]

`RoomIdx[r] = {u32 count, u32 first}`. Room r's connections are `Conn[first .. first+count)`. They list only rooms `s > r`, sorted by `s`. Queries sort the pair first. Proof: `TestRooms`-`` and `TestGraph`. The binary-search bounds read the first and last entries' upper halfword `& 0x3fff`.

```
Conn: bits 31-30 kind, bits 29-16 s (other room), bits 15-0 payload
 kind 0 direct: the rooms share exit `payload` (gain = exit.open)
 kind 1 two exits: SExitPair `payload` (exit0, exit1) through one middle room
                                                                        (gain = open0*open1)
 kind 2 via room m = payload: resolve (min(r,m),max(r,m)) and (m,s) recursively
```

Proof: the top-2-bit switch (`w >> 30`) in `TestRooms` and `TestGraph`. `GetConnections(i)` returns `&Conn[i]`.

A pair of rooms can have many entries. These are alternative paths, and kind-2 entries repeat with the same middle room. `TestGraph` scores the entries:

- by distance from the listener to the exits' gates (`GetSquaredDist(pos, gateRef)`)
- by the product of the exits' `open` factors

It returns the best path in an `SPath`.

### Name table [H]

Each entry is `{NUL-terminated name, u32 index}`, repeated to EOF (`GetSoundGraphIndex`). `Initialize` walks every scene geom:

- For a ZROOM (`IsDerivedFrom 0x100021`), it looks up the geom's full name path and stores the index at ZROOM `+0xa0`, the sound room index.
- For a ZGATE (`0x200015`), it calls `ZGATE::SetSoundGraphId(index)` (vtable +0x490 → `ZGATE::SetSoundGraphId`). Both gates of an exit get the exit index.

The names are full geom paths joined with backslashes, for example `Singleplayer/C01A/FF-C01A_LOCATIONS.zip\Singleplayer/C01A/FF-C01A_LOC_Inside.zip\FF-C01A_Inside_Subway_01\Gate_81`. In the samples, the room entries come first, with indices 0..nRooms-1. Index 0 is the Backdrop, which has no connections.

StartUp's SGP is 16 zero bytes: no rooms, no exits, no names.

## 4. What the sound graph means [H structure / M semantics]

- **Nodes** are the sound rooms, one per ZROOM including the Backdrop.
- **Edges** are exits: portal quads where two rooms' ZGATEs meet.
- For every pair of rooms that can hear each other, the file lists paths of up to two exits directly (kinds 0 and 1). Longer paths are composed through middle rooms (kind 2).
- At runtime, `GetAudiable(room, list, ...)` and `TraceSound` gather the audible rooms. `TestGraph` picks, for a source room and listener room, the path with the highest product of `open` factors (closed doors give 0) and the nearest exit. `GetEnvMorph` blends reverb environments across the exit (`GetGateVertices` and `CreatePlanes` build the portal planes).
- C01A has 200 of 231 room pairs connected; C05A has 91 of 120.

The decompiled-level details of attenuation, such as how distance and `open` turn into volume, were not traced. **[L]**

## 5. Validation

Every number below is printed by the three tools.

| | C01A | C05A | StartUp |
|---|---|---|---|
| RMC size / records / oriented | 13,736 / 126 / 61 | 1,708 / 15 / 0 | 132 / 1 / 0 |
| RMI size / records / oriented / meshRef | 3,588 / 33 / 0 / 0 | 4,672 / 44 / 13 / 25 | 132 / 1 / 0 / 0 |
| Parse exactly to EOF, every object id → a record, every record referenced once | yes | yes | yes |
| Quantised object box == record AABB | 126/126, 33/33 | 15/15, 44/44 | 1/1, 1/1 |
| Room refs → ZROOM geoms | 21/21 of 22 (not Backdrop) | 15/15 of 16 (not Backdrop) | root group |
| RMC room AABB ⊇ OCT slot-0+2 union | 21/21 | 15/15 | 1/1 |
| RMC per-object boxes == OCT slot-0 box | 105/105 | - | - |
| RMI meshPos == InsideBound world pos | 24/24 | 40/40 (+25/25 meshRef) | - |
| RMI rooms without InsideBound == RMC room AABB | 9/9 | 4/4 | 1/1 |
| All RMC/RMI boxes inside the OCT level bounds | 159/159 | 59/59 | 2/2 |
| SGP size / exits / pairs / rooms / conns / names | 30,651 / 37 / 189 / 22 / 2,583 / 96 | 65,406 / 43 / 380 / 16 / 10,446 / 102 | 16 / 0 |
| SGP parse to EOF, RoomIdx contiguous, no bad words, sorted | yes | yes | yes |
| Conn kinds direct/pair/via | 37/165/2381 | 43/308/10095 | - |
| Paths consistent with exit rooms (direct, pair, via) | 37/37, 165/165, 2381/2381 | 43/43, 308/308, 10095/10095 | - |
| ZROOM path in name table, indices exactly 0..n-1 | 22/22 yes | 16/16 yes | - |
| Exit gateRefs are ZGATEs named with that exit index | 37/37 | 43/43 | - |
| Exit centre[k] == gate k world position | 37/37 | 43/43 | - |
| Exit quad[k] inside gate k's OCT slot-2 box | 37/37 | 43/43 | - |
| ZGATE geoms in the sound graph | 74/82 | 86/86 | - |

## 6. GMS hierarchy, static slots and world transforms (gms_world.py)

### 6.1 Instance-table walk [H]

The proof is `ZEngineDataBase::CreateGeoms`. The GMS body starts with `u32 tableOff`. At the table:

```
u32 count; count x { u32 w; u32 aux }
 pop = w >> 25 before creating: go up `pop` parents
                                 (loop calling parent vt+0x48)
 rec = (w << 2) & 0x03fffffc SCompiledGeom offset
 push = w & 0x01000000 after creating: the new geom becomes the current parent

 aux stored at the geom's +0x68
```

- Every entry creates one geom. Records may be aliased, i.e. instantiated more than once: C01A has 6,617 entries, 6,617 geoms and 5,503 distinct records.
- Each geom is attached to the current parent via parent vt+0x510.
- `CorrectEditorDestGroup` returns its group argument, so it is a no-op.

Record fields read here: +0 name, +4 matrix offset, +8 position offset, +0xc PRM, +0x10 class, +0x14 events, +0x18 flags, +0x1c data block, +0x20 / +0x24 / +0x28 (note 2026-10-08: for the Pathfinder3 geom the data block offset was found at `+0x20`, `CreateGeoms` reads it; see `pathfind-format.md`. Recheck which field is the data block before relying on `+0x1c`), and +0x2d (list bank).

### 6.2 Transforms [H]

- `SetMatPos` stores the GMS matrix and position unchanged in ZBaseGeom +0 / +0x24.
- `ZBaseGeom::GetLocalPoint` first recurses into the parent (+0x50), then applies `(p - pos)` and the matrix. So GMS transforms are **parent-relative**, and the world transform is `parent_world ∘ local`.

The matrix convention was fitted on the data and holds for every checked box:

```
world = R·local + p, R[i][j] = m[3*(2-j)+i]
x' = m6·x + m3·y + m0·z + p0
y' = m7·x + m4·y + m1·z + p1
z' = m8·x + m5·y + m2·z + p2
```

The GMS identity is `0,0,1, 0,1,0, 1,0,0`. `oct.py`'s `xform` (`x·m2+y·m1+z·m0`) reads the 3×3 in a different index order, `R[i][j] = m[3i+2-j]`. The two agree for rotations about the vertical axis, which is why the old check still matched about two thirds of the instances. I tested the eight row-reverse, column-reverse and transpose variants of the 3×3 against the OCT boxes. This form gives 2,033 exact C01A matches. The `oct.py` form gives 1,807 under the same corner-box test, and the other variants give at most 1,121 under the triangle-box test.

### 6.3 Static geom slot (geom ref) [H]

`GeomPtrToRef` returns `0x40000000 | (base - staticBlock)`. Slots are assigned as follows:

1. Slot 0 is the root group (`AllocRootGroup` runs before the loop).
2. When the first geom after a push (or the first geom overall) is created, the next record of the **counts table** is consumed. The table is at `u32 @ body+0x14`: `u32 n`, then n × 24 u32.
3. `AllocBaseGeomsSpace` then reserves `Σcounts × 0x70` bytes, and each of the 24 lists gets a contiguous run in order.
4. A geom goes to list `GetBaseGeomListType(class) + 8·rec[0x2d]`. `GetBaseGeomListType`:
 - `0x04000022` → 1
 - classes with bit `0x200000`: `0x200012`, `0x200015`, `0x20001c` → 3; the rest → 1
 - otherwise bit `0x100000` → 0, bit `0x800000` → 2, else 3
5. Every geom whose class has bit `0x100000` (a group) advances to the next counts record (``).
6. A pop moves back to the parent's cursor block (`r22 -= 0x60`).

**Proof by data:**

- The walk uses exactly all counts records: 985/985 (C01A), 913/913 (C05A), 683/683 (StartUp).
- The ZROOM slots it produces are exactly the RMC/RMI `roomRef` values: C01A slots 100..105, 107, 113, 114, 117, 2783..2793; Backdrop = 2.
- **Every** OCT bound-tree id resolves to a geom of a matching class inside the right room: 2783/2783, 1990/1990, 573/573. Slot 0 holds ZSTDOBJ `0x200002` (and `0x20000b` and others), slot 1 lights `0x8000xx`, slot 2 ZGATE `0x200015`, slot 3 ZGROUP `0x100001`.
- All SGP gate refs resolve to the right ZGATEs.

This closes OCT open question 1, "static geom index → GMS instance".

### 6.4 New placement numbers (gms_world.py, OCT slot-0 ids paired exactly with their geom)

The world box of each geom is computed from its collision mesh: the local AABB, with its 8 corners transformed. That is how the engine bounds rotated objects.

| | slot-0 ids with a collision tree | exact match | only contained in the box | other |
|---|---|---|---|---|
| C01A | 2,135 (233 without a tree) | **2,033 (95.2%)**; all 1,829 direct room children match | 93 | 9 |
| C05A | 1,337 (268 without) | **1,332 (99.6%)** | 5 | 0 |
| StartUp | 325 (24 without) | **319 (98.2%)** | 6 | 0 |

`oct.py`'s old count was 1,646 of 2,462 deduplicated C01A instances (732/1601 C05A, 197/212 StartUp). Counted the same way (any slot-0 box, all geoms with a collision tree), the new numbers are:

- C01A: 2,033/2,628
- C05A: 1,332/1,821
- StartUp: 321/327

The denominators now include every instantiated geom, including templates and dynamic objects that are not in any OCT tree.

The remaining mismatches are all children of ZGROUPs, mostly exploding-car parts and rubble. Their OCT box is centred correctly but larger than the collision mesh's box. The OCT box was most likely built from the render mesh or an older pose, not from the simplified collision mesh. 93 of the 102 C01A cases are contained in their box.

## 7. What the browser runtime needs

- **Room membership** (for culling, ambient sound, AI zones): load RMI, and for a point, test every record:
 - axis-aligned: `|p - c| <= half`
 - oriented: for j = 0..2, `|dot(p - c, (M[3(2-j)], M[3(2-j)+1], M[3(2-j)+2]))| <= half[j]`, i.e. stored row 2-j of M is local axis j in world space. The `rooms.py` JSON also gives each record's world AABB for a first pass.
 - Keep the innermost room: rooms nest, so drop any room that is an ancestor (GMS hierarchy) of another hit.
 - If `meshRef` ≠ 0 (C05A), refine with that InsideBound geom's PRM mesh placed by gms_world. Without it the box is a slightly larger approximation.
 - The tree itself is optional: there are at most ~50 records.
- **Ray casts / line of sight**: RMC room boxes are the broad phase. Test the line against them, then against the hit rooms' OCT trees. A browser can skip RMC and test OCT bundles directly.
- **Sound** (SGP):
 - room index per ZROOM (name table)
 - exit quads and centres for portal positions and occlusion planes
 - per room pair, the connection list: direct exit / exit pair / via room
 - Simple model: if listener and source are in different rooms, take their Conn list and pick the path whose exits are all open with the nearest exit. Play the source from that exit's centre (virtual source), attenuated by the extra path length (`SExitPair.dist` is a ready-made exit-to-exit distance).
 - Keep a per-exit `open` flag that doors and scripts can set.
- **World transforms**: use `gms_world.py` (parent stack + `R[i][j] = m[3*(2-j)+i]`) for every GMS placement. This replaces the old earlier viewer formula, and it also places group children such as vehicle parts and InsideBound volumes correctly.

## 8. Open questions

1. The rule for which static geoms get their own RMC box. In C01A these are 105 exploding-car parts, all with GMS flag bit `0x80000`, but 76 other car parts with that bit get none. The builder is stripped. **[L]**
2. Why some RMC room AABBs extend past the union of the room's slot-0+2 boxes. They may include gate quads, InsideBounds or dynamic children; this was not resolved.
3. `SExit +0x0c/+0x10`: no reader found.
4. The exact definition of `SExitPair.dist`. It equals the centre distance in 179/189 and 220/380.
5. How SGP path data becomes volume and filter values (GetAudiable / TraceSound / GetEnvMorph internals were not traced).
6. The meaning of the GMS flag bits (+0x18), the instance-table `aux` word (stored at geom +0x68), and the record fields +0x14..+0x28, beyond what CreateGeoms does with them.
