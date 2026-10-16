"""specs_s1917.py - fresh slice 19, batch1917 (src/batch1917.cpp). Exe callees hooked by address with logging handlers
(pop counts checked against each callee's ret N); stack objects logged by content, never by address; logger and assert
hook from helpers22._log_world."""
from pilot import S
from helpers22 import _rnd, _pyvt, _hk, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _g_50a770(c):
    e = c.emu
    rng = c.rng
    _log_world(c)
    a = _rnd(c, 8)
    ta = rng.choice([3, 3, 4, 4, 0, 1, 5, 0xff])
    e.wbytes(a + 4, bytes([ta]))
    if ta == 4:
        ob = _rnd(c, 0x10)
        e.w32(ob, _pyvt(c, {0x34: _vh(c, 'ob.34', 0)}))
        e.w32(a, ob)
    r = _rnd(c, 8)
    e.wbytes(r + 4, bytes([rng.choice([0, 1, 1, 2, 3, 0x80])]))
    pr = _rnd(c, 0x10)
    pa, pb = _rnd(c, 0x10), _rnd(c, 0x10)
    e.w32(pr + 4, pa)
    e.w32(pr + 8, pb)
    _hk(c, 0x5003d0, 'elem', 1, eax=lambda em: a if em.reg('ecx') == pa else r)
    outv = _r(c)

    def f88(em, r_):
        em.calllog.append(('o.88', 0, em.reg('ecx'), (em.arg32(0), em.r32(em.arg32(1)))))
        em.w32(em.arg32(1), outv)
        em.ret(eax=0, argbytes=8)
    o = _rnd(c, 0x10)
    e.w32(o, _pyvt(c, {0x88: f88}))
    rm = _rnd(c, 0x100)
    e.w32(0x70039c, rm)
    db = _rnd(c, 0x10)
    e.w32(rm + 0x9b, db)
    e.w32(db, _pyvt(c, {0x134: _vh(c, 'db.134', 0, eax=o)}))
    return [_rnd(c, 0x10), pr]


def _g_4437b0(c):
    e = c.emu
    rng = c.rng
    s = _rnd(c, 0x80)
    e.wbytes(s + 0x5c, bytes([rng.choice([0, 1, 2])]))
    n = rng.choice([0, 1, 3])
    lst = rng.choice([0, _rnd(c, 4 + 4 * n), _rnd(c, 4 + 4 * n)])
    if lst:
        e.w32(lst, n | (rng.getrandbits(16) << 16))
    e.w32(s + 0x7b, lst)
    geo = rng.choice([0, _rnd(c, 0x10), _rnd(c, 0x10)])
    e.w32(s, _pyvt(c, {0x20: _vh(c, 'self.20', 0, eax=geo)}))
    dyn = rng.choice([0, _rnd(c, 0x10)])
    if dyn:
        e.w32(dyn, _pyvt(c, {0x2f0: _vh(c, 'dyn.2f0', 1, eax=0), 0x2f4: _vh(c, 'dyn.2f4', 1, eax=0)}))
    tg = rng.choice([0, _rnd(c, 0x10), _rnd(c, 0x10)])
    if tg:
        e.w32(tg, _pyvt(c, {0x2c8: _vh(c, 'tg.2c8', 1, eax=0), 0x2cc: _vh(c, 'tg.2cc', 1, eax=0)}))
    _hk(c, 0x4daff0, 'GetDynamicTreeGroup', 0, eax=dyn)
    _hk(c, 0x4db7e0, 'GetTreeGroup', 0, eax=tg)
    _hk(c, 0x443c80, 'RemoveStaticChild', 1)
    _hk(c, 0x442050, 'AddStaticChild', 1)
    return [s, rng.choice([0, 1, 2, 0x100, _r(c)])]


def _g_4208f0(c):
    e = c.emu
    rng = c.rng
    name = rng.choice([b'', b'a', b'ab', b'c:x', b'\\\\srv\\f', b'\\x', b'data\\levels\\c01a.gms', b'x:', b'\\\\'])
    np = _rnd(c, len(name) + 1)
    e.wbytes(np, name + b'\0')
    s = _rnd(c, 0x130)
    _hk(c, 0x4cbeb0, 'MYSTR()', 0)
    _hk(c, 0x4cc5f0, 'Length', 0, eax=rng.choice([0, 0, 5, _r(c)]))

    def add(em, r):
        em.calllog.append(('MYSTR+=', 0, em.reg('ecx'), (em.rbytes(em.arg32(0), 8),)))
        em.ret(eax=em.reg('ecx'), argbytes=4)
    e.hook(0x4cc2c0, add)
    mark = _rnd(c, 8)

    def ctor(em, r):
        em.calllog.append(('MYSTR(const char*)', 0, None, (em.arg32(0),)))
        em.wbytes(em.reg('ecx'), em.rbytes(mark, 8))
        em.ret(eax=em.reg('ecx'), argbytes=4)
    e.hook(0x4cbe80, ctor)

    def dtor(em, r):
        em.calllog.append(('~MYSTR', 0, None, (em.rbytes(em.reg('ecx'), 8),)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x4cbec0, dtor)
    return [s, _rnd(c, 0x10), np]


S(0x50a770, 'FUN_0050a770 (string value native)', 'thiscall', None, ret=None, gen=_g_50a770,
  note='batch1917; void; out word by content')
S(0x4437b0, 'ZTreeGroup::MakePrivate', 'thiscall', None, ret=None, gen=_g_4437b0, note='batch1917; void')
S(0x4208f0, 'ZSysInterfaceGC::ConvertFileName', 'thiscall', None, ret='eax', gen=_g_4208f0,
  note='batch1917; SEH, cookie not ported; MYSTR temp by content')
