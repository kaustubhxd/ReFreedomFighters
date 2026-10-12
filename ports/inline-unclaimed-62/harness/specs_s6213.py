"""specs_s6213.py - unclaimed-62 claim 6 (slice 1): DBLK::Get (0x4e1110). The item skip 0x4e1590 (exe, DBLK) is a stub returning a random size.
The assert hook is always a logged stub (no trap); g_pDebug's slot 0x24 (cdecl, two words) is logged. The block at this+8 holds items whose
tag byte is random (3, 8, 10, 11, 0xff or another type). count is 1..3; the out array is compared. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd


def _get(c):
    e = c.emu
    r = c.rng
    sz = r.randint(0, 6)
    ss.patch(c, 0x4e1590, ss.rec(c, 0, ret=sz))
    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_6213', hook))
    def dbg24(em, rr):
        em.calllog.append(('dbg24', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=0)
    g = e.alloc(16)
    e.w32(g, e.fake_vtable('gdebug6213', 0x40, {0x24: dbg24}))
    e.w32(0x700390, g)
    items = e.alloc(64)
    e.wbytes(items, bytes(r.getrandbits(8) for _ in range(64)))
    e.w8(items, r.choice([3, 8, 10, 11, 0xff, 0x40 | 10, 5]))
    self_ = rnd(c, 0x100)
    e.w32(self_ + 8, items)
    count = r.randint(1, 3)
    out = e.alloc(16)
    e.wbytes(out, bytes(16))
    return [self_, out, count]


S(0x4e1110, 'DBLK::Get', 'thiscall', None, gen=_get, n=300)
