"""specs_s1216.py - fresh slice 12, batch 16."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, done


def g_4fa800(c):
    o = 0
    if c.rng.random() < 0.7:
        o = rand_obj(c, 0x10)
        arr = c.emu.alloc(0x80, 4)
        c.emu.wbytes(arr, b''.join(struct.pack('<f', c.rng.choice([c.rng.uniform(-1e5, 1e5), c.rng.uniform(-2, 2), c.rng.uniform(0, 1), 3e9, -3e9, float(c.rng.randrange(-3, 4))])) for _ in range(0x20)))
        c.emu.w32(o + 8, arr)
    e = logged_obj(c, 'Eng', 0x20, impl={0x58: lambda em, a: (o, None)}, argwords={0x58: 1})
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, e)
    set_global(c, 0x70039c, eng)
    ctl = logged_obj(c, 'Ctl', 0x100, argwords={0x350: 3, 0x34c: 5})
    self_ = rand_obj(c, 0xc0)
    c.emu.w32(self_, c.emu.logging_vtable('Self', 0xc0, impl={0x2c4: lambda em, a: (ctl, None)}))
    c.emu.w32(self_ + 0x8f, c.rng.randrange(0, 0x10))
    return done(c, [self_, c.rng.getrandbits(32)])


def g_49a040(c):
    n = c.rng.randrange(0, 6)
    elems = [rand_obj(c, 8) for _ in range(n)]
    qs = [rand_obj(c, 8) for _ in range(n)]
    cnt = c.rng.getrandbits(32)

    def h(name, nargs, fn):
        def f(em, r):
            args = tuple(em.arg32(k) for k in range(nargs))
            em.ret(eax=fn(em, args), argbytes=4 * nargs)
        return f

    def start(em, a):
        em.calllog.append(('start', 0, 0, ()))   # the iterator is a stack local: log the call, not its address
        em.w32(a[0], 0)
        return 0

    def step(em, a):
        k = em.r32(a[0])
        em.calllog.append(('next', 0, 0, (k,)))
        if k < n:
            em.w32(a[0], k + 1)
            return elems[k]
        return 0

    def get(em, a):
        em.calllog.append(('get', 0, 0, a))
        return qs[elems.index(a[0])] if a[0] in elems else 0

    def count(em, a):
        em.calllog.append(('count', 0, 0, ()))
        return cnt
    src = zero_obj(c, 0x10)
    c.emu.w32(src, c.emu.fake_vtable('Src', 0x30, {0x14: h('count', 0, count), 0x4c: h('start', 1, start),
                                                   0x64: h('next', 1, step), 0x9c: h('get', 1, get)}))
    self_ = logged_obj(c, 'Dst', 0x20, argwords={0xc: 1, 0x3c: 1, 0x4c: 1})
    return done(c, [self_, src])


S(0x4fa800, 'FUN_004fa800 set target id (controller slots 0x350 / 0x34c)', 'thiscall', None, ret=None, gen=g_4fa800)
S(0x49a040, 'FUN_0049a040 copy point list from src', 'thiscall', None, ret=None, gen=g_49a040)
