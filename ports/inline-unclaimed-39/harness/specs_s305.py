"""specs_s305.py - decomp area 39 (docs/20-unclaimed-39.md): 0x55eae0 stdcall blend; sys vtbl slot 0x1c0 returns st0; exe 0x451890."""
import struct
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c):
    if c.rng.random() < 0.1:
        return c.rng.choice([0.0, 0.5, 1.0, -1.0, 2.0]) if hasattr(c.rng, 'choice') else 0.5
    return c.rng.uniform(-20.0, 20.0)


def _blend(c):
    e = c.emu
    # Global system object at 0x70039c: slot 0x1c0 returns float r (st0) and pops its two stack words.
    # Two calls per case: each returns its own value, so a swapped r1/r2 is visible.
    rets = [_fl(c), _fl(c)]
    calls = [0]

    def _slot(em, a):
        v = rets[calls[0] % 2]
        calls[0] += 1
        return (0, v)

    sys_vt = e.logging_vtable('sys55e', 0x80, impl={0x1c0: _slot}, argwords={0x1c0: 2})
    sys_ = _rnd(c, 0x40)
    e.w32(sys_, sys_vt)
    e.w32(0x70039c, sys_)

    P = _rnd(c, 0x20)
    Sub = _rnd(c, 0x60)
    e.wf32(Sub + 0x40, _fl(c))
    e.wf32(Sub + 0x48, _fl(c))
    e.w32(P + 8, Sub)
    Q = _rnd(c, 0x40)
    for off in (0, 4, 8, 0x18, 0x1c, 0x20):
        e.wf32(Q + off, _fl(c))
    R = _rnd(c, 0x20)
    for off in (0, 4, 8):
        e.wf32(R + off, _fl(c))
    return [P, Q, R]


S(0x55eae0, 'blend (GUESS)', 'stdcall', None, ret=None, gen=_blend,
  note='batch305; three stack pointers; ret 0xc; sys vtbl 0x1c0 (st0, 2 stack words); exe 0x451890')
