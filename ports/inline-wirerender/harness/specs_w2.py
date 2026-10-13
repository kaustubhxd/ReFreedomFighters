"""specs_w2.py - wire-render batch 2000: the ease-in / ease-out follower 0x662330 / 0x6623a0 / 0x6624d0 / 0x6621d0.
Float inputs cover equal values, tiny differences (the 1/8192 tolerance), zeros, NaN and infinities."""
import math
from pilot import S, f32, F


def _fv(c, lo, hi):
    r = c.rng.random()
    if r < 0.06:
        return f32(c.rng.choice([0.0, -0.0, math.nan, math.inf, -math.inf, 1.0, 1e-5, -1e-5, 1e-30]))
    return f32(c.rng.uniform(lo, hi))


def _ease(c):
    e = c.emu
    o = e.alloc(0x40, 4)
    e.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    cur = _fv(c, -300, 300)
    dst = cur if c.rng.random() < 0.15 else (cur + c.rng.choice([1e-5, -1e-5, 1e-4, 0.1, -0.1]) if c.rng.random() < 0.2 else _fv(c, -300, 300))
    e.wf32(o + 0, cur)
    e.wf32(o + 4, f32(dst))
    e.wf32(o + 8, _fv(c, -50, 50))
    e.wf32(o + 0xc, 0.0 if c.rng.random() < 0.2 else _fv(c, -80, 80))
    e.w8(o + 0x10, c.rng.getrandbits(1))
    e.wf32(o + 0x11, _fv(c, 0, 100))
    e.wf32(o + 0x15, _fv(c, -300, 300))
    e.wf32(o + 0x19, 0.0 if c.rng.random() < 0.1 else _fv(c, 0.01, 200))
    e.wf32(o + 0x1d, _fv(c, -20, 20))
    e.wf32(o + 0x21, 0.0 if c.rng.random() < 0.4 else _fv(c, 0.5, 120))
    e.wf32(o + 0x25, 0.0 if c.rng.random() < 0.05 else _fv(c, 0.05, 4))
    e.wf32(o + 0x29, 0.0 if c.rng.random() < 0.03 else _fv(c, 0.002, 0.1))
    # exact-equality cases (a float compare at its boundary): gap == the 1/8192 constant, new speed == the maximum / minimum speed
    r = c.rng.random()
    if r < 0.12:
        e.wf32(o + 0, 0.0)
        e.wf32(o + 4, c.rng.choice([1 / 8192, -1 / 8192]))
    elif r < 0.30:
        import struct as _s
        f = lambda x: _s.unpack('<f', _s.pack('<f', x))[0]
        acc, dt, vel = (_s.unpack_from('<f', bytes(c.emu.mu.mem_read(o + k, 4)))[0] for k in (8, 0x29, 0xc))
        try:
            nv = f(f(acc * dt) + vel)
            e.wf32(o + (0x21 if c.rng.random() < 0.5 else 0x1d), nv)
        except OverflowError:
            pass
    sysobj = e.alloc(0x100, 4)
    e.wbytes(sysobj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    e.w32(0x70039c, sysobj)
    e.w32(sysobj + 0x40, c.rng.randint(0, 2 ** 31 - 1) if c.rng.random() < 0.9 else c.rng.getrandbits(32))
    e.wf32(sysobj + 0x48, 0.0 if c.rng.random() < 0.05 else _fv(c, 0.001, 0.4))
    return o


def _val(c):
    v = c.emu.alloc(4, 4)
    c.emu.wf32(v, _fv(c, -300, 300))
    return v


S(0x6621d0, 'ease step', 'thiscall', None, gen=lambda c: [_ease(c)], note='wire-render batch2000 (name not in the GC map)')
import os, struct
_CNT = [0]


def _dbg(c):
    o = _ease(c)
    _CNT[0] += 1
    if os.environ.get('EASE_DBG') and _CNT[0] == int(os.environ['EASE_DBG']):
        b = bytes(c.emu.mu.mem_read(o, 0x40)); print('case', _CNT[0], {hex(k): struct.unpack_from('<f', b, k)[0] for k in (0, 4, 8, 0xc, 0x11, 0x15, 0x19, 0x1d, 0x21, 0x25, 0x29)}, 'sys', struct.unpack('<If', bytes(c.emu.mu.mem_read(c.emu.r32(0x70039c) + 0x40, 4)) + bytes(c.emu.mu.mem_read(c.emu.r32(0x70039c) + 0x48, 4))))
    return [o]


S(0x6624d0, 'ease setup', 'thiscall', None, gen=_dbg, note='wire-render batch2000')


def _drive(c):
    o = _ease(c)
    v = _val(c)
    if c.rng.random() < 0.4:  # the value equals the follower's current one half the time: no restart
        c.emu.w32(v, c.emu.r32(o))
    return [o, v]


S(0x6623a0, 'ease drive', 'thiscall', None, ret='al', gen=_drive, note='wire-render batch2000; AL = reached')


def _update(c):
    o = _ease(c)
    v = _val(c)
    if c.rng.random() < 0.4:
        c.emu.w32(v, c.emu.r32(o))
    dst = c.emu.r32(o + 4) if c.rng.random() < 0.5 else None
    d = F(f32(c.rng.uniform(-300, 300))) if dst is None else F(__import__('struct').unpack('<f', __import__('struct').pack('<I', dst))[0])
    t = c.emu.r32(o + 0x25) if c.rng.random() < 0.5 else None
    tf = F(f32(c.rng.uniform(0.05, 4))) if t is None else F(__import__('struct').unpack('<f', __import__('struct').pack('<I', t))[0])
    return [o, v, d, tf]


S(0x662330, 'ease update', 'thiscall', None, gen=_update, note='wire-render batch2000')
