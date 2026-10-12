#!/usr/bin/env python3
"""Script instances, lists and the C01A caretaker wiring from a GMS scene.

usage: python3 -I gms_scripts.py FILE.GMS [--json OUT.json] [--summary]

Writes a JSON manifest for the browser script VM (script-vm/):

  refs      geom ref -> scene path, for every geom named below
  scripts   one entry per geom with a script: {ref, geom, sdl, script, vars:[{name,type,value}]}
  lists     List geoms (class 0x800001a) used by script variables: ref -> [member refs]
  events    {ref, geom, events:[names]} for geoms whose events talk to the caretaker
  caretaker {ref, geom, event, refs:[16 refs from its event data block]}
  checkInside  CheckInside events that send a message to the caretaker: {ref, geom, target, msgId, msg}
  msgNames  registered message names of the scene (ZMsg id -> name), only the ids used above

Geom refs are the scene's dynamic refs as stored in data blocks (`0x80000000 | (index+1)`,
index = creation order in the GMS instance table); the manifest uses `index+1` as the ref.

Evidence (records are kept with the unpublished port):
* GMS record +0x28 = offset of the script data block: item 0 = .sdl path (type 4),
  item 1 = declaration string "TYPE name;..." (type 4), then one item per declared
  variable (type 8 = geom ref, 3 = int, 2 = float), then 6, 0xff.  Fitted on all C01A
  actor geoms (Jones, Bagzton, PunchMe ...): the declaration equals the .ppo prefix.
* Record +0x14 = event list: u32 n, n x {u32 class-name offset, f32}; the events' data
  follows the geom's own block inside the +0x20 data block, one block (ended by type 6)
  per event.
* Data-block refs: `0x80000000 | (index+1)` (fitted: the caretaker's 16 refs resolve to
  MrJones\\Ground, Bagzton\\Ground, Punch\\PunchMe\\Ground, the 01_Punch ... 11_Sewer act
  groups, and BlowUpStairs; script refs resolve to the geoms their names describe).
* Message ids (type 10 items) index the scene's registered message-name table at the
  start of the GMS body (fitted: base so that 4602 = msgCloseToStairs makes 4603 =
  msgDownStairs, which is exactly what the DownStairs trigger sends).
"""
import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import gms_world  # noqa: E402
import pathfind   # noqa: E402

LIST_CLASS = 0x800001a


def u32(b, o):
    return struct.unpack_from('<I', b, o)[0]


def event_names(b, rec):
    ev = u32(b, rec + 0x14)
    out = []
    if ev:
        for i in range(u32(b, ev)):
            no, _f = struct.unpack_from('<If', b, ev + 4 + 8 * i)
            e = b.find(b'\0', no)
            out.append(b[no:e].decode('latin-1'))
    return out


def ref_index(v):
    v &= 0xffffffff
    if not (v & 0x80000000) or v == 0xffffffff:
        return None
    return (v & 0xffffff) - 1


def msg_table(b):
    """Registered ZMsg names stored at the start of the GMS body (u32 header words, then
    NUL-terminated names padded to 4).  Returns the list in order."""
    m = re.search(rb'ActionHide\x00', b[:0x4000])
    if not m:
        return []
    names = []
    for mm in re.finditer(rb'([\x20-\x7e]{2,})\x00', b[m.start():m.start() + 0x2000]):
        s = mm.group(1).decode('latin-1')
        names.append(s)
        if s == 'msgDownStairs':
            break
    return names


def build(gms_path):
    sc = gms_world.load_scene(gms_path)
    b = sc.body
    n = len(sc.geoms)
    names = msg_table(b)
    base = None
    if 'msgCloseToStairs' in names:
        base = 4602 - names.index('msgCloseToStairs')

    def msg_name(i):
        if base is None or not (0 <= i - base < len(names)):
            return None
        return names[i - base]

    used = set()

    def R(v):
        k = ref_index(v)
        if k is None or not (0 <= k < n):
            return 0
        used.add(k)
        return k + 1

    out = {'gms': os.path.basename(gms_path), 'scripts': [], 'lists': {}, 'checkInside': [], 'caretaker': None}
    list_refs = set()
    for g in sc.geoms:
        rec = g['rec']
        so = u32(b, rec + 0x28)
        if so:
            d = pathfind.parse_dblk(b, so)
            items = d['items']
            if len(items) >= 2 and items[0]['type'] in (4, 5) and items[1]['type'] in (4, 5):
                sdl = items[0]['value']
                decl = [x.strip().split() for x in items[1]['value'].split(';') if x.strip()]
                vals = [it for it in items[2:] if it['type'] not in (6, 0xff)]
                vars_ = []
                for (typ, name), it in zip(decl, vals):
                    v = it.get('value')
                    if it['type'] == 8:
                        v = R(v)
                        if v and sc.geoms[v - 1]['cls'] == LIST_CLASS:
                            list_refs.add(v)
                    vars_.append({'name': name.split('=')[0], 'type': typ, 'value': v})
                rel = sdl.replace('\\', '/')
                rel = re.sub(r'^scripts/', '', rel, flags=re.I)
                rel = re.sub(r'\.sdl$', '.ppo', rel, flags=re.I)
                used.add(g['index'])
                out['scripts'].append({'ref': g['index'] + 1, 'geom': sc.path(g['index']), 'sdl': sdl,
                                       'script': rel, 'vars': vars_})
        evs = event_names(b, rec)
        if 'ZGROUP_ZFFCareTaker_C01A' in evs:
            d = pathfind.parse_dblk(b, u32(b, rec + 0x20))
            blocks = [[]]
            for it in d['items']:
                if it['type'] == 6:
                    blocks.append([])
                elif it['type'] != 0xff:
                    blocks[-1].append(it)
            # block 0 = the group's own data; the caretaker event's block follows
            ev_block = [it for it in blocks[1] if it['type'] == 8]
            used.add(g['index'])
            out['caretaker'] = {'ref': g['index'] + 1, 'geom': sc.path(g['index']),
                                'event': 'ZGROUP_ZFFCareTaker_C01A',
                                'refs': [R(it['value']) for it in ev_block]}
    for lr in sorted(list_refs):
        g = sc.geoms[lr - 1]
        d = pathfind.parse_dblk(b, u32(b, g['rec'] + 0x20))
        members = []
        for it in d['items']:
            if it['type'] == 9:
                members = [R(x) for x in it['refs']]
                break
        out['lists'][str(lr)] = members
    care = out['caretaker']['ref'] if out['caretaker'] else None
    if care:
        tgt = 0x80000000 | care
        for g in sc.geoms:
            if 'ZGEOM_CheckInside' not in event_names(b, g['rec']):
                continue
            off = u32(b, g['rec'] + 0x20)
            if not off:
                continue
            d = pathfind.parse_dblk(b, off)
            its = d['items']
            for i, it in enumerate(its):
                if it['type'] == 8 and (it['value'] & 0xffffffff) == tgt and i + 1 < len(its) and its[i + 1]['type'] == 10:
                    who = its[i - 1] if i > 0 and its[i - 1]['type'] == 8 else None
                    used.add(g['index'])
                    out['checkInside'].append({'ref': g['index'] + 1, 'geom': sc.path(g['index']),
                                               'watch': R(who['value']) if who else 0,
                                               'target': care, 'msgId': its[i + 1]['value'],
                                               'msg': msg_name(its[i + 1]['value']),
                                               'pos': [round(x, 1) for x in g['wp']]})
    out['refs'] = {str(k + 1): sc.path(k) for k in sorted(used)}
    out['positions'] = {str(k + 1): [round(x, 2) for x in sc.geoms[k]['wp']] for k in sorted(used)}
    return out


def main(argv):
    if not argv or argv[0].startswith('-'):
        print(__doc__)
        return 2
    gms = argv[0]
    out = build(gms)
    if '--json' in argv:
        p = argv[argv.index('--json') + 1]
        with open(p, 'w') as f:
            json.dump(out, f, indent=1)
        print('wrote', p)
    if '--summary' in argv or '--json' not in argv:
        print('scripts', len(out['scripts']), 'lists', len(out['lists']), 'refs', len(out['refs']))
        for s in out['scripts']:
            print('  %5d %-60s %s' % (s['ref'], s['geom'][:60], s['script']))
        if out['caretaker']:
            c = out['caretaker']
            print('caretaker', c['ref'], c['geom'])
            for i, r in enumerate(c['refs']):
                print('  [%2d] %5d %s' % (i, r, out['refs'].get(str(r), '-')))
        for t in out['checkInside']:
            print('checkInside', t['geom'], 'watch', out['refs'].get(str(t['watch'])), '->', t['msg'], t['msgId'])
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
