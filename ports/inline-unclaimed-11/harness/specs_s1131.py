"""specs_s1131.py - unclaimed-11 batch 32 (gap band): 0x5ab970 (GUESS, no name), thiscall, no args, returns an int.
d = dword at this+0x72 minus dword at this+0x6e. If d & 0xfffffff0 is zero the result is 0. Otherwise the code calls
0x4db7c0(&vec) with ecx = R, where P = dword at this+0x6e, Q = dword at P+8, R = dword at Q+8. The callee is stubbed: it
writes three random floats to vec. The result is (int)(vec.y * float at 0x680a60). The object chain is allocated per case.
The chain is random; d lies in 0..15 in about a third of the cases."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _vec_stub(c, vals):
    # thiscall, one argument (out pointer): writes three dwords through it, returns 0. ret 4.
    b = (b'\x8b\x44\x24\x04'
         + b'\xc7\x00' + ss.P(vals[0]) + b'\xc7\x40\x04' + ss.P(vals[1]) + b'\xc7\x40\x08' + ss.P(vals[2])
         + b'\x31\xc0' + b'\xc2\x04\x00')
    return ss.code(c, b)


def _gen(c):
    # [this+0x6e] is both the pointer P and the base of the difference: d = [this+0x72] - P.
    R = c.emu.alloc(0x40, 4)
    c.emu.wbytes(R, bytes(0x40))
    Q = c.emu.alloc(0x40, 4)
    c.emu.wbytes(Q, bytes(0x40))
    c.emu.w32(Q + 8, R)
    P = c.emu.alloc(0x40, 4)
    c.emu.wbytes(P, bytes(0x40))
    c.emu.w32(P + 8, Q)
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.w32(o + 0x6e, P)
    if c.rng.random() < 0.33:
        c.emu.w32(o + 0x72, (P + c.rng.randint(0, 31)) & 0xffffffff)
    else:
        c.emu.w32(o + 0x72, c.rng.getrandbits(32))
    vals = [c.rng.getrandbits(32) for _ in range(3)]
    ss.patch(c, 0x4db7c0, _vec_stub(c, vals))
    return [o]


S(0x5ab970, 'GUESS (no name) scaled vector y through 0x4db7c0 thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-11 batch 32 (gap band); 0x4db7c0 stubbed')
