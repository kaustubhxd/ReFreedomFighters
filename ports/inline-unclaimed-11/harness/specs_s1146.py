"""specs_s1146.py - unclaimed-11 batch 47 (slice 10): 0x5f3160 (GUESS), thiscall, one byte argument (ret 4).
cur = dword at this+8, end = dword at this+0xc. If cur+4 > end (unsigned) and the function pointer at global 0x7003b0 is nonnull, that
function is called with ecx = this (stubbed: rec, no args). Then the dword at [this+8] (the current pointer) receives the byte
argument zero-extended, and [this+8] += 4. The buffer is 0x100 random bytes; end is buf + 0..0x20; the grow pointer is set
(a rec stub) in every case: the null case is the PC's int3 trap at 0x5f318e and is outside this contract."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    buf = c.emu.alloc(0x100, 4)
    c.emu.wbytes(buf, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(o + 8, buf)
    c.emu.w32(o + 0xc, buf + c.rng.choice([0, 1, 2, 4, 8, 0x20]))
    # CONTRACT: when the buffer is full the PC needs the grow pointer; with it null, 0x5f318e is int3 (a trap, not a
    # result). The spec keeps the grow pointer set, so the trap path is outside the checked contract (documented).
    grow = ss.rec(c, 0)
    c.emu.w32(0x7003b0, grow)
    c.emu._image_dirty = True
    return [o, c.rng.getrandbits(8)]


S(0x5f3160, 'GUESS (no name) push a byte as a dword with grow callback thiscall ret 4', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 47 (slice 10); grow callback stubbed')
