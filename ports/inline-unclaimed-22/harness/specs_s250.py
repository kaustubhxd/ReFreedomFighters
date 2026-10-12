"""specs_s250.py - area 22, batch250 (src/batch250.cpp): ZMoveOnSpline::Load. Load stream helpers22._loader (heap pointers
logged, stack ones not) plus slot 0x18 (pointer, size) and slot 0x70 (one value, logged); the engine db's slot 0x58 maps an
id to a per-case value; 0x440e10 hooked with a per-case result; 0x523710, 0x4e78c0, fastcall 0x511bc0 hooked."""
from pilot import S
from helpers22 import _rnd, _hk, _multi_vt, _loader


def _g_5135c0(c):
    e = c.emu
    self_ = _rnd(c, 0x240)
    stream = bytes(c.rng.getrandbits(8) for _ in range(0x10))

    def s18(em, r):
        p, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('load', 0x18, None, (p, n)))
        em.wbytes(p, stream[:n])
        em.ret(eax=0, argbytes=8)

    def s70(em, r):
        em.calllog.append(('load', 0x70, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    l = _loader(c, {0x40: 4, 0x48: 4, 0x50: 4, 0x68: 1, 0x6c: 12, 0x74: 0x24}, log_ptr='heap',
                extra={0x18: s18, 0x70: s70})
    salt = c.rng.getrandbits(32)
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a, k=salt: ((a[0] * 0x9e3779b1 ^ k) & 0xffffffff, None), 1)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    e.w32(self_, _multi_vt(c, {0x2e4: (lambda em, a: (0, None), 0)}))
    ok = (c.rng.getrandbits(24) << 8) | c.rng.choice([1, 1, 1, 0, c.rng.getrandbits(8)])
    _hk(c, 0x440e10, '440e10', 1, eax=ok)
    _hk(c, 0x523710, '523710', 1)
    _hk(c, 0x4e78c0, '4e78c0', 1)

    def fc(em, r):
        em.calllog.append(('511bc0', 0, em.reg('ecx'), (em.reg('edx'),)))
        em.ret(eax=0)
    e.hook(0x511bc0, fc)
    e.mu.ctl_flush_tb()
    return [self_, l]


S(0x5135c0, 'ZMoveOnSpline::Load', 'thiscall', None, ret='al', gen=_g_5135c0,
  note='batch250; base load hooked, 44 reads, three id lookups, vt 0x2e4')
