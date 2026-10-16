"""specs_s210014.py - Sonnet-w3a: flag selector, array sum, guarded reset, ctor, string equality; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g5aaa80(c):
    clear_hooks(c)
    o = obj(c, 0x40, {8: pystub(c, 0, ret=_r(c), this=True), 0x14: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x10)
    t = rnd(c, 0x2c80)
    idx = c.rng.choice([0, 1, 2, 3])
    f = rnd(c, 0x10)
    if c.rng.random() < 0.5: c.emu.w32(f + 4, 3)
    e = rnd(c, 0x60); c.emu.w32(e + 0x54, f)
    _ub(c, t + idx * 4 + 0x2c39, e)
    c.emu.w32(0x7003b8, t)
    this = rnd(c, 0x680)
    c.emu.w32(this + 0x63c, o); c.emu.w32(this + 0x360, idx)
    return [this, _r(c), _r(c), _r(c)]


def g500150(c):
    clear_hooks(c)
    n = c.rng.choice([0, 1, 2, 3, 4])
    arr = rnd(c, 0x40)
    t = rnd(c, 0x10)
    c.emu.w32(t, arr); c.emu.w32(t + 4, arr + 4 * n)
    hook_rec(c, 0x5f9570, 0, ret=lambda e, k: c.rng.getrandbits(8), this=True)
    return [t]


def g62fad0(c):
    clear_hooks(c)
    hook_rec(c, 0x6322e0, 3, ret=_r(c), pop=0)
    r = c.rng.random()
    if r < 0.15: return [0]
    p = rnd(c, 0x40)
    if r < 0.3:
        c.emu.w32(p + 0x1c, 0)
        return [p]
    q = rnd(c, 0x30)
    if c.rng.random() < 0.4: c.emu.w32(q + 0xc, 0)
    c.emu.w32(p + 0x1c, q)
    return [p]


def g43e990(c):
    clear_hooks(c)
    hook_rec(c, 0x45c3a0, 3, ret=_r(c), this=True)
    return [rnd(c, 0x80), _r(c), _r(c), _r(c)]


def g4cc180(c):
    clear_hooks(c)
    L = c.rng.randrange(0, 9)
    s = bytes(c.rng.choice([1, 2, 3, 0x41]) for _ in range(L)) + b'\x00'
    t = bytearray(s)
    mode = c.rng.random()
    if mode < 0.5 and len(t) > 1:
        t[c.rng.randrange(0, len(t))] = c.rng.choice([1, 2, 3, 0x41, 0x80, 0xff, 0])
    p = rnd(c, 0x20); q = rnd(c, 0x20)
    c.emu.wbytes(p, s); c.emu.wbytes(q, bytes(t))
    o = rnd(c, 0x10); c.emu.w32(o, p)
    return [o, q]


S(0x5aaa80, 'select_color_by_state', 'thiscall', None, ret='eax', gen=g5aaa80, note='batch210014')
S(0x500150, 'sum_sizes_over_array', 'thiscall', None, ret='eax', gen=g500150, note='batch210014')
S(0x62fad0, 'reset_state_call_6322e0', 'stdcall', None, ret='eax', gen=g62fad0, note='batch210014')
S(0x43e990, 'ctor_vt_67c8f8', 'thiscall', None, ret='eax', gen=g43e990, note='batch210014')
S(0x4cc180, 'string_equal_pairs', 'thiscall', None, ret='eax', gen=g4cc180, note='batch210014')
