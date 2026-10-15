"""specs_s1909.py - fresh slice 19, batch1909 (src/batch1909.cpp). Exe callees hooked by address with logging handlers;
stack objects are logged by content; COM-style slots log no ecx; stub pop counts follow the callees' ret N."""
import struct
from pilot import S, F
from helpers22 import _rnd, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _g_cache(c):
    e = c.emu
    tag = _r(c)

    def calc(em, r):
        p = em.arg32(0)
        em.calllog.append(('CalcCacheFileName', 0, em.reg('ecx'), (em.arg32(1),)))
        em.w32(p, tag)
        em.ret(eax=p, argbytes=8)
    e.hook(0x48c4b0, calc)
    # 0x4cc1d0 (mov eax, [ecx]; ret) runs as exe code: it returns the tag the CalcCacheFileName stub stored.

    def dt(em, r):
        em.calllog.append(('~MYSTR', 0, None, (em.r32(em.reg('ecx')),)))
        em.ret(eax=0)
    e.hook(0x4cbec0, dt)
    fs = _rnd(c, 0x10)
    e.w32(fs, _pyvt(c, {0x30: _vh(c, 'fs.30', 2)}))
    e.w32(0x700394, fs)
    return [_rnd(c, 0x20)]


def _g_610070(c):
    e = c.emu
    self_ = _rnd(c, 0x1500)
    dev = _rnd(c, 0x10)
    e.w32(dev, _pyvt(c, {0xc8: _vh(c, 'dev.c8', 3, eax=0, log_ecx=False)}))
    e.w32(self_ + 0x1377, dev)
    # Inputs stay where the CRT float->unsigned helper 0x633910 is in range (v <= 1, not NaN): outside it the helper's
    # own error path faults the harness on both sides (exe CRT code, not the port). v > 1, NaN and huge |v| not tested.
    v = c.rng.choice([0.0, 1.0, 0.99, -0.0, 0.5, 0.999, 0.96, 0.9999, -1.0, -1000.0, c.rng.uniform(0.9, 1.0),
                      c.rng.uniform(-1, 1)])
    return [self_, F(v)]


def _g_5eda70(c):
    e = c.emu
    _hk(c, 0x5ed170, 'CSprite2D::Save', 1)
    s = _rnd(c, 0x10)
    e.w32(s, _pyvt(c, {0x4c: _vh(c, 's.4c', 1, eax=0), 0x3c: _vh(c, 's.3c', 1, eax=0), 0x44: _vh(c, 's.44', 1, eax=0)}))
    return [_rnd(c, 0x100), s]


def _g_50f9f0(c):
    e = c.emu
    arr = _rnd(c, 0x10)
    els = [_rnd(c, 8) for _ in range(3)]
    _hk(c, 0x5003d0, 'elem', 1, eax=lambda em: els[em.arg32(0) % 3])
    _hk(c, 0x506040, 'as string', 0)
    g = c.rng.choice([0, _rnd(c, 0x10), _rnd(c, 0x10)])
    if g:
        e.w32(g, _pyvt(c, {0x138: _vh(c, 'g.138', 3, eax=0)}))
    db = _rnd(c, 0x10)
    e.w32(db, _pyvt(c, {0x58: _vh(c, 'db.58', 1, eax=g), 0x114: _vh(c, 'RegisterZMsg', 4)}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    p = _rnd(c, 0x10)
    e.w32(p + 4, arr)
    return [_rnd(c, 0x10), p]


S(0x490470, 'ZEngineDataBase::GetGeomFilesSize', 'thiscall', None, ret='eax', gen=_g_cache, note='batch1909')
S(0x4906f0, 'FUN_004906f0 (cache file size 0x68d83c)', 'thiscall', None, ret='eax', gen=_g_cache, note='batch1909')
S(0x490830, 'FUN_00490830 (cache file size 0x68d840)', 'thiscall', None, ret='eax', gen=_g_cache, note='batch1909')
S(0x610070, 'FUN_00610070 (render state 0x2f)', 'thiscall', None, ret=None, gen=_g_610070, nan_heap=True,
  note='batch1909; void; CRT ftou helper runs as exe code; +0x14f2 is a float')
S(0x5eda70, 'CSpriteBorder2D::Save', 'thiscall', None, ret=None, gen=_g_5eda70, note='batch1909; void')
S(0x50f9f0, 'ZScriptSceneInterface_t::SendCommandToObject', 'thiscall', None, ret=None, gen=_g_50f9f0,
  note='batch1909; void; RegisterZMsg 4 words, g slot 0x138 3 words')
