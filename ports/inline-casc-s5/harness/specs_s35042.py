"""specs_s35042.py - 0x617360 (thiscall, no args). Counter [this+0x30] zero in 2/3 (random small otherwise); [this+4] -> record with +8 -> R (word +0xe 0..6, +0x14 offset); [this+8] = s with [s+0xb9a4] -> q
(0x14d0 bytes) whose unaligned dword at +0x13fa points at t (vtable slot 4 (2 args, returns a heap value), [t+0x30] zero in half); engine +0x1aa3 (unaligned) -> object with +0x20 base; [this+0x28] zero in 1/3;
0x659330 hooked (thiscall, 2 args) and 0x634d22 a cdecl recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g617360(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x659330, 2, this=True)
    hook_rec(c, 0x634d22, 3, pop=0)
    R = rnd(c, 0x40)
    e.wbytes(R + 0xe, r.choice([0, 1, 2, 3, 6]).to_bytes(2, 'little'))
    rec = rnd(c, 0x20)
    e.w32(rec + 8, R)
    t = obj(c, 0x40, {4: pystub(c, 2, this=True, ret=r.getrandbits(32))}, nslots=4)
    if r.random() < 0.5:
        e.w32(t + 0x30, 0)
    q = rnd(c, 0x1500)
    e.wbytes(q + 0x13fa, t.to_bytes(4, 'little'))
    s = rnd(c, 0xba00)
    e.w32(s + 0xb9a4, q)
    me = rnd(c, 0x40)
    e.w32(me + 4, rec)
    e.w32(me + 8, s)
    e.w32(me + 0x30, 0 if r.random() < 2 / 3 else r.randint(1, 5))
    if r.random() < 1 / 3:
        e.w32(me + 0x28, 0)
    so = sysobj(c)
    b = rnd(c, 0x40)
    e.wbytes(so + 0x1aa3, b.to_bytes(4, 'little'))
    return [me]


S(0x617360, 'GUESS first-use hook copies table', 'thiscall', None, ret=None, gen=_g617360, note='batch35042')
