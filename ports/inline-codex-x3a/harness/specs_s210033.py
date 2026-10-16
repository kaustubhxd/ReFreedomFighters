"""specs_s210033.py - Sonnet-w3a: callback teardown, null-check report, record serializer loop; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g6321a0(c):
    clear_hooks(c)
    a = rnd(c, 0x50)
    c.emu.w32(a, c.rng.choice([4, 5, 6, 0, 1, 7]))
    c.emu.w32(a + 0x38, 0 if c.rng.random() < 0.4 else pystub(c, 3, ret=_r(c)))
    b = rnd(c, 0x40)
    c.emu.w32(b + 0x24, pystub(c, 2, ret=_r(c), pop=0))
    hook_rec(c, 0x633170, 2, ret=_r(c), pop=0)
    return [a, b]


def g438d90(c):
    clear_hooks(c)
    o = obj(c, 0x40, {0x2c: pystub(c, 2, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=o, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    hook_rec(c, 0x439670, 0, ret=lambda e, k: c.rng.choice([0, 1, 0xff, _r(c)]), this=True)
    hook_rec(c, 0x438e30, 0, ret=c.rng.choice([0, 1, 0x100, _r(c)]), this=True)
    if c.rng.random() < 0.12: return [0]
    a = rnd(c, 0x40)
    c.emu.w32(a, c.rng.choice([0, 1, 2, 3]))
    c.emu.wbytes(a + 0xc, bytes([c.rng.choice([0, 1, 1, 5])]))
    c.emu.w32(a + 8, rnd(c, 0x20))
    return [a]


def g5c4f80(c):
    clear_hooks(c)
    a = obj(c, 0x40, {0x54: pystub(c, 1, ret=_r(c), this=True), 0x64: pystub(c, 1, ret=_r(c), this=True),
                      0x44: pystub(c, 1, ret=_r(c), this=True), 0x68: pystub(c, 1, ret=_r(c), this=True),
                      0x60: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    t = rnd(c, 0x60)
    n = c.rng.choice([0, 1, 2, 3, 0xffffffff])
    c.emu.w32(t + 0x50, n)
    c.emu.w32(t + 0x4c, rnd(c, 0x100))
    return [t, a]


S(0x6321a0, 'teardown_callbacks', 'cdecl', None, ret='eax', gen=g6321a0, note='batch210033')
S(0x438d90, 'null_check_report_else_flags', 'stdcall', None, ret='al', gen=g438d90, note='batch210033')
S(0x5c4f80, 'serialize_records_loop', 'thiscall', None, ret='al', gen=g5c4f80, note='batch210033')
