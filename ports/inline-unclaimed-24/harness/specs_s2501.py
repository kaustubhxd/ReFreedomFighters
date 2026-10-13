"""specs_s2501.py - decomp area 24, batch 2501. SEH-framed constructors with stack arguments, ported as plain C++ (the frame pushes
ECX before ESI/EDI, so callee-saved registers survive). Thiscall, EAX = this.
0x4284f0 (ret 0x10): recorders for 0x4359f0 and 0x4361a0 (thiscall, one argument); the four argument dwords land at +0x1a1.
0x5062f0 (ret 4): recorders for 0x5047c0 (thiscall, one argument) and 0x509430 (thiscall, none); the global dword 0x701048 is 0
in about half the cases so both branches run."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _gen_4284f0(c):
    clear_hooks(c)
    hook_rec(c, 0x4359f0, 1, this=True)
    hook_rec(c, 0x4361a0, 1, this=True)
    r = c.rng
    return [rnd(c, 0x200)] + [r.getrandbits(32) for _ in range(4)]


def _gen_5062f0(c):
    clear_hooks(c)
    hook_rec(c, 0x5047c0, 1, this=True)
    hook_rec(c, 0x509430, 0, this=True)
    r = c.rng
    c.emu.w32(0x701048, 0 if r.random() < 0.5 else r.getrandbits(32) | 1)
    return [rnd(c, 0x40), r.getrandbits(32)]


S(0x4284f0, 'GUESS ctor with 16-byte argument block at +0x1a1 (SEH frame)', 'thiscall', None, ret='eax', gen=_gen_4284f0, note='batch2501')
S(0x5062f0, 'GUESS ctor storing its argument at +0x18, init gated by [0x701048] (SEH frame)', 'thiscall', None, ret='eax', gen=_gen_5062f0, note='batch2501')
