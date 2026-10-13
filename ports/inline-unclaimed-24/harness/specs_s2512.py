"""specs_s2512.py - decomp area 24, batch 2512.
0x4bc330 (GUESS camera/target follow update): thiscall, no args, plain ret. System object (0x70039c): +0x1a9f object whose slot 0xc0
returns the "camera" object (slot 0x80 (buf, S) recorder writing the 0x24-byte buf), +0x40 time. this+0x44 target: slot 0x94 (buf, S)
recorder writing S (3 floats), slot 0x70 (U). this slot 0x84 (), 0x88 (float, returns a float in ST0, pops 4), 0x8c (float, float).
The exe's own 0x441730/0x440530 (thiscall on 0x68fc84), 0x43e920, 0x4e0030, 0x4e0870 run as code; log10/pow are CRT IAT stubs
(pow stubbed here). Pointer arguments are recorded as 0/1 or by content so stack addresses do not matter."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _pow_stub(e, r):
    from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1
    x = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
    y = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
    try:
        z = float(x ** y) if not (x < 0 and y != int(y)) else float('nan')
    except (OverflowError, ZeroDivisionError, ValueError):
        z = float('inf')
    if isinstance(z, complex):
        z = float('nan')
    e.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    e.ret()


def f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _bc_for(D, pi):
    # a float bc with bc/pi == D exactly (float division), or None
    base = struct.unpack('<I', struct.pack('<f', f32(D * pi)))[0]
    for d in (0, 1, -1, 2, -2):
        v = struct.unpack('<f', struct.pack('<I', base + d))[0]
        if f32(v / pi) == D:
            return v
    return None


def _setedx(em, k):
    from unicorn.x86_const import UC_X86_REG_EDX
    em.mu.reg_write(UC_X86_REG_EDX, 0x1234567)


def _fv(r, lo, hi):
    k = r.random()
    if k < 0.04:
        return 0
    if k < 0.06:
        return 0x7fc00000
    return _fb(r.uniform(lo, hi))


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.stub_import('_libm_sse2_pow_precise', _pow_stub)
    big = r.random() < 0.5
    sc = r.choice([0.02, 0.1, 0.5, 2.0])

    def w80(em, k):
        buf = em.arg32(0)
        for i in range(9):
            em.w32(buf + 4 * i, _fv(r, -3, 3))

    bnd = r.random() < 0.3
    negthr = (not bnd) and r.random() < 0.15
    sx = r.choice([2.0, 3.0, -2.0, -3.0, 4.0]) if bnd else 0
    D = abs(sx - (0.5 if sx >= 0 else -0.5))
    pi = f32(3.1415927410125732)

    def w94(em, k):
        s = em.arg32(1)
        if bnd:
            em.w32(s, _fb(sx))
            em.w32(s + 4, 0)
            em.w32(s + 8, 0)
            return
        for i in range(3):
            if negthr and r.random() < 0.5:
                em.w32(s + 4 * i, r.choice([0, 0x80000000]))
            elif r.random() < 0.3:
                em.w32(s + 4 * i, _fv(r, -1, 1))
            else:
                em.w32(s + 4 * i, _fv(r, -sc * 4, sc * 4))

    cam = obj(c, 0x40, {0x80: pystub(c, 2, this=True, nullflag=(0,), deref={1: 3}, side=w80)})
    ssel = rnd(c, 0x20)
    st = [_fb(r.uniform(-2, 2)) for _ in range(8)]
    slot88 = pystub(c, 1, this=True, st0=lambda em, k: struct.unpack('<f', struct.pack('<I', st[k % 8]))[0])
    so = sysobj(c, slots={0x1c8: pystub(c, 2, this=True, ret=r.getrandbits(32), side=_setedx), 0x178: pystub(c, 3, this=True), 0x17c: pystub(c, 3, this=True)})
    if r.random() < 0.4:
        e.w32(so + 0x9c7, 0)
    o2 = obj(c, 0x20, {0xc0: pystub(c, 0, this=True, ret=(cam if r.random() < 0.92 else 0))})
    e.w32(so + 0x1a9f, o2 if r.random() < 0.93 else 0)
    e.w32(so + 0x40, r.choice([r.getrandbits(32), r.randint(0, 100000)]))
    tb = r.random() < 0.3
    tgt = obj(c, 0x40, {0x94: pystub(c, 2, this=True, nullflag=(0,), deref={1: 3}, side=w94),
                        0x70: pystub(c, 1, this=True, deref={0: 3})})
    me = obj(c, 0x100, {0x84: pystub(c, 0, this=True), 0x88: slot88,
                        0x8c: pystub(c, 2, this=True)})
    e.w32(me + 0x44, tgt)
    for off in (0x54, 0x58, 0x5c):
        e.w32(me + off, _fv(r, 0, 1.0) if r.random() < 0.8 else _fb(sc))
    e.w32(me + 0x60, r.getrandbits(32))
    e.w32(me + 0x70, r.choice([0, 1, 5]))
    e.w32(me + 0x74, _fb(r.uniform(-2, 2)))
    for off in (0x78, 0x7c, 0x80, 0x84, 0xc8, 0xcc):
        e.w32(me + off, _fb(r.uniform(0.1, 5.0)))
    # dead-band thresholds bc <= c0 in degrees-ish units, 7c above D
    e.w32(me + 0x7c, _fb(r.uniform(0.0, 3.0 if big else 0.5)))
    b = r.uniform(0.0, 3.0)
    e.w32(me + 0xbc, _fb(b * 3.14159))
    e.w32(me + 0xc0, _fb((b + r.uniform(0, 3.0)) * 3.14159))
    if bnd:
        e.w32(me + 0x54, _fb(0.5))
        e.w32(me + 0x58, _fb(100.0))
        e.w32(me + 0x5c, _fb(100.0))
        mode = r.choice(['7c', 'bc', 'c0', 'plain'])
        bcv = _bc_for(D, pi)
        e.w32(me + 0x7c, _fb(D if mode == '7c' else D * 2 + 1))
        if mode == 'bc' and bcv is not None:
            e.w32(me + 0xbc, _fb(bcv))
            e.w32(me + 0xc0, _fb(bcv * 2))
        elif mode == 'c0' and bcv is not None:
            e.w32(me + 0xbc, _fb(bcv * 0.25))
            e.w32(me + 0xc0, _fb(bcv))
    elif negthr:
        for off in (0x54, 0x58, 0x5c):
            e.w32(me + off, _fb(-r.uniform(0, 1)))
    e.w32(me + 0xa8, r.choice([0, 1, 2, 3, 4]))
    e.w32(me + 0xac, r.choice([0, 1, 1]))
    e.w32(me + 0xa4, _fb(r.uniform(0, 3000)))
    if tb:
        n = r.randint(0, 3000)
        e.w32(me + 0xa4, _fb(n / 1024.0))
        e.w32(so + 0x40, n + 0x51 + r.choice([-1, 0, 1]))
    e.wbytes(me + 0xd1, bytes(r.getrandbits(8) for _ in range(8)))
    return [me]


S(0x4bc330, 'GUESS camera/target follow update', 'thiscall', None, ret=None, gen=_gen, note='batch2512')
