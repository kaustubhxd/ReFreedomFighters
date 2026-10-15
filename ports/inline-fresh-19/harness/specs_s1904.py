"""specs_s1904.py - fresh slice 19, batch1904 (src/batch1904.cpp). Exe callees hooked by address with logging handlers
(both sides reach them); vtables are Python handlers that log their arguments; stack data behind pointer arguments is
logged by value. 0x4a90b0 (ZSIGTE::InitPointer, batch1903) and the sqrt thunk 0x634d7c run as exe code."""
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


def _g_42a7b0(c):
    _hk(c, 0x4cbec0, 'MYSTR::~MYSTR', 0)
    _hk(c, 0x42bae0, 'base dtor', 0)
    _hk(c, 0x634273, 'sdel', 2, pop=0)
    return [_rnd(c, 0x1e90), c.rng.choice([0, 1, 2, 3, _r(c)])]


def _g_4f50f0(c):
    e = c.emu
    g = _rnd(c, 0xd0)
    e.w32(g, _pyvt(c, {0x1e0: _vh(c, 'g.1e0', 1, eax=c.rng.choice([0, 1, 0x100, 0xff01]))}))
    _hk(c, 0x4ef210, 'ZWINOBJ::CopyData', 1)
    return [_rnd(c, 0xd0), g]


def _g_63ad70(c):
    e = c.emu
    self_ = _rnd(c, 0x20)
    nb = c.rng.choice([0, 1, 2, 3, 4])
    blocks = []
    for i in range(nb):
        b = _rnd(c, 0x10 + 8 * 8)
        free = c.rng.choice([0xffff, 0xffff, 0, 1, 7])
        e.wbytes(b + 2, struct.pack('<H', free))
        for k in range(8):
            e.wbytes(b + 0x10 + 8 * k, struct.pack('<H', c.rng.choice([0xffff, (k + 1) % 8, c.rng.randint(0, 7)])))
        blocks.append(b)
    for i, b in enumerate(blocks):   # a ring, sometimes broken by a 0 link
        e.w32(b + 8, 0 if c.rng.random() < 0.15 else blocks[(i + 1) % nb])
    e.w32(self_ + 8, c.rng.choice(blocks) if blocks else 0)
    grow = c.rng.choice([0, 1, 1])
    nbk = _rnd(c, 0x10 + 8 * 8)
    e.wbytes(nbk + 2, struct.pack('<H', c.rng.choice([0, 3, 0xffff])))

    def g(em, r):
        em.calllog.append(('grow', 0x63b2c0, em.reg('ecx'), ()))
        if grow:
            em.w32(em.reg('ecx') + 8, nbk)
        em.ret(eax=(_r(c) & ~0xff) | grow)
    e.hook(0x63b2c0, g)
    return [self_]


def _g_4f3f70(c):
    e = c.emu
    self_ = _rnd(c, 0x10)
    chain = [_rnd(c, 0x10) for _ in range(c.rng.choice([0, 1, 3]))]
    mode = c.rng.choice(['none', 'self', 'child', 'other'])
    if mode == 'none':
        w = 0
    elif mode == 'self':
        w = self_
    else:
        w = chain[0] if chain else self_
    # parent links: chain[i] -> chain[i+1] -> ... -> self (child) or -> 0 (other)
    for i, x in enumerate(chain):
        nxt = chain[i + 1] if i + 1 < len(chain) else (self_ if mode == 'child' else 0)
        e.w32(x, _pyvt(c, {0x20: _vh(c, 'w.20', 0, eax=nxt)}))
    m = _rnd(c, 0x10)
    e.w32(m, _pyvt(c, {0x2f0: _vh(c, 'm.2f0', 0, eax=w), 0x2f4: _vh(c, 'm.2f4', 2, eax=0)}))
    e.w32(self_, _pyvt(c, {0x2c4: _vh(c, 'vt.2c4', 0, eax=m), 0xbc: _vh(c, 'vt.bc', 1, eax=0),
                           0x20: _vh(c, 'self.20', 0, eax=0)}))
    return [self_, _r(c), _r(c)]


def _g_551670(c):
    e = c.emu
    ev = c.rng.choice([0, _rnd(c, 0x10), _rnd(c, 0x10)])
    if ev:
        arr = _rnd(c, 0x10)
        e.w32(ev, _pyvt(c, {0x4c: _vh(c, 'ev.4c', 0, eax=arr)}))
    f = _rnd(c, 0x10)
    e.w32(f, _pyvt(c, {0x18: _vh(c, 'f.18', 1, eax=ev)}))
    els = [_rnd(c, 8) for _ in range(3)]
    _hk(c, 0x5003d0, 'elem', 1, eax=lambda em: els[em.arg32(0) % 3])
    _hk(c, 0x500360, 'setf', 1)
    _hk(c, 0x5002f0, 'seti', 1)
    return [_rnd(c, 0x10), f, _r(c), _rnd(c, 0x10)]


def _g_57be70(c):
    e = c.emu
    o = c.rng.choice([0, _rnd(c, 0x40)])
    al = _rnd(c, 0x10)
    e.w32(al, _pyvt(c, {0x44: _vh(c, 'alloc.44', 1, eax=o)}))
    db = _rnd(c, 0x20)
    e.w32(db + 8, al)
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    _hk(c, 0x561020, 'CBaseWindow ctor', 0)
    return [_rnd(c, 0x10)]


def _g_451b30(c):
    e = c.emu
    g = _rnd(c, 0x50)
    for o in (0x40, 0x44, 0x48):
        e.wf32(g + o, c.rng.choice([0.0, 1.0, -2.5, c.rng.uniform(-1000, 1000), c.rng.uniform(-1, 1)]))
    self_ = _rnd(c, 0x30)
    e.w32(self_ + 8, g)

    def vec(name, addr):
        def h(em, r):
            p = em.arg32(0)
            em.calllog.append((name, addr, em.reg('ecx'), (p, em.r32(p), em.r32(p + 4), em.r32(p + 8))))
            em.ret(eax=0, argbytes=4)
        e.hook(addr, h)
    vec('SetCen', 0x4dc600)
    vec('fn_4dd060', 0x4dd060)
    _hk(c, 0x4dce50, 'SetRadius', 1)
    return [self_]


def _g_509ff0(c):
    e = c.emu
    self_ = _rnd(c, 0x10)
    a = _rnd(c, 0x20)
    e.w32(self_ + 0xc, a)
    n = c.rng.choice([0, 1, 3])
    st = {'k': 0}

    def init(em, r):
        p = em.arg32(0)
        em.calllog.append(('l.4c', 0x4c, em.reg('ecx'), ()))
        em.w32(p, 0)
        em.ret(eax=0, argbytes=4)

    def nxt(em, r):
        p = em.arg32(0)
        em.calllog.append(('l.5c', 0x5c, em.reg('ecx'), (em.r32(p),)))
        st['k'] += 1
        em.w32(p, 1 if st['k'] <= n else 0)
        em.ret(eax=_r(c), argbytes=4)
    if c.rng.random() < 0.2:
        e.w32(a + 0x18, 0)
    else:
        l = _rnd(c, 0x10)
        e.w32(l, _pyvt(c, {0x4c: init, 0x5c: nxt}))
        e.w32(a + 0x18, l)
    gs = [0, _rnd(c, 0x10)]
    e.w32(gs[1], _pyvt(c, {0xbc: _vh(c, 'g.bc', 1, eax=0)}))
    db = _rnd(c, 0x10)
    e.w32(db, _pyvt(c, {0x58: _vh(c, 'db.58', 1, eax=lambda em: c.rng.choice(gs))}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    return [self_, _r(c)]


def _g_557930(c):
    e = c.emu
    if c.rng.random() < 0.4:
        g = _rnd(c, 0x28)
        e.w32(g, _pyvt(c, {0x24: _vh(c, 'g.24', 0)}))
        e.w32(0x713f04, g)
    else:
        e.w32(0x713f04, 0)
    obj = c.rng.choice([0, _rnd(c, 0x30), _rnd(c, 0x30)])

    def new(em, r):
        em.calllog.append(('new', 0x41e290, None, (em.arg32(0),)))
        em.ret(eax=obj, argbytes=0)
    e.hook(0x41e290, new)
    _hk(c, 0x5577d0, 'init', 0)
    return [_rnd(c, 0x10)]


def _g_4a9330(c):
    e = c.emu
    self_ = _rnd(c, 0xc0)
    old = c.rng.choice([0, _r(c), 7])
    e.w32(self_ + 0xbb, old)
    gs = [0]
    for _ in range(2):
        g = _rnd(c, 0x10)

        def h21c(em, r):
            p = em.arg32(0)
            em.calllog.append(('g.21c', 0x21c, em.reg('ecx'), tuple(em.r32(p + 4 * k) for k in range(3))))
            em.ret(eax=0, argbytes=4)
        e.w32(g, _pyvt(c, {0xbc: _vh(c, 'g.bc', 1, eax=0), 0x1e0: _vh(c, 'g.1e0', 1, eax=c.rng.choice([0, 1])),
                           0x21c: h21c}))
        gs.append(g)
    db = _rnd(c, 0x10)
    e.w32(db, _pyvt(c, {0x58: _vh(c, 'db.58', 1, eax=lambda em: c.rng.choice(gs))}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    return [self_, c.rng.choice([old, 0, _r(c), 7])]


L = '0x42a7b0 0x4f50f0 0x63ad70 0x4f3f70 0x551670 0x57be70 0x451b30 0x509ff0 0x557930 0x4a9330'
S(0x42a7b0, 'FUN_0042a7b0 (scalar deleting dtor)', 'thiscall', None, ret='eax', gen=_g_42a7b0, note='batch1904')
S(0x4f50f0, 'ZFRAME::CopyData', 'thiscall', None, ret=None, gen=_g_4f50f0, note='batch1904; void')
S(0x63ad70, 'ZDrawArray<ZDrawResource,ZDrawResource,ZArrayBlock>::Add', 'thiscall', None, ret='eax', gen=_g_63ad70,
  note='batch1904; random block rings; grow hooked')
S(0x4f3f70, 'ZWINDOW::OnWindowClose', 'thiscall', None, ret='al', gen=_g_4f3f70, note='batch1904; returns 0')
S(0x551670, 'Signature_fii_EventTranslator_t::handleEventTranslation', 'thiscall', None, ret='eax', gen=_g_551670,
  note='batch1904; parameter setters hooked')
S(0x57be70, 'FUN_0057be70 (window factory)', 'thiscall', None, ret='eax', gen=_g_57be70,
  note='batch1904; SEH frame not ported; alloc slot gets ecx as a stack word (GUESS)')
S(0x451b30, 'ZCubeGrid::CalcCenSize', 'thiscall', None, ret=None, gen=_g_451b30, note='batch1904; void')
S(0x509ff0, 'FUN_00509ff0', 'thiscall', None, ret=None, gen=_g_509ff0, note='batch1904; void; iterator by value')
S(0x557930, 'FUN_00557930 (singleton get)', 'thiscall', None, ret='eax', gen=_g_557930, note='batch1904; .data global')
S(0x4a9330, 'ZSIGTE::SetPointer', 'thiscall', None, ret=None, gen=_g_4a9330,
  note='batch1904; void; InitPointer runs as exe code')
