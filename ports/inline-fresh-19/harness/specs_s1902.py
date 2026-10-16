"""specs_s1902.py - fresh slice 19, batch1902 (src/batch1902.cpp). Exe callees are hooked by address with logging handlers
(both sides reach them); vtables are Python handlers that log their arguments; the logger and assert hook come from
helpers22._log_world."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _hk, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, st0=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        if st0 is not None:
            em.ret(st0=st0, argbytes=4 * nargs)
        else:
            em.ret(eax=_r(c) if eax is None else eax, argbytes=4 * nargs)
    return h


def _g_54aaf0(c):
    e = c.emu
    self_ = _rnd(c, 0xa280)
    r = _rnd(c, 0xd0)
    e.wbytes(r + 0xc8, bytes([c.rng.choice([0, 1, 0x40])]))
    e.w32(self_, _pyvt(c, {0xa8: _vh(c, 'vt.a8', 0, eax=r)}))
    return [self_, c.rng.choice([0, 1, 0x100, _r(c)])]


def _g_err(c):
    _log_world(c)
    return [_rnd(c, 0x20), _r(c), _r(c)]


def _g_err0(c):
    _log_world(c)
    return [_rnd(c, 0x20)]


def _g_64fc70(c):
    e = c.emu
    self_ = _rnd(c, 0x20)
    a = c.rng.choice([0, 1, 640, -7, c.rng.randint(-100000, 100000), _r(c)]) & 0xffffffff
    b = c.rng.choice([1.0, 0.5, 3.0, -2.0, 0.0, 1e-30, c.rng.uniform(-50, 50), c.rng.uniform(0, 2)])
    b = struct.unpack('<f', struct.pack('<f', b))[0]
    e.w32(self_, _pyvt(c, {0xd8: _vh(c, 'vt.d8', 0, eax=a), 0xf4: _vh(c, 'vt.f4', 0, st0=b)}))
    return [self_]


def _g_496d70(c):
    e = c.emu
    g = _rnd(c, 0x60)
    if c.rng.random() < 0.3:
        e.w32(g + 0x54, 0)
    else:
        m = _rnd(c, 0x10)
        e.w32(m + 0xc, _rnd(c, 0x30))
        e.w32(g + 0x54, m)
    t = _r(c)

    def glt(em, r):
        em.calllog.append(('GetBaseGeomListType', 0x4daf20, em.reg('ecx'), (em.reg('edx'),)))
        em.ret(eax=t)
    e.hook(0x4daf20, glt)
    _hk(c, 0x496ce0, 'ZBaseGeomLists::Exists', 3, eax=_r(c))
    return [_rnd(c, 0x20), _r(c), g]


def _g_65f170(c):
    e = c.emu
    self_ = _rnd(c, 0x120)
    n = c.rng.choice([0, 1, 2, 5, 9])
    e.w32(self_ + 0xcc, n)
    for i in range(n):
        e.w32(self_ + 0xd0 + 4 * i, _rnd(c, 0x50))
    return [self_]


def _g_4b0ef0(c):
    e = c.emu
    s = _rnd(c, 0x10)
    e.w32(s, _pyvt(c, {0x44: _vh(c, 's.44', 1, eax=0), 0x54: _vh(c, 's.54', 1, eax=0), 0x60: _vh(c, 's.60', 1, eax=0)}))
    return [_rnd(c, 0x70), s]


def _g_4f9970(c):
    _hk(c, 0x43ea20, 'dtor body', 0)
    _hk(c, 0x45c510, 'ZGEOM::delete', 1, pop=0)
    _hk(c, 0x4690b0, 'sized delete', 2, pop=0)
    return [_rnd(c, 0xc0), c.rng.choice([0, 1, 3, 4, 5, 7, _r(c)])]


def _g_4951f0(c):
    e = c.emu
    db = _rnd(c, 0x5d40)
    e.w32(db + 0x5d35, c.rng.choice([0, 1, _r(c)]))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    n = c.rng.choice([0, 1, 3, 6])
    g = _rnd(c, 4 * max(n, 1))
    _hk(c, 0x4dbb00, 'LightNotify', 1)
    return [_rnd(c, 0x20), g, n]


def _g_560530(c):
    e = c.emu
    e.w32(0x714198, c.rng.choice([0, 1, 0x30, 0x31, 0x32, 0x33, 0x100]))
    self_ = _rnd(c, 0x10)
    e.w32(self_, _pyvt(c, {0x44: _vh(c, 'vt.44', 1, eax=0)}))
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    return [self_, _r(c)]


def _g_61a6b0(c):
    e = c.emu
    n = c.rng.choice([0, 1, 2, 5])
    lst = _rnd(c, 0x10)
    e.w32(lst, n)
    e.w32(lst + 8, _rnd(c, 8 * max(n, 1)))
    dev = _rnd(c, 0x10)
    e.w32(dev, _pyvt(c, {0x11c: _vh(c, 'dev.11c', 6, eax=0, log_ecx=False)}))
    e.w32(0x724a00, dev)
    return [_r(c), lst]


def _g_571bf0(c):
    e = c.emu
    o = _rnd(c, 0x10)
    e.w32(o, _pyvt(c, {0x7c: _vh(c, 'o.7c', 0), 0x84: _vh(c, 'o.84', 0), 0x8c: _vh(c, 'o.8c', 0)}))
    eng = _rnd(c, 0x10)
    e.w32(eng, _pyvt(c, {0xbc: _vh(c, 'eng.bc', 0, eax=o)}))
    e.w32(0x70039c, eng)
    return [_rnd(c, 0x1a0)]


def _g_49c770(c):
    e = c.emu
    self_ = _rnd(c, 0x40)
    n = c.rng.choice([0, 1, 3, 6])
    lst = _rnd(c, 4 * max(n, 1) + 4)
    for i in range(n):
        e.w32(lst + 4 * i, _rnd(c, 0x40))
    e.w32(self_ + 0x39, lst)
    lo = c.rng.randint(0, n)
    r = (lo | ((n - lo) << 16)) | (c.rng.choice([0, 0]) << 0)
    _hk(c, 0x49c980, 'PriUnfoldList', 2, eax=r)
    return [self_, _rnd(c, 0x70)]


S(0x54aaf0, 'FUN_0054aaf0', 'thiscall', None, ret='al', gen=_g_54aaf0, note='batch1902; bool')
S(0x5f94b0, 'Process_t::ProcFactory_t::typeInfoFromSerial', 'thiscall', None, ret=None, gen=_g_err,
  note='batch1902; log + assert only')
S(0x603eb0, 'OpaqueUserType_t::serialSize', 'thiscall', None, ret='eax', gen=_g_err0,
  note='batch1902; log + assert, returns 0')
S(0x64fc70, 'ZRender::GetTextSizeX', 'thiscall', None, ret='eax', gen=_g_64fc70, note='batch1902; x87 divide')
S(0x496d70, 'ZGeomBuffer::Exists', 'thiscall', None, ret='eax', gen=_g_496d70, note='batch1902; callees hooked')
S(0x65f170, 'ZGeometryDecal::Flush', 'thiscall', None, ret=None, gen=_g_65f170, note='batch1902; void')
S(0x4b0ef0, 'CCutSequenceSoundFXAttenuation::Save', 'thiscall', None, ret='al', gen=_g_4b0ef0, note='batch1902; returns 1')
S(0x4f9970, 'ZScrollbar::`scalar deleting destructor', 'thiscall', None, ret='eax', gen=_g_4f9970, note='batch1902')
S(0x4951f0, 'ZEngineGeomControl::UpdateChangedLights', 'thiscall', None, ret=None, gen=_g_4951f0, note='batch1902')
S(0x560530, 'CFFMPGameControl_if::registerCallMethod', 'thiscall', None, ret=None, gen=_g_560530,
  note='batch1902; .data table write')
S(0x61a6b0, 'FUN_0061a6b0', 'fastcall', None, ret=None, gen=_g_61a6b0, note='batch1902; device slot 0x11c COM style')
S(0x571bf0, 'CSoundMenu::BackUpOptionsValues', 'thiscall', None, ret=None, gen=_g_571bf0, note='batch1902')
S(0x49c770, 'CListUser::NotifyAllMembers', 'thiscall', None, ret=None, gen=_g_49c770, note='batch1902')
