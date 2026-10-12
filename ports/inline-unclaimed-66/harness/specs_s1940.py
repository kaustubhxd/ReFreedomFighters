"""specs_s1940.py - unclaimed-66 batch 41 (gap band, GUESS name). THISCALL(this), (u32, float), ret 8.

0x5231c0 (batch 40's function, ECX = [this+0x5c]) is a recording GUESS stub hooked by address. Its st0 result is fixed per case in gen."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _wrap(c):
    self = _rnd(c, 0x800)
    st0 = c.rng.uniform(-10, 10)

    def h(e, r):
        e.calllog.append(('0x5231c0 (GUESS stub)', 0x5231c0, e.reg('ecx'), (e.arg32(0), None)))
        e.ret(eax=0, argbytes=8, st0=st0)
    c.emu.hook(0x5231c0, h)
    a1 = c.rng.getrandbits(32)
    v = c.rng.choice([0.0, -0.0, float('nan'), -3.5, 2.25]) if c.rng.random() < 0.3 else c.rng.uniform(-10, 10)
    return [self, a1, F(v)]


S(0x512bc0, 'GUESS FUN_00512bc0 (wrapper: 0x5231c0 with ECX = [this+0x5c])', 'thiscall', None, ret='st0', gen=_wrap,
  note='unclaimed-66 batch 1940; gap band; 0x5231c0 GUESS stub; returns float')
