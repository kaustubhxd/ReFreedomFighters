"""specs_s3014.py - unclaimed-30 batch 14 (docs/20-unclaimed-30.md, claim 1): 0x519950 (no name in the name map). The float slot (+0x2d4,
st0 value) is a stub; the array the element comes from is built valid (index 0 inside the count, element byte +4 random). The
reporter (pfspec) takes the message; the assert hook is a logged stub. No faulting cases."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd, reporter


def _u(c):
    e = c.emu
    r = c.rng
    reporter(c, 0.0)
    fv = e.alloc(4)
    e.wf32(fv, r.uniform(-2, 2))
    fret = ss.code(c, b'\xd9\x05' + struct.pack('<I', fv) + b'\xc3')
    lo = e.alloc(16)
    e.w32(lo, e.fake_vtable('lo', 0x200, {0x2d4: fret}))
    self_ = rnd(c, 0x40)
    e.w32(self_ + 0x14, lo)
    # the assert hook (0x7003b0): the exe traps (int3) when it is null, so a logged hook is installed here
    def hook(em, rr):
        em.calllog.append(('assert',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_hook', hook))
    # arr object at x+8: +0 -> P (data, count at P+8), +4 offset, +8 count (>= 1)
    data = e.alloc(8 * 4)
    elem_t = r.choice([0, 1, 2, 3])
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(32)))
    e.w8(data + 4, elem_t)
    P = e.alloc(16)
    e.w32(P, data)
    e.w32(P + 8, 4)
    arr = e.alloc(16)
    e.w32(arr, P)
    e.w32(arr + 4, 0)
    e.w32(arr + 8, 1)
    x = e.alloc(16)
    e.w32(x + 8, arr)
    return [self_, x]


S(0x519950, 'unnamed 0x519950', 'thiscall', None, gen=_u, n=300)
