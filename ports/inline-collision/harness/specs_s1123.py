"""specs_s1123.py - collision thread batch 1123: 0x4e3ce0 octree node walk. Builds a random tree of 6-byte node
records (sibling runs end with bit 15; children always come after their parent, so no cycles) and an item array;
the item callback is a stub that logs its two register args (item address, info), which are heap values."""
import random
from pilot import S, F


def _tree(c):
    e, r = c.emu, c.rng
    recs = []     # dicts: cnt, w4, w2, last
    items_needed = [0]

    def group(n, depth):
        start = len(recs)
        for k in range(n):
            cnt = r.choice([0, 0, 1, 2, 3])
            recs.append({'cnt': cnt, 'w4': 0, 'w2': 0, 'last': k == n - 1})
            items_needed[0] += 0
        for k in range(n):
            idx = start + k
            cnt = recs[idx]['cnt']
            recs[idx]['w4'] = items_needed[0]
            items_needed[0] += cnt
            if depth < 3 and r.random() < 0.5:
                recs[idx]['w2'] = len(recs)
                group(r.choice([1, 2, 3]), depth + 1)
        return start

    group(1, 0)
    nrec = len(recs)
    base = e.alloc(6 * nrec + 0x10, 4)
    for i, rc in enumerate(recs):
        w0 = (rc['cnt'] << 3) | (0x8000 if rc['last'] else 0) | r.getrandbits(3)   # octant bits: ignored by this walk
        e.w16(base + 6 * i, w0)
        e.w16(base + 6 * i + 2, rc['w2'])
        e.w16(base + 6 * i + 4, rc['w4'])
    items = e.alloc(16 * (items_needed[0] + 2) + 0x10, 16)
    e.wbytes(items, bytes(r.getrandbits(8) for _ in range(16 * (items_needed[0] + 2) + 0x10)))
    info = e.alloc(0x40, 4)
    e.w32(info + 0xc, base)
    e.w32(info + 0x10, items)
    def cb(em, rr):
        em.calllog.append(('item', em.reg('ecx') - items, em.reg('edx') == info))
        em.ret(eax=None, argbytes=0)
    e.w32(info + 4, e.stub_fn('itemcb', cb))
    return base, info


def _gen(c):
    base, info = _tree(c)
    return [base, info]


S(0x4e3ce0, 'octree node walk (GUESS GetEverything helper)', 'thiscall', None, gen=_gen, note='batch1123')
