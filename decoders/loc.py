#!/usr/bin/env python3
"""Freedom Fighters LOC (localisation tree) -> JSON.

Node = [name\\0 (absent on root)] then, unless the node ends right after its
name, u8 childCount, (childCount-1) x u32 child offsets relative to the end of
the offset table (first child implicitly at 0). A node that ends right after
its name is a leaf; its name is the string itself.

usage: loc.py SCENE.LOC [out.json]
"""
import json, struct, sys

def read_sz(d, o):
    e = d.index(b'\0', o)
    b = d[o:e]
    try: return b.decode('utf-8'), e + 1
    except UnicodeDecodeError: return b.decode('cp1252', 'replace'), e + 1

def _offsets_ok(d, n, o, end):
    if o + 4 * (n - 1) > end: return False
    offs = [0] + list(struct.unpack_from('<%dI' % (n - 1), d, o)) + [end - o - 4 * (n - 1)]
    return all(0 <= offs[i] <= offs[i + 1] for i in range(n))

def node(d, o, end, root=False):
    name = None
    if not root:
        name, o = read_sz(d, o)
        if o == end:
            return name, None
    n = d[o]; o += 1
    if n > 1 and not _offsets_ok(d, n, o, end):
        # Some nodes (3 in C02A/C02B/C02RB/C07A) have byte 0x03 and then two packed
        # strings (the text and a designer comment, e.g. "Hm - er denne her ikke ...- Morten I.") with no
        # offset table. INFERRED: bit 0x02 = a comment string follows. The text is kept, the comment under '_comment'.
        parts = d[o:end].split(b'\0')[:-1]
        dec = lambda b: read_sz(b + b'\0', 0)[0]
        return name, {'_': dec(parts[0]), '_comment': [dec(x) for x in parts[1:]]}
    offs = [0] + list(struct.unpack_from('<%dI' % (n - 1), d, o)) if n > 1 else [0] * n
    o += 4 * max(0, n - 1)
    offs.append(end - o)
    kids = {}
    leaves = []
    for i in range(n):
        assert 0 <= offs[i] <= offs[i + 1], 'bad child offsets at %#x' % o
        k, v = node(d, o + offs[i], o + offs[i + 1])
        if v is None: leaves.append(k)
        else: kids[k] = v
    if leaves and not kids and len(leaves) == 1: return name, leaves[0]
    if leaves: kids['_'] = leaves if len(leaves) > 1 else leaves[0]
    return name, kids

def parse(d):
    return node(d, 0, len(d), root=True)[1]

if __name__ == '__main__':
    t = parse(open(sys.argv[1], 'rb').read())
    s = json.dumps(t, indent=1, ensure_ascii=False)
    if len(sys.argv) > 2: open(sys.argv[2], 'w').write(s)
    else: print(s)
