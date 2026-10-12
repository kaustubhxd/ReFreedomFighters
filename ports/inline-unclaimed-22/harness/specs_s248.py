"""specs_s248.py - area 22, batch248 (src/batch248.cpp): ZPlayer::Load. ZActor::Load (0x474770) is hooked and returns a
per-case value (low byte zero or not, random upper bits); the load stream is helpers22._loader; the table at +0x461 holds
0 to 4 objects (some null) with a logged slot 0x38."""
from pilot import S
from helpers22 import _rnd, _hk, _multi_vt, _loader


def _g_483f20(c):
    e = c.emu
    self_ = _rnd(c, 0x700)
    ok = (c.rng.getrandbits(24) << 8) | c.rng.choice([1, 1, 1, 0, c.rng.getrandbits(8)])
    _hk(c, 0x474770, '474770', 1, eax=ok)
    l = _loader(c, {0x40: 4, 0x48: 4, 0x50: 4, 0x68: 1, 0x6c: 12, 0x74: 0x24})
    e.w32(self_, _multi_vt(c, {0x628: (lambda em, a: (0, None), 0)}))
    n = c.rng.choice([0, 1, 2, 4])
    e.w32(self_ + 0x459, n)
    for i in range(n):
        if c.rng.random() < 0.75:
            o = _rnd(c, 0x10)
            e.w32(o, _multi_vt(c, {0x38: (lambda em, a: (0, None), 1)}))
        else:
            o = 0
        e.w32(self_ + 0x461 + 4 * i, o)
    e.mu.ctl_flush_tb()
    return [self_, l]


S(0x483f20, 'ZPlayer::Load', 'thiscall', None, ret='al', gen=_g_483f20,
  note='batch248; 0x474770 hooked, 23 field reads, 1-based object table loads')
