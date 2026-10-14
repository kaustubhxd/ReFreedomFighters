"""specs_s34094.py - seven items; callees are recorders (this recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g636330(c):
    clear_hooks(c)
    return [rnd(c, 0x50)]


def _g54cd70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    return [rnd(c, 0x20), r.choice([0, 1, 2, 3, r.getrandbits(32)])]


def _g55c8b0(c):
    clear_hooks(c)
    r = c.rng
    cell = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=cell)
    tgt = obj(c, 0x20, {0x6a0: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x6a4 // 4)
    me = rnd(c, 0x30)
    c.emu.w32(me + 0x1c, tgt)
    return [me, rnd(c, 0x20)]


def _g596d30(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5a5e90, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x1fd0)
    vals = [0, 1, 0x7fffffff, 0x80000000, 0xffffffff, 5, r.getrandbits(32)]
    c.emu.wbytes(me + 0x1fbe, r.choice(vals).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x1d0f, (0 if r.random() < 0.3 else rnd(c, 0x20)).to_bytes(4, 'little'))
    return [me, r.choice(vals)]


def _g489da0(c):
    clear_hooks(c)
    r = c.rng
    so = rnd(c, 0x60)
    c.emu.w32(0x70039c, so)
    me = rnd(c, 0x40)
    o = rnd(c, 0x420)
    c.emu.w32(me + 4, o)
    c.emu.wbytes(o + 0x417, r.choice([0, 0x7b, 1, 0x80, 0x20, r.getrandbits(32)]).to_bytes(4, 'little'))
    t = c.emu.r32(so + 0x40)
    c.emu.wbytes(me + 0x1d, r.choice([t, (t + 1) & 0xffffffff, (t - 1) & 0xffffffff, 0x7fffffff, 0x80000000, r.getrandbits(32)]).to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g623050(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 3, 8])
    m = r.choice([0, 1, 2, 3, 8, 10])
    src = rnd(c, 0x40)
    dst = rnd(c, 0x40)
    ps = rnd(c, 0x10)
    pd = rnd(c, 0x10)
    c.emu.w32(ps, src)
    c.emu.w32(pd, dst)
    return [r.getrandbits(32), ps, src + n, pd, dst + m]


def _g62cc90(c):
    clear_hooks(c)
    r = c.rng
    a = rnd(c, 0x20)
    c.emu.w32(a + 0xc, r.choice([0, 0, 1, r.getrandbits(32)]))
    return [a, r.choice([0x12, 0x12, 0xf, 0x1c, 0x1c, 0, 0x1d, r.getrandbits(32), 0xffffffff])]


S(0x636330, 'GUESS constructor with magic tag', 'thiscall', None, ret='eax', gen=_g636330, note='batch34094')
S(0x54cd70, 'GUESS scalar deleting destructor D', 'thiscall', None, ret='eax', gen=_g54cd70, note='batch34094')
S(0x55c8b0, 'GUESS forward cell value to slot 0x6a0', 'thiscall', None, ret='eax', gen=_g55c8b0, note='batch34094')
S(0x596d30, 'GUESS clamp and forward', 'thiscall', None, ret=None, gen=_g596d30, note='batch34094')
S(0x489da0, 'GUESS expiry check', 'thiscall', None, ret='al', gen=_g489da0, note='batch34094')
S(0x623050, 'GUESS bounded byte copy', 'cdecl', None, ret=None, gen=_g623050, note='batch34094')
S(0x62cc90, 'GUESS event filter K', 'cdecl', None, ret='eax', gen=_g62cc90, note='batch34094')
