"""specs_s38068.py - cascade s8 batch 38068: 0x409ac0. cdecl(A, B, out, N, cb) -> 0. B[0]=C {start, end = start + Hn*S, stride S (1..4), flag words at +0x14 (8 idx, random bits)}; *B[0x14] = W (1..3);
B[0xc] = planes 0..3; B[0x20] = table of 8 row-index tables (8 dwords each, values 0..7; entries occasionally null); B[0x18] = 8 plane-pointer arrays (4 entries, some null). N 0..3 tile buffers.
Hooks: 0x401820 (allocates the requested size), 0x405f20 (returns an index 0..7, rarely -1); the callback logs (value, pointer, A+4, S) and returns -1 rarely."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g409ac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    A = e.alloc(0x10, 4)
    e.wbytes(A, r.randbytes(0x10))
    Hn = r.choice([0, 1, 2, 3, 4, 5, 7])
    St = r.choice([1, 2, 3, 4])
    start = r.randrange(0, 20)
    C = e.alloc(0x14 + 4 * 8 + 4, 4)
    e.wbytes(C, r.randbytes(0x14 + 36))
    e.w32(C, start)
    e.w32(C + 4, start + Hn * St + r.randrange(0, St))
    e.w32(C + 8, St)
    for i in range(8):
        e.w32(C + 0x14 + 4 * i, r.choice([0xf, 0xf, 0x5, 0xa, 0x1, r.getrandbits(4)]))
    W = r.choice([1, 2, 3])
    Wp = e.alloc(8, 4)
    e.w32(Wp, W)
    tabs = []
    for i in range(8):
        t = e.alloc(8 * 4, 4)
        e.wbytes(t, struct.pack('<8I', *[r.randrange(8) for _ in range(8)]))
        tabs.append(t if r.random() > 0.04 else 0)
    t20 = e.alloc(32, 4)
    e.wbytes(t20, struct.pack('<8I', *tabs))
    planes = []
    for i in range(8):
        q = e.alloc(16, 4)
        e.wbytes(q, struct.pack('<4I', *[r.getrandbits(32) | 1 if r.random() < 0.8 else 0 for _ in range(4)]))
        planes.append(q)
    t18 = e.alloc(32, 4)
    e.wbytes(t18, struct.pack('<8I', *planes))
    B = e.alloc(0x30, 4)
    e.wbytes(B, r.randbytes(0x30))
    e.w32(B, C)
    e.w32(B + 0xc, r.choice([0, 1, 2, 3, 3]))
    e.w32(B + 0x14, Wp)
    e.w32(B + 0x18, t18)
    e.w32(B + 0x20, t20)
    N = r.choice([0, 1, 2, 3])
    outarr = e.alloc(16, 4)
    e.wbytes(outarr, struct.pack('<4I', *[r.getrandbits(32) for _ in range(4)]))

    def cb(em, res_):
        em.calllog.append(('cb', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=(0xffffffff if r.random() < 0.03 else r.getrandbits(8)))
    cbp = e.stub_fn('cb', cb)

    def alloc_h(em, res_):
        sz = em.arg32(1)
        em.calllog.append(('alloc', em.arg32(0), sz))
        p = e.alloc(max(sz, 4), 4)
        em.ret(eax=p)
    e.hook(0x401820, alloc_h)

    def lk(em, res_):
        em.calllog.append(('lookup', em.arg32(0), em.arg32(1)))
        em.ret(eax=(0xffffffff if r.random() < 0.04 else r.randrange(8)))
    e.hook(0x405f20, lk)
    return [A, B, outarr, N, cbp]


S(0x409ac0, 'GUESS walk tile grid and call callback', 'cdecl', None, ret='eax', gen=_g409ac0, note='batch38068')
