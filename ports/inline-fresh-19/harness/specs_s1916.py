"""specs_s1916.py - fresh slice 19, batch1916 (src/batch1916.cpp). Exe callees hooked by address with logging handlers
(pop counts checked against each callee's ret N); stack objects logged by content, never by address; logger and assert
hook from helpers22._log_world; the CRT ftou 0x633910 runs as exe code (inputs kept finite and below 2^32)."""
import struct
from pilot import S, F
from helpers22 import _rnd, _pyvt, _hk, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _rmdb(c, slots, rmn=0x100):
    e = c.emu
    rm = _rnd(c, rmn)
    e.w32(0x70039c, rm)
    db = _rnd(c, 0x10)
    e.w32(rm + 0x9b, db)
    e.w32(db, _pyvt(c, slots))
    return rm, db


def _g_48b5b0(c):
    e = c.emu
    rng = c.rng
    _log_world(c)
    if rng.random() < 0.1:
        e.w32(0x7003b0, 0)
    rm, db = _rmdb(c, {0x4c: _vh(c, 'db.4c', 1)})
    o = rng.choice([0, _rnd(c, 0x40), _rnd(c, 0x40), rm + 0x30])
    if not o and e.r32(0x7003b0) == 0:
        o = _rnd(c, 0x40)
    al = _rnd(c, 0x10)
    e.w32(al, _pyvt(c, {0x44: _vh(c, 'alloc.44', 1, eax=o)}))
    e.w32(db + 8, al)
    built = rng.choice(['this', 'this', 0, _rnd(c, 0x40)])
    _hk(c, 0x469870, 'base ctor', 0, eax=lambda em: em.reg('ecx') if built == 'this' else built)
    s = _rnd(c, 0x10)
    e.w32(s, _pyvt(c, {0x7c: _vh(c, 'self.7c', 0, eax=rng.choice([0, 1, 0x100, _r(c)]))}))
    return [s, _r(c)]


def _g_4c2ab0(c):
    e = c.emu
    rng = c.rng
    s = _rnd(c, 0x1d0)

    def f94(em, r):
        p = em.arg32(1)
        em.calllog.append(('self.94', 0, em.reg('ecx'), (em.arg32(0), p, em.rbytes(p, 12))))
        em.ret(eax=0, argbytes=8)
    e.w32(s, _pyvt(c, {0x94: f94}))
    m = rng.choice([0, 1, 2, 4, 7])
    elems = [_r(c) for _ in range(m)]
    tag = _r(c)

    def begin(em, r):
        em.calllog.append(('lst.4c', 0, em.reg('ecx'), ()))
        em.wbytes(em.arg32(0), struct.pack('<III', 1, 0, tag))
        em.ret(eax=0, argbytes=4)

    def nxt(em, r):
        p = em.arg32(0)
        st = em.rbytes(p, 12)
        em.calllog.append(('lst.5c', 0, em.reg('ecx'), (st,)))
        i = struct.unpack('<III', st)[1]
        if i < m:
            em.wbytes(p, struct.pack('<III', 1, i + 1, tag))
            em.ret(eax=elems[i], argbytes=4)
        else:
            em.wbytes(p, struct.pack('<III', 0, i, tag))
            em.ret(eax=_r(c), argbytes=4)
    e.w32(s + 0xfc, _pyvt(c, {0x4c: begin, 0x5c: nxt}))
    gs = {}
    for x in elems:
        seg = rng.choice([0, _rnd(c, 0x10), _rnd(c, 0x10)])
        if seg:
            info = _rnd(c, 0x10)
            e.w32(info, rng.choice([0, 1, 2, 3, _r(c)]))
            e.w32(seg, _pyvt(c, {0x84: _vh(c, 'seg.84', 0, eax=info)}))
        g = _rnd(c, 0x10)
        e.w32(g, _pyvt(c, {0x104: _vh(c, 'g.104', 1, eax=seg)}))
        gs[x] = g
    _rmdb(c, {0x58: _vh(c, 'db.58', 1, eax=lambda em: gs.get(em.arg32(0), 0))})
    return [s, _r(c)]


def _g_5ea870(c):
    e = c.emu
    rng = c.rng
    s = _rnd(c, 0x1d30)
    t = rng.choice([0, _rnd(c, 0x10)])
    e.w32(s + 0x1d0f, t)
    for off in (0x1d1b, 0x1d1f, 0x1d23, 0x1d27):
        e.wf32(s + off, rng.choice([0.0, 1.0, -2.0, rng.uniform(-500, 500)]))

    def spf(em, r):
        em.calllog.append(('o.198', 0, None, (em.arg32(0), em.arg32(2), em.arg32(3))))
        em.wbytes(em.arg32(1), b'%d\0' % em.arg32(3))
        em.ret(eax=0, argbytes=0)
    o = _rnd(c, 0x10)
    e.w32(o, _pyvt(c, {0x198: spf}))
    rm = _rnd(c, 0x10)
    e.w32(rm, _pyvt(c, {0x190: _vh(c, 'eng.190', 0, eax=o)}))
    e.w32(0x70039c, rm)
    _hk(c, 0x5a5c50, 'fn_5a5c50', 0)
    _hk(c, 0x5a5c60, 'fn_5a5c60', 0)

    def f80(em, r):
        em.calllog.append(('fn_5a5c80', 0x5a5c80, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.rbytes(em.arg32(2), 12))))
        em.ret(eax=0, argbytes=12)
    e.hook(0x5a5c80, f80)
    v = rng.choice([0.0, -0.0, 1e-4, 0.0001220703125, 0.00012207031, 0.00013, 0.5, 1.0, 99.6, 1e6, 4e9, -1.0,
                    -float('inf'), rng.uniform(0, 1000)])
    return [s, F(v)]


def _g_42d730(c):
    e = c.emu
    l = _rnd(c, 0x10)
    e.w32(l, _pyvt(c, {k: _vh(c, 'l.%x' % k, 1, eax=0) for k in (0xc, 0x40, 0x48, 0x50, 0x58, 0x5c, 0x68)}))
    return [_rnd(c, 0x1b60), l]


S(0x48b5b0, 'ZEngineDataBase::AllocGeomCallEvent', 'thiscall', None, ret='eax', gen=_g_48b5b0,
  note='batch1916; SEH not ported')
S(0x4c2ab0, 'ZMusicControl::SendMusicInfo', 'thiscall', None, ret=None, gen=_g_4c2ab0,
  note='batch1916; void; stack iterator by content')
S(0x5ea870, 'FUN_005ea870 (numeric display)', 'thiscall', None, ret=None, gen=_g_5ea870, nan_heap=True,
  note='batch1916; void; cookie not ported; ftou exe code; v finite, < 2^32')
S(0x42d730, 'ZSysInterface::Load', 'thiscall', None, ret=None, gen=_g_42d730, note='batch1916; void')
