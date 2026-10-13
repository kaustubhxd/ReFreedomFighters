"""specs_s323.py - decomp area 64 (docs/20-unclaimed-64.md): 0x43ebb0 forwards seven stack words to exe 0x43ec00."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fwd(c):
    e = c.emu
    # The exe's 0x43ec00 (six stack words) faults on random arguments, so it is stubbed for both sides: it counts and
    # logs its first argument and returns 0. The port calls the same address, so both see the stub.
    # The stub stores all six stack words in a heap block (so each argument is compared), then returns 0 with ret 0x18.
    block = c.emu.alloc(24, 4)
    c.emu.wbytes(block, bytes(24))
    b = b''
    for i in range(6):
        b += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x15' + ss.P(block + 4 * i)   # mov edx,[esp+4+4i]; mov [blk+4i],edx
    b += b'\xb8' + ss.P(0) + b'\xc2\x18\x00'                                           # mov eax, 0; ret 0x18
    ss.patch(c, 0x43ec00, ss.code(c, b))
    sys_ = _rnd(c, 0x1b00)
    e.w32(0x70039c, sys_)
    if c.rng.random() < 0.2:
        e.w32(sys_ + 0x1a9f, 0)                       # null child: returns 0
    else:
        # Slot 0x58 pops its two stack words; it returns 0 or a nonzero value (the third argument of 0x43ec00).
        ret = 0 if c.rng.random() < 0.2 else c.rng.getrandbits(32) | 1
        vt = e.logging_vtable('child43eb', 0x80, impl={0x58: lambda em, a: (ret, None)}, argwords={0x58: 2})
        child = _rnd(c, 0x40)
        e.w32(child, vt)
        e.w32(sys_ + 0x1a9f, child)
    self_ = _rnd(c, 0x40)
    args = [c.rng.getrandbits(32) for _ in range(7)]
    return [self_] + args


S(0x43ebb0, 'forward7 (GUESS)', 'thiscall', None, ret='eax', gen=_fwd,
  note='batch323; seven stack words; ret 0x1c; child vtbl 0x58 (2 args) then exe 0x43ec00 (six args)')
