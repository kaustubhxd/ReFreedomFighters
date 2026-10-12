"""specs_s967.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x42ac38 and 0x42ac08 (see src/batch967.cpp).
0x42ac38: its callee 0x42ac08 is hooked by address with a recording cdecl stub (logs six arguments, returns a per-case value).
0x42ac08: 0x42acaf is the exe's own code (returns 0x6ff948; the spec writes two dwords there per case); 0x634d9a (IAT thunk, GUESS) is hooked by
address with a recording cdecl stub (logs two arguments, returns a per-case signed value, negative about half the time)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook_cdecl(c, addr, name, nargs, ret):
    def h(em, r):
        args = [em.arg32(k) for k in range(nargs)]
        c.emu.calllog.append((name, None, None, tuple(args)))
        em.ret(eax=ret, argbytes=0)
    c.emu.hook(addr, h)


def _gen38(c):
    _hook_cdecl(c, 0x42ac08, '42ac08', 6, c.rng.getrandbits(32))
    return [c.rng.getrandbits(32) for _ in range(5)]


def _gen08(c):
    c.emu.w32(0x6ff948, c.rng.getrandbits(32))
    c.emu.w32(0x6ff94c, c.rng.getrandbits(32))
    r = c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        r |= 0x80000000
    else:
        r &= 0x7fffffff
    _hook_cdecl(c, 0x634d9a, '634d9a', 2, r)
    return [c.rng.getrandbits(32) for _ in range(6)]


S(0x42ac38, 'wrapper around 0x42ac08 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen38,
  note='unclaimed-80 gap band; callee 0x42ac08 hooked by address (its own row); p3 then 0 then p4')
S(0x42ac08, 'GUESS signed clamp over IAT call (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen08,
  note='unclaimed-80 gap band; 0x42acaf real; IAT 0x634d9a hooked (GUESS); negative result becomes -1')
