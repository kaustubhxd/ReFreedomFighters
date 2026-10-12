"""specs_s1512.py - unclaimed-15 claim 12 (docs/20-unclaimed-15.md): ZMovementBaseMove::ZMovementBaseMove (0x4876e0).

Stubbed (unverified, not lifted): the member constructor 0x480980, which is called three times with no arguments on the
embedded objects at +0x25, +0x3d and +0x55. The stub records each `this` in a heap ring, so the call order is compared. The object is 0x200 random
bytes (so the stores that matter, at +0x1c, +0x21 and +0x1d, change memory the harness compares). The two arguments are
random. Return value (this) is compared."""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ctor(c):
    o = _rnd(c, 0x200)
    # The member stub records each `this` (ecx) in a heap ring, so the call order is compared (rec() only counts).
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    code = (b'\xa1' + ss.P(cnt)                      # mov eax, [cnt]
            + b'\x89\x0c\x85' + ss.P(ring)          # mov [ring + eax*4], ecx
            + b'\xff\x05' + ss.P(cnt)                # inc dword [cnt]
            + b'\xc3')                                # ret (no arguments)
    ss.patch(c, 0x480980, ss.code(c, code))
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4876e0, 'ZMovementBaseMove::ZMovementBaseMove (unknown) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-15 claim 12; member ctor 0x480980 stubbed (rec, 0 args), called on +0x25, +0x3d, +0x55')
