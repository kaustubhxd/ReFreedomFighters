"""specs_s38009.py - cascade s8 batch 38009: 0x49c7c0. Scene node s (obj+0x54, null 12%) with flags dword at [[s+0xc]+0x23] drawn from the bit combinations of 0x800000 /
0x100000; shared node vtable: slot 0x50 writes the next child (child -> next map) through its out parameter, slot 0x20 returns the next sibling, slot 0x1e0 returns a random
bool. 0x4de7a0 / 0x4daf90 / 0x4db7c0 / 0x4db600 fill their output structs with random data; 0x4df330 (fastcall) records the struct contents it is given."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g49c7c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    nxt = {}
    sib = {}

    def s50(em, res_):
        out = em.arg32(0)
        cur = em.r32(out)
        em.calllog.append(('s50', em.reg('ecx'), cur))
        em.w32(out, nxt.get(cur, 0))
        em.ret(eax=r.getrandbits(32), argbytes=4)

    def s20(em, res_):
        em.calllog.append(('s20', em.reg('ecx')))
        em.ret(eax=sib.get(em.reg('ecx'), 0), argbytes=0)

    pa = r.choice([0.2, 0.6, 0.9])

    def s1e0(em, res_):
        em.calllog.append(('s1e0', em.reg('ecx'), em.arg32(0)))
        em.ret(eax=(r.getrandbits(24) << 8) | (1 if r.random() < pa else 0), argbytes=4)
    vt = e.alloc(0x200, 4)
    e.w32(vt + 0x50, e.stub_fn('s50', s50))
    e.w32(vt + 0x20, e.stub_fn('s20', s20))
    e.w32(vt + 0x1e0, e.stub_fn('s1e0', s1e0))

    def mknode(flags):
        n = rnd(c, 0x60)
        e.w32(n, vt)
        blk = rnd(c, 0x40)
        e.wbytes(blk + 0x23, struct.pack('<I', flags))
        e.w32(n + 0xc, blk)
        return n
    ch = r.choice([0x800000, 0x900000, 0x100000, 0x100000, 0, 0x1000000, 0x900001, r.getrandbits(32)])
    snodes = [mknode(ch)] + [mknode(r.choice([0x800000, 0x900000, 0x100000, 0x800000])) for _ in range(r.randrange(0, 3))]
    for a, b in zip(snodes, snodes[1:]):
        sib[a] = b
    for sn in snodes:
        kids = [rnd(c, 0x60) for _ in range(r.randrange(0, 4))]
        for k in kids:
            if r.random() < 0.3:
                e.w32(k + 0x54, 0)
        for a, b in zip(kids, kids[1:]):
            nxt[a] = b
        e.w32(sn + 8, kids[0] if kids else 0)
    obj = rnd(c, 0x60)
    e.w32(obj + 0x54, snodes[0] if r.random() > 0.12 else 0)

    def fill(n_arg_idx, nbytes):
        def side(em, k):
            em.wbytes(em.arg32(n_arg_idx), bytes(r.getrandbits(8) for _ in range(nbytes)))
        return side

    def side_ctor(em, k):
        em.wbytes(em.reg('ecx'), bytes(r.getrandbits(8) for _ in range(0x24)))
    hook_rec(c, 0x4de7a0, 0, this='mark', side=side_ctor)
    hook_rec(c, 0x4daf90, 1, this=True, pop=4, stackmark=(0,), side=fill(0, 12))
    hook_rec(c, 0x4db7c0, 1, this=True, pop=4, stackmark=(0,), side=fill(0, 12))
    hook_rec(c, 0x4db600, 2, this=True, pop=8, stackmark=(0, 1), side=fill(0, 0x24))
    pr = r.choice([0.2, 0.6, 0.9])

    def side_df(em, k):
        em.calllog.append(('df', em.rbytes(em.reg('ecx'), 0x24), em.rbytes(em.reg('edx'), 12)))
    hook_rec(c, 0x4df330, 4, this='mark', pop=16, deref={0: -12, 1: -0x24, 2: -12, 3: -12}, side=side_df,
             ret=lambda em, k: (r.getrandbits(24) << 8) | (1 if r.random() < pr else 0))
    return [obj]


S(0x49c7c0, 'GUESS flag scene nodes touching the object bounds', 'stdcall', None, ret=None, gen=_g49c7c0, note='batch38009')
