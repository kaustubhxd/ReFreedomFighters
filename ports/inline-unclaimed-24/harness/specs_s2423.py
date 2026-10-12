"""specs_s2423.py - decomp area 24, batch 2423: three small leaves.
0x4cc5f0 MYSTR::Length() const: strlen of the string whose pointer is the first dword of the object (thiscall, eax).
0x5143f0 ZMoveOnSpline::SetMoveSoundParams(int, float): int at +0x1dd, float at +0x1e1 (thiscall, ret 8).
0x435d30 (GUESS owner): append the argument at +0x20 + 4*count while count <= 16, count at +0x60 (thiscall, ret 4).
Counts are 0..20 so the bound is hit."""
from pilot import S, F
from recruits_util import rnd, clear_hooks


def _str(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    s = bytes(r.randint(1, 255) for _ in range(r.randint(0, 24))) + b'\0'
    p = e.alloc(len(s) + 4, 4)
    e.wbytes(p, s)
    e.w32(o, p)
    return [o]


def _spl(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x200)
    return [o, r.getrandbits(32), F(r.uniform(-500.0, 500.0))]


def _app(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x80)
    e.w32(o + 0x60, r.randint(0, 20))
    return [o, r.getrandbits(32)]


S(0x4cc5f0, 'MYSTR::Length', 'thiscall', None, ret='eax', gen=_str, note='batch2423')
S(0x5143f0, 'ZMoveOnSpline::SetMoveSoundParams', 'thiscall', None, ret=None, gen=_spl, note='batch2423')
S(0x435d30, 'GUESS: bounded append (count at +0x60, 16 slots at +0x20)', 'thiscall', None, ret=None, gen=_app, note='batch2423')
