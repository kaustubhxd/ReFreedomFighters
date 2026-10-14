"""specs_s31128.py - batch 31128."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g5aeff0(c):
    clear_hooks(c)
    r = c.rng
    target = r32(c)
    A = obj(c, 0x40, {0x2e8: pystub(c, 0, ret=target, this=True)}, nslots=0x100)
    n = r.choice([0, 1, 2, 3, 4])
    me = rnd(c, 0x30)
    c.emu.w32(me, n)
    hit = r.randrange(0, n) if n and r.random() < 0.7 else -1
    for i in range(n):
        p = rnd(c, 0x20)
        c.emu.w32(p, target if i == hit else r32(c))
        c.emu.w32(p + 0x10, r32(c))
        c.emu.w32(me + 4 + 4 * i, p)
    return [me, r.choice([A, A, A, 0])]


def g60ff30(c):
    clear_hooks(c)
    r = c.rng
    idx = r.randrange(0, 8)
    vals = [r32(c) for _ in range(3)]
    for base, v in zip((0x724868, 0x724888, 0x7248a8), vals):
        c.emu.w32(base + 4 * idx, v if r.random() < 0.4 else r32(c))
    g = obj(c, 0x40, {0xfc: pystub(c, 4, ret=r32(c), this=True)}, nslots=0x100)
    c.emu.w32(0x724a00, g)
    return [idx, vals[0], vals[1], vals[2]]


def g46aa00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43ea20, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x45c510, 1, ret=r32(c), pop=0)
    hook_rec(c, 0x4690b0, 2, ret=r32(c), pop=0)
    me = rnd(c, 0x90)

    def side(em, k):
        em.calllog.append(('vt', em.r32(me)))

    def sub():
        return r.choice([0, obj(c, 0x40, {0: pystub(c, 1, ret=r32(c), this=True, side=side)}, nslots=0x10)])
    c.emu.w32(me + 0x7c, sub())
    c.emu.w32(me + 0x70, sub())
    return [me, r.choice([0, 1, 2, 3, 4, 5, 7, r32(c)])]


def g4cf5c0(c):
    clear_hooks(c)
    r = c.rng
    k = r.choice([0, 1, 2, 3])
    state = {'n': 0}

    def side5c(em, kk):
        v = 1 if kk < k else 0
        em.w32(em.arg32(0), v | (r.getrandbits(24) << 8 if v else 0) | 0 if v == 0 else (r.getrandbits(31) | 1))
    A = obj(c, 0x40, {0x4c: pystub(c, 1, ret=r32(c), this=True, side=lambda em, kk: em.w32(em.arg32(0) + 4, r.getrandbits(32))),
                      0x5c: pystub(c, 1, ret=lambda e, kk: (kk * 0x11111111 + 5) & 0xffffffff, this=True, side=side5c)}, nslots=0x40)
    K = obj(c, 0x40, {0xc: pystub(c, 0, ret=r32(c), this=True), 4: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x10)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, K)
    return [me, r.choice([A, A, A, 0])]


S(0x5aeff0, 'GUESS find entry whose first dword equals arg slot 0x2e8, return entry[0x10]', 'thiscall', None, ret='eax', gen=g5aeff0, note='batch31128')
S(0x60ff30, 'GUESS fastcall idx,val1 + stack val2,val3: update three tables and notify slot 0xfc', 'fastcall', None, ret='eax', gen=g60ff30, note='batch31128')
S(0x46aa00, 'GUESS dtor vtable 687fe4/6868e8: delete this[0x7c], this[0x70], flags', 'thiscall', None, ret='eax', gen=g46aa00, note='batch31128')
S(0x4cf5c0, 'GUESS feed values from arg slots 0x4c/0x5c to this[8] slot 4 until local zero', 'thiscall', None, ret='eax', gen=g4cf5c0, note='batch31128')
