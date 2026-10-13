"""specs_s7979.py - residue 6 batch 79 (GUESS names). Both are constant returns with no argument use: 0x63dae0 is
`mov eax, 8; ret` and 0x63ec60 is `mov eax, 0x1fe; ret`. The ABI is not visible from the body; thiscall with the object pointer
is used so the ecx value is passed the same way in both runs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    return [_rnd(c, 0x20)]


S(0x63dae0, 'GUESS FUN_0063dae0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='residue 6 batch 79; returns constant 8')
S(0x63ec60, 'GUESS FUN_0063ec60 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='residue 6 batch 79; returns constant 0x1fe')
