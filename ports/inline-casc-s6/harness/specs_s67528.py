"""specs_s67528.py - cascade s6 batch 67528 (0x64d230, thiscall(req) ret 4). The owner (req[8]) carries a request record at +8 with the id word at +4; this slot 0x60 resolves ids to objects (pool of
objects whose +0x40 word, masked to 12 bits, indexes the table at this+0x10071; entries random 0 or pointers); 0x63f3e0 / 0x658f10 / 0x658f50 are hooks; the factory object at this+0x10169 has slot 8
returning a fresh record, this slot 0x5c is a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g64d230(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    keys = [0x5, 0x6, 0x7, 0x1005, 0xf006, 0x1a, 0x805, 0x9f0, 0xa07, 0x8805]
    objs = []
    for _ in range(4):
        o = rnd(c, 0x50)
        _w(c, o + 0x40, r.choice(keys), 2)
        objs.append(o)
    tab = e.alloc(0x4000, 4)
    e.wbytes(tab, bytes(0x4000))
    for k in set(x & 0xfff for x in keys):
        if r.random() < 0.5:
            _w(c, tab + 4 * k, rnd(c, 0x10))
    fresh = [rnd(c, 0x20) for _ in range(6)]
    fac = obj(c, 0x20, {8: pystub(c, 0, this=True, ret=lambda em, k: fresh[k % len(fresh)])})
    mgr = rnd(c, 0x20)
    t = obj(c, 0x10200, {0x60: pystub(c, 1, this=True, ret=lambda em, k: r.choice(objs + [0])),
                        0x5c: pystub(c, 1, this=True, nullflag=(), deref=None)})
    _w(c, t + 0x1005d, mgr)
    _w(c, t + 0x10071, tab)
    _w(c, t + 0x10169, fac)
    pool = objs + [0]
    hook_rec(c, 0x63f3e0, 2, this=True, ret=lambda em, k: r.choice([0, 0x1234 + k, 0x55 + 16 * k, 0x99]))
    hook_rec(c, 0x658f10, 1, this=True, ret=lambda em, k: r.choice(pool))
    hook_rec(c, 0x658f50, 0, this=True, ret=lambda em, k: r.choice([0, 1, 2, 3, 4, -1 & 0xffffffff]))
    rec = rnd(c, 0x10)
    _w(c, rec + 4, r.getrandbits(16), 2)
    owner = rnd(c, 0x30)
    _w(c, owner + 8, rec)
    req = rnd(c, 0x20)
    _w(c, req + 8, owner)
    return [t, req]


S(0x64d230, 'GUESS attach_object_with_children', 'thiscall', None, ret='al', gen=_g64d230, note='batch67528')
