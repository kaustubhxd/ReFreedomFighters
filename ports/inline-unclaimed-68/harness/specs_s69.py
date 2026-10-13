"""specs_s69.py - unclaimed-68 batch 69 (slice 7): trivial leaves. Names GUESS (FUN_addr).
Getters return this+k, a dword from the vtable, or a constant; 0x4c8df0 clears a byte; 0x4e3330 takes four stack arguments and returns 0."""
from pilot import S
from engine_stubs import zero_obj


def _obj(c, size=0x100):
    o = zero_obj(c, size)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return o


def _vtobj(c):
    o = zero_obj(c, 0x100)
    vt = c.emu.alloc(0x40, 4)
    c.emu.wbytes(vt, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(o, vt)
    return [o]


def _one(c):
    return [_obj(c)]


def _four(c):
    return [_obj(c), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4f0030, 'FUN_4f0030 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_one, note='unclaimed-68 batch 69: lea eax,[this+0x3e]')
S(0x54bbb0, 'FUN_54bbb0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_one, note='unclaimed-68 batch 69: lea eax,[this+0x14]')
S(0x5acff0, 'FUN_5acff0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_one, note='unclaimed-68 batch 69: lea eax,[this+0x48]')
S(0x4c8df0, 'FUN_4c8df0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_one, note='unclaimed-68 batch 69: byte this+0x58 = 0')
S(0x4e3330, 'FUN_4e3330 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_four, note='unclaimed-68 batch 69: returns 0, four stack args (ret 0x10)')
S(0x65c9f0, 'FUN_65c9f0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_vtobj, note='unclaimed-68 batch 69: dword at [[this]]')
for a in (0x50a430, 0x50b5b0, 0x51b5f0, 0x615eb0, 0x63daf0, 0x63ec70, 0x64c730):
    S(a, 'FUN_%x (GUESS) thiscall' % a, 'thiscall', None, ret='eax', gen=_one, note='unclaimed-68 batch 69: constant return')
