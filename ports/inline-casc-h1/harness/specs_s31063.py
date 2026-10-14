"""specs_s31063.py - batch 31063."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def r32(c):
    return c.rng.getrandbits(32)


def g6362d0(c):
    clear_hooks(c)
    return [rnd(c, 0x40)]


def g624490(c):
    clear_hooks(c)
    return [r32(c), rnd(c, 8)]


def g532730(c):
    clear_hooks(c)
    r = c.rng
    return [r.choice([r32(c), 0x4002, 0x4002 | 0x8000, 0x4003, 0x2, 0x4000 | r.getrandbits(12), r.getrandbits(16)])]


def _handler(codes):
    def g(c):
        clear_hooks(c)
        me = rnd(c, 0x20)
        if c.rng.random() < 0.5:
            c.emu.w32(me + 0xc, 0)
        return [me, c.rng.choice(codes + [c.rng.getrandbits(8)])]
    return g


def g545d10(c):
    clear_hooks(c)
    me = rnd(c, 0x20)
    n = 4
    tab = rnd(c, 0x34 * n)
    c.emu.w32(me + 0xf, tab)
    return [me, c.rng.randrange(n), rnd(c, 12), rnd(c, 12), rnd(c, 4)]


def g623010(c):
    clear_hooks(c)
    r = c.rng
    n, m = r.randrange(0, 9), r.randrange(0, 9)
    src = rnd(c, 16)
    dst = rnd(c, 40)
    ps = c.emu.alloc(4, 4)
    pd = c.emu.alloc(4, 4)
    c.emu.w32(ps, src)
    c.emu.w32(pd, dst)
    return [r32(c), ps, src + n, pd, dst + 2 * m]


def g615560(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x30 * 6 + 0x40)
    h = r.choice([0xffff, 1, 2, 3, 4, 5])
    c.emu.wbytes(me + 2, bytes([h & 0xff, h >> 8]))
    return [me]


S(0x6362d0, 'GUESS constructor NPAL vtable 6c1fec', 'thiscall', None, ret='eax', gen=g6362d0, note='batch31063')
S(0x624490, 'GUESS two-level table bit lookup', 'cdecl', None, ret='eax', gen=g624490, note='batch31063')
S(0x532730, 'GUESS flag test bool', 'stdcall', None, ret='al', gen=g532730, note='batch31063')
S(0x62cc50, 'GUESS message handler 17 -> 62cc90', 'cdecl', None, ret='eax', gen=_handler([0xf, 0x17, 0x1c, 0x1c]), note='batch31063')
S(0x62cf40, 'GUESS message handler 19 -> 62dbb0', 'cdecl', None, ret='eax', gen=_handler([0xf, 0x19, 0x1c, 0x1c]), note='batch31063')
S(0x545d10, 'GUESS copy record fields to outputs', 'thiscall', None, ret=None, gen=g545d10, note='batch31063')
S(0x623010, 'GUESS widen bytes to words', 'cdecl', None, ret=None, gen=g623010, note='batch31063')
S(0x615560, 'GUESS pool entry alloc', 'thiscall', None, ret='eax', gen=g615560, note='batch31063')
