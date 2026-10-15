"""specs_s31129.py - Sonnet h1 batch 31129."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def wstr(c, L, extra=0):
    r = c.rng
    s = rnd(c, 0x20)
    bs = [r.randrange(1, 256) for _ in range(L)] + [0, 0, 0, 0]
    for i in range(L + 1):
        c.emu.w32(s + i, bs[i] | bs[i + 1] << 8 | bs[i + 2] << 16 | bs[i + 3] << 24)
    return s


def g4f4700(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x40)
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=clob(c))
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    me = obj(c, 0xc0, {0x294: pystub(c, 0, ret=r32(c), this=True)}, nslots=0x100)
    c.emu.w32(me + 0xac, r.choice([0, r32(c) | 1]))
    return [me, wstr(c, r.choice([0, 1, 3, 7]))]


def g533310(c):
    clear_hooks(c)
    r = c.rng
    m = r.choice([0, 1, 2, 3])
    K = obj(c, 0x40, {0x58: pystub(c, 0, ret=r32(c), this=True), 0x4c: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x40)
    c.emu.w32(0x676144, pystub(c, 2, ret=r32(c), pop=8))
    me = obj(c, 0x54a0, {0x19c: pystub(c, 0, ret=lambda e, k: 1 if k >= m else 0, this=True),
                         0x164: pystub(c, 0, ret=r32(c), this=True)}, nslots=0x100)
    c.emu.w32(me + 0x548a, r.choice([0, K, K]))
    c.emu.w32(me + 0x51a5, rnd(c, 0x30))
    return [me]


def g56dd20(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x610100, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    hook_rec(c, 0x4e5e60, 0, ret=lambda e, k: r.getrandbits(32), pop=0, this=True, side=clob(c))
    base = r32(c)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda e, k: (base + k * 0x01000193) & 0xffffffff, this=True)})
    return [rnd(c, 0x220), rnd(c, 0x20)]


def g5bf9b0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x6352f0, 1, ret=r32(c), pop=4, this=False)
    hook_rec(c, 0x5bf940, 0, ret=r32(c), pop=0, this=True)

    def side(em, k):
        if r.random() < 0.6:
            em.w32(em.arg32(0), r.getrandbits(32))
    A = obj(c, 0x40, {0x48: pystub(c, 1, ret=r32(c), this=True), 0x68: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x40)
    me = obj(c, 0x90, {0x84: pystub(c, 1, ret=r32(c), this=True, side=side, deref={0: 1})}, nslots=0x100)
    return [me, A]


S(0x4f4700, 'GUESS free old string, duplicate arg into allocated buffer, slot 0x294', 'thiscall', None, ret='eax', gen=g4f4700, note='batch31129')
S(0x533310, 'GUESS wait loop on slot 0x19c, write two header records, slot 0x164, import, release', 'thiscall', None, ret='eax', gen=g533310, note='batch31129')
S(0x56dd20, 'GUESS read 33 ids via sys slot 0x58 plus three dwords', 'thiscall', None, ret='eax', gen=g56dd20, note='batch31129')
S(0x5bf9b0, 'GUESS 6352f0/slot 0x84 init local, 5bf940, copy three fields via arg slots', 'thiscall', None, ret='al', gen=g5bf9b0, note='batch31129')
