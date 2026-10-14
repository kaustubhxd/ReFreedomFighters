"""specs_s3006.py - unclaimed-30 batch 6 (docs/20-unclaimed-30.md, claim 1): CHitpointControl::Load2 (0x584610). The global list
(0x7003b8) and its sub-list (+0x4a0: cursor +4, end +8) are built per case; the cursor is either inside the buffer (store) or at
the end (the exe's insert at 0x4301c0 grows it through the allocator). The message table slot 0x4c is a logged stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def _alloc_obj(c):
    e = c.emu

    def new(em, rr):
        n = em.arg32(0)
        em.calllog.append(('alloc', n))
        em.ret(eax=em.alloc(n, 16, 0x5a) if n < 0x200000 else 0, argbytes=4)

    def free(em, rr):
        em.calllog.append(('free',))
        em.ret(argbytes=4)
    a = e.alloc(16)
    e.w32(a, e.fake_vtable('allocator', 0x14, {8: new, 0x10: free}))
    e.w32(0x70038c, a)


def _load2(c):
    r = c.rng
    e = c.emu
    _alloc_obj(c)
    ret = r.getrandbits(32)
    msg = e.alloc(0x100)
    e.w32(msg, e.fake_vtable('msgtable', 0x20, {0x4c: _stub_ret(c, ret)}))
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    g = e.alloc(0x5000)
    e.w32(g + 0xb61, r.randint(0, 3))
    buf = e.alloc(64)
    k = r.randint(1, 3)
    end = buf + 4 * k
    at_end = r.random() < 0.3
    e.w32(g + 0x4a0, buf)
    e.w32(g + 0x4a0 + 4, end if at_end else buf + 4 * r.randint(0, k - 1))
    e.w32(g + 0x4a0 + 8, end)
    e.w32(0x7003b8, g)
    self_ = e.alloc(0x80)
    e.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    e.w8(self_ + 0x63, r.choice([0, 1]))
    e.w32(self_ + 0x44, r.getrandbits(32))
    return [self_]


def _stub_ret(c, ret):
    return ss.rec(c, 1, ret=ret)


S(0x584610, 'CHitpointControl::Load2', 'thiscall', None, gen=_load2, n=300)
