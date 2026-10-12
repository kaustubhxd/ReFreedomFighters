#!/usr/bin/env python3
"""Freedom Fighters (Glacier 1, PC) .OCT decoder -- "Trees" file: compiled octrees.

usage: python3 -I oct.py FILE.OCT [--prm FILE.PRM] [--gms FILE.GMS] [--buf FILE.BUF]
                                  [--obj out.obj] [--all-instances] [--rooms N] [-v]

  Prints a summary and runs structural checks.  PRM/GMS/BUF default to the
  siblings of FILE.OCT (same stem) when present.
  --obj out.obj    write prim collision triangles placed in world space with the
                   GMS instance matrix/position.  By default only instances whose
                   world AABB equals a room bound-tree box (proof that the placement
                   is world-space) are written; --all-instances writes every
                   instance (children of groups then land at parent-relative spots).
  --rooms N        override the number of 5-tree room bundles (normally found
                   structurally, and cross-checked against the GMS ZROOM count).

File layout (little-endian; see oct-format.md for proofs):
  0x00  u32 rootStaticFlag, u32[3] unused            (16 bytes)
  rooms*5 bound-tree records (ZTreeGroup::LoadBoundTrees):
        u32 len; len==0 -> 16-byte empty slot
        else: f32 scale, f32 origin[3], 12 zero bytes, len bytes tree data, pad to 16
  prim collision trees (ZCollisionBase::LoadInternColiTree), until u32 0xFFFFFFFF:
        u32 recLen (whole record), 28 bytes placeholder for the runtime ZOctreeCompiled
        object, tree data at +0x20; next record at +recLen
  u32 0xFFFFFFFF
  unique sub-strip table (LoadUniqueSubStripInfo): (EOF-pos)/8 entries of
        u32 strip (bit31 winding, bits30..16 start word, bits15..0 index count),
        u32 PRM entry offset
Tree data (ZOctreeCompiled): u32 objOff, f32 origin[3], f32 scale, nodes at +0x14
  (6 bytes: u16 w0 [bit15 last sibling, bits14..3 objCount, bits2..0 octant],
   u16 firstChild (0 = none), u16 firstObj), objects at +objOff
  (16 bytes: u32 id, u16 min[3], u16 max[3]); world = (q-32768)/scale + origin.
"""
import os
import struct
import sys
import zlib

TREE_TYPES = ['ZSTDOBJ (static meshes)', 'ZLIGHT', 'ZGATE (portals)', 'ZGROUP',
              'ZTreeGroup']
END = 0xFFFFFFFF


class OctError(Exception):
    pass


class Reader:
    def __init__(self, data):
        self.d = data
        self.n = len(data)

    def u32(self, o):
        if o < 0 or o + 4 > self.n:
            raise OctError('read u32 out of range at 0x%x' % o)
        return struct.unpack_from('<I', self.d, o)[0]

    def unpack(self, fmt, o):
        sz = struct.calcsize(fmt)
        if o < 0 or o + sz > self.n:
            raise OctError('read %s out of range at 0x%x' % (fmt, o))
        return struct.unpack_from(fmt, self.d, o)


def decode_tree(r, d, length):
    """Decode ZOctreeCompiled data at offset d spanning length bytes."""
    if length < 0x1a:
        raise OctError('tree at 0x%x too short (%d)' % (d, length))
    objoff, ox, oy, oz, sc = r.unpack('<I4f', d)
    if objoff < 0x1a or objoff > length or (objoff - 0x14) < 6:
        raise OctError('tree at 0x%x: bad objOff 0x%x' % (d, objoff))
    nslots = (objoff - 0x14) // 6
    nobjslots = (length - objoff) // 16
    nodes = [r.unpack('<3H', d + 0x14 + 6 * i) for i in range(nslots)]
    used_nodes = set()
    obj_refs = []
    depth = 0
    stack = [(0, 0)]
    while stack:
        i, lv = stack.pop()
        if i in used_nodes:
            raise OctError('tree at 0x%x: node %d visited twice' % (d, i))
        if i >= nslots:
            raise OctError('tree at 0x%x: node %d out of range' % (d, i))
        used_nodes.add(i)
        depth = max(depth, lv)
        w0, child, first = nodes[i]
        cnt = (w0 >> 3) & 0xFFF
        for k in range(cnt):
            obj_refs.append(first + k)
        if child:
            j = child
            while True:
                if j >= nslots:
                    raise OctError('tree at 0x%x: child %d out of range' % (d, j))
                stack.append((j, lv + 1))
                if nodes[j][0] & 0x8000:
                    break
                j += 1
    nobj = (max(obj_refs) + 1) if obj_refs else 0
    if nobj > nobjslots:
        raise OctError('tree at 0x%x: object %d beyond data' % (d, nobj - 1))
    objs = [r.unpack('<I6H', d + objoff + 16 * i) for i in range(nobj)]
    for o in objs:
        if any(o[1 + a] > o[4 + a] for a in range(3)):
            raise OctError('tree at 0x%x: object with min > max' % d)
    return dict(objoff=objoff, origin=(ox, oy, oz), scale=sc, nodes=len(used_nodes),
                node_slots=nslots, objs=objs, obj_refs=len(obj_refs),
                obj_unique=len(set(obj_refs)), depth=depth,
                pad_objs=nobjslots - nobj)


def obj_box(o, scale, origin):
    mn = tuple((o[1 + a] - 32768) / scale + origin[a] for a in range(3))
    mx = tuple((o[4 + a] - 32768) / scale + origin[a] for a in range(3))
    return mn, mx


def is_prim_record(r, p):
    """A prim (intern) record repeats the tree origin/scale at +8..+0x18 (placeholder
    object fields) and at +0x24..+0x34 (tree data header); a bound-tree record has
    zeros at +0x14..+0x20 instead."""
    try:
        if r.u32(p) < 0x34:
            return False
        a = r.d[p + 8:p + 0x18]
        b = r.d[p + 0x24:p + 0x34]
        return a == b and r.d[p + 0x14:p + 0x20] != bytes(12)
    except OctError:
        return False


def parse_oct(data, rooms=None):
    r = Reader(data)
    res = dict(size=len(data))
    res['header'] = r.unpack('<4I', 0)
    p = 16
    groups = []
    while True:
        if rooms is not None and len(groups) >= rooms:
            break
        if rooms is None and (r.u32(p) == END or is_prim_record(r, p)):
            break
        g = []
        for k in range(5):
            L = r.u32(p)
            if L == 0:
                g.append(None)
                p += 16
                continue
            sc, ox, oy, oz = r.unpack('<4f', p + 4)
            if L == END or p + 32 + L > len(data):
                raise OctError('bound record at 0x%x: bad length 0x%x' % (p, L))
            t = decode_tree(r, p + 32, L)
            t.update(rec=p, len=L, outer_scale=sc, outer_origin=(ox, oy, oz),
                     outer_matches=(abs(sc - t['scale']) < 1e-6 and
                                    (ox, oy, oz) == t['origin']))
            g.append(t)
            p += 32 + ((L + 15) & ~15)
        groups.append(g)
    res['groups'] = groups
    res['prim_start'] = p
    prims = {}
    while True:
        L = r.u32(p)
        if L == END:
            break
        if L < 0x34 or p + L > len(data):
            raise OctError('prim record at 0x%x: bad length 0x%x' % (p, L))
        t = decode_tree(r, p + 0x20, L - 0x20)
        t.update(rec=p, len=L)
        prims[p] = t
        p += L
    res['prims'] = prims
    res['end_marker'] = p
    p += 4
    rem = len(data) - p
    if rem % 8:
        raise OctError('sub-strip table size %d not a multiple of 8' % rem)
    res['substrip_off'] = p
    res['substrips'] = [r.unpack('<II', p + 8 * i) for i in range(rem // 8)]
    return res


# ---------------------------------------------------------------- PRM / GMS
class Prm:
    def __init__(self, data):
        self.r = Reader(data)
        magic, t1, t2, n = self.r.unpack('<4I', 0)
        if magic != 0x12ABC:
            raise OctError('PRM magic 0x%x' % magic)
        self.table = [x & 0x1FFFFFF for x in self.r.unpack('<%dI' % n, t1)]

    def entry_ok(self, e):
        return 0 < e and e + 0x7c <= self.r.n

    def coll_record(self, e):
        """PRM entry +0x28: (OCT offset of prim record + 4) | 1, or no bit0."""
        v = self.r.u32(e + 0x28)
        return (v & ~1) - 4 if v & 1 else None

    def substrip_tris(self, w0, e):
        """Exactly as PC 0x6616f0/0x661b40: idx = PRM+[e+0x3c]+2*start, walks
        count-2 triangles, winding starts at bit31 and alternates; 36-byte stride."""
        r = self.r
        if not self.entry_ok(e):
            raise OctError('sub-strip PRM entry 0x%x out of range' % e)
        flip = w0 >> 31
        start = (w0 >> 16) & 0x7FFF
        cnt = w0 & 0xFFFF
        vb = r.u32(e + 0x14)
        ib = r.u32(e + 0x3c)
        nidx = r.u32(e + 0x40)
        nv = r.unpack('<H', e + 0x0e)[0]
        if start + cnt > nidx:
            raise OctError('sub-strip beyond index block of entry 0x%x' % e)
        idx = r.unpack('<%dH' % cnt, ib + 2 * start) if cnt else ()
        out = []
        degenerate = 0
        for k in range(max(0, cnt - 2)):
            a, b, c = idx[k], idx[k + 1], idx[k + 2]
            t = (a, c, b) if flip else (a, b, c)
            flip ^= 1
            if a == b or b == c or a == c:
                degenerate += 1
                continue
            if max(t) >= nv:
                raise OctError('index out of range in entry 0x%x' % e)
            out.append(tuple(r.unpack('<3f', vb + 36 * v) for v in t))
        return out, degenerate


def load_gms(path):
    raw = open(path, 'rb').read()
    us, cs = struct.unpack_from('<II', raw, 0)
    body = zlib.decompress(raw[9:], -15)
    if len(body) != us:
        raise OctError('GMS size mismatch')
    return body


def gms_instances(body, buf):
    """Per oct-format.md: table at u32 @0: count, then {u32 packed, u32}; record at
    ((packed & 0x3fffff)*4) & 0xffffff; +0 BUF name, +4 matrix off, +8 pos off,
    +0xc PRM entry, +0x10 class id."""
    r = Reader(body)
    t = r.u32(0)
    n = r.u32(t)
    seen = set()
    out = []
    for i in range(n):
        packed = r.u32(t + 4 + 8 * i)
        a = ((packed & 0x3FFFFF) * 4) & 0xFFFFFF
        if a == 0 or a in seen or a + 0x30 > r.n:
            continue
        seen.add(a)
        nm = r.u32(a)
        name = ''
        if buf is not None and nm < len(buf):
            e = buf.find(b'\0', nm)
            name = buf[nm:e].decode('latin-1')
        out.append(dict(index=i, rec=a, name=name, cls=r.u32(a + 0x10),
                        mat_off=r.u32(a + 4), pos_off=r.u32(a + 8),
                        prm=r.u32(a + 0xc) & 0x1FFFFFF))
    return out


def xform(m, o, v):
    # convention from earlier viewer, without its final render z flip
    x, y, z = v
    return (x * m[2] + y * m[1] + z * m[0] + o[0],
            x * m[5] + y * m[4] + z * m[3] + o[1],
            x * m[8] + y * m[7] + z * m[6] + o[2])


# ---------------------------------------------------------------- main
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
    opts = {}
    pos = []
    i = 0
    while i < len(args):
        a = args[i]
        if a in ('--prm', '--gms', '--buf', '--obj', '--rooms'):
            opts[a] = args[i + 1]
            i += 2
        elif a in ('--all-instances', '-v'):
            opts[a] = True
            i += 1
        else:
            pos.append(a)
            i += 1
    path = pos[0]
    data = open(path, 'rb').read()
    rooms = int(opts['--rooms']) if '--rooms' in opts else None
    res = parse_oct(data, rooms)
    verbose = '-v' in opts

    print('%s: %d bytes' % (path, res['size']))
    h = res['header']
    print('header: rootStaticFlag=%d unused=%s' % (h[0], list(h[1:])))
    groups = res['groups']
    print('room bound-tree bundles: %d (5 trees each, end 0x%x)' % (len(groups),
                                                                  res['prim_start']))
    tot = [0] * 5
    ids = []
    outer_bad = 0
    for gi, g in enumerate(groups):
        line = []
        for k, t in enumerate(g):
            if t is None:
                line.append('-')
                continue
            tot[k] += len(t['objs'])
            ids += [o[0] for o in t['objs']]
            outer_bad += not t['outer_matches']
            line.append('%d' % len(t['objs']))
        if verbose:
            t0 = next((t for t in g if t), None)
            extra = ''
            if t0:
                extra = ' scale=%.4g origin=(%.1f,%.1f,%.1f)' % ((t0['scale'],) + t0['origin'])
            print('  bundle %2d objects per slot [%s]%s' % (gi, ' '.join(line), extra))
    for k in range(5):
        print('  slot %d %-24s objects %d' % (k, TREE_TYPES[k], tot[k]))
    stat = sum(1 for x in ids if x & 0x40000000 and (x & 0x3FFFFFFF) % 0x70 == 0)
    print('  object ids: %d, static geom refs (0x40000000|index*0x70): %d' % (len(ids), stat))
    if outer_bad:
        print('  WARNING: %d trees whose record scale/origin differ from tree header' % outer_bad)
    prims = res['prims']
    nobj = sum(len(t['objs']) for t in prims.values())
    print('prim collision trees: %d (0x%x..0x%x), %d objects' % (
        len(prims), res['prim_start'], res['end_marker'], nobj))
    subs = res['substrips']
    print('unique sub-strip table: %d entries at 0x%x, ends at EOF' % (len(subs),
                                                                      res['substrip_off']))
    bad_ids = 0
    refd = set()
    for t in prims.values():
        for o in t['objs']:
            if o[0] % 8 or o[0] // 8 >= len(subs):
                bad_ids += 1
            else:
                refd.add(o[0] // 8)
    print('  prim-tree object ids are byte offsets into it: %d ok, %d bad; %d/%d entries referenced'
          % (nobj - bad_ids, bad_ids, len(refd), len(subs)))
    alltrees = [t for g in groups for t in g if t] + list(prims.values())
    print('trees: %d, nodes %d (all reached), max depth %d, padding object slots %d'
          % (len(alltrees), sum(t['nodes'] for t in alltrees),
             max([t['depth'] for t in alltrees] or [0]),
             sum(t['pad_objs'] for t in alltrees)))
    print('parsed to EOF: yes')

    buf = None
    bpath = opts.get('--buf') or sibling(path, 'BUF')
    if bpath:
        buf = open(bpath, 'rb').read()
    gpath = opts.get('--gms') or sibling(path, 'GMS')
    gms = None
    if gpath:
        gms = load_gms(gpath)
        insts = gms_instances(gms, buf)
        nrooms = sum(1 for x in insts if x['cls'] == 0x100021)
        exp = nrooms + (1 if h[0] else 0)
        print('GMS: %d ZROOM (class 0x100021) + rootStaticFlag %d -> expected bundles %d: %s'
              % (nrooms, h[0], exp, 'OK' if exp == len(groups) else 'MISMATCH'))
    ppath = opts.get('--prm') or sibling(path, 'PRM')
    if not ppath:
        if '--obj' in opts:
            print('--obj needs the PRM file')
            return 1
        return 0
    prm = Prm(open(ppath, 'rb').read())
    linked = {}
    for e in prm.table:
        if prm.entry_ok(e):
            rr = prm.coll_record(e)
            if rr is not None:
                linked.setdefault(rr, []).append(e)
    good = sum(1 for k in linked if k in prims)
    print('PRM: %d root entries with +0x28 bit0 link -> %d distinct targets, %d are prim records; '
          '%d/%d prim records linked' % (sum(len(v) for v in linked.values()), len(linked),
                                         good, sum(1 for k in prims if k in linked), len(prims)))
    tri_cache = {}
    ntri = ndeg = 0
    coli = {}
    for si, (w0, e) in enumerate(subs):
        tr, dg = prm.substrip_tris(w0, e)
        tri_cache[si] = tr
        ntri += len(tr)
        ndeg += dg
        cb = prm.r.u32(e + 0x2c)
        coli[cb] = coli.get(cb, 0) + 1
    print('sub-strips decode: %d triangles (%d degenerate skipped) from %d PRM entries'
          % (ntri, ndeg, len(set(e for w, e in subs))))
    if verbose:
        print('  PRM entry +0x2c coli bits histogram: %s' % ', '.join(
            '0x%x:%d' % kv for kv in sorted(coli.items(), key=lambda kv: -kv[1])[:12]))

    def prim_tris(rec):
        ids_ = sorted(set(o[0] // 8 for o in prims[rec]['objs']))
        out = []
        for s in ids_:
            out += tri_cache[s]
        return out

    if gms is None:
        if '--obj' in opts:
            print('--obj needs the GMS file')
            return 1
        return 0
    # world placement validation against room slot-0 boxes
    boxes = {}
    for g in groups:
        t = g[0]
        if t is None:
            continue
        for o in t['objs']:
            mn, mx = obj_box(o, t['scale'], t['origin'])
            boxes.setdefault(int(mn[0] // 64), []).append((mn, mx, 1.0 / t['scale'], o[0]))
    gr = Reader(gms)
    placed = []
    nmatch = ncand = 0
    for ins in insts:
        e = ins['prm']
        if not prm.entry_ok(e):
            continue
        rec = prm.coll_record(e)
        if rec is None or rec not in prims:
            continue
        try:
            m = gr.unpack('<9f', ins['mat_off'])
            o = gr.unpack('<3f', ins['pos_off'])
        except OctError:
            continue
        tris = prim_tris(rec)
        if not tris:
            continue
        ncand += 1
        pts = [xform(m, o, v) for t in tris for v in t]
        mn = [min(q[a] for q in pts) for a in range(3)]
        mx = [max(q[a] for q in pts) for a in range(3)]
        hit = None
        kx = int(mn[0] // 64)
        for kk in (kx - 1, kx, kx + 1):
            for b in boxes.get(kk, ()):
                tol = 1.5 * b[2] + 0.5
                if all(abs(b[0][a] - mn[a]) <= tol and abs(b[1][a] - mx[a]) <= tol
                       for a in range(3)):
                    hit = b
                    break
            if hit:
                break
        if hit:
            nmatch += 1
        placed.append((ins, m, o, tris, hit))
    print('GMS instances using a prim collision tree: %d; world AABB equal to a room slot-0 '
          'box: %d' % (ncand, nmatch))
    if '--obj' in opts:
        allm = '--all-instances' in opts
        nv = 0
        nt = 0
        lo = [1e30] * 3
        hi = [-1e30] * 3
        with open(opts['--obj'], 'w') as f:
            f.write('# Freedom Fighters OCT prim collision, placed with GMS transforms\n')
            f.write('# source %s\n' % os.path.basename(path))
            for ins, m, o, tris, hit in placed:
                if not (hit or allm):
                    continue
                nm = ''.join(c if c.isalnum() or c in '_-' else '_' for c in ins['name'])
                f.write('o %s_%d\n' % (nm or 'geom', ins['index']))
                vmap = {}
                faces = []
                for t in tris:
                    fi = []
                    for v in t:
                        if v not in vmap:
                            w = xform(m, o, v)
                            for a in range(3):
                                lo[a] = min(lo[a], w[a])
                                hi[a] = max(hi[a], w[a])
                            f.write('v %.2f %.2f %.2f\n' % w)
                            nv += 1
                            vmap[v] = nv
                        fi.append(vmap[v])
                    faces.append(fi)
                for fi in faces:
                    f.write('f %d %d %d\n' % tuple(fi))
                    nt += 1
        print('OBJ: %s, %d triangles, bounds min (%.0f, %.0f, %.0f) max (%.0f, %.0f, %.0f)'
              % ((opts['--obj'], nt) + tuple(lo) + tuple(hi)))
    return 0


if __name__ == '__main__':
    try:
        sys.exit(main(sys.argv))
    except OctError as ex:
        print('error: %s' % ex)
        sys.exit(1)
