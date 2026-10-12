"""specs_s902.py - unclaimed-01 batch 2 (docs/20-unclaimed-01.md): ZActor::IsDead (0x479050) and ZActor::UpdateFacing (0x47cde0).
IsDead gets a fresh vtable per case: slot +0x588 is a stub (mov eax, imm32; ret) returning a random value, so both
the exe and the port call the same stub and get the same answer. UpdateFacing gets a 0x800-byte object with the
byte at +0x726 drawn from {0, 1, 2, 0x80}; the zero case reaches the tail target 0x467d00 (original code)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _isdead(c):
    o = _rnd(c, 0x800)
    vt = c.emu.alloc(0x590, 4)
    v = c.rng.choice([0, 1, 2, 0x80000000, c.rng.getrandbits(32)])
    code = b'\xb8' + v.to_bytes(4, 'little') + b'\xc3'
    stub = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(stub, code)
    c.emu.w32(vt + 0x588, stub)
    c.emu.w32(o, vt)
    return [o]


def _upd(c):
    o = _rnd(c, 0x800)
    c.emu.wbytes(o + 0x726, bytes([c.rng.choice([0, 0, 1, 2, 0x80])]))
    v = c.emu.r32(o + 0x136)
    if c.rng.random() < 0.5:
        # Bit 0x200000 clear: 0x467d00 takes its early return (no visible effect).
        c.emu.w32(o + 0x136, v & ~0x200000 & 0xffffffff)
    else:
        # Bit set with a nonzero pointer at +0x1a6: 0x467d00 makes one logged call, slot +0x58 of the global's sub-object
        # (0x70039c, +0x9b), which returns 0, so the callee leaves through its exit. Its deeper path (the facing
        # computation after the first test) is not exercised here.
        c.emu.w32(o + 0x136, v | 0x200000)
        c.emu.w32(o + 0x1a6, _rnd(c, 0x40))
        g = _rnd(c, 0x100)
        sub = _rnd(c, 0x40)
        c.emu.w32(sub, c.emu.logging_vtable('ZSysSub', 0x30, argwords={0x58: 1}))
        c.emu.w32(g + 0x9b, sub)
        c.emu.w32(0x70039c, g)
    return [o]


S(0x479050, 'ZActor::IsDead (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_isdead,
  note='unclaimed-01 batch 2; vtable slot 0x588 is a stub returning a random eax')
S(0x47cde0, 'ZActor::UpdateFacing (unknown) thiscall', 'thiscall', None, ret=None, gen=_upd,
  note='unclaimed-01 batch 2; byte 0x726 == 0 tail-jumps to 0x467d00')
