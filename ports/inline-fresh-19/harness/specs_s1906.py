"""specs_s1906.py - fresh slice 19, batch1906 (src/batch1906.cpp). Exe callees hooked by address with logging handlers;
vtables are Python handlers that log their arguments; stack data is logged by value, never by address."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _rm(c):
    rm = _rnd(c, 0x1ab0)
    c.emu.w32(0x70039c, rm)
    return rm


def _g_45aff0(c):
    e = c.emu
    g = _rnd(c, 0x50)
    for o in (0x40, 0x44, 0x48):
        e.wf32(g + o, c.rng.choice([0.0, 1.0, -2.5, c.rng.uniform(-1000, 1000), c.rng.uniform(-1, 1)]))
    self_ = _rnd(c, 0x30)
    e.w32(self_ + 8, g)

    def h(em, r):
        p = em.arg32(0)
        em.calllog.append(('fn_4dd060', 0, em.reg('ecx'), (p, em.r32(p), em.r32(p + 4), em.r32(p + 8))))
        em.ret(eax=0, argbytes=4)
    e.hook(0x4dd060, h)
    _hk(c, 0x4dce50, 'SetRadius', 1)
    return [self_]


def _g_454d30(c):
    e = c.emu
    g = _rnd(c, 0x50)
    cls = _rnd(c, 0x30)
    e.w32(cls + 0x23, c.rng.choice([0x2000f0, 0x2000f0, 0x2000f1, _r(c)]))
    e.w32(g + 0xc, cls)
    _hk(c, 0x45d5b0, 'ZGEOM::CopyData', 1)
    return [_rnd(c, 0x50), g]


def _g_4a37f0(c):
    e = c.emu
    self_ = _rnd(c, 0x130)
    e.w32(self_ + 0x78, _pyvt(c, {0x14: _vh(c, 'm.14', 0)}))
    e.w32(self_, _pyvt(c, {0x84: _vh(c, 'vt.84', 1, eax=0), 0x88: _vh(c, 'vt.88', 0, eax=0)}))
    rm = _rm(c)
    e.w32(rm + 0x40, c.rng.choice([0, 1, 1024, -3 & 0xffffffff, _r(c)]))
    return [self_]


def _g_428af0(c):
    e = c.emu
    dev = _rnd(c, 0x10)
    hr = c.rng.choice([0, 1, 0x80000000, 0x80070057, _r(c)])

    def h(em, r):
        p = em.arg32(2)
        em.calllog.append(('dev.18', 0x18, None, (em.arg32(0), em.arg32(1)) + tuple(em.r32(p + 4 * k) for k in range(6))))
        em.ret(eax=hr, argbytes=12)
    e.w32(dev, _pyvt(c, {0x18: h}))
    return [_rnd(c, 0x10), _rnd(c, 0x20), dev]


def _g_48fa70(c):
    e = c.emu
    self_ = _rnd(c, 0xae0)
    for i in range(0x20):
        if c.rng.random() < 0.3:
            o = _rnd(c, 0x10)
            e.w32(o, _pyvt(c, {0: _vh(c, 'o.0', 1, eax=0)}))
            e.w32(self_ + 0x48 + 4 * i, o)
        else:
            e.w32(self_ + 0x48 + 4 * i, 0)
    e.w32(self_ + 0xc8, c.rng.choice([0, _rnd(c, 0x30)]))
    _hk(c, 0x49d2c0, 'fn_49d2c0', 0)
    _hk(c, 0x634273, 'sdel', 2, pop=0)
    return [self_]


def _g_6125f0(c):
    _hk(c, 0x6132a0, '~ZTextureManagerGC', 0)
    _hk(c, 0x634273, 'sdel', 2, pop=0)
    return [_rnd(c, 0x40), c.rng.choice([0, 1, 2, 3, _r(c)])]


def _g_fact(ctor, name):
    def g(c):
        e = c.emu
        o = c.rng.choice([0, _rnd(c, 0x50)])
        al = _rnd(c, 0x10)
        e.w32(al, _pyvt(c, {0x44: _vh(c, 'alloc.44', 1, eax=o)}))
        db = _rnd(c, 0x20)
        e.w32(db + 8, al)
        rm = _rnd(c, 0xa0)
        e.w32(rm + 0x9b, db)
        e.w32(0x70039c, rm)
        _hk(c, ctor, name, 0)
        return [_rnd(c, 0x10)]
    return g


def _g_4ee070(c):
    e = c.emu
    s = _rnd(c, 0x10)
    e.w32(s, _pyvt(c, {0xa0: _vh(c, 's.a0', 2, eax=0), 0x60: _vh(c, 's.60', 2, eax=0)}))
    db = _rnd(c, 0x10)
    e.w32(db, _pyvt(c, {0x138: _vh(c, 'db.138', 0, eax=s), 0x4c: _vh(c, 'db.4c', 2)}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    return [_rnd(c, 0x10), c.rng.choice([0, 1, 0x100, 0x80])]


def _g_638cf0(c):
    e = c.emu
    w, h = c.rng.choice([0, 1, 3, 8]), c.rng.choice([0, 1, 4, -1])
    pitch = c.rng.choice([8, 16, 20])
    data = _rnd(c, 4 * pitch * 12)
    info = _rnd(c, 0x20)
    e.w32(info + 4, pitch)
    e.w32(info + 0x10, data)
    self_ = _rnd(c, 0x10)
    e.w32(self_, _pyvt(c, {0x38: _vh(c, 'vt.38', 1, eax=info)}))
    stride = c.rng.choice([4 * 8, 4 * 10, 64])
    dst = _rnd(c, stride * 6 + 64)
    x, y = c.rng.randint(0, max(0, pitch - 8)), c.rng.randint(0, 6)
    return [self_, dst, x, y, w, h & 0xffffffff, stride, _r(c)]


def _g_4f63b0(c):
    e = c.emu
    _hk(c, 0x4face0, 'ZFONT::CopyDataBlock', 1)
    _hk(c, 0x4e1b20, 'fn_4e1b20', 0)
    _hk(c, 0x4e1b30, 'NextBlock', 0)
    v = _r(c)

    def get(em, r):
        em.calllog.append(('Get', 0x4e12e0, em.reg('ecx'), (em.arg32(1),)))
        em.w32(em.arg32(0), v)
        em.ret(eax=0, argbytes=8)
    e.hook(0x4e12e0, get)
    t = _rnd(c, 0x40)
    e.w32(t + 4, c.rng.choice([0, 8, 0x10]))
    tab = _rnd(c, 0x10)
    e.w32(tab, _pyvt(c, {0xc: _vh(c, 'tab.c', 1, eax=t)}))
    o = _rnd(c, 0x20)
    e.w32(o + 0x18, tab)
    rm = _rm(c)
    e.w32(rm + 0x1aa3, o)
    return [_rnd(c, 0xa4), _rnd(c, 0x10)]


S(0x45aff0, 'ZBoxPrimitive::CalcCenSize', 'thiscall', None, ret=None, gen=_g_45aff0, note='batch1906; void')
S(0x454d30, 'ZMaterialDesc::CopyData', 'thiscall', None, ret=None, gen=_g_454d30, note='batch1906; void')
S(0x4a37f0, 'ZSoundMove::Init', 'thiscall', None, ret=None, gen=_g_4a37f0, note='batch1906; void')
S(0x428af0, 'FUN_00428af0 (SetProperty range)', 'thiscall', None, ret='eax', gen=_g_428af0, note='batch1906; hr >= 0')
S(0x48fa70, 'FUN_0048fa70', 'thiscall', None, ret=None, gen=_g_48fa70, note='batch1906; void')
S(0x6125f0, 'FUN_006125f0 (scalar deleting dtor)', 'thiscall', None, ret='eax', gen=_g_6125f0,
  note='batch1906; SEH frame not ported')
S(0x4a3cf0, 'FUN_004a3cf0 (factory)', 'thiscall', None, ret='eax', gen=_g_fact(0x4a3b40, 'ctor 4a3b40'), note='batch1906')
S(0x5b7fb0, 'FUN_005b7fb0 (CCheckInsideBox factory)', 'thiscall', None, ret='eax',
  gen=_g_fact(0x5b7f00, 'CCheckInsideBox ctor'), note='batch1906')
S(0x5b94f0, 'FUN_005b94f0 (CFriendlyControl factory)', 'thiscall', None, ret='eax',
  gen=_g_fact(0x5b9380, 'CFriendlyControl ctor'), note='batch1906')
S(0x4ee070, 'ZWINOBJSPRITEHOLDER::SaveCleanup', 'thiscall', None, ret=None, gen=_g_4ee070, note='batch1906; void')
S(0x638cf0, 'FUN_00638cf0 (word blit)', 'thiscall', None, ret='eax', gen=_g_638cf0, note='batch1906; returns info')
S(0x4f63b0, 'ZTTFONT::CopyDataBlock', 'thiscall', None, ret=None, gen=_g_4f63b0, note='batch1906; void')
