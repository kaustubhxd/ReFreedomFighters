#!/usr/bin/env python3
"""Freedom Fighters (Glacier 1, PC) AI pathfinding data: ZPathfinder3 / ZPFOctree_packed.

usage: python3 -I pathfind.py FILE.GMS [-v] [--obj OUT.obj] [--png OUT.png [--coli COLI.obj]]
                                       [--dump-dblk]

Where the data is (see pathfind-format.md for the evidence records):
  The pathfinding octree is NOT a separate file. It lives in the GMS scene file, in
  the data block (DBLK) of the geom named "Pathfinder3" (class 0x200075, the
  ZPathfinder3 geom; its parent group is also called "Pathfinder3").
    GMS record +0x20  -> data block offset in the GMS body  
    DBLK: u32 size24, then tagged items (tag & 0x3f = type; 0xff = end)
    item 0, type 7 = blob -> ZPathfinder3::SerializeData (PC 0x52cb60)
       u32 magic 0x01923484 | u8 cPackData | ZPFOctree_packed::SerializeData
       (PC 0x531270)
    items 1.. = doors REFTAB, ints/float settings, A* array size (CopyDataBlock,
       PC 0x52ac10)

Output: summary + validation (exit code 1 if any check fails).
  --obj   one quad per walkable 25x25 cell (at mid-voxel height), world space
  --png   top-down image: walkable cells (by height) over a collision OBJ (--coli,
          default: C01A_collision.obj next to this script when present)
StartUp has no Pathfinder3 geom; the tool reports that and exits 0.

Stdlib only.
"""
import os
import struct
import sys
import zlib

PF_CLASS = 0x200075
MAGICS = {0x01923482: 'v82 (no extra-link flags)',
          0x01923483: 'v83 (link actions, no world link points)',
          0x01923484: 'v84 (link actions + world link points)'}

DBLK_TYPES = {1: 'double', 2: 'float', 3: 'int', 4: 'string', 5: 'string', 6: 'block-end',
              7: 'blob', 8: 'u32', 9: 'reftab', 10: 'u32', 11: 'u32', 12: 'blob'}


class PFError(Exception):
    pass


# --------------------------------------------------------------------------- GMS
def load_gms(path):
    raw = open(path, 'rb').read()
    usize = struct.unpack_from('<I', raw, 0)[0]
    if raw[8] != 0:
        raise PFError('unsupported GMS compression mode %d' % raw[8])
    body = zlib.decompressobj(-15).decompress(raw[9:], usize + 1)
    if len(body) != usize:
        raise PFError('GMS size mismatch')
    return body


def iter_records(body):
    """Instance table walk (same as gms_world.py): yields (index, record offset)."""
    table = struct.unpack_from('<I', body, 0)[0]
    count = struct.unpack_from('<I', body, table)[0]
    for i in range(count):
        w = struct.unpack_from('<I', body, table + 4 + 8 * i)[0]
        yield i, (w << 2) & 0x03FFFFFC


def find_pathfinders(body, buf=None):
    out = []
    for i, rec in iter_records(body):
        if struct.unpack_from('<I', body, rec + 0x10)[0] != PF_CLASS:
            continue
        name = ''
        if buf is not None:
            no = struct.unpack_from('<I', body, rec)[0]
            if no < len(buf):
                name = buf[no:buf.index(b'\0', no)].decode('latin-1')
        out.append(dict(index=i, rec=rec, name=name,
                        dblk=struct.unpack_from('<I', body, rec + 0x20)[0]))
    return out


# --------------------------------------------------------------------------- DBLK
def parse_dblk(body, off):
    """PC DBLK: u32 header (low 24 bits = total size incl. header), then items.
    Item = u8 tag (type = tag & 0x3f, 0xff = end) + payload; lengths from
    DBLK::GetLen."""
    hdr = struct.unpack_from('<I', body, off)[0]
    total = hdr & 0xFFFFFF
    p = off + 4
    end = off + total
    items = []
    while p < end:
        tag = body[p]
        if tag == 0xFF:
            items.append(dict(off=p, tag=tag, type=0xFF))
            p += 1
            break
        t = tag & 0x3F
        if t in (7, 9, 12):
            ln = struct.unpack_from('<I', body, p + 1)[0]     # includes the 4 length bytes
            it = dict(off=p, tag=tag, type=t, data=p + 5, size=ln - 4)
            if t == 9:
                n = (ln - 4) // 4
                it['refs'] = list(struct.unpack_from('<%dI' % n, body, p + 5))
            p += 1 + ln
        elif t == 1:
            it = dict(off=p, tag=tag, type=t, value=struct.unpack_from('<d', body, p + 1)[0])
            p += 9
        elif t == 2:
            it = dict(off=p, tag=tag, type=t, value=struct.unpack_from('<f', body, p + 1)[0])
            p += 5
        elif t in (3, 8, 10, 11):
            it = dict(off=p, tag=tag, type=t, value=struct.unpack_from('<i', body, p + 1)[0])
            p += 5
        elif t in (4, 5):
            e = body.index(b'\0', p + 1)
            it = dict(off=p, tag=tag, type=t, value=body[p + 1:e].decode('latin-1'))
            p = e + 1
        elif t == 6:
            it = dict(off=p, tag=tag, type=t)
            p += 1
        else:
            raise PFError('unknown DBLK item type %d at 0x%x' % (t, p))
        items.append(it)
    return dict(off=off, header=hdr, total=total, end=end, items=items, parsed_to=p)


def pathfinder_settings(items):
    """Field order of ZPathfinder3::CopyDataBlock.
    Each optional field is read only when the next item has the expected type."""
    names = [(7, 'blob'), (9, 'doors'), (3, 'flag_0x4c'), (3, 'int_0x28_clamp2_10'),
             (2, 'float_0x20'), (3, 'UseLooseOctree'), (9, 'reftab_0x38'),
             (3, 'cPackData_default'), (3, 'astar_array_size')]
    res = {}
    k = 0
    for t, nm in names:
        if k < len(items) and items[k]['type'] == t:
            res[nm] = items[k]
            k += 1
    res['_rest'] = items[k:]
    return res


# --------------------------------------------------------------------------- blob
class R:
    def __init__(self, b, p, end):
        self.b, self.p, self.end = b, p, end

    def need(self, n):
        if self.p + n > self.end:
            raise PFError('blob overrun at 0x%x (+%d > 0x%x)' % (self.p, n, self.end))

    def u8(self):
        self.need(1)
        v = self.b[self.p]
        self.p += 1
        return v

    def unpack(self, fmt):
        n = struct.calcsize('<' + fmt)
        self.need(n)
        v = struct.unpack_from('<' + fmt, self.b, self.p)
        self.p += n
        return v

    def table(self, fmt, n):
        sz = struct.calcsize('<' + fmt)
        self.need(n * sz)
        out = [struct.unpack_from('<' + fmt, self.b, self.p + k * sz) for k in range(n)]
        self.p += n * sz
        return out

    def counted(self, fmt):
        n = self.unpack('H')[0]
        return self.table(fmt, n)


def parse_blob(b, start, size):
    """ZPathfinder3::SerializeData + ZPFOctree_packed::SerializeData (PC LE).
    Every table is u16 count + count records; index 0 of every table is an unused
    slot (garbage in the file), real entries start at 1."""
    r = R(b, start, start + size)
    pf = {}
    pf['magic'] = r.unpack('I')[0]
    if pf['magic'] not in MAGICS:
        raise PFError('bad pathfinder magic 0x%08x' % pf['magic'])
    pf['has_link_actions'] = pf['magic'] in (0x01923483, 0x01923484)   # Init0 arg 1
    pf['has_link_world'] = pf['magic'] == 0x01923484                    # Init0 arg 2
    pf['cPackData'] = r.u8()
    if not pf['cPackData']:
        raise PFError('unpacked pathfinder data (engine refuses it)')
    pf['value_bits'], pf['plane_words'] = r.unpack('IH')     # +0x4c / +0x2c
    W = pf['plane_words']
    pf['nodes'] = r.counted('11H')        # +0x58  22 B: area, rt, parent, child[8]
    pf['leaves'] = r.counted('6H')        # +0x60  12 B: area, ?, parent, plane, super, rt
    pf['planes'] = r.counted('%dI' % W)   # +0x80  W u32 = one 64-bit plane (8x8 cells)
    pf['split_bits'] = [x[0] for x in r.counted('I')]   # +0x68  component split bit matrix
    pf['edges'] = r.counted('2B4h')       # +0x70  10 B: compA, compB, dir[3], link
    pf['links'] = r.counted('6H')         # +0x9c  12 B: local start[3], end[3]
    nl = len(pf['links'])
    pf['link_actions'] = r.table('2H', nl) if pf['has_link_actions'] else []    # +0xa0
    pf['link_world'] = (r.table('6f', nl) if pf['has_link_actions'] and pf['has_link_world']
                        else [])                                                 # +0xa4
    pf['super_words'] = [x[0] for x in r.counted('I')]  # +0x78  super-component planes
    na = r.unpack('H')[0]                 # +0x84
    pf['areas'] = r.table('4B3H', na)     # +0x88 10 B: ncomp, b1, b2, b3, remap, split, edge0
    pf['area_nedges'] = list(r.table('%dB' % na, 1)[0]) if na else []   # +0x8c
    pf['remap'] = [x[0] for x in r.counted('B')]        # +0x94  component remap bytes
    v = r.unpack('3i3i3f3f3f')
    pf['top_blocks'] = v[0:3]             # +0x30 (8,8,1)
    pf['grid'] = v[3:6]                   # +0x40 (65536,65536,8192) local cells
    pf['vmin'] = v[6:9]                   # +0x08 m_vMin
    pf['vmax'] = v[9:12]                  # +0x14 m_vMax
    pf['cell'] = v[12:15]                 # +0x20
    pf['num_levels'], pf['u50'] = r.unpack('ii')   # +0x3c m_iNumLevels, +0x50
    pf['end'] = r.p
    pf['blob_end'] = start + size
    return pf


# --------------------------------------------------------------------------- model
def cell_value(pf, leaf, bit):
    """ApplyFuncOnLeaf: value = value_bits bits, MSB = plane value_bits-1."""
    base = leaf[3]
    if base == 0:
        return 0
    v = 0
    for k in range(pf['value_bits'] - 1, -1, -1):
        v = (v << 1) | ((pf['planes'][base + k][bit >> 5] >> (bit & 31)) & 1)
    return v


def nbits(n):
    """NumActiveBits_packed."""
    c = 0
    while n:
        c += 1
        n >>= 1
    return c


def super_comp(pf, leaf, bit):
    """SetPosGetElementSuperComponent + GetBitArrayData2:
    nb = NumActiveBits(area.ncomp) bits from u32 words super_words[leaf.super + ...],
    plane stride 64 bits, MSB first."""
    nb = nbits(pf['areas'][leaf[0]][0])
    w = pf['super_words']
    v = 0
    for k in range(nb - 1, -1, -1):
        b = bit + 64 * k
        v = (v << 1) | ((w[leaf[4] + (b >> 5)] >> (b & 31)) & 1)
    return v


def walk(pf):
    """ApplyFuncRecur from iRoot = 1 with
    depth num_levels-1 and box (0,0,0)-grid.  Child k covers octant k
    (bit0 +local0, bit1 +local1, bit2 +local2).  depth 0 refs are leaves.
    Returns (node_visits, leaf_list[(leaf_idx, min_xyz_local, parent_node)])."""
    nodes = pf['nodes']
    visits = {}
    leaves = []
    errors = []
    stack = [(1, pf['num_levels'] - 1, (0, 0, 0), tuple(pf['grid']), 0)]
    while stack:
        ni, depth, lo, hi, parent = stack.pop()
        if not (0 < ni < len(nodes)):
            errors.append('node index %d out of range' % ni)
            continue
        visits[ni] = visits.get(ni, 0) + 1
        nd = nodes[ni]
        if nd[2] != parent:
            errors.append('node %d parent field %d != %d' % (ni, nd[2], parent))
        mid = tuple((a + b) // 2 for a, b in zip(lo, hi))
        for k in range(8):
            c = nd[3 + k]
            if c == 0:
                continue
            clo = tuple(mid[a] if (k >> a) & 1 else lo[a] for a in range(3))
            chi = tuple(hi[a] if (k >> a) & 1 else mid[a] for a in range(3))
            if depth - 1 == 0:
                leaves.append((c, clo, chi, ni))
            else:
                stack.append((c, depth - 1, clo, chi, ni))
    return visits, leaves, errors


def local_to_world(pf, l):
    """GetGlobalCoords: local (l0,l1,l2) -> world
    (vmin.x + l0*sx/g0, vmin.y + l2*sy/g2, vmin.z + l1*sz/g1)."""
    vmin, vmax, g = pf['vmin'], pf['vmax'], pf['grid']
    return (vmin[0] + l[0] * (vmax[0] - vmin[0]) / g[0],
            vmin[1] + l[2] * (vmax[1] - vmin[1]) / g[2],
            vmin[2] + l[1] * (vmax[2] - vmin[2]) / g[1])


# --------------------------------------------------------------------------- checks
class Checks:
    def __init__(self):
        self.rows = []

    def add(self, name, ok, detail=''):
        self.rows.append((name, bool(ok), detail))

    def ok(self):
        return all(r[1] for r in self.rows)


def analyse(pf):
    ck = Checks()
    nodes, leaves, planes = pf['nodes'], pf['leaves'], pf['planes']
    areas, edges, links = pf['areas'], pf['edges'], pf['links']
    nsw = len(pf['super_words'])
    ck.add('blob parsed to end (even pad allowed)',
           pf['blob_end'] - pf['end'] in (0, 1), 'end 0x%x blob end 0x%x' % (pf['end'], pf['blob_end']))
    ck.add('grid = top_blocks << (num_levels-1)',
           all(t << (pf['num_levels'] - 1) == g for t, g in zip(pf['top_blocks'], pf['grid'])),
           '%s %s %d' % (pf['top_blocks'], pf['grid'], pf['num_levels']))
    ck.add('vmax - vmin = grid * cell (local1 = world z, local2 = world y)',
           all(abs((pf['vmax'][a] - pf['vmin'][a]) - pf['grid'][ga] * pf['cell'][a]) < 1e-3
               for a, ga in ((0, 0), (1, 2), (2, 1))))
    visits, lv, errs = walk(pf)
    ck.add('tree walk: no index/parent errors', not errs, '; '.join(errs[:3]))
    ck.add('every node 1..n-1 reached exactly once',
           len(visits) == len(nodes) - 1 and all(v == 1 for v in visits.values()),
           '%d of %d' % (len(visits), len(nodes) - 1))
    lcount = {}
    for c, lo, hi, par in lv:
        lcount[c] = lcount.get(c, 0) + 1
    bad_leaf = [c for c, _, _, _ in lv if not (0 < c < len(leaves))]
    ck.add('leaf refs in range', not bad_leaf, str(bad_leaf[:5]))
    # leaf 1 is a second reserved slot (copy of slot 0, parent 0) in every sample
    unreached = [k for k in range(2, len(leaves)) if k not in lcount]
    ck.add('every leaf 2..n-1 referenced exactly once; leaf 1 unreferenced, parent 0',
           not unreached and all(v == 1 for v in lcount.values()) and 1 not in lcount
           and leaves[1][2] == 0,
           '%d reached, unreached %s, multi %d' % (len(lcount), unreached[:5],
                                                  sum(1 for v in lcount.values() if v > 1)))
    ck.add('leaf box is 8x8x1 cells',
           all(tuple(h - l for l, h in zip(lo, hi)) == (8, 8, 1) for _, lo, hi, _ in lv))
    ck.add('leaf parent field = referencing node',
           all(leaves[c][2] == par for c, _, _, par in lv if 0 < c < len(leaves)))
    ck.add('runtime fields zero in file (node+2, leaf+0xa, leaf+2)',
           all(n[1] == 0 for n in nodes[1:]) and all(l[5] == 0 and l[1] == 0 for l in leaves[1:]))
    ck.add('area refs in range (nodes, leaves)',
           all(0 < n[0] < len(areas) for n in nodes[1:]) and all(0 < l[0] < len(areas) for l in leaves[1:]))
    vb = pf['value_bits']
    ck.add('leaf plane refs: plane + value_bits <= n',
           all(l[3] == 0 or l[3] + vb <= len(planes) for l in leaves[1:]))
    ck.add('leaf super refs: word + 2*nbits(ncomp) <= n',
           all(l[4] + 2 * nbits(areas[l[0]][0]) <= nsw for l in leaves[1:]))
    ck.add('area edge ranges in range',
           all(a[6] + pf['area_nedges'][k] <= len(edges) and (pf['area_nedges'][k] == 0 or a[6] > 0)
               for k, a in enumerate(areas) if k))
    ck.add('area remap ranges in range (remap + ncomp <= n)',
           all(a[4] + a[0] <= len(pf['remap']) for a in areas[1:]))
    ck.add('area split-bit index in range', all(a[5] < max(1, len(pf['split_bits'])) for a in areas[1:]))
    used_links = set()
    badl = []
    for k in range(1, len(edges)):
        e = edges[k]
        if e[5]:
            li = abs(e[5])
            used_links.add(li)
            if not (0 < li < len(links)):
                badl.append(k)
    ck.add('edge link refs in range', not badl, str(badl[:5]))
    bad0 = sum(1 for k in range(1, len(areas)) for e in edges[areas[k][6]:areas[k][6] + pf['area_nedges'][k]]
               if not (1 <= e[0] <= areas[k][0]))
    ck.add('edge byte0 in 1..ncomp of the owning area', bad0 == 0, '%d bad' % bad0)
    ck.add('edge offsets: local0/local1 in {-1,0,1} (local2 = vertical, free)',
           all(-1 <= e[2] <= 1 and -1 <= e[3] <= 1 for e in edges[1:]),
           'local2 range %d..%d' % (min(e[4] for e in edges[1:]), max(e[4] for e in edges[1:])))
    g = pf['grid']
    ck.add('link local points inside grid',
           all(all(l[a] < g[a % 3] for a in range(6)) for l in links[1:]))
    if pf['link_world']:
        worst = 0.0
        for k in range(1, len(links)):
            for h in (0, 1):
                wl = local_to_world(pf, links[k][3 * h:3 * h + 3])
                ww = pf['link_world'][k][3 * h:3 * h + 3]
                worst = max(worst, max(abs(a - b) for a, b in zip(wl, ww)))
        ck.add('link world points within 4 cells of local points', worst <= 4 * max(pf['cell']),
               'max |d| %.2f' % worst)
    if pf['link_actions']:
        ck.add('link actions: second = 0x4000 | first',
               all(b == (0x4000 | a) for a, b in pf['link_actions'][1:]))
    # cells
    walkable = 0
    comp_bad = 0
    cells = []
    for c, lo, hi, par in lv:
        if not (0 < c < len(leaves)):
            continue
        lf = leaves[c]
        nc = areas[lf[0]][0]
        for bit in range(64):
            v = cell_value(pf, lf, bit)
            sc = super_comp(pf, lf, bit) if nc else 0
            if v:
                walkable += 1
                if not (1 <= sc <= nc):
                    comp_bad += 1
                cells.append((lo[0] + (bit & 7), lo[1] + (bit >> 3), lo[2], v, sc))
            elif sc:
                comp_bad += 1
    ck.add('super component: walkable cells 1..ncomp, blocked cells 0', comp_bad == 0,
           '%d mismatches of %d walkable' % (comp_bad, walkable))
    # coverage
    pref = set()
    for l in leaves[1:]:
        if l[3]:
            pref.update(range(l[3], l[3] + vb))
    eref = set()
    for k, a in enumerate(areas):
        if k:
            eref.update(range(a[6], a[6] + pf['area_nedges'][k]))
    stats = dict(walkable=walkable, planes_used=len(pref), planes=len(planes) - 1,
                 edges_used=len(eref), edges=len(edges) - 1, links_used=len(used_links),
                 links=len(links) - 1, leaves_reached=len(lcount))
    return ck, cells, stats


# --------------------------------------------------------------------------- output
def write_obj(path, pf, cells):
    s = pf['cell']
    with open(path, 'w') as f:
        f.write('# Freedom Fighters pathfinding: walkable cells (ZPFOctree_packed), world space\n')
        f.write('# one quad per walkable %gx%gx%g voxel, at mid-voxel height (the floor lies inside\n'
                '# the voxel: 90%% of C01A cells have collision floor 0..25 above the voxel bottom)\n' % tuple(s))
        n = 0
        for x, z, y, v, sc in cells:
            wx, wy, wz = local_to_world(pf, (x, z, y))
            for dx, dz in ((0, 0), (1, 0), (1, 1), (0, 1)):
                f.write('v %.3f %.3f %.3f\n' % (wx + dx * s[0], wy + 0.5 * s[1], wz + dz * s[2]))
            f.write('f %d %d %d %d\n' % (n + 1, n + 2, n + 3, n + 4))
            n += 4


def png_write(path, w, h, rgb):
    raw = b''.join(b'\0' + bytes(rgb[y * w * 3:(y + 1) * w * 3]) for y in range(h))

    def chunk(t, d):
        c = struct.pack('>I', len(d)) + t + d
        return c + struct.pack('>I', zlib.crc32(t + d) & 0xffffffff)
    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 2, 0, 0, 0))
                + chunk(b'IDAT', zlib.compress(raw, 9)) + chunk(b'IEND', b''))


def read_obj_tris(path):
    vs, tris = [], []
    with open(path) as f:
        for line in f:
            if line.startswith('v '):
                vs.append(tuple(map(float, line.split()[1:4])))
            elif line.startswith('f '):
                idx = [int(t.split('/')[0]) - 1 for t in line.split()[1:]]
                for k in range(1, len(idx) - 1):
                    tris.append((idx[0], idx[k], idx[k + 1]))
    return vs, tris


def write_png(path, pf, cells, coli=None, margin=40):
    """Top-down (x right, world z down), 1 px = 1 cell.  Collision triangles grey
    (walls = steep triangles dark), walkable cells coloured by height (blue low ->
    red high), special links black."""
    s = pf['cell'][0]
    x0 = min(c[0] for c in cells) - margin
    x1 = max(c[0] for c in cells) + 1 + margin
    z0 = min(c[1] for c in cells) - margin
    z1 = max(c[1] for c in cells) + 1 + margin
    W, H = x1 - x0, z1 - z0
    img = bytearray([255] * (W * H * 3))
    if coli:
        vs, tris = read_obj_tris(coli)
        wx0, wz0 = pf['vmin'][0], pf['vmin'][2]
        for t in tris:
            p = [vs[i] for i in t]
            u = [p[1][k] - p[0][k] for k in range(3)]
            v = [p[2][k] - p[0][k] for k in range(3)]
            n = (u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0])
            ln = (n[0] ** 2 + n[1] ** 2 + n[2] ** 2) ** 0.5
            if ln == 0:
                continue
            steep = abs(n[1]) / ln < 0.5
            col = b'\x60\x60\x60' if steep else b'\xd0\xd0\xd0'
            ax = [(q[0] - wx0) / s - x0 for q in p]
            az = [(q[2] - wz0) / s - z0 for q in p]
            mnx, mxx = max(0, int(min(ax))), min(W - 1, int(max(ax)))
            mnz, mxz = max(0, int(min(az))), min(H - 1, int(max(az)))
            if mnx > mxx or mnz > mxz:
                continue
            d = (ax[1] - ax[0]) * (az[2] - az[0]) - (az[1] - az[0]) * (ax[2] - ax[0])
            for zz in range(mnz, mxz + 1):
                cz = zz + 0.5
                for xx in range(mnx, mxx + 1):
                    cx = xx + 0.5
                    if abs(d) > 1e-9:
                        e0 = (ax[2] - ax[1]) * (cz - az[1]) - (az[2] - az[1]) * (cx - ax[1])
                        e1 = (ax[0] - ax[2]) * (cz - az[2]) - (az[0] - az[2]) * (cx - ax[2])
                        e2 = (ax[1] - ax[0]) * (cz - az[0]) - (az[1] - az[0]) * (cx - ax[0])
                        if d > 0 and (e0 < 0 or e1 < 0 or e2 < 0):
                            continue
                        if d < 0 and (e0 > 0 or e1 > 0 or e2 > 0):
                            continue
                    o = (zz * W + xx) * 3
                    if steep or img[o] == 255:
                        img[o:o + 3] = col
    ys = sorted(c[2] for c in cells)
    y0, y1 = ys[len(ys) // 100], ys[-len(ys) // 100 - 1]
    for x, z, y, v, sc in sorted(cells, key=lambda c: c[2]):
        t = min(1.0, max(0.0, (y - y0) / max(1, y1 - y0)))
        col = (int(40 + 215 * t), int(150 - 60 * t), int(230 - 200 * t))
        o = ((z - z0) * W + (x - x0)) * 3
        img[o:o + 3] = bytes(col)
    for k in range(1, len(pf['links'])):
        l = pf['links'][k]
        for h in (0, 1):
            xx, zz = l[3 * h] - x0, l[3 * h + 1] - z0
            for dx in (-1, 0, 1):
                for dz in (-1, 0, 1):
                    if 0 <= xx + dx < W and 0 <= zz + dz < H:
                        o = ((zz + dz) * W + xx + dx) * 3
                        img[o:o + 3] = b'\0\0\0'
    png_write(path, W, H, img)
    return W, H, (x0, z0, y0, y1)


# --------------------------------------------------------------------------- main
def sibling(path, ext):
    stem = os.path.splitext(path)[0]
    for e in (ext, ext.lower()):
        if os.path.exists(stem + '.' + e):
            return stem + '.' + e
    return None


def main(argv):
    args = argv[1:]
    if not args or args[0] in ('-h', '--help'):
        print(__doc__)
        return 2
    path = args[0]
    verbose = '-v' in args

    def opt(name):
        return args[args.index(name) + 1] if name in args else None
    body = load_gms(path)
    bp = sibling(path, 'BUF')
    buf = open(bp, 'rb').read() if bp else None
    pfs = find_pathfinders(body, buf)
    print('%s: GMS body %d bytes' % (os.path.basename(path), len(body)))
    if not pfs:
        print('no ZPathfinder3 geom (class 0x%x) in this scene: no pathfinding data' % PF_CLASS)
        return 0
    rc = 0
    for g in pfs:
        print('geom #%d "%s" record 0x%x, data block 0x%x' % (g['index'], g['name'], g['rec'], g['dblk']))
        db = parse_dblk(body, g['dblk'])
        print('  DBLK header 0x%08x: size %d, %d items, parsed to 0x%x (end 0x%x)'
              % (db['header'], db['total'], len(db['items']), db['parsed_to'], db['end']))
        st = pathfinder_settings(db['items'])
        for k, it in st.items():
            if k.startswith('_') or k == 'blob':
                continue
            print('  %-22s %s' % (k, it.get('refs', it.get('value'))))
        if '--dump-dblk' in args:
            for it in db['items']:
                print('    0x%06x tag 0x%02x %-9s %s' % (it['off'], it['tag'], DBLK_TYPES.get(it['type'], it['type']),
                                                       it.get('size', it.get('value', it.get('refs', '')))))
        if 'blob' not in st:
            print('  no pathfinder blob')
            rc = 1
            continue
        bl = st['blob']
        pf = parse_blob(body, bl['data'], bl['size'])
        print('  blob @0x%x, %d bytes: magic 0x%08x (%s), cPackData %d'
              % (bl['data'], bl['size'], pf['magic'], MAGICS[pf['magic']], pf['cPackData']))
        print('  grid %s cells of %s, top blocks %s, levels %d, u50 %d'
              % (pf['grid'], pf['cell'], pf['top_blocks'], pf['num_levels'], pf['u50']))
        print('  vmin %s vmax %s' % (pf['vmin'], pf['vmax']))
        print('  value_bits %d, plane_words %d' % (pf['value_bits'], pf['plane_words']))
        for k in ('nodes', 'leaves', 'planes', 'split_bits', 'edges', 'links', 'link_actions',
                  'link_world', 'super_words', 'areas', 'remap'):
            print('  %-13s %6d (incl. unused slot 0)' % (k, len(pf[k])))
        ck, cells, stats = analyse(pf)
        print('  walkable cells %d, planes used %d/%d, edges used %d/%d, '
              'links used %d/%d' % (stats['walkable'], stats['planes_used'],
                                    stats['planes'], stats['edges_used'], stats['edges'],
                                    stats['links_used'], stats['links']))
        if cells:
            lo = local_to_world(pf, (min(c[0] for c in cells), min(c[1] for c in cells), min(c[2] for c in cells)))
            hi = local_to_world(pf, (max(c[0] for c in cells) + 1, max(c[1] for c in cells) + 1,
                                     max(c[2] for c in cells) + 1))
            print('  walkable world bounds (%.0f,%.0f,%.0f) .. (%.0f,%.0f,%.0f)' % (lo + hi))
        if verbose:
            for k in range(1, len(pf['links'])):
                a = pf['link_actions'][k] if pf['link_actions'] else None
                w = pf['link_world'][k] if pf['link_world'] else None
                print('    link %2d local %s -> %s action %s world %s' % (
                    k, pf['links'][k][:3], pf['links'][k][3:], a,
                    tuple(round(x, 1) for x in w) if w else None))
        print('  checks:')
        for name, ok, det in ck.rows:
            print('    [%s] %s%s' % ('ok' if ok else 'FAIL', name, ('  (' + det + ')') if det else ''))
        if not ck.ok():
            rc = 1
        if opt('--obj'):
            write_obj(opt('--obj'), pf, cells)
            print('  wrote %s (%d quads)' % (opt('--obj'), len(cells)))
        if opt('--png'):
            coli = opt('--coli')
            if coli is None:
                d = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'C01A_collision.obj')
                coli = os.path.join(os.path.dirname(__file__), 'C01A_collision.obj') if os.path.exists(d) and 'C01A' in os.path.basename(path).upper() else None
            W, H, info = write_png(opt('--png'), pf, cells, coli)
            print('  wrote %s (%dx%d, 1 px = 1 cell, collision %s)' % (opt('--png'), W, H, coli))
    print('RESULT: %s' % ('PASS' if rc == 0 else 'FAIL'))
    return rc


if __name__ == '__main__':
    sys.exit(main(sys.argv))
