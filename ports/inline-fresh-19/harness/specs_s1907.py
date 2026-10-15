"""specs_s1907.py - fresh slice 19, batch1907 (src/batch1907.cpp). Exe callees hooked by address with logging handlers;
stack objects are logged by content, never by address (the port's frame differs)."""
from pilot import S
from helpers22 import _rnd, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _g_4311f0(c):
    e = c.emu
    self_ = _rnd(c, 0x10)
    end = c.rng.choice([0, _rnd(c, 0x30)])
    e.w32(self_ + 4, end)
    e.w32(self_ + 8, c.rng.choice([end, end + 0xc, _r(c)]))
    _hk(c, 0x5f10c0, 'copy ctor', 1)
    _hk(c, 0x4302d0, 'grow insert', 2)
    return [self_, _r(c)]


def _g_4febf0(c):
    return [_rnd(c, 0x140), _rnd(c, 0x140)]


def _g_423ff0(c):
    e = c.emu
    tag = _r(c)

    def ctor(em, r):
        em.calllog.append(('MYSTR(s)', 0, None, (em.arg32(0),)))
        em.w32(em.reg('ecx'), tag)
        em.w32(em.reg('ecx') + 4, em.arg32(0))
        em.ret(eax=em.reg('ecx'), argbytes=4)
    e.hook(0x4cbe80, ctor)

    def asg(em, r):
        o = em.arg32(0)
        em.calllog.append(('MYSTR=', 0, em.reg('ecx'), (em.r32(o), em.r32(o + 4))))
        em.ret(eax=em.reg('ecx'), argbytes=4)
    e.hook(0x4cbee0, asg)

    def dtor(em, r):
        em.calllog.append(('~MYSTR', 0, None, (em.r32(em.reg('ecx')), em.r32(em.reg('ecx') + 4))))
        em.ret(eax=0)
    e.hook(0x4cbec0, dtor)
    return [_rnd(c, 0x2460), _r(c)]


def _g_56f030(c):
    e = c.emu
    o = c.rng.choice([0, _rnd(c, 0x4c0)])
    al = _rnd(c, 0x10)
    e.w32(al, _pyvt(c, {0x44: _vh(c, 'alloc.44', 1, eax=o)}))
    db = _rnd(c, 0x20)
    e.w32(db + 8, al)
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    _hk(c, 0x561020, 'CBaseWindow ctor', 0)
    return [_rnd(c, 0x10)]


def _vec(em, p):
    return (em.r32(p), em.r32(p + 4), em.r32(p + 8), em.r8(p + 0xc))


def _g_51f170(c):
    e = c.emu
    e.w32(0x7018d8, c.rng.choice([0, 0, 1, _r(c)]))
    b = _r(c)

    def res(em, r):
        p = em.reg('ecx')
        em.calllog.append(('reserve', 0, None, _vec(em, p) + (em.arg32(0),)))
        em.w32(p, b)
        em.w32(p + 4, b)
        em.w32(p + 8, b + 0x32 * 4)
        em.ret(eax=0, argbytes=4)
    e.hook(0x59a9b0, res)

    def dt(em, r):
        em.calllog.append(('~vector', 0, None, _vec(em, em.reg('ecx'))))
        em.ret(eax=0)
    e.hook(0x4ff9d0, dt)

    def s1c(em, r):
        p = em.arg32(0)
        em.calllog.append(('vt.1c', 0x1c, em.reg('ecx'), _vec(em, p)))
        em.w32(p + 4, em.r32(p) + 8)
        em.ret(eax=0, argbytes=4)
    self_ = _rnd(c, 0x10)
    e.w32(self_, _pyvt(c, {0x1c: s1c}))
    return [self_]


def _g_54c3f0(c):
    e = c.emu
    o = _rnd(c, 0x10)
    ok = c.rng.choice([0, 1, 0x100, 0xff01])

    def s8(em, r):
        p = em.arg32(0)
        em.calllog.append(('o.8', 8, em.reg('ecx'), tuple(em.r32(p + 4 * k) for k in range(12) if k != 6) + (em.arg32(1),)))
        em.ret(eax=ok, argbytes=8)
    e.w32(o, _pyvt(c, {8: s8, 4: _vh(c, 'o.4', 1, eax=0)}))
    self_ = _rnd(c, 0x10)
    e.w32(self_, _pyvt(c, {0x40: _vh(c, 'vt.40', 0, eax=o)}))
    return [self_]


S(0x4311f0, 'FUN_004311f0 (vector push_back)', 'thiscall', None, ret=None, gen=_g_4311f0, note='batch1907; void')
S(0x4febf0, 'ZSaveGame::ZSaveGame(const ZSaveGame&)', 'thiscall', None, ret='eax', gen=_g_4febf0, note='batch1907')
S(0x423ff0, 'FUN_00423ff0 (set MYSTR +0x23db)', 'thiscall', None, ret=None, gen=_g_423ff0,
  note='batch1907; void; stack MYSTR logged by content')
S(0x56f030, 'FUN_0056f030 (window factory)', 'thiscall', None, ret='eax', gen=_g_56f030, note='batch1907')
S(0x51f170, 'FUN_0051f170', 'thiscall', None, ret=None, gen=_g_51f170, note='batch1907; void; stack vector by content')
S(0x54c3f0, 'FUN_0054c3f0', 'thiscall', None, ret='eax', gen=_g_54c3f0,
  note='batch1907; descriptor word 6 is uninitialised in the exe and not compared')
