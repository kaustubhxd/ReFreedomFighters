"""specs_s1901.py - fresh slice 19, batch1901 (src/batch1901.cpp). Callees hooked by address (logged, both sides reach
them): sized delete 0x634273 (cdecl), DBREAD float 0x4e5e80 / uint 0x4e5e60, ZZoneMap::NextMap 0x575800 and
ZBaseMap::OnKeyPress 0x574250. Vtables are Python handlers that log their arguments."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _g_5eaaf0(c):
    e = c.emu
    self_ = _rnd(c, 0x60)
    e.w32(self_ + 0x48, c.rng.choice([0, 1, 2, 5, 16]))

    def sdel(em, r):
        em.calllog.append(('sdel', 0x634273, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)
    e.hook(0x634273, sdel)
    return [self_]


def _dbread(c, addr, flt):
    vals = [_r(c) for _ in range(3)]

    def h(em, r):
        em.calllog.append(('dbread', addr, em.reg('ecx'), ()))
        v = vals.pop(0) if vals else 0x1234
        if flt:
            em.ret(st0=struct.unpack('<f', struct.pack('<I', v & 0x7f7fffff))[0])
        else:
            em.ret(eax=v)
    c.emu.hook(addr, h)


def _g_4bce30(c):
    _dbread(c, 0x4e5e80, True)
    return [_rnd(c, 0x60), _rnd(c, 0x10)]


def _g_57a1b0(c):
    _dbread(c, 0x4e5e60, False)
    return [_rnd(c, 0x60), _rnd(c, 0x10)]


def _g_657970(c):
    e = c.emu
    self_ = _rnd(c, 0x20)
    x = _rnd(c, 0x40)
    y = _rnd(c, 0x10)
    outs = [x, y]

    def g(em, r):
        em.calllog.append(('vt.c', 0xc, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=outs.pop(0) if outs else y, argbytes=4)
    e.w32(self_, _pyvt(c, {0xc: g}))
    return [self_, _r(c), c.rng.choice([0, 1, 0x5555, 0xffff, _r(c)])]


def _g_60ce70(c):
    e = c.emu
    self_ = _rnd(c, 0x1400)

    def a(em, r):
        em.calllog.append(('vt.2b0', 0x2b0, em.reg('ecx'), ()))
        em.ret(eax=_r(c))
    e.w32(self_, _pyvt(c, {0x2b0: a}))
    o = _rnd(c, 0x10)

    def b(em, r):
        em.calllog.append(('o.8c', 0x8c, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    e.w32(o, _pyvt(c, {0x8c: b}))
    e.w32(self_ + 0x1377, o)
    e.w32(0x724a00, _r(c))
    return [self_]


def _g_575930(c):
    e = c.emu
    self_ = _rnd(c, 0x220)
    self_b = c.rng.choice([0, 1, 0x80])
    e.wbytes(self_ + 0x216, bytes([self_b]))
    nm = c.rng.choice([0, 1, 0x100])
    base = _r(c)

    def nextmap(em, r):
        em.calllog.append(('NextMap', 0x575800, em.reg('ecx'), ()))
        em.ret(eax=(_r(c) & ~0xff) | nm)
    e.hook(0x575800, nextmap)

    def okp(em, r):
        em.calllog.append(('BaseOnKey', 0x574250, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=base, argbytes=4)
    e.hook(0x574250, okp)
    return [self_, c.rng.choice([0, 1, 1, 2, _r(c)])]


S(0x5eaaf0, 'CActorActionMarker::~CActorActionMarker', 'thiscall', None, ret=None, gen=_g_5eaaf0,
  note='batch1901; void; sized delete hooked')
S(0x4bce30, 'ZSoundVolume2D::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_g_4bce30, nan_heap=True,
  note='batch1901; void; three floats (heap words are floats)')
S(0x57a1b0, 'ZFFWaterMark::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_g_57a1b0,
  note='batch1901; void; three dwords')
S(0x657970, 'ZPrimControlGC::SetActiveNrTriangles', 'thiscall', None, ret=None, gen=_g_657970,
  note='batch1901; void; two vt[0xc] lookups')
S(0x60ce70, 'FUN_0060ce70', 'thiscall', None, ret='al', gen=_g_60ce70,
  note='batch1901; returns 1; o->vt[0x8c] taken as stdcall (GUESS)')
S(0x575930, 'ZZoneMap::OnKeyPress', 'thiscall', None, ret='al', gen=_g_575930,
  note='batch1901; bool; NextMap/base OnKeyPress hooked')
