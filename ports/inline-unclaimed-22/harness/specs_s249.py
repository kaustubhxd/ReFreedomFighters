"""specs_s249.py - area 22, batch249 (src/batch249.cpp): ZMoveOnSpline::Save. The stream is helpers22._save_streams (one-word
slots) plus slot 0x10 (pointer, size); 0x441790 is hooked with a per-case result; 0x523990, 0x4e7be0 (thiscall, one word) and
0x511c20 (fastcall, logged with ecx and edx) are hooked."""
from pilot import S
from helpers22 import _rnd, _hk, _pyvt, _save_streams


def _g_513ff0(c):
    e = c.emu
    self_ = _rnd(c, 0x220)
    s = _save_streams(c, (0x3c, 0x44, 0x4c, 0x60, 0x64, 0x68, 0x6c, 0x70))
    vt = e.r32(s)

    def s10(em, r):
        em.calllog.append(('s.10', 0x10, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    e.w32(vt + 0x10, e.stub_fn('s10', s10))
    ok = (c.rng.getrandbits(24) << 8) | c.rng.choice([1, 1, 1, 0, c.rng.getrandbits(8)])
    _hk(c, 0x441790, '441790', 1, eax=ok)
    _hk(c, 0x523990, '523990', 1)
    _hk(c, 0x4e7be0, '4e7be0', 1)

    def fc(em, r):
        em.calllog.append(('511c20', 0, em.reg('ecx'), (em.reg('edx'),)))
        em.ret(eax=0)
    e.hook(0x511c20, fc)
    e.mu.ctl_flush_tb()
    return [self_, s]


S(0x513ff0, 'ZMoveOnSpline::Save', 'thiscall', None, ret='al', gen=_g_513ff0,
  note='batch249; base save hooked, 41 field writes, fastcall 0x511c20 logged with ecx/edx')
