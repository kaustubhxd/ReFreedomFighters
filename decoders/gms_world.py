#!/usr/bin/env python3
"""Freedom Fighters (Glacier 1, PC) GMS scene hierarchy and world transforms.

usage: python3 -I gms_world.py FILE.GMS [--buf FILE.BUF] [--oct FILE.OCT --prm FILE.PRM]
                                        [--tree] [--find NAME]

  Prints a summary of the geom hierarchy rebuilt from the GMS instance table.
  --oct/--prm   (default: siblings of FILE.GMS) run the placement check: every
                static geom reference in the OCT room bound trees is resolved to
                its GMS geom, and each slot-0 box is compared with the geom's
                collision mesh placed with the composed world transform.
  --tree        print the hierarchy (indented).
  --find NAME   print geoms whose name contains NAME, with world position.

Import use (stdlib only):
    import gms_world
    scene = gms_world.load_scene('FF-C01A_MAIN.GMS')   # BUF sibling found automatically
    g = scene.geoms[i]          # dict, see Scene.__init__
    scene.world_point(i, (x, y, z))    # model-local -> world for geom i
    scene.by_static_ref[0x40002df0]    # geom created at static slot 0x2df0/0x70

What it does, and the proof (see

* The instance table (GMS u32 @0 -> u32 count, count x {u32 w, u32 aux}) is walked in
  order by ZEngineDataBase::CreateGeoms.  For each entry:
      pop  = w >> 25            go up `pop` parents first (vtable +0x48 = parent)
      rec  = (w << 2) & 0x03fffffc   SCompiledGeom record offset in the GMS body
      push = w & 0x01000000     after creating, the new geom becomes the parent
  Every entry creates one geom (aliased records are instantiated again).
* SetMatPos(rec+4 matrix, rec+8 position) stores them unchanged in
  the ZBaseGeom (+0 / +0x24); ZBaseGeom::GetLocalPoint recurses into
  the parent (+0x50) first, so they are parent-relative.
* Matrix convention (verified on all OCT boxes, see section 6 of the spec): for
  GMS floats m[0..8] and position p,
      world = R * local + p,  R[i][j] = m[3*(2-j) + i]
      x' = m6*x + m3*y + m0*z + p0
      y' = m7*x + m4*y + m1*z + p1
      z' = m8*x + m5*y + m2*z + p2
  and the world transform of a geom is parent_world o local (column vectors).
  (The GMS identity is stored as 0,0,1, 0,1,0, 1,0,0.)  oct.py's xform used
  x*m2+y*m1+z*m0..., which agrees only for rotations about the vertical axis.
* Static geom slot ("geom ref" 0x40000000|offset, as used by OCT, RMC, RMI, SGP):
  the root group takes slot 0; then per block of children (allocated when the
  first child after a push is created) the counts table (GMS u32 @0x14 -> u32 n,
  n x 24 u32) gives 24 list counts; list k gets a contiguous run.  A geom goes to
  list GetBaseGeomListType(class) + 8*rec[0x2d]; each geom whose class
  has bit 0x100000 (group) advances to the next counts record.
"""
import os
import struct
import sys
import zlib

ROOT = -1


class GmsError(Exception):
    pass


def load_gms(path):
    """GMS wrapper: u32 rawSize, u32 streamEnd, u8 mode(0 = raw deflate)."""
    raw = open(path, 'rb').read()
    if len(raw) < 9:
        raise GmsError('GMS too short')
    usize = struct.unpack_from('<I', raw, 0)[0]
    if raw[8] != 0:
        raise GmsError('unsupported GMS compression mode %d' % raw[8])
    d = zlib.decompressobj(-15)
    body = d.decompress(raw[9:], usize + 1)
    if len(body) != usize:
        raise GmsError('GMS size mismatch %d != %d' % (len(body), usize))
    return body


def list_type(cls):
    """GetBaseGeomListType__FUiUi; second argument unused."""
    if cls == 0x04000022:
        return 1
    if cls & 0x200000:
        return 3 if cls in (0x200015, 0x20001c, 0x200012) else 1
    if cls & 0x100000:
        return 0
    if cls & 0x800000:
        return 2
    return 3


def _mm(a, b):
    return [[a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j]
             for j in range(3)] for i in range(3)]


def _mv(a, v):
    return [a[i][0] * v[0] + a[i][1] * v[1] + a[i][2] * v[2] for i in range(3)]


def gms_matrix(m):
    """GMS 9 floats -> 3x3 column-vector rotation R (world = R*local + p)."""
    return [[m[3 * (2 - j) + i] for j in range(3)] for i in range(3)]


class Scene:
    def __init__(self, body, buf=None):
        self.body = body
        self.buf = buf
        n_body = len(body)

        def u32(o):
            if o < 0 or o + 4 > n_body:
                raise GmsError('read beyond GMS body at 0x%x' % o)
            return struct.unpack_from('<I', body, o)[0]

        def fl(o, k):
            if o < 0 or o + 4 * k > n_body:
                raise GmsError('read beyond GMS body at 0x%x' % o)
            return struct.unpack_from('<%df' % k, body, o)

        table = u32(0)
        count = u32(table)
        if count > (n_body - table) // 8:
            raise GmsError('instance count %d too large' % count)
        counts_off = u32(0x14)
        n_counts = u32(counts_off)
        if n_counts > (n_body - counts_off) // 0x60:
            raise GmsError('counts table too large')
        self.table_off = table
        geoms = []
        parents = []
        cur = ROOT
        cursors = []
        need_alloc = True
        ci = 0
        next_free = 0x70          # slot 0 = root group (AllocRootGroup)
        for i in range(count):
            w, aux = struct.unpack_from('<II', body, table + 4 + 8 * i)
            pop = w >> 25
            for _ in range(pop):
                if not parents:
                    raise GmsError('entry %d pops above the root' % i)
                cur = parents.pop()
                cursors.pop()
            if need_alloc:
                if ci >= n_counts:
                    raise GmsError('counts table exhausted at entry %d' % i)
                cnt = struct.unpack_from('<24I', body, counts_off + 4 + 0x60 * ci)
                cs = []
                for k in range(24):
                    cs.append(next_free if cnt[k] else None)
                    next_free += cnt[k] * 0x70
                cursors.append([cs, list(cnt)])
                need_alloc = False
            rec = (w << 2) & 0x03FFFFFC
            if rec + 0x30 > n_body:
                raise GmsError('entry %d: record 0x%x out of range' % (i, rec))
            cls = u32(rec + 0x10)
            k = list_type(cls) + 8 * body[rec + 0x2d]
            if k >= 24:
                raise GmsError('entry %d: list index %d' % (i, k))
            cs, left = cursors[-1]
            if cs[k] is None or left[k] == 0:
                raise GmsError('entry %d: no static slot left in list %d' % (i, k))
            slot = cs[k]
            cs[k] += 0x70
            left[k] -= 1
            m = fl(u32(rec + 4), 9)
            p = fl(u32(rec + 8), 3)
            name = ''
            if buf is not None:
                no = u32(rec)
                if no < len(buf):
                    e = buf.find(b'\0', no)
                    name = buf[no:e if e >= 0 else len(buf)].decode('latin-1')
            g = dict(index=i, rec=rec, cls=cls, parent=cur, children=[],
                     depth=len(parents), name=name, aux=aux,
                     flags=u32(rec + 0x18), prm=u32(rec + 0xc) & 0x1FFFFFF,
                     static_off=slot, static_ref=0x40000000 | slot,
                     static_index=slot // 0x70, mat=m, pos=p)
            R = gms_matrix(m)
            if cur == ROOT:
                g['wR'], g['wp'] = R, list(p)
            else:
                pg = geoms[cur]
                pg['children'].append(i)
                g['wR'] = _mm(pg['wR'], R)
                g['wp'] = [a + b for a, b in zip(_mv(pg['wR'], p), pg['wp'])]
            geoms.append(g)
            if cls & 0x100000:
                ci += 1
            if w & 0x01000000:
                parents.append(cur)
                cur = i
                need_alloc = True
        self.geoms = geoms
        self.static_size = next_free
        self.by_static_ref = {g['static_ref']: g for g in geoms}
        self.counts_used = ci + 1      # first block + one per group geom
        self.counts_total = n_counts

    # ------------------------------------------------------------ helpers
    def world_point(self, i, v):
        g = self.geoms[i]
        return [a + b for a, b in zip(_mv(g['wR'], v), g['wp'])]

    def world_matrix(self, i):
        """(R, p): R 3x3 column-vector rotation, p translation."""
        g = self.geoms[i]
        return g['wR'], g['wp']

    def ancestors(self, i):
        out = []
        while i != ROOT:
            out.append(i)
            i = self.geoms[i]['parent']
        return out

    def path(self, i):
        """Backslash-joined names from the top-level geom down (the form used in
        the SGP name table)."""
        return '\\'.join(self.geoms[j]['name'] for j in reversed(self.ancestors(i)))

    def room_of(self, i, room_cls=0x100021):
        for j in self.ancestors(i):
            if self.geoms[j]['cls'] == room_cls:
                return j
        return None

    def rooms(self):
        return [g for g in self.geoms if g['cls'] == 0x100021]


def sibling(path, ext):
    stem = os.path.splitext(path)[0]
    for e in (ext, ext.lower()):
        if os.path.exists(stem + '.' + e):
            return stem + '.' + e
    return None


def load_scene(gms_path, buf_path=None):
    body = load_gms(gms_path)
    buf_path = buf_path or sibling(gms_path, 'BUF')
    buf = open(buf_path, 'rb').read() if buf_path else None
    return Scene(body, buf)


# ---------------------------------------------------------------- OCT check
def placement_check(scene, oct_path, prm_path, verbose=False):
    """Resolve every OCT bound-tree id to a geom and compare slot-0 boxes with the
    geom's collision mesh in world space.  Needs oct.py next to this file."""
    here = os.path.dirname(os.path.abspath(__file__))
    if here not in sys.path:
        sys.path.insert(0, here)
    import oct as O  # noqa: E402  (sibling decoder)
    oc = O.parse_oct(open(oct_path, 'rb').read())
    prm = O.Prm(open(prm_path, 'rb').read())
    rooms = scene.rooms()
    nr = len(rooms)
    res = dict(ids=0, resolved=0, in_room=0, slot_cls={}, pairs=0, exact=0,
               exact_room_child=0, room_child=0, contained=0, no_tree=0,
               any_box=0, candidates=0)
    subs = oc['substrips']
    prims = oc['prims']
    cache = {}

    def local_box(rec):
        if rec in cache:
            return cache[rec]
        pts = []
        for s in sorted(set(o[0] // 8 for o in prims[rec]['objs'])):
            for t in prm.substrip_tris(*subs[s])[0]:
                pts.extend(t)
        b = None
        if pts:
            b = ([min(q[a] for q in pts) for a in range(3)],
                 [max(q[a] for q in pts) for a in range(3)])
        cache[rec] = b
        return b

    def world_box(g, lb):
        mn, mx = lb
        R, p = g['wR'], g['wp']
        hw = [sum(abs(R[i][j]) * (mx[j] - mn[j]) / 2 for j in range(3)) for i in range(3)]
        c = [(mn[j] + mx[j]) / 2 for j in range(3)]
        wc = [a + b for a, b in zip(_mv(R, c), p)]
        return [wc[i] - hw[i] for i in range(3)], [wc[i] + hw[i] for i in range(3)]

    allboxes = []
    for gi, grp in enumerate(oc['groups']):
        room = rooms[nr - 1 - gi] if gi < nr else None
        for k, t in enumerate(grp):
            if not t:
                continue
            for ob in t['objs']:
                res['ids'] += 1
                g = scene.by_static_ref.get(ob[0])
                if g is None:
                    continue
                res['resolved'] += 1
                key = '%d:0x%x' % (k, g['cls'])
                res['slot_cls'][key] = res['slot_cls'].get(key, 0) + 1
                if room is None or room['index'] in scene.ancestors(g['index']):
                    res['in_room'] += 1
                if k != 0:
                    continue
                bmn, bmx = O.obj_box(ob, t['scale'], t['origin'])
                tol = 1.5 / t['scale'] + 0.5
                allboxes.append((bmn, bmx, tol))
                rc = room is not None and g['parent'] == room['index']
                rec = prm.coll_record(g['prm']) if prm.entry_ok(g['prm']) else None
                lb = local_box(rec) if rec in prims else None
                if lb is None:
                    res['no_tree'] += 1
                    continue
                res['pairs'] += 1
                res['room_child'] += rc
                mn, mx = world_box(g, lb)
                if all(abs(bmn[a] - mn[a]) <= tol and abs(bmx[a] - mx[a]) <= tol
                       for a in range(3)):
                    res['exact'] += 1
                    res['exact_room_child'] += rc
                elif all(bmn[a] - tol <= mn[a] and mx[a] <= bmx[a] + tol for a in range(3)):
                    res['contained'] += 1
                elif verbose:
                    print('  mismatch geom %d %s' % (g['index'], g['name']))
    # oct.py-style count: every geom with a collision tree vs any slot-0 box
    grid = {}
    for b in allboxes:
        grid.setdefault(int(b[0][0] // 64), []).append(b)
    for g in scene.geoms:
        rec = prm.coll_record(g['prm']) if prm.entry_ok(g['prm']) else None
        if rec not in prims:
            continue
        lb = local_box(rec)
        if lb is None:
            continue
        res['candidates'] += 1
        mn, mx = world_box(g, lb)
        kx = int(mn[0] // 64)
        hit = False
        for kk in (kx - 1, kx, kx + 1):
            for bmn, bmx, tol in grid.get(kk, ()):
                if all(abs(bmn[a] - mn[a]) <= tol and abs(bmx[a] - mx[a]) <= tol
                       for a in range(3)):
                    hit = True
                    break
            if hit:
                break
        res['any_box'] += hit
    return res


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
        if a in ('--buf', '--oct', '--prm', '--find'):
            opts[a] = args[i + 1]
            i += 2
        elif a in ('--tree', '-v'):
            opts[a] = True
            i += 1
        else:
            pos.append(a)
            i += 1
    path = pos[0]
    sc = load_scene(path, opts.get('--buf'))
    gs = sc.geoms
    print('%s: %d instance-table entries -> %d geoms (every entry creates one)'
          % (path, len(gs), len(gs)))
    print('  distinct records %d, top-level geoms %d, max depth %d'
          % (len(set(g['rec'] for g in gs)), sum(1 for g in gs if g['parent'] == ROOT),
             max(g['depth'] for g in gs) if gs else 0))
    print('  static slots: root + %d geoms = 0x%x bytes; counts records used %d of %d'
          % (len(gs), sc.static_size, sc.counts_used, sc.counts_total))
    rooms = sc.rooms()
    print('  ZROOM (0x100021): %d' % len(rooms))
    for g in rooms:
        print('    geom %5d  static_ref 0x%08x (slot %4d)  %s'
              % (g['index'], g['static_ref'], g['static_index'], g['name']))
    if '--tree' in opts:
        for g in gs:
            print('%s%d %s cls=0x%x slot=%d pos=(%.1f,%.1f,%.1f)'
                  % ('  ' * g['depth'], g['index'], g['name'], g['cls'],
                     g['static_index'], *g['wp']))
    if '--find' in opts:
        for g in gs:
            if opts['--find'].lower() in g['name'].lower():
                print('  %d %s cls=0x%x parent=%d world pos (%.1f, %.1f, %.1f)'
                      % (g['index'], sc.path(g['index']), g['cls'], g['parent'], *g['wp']))
    op = opts.get('--oct') or sibling(path, 'OCT')
    pp = opts.get('--prm') or sibling(path, 'PRM')
    if op and pp:
        r = placement_check(sc, op, pp, '-v' in opts)
        print('OCT check (%s):' % os.path.basename(op))
        print('  bound-tree ids %d, resolved to a geom %d, inside the bundle\'s room %d'
              % (r['ids'], r['resolved'], r['in_room']))
        print('  slot:class histogram %s' % ', '.join(
            '%s=%d' % kv for kv in sorted(r['slot_cls'].items())))
        print('  slot-0 ids with a collision tree %d (no tree %d): world box exact %d '
              '(%.1f%%), contained-only %d, other %d'
              % (r['pairs'], r['no_tree'], r['exact'],
                 100.0 * r['exact'] / max(1, r['pairs']), r['contained'],
                 r['pairs'] - r['exact'] - r['contained']))
        print('  of which direct room children %d, exact %d'
              % (r['room_child'], r['exact_room_child']))
        print('  geoms with a collision tree %d; world box equal to some slot-0 box %d '
              '(oct.py-style count)' % (r['candidates'], r['any_box']))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
