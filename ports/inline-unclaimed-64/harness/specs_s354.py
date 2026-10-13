"""specs_s354.py - decomp area 64 residue-18 pass: 0x4d93e0; helpers 0x634d10 (cdecl), 0x4de7a0 and child slot 0x34 stubbed (GUESS)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _init(c):
    e = c.emu
    cell = e.alloc(24, 4)
    e.wbytes(cell, bytes(24))
    # 0x634d10 (cdecl, three words; the caller pops): records its three words.
    ss.patch(c, 0x634d10, ss.code(c, b''.join(b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x15' + ss.P(cell + 4 * i) for i in range(3)) + b'\xc3'))
    # 0x4de7a0 (thiscall, ecx = self): records ecx.
    ss.patch(c, 0x4de7a0, ss.code(c, b'\x89\x0d' + ss.P(cell + 12) + b'\xc3'))
    # Child slot 0x34 (one word): a logging object, reached through sys[+0x9b][+8].
    obj_vt = e.logging_vtable('obj4d93', 0x40, argwords={0x34: 1})
    obj = e.alloc(0x40, 4)
    e.wbytes(obj, bytes(0x40))
    e.w32(obj, obj_vt)
    ch = e.alloc(0x20, 4)
    e.wbytes(ch, bytes(0x20))
    e.w32(ch + 0x8, obj)
    sys_ = e.alloc(0x100, 4)
    e.wbytes(sys_, bytes(0x100))
    e.w32(sys_ + 0x9b, ch)
    e.w32(0x70039c, sys_)
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [self_]


S(0x4d93e0, 'initLink (GUESS)', 'thiscall', None, ret='eax', gen=_init,
  note='batch354; no stack words; helpers 0x634d10, 0x4de7a0 and child slot 0x34 stubbed (GUESS)')
