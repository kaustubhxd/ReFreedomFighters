"""specs_s965.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): three cdecl wrappers (src/batch965.cpp). The helpers 0x42aae8, 0x42ab81
(four arguments; the fourth is an out-pointer) and 0x42ac38 (five arguments; the fifth is an out-pointer) are hooked by address with recording
cdecl stubs. Each stub logs all its arguments, writes a per-case value through its out-pointer and returns a per-case eax (the caller pops)."""
from pilot import S


def _hook(c, addr, name, nargs, outidx, ret, val):
    def h(em, r):
        args = [em.arg32(k) for k in range(nargs)]
        c.emu.calllog.append((name, None, None, tuple(args)))
        c.emu.w32(args[outidx], val)
        em.ret(eax=ret, argbytes=0)
    c.emu.hook(addr, h)


def _gen3(c):
    _hook(c, 0x42aae8, '42aae8', 4, 3, c.rng.getrandbits(32), c.rng.getrandbits(32))
    _hook(c, 0x42ab81, '42ab81', 4, 3, c.rng.getrandbits(32), c.rng.getrandbits(32))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gen4(c):
    _hook(c, 0x42ac38, '42ac38', 5, 4, c.rng.getrandbits(32), c.rng.getrandbits(32))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x42ab0d, 'GUESS wrapper with out-pointer (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen3,
  note='unclaimed-80 gap band; helper 0x42aae8 hooked by address (GUESS); out-pointer is the third parameter')
S(0x42aba4, 'GUESS wrapper with out-pointer (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen3,
  note='unclaimed-80 gap band; helper 0x42ab81 hooked by address (GUESS); out-pointer is the third parameter')
S(0x428420, 'GUESS wrapper with out-pointer (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen4,
  note='unclaimed-80 gap band; helper 0x42ac38 hooked by address (GUESS); out-pointer is the fourth parameter')
