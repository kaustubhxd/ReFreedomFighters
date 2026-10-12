"""specs_s245.py - area 22, batch245 (src/batch245.cpp): ZProjectile::Save, CAction::Load. Stream objects are Python
vtables that log (object, slot, value) and return the other stream, so the chained-return calls are checked; load handlers
write fixed per-case values through their pointers (never logging stack addresses); 0x4e74d0 and 0x634273 are hooked."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _hk, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _streams(c):
    e = c.emu
    a, b = _rnd(c, 0x20), _rnd(c, 0x20)

    def mk(name, other):
        def slot(off):
            def h(em, r):
                em.calllog.append((name, off, None, (em.arg32(0),)))
                em.ret(eax=other, argbytes=4)
            return h
        return _pyvt(c, {0x4c: slot(0x4c), 0x3c: slot(0x3c), 0x68: slot(0x68)})
    e.w32(a, mk('sA', b))
    e.w32(b, mk('sB', a))
    return a


def _g_4ba390(c):
    self_ = _rnd(c, 0x100)
    s = _streams(c)
    _hk(c, 0x4e74d0, '4e74d0', 1)
    c.emu.mu.ctl_flush_tb()
    return [self_, s]


def _g_4a1390(c):
    e = c.emu
    self_ = _rnd(c, 0x140)
    strs = [_rnd(c, 0x10), _rnd(c, 0x10)]
    vals = {'w': [c.rng.getrandbits(16), c.rng.getrandbits(16)], 'd': _r(c),
            'buf': bytes(c.rng.getrandbits(8) for _ in range(0x16)) + bytes([c.rng.choice([0, 0, 1, c.rng.getrandbits(8)])])}
    st = {'n60': 0, 'n44': 0}

    def s60(em, r):
        em.w32(em.arg32(0), strs[st['n60'] & 1])
        em.calllog.append(('l.60', 0x60, None, (st['n60'],)))
        st['n60'] += 1
        em.ret(eax=0, argbytes=4)

    def s44(em, r):
        p = em.arg32(0)
        em.calllog.append(('l.44', 0x44, None, (p,)))
        em.wbytes(p, vals['w'][st['n44'] & 1].to_bytes(2, 'little'))
        st['n44'] += 1
        em.ret(eax=0, argbytes=4)

    def s40(em, r):
        p = em.arg32(0)
        em.calllog.append(('l.40', 0x40, None, (p,)))
        em.w32(p, vals['d'])
        em.ret(eax=0, argbytes=4)

    def s18(em, r):
        p, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('l.18', 0x18, None, (p, n)))
        em.wbytes(p, vals['buf'][:n])
        em.ret(eax=0, argbytes=8)
    l = _rnd(c, 0x20)
    e.w32(l, _pyvt(c, {0x60: s60, 0x44: s44, 0x40: s40, 0x18: s18}))
    e.w32(self_, _multi_vt(c, {0xb0: (lambda em, a: (0, None), 8)}))
    _hk(c, 0x634273, '634273', 2, pop=0)   # cdecl (p, 1)
    e.mu.ctl_flush_tb()
    return [self_, l]


S(0x4ba390, 'ZProjectile::Save', 'thiscall', None, ret='al', gen=_g_4ba390,
  note='batch245; chained stream slots 0x4c/0x3c/0x68, 0x4e74d0 hooked')
S(0x4a1390, 'CAction::Load', 'thiscall', None, ret='al', gen=_g_4a1390,
  note='batch245; load slots 0x60/0x44/0x40/0x18 write per-case values, vt 0xb0 with 8 words, 0x634273 hooked')
