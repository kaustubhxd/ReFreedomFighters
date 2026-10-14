"""specs_s35039.py - 0x454ca0. [this+0x5c] = list L (null in 1/6; slots 0x4c, 0x5c (flag-recorded out param, first dword zeroed after 0..3 calls, non-zero at the start in 4/5)) whose entries are 0x40-byte blocks;
engine table slot 0x58 returns an object (null in 1/3) whose +0xc points at a block whose unaligned dword at +0x23 is 0x2000ee in 2/3 of the cases; assert hook always set; 0x45be60 hooked (thiscall, 1 arg, random result)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g454ca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x45be60, 1, this=True, ret=lambda em, k: (k + 1) * 0x1111 ^ r.getrandbits(32))
    m = 0 if r.random() < 0.2 else r.choice([1, 2, 3])
    ents = [rnd(c, 0x40) for _ in range(5)]

    def s5c(em, k):
        em.w32(em.arg32(0), 0 if k >= m else r.getrandbits(32) | 1)
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: ents[min(k, 4)], side=s5c)}, nslots=0x20)
    me = rnd(c, 0x80)
    e.w32(me + 0x5c, L)
    objs = []
    for _ in range(4):
        if r.random() < 1 / 3:
            objs.append(0)
            continue
        blk = rnd(c, 0x40)
        e.wbytes(blk + 0x23, (0x2000ee if r.random() < 2 / 3 else r.getrandbits(32)).to_bytes(4, 'little'))
        o = rnd(c, 0x20)
        e.w32(o + 0xc, blk)
        objs.append(o)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, 3)])})
    return [me]


S(0x454ca0, 'GUESS refresh resolved value of listed entries', 'thiscall', None, ret=None, gen=_g454ca0, note='batch35039')
