"""specs_w1.py - wire-render batch 1036 / 1065 in the strict pilot: ZCAMERA setters (SetFOV, SetFar, SetNear, SetTargetLen,
SetViewAspect, SetViewport). Same bodies as the camera thread's specs, written for this pilot's Spec."""
import math
from pilot import S, f32, F


def _obj(c, n=0x200):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _val(c):
    r = c.rng.random()
    if r < 0.25:
        return f32(c.rng.choice([0.0, -0.0, 1.0, 0.9999999, 1.0000001, -1.0, math.nan, math.inf, -math.inf, 1e-40, 90.0, 360.0]))
    if r < 0.8:
        return f32(c.rng.uniform(-400, 400))
    return f32(c.rng.uniform(-3e4, 3e4))


def _setter(c):
    cam = _obj(c)
    off = {0x446d80: 0x5c, 0x446db0: 0x68, 0x446de0: 0x64, 0x446e10: 0x60, 0x446e40: 0x181}
    v = _val(c)
    # half the time store the very value the setter will compute, so the "unchanged" branch runs
    return [cam, F(v)]


for addr, nm in [(0x446d80, 'SetFOV'), (0x446db0, 'SetFar'), (0x446de0, 'SetNear'), (0x446e10, 'SetTargetLen'), (0x446e40, 'SetViewAspect')]:
    S(addr, 'ZCAMERA::' + nm, 'thiscall', None, gen=_setter, note='wire-render; camera batch1036 [high]')


def _vp(c):
    cam = _obj(c)
    v = c.emu.alloc(16, 4)
    for i in range(4):
        c.emu.w32(v + 4 * i, c.rng.getrandbits(32) if c.rng.random() < 0.3 else c.rng.randint(0, 2000))
    return [cam, v]


S(0x446e60, 'ZCAMERA::SetViewport', 'thiscall', None, gen=_vp, note='wire-render; camera batch1065 [medium name]', )


# ---- ZCAMERA::SetCam6ClipPlanes 0x446790 and its plane builder 0x4453c0 (camera batches 1069 / 1070)
def _fl(c, lo, hi):
    return c.rng.uniform(lo, hi)


def _fbits(c):
    r = c.rng.random()
    if r < 0.6:
        return f32bits(c.rng.uniform(-2000, 2000))
    if r < 0.75:
        return f32bits(c.rng.choice([0.0, -0.0, 1.0, -1.0, 0.5, 1e-30, -1e-30, 3.4e38, -3.4e38, math.inf, -math.inf]))
    if r < 0.85:
        return c.rng.choice([0x7fc00000, 0xffc00000, 0x7f800001, 0xff812345])
    return c.rng.getrandbits(32)


def f32bits(x):
    import struct
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _plane(c):
    pl = _obj(c, 0x20)
    if c.rng.random() < 0.15:
        for i in range(3):
            c.emu.w32(pl + 4 * i, 0)
    else:
        for i in range(3):
            c.emu.w32(pl + 4 * i, _fbits(c) if c.rng.random() < 0.1 else f32bits(_fl(c, -2.0, 2.0)))
    c.emu.w32(pl + 12, _fbits(c) if c.rng.random() < 0.1 else f32bits(_fl(c, -300, 300)))
    return pl


def _add(c):
    s = _obj(c)
    n = c.rng.randint(0, 4)
    c.emu.w32(s, n)
    c.emu.w32(s + 4, c.rng.getrandbits(16))
    return [s, _plane(c), n]


S(0x4453c0, 'ZCamPlanes::Add (unnamed)', 'thiscall', None, gen=_add, note='wire-render; camera batch1069')


def _clip(c):
    r = c.rng

    def memset(e, res):  # cdecl memset(p, v, n): the caller pops; returns p
        p, v, n = e.arg32(0), e.arg32(1) & 0xff, e.arg32(2)
        for i in range(n):
            c.emu.w8(p + i, v)
        e.ret(eax=p, argbytes=0)
    c.emu.stub_import('memset', memset)
    s = _obj(c, 0x400)
    c.emu.w32(s + 0x48, r.getrandbits(8))
    c.emu.w32(s + 0x3c, 0x3f800000 if r.random() < 0.3 else f32bits(_fl(c, 0.5, 4.0)))
    c.emu.w32(s + 0x40, f32bits(_fl(c, 0.5, 4.0)))
    c.emu.w32(s + 0x60, f32bits(_fl(c, 0.5, 4.0)))
    c.emu.w32(s + 0x181, f32bits(_fl(c, 0.5, 2.5)))
    eng = _obj(c, 0x2000)
    c.emu.w32(0x70039c, eng)
    node = _obj(c, 0x100)
    c.emu.w32(node + 0x81, r.getrandbits(8))
    c.emu.w32(eng + 0x190f, node)
    return [s, F(f32(_fl(c, 0.2, 2.5))), F(f32(_fl(c, 0.1, 5.0))), F(f32(_fl(c, 10.0, 900.0))), r.randint(1, 1000), r.randint(1, 1000),
            F(f32(_fl(c, 0.5, 2.0)))]


S(0x446790, 'ZCAMERA::SetCam6ClipPlanes', 'thiscall', None, gen=_clip, note='wire-render; camera batch1070 [high]; 0x4453c0 / 0x446ee0 run as exe code, CRT memset stubbed')
