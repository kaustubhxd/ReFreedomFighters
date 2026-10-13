"""specs_s1009.py - unclaimed-02 batch 9 (docs/20-unclaimed-02.md): ZMatPosAnim::CopyData (0x4a54d0). Two random 0x100-byte
objects; about one case in ten uses the same object for both sides, which takes the alias branch at +0xb7."""
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    self_ = _rnd(c, 0x100)
    if c.rng.random() < 0.1:
        return [self_, self_]
    return [self_, _rnd(c, 0x100)]


S(0x4a54d0, 'ZMatPosAnim::CopyData(ZEventBase*) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-02 batch 9; field copy from the argument; 36-byte blocks at +0x6b and +0x93; alias guard at +0xb7')
