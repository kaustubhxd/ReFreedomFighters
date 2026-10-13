"""specs_s1138.py - unclaimed-11 batch 39 (slice 10, full list): five tiny leaves, GUESS names, thiscall, no args.
0x612560: dword at [this] = 0x6bd594 (ret 0). 0x626a60: eax = 0x6bece8. 0x63db20: eax = 0x4c. 0x64c760: eax = 0xcc.
0x64fbe0: ST0 = float at this+0xb5 times the float constant at 0x679544 (ret 0). The object is 0x100 random bytes."""
from pilot import S


def _obj(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [o]


S(0x612560, 'GUESS (no name) store vtable 0x6bd594 thiscall', 'thiscall', None, ret=None, gen=_obj, note='unclaimed-11 batch 39')
S(0x626a60, 'GUESS (no name) returns 0x6bece8 thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-11 batch 39')
S(0x63db20, 'GUESS (no name) returns 0x4c thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-11 batch 39')
S(0x64c760, 'GUESS (no name) returns 0xcc thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-11 batch 39')
S(0x64fbe0, 'GUESS (no name) float at +0xb5 times constant thiscall', 'thiscall', None, ret='st0', gen=_obj, note='unclaimed-11 batch 39')
