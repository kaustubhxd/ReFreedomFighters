"""specs_s316.py - unclaimed-43 batch 316: 0x45d1e0, stdcall with two arguments (both unused), ret 8, returns false in al."""
from pilot import S


def _gen(c):
    c.emu.mu.ctl_flush_tb()
    return [c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x45d1e0, 'returns false (unknown) stdcall', 'stdcall', None, ret='al', gen=_gen,
  note='unclaimed-43 batch 316 (leaf)')
