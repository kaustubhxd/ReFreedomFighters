"""specs_s210034.py - Sonnet-w3a: field reads + engine lookups, list dispatch by flag, list walk with report; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g5dd4b0(c):
    clear_hooks(c)
    hook_rec(c, 0x4e5e60, 0, ret=lambda e, k: c.rng.getrandbits(32), this=True)
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda e, k: c.rng.getrandbits(32), this=True)}, nslots=0x20))
    return [rnd(c, 0x80), rnd(c, 0x20)]


def g44e590(c):
    clear_hooks(c)
    n = c.rng.choice([0, 1, 2, 3])
    ents = rnd(c, 0x20)
    for i in range(n):
        e = rnd(c, 0x20)
        c.emu.w32(ents + 4 * i, e)
    t = rnd(c, 0x30); c.emu.w32(t + 0x1c, n); c.emu.w32(t + 0x20, ents)
    objs = [0 if c.rng.random() < 0.3 else obj(c, 0x40, {0x294: pystub(c, 2, ret=_r(c), this=True), 0x290: pystub(c, 4, ret=_r(c), this=True)}, nslots=0xa5) for _ in range(4)]
    _eng(c, obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda e, k: objs[k % 4], this=True)}, nslots=0x20))
    return [t, c.rng.choice([0, 1, 0x100, 0x1ff])]


def g43ff00(c):
    clear_hooks(c)
    hook_rec(c, 0x45dcd0, 5, ret=0 if c.rng.random() < 0.2 else rnd(c, 0x10), this=True)
    k = c.rng.choice([0, 1, 2, 3])
    nodes = [rnd(c, 0x70) for _ in range(k)]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 0x60, nodes[i + 1] if i + 1 < k else 0)
        if c.rng.random() < 0.25:
            c.emu.w32(nd + 0x54, 0)
        else:
            m = obj(c, 0x40, {0x1b8: pystub(c, 5, ret=_r(c), this=True)}, nslots=0x70)
            c.emu.w32(m + 0xc, rnd(c, 8))
            c.emu.w32(m + 4, 0 if c.rng.random() < 0.4 else rnd(c, 8))
            c.emu.w32(nd + 0x54, m)
    t = rnd(c, 0x60); c.emu.w32(t + 0x50, nodes[0] if nodes else 0)
    o = obj(c, 0x40, {0x2c: pystub(c, 2, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=o, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    return [t, _r(c), _r(c), _r(c), _r(c), c.rng.choice([0, 1, 1, 0x100])]


S(0x5dd4b0, 'read_six_lookup_five', 'thiscall', None, ret='eax', gen=g5dd4b0, note='batch210034')
S(0x44e590, 'dispatch_list_by_flag', 'thiscall', None, ret=None, gen=g44e590, note='batch210034')
S(0x43ff00, 'notify_list_report_missing', 'thiscall', None, ret='eax', gen=g43ff00, note='batch210034')
