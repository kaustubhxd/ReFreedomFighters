"""specs_s1921.py - unclaimed-66 batch 1921: GUESS FUN_005002d0, cdecl with no arguments.

The allocator 0x41e290 is HOOKED by address (the allocator uses a global heap object; the spec stands in for it): it logs its size
argument and returns a fresh 0x40-byte object (80%) or 0 (20%, the no-allocation path). The constructor 0x4ff7b0 runs the original
code on that object (no arguments, ECX = the object). The object is 0x40 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _alloc(c):
    def h(e, r):
        size = e.arg32(0)
        e.calllog.append(('allocator 0x41e290 (hook)', 0x41e290, None, (size,)))
        p = _rnd(c, 0x40) if c.rng.random() < 0.8 else 0
        e.ret(eax=p, argbytes=0)
    c.emu.hook(0x41e290, h)
    return []


S(0x5002d0, 'GUESS FUN_005002d0 (allocate 0x34 and construct)', 'cdecl', None, ret='eax', gen=_alloc,
  note='unclaimed-66 batch 1921; slice-5 (GUESS); allocator 0x41e290 HOOKED; ctor 0x4ff7b0 exe code')
