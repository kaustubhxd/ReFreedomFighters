"""specs_s46001.py - cascade t7 batch 46001: 0x5a04f0 resource-handle table loader. 0x41e290 (alloc) and 0x634d10 (memset) are cdecl recorders; the
lookup object at [engine+0x1a9f] slot 0x60 returns random handles (0 for 0x6aebf0 sometimes); object table (+0x9b) slots 0x138/0x58, global 0x700390 slot 0x20, then cdecl slot 0x2c."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g5a04f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x98)
    hook_rec(c, 0x41e290, 1, pop=0, ret=blk)
    hook_rec(c, 0x634d10, 3, pop=0)
    zero_ebf0 = [r.random() < 0.4 for _ in range(8)]
    rets = [r.getrandbits(32) for _ in range(120)]
    cnt = [0]

    def lret(em, k):
        cnt[0] += 1
        v = rets[(cnt[0] - 1) % 120]
        if em.arg32(1) == 0x6aebf0 and zero_ebf0[(cnt[0] - 1) % 8]:
            return 0
        return v
    lookup = obj(c, 0x40, {0x60: pystub(c, 2, this=True, ret=lret), 0x80: pystub(c, 1, this=True)}) if r.random() < 0.9 else 0
    loc = r.getrandbits(32)

    set_local = [r.choice([0, 0, r.getrandbits(32)]) for _ in range(4)]
    k88 = [0]

    def s88(em, k):
        em.w32(em.arg32(1), set_local[min(k, 3)])
    o100 = obj(c, 0x40, {0x100: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    q = obj(c, 0x40, {0x88: pystub(c, 2, this=True, side=s88, stackmark=(1,))})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=q), 0x58: pystub(c, 1, this=True, ret=o100)})
    so = c.emu.r32(0x70039c)
    e.w32(so + 0x1a9f, lookup)
    errobj = obj(c, 0x40, {0x2c: pystub(c, 2, pop=0)})
    g = obj(c, 0x40, {0x20: pystub(c, 2, this=True, ret=errobj)})
    e.w32(0x700390, g)
    w = rnd(c, 0x20)
    if r.random() < 0.5:
        e.w32(w + 4, 0)
    me = obj(c, 0x980, {0x680: pystub(c, 0, this=True, ret=(r.getrandbits(32) | 1) if r.random() < 0.85 else 0)})
    e.w32(me + 0x54, w)
    return [me]


S(0x5a04f0, 'GUESS resource handle table loader', 'thiscall', None, ret=None, gen=g5a04f0, note='batch46001')
