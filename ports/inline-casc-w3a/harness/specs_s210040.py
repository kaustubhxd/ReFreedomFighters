"""specs_s210040.py - Sonnet-w3a: string-keyed table add, read-and-report chain, selector with callbacks; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _str(c, text):
    p = rnd(c, 0x10); c.emu.wbytes(p, text + b'\x00'); return p


def g5c2e10(c):
    clear_hooks(c)
    t = rnd(c, 0x2d0)
    n = c.rng.choice([0, 1, 2, 3, 5, 6])
    c.emu.w32(t + 0x2c4, n)
    words = [b'ab', b'cd', b'a', b'abc', b'b']
    for i in range(n):
        c.emu.w32(t + 0xf8 + i * 0x4c, _str(c, c.rng.choice(words)))
    s = 0 if c.rng.random() < 0.1 else _str(c, c.rng.choice(words))
    return [t, s]


def g51c210(c):
    clear_hooks(c)
    hook_rec(c, 0x512850, 1, ret=_r(c))
    for h, nargs in ((0x4e12e0, 2),):
        def side(emu, k):
            emu.w32(emu.arg32(0), c.rng.choice([0, 1, 7]))
        hook_rec(c, h, nargs, ret=_r(c), this=True, side=side)
    hook_rec(c, 0x4e1600, 0, ret=c.rng.choice([8, 8, 0, 7, 0x108]), this=True)
    hook_rec(c, 0x4e1b30, 0, ret=_r(c), this=True)
    o = obj(c, 0x40, {0x2c: pystub(c, 3, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=o, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    t = rnd(c, 0x460)
    c.emu.w32(t + 4, 0 if c.rng.random() < 0.4 else _str(c, b'name'))
    return [t, rnd(c, 0x20)]


def g62d840(c):
    clear_hooks(c)
    A = rnd(c, 0x20); c.emu.w32(A + 0xc, c.rng.choice([0, 0, 1]))
    ob = rnd(c, 0x40)
    c.emu.w32(ob + 0x1c, pystub(c, 4, ret=lambda e, k: c.rng.choice([0, 0, 1, 7]), pop=0))
    return [A, c.rng.choice([0xf, 0x12, 0x12, 0x1b, 0x1c, 0, 5]), _r(c), _r(c), ob]


S(0x5c2e10, 'find_or_add_string_entry', 'thiscall', None, ret='eax', gen=g5c2e10, note='batch210040')
S(0x51c210, 'read_and_report_chain', 'thiscall', None, ret='eax', gen=g51c210, note='batch210040')
S(0x62d840, 'selector_with_callbacks_b', 'cdecl', None, ret='eax', gen=g62d840, note='batch210040')
