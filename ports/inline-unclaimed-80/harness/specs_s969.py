"""specs_s969.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x42ab81 (src/batch969.cpp). Helper 0x42acb5 (claimed in docs/20-unclaimed-69.md)
hooked by address with a recording cdecl stub (four arguments; returns a pointer to a per-case two-dword block). IAT thunk 0x634d8e (GUESS)
hooked with a recording cdecl stub (two arguments, a per-case eax)."""
from pilot import S


def _gen(c):
    blk = c.emu.alloc(8, 4)
    c.emu.w32(blk, c.rng.getrandbits(32))
    c.emu.w32(blk + 4, c.rng.getrandbits(32))
    ret = c.rng.getrandbits(32)

    def h42(em, r):
        c.emu.calllog.append(('42acb5', None, None, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=blk, argbytes=0)

    def h634(em, r):
        c.emu.calllog.append(('634d8e', None, None, tuple(em.arg32(k) for k in range(2))))
        em.ret(eax=ret, argbytes=0)

    c.emu.hook(0x42acb5, h42)
    c.emu.hook(0x634d8e, h634)
    return [c.rng.getrandbits(32) for _ in range(4)]


S(0x42ab81, 'GUESS wrapper over claimed helper and IAT (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='unclaimed-80 gap band; helper 0x42acb5 hooked (claimed elsewhere); IAT 0x634d8e hooked (GUESS)')
