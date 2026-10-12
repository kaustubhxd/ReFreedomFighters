"""specs_s1932.py - unclaimed-66 batch 32 (gap band, GUESS names). Thiscall(X), ret 4.

0x5003d0 (another area's helper) is hooked by address: it returns a fixed object P whose first dword is 0, 1 or random (the bool).
The sub-object at this+0x18 is 0x800 random bytes, so the byte stores at +0x157 and +0x704 land inside it. X+4 holds a holder."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    P = _rnd(c, 0x40)
    c.emu.w32(P, c.rng.choice([0, 1, c.rng.getrandbits(32)]))

    def h5003(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=P, argbytes=4)

    c.emu.hook(0x5003d0, h5003)
    sub = _rnd(c, 0x800)
    self = _rnd(c, 0x200)
    c.emu.w32(self + 0x18, sub)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, _rnd(c, 0x20))
    return [self, x]


S(0x5063a0, 'GUESS FUN_005063a0 (bool to sub +0x157)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1932; gap band; 0x5003d0 is another area: HOOKED')
S(0x508530, 'GUESS FUN_00508530 (bool to sub +0x704)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1932; gap band; 0x5003d0 is another area: HOOKED')
