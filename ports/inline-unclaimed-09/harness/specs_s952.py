"""specs_s952.py - area 56 band, claim A11: 0x533c20 (bool wrapper).

The object is 0x40 random bytes. 0x539780 is a GUESS recording stub: it logs its object pointer (heap) and returns a random
dword: zero in about one case in five, and a word with a zero low byte in about 30% (the original tests only the low byte). The return is the bool in al (ret='al')."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    rng = c.rng

    def h(e2, r):
        u = rng.random()
        v = 0 if u < 0.2 else (rng.getrandbits(32) & 0xffffff00) if u < 0.5 else rng.getrandbits(32)  # low byte zero but non-zero word in 30%
        e2.calllog.append(('E539780', e2.reg('ecx'), v))
        e2.ret(eax=v, argbytes=0)

    c.emu.hook(0x539780, h)
    return [_rnd(c, 0x40)]


S(0x533c20, 'unnamed 0x533c20 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-56 A11; band list; 0x539780 is a GUESS recording stub (unverified)')
