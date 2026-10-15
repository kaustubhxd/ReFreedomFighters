"""specs_s1910.py - fresh slice 19, batch1910 (src/batch1910.cpp). Exe callees hooked by address with logging handlers
(pop counts checked against each callee's ret N); stack buffers logged by content; 0x4cc1d0 runs as exe code."""
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


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _g_57c870(c):
    _hk(c, 0x4cbe50, 'MYSTR copy', 1)
    return [_rnd(c, 0xc0), _rnd(c, 0xc0)]


def _g_57f6b0(c):
    e = c.emu
    o = _rnd(c, 0x10)
    v = _f32(c.rng.choice([0.0, 1.0, 0.5, 0.05, 2.7, -1.3, c.rng.uniform(0, 1), c.rng.uniform(-1e9, 1e9)]))

    def fa8(em, r):
        em.calllog.append(('o.a8', 0xa8, em.reg('ecx'), ()))
        em.ret(st0=v)
    e.w32(o, _pyvt(c, {0xa8: fa8}))
    s = _rnd(c, 0x10)
    txt = bytes(c.rng.randint(1, 255) for _ in range(c.rng.randint(0, 120))) + b'\0'

    def f198(em, r):
        em.calllog.append(('s.198', 0x198, None, (em.arg32(0), em.arg32(2), em.arg32(3))))
        em.wbytes(em.arg32(1), txt)
        em.ret(eax=0)
    e.w32(s, _pyvt(c, {0x198: f198}))
    eng = _rnd(c, 0x10)
    e.w32(eng, _pyvt(c, {0xbc: _vh(c, 'eng.bc', 0, eax=o), 0x190: _vh(c, 'eng.190', 0, eax=s)}))
    e.w32(0x70039c, eng)
    w = _rnd(c, 0x10)

    def f378(em, r):
        em.calllog.append(('w.378', 0x378, em.reg('ecx'), (em.rbytes(em.arg32(0), 128).split(b'\0')[0],)))
        em.ret(eax=0, argbytes=4)
    e.w32(w, _pyvt(c, {0x378: f378}))
    self_ = _rnd(c, 0x190)
    e.w32(self_ + 0x180, w)
    return [self_]


def _g_4528f0(c):
    e = c.emu
    o = c.rng.choice([0, _rnd(c, 0x30), _rnd(c, 0x30)])

    def new(em, r):
        em.calllog.append(('pool new', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=o)
    e.hook(0x45c4f0, new)
    _hk(c, 0x447640, 'base ctor', 3)
    return [_r(c), _r(c), _r(c), _r(c)]


def _g_4a6270(c):
    e = c.emu
    _hk(c, 0x469870, 'base ctor', 0)
    _hk(c, 0x4e7160, 'ZParamParticle ctor', 0)
    db = _rnd(c, 0x10)
    e.w32(db, _pyvt(c, {0x114: _vh(c, 'RegisterZMsg', 4)}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    return [_rnd(c, 0x120)]


def _g_570930(c):
    e = c.emu
    _hk(c, 0x5626d0, 'CBaseWindow::Load', 1, eax=c.rng.choice([0, 1, 0x100, 0xffffff01]))
    l = _rnd(c, 0x10)
    e.w32(l, _pyvt(c, {0x68: _vh(c, 'l.68', 1, eax=0), 0x40: _vh(c, 'l.40', 1, eax=0)}))
    return [_rnd(c, 0x1c0), l]


def _g_561f70(c):
    e = c.emu
    _hk(c, 0x4f9680, 'PlaySound', 1)
    _hk(c, 0x563750, 'SetWindowStatus', 2)
    self_ = _rnd(c, 0xe0)
    e.w32(self_ + 0xdc, c.rng.choice([3, 5, 5, 3, 0, 4, 6, _r(c)]))
    e.w32(self_, _pyvt(c, {0xd4: _vh(c, 'vt.d4', 1, eax=0)}))
    for off in (0x4c, 0x50):
        if c.rng.random() < 0.3:
            e.w32(self_ + off, 0)
        else:
            w = _rnd(c, 0x10)
            e.w32(w, _pyvt(c, {0xbc: _vh(c, 'child.bc', 1, eax=0)}))
            e.w32(self_ + off, w)
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x30, c.rng.choice([0, 1024, -7 & 0xffffffff, _r(c)]))
    e.w32(0x70039c, rm)
    return [self_]


def _g_5fa4f0(c):
    e = c.emu
    b = _rnd(c, 0x20)
    n1, n2 = c.rng.choice([0, 1, 4]), c.rng.choice([0, 1, 3])
    e.w32(b + 0x14, n1)
    e.w32(b + 0xc, _rnd(c, 4 * max(n1, 1)))
    e.w32(b + 8, n2)
    arr = _rnd(c, 4 * max(n2, 1))
    for i in range(n2):
        o = _rnd(c, 0x10)
        e.w32(o, _pyvt(c, {0xc: _vh(c, 'obj.c', 2, eax=0)}))
        e.w32(arr + 4 * i, o)
    e.w32(b, arr)
    si = _rnd(c, 0x10)
    e.w32(si, _pyvt(c, {0x2c: _vh(c, 'si.2c', 1, eax=0), 0x3c: _vh(c, 'si.3c', 1, eax=0)}))
    self_ = _rnd(c, 0x10)
    e.w32(self_ + 4, b)
    return [self_, si]


def _g_490e70(c):
    e = c.emu
    tag = _r(c)

    def calc(em, r):
        p = em.arg32(0)
        em.calllog.append(('CalcCacheFileName', 0, em.reg('ecx'), (em.arg32(1),)))
        em.w32(p, tag)
        em.ret(eax=p, argbytes=8)
    e.hook(0x48c4b0, calc)

    def dt(em, r):
        em.calllog.append(('~MYSTR', 0, None, (em.r32(em.reg('ecx')),)))
        em.ret(eax=0)
    e.hook(0x4cbec0, dt)
    fs = _rnd(c, 0x10)
    e.w32(fs, _pyvt(c, {0x60: _vh(c, 'fs.60', 5)}))
    e.w32(0x700394, fs)
    return [_rnd(c, 0x20), _r(c), _r(c)]


S(0x57c870, 'FUN_0057c870 (copy constructor)', 'thiscall', None, ret='eax', gen=_g_57c870, note='batch1910')
S(0x57f6b0, 'FUN_0057f6b0 (format value into window)', 'thiscall', None, ret=None, gen=_g_57f6b0,
  note='batch1910; void; x87 multiply; cookie not ported')
S(0x4528f0, 'FUN_004528f0 (pool factory)', 'fastcall', None, ret='eax', gen=_g_4528f0, note='batch1910; SEH not ported')
S(0x4a6270, 'FUN_004a6270 (event constructor)', 'thiscall', None, ret='eax', gen=_g_4a6270, note='batch1910')
S(0x570930, 'CSewerMenu::Load', 'thiscall', None, ret='al', gen=_g_570930, note='batch1910; bool')
S(0x561f70, 'CBaseWindow::Enter', 'thiscall', None, ret=None, gen=_g_561f70, nan_heap=True,
  note='batch1910; void; +0x64 is a float')
S(0x5fa4f0, 'OpaqueObjectSerialBuffer_t::toSerial', 'thiscall', None, ret=None, gen=_g_5fa4f0, note='batch1910; void')
S(0x490e70, 'ZEngineDataBase::GetSoundGraphData', 'thiscall', None, ret=None, gen=_g_490e70,
  note='batch1910; fs slot 0x60 5 words; return value not compared')
