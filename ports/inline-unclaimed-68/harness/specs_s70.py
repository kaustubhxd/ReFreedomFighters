"""specs_s70.py - unclaimed-68 batch 70 (slice 7): small leaves. Names GUESS (FUN_addr)."""
from pilot import S
from engine_stubs import zero_obj


def _one(c, size=0x100):
    o = zero_obj(c, size)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return [o]


S(0x46b6f0, 'FUN_46b6f0 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_one,
  note='unclaimed-68 batch 70: returns byte this+0xc5')
S(0x446030, 'FUN_446030 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_one,
  note='unclaimed-68 batch 70: (dword this+0x48 >> 5) & 1')
S(0x4cbeb0, 'FUN_4cbeb0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_one,
  note='unclaimed-68 batch 70: first dword = this+4, byte this+4 = 0, returns this')
