#!/usr/bin/env python3
"""Freedom Fighters (Glacier 1, PC) .RMC / .RMI decoder -- room collision / room inside trees.

usage: python3 -I rooms.py FILE.RMC|FILE.RMI|STEM [--gms FILE.GMS] [--oct FILE.OCT] [-v] [--json out.json]

  Given a stem (or either file) both RMC and RMI are decoded when present.  Prints
  a summary and runs structural checks.  When the sibling GMS (+BUF) is present
  the room links are resolved with gms_world.py; when the sibling OCT is present
  the boxes are compared with the OCT room bound trees (needs oct.py).
  -v           list every room record.
  --json PATH  write {rmc:[...], rmi:[...]} records (world-space boxes) for a viewer.

File layout (little-endian; see rooms-sgp-format.md for the proofs):

  The whole file is one ZOctreeCompiled blob, Init()ed in place
  (ZCollisionBase::InstallCollisionBuffer / InstallInsideBuffer):
    +0x00 u32 objOff, f32 origin[3], f32 scale, 6-byte nodes from +0x14
    +objOff 16-byte objects {u32 id, u16 min[3], u16 max[3]}  (same as OCT)
  followed by the room-box records (SRoomTreeBox, 0x54 bytes each) to EOF.
  Object id = byte offset of its record from the start of the file.

  SRoomTreeBox (writer SRoomTreeBox::SetBox ; readers
  InnerRoomFuncPoint / InnerRoomFuncBox / CalcRoomLineCallBack; PC InnerRoomFuncBox 0x4ed840):
    +0x00 u32 axisAligned   1: box is a world AABB (half extents in world axes)
                            0: oriented: local = d * M, test |local| <= half
    +0x04 f32 M[9]          orientation (ZBaseGeom matrix format, as in GMS)
    +0x28 f32 centre[3]     world
    +0x34 f32 meshPos[3]    world position of the bound geom whose mesh refines the
                            test (RMI: the InsideBound geom; 0 when none)
    +0x40 f32 half[3]       half extents
    +0x4c u32 roomRef       static geom ref of the ZROOM (0x40000000 | slot*0x70)
    +0x50 u32 meshRef       geom ref of a non-box bound mesh for an exact
                            point/box-in-mesh test; 0 = the box is exact
"""
import json
import os
import struct
import sys

REC = 0x54


class RoomsError(Exception):
    pass


def decode_tree(d):
    """ZOctreeCompiled at offset 0 of d; returns header, objects and checks."""
    n = len(d)
    if n < 0x1a:
        raise RoomsError('file too short for a tree (%d bytes)' % n)
    objoff, ox, oy, oz, sc = struct.unpack_from('<I4f', d, 0)
    if objoff < 0x1a or objoff > n or (objoff - 0x14) % 2:
        raise RoomsError('bad objOff 0x%x' % objoff)
    if not sc > 0:
        raise RoomsError('bad tree scale %r' % sc)
    nslots = (objoff - 0x14) // 6
    nodes = [struct.unpack_from('<3H', d, 0x14 + 6 * i) for i in range(nslots)]
    seen = set()
    refs = []
    depth = 0
    stack = [(0, 0)]
    while stack:
        i, lv = stack.pop()
        if i >= nslots or i in seen:
            raise RoomsError('node %d out of range or visited twice' % i)
        seen.add(i)
        depth = max(depth, lv)
        w0, child, first = nodes[i]
        refs.extend(range(first, first + ((w0 >> 3) & 0xFFF)))
        if child:
            j = child
            while True:
                if j >= nslots:
                    raise RoomsError('child %d out of range' % j)
                stack.append((j, lv + 1))
                if nodes[j][0] & 0x8000:
                    break
                j += 1
    nobj = max(refs) + 1 if refs else 0
    if objoff + 16 * nobj > n:
        raise RoomsError('objects run past EOF')
    objs = [struct.unpack_from('<I6H', d, objoff + 16 * k) for k in range(nobj)]
    return dict(objoff=objoff, origin=(ox, oy, oz), scale=sc, node_slots=nslots,
                nodes=len(seen), depth=depth, objs=objs, refs=refs)


def obj_box(o, t):
    sc, org = t['scale'], t['origin']
    return ([(o[1 + a] - 32768) / sc + org[a] for a in range(3)],
            [(o[4 + a] - 32768) / sc + org[a] for a in range(3)])


def record_aabb(r):
    """World AABB of a record (centre +- half for axis-aligned; OBB otherwise).
    For oriented records half[j] lies along M's column 2-j (verified against the
    OCT boxes of the same geoms, see the spec)."""
    c, h = r['centre'], r['half']
    if r['axis_aligned']:
        hw = list(h)
    else:
        M = r['M']
        hw = [sum(abs(M[3 * (2 - j) + i]) * h[j] for j in range(3)) for i in range(3)]
    return [c[i] - hw[i] for i in range(3)], [c[i] + hw[i] for i in range(3)]


def parse_rooms(d):
    t = decode_tree(d)
    start = t['objoff'] + 16 * len(t['objs'])
    rem = len(d) - start
    if rem % REC:
        raise RoomsError('record area %d bytes is not a multiple of 0x54' % rem)
    recs = []
    for k in range(rem // REC):
        p = start + REC * k
        v = struct.unpack_from('<I9f3f3f3fII', d, p)
        recs.append(dict(off=p, axis_aligned=v[0], M=v[1:10], centre=v[10:13],
                         mesh_pos=v[13:16], half=v[16:19], room_ref=v[19],
                         mesh_ref=v[20]))
    byoff = {r['off']: r for r in recs}
    ids = [o[0] for o in t['objs']]
    bad = [i for i in ids if i not in byoff]
    if bad:
        raise RoomsError('%d object ids do not point at a record (e.g. 0x%x)' % (len(bad), bad[0]))
    # quantised object box vs record box
    qmis = 0
    for o in t['objs']:
        r = byoff[o[0]]
        mn, mx = record_aabb(r)
        bmn, bmx = obj_box(o, t)
        tol = 1.5 / t['scale'] + 0.01 * max(r['half']) + 1.0
        if not all(abs(bmn[a] - mn[a]) <= tol and abs(bmx[a] - mx[a]) <= tol
                   for a in range(3)):
            qmis += 1
    return dict(tree=t, start=start, records=recs, ids=ids,
                unreferenced=len(byoff) - len(set(ids)), dup_ids=len(ids) - len(set(ids)),
                box_mismatch=qmis)


def sibling(path, ext):
    stem = os.path.splitext(path)[0]
    for e in (ext, ext.lower()):
        if os.path.exists(stem + '.' + e):
            return stem + '.' + e
    return None


def summary(name, res, scene, verbose):
    t = res['tree']
    recs = res['records']
    print('%s: tree objOff 0x%x scale %.6g origin (%.1f, %.1f, %.1f); nodes %d reached '
          '(%d slots before objOff, rest is 16-byte padding), depth %d'
          % (name, t['objoff'], t['scale'], *t['origin'], t['nodes'], t['node_slots'],
             t['depth']))
    print('  objects %d (refs %d, duplicates %d) -> room records %d at 0x%x..EOF; '
          'unreferenced records %d' % (len(t['objs']), len(t['refs']), res['dup_ids'],
                                       len(recs), res['start'], res['unreferenced']))
    print('  object box == record box (quantisation tolerance): %d/%d'
          % (len(t['objs']) - res['box_mismatch'], len(t['objs'])))
    na = sum(1 for r in recs if r['axis_aligned'])
    print('  axisAligned=1: %d, oriented: %d, meshRef!=0: %d, meshPos!=0: %d'
          % (na, len(recs) - na, sum(1 for r in recs if r['mesh_ref']),
             sum(1 for r in recs if any(r['mesh_pos']))))
    rooms = sorted(set(r['room_ref'] for r in recs))
    print('  distinct room refs: %d' % len(rooms))
    if scene is not None:
        zr = scene.rooms()
        link = 0
        for ref in rooms:
            g = scene.by_static_ref.get(ref)
            link += g is not None and g['cls'] in (0x100021, 0x100001)
        nz = sum(1 for ref in rooms if scene.by_static_ref.get(ref, {}).get('cls') == 0x100021)
        print('  room refs resolved to ZROOM geoms: %d/%d (scene has %d ZROOMs; root group '
              'refs %d)' % (nz, len(rooms), len(zr),
                            sum(1 for ref in rooms if ref == 0x40000000)))
        missing = [g['name'] for g in zr if g['static_ref'] not in rooms]
        if missing:
            print('  ZROOMs without a record: %s' % ', '.join(missing))
    if verbose:
        for r in recs:
            nm = ''
            if scene is not None:
                g = scene.by_static_ref.get(r['room_ref'])
                nm = g['name'] if g else '?'
            mn, mx = record_aabb(r)
            print('    0x%04x %s c=(%.1f,%.1f,%.1f) half=(%.1f,%.1f,%.1f) aabb=(%.0f,%.0f,%.0f)..'
                  '(%.0f,%.0f,%.0f) meshPos=(%.1f,%.1f,%.1f) room=0x%08x %s'
                  % (r['off'], 'AA ' if r['axis_aligned'] else 'OBB', *r['centre'], *r['half'],
                     *mn, *mx, *r['mesh_pos'], r['room_ref'], nm))


def oct_checks(res_rmc, res_rmi, scene, oct_path):
    here = os.path.dirname(os.path.abspath(__file__))
    if here not in sys.path:
        sys.path.insert(0, here)
    import oct as O  # noqa: E402
    oc = O.parse_oct(open(oct_path, 'rb').read())
    rooms = scene.rooms()
    nr = len(rooms)
    per = {}          # room static_ref -> list of (slot k, mn, mx, id)
    lvl = [[1e30] * 3, [-1e30] * 3]
    for gi, grp in enumerate(oc['groups']):
        ref = rooms[nr - 1 - gi]['static_ref'] if gi < nr else 0x40000000
        for k, t in enumerate(grp):
            if not t:
                continue
            for ob in t['objs']:
                mn, mx = O.obj_box(ob, t['scale'], t['origin'])
                per.setdefault(ref, []).append((k, mn, mx, ob[0]))
                for a in range(3):
                    lvl[0][a] = min(lvl[0][a], mn[a])
                    lvl[1][a] = max(lvl[1][a], mx[a])
    print('OCT cross-check (%s): level bounds from all bound-tree boxes '
          '(%.0f,%.0f,%.0f)..(%.0f,%.0f,%.0f)' % (os.path.basename(oct_path), *lvl[0], *lvl[1]))
    for name, res in (('RMC', res_rmc), ('RMI', res_rmi)):
        if res is None:
            continue
        recs = res['records']
        inside = 0
        for r in recs:
            mn, mx = record_aabb(r)
            inside += all(lvl[0][a] - 1 <= mn[a] and mx[a] <= lvl[1][a] + 1 for a in range(3))
        print('  %s: %d/%d record boxes inside the level bounds' % (name, inside, len(recs)))
        if name == 'RMC':
            first = {}
            for r in recs:
                first.setdefault(r['room_ref'], r)
            cont = eq = 0
            for ref, r in first.items():
                U = [b for b in per.get(ref, []) if b[0] in (0, 2)]
                if not U:
                    continue
                umn = [min(b[1][a] for b in U) for a in range(3)]
                umx = [max(b[2][a] for b in U) for a in range(3)]
                mn, mx = record_aabb(r)
                cont += all(mn[a] - 2 <= umn[a] and umx[a] <= mx[a] + 2 for a in range(3))
                eq += all(abs(mn[a] - umn[a]) < 2 and abs(mx[a] - umx[a]) < 2 for a in range(3))
            print('  RMC first record per room (room AABB) contains the union of the room\'s '
                  'OCT slot-0+slot-2 boxes: %d/%d (equal on all axes: %d)'
                  % (cont, len(first), eq))
            obj = [r for r in recs if first[r['room_ref']] is not r]
            hit = 0
            group_child = 0
            for r in obj:
                mn, mx = record_aabb(r)
                tol = [2 + 0.01 * (mx[a] - mn[a]) for a in range(3)]
                m = [b for b in per.get(r['room_ref'], []) if b[0] == 0 and
                     all(abs(b[1][a] - mn[a]) <= tol[a] and abs(b[2][a] - mx[a]) <= tol[a]
                         for a in range(3))]
                if m:
                    hit += 1
                    g = scene.by_static_ref.get(m[0][3])
                    if g and scene.geoms[g['parent']]['cls'] != 0x100021:
                        group_child += 1
            print('  RMC other records (per-object boxes): %d; equal to a slot-0 geom box of '
                  'the same room: %d (geom inside a ZGROUP, not directly in the room: %d)'
                  % (len(obj), hit, group_child))
        else:
            ok = nb = same = 0
            rmc_first = {}
            if res_rmc:
                for r in res_rmc['records']:
                    rmc_first.setdefault(r['room_ref'], r)
            for r in recs:
                room = scene.by_static_ref.get(r['room_ref'])
                if any(r['mesh_pos']):
                    nb += 1
                    for g in scene.geoms:
                        if g['cls'] == 0x20001c and room and \
                                room['index'] in scene.ancestors(g['index']) and \
                                all(abs(g['wp'][a] - r['mesh_pos'][a]) < 0.5 for a in range(3)):
                            ok += 1
                            break
                else:
                    f = rmc_first.get(r['room_ref'])
                    if f and all(abs(f['centre'][a] - r['centre'][a]) < 0.01 and
                                 abs(f['half'][a] - r['half'][a]) < 0.01 for a in range(3)):
                        same += 1
            nib = {}
            for g in scene.geoms:
                if g['cls'] == 0x20001c:
                    rm = scene.room_of(g['index'])
                    if rm is not None:
                        nib[scene.geoms[rm]['static_ref']] = nib.get(scene.geoms[rm]['static_ref'], 0) + 1
            print('  RMI records with meshPos set: %d; meshPos == world position of an '
                  'InsideBound geom (class 0x20001c) in that room: %d' % (nb, ok))
            mr = [r for r in recs if r['mesh_ref']]
            mok = 0
            for r in mr:
                g = scene.by_static_ref.get(r['mesh_ref'])
                mok += bool(g and g['cls'] == 0x20001c and
                            all(abs(g['wp'][a] - r['mesh_pos'][a]) < 0.5 for a in range(3)))
            print('  RMI records with meshRef set: %d; meshRef is that InsideBound geom '
                  '(class 0x20001c, world pos == meshPos): %d' % (len(mr), mok))
            print('  RMI records with meshPos 0: %d; identical to the room\'s RMC room AABB: %d'
                  % (len(recs) - nb, same))
            withib = set(nib)
            recrooms_b = set(r['room_ref'] for r in recs if any(r['mesh_pos']))
            print('  rooms with InsideBound geoms %d (geoms %d) == rooms with meshPos records %d: %s'
                  % (len(withib), sum(nib.values()), len(recrooms_b),
                     'yes' if withib == recrooms_b else 'NO'))


def to_json(res, scene):
    out = []
    for r in res['records']:
        mn, mx = record_aabb(r)
        g = scene.by_static_ref.get(r['room_ref']) if scene else None
        out.append(dict(off=r['off'], axis_aligned=r['axis_aligned'], M=r['M'],
                        centre=r['centre'], half=r['half'], mesh_pos=r['mesh_pos'],
                        room_ref=r['room_ref'], mesh_ref=r['mesh_ref'],
                        room=(g['name'] if g else None), aabb=[mn, mx]))
    return out


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
        if a in ('--gms', '--oct', '--json'):
            opts[a] = args[i + 1]
            i += 2
        elif a == '-v':
            opts[a] = True
            i += 1
        else:
            pos.append(a)
            i += 1
    p = pos[0]
    stem = os.path.splitext(p)[0] if os.path.splitext(p)[1].upper() in ('.RMC', '.RMI') else p
    paths = {}
    for ext in ('RMC', 'RMI'):
        q = sibling(stem + '.x', ext)
        if q:
            paths[ext] = q
    if not paths:
        print('no RMC/RMI found for %s' % p)
        return 1
    scene = None
    gp = opts.get('--gms') or sibling(stem + '.x', 'GMS')
    if gp:
        here = os.path.dirname(os.path.abspath(__file__))
        if here not in sys.path:
            sys.path.insert(0, here)
        import gms_world  # noqa: E402
        scene = gms_world.load_scene(gp)
    res = {}
    for ext, q in paths.items():
        d = open(q, 'rb').read()
        res[ext] = parse_rooms(d)
        summary('%s (%d bytes)' % (os.path.basename(q), len(d)), res[ext], scene, '-v' in opts)
        print('  parsed to EOF: yes')
    op = opts.get('--oct') or sibling(stem + '.x', 'OCT')
    if scene is not None and op:
        oct_checks(res.get('RMC'), res.get('RMI'), scene, op)
    if '--json' in opts:
        with open(opts['--json'], 'w') as f:
            json.dump({k.lower(): to_json(v, scene) for k, v in res.items()}, f, indent=1)
        print('wrote %s' % opts['--json'])
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
