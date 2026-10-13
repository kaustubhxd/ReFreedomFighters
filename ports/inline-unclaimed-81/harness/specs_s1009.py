"""specs_s1009.py - area 81 (residue 11 remainder), batch 1009: ZCarIf::addMethodDefinitions (0x51b270). The count at 0x701800 is random in 0..0x20, so the
ten appends never reach the limit of 0x32 and the overflow branch (vslot 0x44 and the hook) is not exercised. The helper 0x51aba0 is a counting stub
(area 23 claims it as ZVehicleIf::addMethodDefinitions). The list's flag byte at +0xc is set in most cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import obj, r32


def g(c):
    ss.patch(c, 0x51aba0, ss.rec(c, 1))
    c.emu.w32(0x701800, c.rng.randint(0, 0x20))
    for i in range(0x20):
        c.emu.w32(0x701808 + 4 * i, r32(c))
    self_ = obj(c, 0x40)
    lst = obj(c, 0x20)
    c.emu.wbytes(lst + 0xc, bytes([1 if c.rng.random() < 0.8 else 0]))
    return [self_, lst]


S(0x51b270, 'ZCarIf::addMethodDefinitions', 'thiscall', gen=g)
