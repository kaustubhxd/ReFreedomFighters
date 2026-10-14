"""specs_s31127.py - batch 31127."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g4714d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dc630, 2, ret=r32(c), pop=8, this=True, side=clob(c))
    ebx = r.choice([0, obj(c, 0x40, {0x5c: pystub(c, 3, ret=r32(c), this=True)}, nslots=0x40)])
    b = obj(c, 0x40, {0x100: pystub(c, 1, ret=ebx, this=True, side=clob(c))}, nslots=0x100)
    blk = rnd(c, 0x60)
    c.emu.w32(b + 8, blk)
    c.emu.w32(blk + 0x3c, r.choice([0x800000, 0, r32(c), r32(c) | 0x800000]))
    return [rnd(c, 0x80), r32(c), b]


def g4f8420(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4fa8a0, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    flag = lambda: r.choice([0, 1, 0x100, r32(c)])

    def node(nxt):
        n = rnd(c, 0x70)
        if r.random() < 0.2:
            q = 0
        else:
            q = obj(c, 0x40, {0x1e0: pystub(c, 1, ret=flag(), this=True), 0x2ec: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x100)
            M = rnd(c, 0x40)
            c.emu.w32(M + 0x23, r.choice([0x100000, 0, r32(c), r32(c) | 0x100000]))
            c.emu.w32(q + 0xc, M)
        c.emu.w32(n + 0x54, q)
        c.emu.w32(n + 0x60, nxt)
        return n
    n = r.choice([0, 1, 2, 3])
    head = 0
    for _ in range(n):
        head = node(head)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x50, head)
    return [me, r32(c)]


def g533fc0(c):
    clear_hooks(c)
    r = c.rng
    A = r.choice([0, obj(c, 0x40, {0x14: pystub(c, 1, ret=r.choice([0, 1, 0x100, r32(c)]), this=True)}, nslots=0x20)])
    if A:
        c.emu.w32(A + 0x10, r.choice([0, 1, 3, 7, 0xf]))
    T = rnd(c, 0x40)
    for i in range(16):
        c.emu.w32(T + 4 * i, r.choice([0xffffffff, 0, 1, 2, 3, r32(c) & 0xffff]))
    me = rnd(c, 0x20)
    c.emu.w32(me, A)
    c.emu.w32(me + 4, T)
    c.emu.w32(me + 8, r32(c))
    return [me, r.choice([0, 0, 1, 2, 5, 8, r32(c)])]


def g578db0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, ret=lambda e, k: e.reg('eax'), pop=0, this=True,
             side=lambda e, k: e.calllog.append(('cookie', e.reg('ecx'))))
    c.emu.w32(0x6f5630, r32(c))
    c.emu.w32(0x6f5634, r32(c))

    def fill(em, k):
        a = em.arg32(1)
        for i in range(16):
            em.w32(a + 4 * i, r.getrandbits(32))

    def setbyte(em, k):
        if r.random() < 0.7:
            em.wbytes(em.arg32(1), bytes([r.getrandbits(8)]))
    o = obj(c, 0x40, {0x198: pystub(c, 4, ret=r32(c), pop=0, side=fill)}, nslots=0x100)
    t = obj(c, 0x40, {0x90: pystub(c, 2, ret=r32(c), this=True, deref={0: 16}, side=setbyte)}, nslots=0x40)
    sysobj(c, slots={0x190: pystub(c, 0, ret=o, this=True)}, table_slots={0x134: pystub(c, 0, ret=t, this=True)})
    return [rnd(c, 0x1a0)]


S(0x4714d0, 'GUESS toggle flag 0x800000 around slot 0x5c(0x20,a,word this[0x74])', 'thiscall', None, ret='eax', gen=g4714d0, note='batch31127')
S(0x4f8420, 'GUESS 4fa8a8 then walk list notifying objects with flag 0x100000 via slot 0x2ec', 'thiscall', None, ret='eax', gen=g4f8420, note='batch31127')
S(0x533fc0, 'GUESS lookup slot address for id via table mask, -1 -> 0', 'thiscall', None, ret='eax', gen=g533fc0, note='batch31127')
S(0x578db0, '/GS: slot 0x198 fills local, table slot 0x134 obj slot 0x90(local,&byte), return byte', 'thiscall', None, ret='al', gen=g578db0, note='batch31127')
