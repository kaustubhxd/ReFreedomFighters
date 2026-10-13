"""specs_s2705.py - unclaimed-27 claim 5 (docs/20-unclaimed-27.md): ZGROUP::ResetGroupPosition (0x441660, thiscall, ret 4).
The group is 0x800 random bytes with +8 pointing to a fresh 0x100-byte block (its +0x24, +0x30 vectors). Its +0x50 is the head
of a list of 0..3 nodes (0x100 bytes each; node +0x24 vector; node +0x60 next). Bit 0x40000000 of +0x30 is set in about half
the cases, and the flag is 0 or 1. The group's vtable slot +0x2a4 (two arguments, ret 8) is a STUB that records its two
arguments (NOT verified). The helpers 0x43e920 and 0x43e960 are original code."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _rgp(c):
    rec = c.emu.alloc(0x10, 4)
    # slot +0x2a4 (thiscall, two arguments, ret 8): [esp+4] -> rec, [esp+8] -> rec+4
    s2a4 = (b'\x8b\x44\x24\x04\xa3' + rec.to_bytes(4, 'little')
            + b'\x8b\x44\x24\x08\xa3' + (rec + 4).to_bytes(4, 'little') + b'\xc2\x08\x00')
    vt = c.emu.alloc(0x400, 4)
    c.emu.w32(vt + 0x2a4, _stub(c, s2a4))
    g = _rnd(c, 0x100)
    o = _rnd(c, 0x800)
    c.emu.w32(o, vt)
    c.emu.w32(o + 8, g)
    if c.rng.random() < 0.5:
        c.emu.w32(o + 0x30, c.rng.getrandbits(32) | 0x40000000)
    else:
        c.emu.w32(o + 0x30, c.rng.getrandbits(32) & 0xbfffffff)
    # the node list at +0x50
    n = c.rng.randint(0, 3)
    nodes = [_rnd(c, 0x100) for _ in range(n)]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 0x60, nodes[i + 1] if i + 1 < n else 0)
    c.emu.w32(o + 0x50, nodes[0] if n else 0)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.choice([0, 1, c.rng.getrandbits(32)])]


S(0x441660, 'ZGROUP::ResetGroupPosition (unknown) thiscall', 'thiscall', None, ret=None, gen=_rgp,
  note='unclaimed-27 claim 5; vtable slot +0x2a4 is a stub that records its arguments')
