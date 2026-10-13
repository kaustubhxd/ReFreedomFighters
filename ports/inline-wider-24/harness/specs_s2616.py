"""specs_s2616.py - wider batch 2616: sixteen unclaimed functions; every callee/slot is a recorder (arities from `ret` immediates)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def rl(r, n, f):
    v = [f() for _ in range(n)]
    return lambda em, k: v[k % n]


def _fb(r):
    return struct.unpack('<I', struct.pack('<f', r.uniform(-50, 50)))[0]


def _rec_group(S1, S2, size, extra_self_slots):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        so = sysobj(c)

        def fill(em, k):
            b = em.arg32(1)
            for i in range(size // 4):
                em.w32(b + 4 * i, r.getrandbits(32))
        tab = obj(c, 0x40, {S1: pystub(c, 2, this=True, nullflag=(1,), side=fill),
                            S2: pystub(c, 2, this=True, nullflag=(), deref={1: size // 4})})
        x = rnd(c, 0x40)
        e.w32(x + 0x18, tab)
        e.wbytes(so + 0x1aa3, x.to_bytes(4, 'little'))
        slots = {0x238: pystub(c, 0, this=True)}
        for off in extra_self_slots:
            slots[off] = pystub(c, 1, this=True)
        me = obj(c, 0x80, slots)
        o8 = rnd(c, 0x80)
        e.w32(o8 + 0x6c, r.getrandbits(32))
        e.w32(me + 8, o8)
        return [me, _fb(r)]
    return g


def g44a0e0(c):
    clear_hooks(c)
    hook_rec(c, 0x4dc5d0, 3, this=True)
    hook_rec(c, 0x4dd060, 1, this=True, deref={0: 3})
    hook_rec(c, 0x4dce50, 1, this=True)
    me = rnd(c, 0x40)
    c.emu.w32(me + 8, rnd(c, 0x40))
    return [me]


def g44a8c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45c3a0, 3, this=True)
    hook_rec(c, 0x4609b0, 0, this=True)
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g44c180(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, nargs=3, slot=0x2c)
    hook_rec(c, 0x4cc5a0, 4, this=True, pop=0, ret=lambda em, k: r.getrandbits(32))
    me = rnd(c, 0x40)
    s = e.alloc(16, 4)
    e.wbytes(s, b'name\0')
    e.w32(me + 4, s if r.random() < 0.6 else 0)
    e.w32(me + 8, rnd(c, 0x40))
    e.w32(me + 0xc, rnd(c, 8))
    return [me, rnd(c, 0x20), r.getrandbits(32)]


def g44d200(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    R = r.getrandbits(32)
    sysobj(c, table_slots={0x50: pystub(c, 1, this=True, ret=R)})
    b = r.getrandbits(32)
    me = rnd(c, 0x40)
    n = r.choice([0, 1, 2, 4, 6])
    tab = e.alloc(4 * 8, 4)
    for i in range(n):
        el = rnd(c, 0x20)
        e.w32(el + 0x10, R if r.random() < 0.5 else r.getrandbits(32))
        e.w32(el + 0xc, b if r.random() < 0.5 else r.getrandbits(32))
        e.w32(tab + 4 * i, el)
    e.w32(me + 0x1c, n)
    e.w32(me + 0x20, tab)
    return [me, r.getrandbits(32), b]


def _dtor(base, size, extra):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        hook_rec(c, 0x634273, 2, pop=0)
        hook_rec(c, base, 0, this=True)
        hook_rec(c, 0x45c510, 1, pop=0)
        hook_rec(c, 0x4690b0, 2, pop=0)
        me = rnd(c, 0x100)
        extra(c, me)
        return [me, r.choice([0, 1, 4, 5, 2, 0x100, r.getrandbits(32)])]
    return g


def _x44ee60(c, me):
    for off in (0x8c, 0xac, 0xb0):
        c.emu.w32(me + off, c.rng.getrandbits(32))


def _x454b00(c, me):
    c.emu.w32(me + 0x5c, obj(c, 0x20, {0: pystub(c, 1, this=True)}) if c.rng.random() < 0.7 else 0)


def _x457340(c, me):
    c.emu.w32(me + 0x4c, c.rng.choice([0, c.rng.getrandbits(32)]))


def g4571f0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de40, 3, this=True)
    return [rnd(c, 0xe0), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g457610(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dd060, 1, this=True)
    hook_rec(c, 0x4dce50, 1, this=True)
    me = rnd(c, 0x80)
    o = rnd(c, 0x80)
    for off in (0x40, 0x44, 0x48):
        c.emu.w32(o + off, _fb(r) if r.random() < 0.9 else 0)
    c.emu.w32(me + 8, o)
    return [me]


def g45b1c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x610100, 1, this=True)
    hook_rec(c, 0x4e12f0, 2, this=True)
    hook_rec(c, 0x4e1b30, 0, this=True)
    me = obj(c, 0x80, {0xb4: pystub(c, 1, this=True)})
    return [me, rnd(c, 0x40)]


def g45bf40(c):
    clear_hooks(c)
    r = c.rng
    lg = obj(c, 0x20, {0x60: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=lg),
                           0x4c: pystub(c, 2, this=True, ret=rl(r, 4, lambda: r.getrandbits(32)))})
    hook_rec(c, 0x45f3c0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x55]))
    me = obj(c, 0x80, {0x214: pystub(c, 0, this=True)})
    return [me, r.getrandbits(32)]


def g4859c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x469870, 0, this=True)
    so = sysobj(c)
    tbl = e.r32(so + 0x9b)
    blk = rnd(c, 0x100)
    ret = 0 if r.random() < 0.2 else blk
    e.w32(tbl + 8, obj(c, 0x40, {0x44: pystub(c, 0, ret=ret)}))
    return [rnd(c, 0x10)]


S(0x449730, 'GUESS record fetch, set +0x10, apply', 'thiscall', None, ret=None, gen=_rec_group(0x88, 0xa8, 0x3c, []), note='batch2616')
S(0x449b50, 'GUESS record fetch, set +0x14, apply, slot 0x220', 'thiscall', None, ret=None, gen=_rec_group(0x84, 0xa0, 0x38, [0x220]), note='batch2616')
S(0x449bc0, 'GUESS record fetch, set +0x14, apply, slot 0x220', 'thiscall', None, ret=None, gen=_rec_group(0x88, 0xa8, 0x3c, [0x220]), note='batch2616')
S(0x449c30, 'GUESS record fetch, set +0x18, apply', 'thiscall', None, ret=None, gen=_rec_group(0x80, 0x98, 0x24, []), note='batch2616')
S(0x44a0e0, 'GUESS three calls on member (cookie)', 'thiscall', None, ret=None, gen=g44a0e0, note='batch2616')
S(0x44a8c0, 'GUESS ctor (SEH)', 'thiscall', None, ret='eax', gen=g44a8c0, note='batch2616')
S(0x44c180, 'GUESS log a record name', 'thiscall', None, ret=None, gen=g44c180, note='batch2616')
S(0x44d200, 'GUESS find index by key', 'thiscall', None, ret='eax', gen=g44d200, note='batch2616')
S(0x44ee60, 'GUESS scalar deleting dtor (0xd1)', 'thiscall', None, ret='eax', gen=_dtor(0x43de70, 0xd1, _x44ee60), note='batch2616')
S(0x454b00, 'GUESS scalar deleting dtor (0x60)', 'thiscall', None, ret='eax', gen=_dtor(0x43ea20, 0x60, _x454b00), note='batch2616')
S(0x4571f0, 'GUESS ctor with field defaults', 'thiscall', None, ret='eax', gen=g4571f0, note='batch2616')
S(0x457340, 'GUESS scalar deleting dtor (0xbc)', 'thiscall', None, ret='eax', gen=_dtor(0x451a00, 0xbc, _x457340), note='batch2616')
S(0x457610, 'GUESS length plus one', 'thiscall', None, ret=None, gen=g457610, note='batch2616')
S(0x45b1c0, 'GUESS read three out-params', 'thiscall', None, ret=None, gen=g45b1c0, note='batch2616')
S(0x45bf40, 'GUESS log and update', 'thiscall', None, ret='al', gen=g45bf40, note='batch2616')
S(0x4859c0, 'GUESS SEH alloc and init (naked frame)', 'thiscall', None, ret='eax', gen=g4859c0, note='batch2616')
