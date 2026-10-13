"""specs_s1147.py - unclaimed-11 batch 48 (slice 10 gap band): 0x5bc160 (GUESS, Save-like), thiscall, one argument (ret 4),
returns al = 1. Clears bit 6 of the dword at this+4, then calls on the serializer argument: slot 0x64([this+0x48]),
slot 0x60(byte [this+0x4c] zero-extended), slot 0x4c(float bits [this+0x4d]), slot 0x3c with [this+0x51], [this+0x55],
[this+0x5d], [this+0x59] (in that order). Every slot is a tagged logger sharing one ring: each call writes (slot tag, first
argument, ecx) into the next 16-byte entry, so the order across slots, the arguments and the this pointer are all compared.
The object is 0x80 random bytes (the float at +0x4d is raw bits, NaNs included)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S

P = ss.P


def _tag_stub(c, cnt, ring, tag):
    # thiscall, one stack arg: ring[cnt] = (tag, arg, ecx); cnt++; ret 4.
    b = (b'\xa1' + P(cnt)                        # mov eax, [cnt]
         + b'\xc1\xe0\x04'                       # shl eax, 4
         + b'\xc7\x80' + P(ring) + P(tag)        # mov dword [eax + ring], tag
         + b'\x8b\x54\x24\x04'                   # mov edx, [esp+4]
         + b'\x89\x90' + P(ring + 4)             # mov [eax + ring + 4], edx
         + b'\x89\x88' + P(ring + 8)             # mov [eax + ring + 8], ecx
         + b'\xff\x05' + P(cnt)                  # inc dword [cnt]
         + b'\xc2\x04\x00')                      # ret 4
    return ss.code(c, b)


def _gen(c):
    o = c.emu.alloc(0x80, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(16 * 8, 4)
    c.emu.wbytes(ring, bytes(16 * 8))
    slots = {off: _tag_stub(c, cnt, ring, off) for off in (0x3c, 0x4c, 0x60, 0x64)}
    s = ss.save_obj(c, slots)
    return [o, s]


S(0x5bc160, 'GUESS (no name) Save-like: seven serializer slot calls thiscall ret 4 returns al=1', 'thiscall', None, ret='al',
  gen=_gen, note='unclaimed-11 batch 48 (slice 10 gap band); serializer slots are tagged loggers')
