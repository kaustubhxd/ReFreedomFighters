"""specs_s1651.py - residue 13 batch 1651: five one-instruction getters (0x46e6f0, 0x46e7f0, 0x469120, 0x4808c0,
0x462f40). Two read this+0x64 / this+0x60 / this+0x6c; two read a global dword (0x6e59d8 and 0x6e5ef8) and ignore this."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks


def _obj(c, off):
    def g(c):
        return [rnd(c, 0x100)]
    return g


def _gen_obj(c):
    return [rnd(c, 0x100)]


def _gen_glob(addr):
    def g(c):
        c.emu.w32(addr, c.rng.getrandbits(32))
        return [rnd(c, 0x20)]
    return g


S(0x46e6f0, 'GUESS FUN_46e6f0', 'thiscall', None, ret='eax', gen=_gen_obj, note='batch1651; this+0x64')
S(0x46e7f0, 'GUESS FUN_46e7f0', 'thiscall', None, ret='eax', gen=_gen_obj, note='batch1651; this+0x60')
S(0x469120, 'GUESS FUN_469120', 'thiscall', None, ret='eax', gen=_gen_glob(0x6e59d8), note='batch1651; global dword')
S(0x4808c0, 'GUESS FUN_4808c0', 'thiscall', None, ret='eax', gen=_gen_glob(0x6e5ef8), note='batch1651; global dword')
S(0x462f40, 'ZItemTemplate::GetPointerContextPicture', 'thiscall', None, ret='eax', gen=_gen_obj, note='batch1651; this+0x6c')
