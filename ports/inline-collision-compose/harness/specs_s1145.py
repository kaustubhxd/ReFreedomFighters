"""specs_s1145.py - collision thread batch 1145 (GUESS name): 0x43b630 (void). X (at this+0xd) is a logged fake: slot 0x14 (no
arguments) returns a per-case limit N; slot 0x34 (one argument, logged) returns the entry object Z (the same object each call).
Z's first dword equals A in half of the cases; Z+4 is a byte drawn 0 or 1. The global sys+0x1c is a dword; this+0x16 equals it in
a quarter of the cases, else differs by a value on either side of 0x1400. The counter at this+0x11 starts 0..N+1."""
import struct
from pilot import S, F


def _step(c):
    e, r = c.emu, c.rng
    N = r.randrange(0, 4)
    Z = e.alloc(0x40, 16)
    e.wbytes(Z, bytes(r.getrandbits(8) for _ in range(0x40)))
    A = r.getrandbits(32)
    e.w32(Z, A if r.random() < 0.5 else r.getrandbits(32))
    e.wbytes(Z + 4, bytes([r.choice([0, 1])]))

    def slot14(em, rr):
        em.ret(eax=N, argbytes=0)

    def slot34(em, rr):
        em.calllog.append(('34', em.arg32(0)))
        em.ret(eax=Z, argbytes=4)

    xvt = e.fake_vtable('X_43b630', 0x40, {0x14: slot14, 0x34: slot34})
    X = e.alloc(0x40, 16)
    e.w32(X, xvt)
    sys_ = e.alloc(0x40, 16)
    e.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0x40)))
    gv = r.getrandbits(32)
    e.w32(sys_ + 0x1c, gv)
    e.w32(0x70039c, sys_)
    self_ = e.alloc(0x40, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(self_ + 0xd, X)
    e.w32(self_ + 0x11, N if r.random() < 0.35 else r.randrange(0, N + 2))   # the counter equal to the limit: the reset branch
    k = r.random()
    if k < 0.25:
        e.w32(self_ + 0x16, gv)
    else:
        e.w32(self_ + 0x16, (gv - r.choice([0x100, 0x1200, 0x1400, 0x1401, 0x2000, 0x1000])) & 0xffffffff)
    return [self_, A, r.choice([0, 1, 0x100])]


S(0x43b630, 'counter and flag update on X and Z, then the global copy (name GUESS; void)', 'thiscall', None, ret=None,
  gen=_step, note='batch1145')
