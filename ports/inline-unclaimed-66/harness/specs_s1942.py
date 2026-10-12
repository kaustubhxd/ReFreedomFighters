"""specs_s1942.py - unclaimed-66 batch 43 (gap band, GUESS name). THISCALL(this), no arguments, eax returned.

0x573da0 (a jmp thunk to 0x573dd0, ZBaseMap::Init2 family in the map area) and 0x576330 (its tail target) are recording GUESS stubs hooked
by address. The stub for 0x576330 returns a fixed eax per case (chosen in gen). The object is 0x200 random bytes; the wrapper does not read it."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    self = _rnd(c, 0x200)
    rv = c.rng.getrandbits(32)

    def h573(e, r):
        e.calllog.append(('0x573da0 (GUESS stub)', 0x573da0, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x573da0, h573)

    def h576(e, r):
        e.calllog.append(('0x576330 (GUESS stub)', 0x576330, e.reg('ecx'), ()))
        e.ret(eax=rv, argbytes=0)
    c.emu.hook(0x576330, h576)
    return [self]


S(0x576250, 'GUESS FUN_00576250 (0x573da0, then tail to 0x576330; eax returned)', 'thiscall', None, ret='eax', gen=_gap,
  note='unclaimed-66 batch 1942; parked row resolved; 0x573da0 and 0x576330 GUESS stubs')
