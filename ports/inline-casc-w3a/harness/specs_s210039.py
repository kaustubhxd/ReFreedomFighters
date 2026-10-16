"""specs_s210039.py - Sonnet-w3a: record cache update with dirty flag, state reset with engine lookup; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _s16(c): return c.rng.choice([0, 1, 5, 0x7fff, 0x8000, 0xffff, 0xfffe])


def g5ed1e0(c):
    clear_hooks(c)
    t = rnd(c, 0x100)
    k = c.rng.choice([1, 2, 3])
    recs = [rnd(c, 0x20) for _ in range(k)]
    arr = rnd(c, 0x20)
    for i, rc in enumerate(recs): c.emu.w32(arr + 4 * i, rc)
    _ub(c, t + 0xcb, arr); _ub(c, t + 0xcf, arr + 4 * k)
    c.emu.wbytes(t + 0xa6, bytes([c.rng.choice([0, 0])]))
    a, b = c.rng.choice([1, 2, _r(c)]), c.rng.choice([1, 2, _r(c)])
    cw, dw = _s16(c), _s16(c)
    cs = cw - 0x10000 if cw >= 0x8000 else cw
    ds = dw - 0x10000 if dw >= 0x8000 else dw
    e = 0xffffffff if c.rng.random() < 0.5 else c.rng.randrange(0, k)
    targets = recs if e == 0xffffffff else [recs[e]]
    for rc in targets:
        if c.rng.random() < 0.6:
            c.emu.w32(rc + 4, a); c.emu.w32(rc + 8, b)
            c.emu.wbytes(rc + 0xc, cw.to_bytes(2, 'little')); c.emu.wbytes(rc + 0xe, dw.to_bytes(2, 'little'))
    if e == 0xffffffff and c.rng.random() < 0.15:
        _ub(c, t + 0xcf, arr)
    return [t, a, b, cs & 0xffffffff, ds & 0xffffffff, e]


def g5d5b40(c):
    clear_hooks(c)
    k = [0]

    def x_ret(e, n):
        return [c.rng.getrandbits(8), c.rng.getrandbits(8)][min(n, 1)] if False else c.rng.getrandbits(4)
    hook_rec(c, 0x64fc60, 0, ret=x_ret, this=True)

    def side(emu, kk):
        emu.w32(emu.arg32(1), c.rng.getrandbits(32))
    g = obj(c, 0x40, {0x88: pystub(c, 2, ret=_r(c), this=True, deref={1: 1}, side=side)}, nslots=0x40)
    mg = obj(c, 0x40, {0x138: pystub(c, 0, ret=g, this=True), 0x114: pystub(c, 5, ret=_r(c), this=True)}, nslots=0x60)
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    t = obj(c, 0x60, {0x110: pystub(c, 2, ret=_r(c), this=True), 0x12c: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x50)
    c.emu.wbytes(t + 0x31, bytes([c.rng.choice([0, 1, 1])]))
    _ub(c, t + 0x2d, c.rng.choice([0, 1, 2, 5]))
    _ub(c, t + 0x25, 0 if c.rng.random() < 0.3 else obj(c, 0x40, {0x2c: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x20))
    p = 0 if c.rng.random() < 0.15 else obj(c, 0x40, {4: pystub(c, 2, ret=_r(c), this=True)}, nslots=8)
    _ub(c, t + 0x19, p)
    _ub(c, t + 0x32, c.rng.choice([0, 3, 8, 15, 16]))
    return [t, _r(c), _r(c), _r(c), _r(c)]


S(0x5ed1e0, 'update_records_dirty_flag', 'thiscall', None, ret=None, gen=g5ed1e0, note='batch210039')
S(0x5d5b40, 'reset_state_engine_lookup', 'thiscall', None, ret=None, gen=g5d5b40, note='batch210039')
