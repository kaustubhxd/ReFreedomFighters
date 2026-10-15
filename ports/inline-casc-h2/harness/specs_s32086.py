"""specs_s32086.py - h2 (Sonnet) batch 32086: eight tier C wrappers. Callees hooked as recorders; slots are recorder stubs."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g522850(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    buf = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=buf)
    me = rnd(c, 0x40)
    e.w32(me + 0x1c, obj(c, 0x20, {0x37c: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x37c // 4 + 1))
    return [me, rnd(c, 0x20)]


def _g_pair(k):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        hook_rec(c, 0x593f40, 1, this=True, pop=4)
        hook_rec(c, 0x594040, 2, this=True, pop=8, ret=r.getrandbits(32))
        hook_rec(c, 0x596ef0, 2, this=True, pop=8, ret=r.getrandbits(32))
        me = rnd(c, 0x1d20)
        e.wbytes(me + 0x1d0b, rnd(c, 0x20).to_bytes(4, 'little'))
        return [me]
    return g


def g5d5790(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x43de70, 0, this=True, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x60)
    if r.random() < 0.7:
        e.wbytes(me + 0x19, obj(c, 0x20, {0: pystub(c, 1, this=True)}).to_bytes(4, 'little'))
    else:
        e.wbytes(me + 0x19, bytes(4))
    return [me]


def g65c030(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x6493d0, 1, this=True, pop=4)
    p = obj(c, 0x20, {0: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x20), p]


def g46e980(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4de7a0, 0, this=True, pop=0)
    hook_rec(c, 0x4db2c0, 2, this=True, pop=8, ret=r.getrandbits(32))
    inner = rnd(c, 0x20)
    rec = rnd(c, 0x20)
    e.w32(rec + 8, inner)
    me = obj(c, 0x40, {0x2dc: pystub(c, 0, ret=(rec if r.random() < 0.6 else 0), this=True)}, nslots=0x2dc // 4 + 1)
    return [me, rnd(c, 0x20), rnd(c, 0x20)]


def g46f660(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x440e10, 1, this=True, pop=4)
    p = obj(c, 0x20, {0x70: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x90), p]


def g4798d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.wbytes(0x6ffa28, r.getrandbits(16).to_bytes(2, 'little'))
    me = obj(c, 0x6d0, {0x128: pystub(c, 3, this=True)}, nslots=0x128 // 4 + 1)
    v = r.choice([0, 1, 0xffffffff, 0x80000000, r.getrandbits(32), r.randrange(1, 100)])
    e.wbytes(me + 0x691, v.to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


S(0x522850, 'GUESS 5003d0 then slot 0x37c([r],0)', 'thiscall', None, ret='eax', gen=g522850, note='batch32086')
S(0x596900, 'GUESS init sequence 593f40(0) 594040(0xb) 596ef0(4)', 'thiscall', None, ret='eax', gen=_g_pair(0), note='batch32086')
S(0x597f70, 'GUESS init sequence 593f40(1) 594040(0xd) 596ef0(0)', 'thiscall', None, ret='eax', gen=_g_pair(1), note='batch32086')
S(0x5d5790, 'GUESS dtor: release owned, free, tail base', 'thiscall', None, ret='eax', gen=g5d5790, note='batch32086')
S(0x65c030, 'GUESS 6493d0(p), slot 0(this)', 'thiscall', None, ret='eax', gen=g65c030, note='batch32086')
S(0x46e980, 'GUESS slot 0x2dc lookup or zero out', 'thiscall', None, ret='eax', gen=g46e980, note='batch32086')
S(0x46f660, 'GUESS 440e10(p), slot 0x70, true', 'thiscall', None, ret='al', gen=g46f660, note='batch32086')
S(0x4798d0, 'GUESS conditional slot 0x128', 'thiscall', None, ret=None, gen=g4798d0, note='batch32086')
