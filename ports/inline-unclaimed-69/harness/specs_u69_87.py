"""specs_u69_87.py - area 69, gameplay-core residue-8: 0x5c2900 ZFenceGate::Save(ZSaveGame*) (thiscall, one stack arg, ret 4).
GUESS: the save object sg and its two sub-objects are fake vtables (slots 0x60, 0x60, 0x3c, each one stack arg, ret 4).
Their bodies only log booleans (argument equality) and small byte values; the save callee also logs bits 6 and 7 of the object's +4 word, read after the flag clear; their return values are opaque dwords (sub-objects are pointers)."""
from pilot import S
from ckit import rnd, rvt


def _save(c):
    e = c.emu
    r = c.rng
    obj = rnd(c, 0x300)
    v50 = r.getrandbits(32)
    e.w32(obj + 4, r.getrandbits(32))
    e.w32(obj + 0x50, v50)
    e.wbytes(obj + 0x25a, bytes([r.getrandbits(1), r.getrandbits(1)]))
    tail = r.getrandbits(32)
    sg = rnd(c, 0x40)
    a = rnd(c, 0x40)
    b = rnd(c, 0x40)
    vtb = rvt(e, 'fenceSub2', {0x3c: (1, lambda e, ecx, args: (tail, None, ('b3c', int(ecx == b), int(args[0] == v50))), 4)}, nslots=0x80 // 4)
    vta = rvt(e, 'fenceSub1', {0x60: (1, lambda e, ecx, args: (b, None, ('a60', int(ecx == a), int(args[0] in (0, 1)))), 4)}, nslots=0x80 // 4)
    vts = rvt(e, 'fenceSave', {0x60: (1, lambda e, ecx, args: (a, None, ('s60', int(ecx == sg), int(args[0] in (0, 1)), (e.r32(obj + 4) >> 6) & 1, (e.r32(obj + 4) >> 7) & 1)), 4)}, nslots=0x80 // 4)
    e.w32(b, vtb)
    e.w32(a, vta)
    e.w32(sg, vts)
    return [obj, sg]


S(0x5c2900, 'ZFenceGate::Save (thiscall, one stack arg, ret 4)', 'thiscall', None, ret='eax', gen=_save,
  note='u69 gameplay-core; GUESS fake vtables for the save object and its sub-objects')
