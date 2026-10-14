"""specs_u69_91.py - area 69, gameplay-core residue-8: 0x4c4f80 ZAnimSequence::Save and 0x4c3680 ZWindControl::Load (thiscall, one stack arg, ret 4).
GUESS: the save/load object sg and its sub-objects are fake vtables; callees are stdcall one-arg (callee pops 4) and log equalities only.
Load's sg slot 0x50 returns sub-object A on the first call and B on the second (order is part of the contract)."""
from pilot import S
from ckit import rnd, rvt


def _save(c):
    e = c.emu
    r = c.rng
    obj = rnd(c, 0x100)
    v65, b69, v6a = r.getrandbits(32), r.getrandbits(8), r.getrandbits(32)
    e.w32(obj + 4, r.getrandbits(32))
    e.w32(obj + 0x65, v65)
    e.w8(obj + 0x69, b69)
    e.w32(obj + 0x6a, v6a)
    sg = rnd(c, 0x40)
    vt = rvt(e, 'animSave', {
        0x54: (1, lambda e, ecx, args: (0x77777777, None, ('s54', int(ecx == sg), int(args[0] == v65))), 4),
        0x60: (1, lambda e, ecx, args: (0x12345678, None, ('s60', int(ecx == sg), int(args[0] == b69))), 4),
        0x6c: (1, lambda e, ecx, args: (0x9abcdef0, None, ('s6c', int(ecx == sg), int(args[0] == v6a))), 4),
    }, nslots=0x80 // 4)
    e.w32(sg, vt)
    return [obj, sg]


def _load(c):
    e = c.emu
    r = c.rng
    obj = rnd(c, 0x100)
    v48 = r.getrandbits(32)
    e.w32(obj + 4, r.getrandbits(32))
    e.w32(obj + 0x48, v48)
    sg = rnd(c, 0x40)
    A = rnd(c, 0x40)
    B = rnd(c, 0x40)
    calls = [0]

    def sg50(e, ecx, args):
        calls[0] += 1
        if calls[0] == 1:
            return (A, None, ('l50a', int(ecx == sg), int(args[0] == obj + 0x4c)))
        return (B, None, ('l50b', int(ecx == sg), int(args[0] == obj + 0x54)))

    vtS = rvt(e, 'loadSg', {
        0x70: (1, lambda e, ecx, args: (0x0badf00d, None, ('l70', int(ecx == sg), int(args[0] == v48))), 4),
        0x50: (1, sg50, 4),
    }, nslots=0x80 // 4)
    vtA = rvt(e, 'loadA', {0x50: (1, lambda e, ecx, args: (0x1111, None, ('a50', int(ecx == A), int(args[0] == obj + 0x50))), 4)}, nslots=0x80 // 4)
    vtB = rvt(e, 'loadB', {0x50: (1, lambda e, ecx, args: (0x2222, None, ('b50', int(ecx == B), int(args[0] == obj + 0x5c))), 4)}, nslots=0x80 // 4)
    e.w32(sg, vtS)
    e.w32(A, vtA)
    e.w32(B, vtB)
    return [obj, sg]


S(0x4c4f80, 'ZAnimSequence::Save (thiscall, one stack arg, ret 4)', 'thiscall', None, ret='eax', gen=_save,
  note='u69 gameplay-core; GUESS fake vtable for the save object (slots 0x54, 0x60, 0x6c)')
S(0x4c3680, 'ZWindControl::Load (thiscall, one stack arg, ret 4)', 'thiscall', None, ret='eax', gen=_load,
  note='u69 gameplay-core; GUESS fake vtables for the load object and sub-objects A, B')
