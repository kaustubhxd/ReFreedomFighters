"""specs_s34053.py - cascade tier E, batch 34053.
0x5b8200 / 0x5b8270: [[this+0x54]+0x18] is the iterator object (null in a seventh; slots 0x4c, 0x5c with a stack iterator, 0..3 ids); the global object at 0x70038c has slot 0xcc (returns an object with slot 0x128, three
stack args); the stored words at +0x5a / +0x58 are random.
0x5c1aa0: the unaligned dword at +0x111 is zero in half the cases; the id array at [this+0xe4] holds 0..4 non-zero ids then a zero; the counter start [this+0xe8] and [this+0x48] are chosen so that the equality fires
for some element; the object at the unaligned +0x10d has slot 0x25c (returns an object, null in a quarter, with slot 0xbc); engine +0x1b5d is zero in half the cases; this slot 0x68 (two args) is a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _gen_send(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3])

    def begin(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    def nxt(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    l = 0 if r.random() < 1 / 7 else obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                                                   0x5c: pystub(c, 1, this=True, side=nxt, stackmark=(0,), ret=lambda em, k: r.getrandbits(32))},
                                         nslots=0x60 // 4)
    owner = rnd(c, 0x30)
    c.emu.w32(owner + 0x18, l)
    target = obj(c, 0x20, {0x128: pystub(c, 3, this=True)}, nslots=0x130 // 4)
    g = obj(c, 0x20, {0xcc: pystub(c, 1, ret=target, this=True)}, nslots=0xd0 // 4)
    c.emu.w32(0x70038c, g)
    me = rnd(c, 0x70)
    c.emu.w32(me + 0x54, owner)
    return [me]


def _g5c1aa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4])
    arr = rnd(c, 0x20)
    ids = [r.getrandbits(32) | 1 for _ in range(n)] + [0]
    for i, v in enumerate(ids):
        e.w32(arr + 4 * i, v)
    objs = [0 if r.random() < 0.25 else obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4) for _ in range(5)]
    owner = obj(c, 0x20, {0x25c: pystub(c, 2, ret=lambda em, k: objs[min(k, 4)], this=True)}, nslots=0x260 // 4)
    so = sysobj(c)
    e.wbytes(so + 0x1b5d, (0 if r.random() < 0.5 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    me = obj(c, 0x120, {0x68: pystub(c, 2, this=True)}, nslots=0x70 // 4)
    start = r.getrandbits(32) & 0xff
    e.w32(me + 0xe4, arr)
    e.w32(me + 0xe8, start)
    e.w32(me + 0x48, (start + r.randrange(0, 5)) & 0xffffffff if r.random() < 0.8 else r.getrandbits(32))
    e.wbytes(me + 0x10d, owner.to_bytes(4, 'little'))
    e.wbytes(me + 0x111, (0 if r.random() < 0.5 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    return [me]


def _gen_a(c):
    return _gen_send(c)


S(0x5b8200, 'GUESS send stored word +0x5a to the objects of an id list', 'thiscall', None, ret=None, gen=_gen_a, note='batch34053')
S(0x5b8270, 'GUESS send stored word +0x58 to the objects of an id list', 'thiscall', None, ret=None, gen=_gen_a, note='batch34053')
S(0x5c1aa0, 'GUESS toggle visibility of a listed set then maybe notify', 'thiscall', None, ret=None, gen=_g5c1aa0, note='batch34053')
