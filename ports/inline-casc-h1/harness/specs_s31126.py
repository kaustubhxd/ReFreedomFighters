"""specs_s31126.py - Sonnet h1 batch 31126."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def g4cafb0(c):
    clear_hooks(c)
    r = c.rng
    res = r.choice([0, rnd(c, 0x40)])
    h = obj(c, 0x40, {0xe4: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x100)
    G = obj(c, 0x40, {0x80: pystub(c, 1, ret=res, this=True)}, nslots=0x100)
    c.emu.w32(G + 0x18, h)
    so = sysobj(c)
    c.emu.w32(so + 0x1aa3, G)
    B = rnd(c, 0x80)
    A = rnd(c, 0x20)
    c.emu.w32(A + 8, B)
    me = obj(c, 0x100, {0x68: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x40)
    c.emu.w32(me + 0x44, A)
    c.emu.w32(me + 0x8c, r.choice([0, 0, r32(c) | 1]))
    return [me]


def g4f63b0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4face0, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    hook_rec(c, 0x4e1b20, 0, ret=r32(c), pop=0, this=True, side=clob(c))
    hook_rec(c, 0x4e1b30, 0, ret=r32(c), pop=0, this=True)

    def side(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x4e12e0, 2, ret=r32(c), pop=8, this=True, side=side, nullflag=(0,))
    P = rnd(c, 0x100)
    d = r.choice([0, 4, 8, 0x10, 0x20])
    c.emu.w32(P + 4, d)
    c.emu.w32(P + d + 8, r.choice([0, 1, 2, 5]))
    G = obj(c, 0x40, {}, nslots=0x10)
    H = obj(c, 0x40, {0xc: pystub(c, 1, ret=P, this=True)}, nslots=0x20)
    Gb = rnd(c, 0x40)
    c.emu.w32(Gb + 0x18, H)
    so = sysobj(c)
    c.emu.w32(so + 0x1aa3, Gb)
    return [rnd(c, 0xa8), rnd(c, 0x20)]


def g56ce70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5625c0, 1, ret=r32(c), pop=4, this=True, side=clob(c))
    vt = c.emu.alloc(0x40, 4)
    c.emu.w32(vt + 0x14, pystub(c, 0, ret=r.choice([1, 1, 0, 2, r32(c)]), this=True))
    X = rnd(c, 0xe0)
    c.emu.w32(X + 0xcb, vt)

    def side(em, k):
        if r.random() < 0.8:
            em.w32(em.arg32(1), r.getrandbits(32))
    o = obj(c, 0x40, {0x88: pystub(c, 2, ret=r32(c), this=True, side=side)}, nslots=0x100)
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=o, this=True)})
    me = obj(c, 0x100, {0x84: pystub(c, 0, ret=X, this=True, side=clob(c))}, nslots=0x100)
    return [me, r.choice([0, 0, 1, r32(c)])]


def g5f2f70(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    hook_rec(c, 0x5f2d60, 2, ret=r32(c), pop=8, this=True)
    L = r.choice([0, 1, 3, 6])
    s = rnd(c, 0x20)
    bs = [r.randrange(1, 256) for _ in range(L)] + [0, 0, 0, 0]
    for i in range(L + 1):
        c.emu.w32(s + i, bs[i] | bs[i + 1] << 8 | bs[i + 2] << 16 | bs[i + 3] << 24)
    a = rnd(c, 0x10)
    st = r.choice([0, 3, 100, r32(c)])
    c.emu.w32(a, st)
    c.emu.w32(a + 4, (st + r.choice([0, 1, 4, 10])) & 0xffffffff)
    new = (s + ((c.emu.r32(a + 4) - st + 1) & 0xffffffff)) & 0xffffffff
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, s)
    c.emu.w32(me + 0xc, r.choice([new, (new - 1) & 0xffffffff, (new + 1) & 0xffffffff, r32(c)]))
    return [me, a]


S(0x4cafb0, 'GUESS create handle via global+0x1aa3 chain slots 0xe4/0x80 then slot 0x68(0x10,0)', 'thiscall', None, ret='eax', gen=g4cafb0, note='batch31126')
S(0x4f63b0, 'GUESS read id from stream, resolve record via global+0x1aa3 slot 0xc, set pointers', 'thiscall', None, ret='eax', gen=g4f63b0, note='batch31126')
S(0x56ce70, 'GUESS embedded slot 0x14 == 1 and arg 0 -> flag, table slot 0x138 obj slot 0x88, 5625c0', 'thiscall', None, ret='eax', gen=g56ce70, note='batch31126')
S(0x5f2f70, 'GUESS append string span: 5f2d60, advance this[8], assert on overrun', 'thiscall', None, ret='eax', gen=g5f2f70, note='batch31126')
