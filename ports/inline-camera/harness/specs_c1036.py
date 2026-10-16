"""specs_c1036.py - camera batch 1036: ZCAMERA accessors and setters (engine render camera)."""
import struct
from pilot import S
from camgen import rnd, fbits, f32


def _cam(c):
    cam = rnd(c, 0x200)
    return cam


def _f(c):
    return struct.unpack('<f', struct.pack('<I', fbits(c)))[0]


S(0x445fb0, 'ZCAMERA::GetViewAspect', 'thiscall', ret='st0', gen=lambda c: [_cam(c)])
S(0x445fc0, 'ZCAMERA::GetViewport', 'thiscall', gen=lambda c: [_cam(c), rnd(c, 16)])
S(0x446030, 'ZCAMERA::IsActive', 'thiscall', ret='eax', gen=lambda c: [_cam(c)])


def _setf(a):
    def g(c):
        from pe_emu import F
        return [_cam(c), F(_f(c))]
    return g


def _setdeg(c):
    from pe_emu import F
    return [_cam(c), F(c.rng.uniform(-400, 400) if c.rng.random() < 0.8 else _f(c))]


S(0x446d80, 'ZCAMERA::SetFOV', 'thiscall', gen=_setdeg)
S(0x446db0, 'ZCAMERA::SetFar', 'thiscall', gen=_setf(0))
S(0x446de0, 'ZCAMERA::SetNear', 'thiscall', gen=_setf(0))
S(0x446e10, 'ZCAMERA::SetTargetLen', 'thiscall', gen=_setf(0))
S(0x446e40, 'ZCAMERA::SetViewAspect', 'thiscall', gen=_setf(0))
S(0x446eb0, 'ZCAMERA::SetWideScreen', 'thiscall', gen=lambda c: [_cam(c), c.rng.getrandbits(8)])
S(0x446780, 'ZCAMERA::SetBackColor', 'thiscall', gen=lambda c: [_cam(c), c.rng.getrandbits(32)])
