"""specs_s48.py - inline session batch 48: small callees of ZFFHERO::ClassFrameUpdate and ZPlayer::ClassFrameUpdate.
Vtable callees are heap stubs (saved args, call counter, fixed per-input eax/edx). ZGameOSD::PlaySound runs as exe code
with its sound object and render-manager calls stubbed the same way."""
import struct
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vec(c, n, lo, hi):
    a = c.emu.alloc(4 * n + 0x10, 4)
    for i in range(n):
        c.emu.wf32(a + 4 * i, c.rng.uniform(lo, hi))
    return a


def _stub(c, nargs, ret=0, edx=None):
    rec = c.emu.alloc(4 * nargs + 4, 4)
    code = b''
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    if edx is not None:
        code += b'\xba' + struct.pack('<I', edx & 0xffffffff)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _obj(c, size, slots):
    o = _rnd(c, size)
    vt = c.emu.alloc(max(slots) + 4, 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def _lod(c):
    r = c.rng
    o = _rnd(c, 0x270)
    on = r.getrandbits(32) if r.random() < 0.5 else (r.getrandbits(24) << 8)   # only the low byte counts
    return [o, on, r.getrandbits(32)]


def _cnt(c):
    o = _rnd(c, 0x900)
    if c.rng.random() < 0.4:
        c.emu.w32(o + 0x300, 0x10000000)
    return [o]


def _vm(c):
    r = c.rng
    v = _vec(c, 3, -100.0, 100.0)
    m = _vec(c, 9, -2.0, 2.0) if r.random() < 0.8 else _rnd(c, 0x24)
    if r.random() < 0.25:   # cancelling lanes: v0*m[6+j] + v1*m[3+j] = 0 exactly, so the add order shows
        x = r.uniform(1e7, 1e8)
        c.emu.wf32(v, x)
        c.emu.wf32(v + 4, x)
        c.emu.wf32(v + 8, r.uniform(-1e-3, 1e-3))
        for j in range(3):
            c.emu.wf32(m + 24 + 4 * j, 1.0)
            c.emu.wf32(m + 12 + 4 * j, -1.0)
            c.emu.wf32(m + 4 * j, r.uniform(-2.0, 2.0))
    return [v, m]


def _mm(c):
    return [_vec(c, 9, -2.0, 2.0), _vec(c, 9, -2.0, 2.0)]


def _dist(c):
    return [_vec(c, 3, -500.0, 500.0), _vec(c, 3, -500.0, 500.0)]


def _sysprof(c, slot):
    r = c.rng
    sysobj = _obj(c, 0x9d0, {0x1c8: _stub(c, 2, ret=r.getrandbits(32), edx=r.getrandbits(32)), slot: _stub(c, 3)})
    for off in (0x9c3, 0x9c7):
        x = r.random()
        c.emu.wf32(sysobj + off, 0.0 if x < 0.25 else (-0.0 if x < 0.3 else r.uniform(-1.0, 1.0)))
    c.emu.w32(0x70039c, sysobj)
    tag = _rnd(c, 0x10)
    c.emu.mu.ctl_flush_tb()
    return [tag]


def _recruit(c):
    r = c.rng
    o = _obj(c, 0x440, {0x438: _stub(c, 0, ret=r.getrandbits(32) & (0xffffff00 if r.random() < 0.5 else 0xffffffff))})
    self = _rnd(c, 0x1000)
    c.emu.w32(self + 0xf56, o if r.random() < 0.85 else 0)
    now = r.randint(0, 1 << 20)
    if r.random() < 0.3:   # exactly on the 1024-tick boundary, give or take one tick
        c.emu.wf32(self + 0xf52, (now - 1024 + r.randint(-1, 1)) / 1024.0)
    else:
        c.emu.wf32(self + 0xf52, (now - r.randint(0, 2048)) / 1024.0 + r.uniform(-0.001, 0.001))
    snd = _obj(c, 0x10, {0x120: _stub(c, 2, ret=r.getrandbits(32))})
    rmres = _rnd(c, 0x50)
    rm = _obj(c, 0x10, {0x60: _stub(c, 1, ret=rmres if r.random() < 0.7 else 0)})
    sysobj = _rnd(c, 0x1ab0)
    c.emu.w32(sysobj + 0x40, now)
    c.emu.w32(sysobj + 0x1a9f, snd if r.random() < 0.9 else 0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    osd = _rnd(c, 0x100)
    if r.random() < 0.1:
        c.emu.w32(osd + 0x89 + 0x11 * 4, 0)
    c.emu.w32(self + 0x852, osd)
    c.emu.mu.ctl_flush_tb()
    return [self]


def _endscene(c):
    r = c.rng
    rm = _obj(c, 0x10, {0xa0: _stub(c, 1), 0xa4: _stub(c, 0), 0xa8: _stub(c, 0)})
    sysobj = _obj(c, 0xa0, {0xc: _stub(c, 4)})
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    self = _rnd(c, 0x1050)
    c.emu.wbytes(self + 0x1042, bytes([0 if r.random() < 0.5 else r.randint(1, 255)]))
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x6474d0, 'ZBoneModifyBase::SetOverrideLODIndex', 'thiscall', None, ret=None, gen=_lod, note='batch48')
S(0x5ab070, 'count frame at +0x8cb', 'thiscall', None, ret=None, gen=_cnt, note='batch48')
S(0x59ffc0, 'get dword +0x77f', 'thiscall', None, ret='eax', gen=lambda c: [_rnd(c, 0x790)], note='batch48')
S(0x596cf0, 'ZGameOSD::CharismaGetRecruitable', 'thiscall', None, ret='eax', gen=lambda c: [_rnd(c, 0x1fc0)], note='batch48')
S(0x4419f0, 'vmmul', 'fastcall', None, ret=None, gen=_vm, note='batch48; x87 at 53-bit precision')
S(0x4de480, 'mmul in place (three vmmul)', 'fastcall', None, ret=None, gen=_mm, note='batch48')
S(0x4e0870, 'vdist', 'fastcall', None, ret='st0', gen=_dist, note='batch48')
S(0x441730, 'profiler begin', 'fastcall', None, ret=None, gen=lambda c: _sysprof(c, 0x178), note='batch48')
S(0x440530, 'profiler end', 'fastcall', None, ret=None, gen=lambda c: _sysprof(c, 0x17c), note='batch48')
S(0x596680, 'recruit timeout (OSD sound 0x11)', 'thiscall', None, ret=None, gen=_recruit, note='batch48; PlaySound as exe code')
S(0x59c420, 'ZFFLevelController::PushEndScene', 'thiscall', None, ret=None, gen=_endscene, note='batch48')
