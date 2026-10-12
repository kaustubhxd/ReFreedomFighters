# Pathfinding data (ZPathfinder3 / ZPFOctree_packed), Freedom Fighters PC

**Where it is:** inside the **GMS** scene file. There is no separate pathfinding file. The data is the data block (DBLK) of the geom named `Pathfinder3`, class `0x200075`, which is the `ZPathfinder3` geom. Its parent is a group (`0x100001`) that is also called `Pathfinder3`. The first item of that data block is the blob that `ZPathfinder3::SerializeData` reads. It holds a packed, sparse octree of 25-unit voxels, with a walkable bit per voxel, connected-component tables, extra edges and special links (climbs, jumps).

Decoder: `pathfind.py` (stdlib only).

```
python3 -I decoders/pathfind.py FF-C01A_MAIN.GMS [-v] [--dump-dblk] [--obj out.obj] [--png out.png [--coli coll.obj]]
```

It prints a summary and the checks, and exits 1 if any check fails. `--obj` writes one quad per walkable cell in world space. `--png` writes a top-down image (`C01A_pathfind_top.png` in this folder).

Conventions:
- PC data is little-endian. Every table index 0 is an unused slot that holds editor garbage. Real entries start at 1.
- Recheck commands run from the repo root. `$C01A` and `$C05A` are the `FF-C01A_MAIN.GMS` and `FF-C05A_MAIN.GMS` sample paths; `$SU` is `FF-StartUp.GMS`.

---

## 1. Location: GMS geom → data block → blob

```
GMS body (inflated)
 record of geom "Pathfinder3" (class 0x200075)
    +0x20  u32  offset of its data block in the GMS body
 DBLK @ offset
    u32   header: low 24 bits = total size including the header (PC LE)
    items: u8 tag (type = tag & 0x3f; 0xff = end) + payload
      0  type 7  blob      u32 len (counts its own 4 bytes) + len-4 bytes  -> section 2
      1  type 9  REFTAB    extra door geoms (u32 len + refs)
      2  type 3  int       -> ZPathfinder3+0x4c (bool)
      3  type 3  int       -> +0x28, clamped to 2..10
      4  type 2  float     -> +0x20
      5  type 3  int       -> g_bUseLooseOctree
      6  type 9  REFTAB    -> +0x38
      7  type 3  int       -> +0x34 (cPackData default)
      8  type 3  u32       -> +0x78 = A* array size -> ZPFOctree_packed::Init(n)
      9  type 6  block end
     10  0xff
```

### Evidence: the data is in the GMS, in the Pathfinder3 geom's data block
- Claim: The pathfinding blob is in the GMS, in the data block of the geom named `Pathfinder3` (class `0x200075`). OCT, BUF, RMC, RMI, SGP and the ZIP members do not hold it.
- Recheck: `python3 -I decoders/pathfind.py $C01A | sed -n 2p` → `geom #2 "Pathfinder3" record 0x332a0, data block 0x2590`. C05A gives `geom #2288 ... record 0x4fc04, data block 0x2cec4`.
- Confidence: proven. The class id `0x200075` = ZPathfinder3 is fitted on data: it is the only class whose data block holds the magic, and the geom is named Pathfinder3 in both levels.

### Evidence: record +0x20 holds the data block offset
- Claim: GMS record `+0x20` is the data block offset (relative to the GMS body).
- Confidence: proven. On PC it is fitted: the C01A and C05A offsets point exactly at a DBLK header whose size ends at the `0xff` terminator.

### Evidence: DBLK item encoding
- Claim: Each DBLK item is a tag byte (type = `tag & 0x3f`; `0xff` ends the block) followed by a payload whose size depends on the type:
 - type 1: 8 bytes;
 - types 2, 3, 8, 10, 11: 4 bytes;
 - types 4, 5: a NUL-terminated string;
 - type 6: no payload;
 - types 7, 9, 12: `u32 len` that counts its own 4 bytes. `Get(void**)` returns `tag+5` and size `len-4`.

 The header's low 24 bits are the size minus 4.
- Source: `DBLK::GetLen`, `DBLK::Get(void**)` (returns `len-4`), `DBLK::SetDataBlock` (masks the low 24 bits, `-4`). PC `Get(void**)` = `0x4e0f60` (same "DATABLOCK type mismatch" string, `add ecx,5`), PC `GetLen` = `0x4e1590`.
- Confidence: proven.

### Evidence: settings items after the blob
- Claim: The items after the blob are read in the order shown in the table above.
- Source: ``: `GetType==9` → REFTAB doors; then `==3` → `+0x4c`; `==3` → `+0x28` (clamped to 2..10); `==2` → `+0x20`; `==3` → `g_bUseLooseOctree`; `==9` → REFTAB `+0x38`; `==3` → `+0x34`; `==3` → `+0x78`; `ZPFOctree_packed::Init(+0x78)`; `NextBlock`. The PC call sequence matches (`0x52ad7a`…`0x52af1c`).
- Recheck: `python3 -I decoders/pathfind.py $C01A`. Expected values in both levels: `doors []`, `flag_0x4c 1`, `int_0x28_clamp2_10 6`, `float_0x20 0.0`, `UseLooseOctree 0`, `reftab_0x38 []`, `cPackData_default 1`, `astar_array_size 20000`.
- Confidence: proven (order). Field meanings beyond the names are open.

## 2. Blob header (ZPathfinder3::SerializeData)

```
u32 magic 0x01923482 / 0x01923483 / 0x01923484 (samples: ...84)
u8 cPackData must be non-zero ("Don't use unpacked data.")
... ZPFOctree_packed stream (section 3)
```

- Claim: The magic value selects the optional tables.
 - `…83` or `…84` sets Init0 arg 1, which enables the link-action table.
 - `…84` sets Init0 arg 2, which enables the world link-point table.
 - `…83` warns "level does not support path way corrections".
- Source: `` (constants `0x01923484`, `0x84349201`, …; stores into `+0x50`/`+0x54`, then `Init0(+0x50,+0x54)` stores `+0`/`+4`). PC `0x52cb60` (`cmp esi,0x1923484` …; `[edi+0x47]`, `[edi+0x48]`). The PC packed reader tests `byte [esi+4]` and `[esi+5]` at `0x531465` and `0x5314ba`.
- Confidence: proven.

## 3. ZPFOctree_packed stream

The stream is read sequentially with `memcpy`: PC `0x531270` has 12 `memcpy` calls; ``. `n` = a `u16` count that comes before each table.

| # | Field (PC member) | Stored | Record layout |
|---|---|---|---|
| 1 | value_bits (`+0x4c`) | u32 | bits per voxel value (samples: 1) |
| 2 | plane_words W (`+0x2c`) | u16 | u32 words per bit plane (samples: 2 → 64 bits = 8×8 cells) |
| 3 | **nodes** (`+0x58`) | u16 n, n×22 | `u16 area, u16 rt, u16 parent, u16 child[8]` |
| 4 | **leaves** (`+0x60`) | u16 n, n×12 | `u16 area, u16 rt, u16 parent, u16 plane, u16 super, u16 rt2` |
| 5 | **planes** (`+0x80`) | u16 n, n×W×4 | 64-bit voxel bit planes |
| 6 | split_bits (`+0x68`) | u16 n, n×4 | u32 words, component split / adjacency bit matrix |
| 7 | **edges** (`+0x70`) | u16 n, n×10 | `u8 compA, u8 compB, s16 off[3], s16 link` |
| 8 | **links** (`+0x9c`) | u16 n, n×12 | `u16 start[3], u16 end[3]` (local cells) |
| 9 | link_actions (`+0xa0`) | n8×4 (if Init0 arg 1) | `u16 fwd, u16 back` (back = 0x4000\|fwd) |
| 10 | link_world (`+0xa4`) | n8×24 (if Init0 arg 1 and arg 2) | `f32 start[3], f32 end[3]` (world) |
| 11 | super_words (`+0x78`) | u16 n, n×4 | u32 words, super-component bit planes |
| 12 | **areas** (`+0x88`) | u16 n, n×10 | `u8 ncomp, u8 b1, u8 b2, u8 b3, u16 remap, u16 split, u16 edge0` |
| 13 | area_nedges (`+0x8c`) | n12×1 | u8 number of edges of area k |
| 14 | remap (`+0x94`) | u16 n, n×1 | u8 component remap table |
| 15 | vectors | 3i 3i 3f 3f 3f | `+0x30` top_blocks, `+0x40` grid, `+0x08` m_vMin, `+0x14` m_vMax, `+0x20` cell |
| 16 | `+0x3c` m_iNumLevels, `+0x50` | 2×i32 | levels; `+0x50` unknown (6) |

Notes on the table:
- `rt` in nodes and leaves is a runtime field.
- n8 is the link count from row 8; n12 is the area count from row 12.
- The edges, links and areas swap rules on PC show which fields are bytes and which are 16-bit:
 - edges (`+0x70`): u16 swapped at +2, +4, +6, +8; bytes 0–1 are not swapped;
 - links (`+0x9c`): 2×3 u16;
 - areas (`+0x88`): u16 swapped at +4, +6, +8; bytes 0–3 are not swapped.

### Evidence: stream order and record sizes
- Claim: The stream order and record sizes are those in the table.
- Recheck: `python3 -I decoders/pathfind.py $C01A | grep 'blob parsed'` → `[ok] ... (end 0x33267 blob end 0x33267)`. C05A ends 1 byte before the item end (see open question 3).
- Confidence: proven (order and sizes). Exact EOF on C01A; C05A is off by 1 byte.

### Evidence: grid geometry
- Claim: The grid is 65536 × 65536 × 8192 cells of 25 units, with 14 levels and top blocks 8×8×1. Local axes are (l0, l1, l2) = (world x, world z, world y). l2 is vertical and is the short axis.
- Source: `GetLocalCoords(float*,float*)` and `GetGlobalCoords`: local[0] uses x and `+0x40`, local[1] uses z and `+0x44`, local[2] uses y and `+0x48`. `GetLevelBlockSize`: a level-L block is `(8<<s, 8<<s, 1<<s)` with `s = levels-L-1`.
- Recheck: `python3 -I decoders/pathfind.py $C01A | grep -E 'grid|vmin'` → `grid (65536, 65536, 8192) cells of (25.0, 25.0, 25.0), top blocks (8, 8, 1), levels 14` and `vmin (-819196.875, -102396.8984375, -819196.875) vmax (819203.125, ...)`. The checks `grid = top_blocks << (num_levels-1)` and `vmax - vmin = grid * cell` print `[ok]`.
- Confidence: proven (code + data).

### Evidence: tree layout
- Claim: The octree is walked from node 1 with depth `levels-1` (13) and box (0,0,0)–grid.
 - Child k of a node covers octant k (bit0 +l0, bit1 +l1, bit2 +l2).
 - A child reference of 0 means empty.
 - The children of a depth-1 node are **leaf** indices, and each leaf covers 8×8×1 cells.
 - Node `+4` and leaf `+4` are the parent node index.
- Source: `ApplyFuncRecur(SPFArguments*,…)` (child offsets +6…+0x14, midpoint split, `depth==0` → `ApplyFuncOnLeaf`); start `ApplyFuncRecur(...,bool)` with `iRoot` (`.sdata` value `0x0001`) and depth `+0x3c - 1`.
- Recheck: `python3 -I decoders/pathfind.py $C01A`:
 - `every node 1..n-1 reached exactly once (2735 of 2735)`;
 - `every leaf 2..n-1 referenced exactly once ... (5560 reached ...)`;
 - `leaf box is 8x8x1 cells` and `leaf parent field = referencing node` both `[ok]`.

 C05A: 1867 nodes, 3237 leaves.
- Confidence: proven (code) and checked on data.

### Evidence: runtime fields
- Claim: Node `+2`, leaf `+2` and leaf `+0xa` are runtime A* extra-data indices. They are 0 in the file.
- Source: `VisitNeighborFloodFillCoarse`. If the field is 0, it is set to the current counter, and the counter grows by `area.ncomp` (node/leaf) or 64 (elements). The iterator state `+0x25` (1 node, 2 leaf, 3 element) is set in `CalcMissingInfo`.
- Recheck: the `runtime fields zero in file` check prints `[ok]` on C01A and C05A.
- Confidence: proven (code) and checked on data.

### Evidence: voxel values (walkability)
- Claim: Voxel (i, j) of a leaf, with i, j in 0..7 and bit = i + 8j, has the value `value_bits` bits `planes[leaf.plane + k]` word `bit>>5` bit `bit&31`, MSB = plane `value_bits-1`. If `leaf.plane == 0`, every voxel is 0. A value of 0 means blocked; non-zero means walkable (an "element").
- Source: `ApplyFuncOnLeaf` (plane base `+0x80 + leaf[+6]*W*4`; bit loop over `+0x4c` planes at −8 bytes; the element callback runs only when value ≠ 0, e.g. `ElementFuncGetAreaInfo` tests `value != 0`).
- Recheck:
 - `python3 -I decoders/pathfind.py $C01A | grep 'walkable cells'` → `walkable cells 206533`. C05A gives 93503.
 - The **cross-check against collision** is in `C01A_pathfind_top.png`: the holes in the walkable layer outline the parked cars, walls and props of `C01A_collision.obj` exactly.
 - Of the 203,902 C01A walkable cells whose column has a flat collision triangle, 194,144 have the nearest floor within ±50 units of the voxel bottom. About 90% have it 0..25 above the voxel bottom, so the floor lies inside the voxel. (Scratch script `floorchk.py`, not shipped.)
- Confidence: proven (decoding). The meaning "floor inside voxel" is fitted on data.

### Evidence: super-component planes
- Claim: Each voxel has a component number of `nb = NumActiveBits(area.ncomp)` bits, read from the u32 words `super_words[leaf.super …]` at bit `bit + 64k`, MSB first.
- Source: `SetPosGetElementSuperComponent`, `GetBitArrayData2`, `NumActiveBits_packed`.
- Recheck: the check `super component: walkable cells 1..ncomp, blocked cells 0` prints `0 mismatches of 206533 walkable` (C01A) and `0 mismatches of 93503 walkable` (C05A). This independently confirms the walkability planes.
- Confidence: proven (code) and an exact match on data.

### Evidence: areas
- Claim: The `area` field of nodes and leaves indexes `areas`.
 - `ncomp` = number of local connected components.
 - `remap` = offset into `remap`. `GetComponent` maps a child-level component c to `remap[area.remap + c - 1]` at each coarser level.
 - `edge0` and `area_nedges[k]` give the area's slice of `edges`.
 - `split` = u32 index into `split_bits`.
 - `b1`, `b2`, `b3` are per-direction cost factors.
- Source (function names from the engine's class layout):
 - `GetComponent` (`+0x88[area]+4` → `+0x94`);
 - `ZPFOctreeLeafFuncShowExtraEdges_packed::Apply` (`+0x8c[area]` count, `+0x88[area]+8` start in `+0x70`);
 - `VisitNeighborFloodFillCoarseSplit` (`+0x68` + `area[+6]*4`);
 - `VisitNeighborFloodFillCoarse` (`b1`, `b2` multiply `ncomp` for directions 0/1 and 4/5).
- Recheck: these checks print `[ok]` on both levels:
 - `area refs in range`;
 - `area edge ranges in range`;
 - `area remap ranges in range`;
 - `area split-bit index in range`;
 - `edge byte0 in 1..ncomp of the owning area`.
- Confidence: proven for the index fields. The semantics of `b1`–`b3`, `split_bits` and `remap` are inferred.

### Evidence: edges
- Claim: An edge is `u8 compA, u8 compB, s16 off[3], s16 link`.
 - `off` is a neighbour offset in local axes. l0 and l1 are always in −1..1; l2 (vertical) goes up to ±13 in C01A and ±8 in C05A.
 - `link` ≠ 0 means the edge uses special link `|link|`; the sign gives the direction.
 - `compA` is a component of the owning area.
- Recheck: these checks print `[ok]`:
 - `edge link refs in range`;
 - `edge offsets: local0/local1 in {-1,0,1}`;
 - `edge byte0 in 1..ncomp`.

 Every edge is in some area's slice: `edges used 674/674` (C01A), `434/434` (C05A).
- Confidence: proven (link field). The `off` and `compB` meanings are fitted or inferred.

### Evidence: special links
- Claim: A special link (ladder, climb, jump) is two local cell points (`links`), plus a pair of action codes (`fwd`, `0x4000|fwd`; values 1, 2 and 4 in the samples), plus exact world start and end points (`link_world`, the "path way corrections").
- Source: `ShowExtraEdges` draws `+0xa4` world points when `+4` (Init0 arg 2) is set, otherwise `GetGlobalCoords(+0x9c)`. It picks the colour from `+0xa0` value 2. `isActionAllowed` tests `(v & 0x4fff) == 0x4002`. `ZPathfinder3::SerializeData` warns that without `…84`, "Climb animations etc. may be offset incorrectly".
- Recheck: `python3 -I decoders/pathfind.py $C01A -v` lists 16 links. The checks `link actions: second = 0x4000 | first` and `link world points within 4 cells of local points (max |d| 80.32)` print `[ok]`; C05A has 21 links with max 68.33.
- Confidence: proven for the structure. The meaning of action codes 1, 2 and 4 is open.

## 4. Validation summary

| Sample | Pathfinder geom | Blob bytes | Nodes | Leaves | Planes | Edges | Links | Areas | Walkable cells | Result |
|---|---|---|---|---|---|---|---|---|---|---|
| C01A | #2 rec 0x332a0, DBLK 0x2590 | 199,886 | 2735 | 5560 (+1 reserved) | 3334 (1671 used) | 674 | 16 | 965 | 206,533 | PASS, exact EOF |
| C05A | #2288 rec 0x4fc04, DBLK 0x2cec4 | 142,593 | 1867 | 3237 (+1 reserved) | 3112 (1559 used) | 434 | 21 | 649 | 93,503 | PASS, 1 byte left |
| StartUp | none (no class 0x200075, no magic in any file) | – | – | – | – | – | – | – | – | no data (menu scene) |

All counts exclude slot 0. Recheck: `python3 -I decoders/pathfind.py <GMS>` prints `RESULT: PASS`, or the "no ZPathfinder3 geom" line for StartUp.

The C01A walkable bounds are (−18622, −697, −2172)..(6353, 2478, 12903). `C01A_pathfind_top.png` uses these settings:
- 1 px = 1 cell; x to the right, world z downward;
- walkable cells are coloured by height (blue = low, red = high);
- collision is grey (dark = steep walls);
- link endpoints are black.

## 5. Open questions

1. Plane and super-word slots that no leaf references are uninitialised editor memory. Referenced plane indices step by 2, and super words by 4, so the builder reserved twice the space it used. Planes: 1671 of 3334 used (C01A), 1559 of 3112 (C05A). (fitted)
2. Leaf 1 is a reserved copy of leaf 0, with parent 0, in both levels. It is never referenced. (fitted)
3. C05A's blob item is 1 byte longer than the stream, and the extra byte is `0x00`. C01A's is exact. Possibly the writer pads to an even length. (guess)
4. `+0x50` (= 6) and the meaning of the settings `+0x4c` (1), `+0x28` (6), `+0x20` (0.0) and REFTAB `+0x38` are unknown. The doors REFTAB is empty in both levels. At load the engine also adds every geom named `*door*` with a matching class to the door list.
5. The semantics of the area bytes `b1`–`b3`, of `split_bits` and of edge `compB` need `FindPathCoarse` / `FindPath` read in full. Only the indexing is proven.
6. Link action codes: 1, 2 and 4 appear (stairs-like chains are mostly 1, rooftop and ladder pairs 4, and 2 is "climb"?). The meaning is a guess until it is matched to the actor code.
