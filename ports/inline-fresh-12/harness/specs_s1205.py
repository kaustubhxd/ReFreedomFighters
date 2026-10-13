"""specs_s1205.py - fresh slice 12, batch 5 (7 functions). Exe callees hooked by address and logged; iterator calls
that take a pointer to a stack local write/read it in Python and log only values, never the stack address."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, rand_fast, hk, hk_cdecl, done, com_obj


def _g4ce480(c):
    mode = c.rng.choice([0, 1, 2])
    cells = [zero_obj(c, 4) for _ in range(4)]
    seq = [0]

    def s18(em, r):
        em.calllog.append(('S', 0x18, em.reg('ecx'), ()))
        v = 1 if mode == 1 else (0 if mode == 0 else (seq[0] & 1) * 1)
        seq[0] += 1
        em.ret(eax=v if v else c.rng.choice([0, 2]) if False else v, argbytes=0)

    def s4(em, r):
        em.calllog.append(('S', 4, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=cells[seq[0] % 4], argbytes=4)
    s = zero_obj(c, 0x20)
    c.emu.w32(s, c.emu.fake_vtable('S', 0x10, {0x18: s18, 4: s4}))
    o = rand_obj(c, 0x10)
    n = c.rng.choice([0, 1, 2, 4])
    arr = rand_obj(c, 8 * 4 + 8)
    c.emu.w32(o + 4, arr)
    c.emu.w32(o + 8, n)
    return done(c, [o, s])


S(0x4ce480, 'FUN_004ce480 stream pair list', 'thiscall', None, ret=None, gen=_g4ce480)


def _s455080(c):
    c.emu.hook(0x4cc850, lambda em, r: (em.calllog.append(('f4cc850', 0, em.reg('ecx'), (em.reg('edx'),))),
                                        em.ret(eax=em.case_r, argbytes=0)))


def _g455080(c):
    c.emu.case_r = c.rng.choice([0, 1, 0x80000000])
    inner = rand_obj(c, 0x30)
    if c.rng.random() < 0.4:
        c.emu.w32(inner + 0x23, 0x1000f0)
    d = logged_obj(c, 'D', 0x100, impl={0x2c4: lambda e, a: (0x2c4 ^ a[0], None)}, argwords={0x2c4: 1})
    c.emu.w32(d + 0xc, inner)
    c.emu.w32(d + 4, c.rng.choice([0, rand_obj(c, 8)]))
    o = logged_obj(c, 'O', 0x10, impl={0x20: lambda e, a: (d, None)})
    lst = logged_obj(c, 'L', 0x10, impl={4: lambda e, a: (0x44 ^ a[0], None)}, argwords={4: 1})
    en = zero_obj(c, 0xb10)
    c.emu.w32(en + 0xb00, c.emu.r32(lst))   # embedded list object: its vtable word at +0xb00
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return done(c, [o])


S(0x455080, 'FUN_00455080 type check then register (engine+0xb00 slot 4)', 'thiscall', None, ret='eax',
  setup=_s455080, gen=_g455080)


def _g423440(c):
    k = c.rng.choice([0, 1, 2, 3, 5])
    nodes = []
    for i in range(k):
        f = c.rng.choice([0, 0, 1, 0x100, 0x101])
        nodes.append(logged_obj(c, 'N%d' % i, 4, impl={4: lambda e, a, f=f: (0xabcd00 | f, None)}))
    live = list(nodes)
    st = {'i': 0}

    def l4c(em, r):
        p = em.arg32(0)
        em.calllog.append(('L', 0x4c, 0, ()))
        st['i'] = 0
        em.w32(p, 0x77)
        em.ret(eax=0, argbytes=4)

    def l5c(em, r):
        p = em.arg32(0)
        em.calllog.append(('L', 0x5c, 0, (em.r32(p),)))
        if st['i'] < len(live):
            n = live[st['i']]
            st['i'] += 1
            em.w32(p, 1)
        else:
            n = 0x5c5c
            em.w32(p, 0)
        em.ret(eax=n, argbytes=4)

    def t4c(em, r):
        n = em.arg32(0)
        em.calllog.append(('T', 0x4c, em.reg('ecx'), (n,)))
        if n in live:
            live.remove(n)
        em.ret(eax=0, argbytes=4)
    o = zero_obj(c, 0x21a0)
    c.emu.w32(o, c.emu.fake_vtable('T', 0x20, {0x4c: t4c}))
    c.emu.w32(o + 0x2191, c.emu.fake_vtable('L', 0x20, {0x4c: l4c, 0x5c: l5c}))
    return done(c, [o])


S(0x423440, 'FUN_00423440 purge list at +0x2191', 'thiscall', None, ret=None, gen=_g423440)


def _g578c00(c):
    seq = [c.rng.getrandbits(32)]

    def h(em, r):
        em.calllog.append(('f4e5e60', 0, em.reg('ecx'), ()))
        seq[0] = (seq[0] * 1103515245 + 12345) & 0xffffffff
        em.ret(eax=seq[0], argbytes=0)
    c.emu.hook(0x4e5e60, h)
    return done(c, [rand_obj(c, 0x1a0), rand_obj(c, 0x10)])


S(0x578c00, 'FUN_00578c00 read six values', 'thiscall', None, ret=None, gen=_g578c00, note='0x610100 runs (empty, ret 4)')


def _g435dc0(c):
    o = rand_obj(c, 0x64)
    for base, cnt_off, mx in ((4, 0xc, 2), (0x10, 0x1c, 3), (0x20, 0x60, 16)):
        n = c.rng.randrange(0, mx + 1)
        for i in range(n):
            c.emu.w32(o + base + 4 * i, logged_obj(c, 'X%x_%d' % (base, i), 0x10, argwords={0x24: 1}))
        c.emu.w32(o + cnt_off, n)
    return done(c, [o])


S(0x435dc0, 'FUN_00435dc0 slot 0x24(0) on three arrays', 'thiscall', None, ret=None, gen=_g435dc0)


