"""specs_s34074.py - 0x471a70 (a null in a fifth of the cases; [a+0xc] block with the unaligned dword +0x23 equal to 0x1007d9 half the time), 0x4e54a0 (dword +0x48 of the argument negative / small / random)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g471a70(c):
    clear_hooks(c)
    r = c.rng
    if r.random() < 0.2:
        return [0]
    a = rnd(c, 0x20)
    blk = rnd(c, 0x40)
    v = r.choice([0x1007d9, 0x1007d9, 0x1007d8, 0x1007da, 0x7d9, r.getrandbits(32)])
    c.emu.wbytes(blk + 0x23, v.to_bytes(4, 'little'))
    c.emu.w32(a + 0xc, blk)
    return [a]


def _g4e54a0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    a = rnd(c, 0x60)
    c.emu.w32(a + 0x48, r.choice([0, 1, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32)]))
    return [me, a]


S(0x471a70, 'GUESS is object kind 0x1007d9', 'stdcall', None, ret='al', gen=_g471a70, note='batch34074')
S(0x4e54a0, 'GUESS base plus non-negative offset', 'thiscall', None, ret='eax', gen=_g4e54a0, note='batch34074')
