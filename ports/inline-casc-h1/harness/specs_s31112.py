"""specs_s31112.py - batch 31112."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def g62c730(c):
    clear_hooks(c)
    r = c.rng
    v = r.choice([r.getrandbits(16), r.getrandbits(16), r.getrandbits(8), r.getrandbits(8) << 8, r32(c), r.getrandbits(8) << 16 | r.getrandbits(16), r.getrandbits(24)])
    o = rnd(c, 0x180)
    c.emu.w32(o + 0x170, pystub(c, 2, ret=v, pop=0))
    c.emu.w32(o + 0x174, r32(c))
    return [o, r32(c)]


def g654720(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, ret=lambda e, k: e.reg('eax'), pop=0, this=True)

    def fill(em, k):
        p = em.arg32(1)
        for i in range(4):
            em.w32(p + 4 * i, r.getrandbits(32))
    c.emu.w32(0x676210, pystub(c, 2, ret=r32(c), pop=8, side=fill))
    c.emu.w32(0x676214, pystub(c, 2, ret=r32(c), pop=8, side=fill))
    me = rnd(c, 0x150)
    c.emu.w32(me + 0x137, r.choice([0, 0, 1, r32(c) | 1]))
    return [me, rnd(c, 0x20)]


def g65cb00(c):
    clear_hooks(c)
    r = c.rng
    o2 = obj(c, 0x40, {0x30: pystub(c, 2, ret=r32(c), pop=0)}, nslots=0x40)
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}, nslots=0x40))
    buf = rnd(c, 0x60)
    me = rnd(c, 0x430)
    e = buf + r.choice([0, 4, 8, 0x10])
    c.emu.w32(me + 0x41c, e)
    c.emu.w32(me + 0x420, (e + r.choice([0xc, 0xc, 0xb, 0xd, 0x10, 0, 0x20, -1])) & 0xffffffff)
    return [me, r32(c)]


S(0x62c730, 'GUESS callback value lookup in 0x6bfd20/0x6bf720 bit tables', 'cdecl', None, ret='eax', gen=g62c730, note='batch31112')
S(0x654720, '/GS: IAT call (this[0x133], &tmp) chosen by flag, copy 4 dwords to out', 'thiscall', None, ret='eax', gen=g654720, note='batch31112')
S(0x65cb00, 'GUESS bounded push of 12-byte node {arg,0,0} else log', 'thiscall', None, ret='al', gen=g65cb00, note='batch31112')
