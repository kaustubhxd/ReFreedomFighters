"""specs_c1004.py - camera batch 1004: UpdateShaking, ShakeCamera."""
import struct
from pilot import S
from camgen import rnd, fbits, f32, Log, handler, handler2, sys_with_mgr


def _fl(c, lo, hi, p=0.75):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0] if c.rng.random() < p else fbits(c)


def _shk(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x5ca460, handler2(c, log, 0x5ca460, 'v', eax=r.getrandbits(32)))
    cam = rnd(c, 0x600)
    for off in range(0x444, 0x450, 4):
        c.emu.w32(cam + off, fbits(c))
    for off in (0x4ba, 0x4be, 0x4c2, 0x4c6):
        c.emu.w32(cam + off, _fl(c, -0.05, 0.1))
    s = sys_with_mgr(c, 0x200)
    c.emu.w32(s + 0x48, _fl(c, 0, 0.05))

    def rand_h(e, res):
        log.put(0x1c0, e.reg('ecx'), e.arg32(0), e.arg32(1))
        e.ret(argbytes=8, st0=r.random() if r.random() < 0.9 else f32(c))
    sv = c.emu.fake_vtable('sys', 0x1c4 // 4, {0x1c0: rand_h})
    c.emu.w32(s, sv)
    return [cam]


S(0x5ccd10, 'ZFFCamera1::UpdateShaking (inferred)', 'thiscall', gen=_shk)


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


def _shake(c):
    r = c.rng
    log = Log(c)
    c.emu.stub_import('_libm_sse2_pow_precise', _pow_stub)
    cam = rnd(c, 0x600)
    for off in range(0x408, 0x414, 4):
        c.emu.w32(cam + off, _fl(c, -3000, 3000, 0.9))
    for off in (0x4ba, 0x4be, 0x4c2, 0x4c6):
        c.emu.w32(cam + off, _fl(c, -2, 2))
    v = c.emu.alloc(16, 4)
    for i in range(3):
        c.emu.w32(v + 4 * i, _fl(c, -3000, 3000, 0.9))
    g = c.emu.fake_object('geom', 0x10, slots={0x438: handler(log, 0x438, 0, eax=r.getrandbits(32))}) if r.random() < 0.8 else 0
    s = sys_with_mgr(c, 0x200)
    m = c.emu.fake_object('mgr', 0x40, slots={0x58: handler(log, 0x58, 1, eax=g)})
    c.emu.w32(s + 0x9b, m)
    from pe_emu import F
    a = struct.unpack('<f', struct.pack('<I', _fl(c, 0, 50)))[0]
    b = struct.unpack('<f', struct.pack('<I', _fl(c, 0, 8000) if r.random() < 0.8 else r.choice([0, 0x3a000000, 0x39000000])))[0]
    return [cam, v, F(a), F(b)]


S(0x5cc900, 'ZFFCamera1::ShakeCamera (inferred)', 'thiscall', gen=_shake)
