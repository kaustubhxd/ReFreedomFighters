# OCT: compiled collision and visibility octrees (Freedom Fighters, PC)

The engine's own name for OCT is the **"Trees"** file. `ZEngineDataBase::GetTreesSize/GetTreesData` open it by the extension string `oct`. The community label "Physics Octree" is roughly right, but **OCT is not the pathfinding octree.** `ZPFOctree_packed` is not involved: it is serialised by `ZPathfinder3::SerializeData` from other data.

An OCT file holds three things, in this order:

1. **Room bound trees.** Each static `ZTreeGroup` (in practice each `ZROOM`, plus the scene root when the header flag is set) has 5 octrees, one per `eGlobalTreeType`. They index the room's static geoms, lights, gates, groups and sub-tree-groups by world-space AABB.
2. **Prim collision trees.** There is one octree per collidable PRM model, in model-local space. Its objects are collision sub-strips.
3. **The unique sub-strip table.** Each 8-byte entry names a run of triangle-strip indices inside a specific PRM entry.

All three use one compiled octree format, `ZOctreeCompiled`/`ZNodeCompiled`. RMC and RMI use the same format too (see the last section).

Decoder: `oct.py` in this folder (Python 3, stdlib only).
`python3 -I oct.py FF-C01A_MAIN.OCT [-v] [--obj out.obj]`. It finds the sibling PRM, GMS and BUF files automatically.


---

## 1. Top level

| Offset | Content | Conf |
|---|---|---|
| 0x00 | `u32 rootStaticFlag`. If non-zero, the loader calls `root->MakeStaticContainer(1)`, so the scene root gets bound trees too. | H (loader); M (meaning of name) |
| 0x04 | `u32[3]`, never read. StartUp holds `1,1,1`; C01A and C05A hold `0,0,0`. | H (unused) |
| 0x10 | `N × 5` bound-tree records (§2). | H |
| … | prim collision records (§3) until `u32 0xFFFFFFFF` | H |
| … | `u32 0xFFFFFFFF` | H |
| …EOF | unique sub-strip table, `(EOF - pos) / 8` entries (§4) | H |

**Loader.** `ZEngineDataBase::CreateBoundTrees` (PC `FUN_0048dcb0`):

1. Skip 16 bytes.
2. Walk every geom. When a geom has class bit `0x100000`, `IsDerivedFrom(0x100020)` and `IsStaticContainer` ( vtable +0x614 → `IsStaticContainer__C10ZTreeGroup`; PC vtable +0x308), call `ZTreeGroup::LoadBoundTrees(p)` ( vtable +0x65c → ``; PC vtable +0x32c → `FUN_00443570`). It consumes 5 records.
3. Then `while (*p != -1) p = ZCollision->LoadInternColiTree(p)` ( vtable +0xac → ``; PC vtable +0x50 → `FUN_004edcb0`).
4. Finally `LoadUniqueSubStripInfo(p + 4, totalSize - (p + 4 - base))` (``; PC vtable +0x40 → `FUN_004edce0`). It stores `count = size >> 3`.


**Number of bundles.** The loader gets this from the scene graph, not from the file. **[H]** The count is the number of GMS geoms of class `0x100021` (ZROOM), plus 1 if `rootStaticFlag` is set. Checked on all 3 samples: C01A has 22+0 and 22 bundles, C05A has 16+0 and 16, StartUp has 0+1 and 1.

**Bundle order.** Bundle `g` belongs to ZROOM number `R-1-g` in GMS instance-table order, i.e. **reverse table order**. **[H]** This comes from matching AABBs: C01A 1644/1646, C05A 732/732. For example, C01A bundle 0 (all five trees empty) is the last ZROOM, `FF-C01_Backdrop.zip`.

`oct.py` finds the boundary between bundles and prim records structurally. A prim record repeats the tree origin and scale at +8 and +0x24, and is non-zero at +0x14..+0x20. It then cross-checks the boundary against the GMS ZROOM count. `--rooms N` overrides it.

## 2. Bound-tree record (per slot) [H]

`ZTreeGroup::LoadBoundTrees`; PC `FUN_00443570`. The writer is `ZTreeGroup::SaveBoundTrees`.

```
u32 len 0 -> empty slot, record is 16 bytes (len + 12 zero bytes)
f32 scale overrides tree scale (stored to ZOctree+0x10)
f32 origin[3] overrides tree origin (ZOctree::SetOrigin / PC 0x4e3360)
u8 zero[12]
u8 treeData[len] ZOctreeCompiled data (section 5), then pad to 16
next record = rec + 32 + ((len + 15) & ~15)
```

The writer emits the scale and origin from the tree header again, so they always match the tree header. `oct.py` warns if they differ; no sample has a mismatch.

**Slot k = `eGlobalTreeType` k.** It is `ZTreeGroup+0x60[k]`, read by `GetGlobalTreePtr__C10ZTreeGroup15eGlobalTreeType`. Each class's `GetBoundTreeType` names its slot:

| slot | class | PC proof |
|---|---|---|
| 0 | ZSTDOBJ, the static meshes | `ZSTDOBJ::GetBoundTreeType` returns 0 |
| 1 | ZLIGHT | `__6ZLIGHT` returns 1 |
| 2 | ZGATE, the room portals | `__5ZGATE` returns 2 |
| 3 | ZGROUP | `__6ZGROUP` returns 3 |
| 4 | ZTreeGroup, nested static groups | `__10ZTreeGroup` returns 4; always empty in the samples |

(ZGEOM, ZBOUND and ZSNDOBJ return -1 and are not put in any tree.) The data agrees: slot 2 boxes are paper-thin portals and slot 1 boxes are large light volumes.

**Object id in bound trees** = a geom reference. If bit 30 is set, it is a static geom: `0x40000000 | index*0x70`. Proof: `ZGeomBuffer::GeomRefToBasePtr` adds `id & 0x3fffffff` to the static memory block. `ZGeomBuffer::LoadGeoms` lays geoms out at `index * 0x70`. All 2783 (C01A), 1990 (C05A) and 573 (StartUp) ids have this form. The remap hooks `RemapGeomIDLoad/Save` (`` / ``) are no-ops. Mapping `index` to a GMS instance is **open** (§8). Within a room the indices increase with GMS table order.

## 3. Prim collision record [H]

`ZCollisionBase::LoadInternColiTree`; PC `FUN_004edcb0`.

```
+0x00 u32 recLen whole record; next = rec + recLen
+0x04 24 bytes placeholder for the runtime ZOctreeCompiled object
                           (vtable, origin[3], scale, dataPtr); the loader placement-news it
                           (PC writes vtable 0x67d138) and Init refills it from the data.
                           The file holds the editor's garbage (0x008a3150, a heap pointer).
+0x1c u32 unused (always 0x1c in the samples)
+0x20 treeData ZOctreeCompiled (section 5), recLen-0x20 bytes
```

**Who points at it.** **[H]** A PRM entry's `+0x28` holds `(OCT offset of record + 4) | 1`, i.e. a pointer to the embedded object with bit 0 set as a tag. The proofs:

- `CalcGeomLineCallBack__FP11CObjectInfoP10SOctreeChk` takes geom+0x6c to the prim entry. If bit 0 of `+0x28` is set, it uses `treesBuffer(+0xae8) + (v & ~1)` and calls its vtable +0x3c (`CheckLinesegment`).
- PC `FUN_004ebcf0`, ZCollision vtable +0x64, does the same with `[+0xaec]`.

In C01A, 1031 PRM root entries carry the tag, pointing to 956 distinct targets. All 956 are prim records, and all 956 records are linked. C05A: 776 entries, 703 targets, 703/703. StartUp: 139 entries, 87 targets, 87/87.

These trees are in **model-local space**: the ray is moved into geom space by `GetLocalPointVect` before the test. **Object id** = byte offset into the unique sub-strip table, always a multiple of 8. `CalcStripLineCallBack` computes `base + id`. In C01A all 20107 ids are valid and every one of the 20107 entries is referenced; C05A has 25659 and StartUp 816.

## 4. Unique sub-strip table (STempStripsUniqueId, 8 bytes) [H]

```
u32 strip: bit31 initial winding flip (= parity of start inside its strip)
            bits30-16 start: u16-word index into the PRM entry's index block
                      (counted from the block start, i.e. including the u16 strip-count header)
            bits15-0  count: number of indices; triangles = count-2
u32 prim: PRM file offset of the (sub-)mesh entry
```

These proofs agree with each other:

- PC `FUN_00661650` and `FUN_00661940`: `start = (w0>>16)&0x7fff`, `end = start + (w0&0xffff)`, `flip = w0>>31`. The index pointer is `PRM + [e+0x3c] + 2*start`, the vertex base is `PRM + [e+0x14]`, and the coli mask is tested against `[e+0x2c]`.
- PC `FUN_006616f0` and `FUN_00661b40` walk triangles `k = start .. end-3` as `(i[k], i[k+1], i[k+2])`, or `(i[k], i[k+2], i[k+1])` when flipped, toggling every step. They use a hard-coded 36-byte vertex stride (`idx*9*4`).
- `GetStripsFromId__C12ZCollisionGC…` decodes the same bits.
- `GetPrimFromStripUniqueId` (``, PC `0x63ea80`) returns `+4`.
- `GetColiBits` (``, PC `0x661bf0`) returns `[prims + prim + 0x2c]`.
- `CreateSubStripId` (``, PC `0x661bd0`) ORs extra bits into word 0.

**Checked:** every sub-strip in all 3 samples lies inside a single strip of its entry, and bit 31 always equals the parity of the start. The `prim` field often names a sub-mesh entry of a multi-material model rather than the root entry that owns the tree. Those entries share PRM `+0x10`.

**Coli bits** at PRM entry `+0x2c` are a material/collision mask (e.g. `0x20082`, `0x200f3`, `0x71`); their meaning is unknown. **[L]**

## 5. ZOctreeCompiled data [H]

`ZOctreeCompiled::Init` (PC `FUN_004e3d60`), plus `GetBasePtrNodes` (data+0x14) and `GetBasePtrObjects` (data + `[data]`):

```
+0x00 u32 objOff objects = data + objOff
+0x04 f32 origin[3]
+0x10 f32 scale
+0x14 nodes[] node 0 = root (cube centre 0x8000, half size 0x8000)
+objOff objects[]
```

**Node** (6 bytes). Proofs: `ZNodeCompiled::GetChildPtr`, `ZNodeCompiled::CheckCube`…`, `GetObjects`, `RemapObjects`; PC `FUN_004e3dc0`.

```
u16 w0 bit15 last sibling; bits14-3 object count; bits2-0 octant (1=+x, 2=+y, 4=+z)
u16 child index of first child node (6-byte units from nodes base); 0 = leaf
u16 firstObj index of first object (16-byte units)
```

The children of a node are the consecutive nodes starting at `child`, up to and including the one with bit 15 set. A node's objects are `objects[firstObj .. firstObj+count)`.

**Object** (16 bytes, `CObjectInfo`): `u32 id`, `u16 min[3]`, `u16 max[3]`. `CheckCube` compares `query.min < obj.max(+0xa,+0xc,+0xe)` and `query.max > obj.min(+4,+6,+8)`.

**Coordinates:** `q = (world - origin) * scale + 32768`, so `world = (q - 32768) / scale + origin`. See `ZOctree::ConvToOCS` (constants 32768.0 / 65535.0) and PC `FUN_004e3c20` (32768.0 @ `0x6972d4`). Child cubes halve in size. The traversal tests a loose (2×) child cube, matching `g_bUseLooseOctree`; this does not affect decoding.

Checked on all 3 samples: every node is reached exactly once, every object index is in range, min ≤ max, and no stray object slots remain.

## 6. Validation

| Sample | Size | Bundles | Bound objs (slot 0/1/2/3) | Prim trees | Sub-strips | Triangles |
|---|---|---|---|---|---|---|
| C01A | 678,556 | 22 | 2368/235/82/98 | 956 | 20,107 | 114,114 (5 degenerate skipped) |
| C05A | 783,580 | 16 | 1605/159/86/140 | 703 | 25,659 | 111,721 (14 degenerate) |
| StartUp | 41,492 | 1 | 349/3/0/221 | 87 | 816 | 3,419 |

- All three parse **exactly to EOF**, with the end marker and the 8-byte table filling the remainder.
- **Placement check (cross-file).** For each GMS instance whose PRM entry has a prim tree, I placed its collision triangles with the GMS matrix and position. The convention is `world = (x*m2+y*m1+z*m0+o0, x*m5+y*m4+z*m3+o1, x*m8+y*m7+z*m6+o2)`, without the viewer's z flip. The resulting world AABB **equals a room slot-0 bound-tree box to quantisation** for:
 - C01A: 1646 of 2462 instances
 - C05A: 732 of 1601
 - StartUp: 197 of 212

 The rest are children of groups whose GMS position is parent-relative (e.g. van wheels near the origin), so they cannot be checked this way.

## 7. RMC / RMI / SGP (found along the way, not decoded)

- **RMC = room collision tree**, **RMI = room inside tree**. Both are a raw `ZOctreeCompiled` blob, `Init`ed directly on the file buffer:
 - `ZEngineDataBase::LoadRoomTrees`: `GetRoomColiTreeSize/Data` (ext `rmc`) → `ZCollisionBase::InstallCollisionBuffer`; `GetRoomInsideTreeSize/Data` (ext `rmi`) → `InstallInsideBuffer`.
 - Users: `GetRoomsLst__C14ZCollisionBase…` and `CalcRoomLineCallBack`.
 - Object ids are offsets into a table of 0x54-byte room records that follows the objects in the same file (C01A RMC ids step 84). The record's +0x4c is a geom ref. Not decoded.
- The same extension table also lists `col` (global coli tree, `InstallGlobalColiTree`, `ZColiTreeCompiled`) and `gst` (global strip coli tree, `ZStripColiTreeCompiled`). The PC samples have no such files.

## 8. Open questions

1. **CLOSED 2026-10-10** (proof in `rooms-sgp-format.md` §6.3: every OCT bound-tree id resolves to a geom of the right class in the right room, 2783/2783, 1990/1990, 573/573). Original note: **Static geom index → GMS instance.** The bound-tree ids are `0x40000000 | k*0x70`, and the AABB matching gives about 1646 (k, GMS index) pairs for C01A. Within a room, k increases by 1 per static instance in table order, and the room blocks of k run in the reverse of table order. Room bundles also run in reverse table order, so the geom list is probably walked last-room-first. The exact rule (which instances get a static slot, and the full traversal order) is still open. **[M]**
2. The meaning of header words 1–3, which no loader reads, and the `rootStaticFlag` name. The flag's effect, `MakeStaticContainer(true)` on the root, is proven. **[H]**
3. The coli-bit mask values at PRM `+0x2c`, i.e. which bits mean bullet, player, camera and so on. **[L]**
4. Group-relative GMS transforms, needed to place the remaining ~33% of collision instances in world space. That is a GMS hierarchy question, not an OCT one.
