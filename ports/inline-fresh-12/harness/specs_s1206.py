"""specs_s1206.py - fresh slice 12, batch 6 (7 functions). Exe callees hooked by address and logged."""
import struct
from unicorn.x86_const import UC_X86_REG_EDX
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, rand_fast, hk, hk_cdecl, done, com_obj


def _f(c, o, off, v):
    c.emu.wbytes(o + off, struct.pack('<f', v))


def _g4b0e80(c):
    o = rand_obj(c, 0x70)
    c.emu.w8(o + 0x6c, c.rng.choice([0, 0, 0, 1]))
    eng = zero_obj(c, 0x1b00)
    c.emu.w32(eng + 0x1a9f, c.rng.choice([0, 1, 1, 1]))
    start = c.rng.getrandbits(32)
    c.emu.w32(o + 0x50, start)
    dt = c.rng.choice([0, 10, 1000, 5000, 20000, c.rng.getrandbits(32)])
    c.emu.w32(eng + 0x40, (start + dt) & 0xffffffff)
    for off in (0x54, 0x58, 0x5c):
        _f(c, o, off, c.rng.choice([c.fv(-5.0, 30.0), float(c.rng.randrange(0, 25)), float('nan')]))
    if c.rng.random() < 0.25 and dt < 0x7fffffff // 25:   # hi exactly at t, with a non-positive window width
        t = struct.unpack('<f', struct.pack('<f', float(dt * 25 >> 10 if dt * 25 < 2**31 else 0) / 1024.0))[0]
        _f(c, o, 0x58, t)
        _f(c, o, 0x54, c.rng.choice([0.0, -1.0, 2.0]))
        _f(c, o, 0x5c, c.rng.choice([-1.0, t]))
    set_global(c, 0x70039c, eng)
    return done(c, [o])


S(0x4b0e80, 'FUN_004b0e80 window timeout flag', 'thiscall', None, ret=None, gen=_g4b0e80)


def _g6211c0(c):
    r = c.rng.choice([0, 0, 0, 1, 0x16])
    grow = c.rng.choice([0, 1])
    c.emu.hook(0x61c790, hk_cdecl(0x61c790, 'f61c790', 6, lambda em: r))
    s = rand_obj(c, 0x14)
    buf = rand_obj(c, 0x10)
    if c.rng.random() < 0.5:
        c.emu.w8(buf + 4, 0x20)
    used = c.rng.choice([0, 3, 5, 8])
    c.emu.w32(s + 0x10, buf)
    c.emu.w32(s + 0xc, buf + used)
    c.emu.w32(s + 8, buf + c.rng.choice([used, 8, 12]))

    def g(em, r_):
        em.calllog.append(('grow', 0, 0, (em.arg32(0),)))
        em.ret(eax=grow, argbytes=0)
    c.emu.hook(0x6206e0, g)
    return done(c, [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.choice([0, 1]), c.rng.getrandbits(32),
                    c.rng.getrandbits(32), s])


S(0x6211c0, 'FUN_006211c0 format then terminate buffer', 'cdecl', None, ret='eax', gen=_g6211c0)


def _g494b40(c):
    lo, hi = c.rng.getrandbits(32), c.rng.getrandbits(32)

    def s1c8(em, r):
        em.calllog.append(('Eng', 0x1c8, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.mu.reg_write(UC_X86_REG_EDX, hi)
        em.ret(eax=lo, argbytes=8)

    def s184(em, r):
        em.calllog.append(('Obj', 0x184, 0, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=0, argbytes=0)
    ob = zero_obj(c, 0x10)
    c.emu.w32(ob, c.emu.fake_vtable('Obj', 0x70, {0x184: s184}))

    def s190(em, r):
        em.calllog.append(('Eng', 0x190, em.reg('ecx'), ()))
        em.ret(eax=ob, argbytes=0)
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng, c.emu.fake_vtable('Eng', 0x80, {0x1c8: s1c8, 0x190: s190}))
    gen = c.rng.getrandbits(32)
    c.emu.w32(eng + 0x3c, gen)
    set_global(c, 0x70039c, eng)
    o = rand_obj(c, 0x10)
    if c.rng.random() < 0.4:
        c.emu.w32(o, gen)
    return done(c, [o, c.rng.getrandbits(32)])


S(0x494b40, 'FUN_00494b40 refresh generation and 64-bit stamp', 'thiscall', None, ret=None, gen=_g494b40)


def _gpair(c):
    o = rand_obj(c, 0x10)
    tgt = logged_obj(c, 'Tgt', 0x30, argwords={0x8c: 2, 0x88: 2})
    mode = c.rng.choice([0, 1, 2])   # 0: already set, 1: 0x553d00 sets it, 2: the log printer sets it
    if mode == 0:
        c.emu.w32(o + 0xc, tgt)
    else:
        c.emu.w32(o + 0xc, 0)

    def h553(em, r):
        em.calllog.append(('f553d00', 0, em.reg('ecx'), ()))
        if mode == 1:
            em.w32(em.reg('ecx') + 0xc, tgt)
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x553d00, h553)

    def p2c(em, r):
        em.calllog.append(('Printer', 0x2c, 0, (em.arg32(0), em.arg32(1))))
        em.w32(o + 0xc, tgt)
        em.ret(eax=0, argbytes=0)
    pr = zero_obj(c, 0x10)
    c.emu.w32(pr, c.emu.fake_vtable('Printer', 0x10, {0x2c: p2c}))
    log = logged_obj(c, 'Log', 0x10, impl={0x20: lambda e, a: (pr, None)}, argwords={0x20: 2})
    set_global(c, 0x700390, log)
    items = [rand_obj(c, 4), rand_obj(c, 4)]
    c.emu.hook(0x5003d0, hk(0x5003d0, 'f5003d0', 1, lambda em: items[em.arg32(0) & 1]))
    arg = rand_obj(c, 8)
    return done(c, [o, arg])


S(0x5537c0, 'FUN_005537c0 pair call slot 0x8c (msg 0x28c)', 'thiscall', None, ret=None, gen=_gpair)
S(0x555fc0, 'FUN_00555fc0 pair call slot 0x88 (msg 0x27c)', 'thiscall', None, ret=None, gen=_gpair)


def _g4bb4c0(c):
    c.emu.hook(0x44c2b0, hk(0x44c2b0, 'f44c2b0', 0))
    c.emu.hook(0x44c370, hk(0x44c370, 'f44c370', 0))
    o = rand_obj(c, 0x60)
    ctl = rand_obj(c, 0x24)
    c.emu.w8(ctl + 0x20, c.rng.choice([0, 1]))
    st = rand_obj(c, 0x80)
    c.emu.w32(st + 4, c.rng.choice([0, 1, 2]))
    c.emu.w32(ctl + 0x18, st)
    c.emu.w32(o + 0x44, ctl if c.rng.random() < 0.85 else 0)
    own = rand_obj(c, 0x1e0)
    c.emu.w8(own + 0x1dc, c.rng.choice([0, 1]))
    c.emu.w32(o + 0x55, c.rng.choice([0, own]))
    c.emu.w32(o + 0x51, c.rng.choice([0, logged_obj(c, 'F', 0x30)]))
    a, b = c.rng.getrandbits(16), c.rng.getrandbits(16)
    if c.rng.random() < 0.3:
        b = a
    c.emu.wbytes(o + 0x48, struct.pack('<HH', a, b))
    idv = c.rng.choice([a, b, c.rng.getrandbits(16)])
    return done(c, [o, idv | (c.rng.getrandbits(16) << 16), c.rng.getrandbits(32)])


S(0x4bb4c0, 'FUN_004bb4c0 controller id handler', 'thiscall', None, ret='eax', gen=_g4bb4c0)
