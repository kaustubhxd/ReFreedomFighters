"""specs_s67555.py - cascade s6 batch 67555 (0x4946b0, thiscall(newSize) ret 4, no return value). The old table (this[0x18] buckets of 8 bytes, this[4] occupancy bitmap, this[0x10] used count) holds
`used` set bits among n_old buckets; newSize is below `used` sometimes (early return). 0x41e290 (alloc) is a hook returning two spec buffers in turn (requested size logged), 0x634d10 (memset) a hook that
performs and logs the fill, 0x634273 (free) and 0x493820 (insert, this + 3 args) are hooks."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4946b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    bufs = [rnd(c, 0x900), rnd(c, 0x100)]
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: bufs[min(k, 1)])

    def fill(em, k):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(p, bytes([v & 0xff]) * n)
    hook_rec(c, 0x634d10, 3, pop=0, side=fill)
    hook_rec(c, 0x634273, 2, pop=0)

    def ins(em, res_):
        em.calllog.append(('ins', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2), em.rbytes(em.arg32(0), 8)))
        em.ret(eax=0, argbytes=12)
    e.hook(0x493820, ins)
    n_old = r.choice([1, 8, 32, 33, 64])
    used = r.randrange(0, min(n_old, 12) + 1)
    bits = sorted(r.sample(range(n_old), used))
    words = (n_old + 31) // 32
    bm = e.alloc(4 * words + 4, 4)
    e.wbytes(bm, bytes(4 * words + 4))
    for b in bits:
        _w(c, bm + 4 * (b >> 5), int.from_bytes(e.rbytes(bm + 4 * (b >> 5), 4), 'little') | (1 << (b & 31)))
    old = rnd(c, 8 * n_old + 8)
    t = rnd(c, 0x30)
    _w(c, t + 4, bm)
    _w(c, t + 0x10, used)
    _w(c, t + 0x18, old)
    new = r.choice([0, used, used + 1, 32, 33, 64, 96, 70, max(0, used - 1)])
    return [t, new]


S(0x4946b0, 'GUESS rehash_table', 'thiscall', None, ret=None, gen=_g4946b0, note='batch67555')
