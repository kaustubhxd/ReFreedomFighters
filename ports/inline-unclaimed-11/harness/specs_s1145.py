"""specs_s1145.py - unclaimed-11 batch 46 (slice 10): 0x4d4d60 (GUESS), thiscall, one byte arg (ret 4), returns this.
Order: read [this+0xd]; vt = 0x69666c; [this+0x11] = 0; cdecl free(pointer, 1) via 0x634273 (stubbed: logs the pointer in a
counter-indexed heap ring); vt = 0x696634; if bit 0 of the argument is set, cdecl free(this, 0x15). Both free calls are logged
in order. The object is 0x40 random bytes; the pointer at +0xd is a fresh block or 0 (about 20%)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _log_free_stub(c, cnt, ring):
    # cdecl free(ptr, size): logs ptr into ring[cnt], cnt++ (counter in the heap); caller cleans the stack.
    b = (b'\x8b\x0d' + ss.P(cnt)             # mov ecx, [cnt]
         + b'\x8b\x44\x24\x04'               # mov eax, [esp+4]
         + b'\x89\x04\x8d' + ss.P(ring)      # mov [ecx*4 + ring], eax
         + b'\xff\x05' + ss.P(cnt)           # inc dword [cnt]
         + b'\xc3')
    return ss.code(c, b)


def _gen(c):
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    p = 0 if c.rng.random() < 0.2 else c.emu.alloc(8, 4)
    c.emu.w32(o + 0xd, p)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(16, 4)
    c.emu.wbytes(ring, bytes(16))
    ss.patch(c, 0x634273, _log_free_stub(c, cnt, ring))
    return [o, c.rng.getrandbits(8)]


S(0x4d4d60, 'GUESS (no name) vtable pair and cdecl frees thiscall ret 4', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-11 batch 46 (slice 10); free stubbed')
