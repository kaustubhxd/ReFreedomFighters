"""specs_s242011.py - hand specs for two small hand-ported rows (Sonnet-w4b)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _pre(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32)))
    return r, c.emu, (lambda emu, k: r.getrandbits(32))


def g5c5910(c):
    r, em, R = _pre(c)
    lg = lambda tag, n: (lambda emu, k: emu.calllog.append((tag,) + tuple(emu.arg32(i) for i in range(n))))
    rv = lambda emu, k: r.choice([0, 1, 7, 100, 12345, 0x7fffffff, 0x80000000 | 5])
    L2 = obj(c, 0x40, {0x2c: pystub(c, 3, ret=R, pop=0, side=lg('l2c', 3))})
    em.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=L2, this=True, side=lg('l20', 2))}))
    P = obj(c, 0x200, {0x130: pystub(c, 2, ret=R, this=True, side=lg('p130', 2))})
    sysobj(c, slots={0x1bc: pystub(c, 2, ret=rv, this=True, side=lg('g1bc', 2))},
           table_slots={0x114: pystub(c, 5, ret=R, this=True, side=lg('t114', 5))})
    THIS = rnd(c, 0x80)
    em.w32(THIS + 0x44, P)
    cnt = r.choice([-3, 0, 1, 5, 9, 10, 0x7fffffff])
    em.w32(THIS + 0x4c, cnt & 0xffffffff)
    em.w32(THIS + 0x50, r.choice([-2, 0, 3, 5, 9, 10]) & 0xffffffff)
    em.w32(THIS + 0x48, r.choice([1, 2, 7, 64, 1000, 0xfffffffd]))
    return [THIS]


def g46e2d0(c):
    r, em, R = _pre(c)
    lg = lambda tag, n: (lambda emu, k: emu.calllog.append((tag, emu.reg('ecx')) + tuple(emu.arg32(i) for i in range(n))))
    L2 = obj(c, 0x40, {0x30: pystub(c, 3, ret=R, pop=0, side=lg('l30', 3))})
    em.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=L2, this=True)}))
    z = 0 if r.random() < 0.2 else 1
    sl = {0x328: pystub(c, 0, ret=z, this=True), 0x110: pystub(c, 2, ret=R, this=True, side=lg('s110', 2)),
          0x160: pystub(c, 0, ret=R, this=True, side=lg('s160', 0)), 0x304: pystub(c, 1, ret=R, this=True, side=lg('s304', 1))}
    THIS = obj(c, 0x200, sl)
    em.w32(THIS + 4, 0 if r.random() < 0.3 else r.getrandbits(32))
    em.w32(THIS + 0xd5, r.choice([0, 1, 2, 3, 4, 7, 0xffffffff]))
    em.w32(THIS + 0xba, r.choice([-3, 0, 1, 2, 3, 5, 9]) & 0xffffffff)
    em.w32(THIS + 0xc4, r.choice([-1, 0, 2, 4, 8]) & 0xffffffff)
    em.wbytes(THIS + 0xbf, bytes([r.choice([0, 1, 1, 0x80])]))
    return [THIS]


def g584480(c):
    r, em, R = _pre(c)
    lg = lambda tag, n: (lambda emu, k: emu.calllog.append((tag, emu.reg('ecx')) + tuple(emu.arg32(i) for i in range(n))))
    L2 = obj(c, 0x40, {0x2c: pystub(c, 2, ret=R, pop=0, side=lg('l2c', 2))})
    em.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=L2, this=True, side=lg('l20', 2))}))
    hook_rec(c, 0x4dbe30, 1, ret=R, this=True)
    hook_rec(c, 0x4dc440, 1, ret=R, this=True)
    def child():
        ch = obj(c, 0x300, {0x224: pystub(c, 1, ret=R, this=True, side=lg('c224', 1)), 0x24: pystub(c, 1, ret=R, this=True, side=lg('c24', 1))})
        em.w32(ch + 8, rnd(c, 0x20))
        return ch
    kids = [child() if r.random() < 0.75 else 0 for _ in range(2)]
    P = obj(c, 0x300, {0x25c: pystub(c, 2, ret=lambda emu, k: kids[min(k, 1)], this=True, side=lg('p25c', 2))})
    so = sysobj(c, table_slots={0x4c: pystub(c, 1, ret=R, this=True, side=lg('t4c', 1))})
    tbl = em.r32(so + 0x9b)
    tbl2 = rnd(c, 0xb10); vt = em.alloc(0x300, 4)
    em.w32(vt + 0x4c, em.r32(em.r32(tbl) + 0x4c)); em.w32(tbl2, vt); em.w32(so + 0x9b, tbl2)
    Z = obj(c, 0x300, {0x288: pystub(c, 3, ret=R, this=True, side=lg('z288', 3))})
    em.w32(tbl2 + 0xadc, Z)
    THIS = rnd(c, 0x400)
    em.w32(THIS + 0x44, P)
    return [THIS]


import struct, math


def _f2u(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def g4b5db0(c):
    from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1
    r, em, R = _pre(c)
    def powh(e, rr):
        x = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
        y = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
        try:
            z = math.pow(x, y)
        except (ValueError, ZeroDivisionError):
            z = float('nan')
        except OverflowError:
            z = float('inf')
        e.calllog.append(('pow', struct.pack('<d', x), struct.pack('<d', y)))
        e.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
        e.ret()
    em.stub_import('_libm_sse2_pow_precise', powh)
    fl = lambda emu, k: r.choice([-2.0, -0.5, 0.0, 0.5, 1.0, 3.0, 100.0])
    ints = lambda emu, k: (r.randrange(0, 6) if r.random() < 0.6 else r.randrange(-40, 4000)) & 0xffffffff
    hook_rec(c, 0x4e5e60, 0, ret=ints, this=True)
    hook_rec(c, 0x4e5e80, 0, ret=R, this=True, st0=fl)
    names = [b'data/ui/icons/flag.tga', b'a/b/cdef', b'xx/yy/zzzzz.bmp', b'/x/12345', b'a//bbbbbb', b'p/q/rrrr', b'one/two/three/four.png']
    nm = r.choice(names)
    pth = rnd(c, 0x80); em.wbytes(pth, nm + b'\0')
    X = obj(c, 0x40, {0x78: pystub(c, 1, ret=lambda emu, k: pth if r.random() < 0.85 else 0, this=True, side=lambda emu, k: emu.calllog.append(('x78', emu.arg32(0))))})
    so = sysobj(c)
    em.w32(so + 0x1a9f, X if r.random() < 0.85 else 0)
    buf = rnd(c, 8)
    em.wbytes(buf, bytes([r.choice([0xff, 3, 0x43, 2, 0x42, 0, 0x3f])]))
    stream = rnd(c, 0x10); em.w32(stream, buf)
    THIS = rnd(c, 0x200)
    return [THIS, stream]


def g4c2c00(c):
    from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1
    r, em, R = _pre(c)
    def powh(e, rr):
        x = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
        y = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
        try:
            z = math.pow(x, y)
        except (ValueError, ZeroDivisionError):
            z = float('nan')
        except OverflowError:
            z = float('inf')
        e.calllog.append(('pow', struct.pack('<d', x), struct.pack('<d', y)))
        e.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
        e.ret()
    em.stub_import('_libm_sse2_pow_precise', powh)
    lg = lambda tag, n: (lambda emu, k: emu.calllog.append((tag, emu.reg('ecx')) + tuple(emu.arg32(i) for i in range(n))))
    fl = lambda emu, k: r.choice([0.0, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0])
    hook_rec(c, 0x44c230, 1, ret=R, this=True)
    tabs = obj(c, 0x40, {0x2c: pystub(c, 0, ret=lambda emu, k: r.choice([0, 1, 0x100, 1]), this=True, side=lg('t2c', 0))})
    so = sysobj(c, slots={0x1c0: pystub(c, 2, st0=fl, this=True, side=lg('rand', 2))})
    tbl = rnd(c, 0x40); vtt = em.alloc(0x40, 4); em.w32(vtt + 0x2c, em.r32(em.r32(tabs) + 0x2c)); em.w32(tbl, vtt); em.w32(so + 0x9b, tbl)
    A = rnd(c, 0x100)
    C = obj(c, 0x40, {0x218: pystub(c, 1, ret=R, this=True, side=lg('c218', 1))})
    em.w32(C + 0x18, A); em.w32(C + 0x1c, r.choice([0, 1, 1, 1]) * 5)
    sl = {0x64: pystub(c, 1, ret=R, this=True, side=lg('s64', 1)), 0x68: pystub(c, 2, ret=R, this=True, side=lg('s68', 2))}
    THIS = obj(c, 0x100, sl)
    em.w32(THIS + 0x44, C if r.random() < 0.95 else 0)
    fv = lambda: _f2u(r.choice([0.0, 0.0, 0.5, 1.0, -1.0, 2.5, -3.0, 100.0]))
    for off in (0x48, 0x54, 0x60):
        em.w32(THIS + off, fv())
    em.wbytes(THIS + 0x69, struct.pack('<f', r.choice([0.0, 0.5, 2.0, -1.0, -4.0])))
    for off in (0x4c, 0x50, 0x6d, 0x71, 0x75, 0x79, 0x7d):
        em.wbytes(THIS + off, struct.pack('<I', r.choice([0, 0, 1, 3, 7, 0x1234, 0xffffffff])))
    em.w32(THIS + 0x64, r.choice([0, 0, 1, 2, 3, 0xffffffff]))
    em.wbytes(THIS + 0x68, bytes([r.choice([0, 1])]))
    return [THIS]


def g40d060(c):
    r, em, R = _pre(c)
    N = r.choice([1, 2, 3, 4, 5, 6, 7, 8, 9])
    M = r.choice([0, 1, 1, 2, 3, 5])
    tot = N * M
    def fl():
        k = r.random()
        if k < 0.1: return 0.0
        if k < 0.15: return -0.0
        return r.choice([-1, 1]) * r.uniform(0.001, 50.0)
    src = rnd(c, 4 * (2 * tot) + 16)
    for j in range(2 * tot): em.wbytes(src + 4 * j, struct.pack('<f', fl()))
    dst = rnd(c, 4 * (2 * tot) + 32)
    tw = rnd(c, 4 * (N + 6))
    for j in range(N + 6): em.wbytes(tw + 4 * j, struct.pack('<f', r.uniform(-1.0, 1.0)))
    return [N, M, src, dst, tw]


def g4a1e00(c):
    from unicorn.x86_const import UC_X86_REG_EDX
    r, em, R = _pre(c)
    lg = lambda tag, n: (lambda emu, k: emu.calllog.append((tag, emu.reg('ecx')) + tuple(emu.arg32(i) for i in range(n))))
    def s1c8(emu, k):
        emu.calllog.append(('s1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    hook_rec(c, 0x4db670, 1, ret=R, this=True, nullflag=(0,), side=lambda emu, k: [emu.w32(emu.arg32(0) + 4 * j, r.getrandbits(32)) for j in range(3) if r.random() < 0.5])
    hook_rec(c, 0x4a21b0, 2, ret=R, this=True, nullflag=(1,), deref=None, side=lambda emu, k: emu.calllog.append(('a21b0', emu.arg32(0)) + tuple(emu.r32(emu.arg32(1) + 4 * j) for j in range(3))))
    X = rnd(c, 0x40)
    so = sysobj(c, slots={0x1c8: pystub(c, 2, ret=R, this=True, side=s1c8),
                          0x178: pystub(c, 3, ret=R, this=True, side=lg('s178', 3)),
                          0x17c: pystub(c, 3, ret=R, this=True, side=lg('s17c', 3))},
                table_slots={0x54: pystub(c, 1, ret=lambda emu, k: X if r.random() < 0.8 else 0, this=True, side=lg('t54', 1))})
    fz = lambda: struct.pack('<f', r.choice([0.0, 0.0, 1.0, -2.0]))
    em.wbytes(so + 0x9c7, fz()); em.wbytes(so + 0x9c3, fz())
    THIS = rnd(c, 0x900)
    em.w32(THIS, r.getrandbits(32))
    for k in range(8):
        v = r.choice([0.0, 0.0, 0.5, 1.0, 3.0, -1.0, 0.001, 0.002, 10.0, 0.3])
        em.wbytes(THIS + 0x824 + 4 * k, struct.pack('<f', v))
    # exact ties: accumulator = -(K / divisor) makes the new value exactly 0.0 (== the initial best)
    Kc = struct.unpack('<f', bytes(em.rbytes(0x678858, 4)))[0]
    allties = r.random() < 0.15
    for k in range(8):
        if allties or r.random() < 0.25:
            dk = struct.unpack('<f', struct.pack('<f', float((1 << k) * 500 + 1)))[0]
            q = struct.unpack('<f', struct.pack('<f', Kc / dk))[0]
            em.wbytes(THIS + 0x824 + 4 * k, struct.pack('<f', -q))
    return [THIS]


S(0x5c5910, 'GUESS countdown reroll', 'thiscall', None, ret='eax', gen=g5c5910, note='batch242011')
S(0x46e2d0, 'GUESS state clamp dispatch', 'thiscall', None, ret='eax', gen=g46e2d0, note='batch242011')
S(0x584480, 'GUESS attach two children', 'thiscall', None, ret='eax', gen=g584480, note='batch242011')
S(0x4b5db0, 'GUESS read record with path', 'thiscall', None, ret='eax', gen=g4b5db0, note='batch242011')
S(0x4c2c00, 'GUESS push record into target', 'thiscall', None, ret=None, gen=g4c2c00, note='batch242011')
S(0x40d060, 'GUESS fft butterfly pass', 'cdecl', None, ret=None, gen=g40d060, note='batch242011')
S(0x4a1e00, 'GUESS weighted slot pick', 'thiscall', None, ret=None, gen=g4a1e00, note='batch242011')
