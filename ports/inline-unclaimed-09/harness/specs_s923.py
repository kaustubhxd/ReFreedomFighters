"""specs_s923.py - unclaimed-09 batch 15 (docs/20-unclaimed-09.md, claim 15): 0x647100 (no GC name).

The object is 0x300 random bytes; the word at +0x291 is zero in about one case in two. The out buffer is 12 random
bytes on the heap. 0x642120 is hooked (unverified callee): it logs its two arguments (out is a heap pointer, stable)
and returns with ret 8 (stdcall)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook(e2, r):
    e2.calllog.append(('Call642120', e2.arg32(0), e2.arg32(1)))
    e2.ret(argbytes=8)


def _gen(c):
    c.emu.hook(0x642120, _hook)
    this = _rnd(c, 0x300)
    c.emu.w32(this + 0x291, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32) | 1)
    return [this, _rnd(c, 12), c.rng.getrandbits(32)]


S(0x647100, 'unnamed 0x647100 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-09 b15; no GC name (GUESS); 0x642120 hooked (unverified callee)')
