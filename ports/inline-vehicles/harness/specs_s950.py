"""specs_s950.py - vehicles batch 950: deleting destructors of ZCar (0x5171f0), ZTank (0x520360) and ZHeli (0x51bd30).
Everything runs as exe code (member dtors, base dtor, free); the flags byte is random 0..7 (bit 0 deletes, bit 2 chooses
the sized delete). The object is a random block of the class size."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, cstub


def mk(size, member):
    def g(c):
        if member:
            ss.patch(c, member, ss.rec(c, 0))
        ss.patch(c, 0x512070, ss.rec(c, 0))
        ss.patch(c, 0x45c510, cstub(c, 1))
        return [_rnd(c, size), c.rng.randint(0, 7)]
    return g


S(0x5171f0, 'ZCar::~ZCar', 'thiscall', gen=mk(0x1800, 0x511950))
S(0x520360, 'ZTank::~ZTank', 'thiscall', gen=mk(0x2800, 0x511a00))
S(0x51bd30, 'ZHeli::~ZHeli', 'thiscall', gen=mk(0x1000, None))
