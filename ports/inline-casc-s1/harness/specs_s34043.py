"""specs_s34043.py - cascade tier E, batch 34043.
0x5efe00: hooked 0x5ee720; the stream's slots 0x50 and 0x68 (heap pointer args) and 0x40 (stack pointer arg: writes a random dword) are recorders.
0x5fd240: the import VCRUNTIME140!memmove is a Python stub (logs dst offset, src offset and size, performs the copy, pops nothing); the array holds n = 0..6 random dwords; k is one of them (any
position, last position included) in two thirds of the cases.
0x64db30: current chunk with count 1..4 and random items, previous chunk null or valid, [this+4] slot 0xc a recorder, the iterator p points at the last item, at another item, and [p+8] is random."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g5efe00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ee720, 1, this=True)

    def wv(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    s = obj(c, 0x20, {0x50: pystub(c, 1, this=True), 0x68: pystub(c, 1, this=True),
                      0x40: pystub(c, 1, this=True, side=wv, stackmark=(0,))}, nslots=0x70 // 4)
    return [rnd(c, 0xb0), s]


def _g5fd240(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mm(em, res_):
        dst, src, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memmove', dst - base, src - base, n))
        em.wbytes(dst, bytes(em.rbytes(src, n)))
        em.ret(eax=dst, argbytes=0)
    e.stub_import('memmove', mm)
    n = r.choice([0, 1, 2, 3, 6, r.randint(0, 6)])
    base = rnd(c, 0x40)
    vals = [r.getrandbits(32) for _ in range(8)]
    for i, v in enumerate(vals):
        e.w32(base + 4 * i, v)
    me = rnd(c, 0x20)
    e.w32(me, base)
    e.w32(me + 8, n)
    k = vals[r.randrange(max(n, 1))] if (n and r.random() < 0.67) else r.getrandbits(32)
    return [me, k]


def _g64db30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = r.choice([1, 1, 2, 3, 4])
    blk = rnd(c, 0x40)
    e.w32(blk, cnt)
    prev = 0 if r.random() < 0.5 else rnd(c, 0x40)
    e.w32(blk + 0xc, prev)
    owner = obj(c, 0x20, {0xc: pystub(c, 1, this=True)}, nslots=0x10 // 4)
    me = rnd(c, 0x20)
    e.w32(me + 0x10, blk)
    e.w32(me + 4, owner)
    last = blk + 0x10 + 4 * (cnt - 1)
    it = last if (cnt == 1 or r.random() < 0.5) else blk + 0x10 + 4 * r.randrange(cnt - 1)
    p = rnd(c, 0x20)
    e.w32(p, it)
    return [me, p]


S(0x5efe00, 'GUESS read five fields from a stream', 'thiscall', None, ret=None, gen=_g5efe00, note='batch34043')
S(0x5fd240, 'GUESS remove a value from an array', 'thiscall', None, ret='al', gen=_g5fd240, note='batch34043')
S(0x64db30, 'GUESS pop item from chunked list', 'thiscall', None, ret=None, gen=_g64db30, note='batch34043')
