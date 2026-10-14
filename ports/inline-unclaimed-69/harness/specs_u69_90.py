"""specs_u69_90.py - area 69, gameplay-core residue-8: 0x506e80 (thiscall, one stack arg, ret 4).
GUESS: G (global at 0x700390) with vt slot 0x20 (two args, callee pops 8) returning X; this+0x18 object with vt slot 0x20 (no args) returning Y1;
X with vt slot 0x2c (three args, cdecl, caller pops 0xc); the global function pointer 0x7003b0 is a logging hook H (no args, returns a random eax).
The exe's pointer is never zero in the spec (zero would reach an int3 at 0x506ecf on both sides)."""
from pilot import S
from ckit import rnd, rvt

H = 0x51b63e   # an int3 byte inside the image, hooked as the callee of the global pointer (its real code never runs)


def _fn(c):
    e = c.emu
    r = c.rng
    obj = rnd(c, 0x40)
    G = rnd(c, 0x40)
    Y0 = rnd(c, 0x40)
    Y1 = rnd(c, 0x40)
    X = rnd(c, 0x40)
    p = r.choice([0, r.getrandbits(32) | 4])
    e.w32(Y1 + 4, p)
    e.w32(obj + 0x18, Y0)
    e.w32(0x700390, G)
    e.w32(0x7003b0, H)
    val = r.getrandbits(32)
    vtX = rvt(e, 'fnX', {0x2c: (3, lambda e, ecx, args: (0, None, ('x2c', int(ecx == p), int(args[0] == X), int(args[1] == 0x69d188),
                                                                 int(args[2] == (p if p else 0x67c8e8)))), 0)}, nslots=0x40 // 4)
    vtG = rvt(e, 'fnG', {0x20: (2, lambda e, ecx, args: (X, None, ('g20', int(ecx == G), int(args[0] == 0x69cff0), int(args[1] == 0x290))), 8)}, nslots=0x40 // 4)
    vtY = rvt(e, 'fnY', {0x20: (0, lambda e, ecx, args: (Y1, None, ('y20', int(ecx == Y0))), 0)}, nslots=0x40 // 4)
    e.w32(X, vtX)
    e.w32(G, vtG)
    e.w32(Y0, vtY)

    def hook(e, res):
        e.calllog.append(('h7003b0',))
        e.ret(eax=val, argbytes=0)
    e.hook(H, hook)
    return [obj, r.getrandbits(32)]


S(0x506e80, 'opcall506e80 (thiscall, one stack arg, ret 4)', 'thiscall', None, ret='eax', gen=_fn,
  note='u69 gameplay-core; GUESS fake vtables G, Y0, X and hook H for the global function pointer')
