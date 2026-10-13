"""specs_s1964.py - unclaimed-66 batches 81 and 82 (gap band, GUESS names). THISCALL(this), one float argument, ret 4.

0x4690b0 (THISCALL, no arguments; ECX logged) and 0x524890 (THISCALL, one float argument, ret 4; the argument bits logged) are recording GUESS
stubs by address. The object under test is 0x80 random bytes; the float argument is drawn from a mix of finite, zero, NaN and infinity."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hooks(c):
    def h469(e, r):
        e.calllog.append(('0x4690b0 (GUESS stub)', 0x4690b0, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x4690b0, h469)

    def h524(e, r):
        e.calllog.append(('0x524890 (GUESS stub)', 0x524890, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x524890, h524)


def _gen(c):
    _hooks(c)
    self = _rnd(c, 0x80)
    v = c.rng.choice([0.0, -0.0, float('nan'), -3.5, 2.25, float('inf')]) if c.rng.random() < 0.3 else c.rng.uniform(-10, 10)
    return [self, F(v)]


S(0x516640, 'GUESS FUN_00516640 (float constants; 0x4690b0 twice; 0x524890 with the float)', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-66 batch 1964; gap band; helpers GUESS stubs by address')
S(0x516780, 'GUESS FUN_00516780 (float constants; 0x4690b0 twice; 0x524890 with the float)', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-66 batch 1964; gap band; helpers GUESS stubs by address')
