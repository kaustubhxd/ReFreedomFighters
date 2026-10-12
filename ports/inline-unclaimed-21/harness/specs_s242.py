"""specs_s242.py - batch242 (0x574680, stdcall(A, B, G, D, F), ret 0x14). The libm IAT stubs (tan, atan) come from the
harness (Python math on both sides). Hooks: child vt 0x58 returns E; E's vt 0x224 logs its float argument; E's vt 0x70 logs ecx
and the three dwords its pointer addresses (a stack block, read through the pointer, never logged as an address); 0x4db7c0
(thiscall, one word) logs ecx and its word. The floats are passed as F(x) (single precision)."""
import struct
from pilot import S, F
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _ring(c, nwords, ret_bytes, val=None):
    n = 1 + nwords
    ring = c.emu.alloc(4 * n * 8, 4)
    c.emu.wbytes(ring, bytes(4 * n * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
    for k in range(nwords):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x50' + bytes([4 * (k + 1)])
    body += b'\x83\x05' + struct.pack('<I', ptr) + bytes([4 * n])
    if val is not None:
        body += b'\xb8' + struct.pack('<I', val & 0xffffffff)
    return ss.code(c, body + b'\xc2' + struct.pack('<H', ret_bytes))


def _ring70(c):
    """thiscall with one pointer (ret 4): logs ecx and the three dwords the pointer addresses."""
    ring = c.emu.alloc(4 * 4 * 8, 4)
    c.emu.wbytes(ring, bytes(4 * 4 * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = (b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
            + b'\x8b\x54\x24\x04' + b'\x8b\x12' + b'\x89\x50\x04'
            + b'\x8b\x54\x24\x04' + b'\x8b\x52\x04' + b'\x89\x50\x08'
            + b'\x8b\x54\x24\x04' + b'\x8b\x52\x08' + b'\x89\x50\x0c'
            + b'\x83\x05' + struct.pack('<I', ptr) + b'\x10'
            + b'\xc2\x04\x00')
    return ss.code(c, body)


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _plant_tie(c, gval, e5c):
    """A D whose xm2 = (float)(dn / tan(e5c * 0.5)) equals 20000.0f exactly (search with the port's float steps), or None."""
    import math
    xm0 = _f32(1.0 - _f32(gval + gval))
    s_ = _f32(e5c * 0.5)
    t = math.tan(s_)
    if t == 0.0:
        return None
    target = _f32(20000.0)
    base = target * t * xm0
    for k in range(-400, 401):
        d = _f32(base * (1.0 + k * 1e-7))
        dn = _f32(d / xm0)
        xm2 = _f32(dn / t)
        if xm2 == target:
            return d
    return None


def _gen(c):
    A = c.rng.getrandbits(32)
    B = _rnd(c, 0x40)
    M = _rnd(c, 0x40)
    c.emu.w32(B + 8, M)
    for off in (0x30, 0x38):
        c.emu.wbytes(M + off, struct.pack('<f', c.rng.uniform(-3.0, 3.0)))
    Dp = _rnd(c, 0x40)
    c.emu.wbytes(Dp, struct.pack('<f', c.rng.uniform(-300.0, 300.0)))
    tie_g = c.rng.uniform(-0.5, 0.5)
    tie_e = c.rng.uniform(-300.0, 300.0)
    E = _rnd(c, 0x100)
    e5c = c.rng.uniform(-300.0, 300.0)
    c.emu.wbytes(E + 0x5c, struct.pack('<f', e5c))
    Evt = c.emu.alloc(0x300, 4)
    c.emu.w32(Evt + 0x224, _ring(c, 1, 4))
    c.emu.w32(Evt + 0x70, _ring70(c))
    c.emu.w32(E, Evt)
    child = ss.mkobj(c, {0x58: _ring(c, 1, 4, val=E)}, size=0x40)
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x9b, child)
    c.emu.w32(0x70039c, rm)
    ss.patch(c, 0x4db7c0, _ring(c, 1, 4))
    _flush(c)
    g = c.rng.uniform(-0.5, 0.5)
    if c.rng.random() < 0.5:
        d_tie = _plant_tie(c, tie_g, tie_e)
        if d_tie is not None:
            c.emu.wbytes(Dp, struct.pack('<f', d_tie))
            c.emu.wbytes(E + 0x5c, struct.pack('<f', tie_e))
            g = tie_g
    f = 0.0 if c.rng.random() < 0.15 else c.rng.uniform(-3.0, 3.0)
    return [A, B, F(g), Dp, F(f)]


S(0x574680, 'blockUpdate574 (GUESS)', 'stdcall', None, ret=None, gen=_gen,
  note='batch242; child vt 0x58, 0x4db7c0 (stubbed), E vt 0x224 (if F > 0), tan / atan through the harness IAT stubs, vt 0x70')
