"""specs_s67538.py - cascade s6 batch 67538 (0x64d030, thiscall(owner, rec, forceAlloc, mark) ret 0x10, returns the slot record or 0). this holds the manager (+0x1005d, with a sub-allocator
at +0x234: slots 8 / 0xc), the 4096-entry slot table (+0x10071, some entries pre-filled with records whose object flag byte +5 varies) and the record factory (+0x10159: slots 8 / 0xc); rec[0x54] has
slot 0xe4 (bool); 0x63e850 / 0x63f0e0 / 0x64c040 / 0x64c090 are hooks; sys[0x3c] is random."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g64d030(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c)
    keys = [0x11, 0x12, 0x1011, 0xf013]
    tab = e.alloc(0x4000, 4)
    e.wbytes(tab, bytes(0x4000))
    for k in set(x & 0xfff for x in keys):
        if r.random() < 0.4:
            s = rnd(c, 0x30)
            o = rnd(c, 0x20)
            _w(c, o + 5, r.choice([0, 1, 0x40, 0x41, 0x80]), 1)
            _w(c, s + 8, o)
            _w(c, tab + 4 * k, s)
    objs = [rnd(c, 0x20) for _ in range(3)]
    for o in objs:
        _w(c, o + 5, r.choice([0, 0x40, 0x41, 0x80, 0x44]), 1)
    hook_rec(c, 0x63e850, 1, this=True)
    hook_rec(c, 0x63f0e0, 2, this=True, ret=lambda em, k: r.choice(objs + [0]))
    hook_rec(c, 0x64c040, 1, this=True)
    hook_rec(c, 0x64c090, 1, this=True)
    sub = obj(c, 0x20, {8: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0x7000, 0x7100])), 0xc: pystub(c, 1, this=True)})
    mgr = rnd(c, 0x260)
    _w(c, mgr + 0x234, sub)
    recs = [rnd(c, 0x40) for _ in range(3)]
    fac = obj(c, 0x20, {8: pystub(c, 0, this=True, ret=lambda em, k: r.choice(recs + [0] if k >= 0 else recs)), 0xc: pystub(c, 1, this=True)})
    t = rnd(c, 0x10200)
    _w(c, t + 0x1005d, mgr)
    _w(c, t + 0x10071, tab)
    _w(c, t + 0x10159, fac)
    owner = rnd(c, 0x40)
    _w(c, owner + 8, rnd(c, 0x10))
    rec = rnd(c, 0x70)
    _w(c, rec + 0x5a, r.choice(keys), 2)
    _w(c, rec + 0x54, obj(c, 0x20, {0xe4: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))}))
    return [t, owner, rec, r.choice([0, 1, 0x100, 0x2]), r.choice([0, 1, 0x100, 5])]


S(0x64d030, 'GUESS acquire_slot_record', 'thiscall', None, ret='eax', gen=_g64d030, note='batch67538')
