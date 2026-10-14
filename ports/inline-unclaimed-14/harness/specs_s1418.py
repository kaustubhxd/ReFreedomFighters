"""specs_s1418.py - unclaimed-14 batch 18 (residue 13): CImpactResponse::Save (0x5dc490, thiscall, one stack argument, ret 4,
returns al = 1).

The save object's vtable slots +0x3c, +0x68, +0x6c, +0x70 and +0x10 are checksum stubs (callee pops; the PC does not adjust
esp). +0x10 takes (string, length). The string at this+0x4c is a random NUL-terminated buffer of 0..24 letters (the strlen
loop in the PC reads it). Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _impact(c):
    vt = c.emu.alloc(0x100, 4)
    for off, nargs in [(0x3c, 1), (0x68, 1), (0x6c, 1), (0x70, 1), (0x10, 2)]:
        s, _, _ = hs.stub(c, nargs, ecx=True, edx=False)
        c.emu.w32(vt + off, s)
    save = _rnd(c, 0x100)
    c.emu.w32(save, vt)
    n = c.rng.randint(0, 24)
    text = bytes(c.rng.choice(b'abcdefghijklmnopqrstuvwxyz0123456789_') for _ in range(n)) + b'\x00'
    sp = c.emu.alloc(len(text), 4)
    c.emu.wbytes(sp, text)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x4c, sp)
    return [o, save]


S(0x5dc490, 'CImpactResponse::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_impact,
  note='unclaimed-14 batch 18 (residue 13); save vtable checksum stubs; strlen of this+0x4c')
