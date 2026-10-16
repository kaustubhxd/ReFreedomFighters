"""specs_s1912.py - fresh slice 19, batch1912 (src/batch1912.cpp). Exe callees hooked by address with logging handlers
(pop counts checked against each callee's ret N); stack objects logged by content, never by address."""
from pilot import S
from helpers22 import _rnd, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _rm(c, n=0x100):
    e = c.emu
    rm = _rnd(c, n)
    e.w32(0x70039c, rm)
    return rm


def _g_459ab0(c):
    e = c.emu
    rm = _rm(c)
    fr = c.rng.choice([0, 1, _r(c)])
    e.w32(rm + 0x3c, fr)
    s = _rnd(c, 0x360)
    e.w32(s + 0x20, c.rng.choice([fr, fr, fr ^ 1, _r(c)]))
    e.w32(s + 0x1c, c.rng.choice([0, 1, 2, 3, 4, 5, 0xffffffff, _r(c)]))
    e.w32(s + 0x40, c.rng.choice([0, _r(c), _r(c)]))
    mb = bytes(c.rng.getrandbits(8) for _ in range(0x24))
    vb = bytes(c.rng.getrandbits(8) for _ in range(0xc))

    def fill(em, r):
        em.calllog.append(('vt80', 0, em.reg('ecx'), ()))
        em.wbytes(em.arg32(0), mb)
        em.wbytes(em.arg32(1), vb)
        em.ret(eax=0, argbytes=8)
    e.w32(s, _pyvt(c, {0x80: fill}))

    def draw(em, r):
        em.calllog.append(('b.28', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.rbytes(em.arg32(2), 0x24),
                                                     em.rbytes(em.arg32(3), 0xc), em.arg32(4), em.arg32(5))))
        em.ret(eax=0, argbytes=24)
    b = _rnd(c, 0x10)
    e.w32(b, _pyvt(c, {0x28: draw}))
    return [s, b, _rnd(c, 0x70)]


def _g_4ca8f0(c):
    e = c.emu
    rm = _rm(c)
    db = _rnd(c, 0x10)
    e.w32(rm + 0x9b, db)
    e.w32(db, _pyvt(c, {0x114: _vh(c, 'RegisterZMsg', 4)}))
    _hk(c, 0x469870, 'base ctor', 0)
    return [_rnd(c, 0xa0)]


def _g_5c7af0(c):
    e = c.emu
    rm = _rm(c)
    db = _rnd(c, 0x10)
    e.w32(rm + 0x9b, db)
    e.w32(db, _pyvt(c, {0x34: _vh(c, 'db.34', 1, eax=0)}))
    _hk(c, 0x4690b0, 'sized delete', 2, pop=0)
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    return [_rnd(c, 0x60), c.rng.choice([0, 1, 3, 4, 5, 7, _r(c)])]


def _g_4f4ab0(c):
    e = c.emu
    o = c.rng.choice([0, _rnd(c, 0xa0), _rnd(c, 0xa0)])
    _hk(c, 0x45c4b0, 'new', 1, eax=o, pop=0)
    _hk(c, 0x4f97f0, 'base ctor', 3)

    def h(em, r):
        em.calllog.append(('fn_4f4990', 0x4f4990, em.reg('ecx'), (em.reg('edx'), em.arg32(0), em.arg32(1))))
        em.ret(eax=0x5a5a0000 | (em.reg('edx') & 0xffff), argbytes=8)
    e.hook(0x4f4990, h)
    return [_r(c), _r(c), _r(c), c.rng.choice([0, _r(c), _rnd(c, 0x10)])]


def _ty(tab, hi, lo):
    if hi == 0:
        return tab[lo]
    if 0xd8 <= hi <= 0xdb:
        return 7
    if 0xdc <= hi <= 0xdf:
        return 8
    if hi == 0xff and lo >= 0xfe:
        return 0
    return 0x1d


def _g_622ef0(c):
    """Buffer of random units; end is picked among the positions where the exe compares p with end (simulated from the
    exe's step rules), so the walk always stops inside the buffer."""
    e = c.emu
    rng = c.rng
    tab = bytes(rng.choice([0, 1, 2, 5, 6, 7, 8, 9, 10, 10, 9, 0x16, 0x1d]) for _ in range(256))
    enc = _rnd(c, 0x150)
    e.wbytes(enc + 0x4c, tab)
    n = rng.choice([0, 2, 6, 20, 60])
    buf = bytearray()
    for _ in range(n + 4):
        buf += bytes([rng.choice([0, 0, 0, 0xd8, 0xdc, 0xff, 0x30, rng.getrandbits(8)]), rng.getrandbits(8)])
    lim = len(buf) - 8
    pts = [0]
    q = 0
    while q < lim:
        t = _ty(tab, buf[q], buf[q + 1])
        if t == 6:
            q += 3
        elif t == 7:
            q += 4
        elif t == 9:
            q += 2
            pts.append(q)
            if _ty(tab, buf[q], buf[q + 1]) == 10:
                q += 2
        else:
            q += 2
        pts.append(q)
    pts = [x for x in pts if x <= lim]
    b = _rnd(c, len(buf) + 8)
    e.wbytes(b, bytes(buf))
    pos = _rnd(c, 8)
    e.w32(pos, rng.choice([0, 1, _r(c)]))
    e.w32(pos + 4, rng.choice([0, 0xffffffff, _r(c)]))
    return [enc, b, b + rng.choice(pts), pos]


S(0x459ab0, 'ZParticleBox::DrawBufferViewUpdate', 'thiscall', None, ret='al', gen=_g_459ab0,
  note='batch1912; returns 0; stack m/v logged by content; cookie not ported')
S(0x4ca8f0, 'FUN_004ca8f0 (constructor)', 'thiscall', None, ret='eax', gen=_g_4ca8f0, note='batch1912; SEH not ported')
S(0x5c7af0, 'ZFFShowMessage::`scalar deleting destructor', 'thiscall', None, ret='eax', gen=_g_5c7af0,
  note='batch1912; SEH not ported')
S(0x4f4ab0, 'FUN_004f4ab0 (factory)', 'fastcall', None, ret='eax', gen=_g_4f4ab0, note='batch1912; SEH not ported')
S(0x622ef0, 'FUN_00622ef0 (big2 updatePosition)', 'cdecl', None, ret=None, gen=_g_622ef0, note='batch1912; void; 0x62c640 exe code')
