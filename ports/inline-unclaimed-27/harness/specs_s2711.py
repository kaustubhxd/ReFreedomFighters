"""specs_s2711.py - unclaimed-27 batch 11: ZPlayer::GetCenterSphere (0x483a60, thiscall, ret 0xc). The object is 0x800 random
bytes with a vtable whose slot +0x59c (two arguments, ret 8) is a STUB that records its two arguments (NOT verified). The
out buffer is 12 random bytes. The three copied dwords come from the object itself."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _gcs(c):
    rec = c.emu.alloc(0x10, 4)
    # slot +0x59c: [esp+4] (a1) -> rec, [esp+8] (a2) -> rec+4; ret 8
    s59c = (b'\x8b\x44\x24\x04\xa3' + rec.to_bytes(4, 'little')
            + b'\x8b\x44\x24\x08\xa3' + (rec + 4).to_bytes(4, 'little') + b'\xc2\x08\x00')
    vt = c.emu.alloc(0x800, 4)
    c.emu.w32(vt + 0x59c, _stub(c, s59c))
    o = _rnd(c, 0x800)
    c.emu.w32(o, vt)
    out = _rnd(c, 12)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32), out]


S(0x483a60, 'ZPlayer::GetCenterSphere (unknown) thiscall', 'thiscall', None, ret=None, gen=_gcs,
  note='unclaimed-27 batch 11; slot +0x59c is a stub that records its arguments')
