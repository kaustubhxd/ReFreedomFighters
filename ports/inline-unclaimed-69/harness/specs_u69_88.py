"""specs_u69_88.py - area 69, gameplay-core residue-8: 0x5bdcc0 CCivilianPath::Init2 (thiscall, no args, plain ret).
GUESS: the global object (0x70039c -> G), its sub-object M (vtable slot 0x58, one arg, returns R), R (slot 0x100, one arg, returns Z)
and the RegisterPath call 0x5bef80 (thiscall, six stack args, ret 0x18) are fake/logging stubs. The hook logs ECX equality, the
argument equalities and small values only (no pointers), so the stored addresses are not compared as values."""
import struct
from pilot import S, F
from ckit import rnd, rvt


def _init2(c):
    e = c.emu
    r = c.rng
    G = rnd(c, 0x100)
    M = rnd(c, 0x100)
    R = rnd(c, 0x100)
    Z = rnd(c, 0x100)
    obj = rnd(c, 0x100)
    v59 = r.getrandbits(32)
    p44, p48 = r.getrandbits(32), r.getrandbits(32)
    p4c = r.choice([0, r.getrandbits(32) | 1])   # bool flags: zero half the time, so a swapped flag is visible
    p50 = r.choice([0, r.getrandbits(32) | 1])
    b58 = r.getrandbits(8)
    f54 = r.uniform(-50.0, 50.0)
    e.w32(obj + 0x59, v59)
    e.w32(obj + 0x44, p44)
    e.w32(obj + 0x48, p48)
    e.w32(obj + 0x4c, p4c)
    e.w32(obj + 0x50, p50)
    e.w8(obj + 0x58, b58)
    e.wf32(obj + 0x54, f54)
    e.w32(G + 0x9b, M)
    e.w32(0x70039c, G)
    r_ok = r.random() < 0.75
    z_ok = r.random() < 0.75
    vtM = rvt(e, 'initM', {0x58: (1, lambda e, ecx, args: (R if r_ok else 0, None, ('m58', int(ecx == M), int(args[0] == v59))), 4)}, nslots=0x120 // 4)
    vtR = rvt(e, 'initR', {0x100: (1, lambda e, ecx, args: (Z if z_ok else 0, None, ('r100', int(ecx == R), int(args[0] == 0x6b3538))), 4)}, nslots=0x120 // 4)
    vtZ = rvt(e, 'initZ', {}, nslots=0x20 // 4)
    e.w32(M, vtM)
    e.w32(R, vtR)
    e.w32(Z, vtZ)

    def reg(e, res):
        ecx = e.reg('ecx')
        e.calllog.append(('reg5bef80', int(ecx == Z), int(e.arg32(0) == p44), int(e.arg32(1) == p48),
                          int(e.arg32(2) == struct.unpack('<I', struct.pack('<f', f54))[0]),
                          e.arg32(3) & 1, e.arg32(4) & 1, e.arg32(5) & 0xff, int(e.arg32(5) & 0xff == b58)))
        e.ret(argbytes=0x18)
    e.hook(0x5bef80, reg)
    return [obj]


S(0x5bdcc0, 'CCivilianPath::Init2 (thiscall, no args)', 'thiscall', None, ret=None, gen=_init2,
  note='u69 gameplay-core; GUESS: fake vtables for M and R, RegisterPath 0x5bef80 hooked')
