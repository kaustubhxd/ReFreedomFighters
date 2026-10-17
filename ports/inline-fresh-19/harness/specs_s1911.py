"""specs_s1911.py - fresh slice 19, batch1911 (src/batch1911.cpp). Exe callees hooked by address with logging handlers
(pop counts checked against each callee's ret N); stack data logged by value; 0x6071c0 runs as exe code."""
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


def _g_4550f0(c):
    e = c.emu
    _hk(c, 0x45f960, 'ZGEOM::Save', 1, eax=c.rng.choice([0, 1]))
    s = _rnd(c, 0x10)
    e.w32(s, _pyvt(c, {0x3c: _vh(c, 's.3c', 1, eax=0), 0x4c: _vh(c, 's.4c', 1, eax=0), 0x44: _vh(c, 's.44', 1, eax=0)}))
    return [_rnd(c, 0x50), s]


def _g_4c1e30(c):
    e = c.emu
    vals = [c.rng.choice([0, 1, 2, 3, _r(c)])] + [c.rng.choice([0, _r(c)]) for _ in range(4)]

    def u(em, r):
        em.calllog.append(('dbread.u32', 0, em.reg('ecx'), ()))
        em.ret(eax=vals.pop(0) if vals else 0x1234)
    e.hook(0x4e5e60, u)
    fl = [struct.unpack('<f', struct.pack('<I', _r(c) & 0x7f7fffff))[0] for _ in range(3)]

    def f(em, r):
        em.calllog.append(('dbread.f', 0, em.reg('ecx'), ()))
        em.ret(st0=fl.pop(0) if fl else 0.0)
    e.hook(0x4e5e80, f)
    d = _rnd(c, 0x10)
    buf = _rnd(c, 4)
    e.wbytes(buf, bytes([c.rng.choice([2, 0x22, 0x42, 0x62, 0x82, 0xc2, 0xff, 1, 3, _r(c) & 0xff])]))
    e.w32(d, buf)
    return [_rnd(c, 0x68), _rnd(c, 0x10), d]


def _g_51f530(c):
    e = c.emu
    o = c.rng.choice([0, _rnd(c, 0x20), _rnd(c, 0x20)])

    def pnew(em, r):
        em.calllog.append(('pool new', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=o)
    e.hook(0x45c4f0, pnew)

    def new(em, r):
        em.calllog.append(('new', 0, None, (em.arg32(0),)))
        em.ret(eax=o)
    e.hook(0x45c4b0, new)
    _hk(c, 0x51f3e0, 'ctor', 3)
    return [_r(c), _r(c), _r(c), c.rng.choice([0, _r(c)])]


def _g_606a70(c):
    e = c.emu
    _hk(c, 0x59a9b0, 'reserve', 1)

    def ins(em, r):
        em.calllog.append(('insert', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.r32(em.arg32(2)))))
        em.w32(em.reg('ecx') + 4, _r(c))
        em.ret(eax=0, argbytes=12)
    e.hook(0x606ee0, ins)
    return [_rnd(c, 0x20)]


def _g_57edf0(c):
    e = c.emu
    self_ = _rnd(c, 0x30)
    for k in range(8):
        w = _rnd(c, 0x10)
        e.w32(w, _pyvt(c, {0x284: _vh(c, 'w.284', 1, eax=0), 0x26c: _vh(c, 'w.26c', 3, eax=0)}))
        e.w32(self_ + 0xc + 4 * k, w)
    return [self_, _r(c), c.rng.randint(0, 3), c.rng.choice([0, 1, 100, 0x80000000, 0xffffffff, _r(c)])]


def _g_6101b0(c):
    e = c.emu
    dev = _rnd(c, 0x10)
    e.w32(dev, _pyvt(c, {0xc8: _vh(c, 'dev.c8', 3, eax=0, log_ecx=False)}))
    self_ = _rnd(c, 0x1380)
    e.w32(self_ + 0x1377, dev)
    return [self_, F(c.rng.uniform(-100, 1000)), F(c.rng.uniform(0, 5000)), _r(c)]


def _g_57a6b0(c):
    e = c.emu
    inp = _rnd(c, 0x10)
    e.w32(inp, _pyvt(c, {0x4c: _vh(c, 'inp.4c', 0, eax=c.rng.choice([0, 1, 0xf, 5, _r(c)]))}))
    e.w32(0x7003a0, inp)
    self_ = _rnd(c, 0x1a0)
    for i in range(4):
        e.w32(self_ + 0x184 + 4 * i, c.rng.choice([0xffffffff, 0, 1, 2, 3, 33, _r(c)]))
        e.wbytes(self_ + 0x194 + i, bytes([c.rng.choice([0, 0, 1])]))
    e.wbytes(self_ + 0x198, bytes([c.rng.choice([0, 0, 1])]))
    e.wbytes(self_ + 0x88, bytes([c.rng.choice([0, 1])]))
    if c.rng.random() < 0.4:
        e.w32(self_ + 0x94, 0)
    else:
        p = _rnd(c, 0x132a0)
        e.wbytes(p + 0x13298, bytes([c.rng.choice([0, 0, 1]), c.rng.choice([0, 0, 1])]))
        e.w32(self_ + 0x94, p)
    w = _rnd(c, 0x10)
    e.w32(w, _pyvt(c, {0x2fc: _vh(c, 'w.2fc', 1, eax=0)}))
    e.w32(self_, _pyvt(c, {0x84: _vh(c, 'vt.84', 0, eax=w)}))
    _hk(c, 0x57aaf0, 'UpdateMessage', 0)
    return [self_]


S(0x4550f0, 'ZMaterialDesc::Save', 'thiscall', None, ret='al', gen=_g_4550f0, note='batch1911; returns 1')
S(0x4c1e30, 'ZMusicSegment::Init', 'thiscall', None, ret=None, gen=_g_4c1e30, nan_heap=True,
  note='batch1911; void; DBREAD hooked; +0x59.. are floats')
S(0x51f530, 'FUN_0051f530 (factory)', 'fastcall', None, ret='eax', gen=_g_51f530, note='batch1911; SEH not ported')
S(0x606a70, 'FUN_00606a70 (constructor)', 'thiscall', None, ret='eax', gen=_g_606a70, note='batch1911; SEH not ported')
S(0x57edf0, 'FUN_0057edf0', 'thiscall', None, ret=None, gen=_g_57edf0, note='batch1911; void')
S(0x6101b0, 'FUN_006101b0 (fog states)', 'thiscall', None, ret=None, gen=_g_6101b0, note='batch1911; void; .data')
S(0x57a6b0, 'ZFFMissingControllerDialog::FrameUpdate', 'thiscall', None, ret=None, gen=_g_57a6b0, note='batch1911; void')
