#!/usr/bin/env python3
"""Freedom Fighters (Glacier 1, PC) .SGP decoder -- "Sound Graph Data" (ZSoundGraph).

usage: python3 -I sgp.py FILE.SGP [--gms FILE.GMS] [--oct FILE.OCT] [-v] [--json out.json]

  Prints a summary and runs structural checks.  With the sibling GMS (+BUF) the
  gate/room references are resolved through gms_world.py; with the sibling OCT
  the portal quads are compared with the OCT gate (slot 2) boxes (needs oct.py).
  -v           list exits, exit pairs and per-room connection lists.
  --json PATH  write the decoded graph (rooms, exits with quads, pairs, connections).

Layout (little-endian).  Loader ZSoundGraph::Initialize (PC 0x53c280); the file buffer is handed over
by ZEngineDataBase::LoadSoundGraph -> ZDllSound::InstallSoundGraph
-> ZSoundGraph::InstallLoadedGraph (stores ptr,size).

  +0x00 u32 nExits        SExit records          -> ZSoundGraph+0x1248 / +0x1258
  +0x04 u32 nPairs        SExitPair records      -> +0x1250 / +0x125c
  +0x08 u32 nRooms        room connection index  -> +0x124c / +0x1260
  +0x0c u32 nConns        connection words       -> +0x1254 / +0x1264
  SExit[nExits]     0xa4 bytes: portal between two rooms (one ZGATE geom per side)
     +0x00 u32 gateRef[2]   static geom refs of the two ZGATE geoms
     +0x08 f32 open         transmission factor, 1.0 = open, 0.0 = closed (runtime)
     +0x0c u32[2]           not read by any decoded function (editor leftovers)
     +0x14 f32 quad0[4][3]  portal polygon of gate 0, world space
     +0x44 f32 quad1[4][3]  portal polygon of gate 1 (normally the same 4 points)
     +0x74 f32 centre0[3], +0x80 f32 centre1[3]   world position of gate 0 / gate 1
     +0x8c f32 normal0[3], +0x98 f32 normal1[3]   area vector of quad0 / quad1
  SExitPair[nPairs] 12 bytes: u32 exit0, u32 exit1, f32 distance (often = centre distance)
  RoomIdx[nRooms]   8 bytes: u32 count, u32 first (into conns) -- room r's connections
                    to rooms s > r, sorted by s
  Conn[nConns]      u32: bits31-30 kind, bits29-16 other room s, bits15-0 payload
                    kind 0: direct, payload = exit index
                    kind 1: through two exits, payload = SExitPair index
                    kind 2: through room `payload` (resolve (r,payload),(payload,s))
  Name table to EOF: {char name[] NUL, u32 index}.  ZROOM names (full geom path,
                    backslash-joined) -> sound room index (stored at ZROOM+0xa0);
                    ZGATE paths -> exit index (ZGATE::SetSoundGraphId).
"""
import json
import math
import os
import struct
import sys


class SgpError(Exception):
    pass


def parse_sgp(d):
    if len(d) < 16:
        raise SgpError('file shorter than the 16-byte header')
    ne, npair, nr, nc = struct.unpack_from('<4I', d, 0)
    end = 16 + ne * 0xa4 + npair * 12 + nr * 8 + nc * 4
    if end > len(d):
        raise SgpError('counts (%d,%d,%d,%d) exceed the file' % (ne, npair, nr, nc))
    p = 16
    exits = []
    for i in range(ne):
        w = struct.unpack_from('<2I', d, p)
        f = struct.unpack_from('<41f', d, p)
        exits.append(dict(gates=list(w), open=f[2],
                          unk=list(struct.unpack_from('<2I', d, p + 0xc)),
                          quad=[[list(f[5 + 3 * k:8 + 3 * k]) for k in range(4)],
                                [list(f[17 + 3 * k:20 + 3 * k]) for k in range(4)]],
                          centre=[list(f[29:32]), list(f[32:35])],
                          normal=[list(f[35:38]), list(f[38:41])]))
        p += 0xa4
    pairs = []
    for i in range(npair):
        a, b = struct.unpack_from('<2I', d, p)
        dist = struct.unpack_from('<f', d, p + 8)[0]
        pairs.append((a, b, dist))
        p += 12
    rooms = [struct.unpack_from('<2I', d, p + 8 * i) for i in range(nr)]
    p += 8 * nr
    conns = list(struct.unpack_from('<%dI' % nc, d, p)) if nc else []
    p += 4 * nc
    names = []
    while p < len(d):
        e = d.find(b'\0', p)
        if e < 0 or e + 5 > len(d):
            raise SgpError('name table entry at 0x%x runs past EOF' % p)
        names.append((d[p:e].decode('latin-1'), struct.unpack_from('<I', d, e + 1)[0]))
        p = e + 5
    return dict(exits=exits, pairs=pairs, rooms=rooms, conns=conns, names=names,
                names_off=end)


def conn_fields(w):
    return w >> 30, (w >> 16) & 0x3FFF, w & 0xFFFF


def structural_checks(g):
    ex, pr, rm, cn = g['exits'], g['pairs'], g['rooms'], g['conns']
    nr = len(rm)
    out = {}
    # room index covers conns exactly, contiguous
    pos = 0
    contiguous = True
    for cnt, first in rm:
        if cnt and first != pos:
            contiguous = False
        pos = first + cnt if cnt else pos
    out['roomidx_contiguous'] = contiguous and sum(c for c, f in rm) == len(cn)
    bad = sorted_ok = 0
    kinds = [0, 0, 0, 0]
    for r, (cnt, first) in enumerate(rm):
        prev = -1
        for w in cn[first:first + cnt]:
            k, s, pay = conn_fields(w)
            kinds[k] += 1
            if s <= r or s >= nr:
                bad += 1
            if s < prev:
                sorted_ok += 1
            prev = s
            if (k == 0 and pay >= len(ex)) or (k == 1 and pay >= len(pr)) or \
                    (k == 2 and pay >= nr) or k == 3:
                bad += 1
    out['conn_bad'] = bad
    out['conn_unsorted'] = sorted_ok
    out['kinds'] = kinds
    out['pair_bad'] = sum(1 for a, b, _ in pr if a >= len(ex) or b >= len(ex))
    # pair distance == distance between exit centres (closest side combination)
    dok = 0
    for a, b, dist in pr:
        best = min(math.dist(ca, cb) for ca in ex[a]['centre'] for cb in ex[b]['centre'])
        dok += abs(best - dist) <= max(0.5, 1e-3 * dist)
    out['pair_dist_ok'] = dok
    # exit geometry: normal[k] == area vector of quad[k] (cross products / 2)
    def sub(u, v):
        return [u[i] - v[i] for i in range(3)]

    def cross(u, v):
        return [u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0]]
    aok = opp = 0
    for e in ex:
        good = True
        for k in range(2):
            q = e['quad'][k]
            c1 = cross(sub(q[1], q[0]), sub(q[2], q[0]))
            c2 = cross(sub(q[2], q[0]), sub(q[3], q[0]))
            av = [(c1[i] + c2[i]) / 2 for i in range(3)]
            n = e['normal'][k]
            good &= all(abs(av[i] - n[i]) <= 1 + 0.01 * math.hypot(*av) for i in range(3))
        aok += good
        opp += sum(e['normal'][0][i] * e['normal'][1][i] for i in range(3)) < 0
    out['exit_area_ok'], out['exit_opposite'] = aok, opp
    return out


def path_checks(g):
    """Do the connection kinds describe real paths?  Uses the rooms of each exit
    from the name table (gate path -> exit index)."""
    room_idx = {}
    gate_rooms = {}
    for nm, idx in g['names']:
        room_idx.setdefault(nm, idx)
    rooms_by_path = {}
    nrooms = len(g['rooms'])
    rnames = [(n, i) for n, i in g['names'][:nrooms]]
    for nm, idx in g['names'][nrooms:]:
        # a gate name is "<room path>\\...\\<gate name>": longest room-name prefix
        best = None
        for rn, ri in rnames:
            if nm.startswith(rn + '\\') and (best is None or len(rn) > len(best[0])):
                best = (rn, ri)
        if best:
            rooms_by_path.setdefault(nm, (best[1], idx))
    for nm, (r, e) in rooms_by_path.items():
        gate_rooms.setdefault(e, set()).add(r)
    ex_rooms = {e: rs for e, rs in gate_rooms.items()}
    rm, cn, pr = g['rooms'], g['conns'], g['pairs']
    has = set()
    for r, (cnt, first) in enumerate(rm):
        for w in cn[first:first + cnt]:
            has.add((r, conn_fields(w)[1]))
    ok = [0, 0, 0]
    tot = [0, 0, 0]
    for r, (cnt, first) in enumerate(rm):
        for w in cn[first:first + cnt]:
            k, s, pay = conn_fields(w)
            if k > 2:
                continue
            tot[k] += 1
            if k == 0:
                ok[0] += ex_rooms.get(pay) == {r, s}
            elif k == 1:
                a, b, _ = pr[pay]
                ra, rb = ex_rooms.get(a, set()), ex_rooms.get(b, set())
                fine = False
                for x, y in ((ra, rb), (rb, ra)):
                    if r in x and s in y and (x - {r}) & (y - {s}):
                        fine = True
                ok[1] += fine
            else:
                m = pay
                ok[2] += m not in (r, s) and \
                    (min(r, m), max(r, m)) in has and (min(m, s), max(m, s)) in has
    return dict(exit_rooms=ex_rooms, path_ok=ok, path_tot=tot,
                gates_named=sum(len(v) for v in gate_rooms.values()))


def sibling(path, ext):
    stem = os.path.splitext(path)[0]
    for e in (ext, ext.lower()):
        if os.path.exists(stem + '.' + e):
            return stem + '.' + e
    return None


def scene_checks(g, scene, oct_path):
    names = dict(g['names'])
    rooms = scene.rooms()
    by_path = {}
    for gg in scene.geoms:
        if gg['cls'] in (0x100021, 0x200015):
            by_path.setdefault(scene.path(gg['index']), []).append(gg)
    nroom = sum(1 for r in rooms if names.get(scene.path(r['index'])) is not None)
    idx_ok = sorted(names[scene.path(r['index'])] for r in rooms
                    if scene.path(r['index']) in names) == list(range(len(g['rooms'])))
    print('  ZROOMs whose full path is in the name table: %d/%d; their indices are exactly '
          '0..nRooms-1: %s' % (nroom, len(rooms), 'yes' if idx_ok else 'NO'))
    gates = [gg for gg in scene.geoms if gg['cls'] == 0x200015]
    gnamed = sum(1 for gg in gates if scene.path(gg['index']) in names)
    print('  ZGATE geoms whose full path is in the name table: %d/%d' % (gnamed, len(gates)))
    ref_ok = room_ok = 0
    for i, e in enumerate(g['exits']):
        good = True
        for side, ref in enumerate(e['gates']):
            gg = scene.by_static_ref.get(ref)
            if not gg or gg['cls'] != 0x200015 or names.get(scene.path(gg['index'])) != i:
                good = False
        ref_ok += good
    print('  exits whose two gateRefs are ZGATE geoms named with that exit index: %d/%d'
          % (ref_ok, len(g['exits'])))
    # sound room index of each side's room
    for i, e in enumerate(g['exits']):
        rs = []
        for ref in e['gates']:
            gg = scene.by_static_ref.get(ref)
            rm = scene.room_of(gg['index']) if gg else None
            rs.append(names.get(scene.path(rm)) if rm is not None else None)
        e['rooms'] = rs
        room_ok += None not in rs and rs[0] != rs[1]
    print('  exits joining two different named rooms: %d/%d' % (room_ok, len(g['exits'])))
    cpos = 0
    for e in g['exits']:
        cpos += all(math.dist(e['centre'][k], scene.by_static_ref[e['gates'][k]]['wp']) < 0.5
                    for k in range(2) if e['gates'][k] in scene.by_static_ref)
    print('  centre[k] == world position of gate k (gms_world transforms): %d/%d'
          % (cpos, len(g['exits'])))
    if oct_path:
        here = os.path.dirname(os.path.abspath(__file__))
        if here not in sys.path:
            sys.path.insert(0, here)
        import oct as O  # noqa: E402
        oc = O.parse_oct(open(oct_path, 'rb').read())
        boxes = {}
        lvl = [[1e30] * 3, [-1e30] * 3]
        for grp in oc['groups']:
            for k, t in enumerate(grp):
                if not t:
                    continue
                for ob in t['objs']:
                    mn, mx = O.obj_box(ob, t['scale'], t['origin'])
                    for a in range(3):
                        lvl[0][a] = min(lvl[0][a], mn[a])
                        lvl[1][a] = max(lvl[1][a], mx[a])
                    if k == 2:
                        boxes[ob[0]] = (mn, mx, 1.5 / t['scale'] + 0.5)
        inq = inl = withbox = 0
        for e in g['exits']:
            allin = True
            for k, ref in enumerate(e['gates']):
                b = boxes.get(ref)
                if b is None:
                    allin = False
                    continue
                withbox += 1
                for v in e['quad'][k]:
                    if not all(b[0][a] - b[2] <= v[a] <= b[1][a] + b[2] for a in range(3)):
                        allin = False
            inq += allin
            inl += all(lvl[0][a] <= v[a] <= lvl[1][a] for v in e['quad'][0] for a in range(3))
        print('  OCT: gateRefs with an OCT slot-2 (ZGATE) box: %d/%d; exits whose quad[k] lies in '
              'gate k\'s box: %d/%d; exits inside the level bounds: %d/%d'
              % (withbox, 2 * len(g['exits']), inq, len(g['exits']), inl, len(g['exits'])))


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
    path = pos[0]
    d = open(path, 'rb').read()
    g = parse_sgp(d)
    ex, pr, rm, cn, nm = g['exits'], g['pairs'], g['rooms'], g['conns'], g['names']
    print('%s: %d bytes; exits %d, exit pairs %d, rooms %d, connections %d; name table '
          '%d entries at 0x%x..EOF' % (os.path.basename(path), len(d), len(ex), len(pr),
                                     len(rm), len(cn), len(nm), g['names_off']))
    print('  parsed to EOF: yes')
    if not (ex or pr or rm or cn or nm):
        print('  empty graph (no rooms)')
    s = structural_checks(g)
    print('  room index contiguous and covers all connections: %s; bad connection words %d; '
          'unsorted %d; kinds direct/pair/via-room = %d/%d/%d'
          % ('yes' if s['roomidx_contiguous'] else 'NO', s['conn_bad'], s['conn_unsorted'],
             *s['kinds'][:3]))
    print('  exit pairs with bad exit index %d; pair distance == distance of exit centres: %d/%d'
          % (s['pair_bad'], s['pair_dist_ok'], len(pr)))
    print('  exits: normal[k] == area vector of quad[k] (both sides) %d/%d; the two normals '
          'point opposite ways %d/%d' % (s['exit_area_ok'], len(ex), s['exit_opposite'], len(ex)))
    opn = {}
    for e in ex:
        opn[e['open']] = opn.get(e['open'], 0) + 1
    print('  exit open factors: %s' % ', '.join('%g x%d' % kv for kv in sorted(opn.items())))
    pc = path_checks(g)
    print('  name table: %d room names, gate names %d (two per exit); connection paths '
          'consistent with the exits\' rooms: direct %d/%d, pair %d/%d, via-room %d/%d'
          % (len(rm), pc['gates_named'], pc['path_ok'][0], pc['path_tot'][0],
             pc['path_ok'][1], pc['path_tot'][1], pc['path_ok'][2], pc['path_tot'][2]))
    npair_rooms = sum(1 for r in range(len(rm)) for s2 in range(r + 1, len(rm))
                      if any(conn_fields(w)[1] == s2 for w in cn[rm[r][1]:rm[r][1] + rm[r][0]]))
    print('  room pairs with at least one connection: %d of %d'
          % (npair_rooms, len(rm) * (len(rm) - 1) // 2))
    scene = None
    gp = opts.get('--gms') or sibling(path, 'GMS')
    if gp and (ex or nm):
        here = os.path.dirname(os.path.abspath(__file__))
        if here not in sys.path:
            sys.path.insert(0, here)
        import gms_world  # noqa: E402
        scene = gms_world.load_scene(gp)
        scene_checks(g, scene, opts.get('--oct') or sibling(path, 'OCT'))
    if '-v' in opts:
        rname = {idx: n.rsplit('\\', 1)[-1] for n, idx in nm[:len(rm)]}
        for i, e in enumerate(ex):
            print('    exit %3d gates 0x%08x/0x%08x open %g centre (%.0f,%.0f,%.0f) area %.0f rooms %s'
                  % (i, e['gates'][0], e['gates'][1], e['open'], *e['centre'][0],
                     math.hypot(*e['normal'][0]), e.get('rooms')))
        for i, (a, b, dist) in enumerate(pr):
            print('    pair %3d exits %d,%d dist %.1f' % (i, a, b, dist))
        for r, (cnt, first) in enumerate(rm):
            lst = ['%s%d:%d' % ('DPV'[k], s2, pay) for k, s2, pay in
                   (conn_fields(w) for w in cn[first:first + cnt])]
            print('    room %2d %-40s %s' % (r, rname.get(r, '?'), ' '.join(lst[:40]) +
                                             (' ...' if len(lst) > 40 else '')))
    if '--json' in opts:
        rnames = {idx: n for n, idx in nm[:len(rm)]}
        js = dict(rooms=[dict(index=r, name=rnames.get(r)) for r in range(len(rm))],
                  exits=ex, pairs=pr,
                  connections=[[dict(kind=k, room=s2, payload=pay) for k, s2, pay in
                                (conn_fields(w) for w in cn[first:first + cnt])]
                               for cnt, first in rm],
                  names=nm)
        with open(opts['--json'], 'w') as f:
            json.dump(js, f, indent=1)
        print('wrote %s' % opts['--json'])
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
