"""specs_s66052.py - cascade s4 batch 66052: 0x4cf850 (sort the elements of a container, detach and free them)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub, reftab_vt


def _g4cf850(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 4])
    elems = [e.alloc(0x10, 8) for _ in range(n)]
    cnt = r.choice([n, n, n, 0x40000001, 5])
    base = reftab_vt(c, list(elems), count=cnt)
    vt = e.alloc(0x100, 4)
    for off in (0x14, 0x4c, 0x5c):
        e.w32(vt + off, int.from_bytes(bytes(e.rbytes(base + off, 4)), 'little'))
    e.w32(vt + 0x7c, pystub(c, 1, this=True, side=lambda em, k: em.w32(em.arg32(0) + 4, 0)))
    e.w32(vt + 0x8c, pystub(c, 1, this=True))

    def alloc(em, rr):
        em.calllog.append(('alloc', em.arg32(0)))
        em.ret(eax=e.alloc(max(min(em.arg32(0), 0x100), 16), 8), argbytes=0)
    e.hook(0x41e290, alloc)
    hook_rec(c, 0x634273, 2, pop=0)

    def qs(em, rr):                       # qsort (base, n, size, cmp): reverses the array
        b, nn, sz, cmpf = em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)
        em.calllog.append(('qsort', nn, sz, cmpf))
        vals = [em.r32(b + 4 * i) for i in range(nn)]
        for i, v in enumerate(reversed(vals)):
            em.w32(b + 4 * i, v)
        em.ret(eax=0, argbytes=0)
    e.stub_import('qsort', qs)
    t = e.alloc(0x40, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(t, vt)
    chain = []
    for i in range(r.choice([0, 1, 2, 3])):
        nd = e.alloc(0x10, 8)
        chain.append(nd)
    for i, nd in enumerate(chain):
        e.w32(nd + 4, chain[i + 1] if i + 1 < len(chain) else 0)
    e.w32(t + 4, chain[0] if chain else 0)
    e.w32(t + 0x14, r.getrandbits(32))
    return [t]


S(0x4cf850, 'GUESS sort the elements of a container then detach and free them', 'thiscall', None, ret=None, gen=_g4cf850, note='batch66052')
