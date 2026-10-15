"""specs_s1905.py - fresh slice 19, batch1905 (src/batch1905.cpp). Exe callees hooked by address with logging handlers;
vtables are Python handlers that log their arguments (stack buffers logged by content); COM-style slots log no ecx."""
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


def _db(c, slots):
    e = c.emu
    db = _rnd(c, 0x20)
    e.w32(db, _pyvt(c, slots))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    return db


def _g_56ce70(c):
    e = c.emu
    self_ = _rnd(c, 0x90)
    m = _rnd(c, 0xe0)
    e.w32(m + 0xcb, _pyvt(c, {0x14: _vh(c, 'm.14', 0, eax=c.rng.choice([0, 1, 1, 2]))}))
    e.w32(self_, _pyvt(c, {0x84: _vh(c, 'vt.84', 0, eax=m)}))
    o = _rnd(c, 0x10)
    v = c.rng.choice([0, _r(c)])

    def h88(em, r):
        p = em.arg32(1)
        em.calllog.append(('o.88', 0x88, em.reg('ecx'), (em.arg32(0), em.r32(p))))
        em.w32(p, v)
        em.ret(eax=0, argbytes=8)
    e.w32(o, _pyvt(c, {0x88: h88}))
    _db(c, {0x138: _vh(c, 'db.138', 0, eax=o)})
    _hk(c, 0x5625c0, 'CBaseWindow::Leave', 1)
    return [self_, c.rng.choice([0, 0, 1, _r(c)])]


def _g_650f30(c):
    e = c.emu
    n = c.rng.choice([0, 1, 5, 40, 256, 300])
    e.w32(0x6f5a98, n)
    self_ = _rnd(c, 0x20)
    e.w32(self_ + 0x10, _rnd(c, max(n, 1)))
    lod = c.rng.randint(0, 3)
    if c.rng.random() < 0.3:   # random table contents (incl. NaN) for that lod
        for k in range(8):
            e.w32(0x6c33b8 + lod * 32 + 4 * k, c.rng.choice([0x7fc00000, _r(c),
                  struct.unpack('<I', struct.pack('<f', c.rng.uniform(0, 300)))[0]]))
    return [self_, lod]


def _g_4947f0(c):
    e = c.emu
    self_ = _rnd(c, 0xa10)
    els = [_rnd(c, 0x14) for _ in range(c.rng.choice([1, 2, 4, 7]))]
    for x in els:
        e.w32(x + 8, c.rng.choice([0, 5, 10, 0x80000000, _r(c)]))
        e.w32(x + 4, c.rng.choice([0, 1, -1 & 0xffffffff, _r(c)]))
    for i, x in enumerate(els):
        e.w32(x + 0xc, els[i - 1] if i else 0)
        e.w32(x + 0x10, els[i + 1] if i + 1 < len(els) else 0)
    e.w32(self_ + 0xa04, els[0])
    _hk(c, 0x4920e0, 'LinkBefore', 2)
    return [self_, c.rng.choice(els), c.rng.choice([0, 5, 10, 11, 0x80000000, _r(c)])]


def _g_fact(c):
    e = c.emu
    o = c.rng.choice([0, _rnd(c, 0x50)])
    al = _rnd(c, 0x10)
    e.w32(al, _pyvt(c, {0x44: _vh(c, 'alloc.44', 1, eax=o)}))
    db = _rnd(c, 0x20)
    e.w32(db + 8, al)
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    _hk(c, 0x469870, 'base ctor', 0)
    return [_rnd(c, 0x10)]


def _g_578db0(c):
    e = c.emu
    s = _rnd(c, 0x10)
    txt = bytes(c.rng.randint(1, 255) for _ in range(c.rng.randint(0, 60))) + b'\0'

    def f198(em, r):
        buf = em.arg32(1)
        em.calllog.append(('s.198', 0x198, None, (em.arg32(0), em.arg32(2), em.arg32(3))))
        em.wbytes(buf, txt)
        em.ret(eax=0, argbytes=0)
    e.w32(s, _pyvt(c, {0x198: f198}))
    eng = _rnd(c, 0xa0)
    e.w32(eng, _pyvt(c, {0x190: _vh(c, 'eng.190', 0, eax=s)}))
    o = _rnd(c, 0x10)
    fl = c.rng.choice([None, 0, 1, 0x80])

    def f90(em, r):
        buf, p = em.arg32(0), em.arg32(1)
        em.calllog.append(('o.90', 0x90, em.reg('ecx'), (em.rbytes(buf, 64).split(b'\0')[0], em.r8(p))))
        if fl is not None:
            em.wbytes(p, bytes([fl]))
        em.ret(eax=0, argbytes=8)
    e.w32(o, _pyvt(c, {0x90: f90}))
    db = _rnd(c, 0x20)
    e.w32(db, _pyvt(c, {0x134: _vh(c, 'db.134', 0, eax=o)}))
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    return [_rnd(c, 0x1a0)]


def _g_60ff30(c):
    e = c.emu
    st = c.rng.randint(0, 7)
    vals = [c.rng.choice([0, 1, 2, _r(c)]) for _ in range(3)]
    for k in range(3):
        e.w32(0x724868 + 0x20 * k + 4 * st, c.rng.choice([vals[k], _r(c)]))
    dev = _rnd(c, 0x10)
    e.w32(dev, _pyvt(c, {0xfc: _vh(c, 'dev.fc', 4, eax=0, log_ecx=False)}))
    e.w32(0x724a00, dev)
    return [st, vals[0], vals[1], vals[2]]


def _g_54c8f0(c):
    e = c.emu
    self_ = _rnd(c, 0x63f0)
    o = _rnd(c, 0x10)
    e.w32(o, _pyvt(c, {0x3c: _vh(c, 'o.3c', 2, eax=0, log_ecx=False), 0x44: _vh(c, 'o.44', 2, eax=0, log_ecx=False)}))
    e.w32(self_ + 0x63ec, o)
    _hk(c, 0x549780, 'fn_549780', 1)
    v = c.rng.choice([0, 50, 100, 101, 99999, 100000, 100001, -5 & 0xffffffff, _r(c)])
    _hk(c, 0x5496e0, 'fn_5496e0', 1, eax=v)
    return [self_, _rnd(c, 0x30)]


S(0x56ce70, 'CMultiplayerKOTH::Leave', 'thiscall', None, ret=None, gen=_g_56ce70, note='batch1905; void')
S(0x650f30, 'ZRender::SetLOD', 'thiscall', None, ret=None, gen=_g_650f30, note='batch1905; void; .data table')
S(0x4947f0, 'ZTimeUpdateList::SetTime', 'thiscall', None, ret=None, gen=_g_4947f0, note='batch1905; void; random lists')
for _a, _v in ((0x4b2f70, 0x6912e4), (0x4b31f0, 0x6919b0), (0x4bec30, 0x693204), (0x5b75b0, 0x6b2304)):
    S(_a, 'FUN_%08x (event factory, vptr 0x%x)' % (_a, _v), 'thiscall', None, ret='eax', gen=_g_fact,
      note='batch1905; SEH frame not ported; alloc slot gets ecx (GUESS)')
S(0x578db0, 'FUN_00578db0', 'thiscall', None, ret='al', gen=_g_578db0, note='batch1905; flag byte; cookie not ported')
S(0x60ff30, 'FUN_0060ff30 (sampler state cache)', 'fastcall', None, ret=None, gen=_g_60ff30, note='batch1905; .data')
S(0x54c8f0, 'FUN_0054c8f0', 'thiscall', None, ret=None, gen=_g_54c8f0, note='batch1905; void; COM-style slots')
