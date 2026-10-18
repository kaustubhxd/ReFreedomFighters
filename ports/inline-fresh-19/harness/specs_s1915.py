"""specs_s1915.py - fresh slice 19, batch1915 (src/batch1915.cpp). Exe callees hooked by address with logging handlers
(pop counts checked against each callee's ret N); stack objects logged by content, never by address; CRT imports stubbed
through the IAT; logger from helpers22._log_world."""
from pilot import S
from helpers22 import _rnd, _pyvt, _hk, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _hn(c, addr, name, nargs, eax=0, pop=None):
    """_hk without ecx in the log (cdecl or argument-less callees, where ecx is a leftover)."""
    def h(em, r):
        em.calllog.append((name, addr, None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=eax(em) if callable(eax) else eax, argbytes=4 * nargs if pop is None else pop)
    c.emu.hook(addr, h)


def _g_5fd6f0(c):
    e = c.emu
    rng = c.rng
    s = _rnd(c, 0x40)
    sch = rng.choice([0, 0, 0, _rnd(c, 0x10)])
    if sch:
        e.w32(sch, _pyvt(c, {0: _vh(c, 'sch.0', 1, eax=0)}))
    e.w32(s + 0x30, sch)
    n = rng.choice([0, 1, 2, 4, 6])
    ps = [_rnd(c, 0xb0) for _ in range(max(n, 1))]
    for p in ps:
        e.w32(p + 0xac, rng.choice([0, 0x4000, 0xbfff, 0x4001, _r(c)]))
    arr = _rnd(c, 4 * (n + 1))
    for k in range(n):
        e.w32(arr + 4 * k, ps[k] if rng.random() < 0.8 else ps[rng.randrange(len(ps))])
    e.w32(s + 0x18, arr)
    e.w32(s + 0x20, n)

    def mm(em, r):
        d, src, sz = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memmove', 0, None, (d, src, sz)))
        em.wbytes(d, em.rbytes(src, sz))
        em.ret(eax=d, argbytes=0)
    e.stub_import('memmove', mm)
    _hn(c, 0x4248e0, 'mcrdtsc666', 0, eax=_r(c))
    _hk(c, 0x5f56f0, 'runProcess', 0)
    o = _rnd(c, 0x10)
    e.w32(o, _pyvt(c, {0x24: _vh(c, 'o.24', 1, eax=0)}))
    _hn(c, 0x5fa630, 'getter', 0, eax=o)
    _hk(c, 0x5fd2a0, 'fn_5fd2a0', 1)
    _hk(c, 0x5f3b00, 'dtor body', 0)
    _hn(c, 0x634273, 'delete', 2, pop=0)
    return [s]


def _g_4e69b0(c):
    e = c.emu
    rng = c.rng
    n = rng.choice([1, 2, 3, 5, 10, 30, 64])
    small = rng.random() < 0.5
    keys = [rng.randrange(4) if small else rng.choice([_r(c), 0, 0xffffffff, rng.randrange(100)]) for _ in range(n)]
    k = _rnd(c, 4 * n)
    for i, x in enumerate(keys):
        e.w32(k + 4 * i, x)
    v = _rnd(c, 4 * n)
    lo = rng.randrange(n)
    hi = rng.randrange(lo, n)
    if rng.random() < 0.5:
        lo, hi = 0, n - 1
    e.w32(0x6e7b9c, rng.choice([0, 1, _r(c)]))
    return [k, v, lo, hi]


def _g_4c85f0(c):
    e = c.emu
    rng = c.rng
    rm = _rnd(c, 0x100)
    e.w32(0x70039c, rm)
    db = _rnd(c, 0xbb0)
    e.w32(rm + 0x9b, db)
    m = rng.choice([0, 1, 2, 5])
    gs = [_rnd(c, 0x60) for _ in range(m)]
    for g in gs:
        t = rng.choice([0, _rnd(c, 0x10)])
        if t:
            u = _rnd(c, 0x30)
            e.w32(u + 0x23, rng.choice([0x800000, 0, 0x7fffff, 0xffffffff, _r(c)]))
            e.w32(t + 0xc, u)
        e.w32(g + 0x54, t)
    lst = _rnd(c, 0x10)
    e.w32(lst + 8, gs[0] if gs else 0)

    def nxt(em, r):
        p = em.arg32(0)
        cur = em.r32(p)
        em.calllog.append(('list.50', 0, em.reg('ecx'), (cur,)))
        i = gs.index(cur) if cur in gs else len(gs)
        em.w32(p, gs[i + 1] if i + 1 < len(gs) else 0)
        em.ret(eax=0, argbytes=4)
    e.w32(lst, _pyvt(c, {0x50: nxt}))
    e.w32(db + 0xadc, lst)
    _hk(c, 0x4daa20, 'ZBaseGeom::Display', 1)
    _log_world(c)
    s = _rnd(c, 0x60)
    e.wbytes(s + 0x51, bytes([rng.choice([0, 1, 0x80])]))
    return [s]


def _g_41e4b0(c):
    e = c.emu
    rng = c.rng
    s = _rnd(c, 0x30)
    e.w32(s, _pyvt(c, {0x44: _vh(c, 'self.44', 0, eax=0)}))
    allocs = [_rnd(c, 0x20), rng.choice([0, _r(c)])]
    seq = list(allocs)
    al = rng.choice([0, _rnd(c, 0x10)])
    if al:
        e.w32(al, _pyvt(c, {8: _vh(c, 'alloc.8', 1, eax=lambda em: seq.pop(0) if seq else 0)}))
    e.w32(0x70038c, al)
    e.stub_import('malloc', lambda em, r: (em.calllog.append(('malloc', 0, None, (em.arg32(0),))),
                                           em.ret(eax=seq.pop(0) if seq else 0, argbytes=0)))
    o = _rnd(c, 0x20)
    e.w32(o + 0x10, rng.choice([0, 1, 0x100, 0x3fffffff, 0x40000000, 0x7fffffff, 0xffffffff, _r(c)]))
    _hk(c, 0x4cc930, 'ctor_4cc930', 2, eax=o)
    _hn(c, 0x634d10, 'memset', 3, pop=0)
    return [s]


S(0x5fd6f0, 'ScriptEngine_t::scheduleProcesses', 'thiscall', None, ret=None, gen=_g_5fd6f0,
  note='batch1915; void; mcrdtsc666 hooked; memmove via IAT')
S(0x4e69b0, 'FUN_004e69b0 (quicksort key/value)', 'fastcall', None, ret=None, gen=_g_4e69b0,
  note='batch1915; void; global seed 0x6e7b9c')
S(0x4c85f0, 'CRootGroup::ToggleLightDisplay', 'thiscall', None, ret=None, gen=_g_4c85f0, note='batch1915; void')
S(0x41e4b0, 'ZSysMem::CheckAndInitRefs', 'thiscall', None, ret=None, gen=_g_41e4b0,
  note='batch1915; void; SEH not ported; malloc via IAT')
