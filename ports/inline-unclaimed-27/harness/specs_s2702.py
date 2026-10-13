"""specs_s2702.py - unclaimed-27 claim 2 (docs/20-unclaimed-27.md): ZPlayer::EnableControls (0x483420), void, no arguments.
The player object is 0x800 random bytes with a counter at +0x606 (0, 1, 2 or random), random bits at +0x417 and +0x600.
The global at 0x70039c is a fresh 0x800-byte object whose +0x9b field points to G9 (fresh). Stubs, NOT verified:
G9's slot +0x138 returns P; G9's slot +0x114 returns a random dword (the original keeps only its low 16 bits; ret 0x10, four arguments);
P's slot +0x88 writes a random
value to its second argument (the tmp), or 0; the player's own slot +0x12c records its three arguments (the third is the leftover 0) in a heap record."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _ec(c):
    rec = c.emu.alloc(0x10, 4)
    # player's own vtable: slot +0x12c (thiscall, 3 args: tmp, ax and the leftover 0 the exe pushed before the 0x114 call;
    # callee cleans, ret 0xc): records its three arguments
    s12c = (b'\x8b\x44\x24\x04\xa3' + rec.to_bytes(4, 'little')
            + b'\x8b\x44\x24\x08\xa3' + (rec + 4).to_bytes(4, 'little')
            + b'\x8b\x44\x24\x0c\xa3' + (rec + 8).to_bytes(4, 'little') + b'\xc2\x0c\x00')
    pvt = c.emu.alloc(0x800, 4)
    p = _rnd(c, 0x800)
    # P's vtable: slot +0x88 (thiscall, 2 args): writes a chosen value to *[esp+8]; ret 8
    tmp_val = c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])
    s88 = b'\x8b\x44\x24\x08' + b'\xc7\x00' + tmp_val.to_bytes(4, 'little') + b'\xc2\x08\x00'
    c.emu.w32(pvt + 0x88, _stub(c, s88))
    c.emu.w32(p, pvt)
    # G9's vtable: slot +0x138 (no args) returns P; slot +0x114 (thiscall, 4 args: RegisterZMsg) returns a random dword (the original keeps its low 16 bits); ret 0x10
    g9vt = c.emu.alloc(0x800, 4)
    g9 = _rnd(c, 0x800)
    c.emu.w32(g9vt + 0x138, _stub(c, b'\xb8' + p.to_bytes(4, 'little') + b'\xc3'))
    c.emu.w32(g9vt + 0x114, _stub(c, b'\xb8' + c.rng.getrandbits(32).to_bytes(4, 'little') + b'\xc2\x10\x00'))   # full dword
    c.emu.w32(g9, g9vt)
    g = _rnd(c, 0x800)
    c.emu.w32(g + 0x9b, g9)
    c.emu.w32(0x70039c, g)
    # the player
    o = _rnd(c, 0x800)
    vt = c.emu.alloc(0x800, 4)
    c.emu.w32(vt + 0x12c, _stub(c, s12c))
    c.emu.w32(o, vt)
    c.emu.w32(o + 0x606, c.rng.choice([0, 1, 2, c.rng.getrandbits(32)]))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x483420, 'ZPlayer::EnableControls (unknown) thiscall', 'thiscall', None, ret=None, gen=_ec,
  note='unclaimed-27 claim 2; G9 and P and the player vtable slots are stubs')
