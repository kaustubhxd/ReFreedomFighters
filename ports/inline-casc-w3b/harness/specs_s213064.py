"""specs_s213064.py - batch 213064: table lookups and a 14-argument forward, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g531c40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    N = 6

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    this = rnd(c, 0x100)
    t98 = rnd(c, 0x15 * N + 8)
    for i in range(N):
        e.wbytes(t98 + 0x15 * i, struct.pack('<H', r.choice([r.randrange(N)] * 5 + [r.getrandbits(16) % N])) + rnd_bytes(r, 2) + struct.pack('<HHH', r.getrandbits(16), r.getrandbits(16), r.getrandbits(16)))
    last = r.randint(1, 5)
    t5a = rnd(c, 12 * N + 4)
    t54 = rnd(c, 0x16 * N + 4)
    t78 = rnd(c, 10 * N + 4)
    for base, n, stride in ((t5a, N, 12), (t54, N, 0x16)):
        for i in range(n):
            e.wbytes(base + stride * i, struct.pack('<H', r.randrange(N) if r.random() < 0.85 else 0))
    e.w32(this + 0x98, t98)
    e.w32(this + 0x38, last + 1)
    e.w32(this + 0x5a, t5a)
    e.w32(this + 0x54, t54)
    e.w32(this + 0x78, t78)
    C = rnd(c, 0x40)
    e.wbytes(C + 0x16, struct.pack('<H', r.choice([0, 1, 2, 3, 5, r.randrange(N)])))
    e.wbytes(C + 0x20, bytes([r.choice([3, 3, 0, 1, 0xff])]))
    D = r.choice([0, 1, 2, 3, 4, 5] * 3 + [10, 10, 11, 11, 6, 7, 8, 9, 12, 0xffffffff, r.getrandbits(32)])
    A = r.choice([r.randrange(N), r.randrange(N), r.getrandbits(32) & 0xffff0000 | r.randrange(N), r.getrandbits(32)]) if r.random() < 0.9 else r.randrange(N)
    A = (A & 0xffff0000) | (A % N) if A & 0xffff >= N else A
    B = r.choice([last, last, last, last - 1, 0, 3, r.getrandbits(32)])
    E = r.getrandbits(32)

    def zr(*vals):
        return lambda emu, k: r.choice(list(vals) + [r.getrandbits(32), 0, 0x10000]) if r.random() < 0.9 else 0
    hook_rec(c, 0x5320b0, 4, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x52e320, 1, ret=lambda emu, k: r.choice([0, 1, 0x10000, 0x20000, r.getrandbits(32)]), this=True)
    hook_rec(c, 0x531070, 1, ret=lambda emu, k: r.choice([0, 1, 0x10000, 0x20000, r.getrandbits(32)]), this=True)
    hook_rec(c, 0x530a40, 0, ret=lambda emu, k: r.choice([0, 1, 0x10000, 0x20000, r.getrandbits(32)]), this=True)
    hook_rec(c, 0x531e70, 14, ret=r.getrandbits(32), this=True, deref={5: -6})
    return [this, A, B, C, D, E]


def rnd_bytes(r, n):
    return bytes(r.getrandbits(8) for _ in range(n))


S(0x531c40, 'weighted_lookup_forward', 'thiscall', None, ret='eax', gen=g531c40)
