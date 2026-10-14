"""specs_s963.py - area 56 band, claim A26 (0x533cc0).

0x41e290 is hooked (emu.hook): it logs its argument and returns a random heap pointer, or zero in about one case in five (a
cdecl helper: caller pops, so the hook returns with argbytes=0). 0x5328b0 is hooked: it logs ecx and returns a random dword with a
plain ret (the tail target; the wrapper has no arguments, so none are popped). ret='eax'."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    p = _rnd(c, 0x40) if rng.random() < 0.8 else 0
    rv = rng.getrandbits(32)

    def h41e(e2, r):
        e2.calllog.append(('H41e290', e2.arg32(0)))
        e2.ret(eax=p, argbytes=0)

    def h5328(e2, r):
        e2.calllog.append(('H5328b0', e2.reg('ecx')))
        e2.ret(eax=rv, argbytes=0)

    e.hook(0x41e290, h41e)
    e.hook(0x5328b0, h5328)
    return []


S(0x533cc0, 'unnamed 0x533cc0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='unclaimed-56 A26; 0x41e290 and 0x5328b0 hooked (GUESS stubs)')
