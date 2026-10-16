"""specs_s1903.py - fresh slice 19, batch1903 (src/batch1903.cpp). Exe callees hooked by address with logging handlers;
vtables are Python handlers that log their arguments (pointer arguments to stack data are logged by the values they
point at); logger and assert hook from helpers22._log_world."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _hk, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _g_6120f0(c):
    e = c.emu
    self_ = _rnd(c, 0x1400)
    o = _rnd(c, 0x10)
    e.w32(o, _pyvt(c, {4: _vh(c, 'o.4', 2)}))
    e.w32(self_ + 0x13e7, o)
    _hk(c, 0x612030, 'fn_612030', 2)
    return [self_, c.rng.choice([0, 0x800, 1, 0x801, _r(c)]), _r(c), _r(c)]


def _g_5f3bf0(c):
    e = c.emu
    pa = _rnd(c, 0x10)
    e.w32(pa, _pyvt(c, {0x28: _vh(c, 'a.28', 0), 0x24: _vh(c, 'a.24', 0)}))
    pb = _rnd(c, 0x10)
    e.w32(pb, _pyvt(c, {0x28: _vh(c, 'b.28', 0), 0x24: _vh(c, 'b.24', 0)}))
    self_ = _rnd(c, 8)
    e.w32(self_, pa)
    e.wbytes(self_ + 4, bytes([c.rng.choice([0, 4, 3, 0x84])]))
    if c.rng.random() < 0.15:
        return [self_, self_]
    o = _rnd(c, 8)
    e.w32(o, pb)
    e.wbytes(o + 4, bytes([c.rng.choice([0, 4, 1, 0x44])]))
    return [self_, o]


def _g_56a030(c):
    e = c.emu
    self_ = _rnd(c, 0x1d0)
    e.w32(self_ + 0x1c5, c.rng.choice([2, 2, 5, 5, 0, 3]))
    e.w32(self_ + 0x94, 0 if c.rng.random() < 0.3 else _rnd(c, 0x132b0))
    e.w32(self_, _pyvt(c, {0x64: _vh(c, 'vt.64', 1)}))
    db = _rnd(c, 0x10)
    e.w32(db, _pyvt(c, {0x4c: _vh(c, 'db.4c', 1)}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    _hk(c, 0x563a50, 'SetupScanLinesAndHelp', 0)
    return [self_]


def _g_5f2f70(c):
    e = c.emu
    n = c.rng.choice([0, 1, 5, 20])
    buf = _rnd(c, 0x40)
    e.wbytes(buf, bytes(c.rng.randint(1, 255) for _ in range(n)) + b'\0')
    self_ = _rnd(c, 0x10)
    e.w32(self_ + 8, buf)
    e.w32(self_ + 0xc, buf + c.rng.choice([0, n, n + 1, n + 2, 0x20]))
    s = _rnd(c, 0x10)
    d = c.rng.choice([0, n, n + 3])

    def asg(em, r):
        em.calllog.append(('assign', 0x5f2d60, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        b = _r(c) & 0xfffff
        em.w32(em.reg('ecx'), b)
        em.w32(em.reg('ecx') + 4, b + d)
        em.ret(eax=0, argbytes=8)
    e.hook(0x5f2d60, asg)
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    return [self_, s]


def _g_65e130(c):
    _hk(c, 0x65f0f0, 'ZGeometryDecal::End', 0)
    _hk(c, 0x63418c, 'eh vector dtor iterator', 4)
    return [_rnd(c, 0xd0)]


def _g_4e83f0(c):
    """A random binary tree (nodes: +0 parent, +4 and +8 children) with a nil node; the argument is a random node."""
    e = c.emu
    nil = _rnd(c, 0x10)
    nodes = []
    for i in range(c.rng.choice([1, 2, 4, 8, 12])):
        a = _rnd(c, 0x10)
        e.w32(a + 4, nil)
        e.w32(a + 8, nil)
        if nodes:
            while True:
                p = c.rng.choice(nodes)
                side = c.rng.choice([4, 8])
                if e.r32(p + side) == nil:
                    break
            e.w32(p + side, a)
            e.w32(a, p)
        else:
            e.w32(a, nil)
        nodes.append(a)
    self_ = _rnd(c, 0x10)
    e.w32(self_ + 8, nil)
    return [self_, c.rng.choice(nodes)]


def _g_49e070(c):
    e = c.emu
    _log_world(c, pslot=0x30)
    self_ = _rnd(c, 0x10)
    if c.rng.random() < 0.2:
        e.w32(self_ + 4, 0)
    ent = _rnd(c, 0x10)
    _hk(c, 0x49e140, 'Lookup', 2, eax=c.rng.choice([0, ent]))
    return [self_, _r(c)]


def _g_4a90b0(c):
    e = c.emu
    g = _rnd(c, 0x10)
    ok = c.rng.choice([0, 1, 0x100, 0xffffff01])

    def h21c(em, r):
        p = em.arg32(0)
        em.calllog.append(('g.21c', 0x21c, em.reg('ecx'), tuple(em.r32(p + 4 * k) for k in range(3))))
        em.ret(eax=0, argbytes=4)
    e.w32(g, _pyvt(c, {0x1e0: _vh(c, 'g.1e0', 1, eax=ok), 0x21c: h21c}))
    return [_rnd(c, 0x10), g]


S(0x6120f0, 'FUN_006120f0', 'thiscall', None, ret=None, gen=_g_6120f0, note='batch1903; void')
S(0x5f3bf0, 'FUN_005f3bf0 (handle operator=)', 'thiscall', None, ret='eax', gen=_g_5f3bf0, note='batch1903; returns this')
S(0x56a030, 'CLinkMenu::Init2', 'thiscall', None, ret=None, gen=_g_56a030, note='batch1903; void')
S(0x5f2f70, 'SerialInfo_t::loadstring', 'thiscall', None, ret=None, gen=_g_5f2f70, note='batch1903; void')
S(0x65e130, 'FUN_0065e130 (decal owner dtor)', 'thiscall', None, ret=None, gen=_g_65e130,
  note='batch1903; void; SEH frame not ported')
S(0x4e83f0, 'ZBinTree::Next', 'thiscall', None, ret='eax', gen=_g_4e83f0, note='batch1903; random trees')
S(0x49e070, 'ResourceCollection::GetResourceText', 'thiscall', None, ret='eax', gen=_g_49e070, note='batch1903')
S(0x4a90b0, 'ZSIGTE::InitPointer', 'thiscall', None, ret=None, gen=_g_4a90b0,
  note='batch1903; void; stack vector logged by value; cookie check not ported')
