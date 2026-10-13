"""specs_s4117.py - unclaimed-41 batch 17 (slice 13): 0x523990 (thiscall, one stack argument s, ret 4, returns al = 1).

Stream s: checksum stubs for slots +0x4c (one argument; the float bits are checked), +0x68, +0x60 and +0x10 (two arguments) and
+0x3c. The global object (0x70039c)+0x9b has a slot +0x4c that returns a random eax (checksum). The pointer arguments into self are
heap addresses. Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _wr(c):
    vt = c.emu.alloc(0x100, 4)
    for slot, nargs in [(0x4c, 1), (0x68, 1), (0x60, 1), (0x10, 2), (0x3c, 1)]:
        st, _, _ = hs.stub(c, nargs, ecx=True, edx=False)
        c.emu.w32(vt + slot, st)
    s = _rnd(c, 0x100)
    c.emu.w32(s, vt)
    vt_b = c.emu.alloc(0x100, 4)
    st, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=c.rng.getrandbits(32))
    c.emu.w32(vt_b + 0x4c, st)
    b = _rnd(c, 0x200)
    c.emu.w32(b, vt_b)
    g = _rnd(c, 0x200)
    c.emu.w32(g + 0x9b, b)
    c.emu.w32(0x70039c, g)
    self_ = _rnd(c, 0x100)
    return [self_, s]


S(0x523990, 'fn523990 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_wr,
  note='unclaimed-41 batch 17; serialization write sequence; stream and global slots are checksum stubs')
