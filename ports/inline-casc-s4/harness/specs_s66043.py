"""specs_s66043.py - cascade s4 batch 66043: 0x648fb0 (collect masked records and link their slots into a chain)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g648fb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x3c, r.getrandbits(32))
    hook_rec(c, 0x64d030, 4, this=True)
    hook_rec(c, 0x63e850, 1, this=True)
    hook_rec(c, 0x64c090, 1, this=True)
    n = r.choice([0, 0xffffffff, 1, 2, 5, 16, 17, 20, 33])
    cnt = n if 0 < n < 100 else 1
    slots = {}
    for idx in (1, 2, 3, 0x801):
        if r.random() < 0.75:
            s = e.alloc(0x40, 8)
            ee = e.alloc(0x20, 8)
            e.wbytes(ee + 5, bytes([r.choice([0, 1, 2, 3])]))
            e.w32(s + 8, ee)
            e.wbytes(s + 5, bytes([r.choice([0, 1, 2, 3])]))
            slots[idx] = s
    tab = e.alloc(4 * 0x1000, 8)
    for idx, s in slots.items():
        e.w32(tab + 4 * idx, s)
    t = e.alloc(0x10100, 8)
    e.w32(t + 0x10071, tab)
    e.w32(t + 0x1005d, rnd(c, 8))
    recs = e.alloc(4 * cnt + 4, 8)
    for i in range(cnt):
        rec = e.alloc(0x70, 8)
        e.w32(rec + 0x3c, r.getrandbits(32) & 0xefffffff)
        e.wbytes(rec + 0x5a, r.choice([1, 2, 3, 0x801, 0x1801, 7, 0x1001]).to_bytes(2, 'little'))
        e.w32(recs + 4 * i, rec)
    masks = e.alloc(4 * ((cnt + 15) // 16) + 4, 8)
    for i in range((cnt + 15) // 16 + 1):
        e.w32(masks + 4 * i, r.getrandbits(32) if r.random() < 0.8 else 0)
    d = e.alloc(0x40, 8)
    e.w32(d + 0x18, rnd(c, 8))
    return [t, masks, recs, n, d]


S(0x648fb0, 'GUESS collect masked records and link their slots into a chain', 'thiscall', None, ret='eax', gen=_g648fb0, note='batch66043')
