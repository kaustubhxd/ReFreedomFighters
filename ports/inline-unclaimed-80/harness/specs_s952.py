"""specs_s952.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): sixteen trivial thiscall leaves. Each gets a random 0x200-byte object
(0x42ace0 gets a 16-byte object: it writes the vtable 0x679754 to [ecx]). 0x43e140 (ret 0x1c) and 0x42adb0 (ret 0x14) get random stack
arguments (7 and 5). 0x4364c0 reads a random dword at 0x6e4190 (the global is written before the call). Byte getters compare AL only."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x200)]


def _obj_args(n):
    def g(c):
        return [_rnd(c, 0x200)] + [c.rng.getrandbits(32) for _ in range(n)]
    return g


def _glob(c):
    c.emu.w32(0x6e4190, c.rng.getrandbits(32))
    return _obj(c)


def _small(c):
    return [_rnd(c, 0x10)]


S(0x43e140, 'no-op stub (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_args(7), note='unclaimed-80 gap band; ret 0x1c')
S(0x443020, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0x77')
S(0x443060, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0x71')
S(0x443540, 'getter (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj, note='unclaimed-80 gap band; byte at +0x76')
S(0x443550, 'getter (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj, note='unclaimed-80 gap band; byte at +0x5c')
S(0x443560, 'getter (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj, note='unclaimed-80 gap band; byte at +0x75')
S(0x452e10, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0x1c')
S(0x453b10, 'address of field (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; lea +0x22')
S(0x453b30, 'getter (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj, note='unclaimed-80 gap band; byte at +0x60')
S(0x453b40, 'getter (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj, note='unclaimed-80 gap band; byte at +0x61')
S(0x42adb0, 'zero stub (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj_args(5), note='unclaimed-80 gap band; xor al,al, ret 0x14')
S(0x4364c0, 'global getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_glob, note='unclaimed-80 gap band; dword at 0x6e4190')
S(0x453a30, 'constant (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; returns 2')
S(0x42ace0, 'vtable setter (unknown) thiscall', 'thiscall', None, ret=None, gen=_small, note='unclaimed-80 gap band; [ecx] = 0x679754')
S(0x432430, 'getter (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj, note='unclaimed-80 gap band; byte at +0x101')
S(0x432530, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0xf4')
