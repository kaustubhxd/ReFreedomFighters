"""specs_s1104.py - unclaimed-11 batch 4 (docs/20-unclaimed-11.md): ZActor::MoveToPosition(const float*, const float*)
at 0x4796e0, thiscall, ret 8. The body is three virtual calls on this: slot 0x630 fills a local vec3 (out pointer),
slot 0x5e8 gets the second argument, slot 0x5e0 gets (the local vec3, the first argument). The object is 0x40 random bytes
whose vtable holds three stubs (serial_stubs.mkobj), so the calls go to the stubs and not to exe code (unverified
callees, stubbed): slot 0x630 writes three floats through its out pointer, slot 0x5e8 records its argument (rec), and slot
0x5e0 writes its second argument (a1) to a heap ring so a swapped argument shows in the memory compare. Slot 0x630 sets
a shared word that slot 0x5e8 copies to the heap, so the call order (0x630 before 0x5e8) shows in the memory compare."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S, F
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vec(c):
    a = c.emu.alloc(16, 16)
    c.emu.wbytes(a, bytes(16))
    for k in range(3):
        c.emu.wf32(a + 4 * k, c.fv(-100.0, 100.0))
    return a


def _out_vec_stub(c, mark):
    # 0x630: writes three random dwords through its out pointer (first argument), sets mark at the shared word
    # (so slot 0x5e8 can tell whether this call came first), returns 0 (thiscall, 1 arg).
    imm = [c.rng.getrandbits(32) for _ in range(3)]
    b = (b'\x8b\x44\x24\x04' + b'\xc7\x00' + ss.P(imm[0]) + b'\xc7\x40\x04' + ss.P(imm[1])
         + b'\xc7\x40\x08' + ss.P(imm[2]) + b'\xc7\x05' + ss.P(mark) + ss.P(0x630)
         + b'\x31\xc0' + b'\xc2\x04\x00')
    return ss.code(c, b)


def _mark_stub(c, mark, out):
    # 0x5e8: copies the shared word into out (heap), returns 0 (thiscall, 1 arg).
    b = b'\xb8' + ss.P(out) + b'\x8b\x0d' + ss.P(mark) + b'\x89\x08' + b'\x31\xc0' + b'\xc2\x04\x00'
    return ss.code(c, b)


def _second_arg_stub(c):
    # 0x5e0: logs its second argument (a1) into a heap ring, returns 0 (thiscall, 2 args).
    ring = c.emu.alloc(8, 4)
    c.emu.wbytes(ring, bytes(8))
    b = b'\xb8' + ss.P(ring) + b'\x8b\x4c\x24\x08' + b'\x89\x08' + b'\x31\xc0' + b'\xc2\x08\x00'
    return ss.code(c, b)


def _mtp(c):
    mark = c.emu.alloc(4, 4)
    c.emu.w32(mark, 0)
    seen = c.emu.alloc(4, 4)
    c.emu.w32(seen, 0)
    st0 = _out_vec_stub(c, mark)
    st1 = _mark_stub(c, mark, seen)
    st2 = _second_arg_stub(c)
    o = ss.mkobj(c, {0x630: st0, 0x5e8: st1, 0x5e0: st2}, size=0x40)
    return [o, _vec(c), _vec(c)]


S(0x4796e0, 'ZActor::MoveToPosition (unknown) thiscall', 'thiscall', None, ret=None, gen=_mtp,
  note='unclaimed-11 batch 4; vtable calls 0x630/0x5e8/0x5e0 stubbed')
