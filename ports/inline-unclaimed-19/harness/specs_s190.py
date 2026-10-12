"""specs_s190.py - unclaimed area 19 (docs/20-unclaimed-19.md): leaf thiscall functions, no calls out."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x200)]


def _obj_val(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


S(0x42acaf, 'getStr (GUESS)', 'thiscall', None, ret='eax', gen=_obj, note='batch190; returns a string address')
S(0x4609e0, 'setVtbl (GUESS)', 'thiscall', None, ret=None, gen=_obj, note='batch190; writes a vtable pointer at +0')
S(0x504720, 'bump (GUESS)', 'thiscall', None, ret='eax', gen=_obj, note='batch190; returns this')
S(0x4e64a0, 'unitFloats (GUESS)', 'thiscall', None, ret='eax', gen=_obj, note='batch190; returns this')
S(0x52a1a0, 'bounds (GUESS)', 'thiscall', None, ret=None, gen=_obj, note='batch190; writes three unaligned dwords')
S(0x5ec660, 'setField5e (GUESS)', 'thiscall', None, ret=None, gen=_obj_val, note='batch190; stack argument to +0x5e')
