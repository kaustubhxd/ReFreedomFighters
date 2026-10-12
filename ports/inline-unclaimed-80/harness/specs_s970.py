"""specs_s970.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x42ab26 (src/batch970.cpp). Helper 0x42acaf (claimed in
docs/20-unclaimed-19.md) is the exe's own code: it returns the constant 0x6ff948, so the spec writes two dwords there per case. IAT thunk
0x634d88 (GUESS) is hooked with a recording cdecl stub (two arguments, a per-case eax)."""
from pilot import S


def _gen(c):
    c.emu.w32(0x6ff948, c.rng.getrandbits(32))
    c.emu.w32(0x6ff94c, c.rng.getrandbits(32))
    ret = c.rng.getrandbits(32)

    def h634(em, r):
        c.emu.calllog.append(('634d88', None, None, tuple(em.arg32(k) for k in range(2))))
        em.ret(eax=ret, argbytes=0)

    c.emu.hook(0x634d88, h634)
    return [c.rng.getrandbits(32) for _ in range(4)]


S(0x42ab26, 'GUESS wrapper over real helper and IAT (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='unclaimed-80 gap band; helper 0x42acaf runs for real; IAT 0x634d88 hooked (GUESS)')
