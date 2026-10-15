"""specs_s31117.py - Sonnet h1 batch 31117."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g5aabe0(c):
    clear_hooks(c)
    r = c.rng
    b = obj(c, 0x40, {0x64: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x40)
    a = obj(c, 0x40, {0x3c: pystub(c, 1, ret=r32(c), this=True, side=clob(c)),
                      0x64: pystub(c, 1, ret=b, this=True, side=clob(c))}, nslots=0x40)
    me = rnd(c, 0x20)
    c.emu.w32(me, r.choice([0, 1, 2, 3, 4]))
    c.emu.w32(me + 4, rnd(c, 0x40))
    c.emu.w32(me + 8, rnd(c, 0x40))
    return [me, a]


def g5ffbc0(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3, 5])
    ws = [r.getrandbits(16) for _ in range(n)]
    if n and r.random() < 0.7:
        v = r.choice(ws)
    else:
        v = r.getrandbits(16)
    ret = v | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0)
    g = obj(c, 0x40, {0x14: pystub(c, 1, ret=ret, this=True)}, nslots=0x20)
    blk = rnd(c, 0x60)
    c.emu.w32(blk + 0x3c, g)
    c.emu.w32(0x724278, blk)
    arr = rnd(c, 0x40)
    wsx = ws + [v if r.random() < 0.6 else r.getrandbits(16), r.getrandbits(16)]
    for j in range(len(wsx) // 2):
        c.emu.w32(arr + 4 * j, wsx[2 * j] | wsx[2 * j + 1] << 16)
    me = rnd(c, 0x20)
    c.emu.w32(me + 4, n | (r.getrandbits(16) << 16))
    c.emu.w32(me + 6, arr)
    c.emu.w32(me + 0xa, rnd(c, 0x40))
    return [me, r32(c)]


def g63fd80(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x120)
    n = r.choice([0, 1, 2, 3])
    arg = r32(c)
    ents = []
    for i in range(n):
        e = rnd(c, 0x10060)
        c.emu.w32(e + 0x10051, arg if r.random() < 0.5 else r32(c))
        ents.append(e)
        c.emu.w32(me + 0xf0 + 4 * i, e)
    c.emu.w32(me + 0xec, n)

    def side(em, k):
        e = em.arg32(0)
        i = ents.index(e) if e in ents else 0
        em.w32(me + 0xec, i)
    obj_me = c.emu.r32(me)
    vt = c.emu.alloc(0x200, 4)
    c.emu.w32(vt + 0x30, pystub(c, 1, ret=r32(c), this=True, side=side))
    c.emu.w32(vt + 0x64, pystub(c, 0, ret=r32(c), this=True))
    c.emu.w32(me, vt)
    return [me, arg]


def g4873f0(c):
    clear_hooks(c)
    r = c.rng
    e1 = r32(c)
    e2 = e1 if r.random() < 0.5 else r32(c)
    a = obj(c, 0x40, {0x364: pystub(c, 0, ret=e1, this=True, side=clob(c)),
                      0x35c: pystub(c, 0, ret=e2, this=True)}, nslots=0x200)
    o = obj(c, 0x40, {0x560: pystub(c, 1, ret=r.choice([0, r32(c) | 1]), this=True)}, nslots=0x200)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, o)
    return [me, a]


S(0x5aabe0, 'GUESS slot 0x3c(count) then paired slot 0x64 over two arrays', 'thiscall', None, ret='eax', gen=g5aabe0, note='batch31117')
S(0x5ffbc0, 'GUESS map id via slot 0x14 to value through word table', 'thiscall', None, ret='eax', gen=g5ffbc0, note='batch31117')
S(0x63fd80, 'GUESS remove matching entries (slot 0x30) until none, then slot 0x64', 'thiscall', None, ret='eax', gen=g63fd80, note='batch31117')
S(0x4873f0, 'GUESS compare slot 0x364 vs 0x35c unless slot 0x560 is zero', 'thiscall', None, ret='al', gen=g4873f0, note='batch31117')
