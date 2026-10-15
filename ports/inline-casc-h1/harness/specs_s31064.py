"""specs_s31064.py - Sonnet h1 batch 31064."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def _handler(special):
    def g(c):
        clear_hooks(c)
        me = rnd(c, 0x20)
        if c.rng.random() < 0.5:
            c.emu.w32(me + 0xc, 0)
        return [me, c.rng.choice([0xf, special, 0x1c, 0x1c, 0x17, c.rng.getrandbits(8)])]
    return g


def g6487a0(c):
    clear_hooks(c)
    me = rnd(c, 0x24 * 4 + 0x80)
    h = c.rng.choice([0xffff, 1, 2, 3])
    c.emu.wbytes(me + 2, bytes([h & 0xff, h >> 8]))
    return [me]


def g6244e0(c):
    clear_hooks(c)
    return [r32(c), rnd(c, 8)]


def g62ad10(c):
    clear_hooks(c)
    r = c.rng
    tag = c.emu.rbytes(0x6c0148, 6)
    n = r.choice([0, 3, 5, 6, 6, 7, 10])
    buf = rnd(c, 16)
    if r.random() < 0.5 and n >= 6:
        k = r.randrange(0, 7)            # match first k bytes, then (maybe) mismatch
        c.emu.wbytes(buf, tag[:k])
        if k == 6:
            pass
    out = c.emu.alloc(4, 4)
    return [r32(c), buf, buf + n, out]


def g597a20(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c)
    c.emu.w32(so + 0x1b5d, 1 if r.random() < 0.3 else r32(c))
    hook_rec(c, 0x597a70, 1, ret=r32(c), pop=4, this=True)
    me = rnd(c, 0x2000)
    n = r.choice([0, 1, 3, 6, 0x10, -2 & 0xffffffff])
    c.emu.w32(me + 0x1fae, n)
    arg = r32(c)
    if r.random() < 0.5 and 0 < n < 0x80:
        c.emu.w32(me + 0x1dae + 4 * r.randrange(n), arg)
    return [me, arg]


def g4dcd10(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c, table_size=0x5d50)
    tab = c.emu.r32(so + 0x9b)
    c.emu.w32(tab + 0x5d31, obj(c, 0x20, {0: pystub(c, 1, ret=r32(c), this=True)}))
    me = rnd(c, 0x60)
    v = rnd(c, 12)
    if r.random() < 0.4:
        c.emu.wbytes(v, c.emu.rbytes(me + 0x24, 12))
    elif r.random() < 0.5:
        c.emu.wbytes(v, c.emu.rbytes(me + 0x24, 4))
        c.emu.w32(v + 4, r32(c))
    return [me, v]


S(0x597a20, 'GUESS list contains (global flag tail call)', 'thiscall', None, ret='al', gen=g597a20, note='batch31064')
S(0x4dcd10, 'GUESS set 3-vector, flag, notify object', 'thiscall', None, ret='eax', gen=g4dcd10, note='batch31064')
S(0x62d7f0, 'GUESS message handler 12 -> 62da60', 'cdecl', None, ret='eax', gen=_handler(0x12), note='batch31064')
S(0x62da10, 'GUESS message handler 12 -> 62cf90', 'cdecl', None, ret='eax', gen=_handler(0x12), note='batch31064')
S(0x62ddb0, 'GUESS message handler 12 -> 62de00', 'cdecl', None, ret='eax', gen=_handler(0x12), note='batch31064')
S(0x6487a0, 'GUESS pool entry alloc 0x24', 'thiscall', None, ret='eax', gen=g6487a0, note='batch31064')
S(0x6244e0, 'GUESS three-byte table bit lookup', 'cdecl', None, ret='eax', gen=g6244e0, note='batch31064')
S(0x62ad10, 'GUESS match 6-byte tag', 'cdecl', None, ret='eax', gen=g62ad10, note='batch31064')
