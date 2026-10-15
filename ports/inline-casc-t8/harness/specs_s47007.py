"""specs_s47007.py - cascade t8 batch 47007: 0x5c17c0 (init handlers from named config), 0x604570 (case-insensitive substring search)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5c17c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    objs = [0] + [obj(c, 0x20, {0x128: pystub(c, 1, this=True)}) for _ in range(3)]
    rd = obj(c, 0x20, {0x88: pystub(c, 2, this=True, nullflag=(1,),
                                    side=lambda em, k: em.w32(em.arg32(1), r.getrandbits(32)) if r.random() < 0.8 else None)})
    h2 = obj(c, 0x20, {0x100: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    holder = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=h2 if r.random() < 0.8 else 0)})

    def side114(em, k):
        em.w32(em.arg32(4), r.choice([0, 1, r.getrandbits(32)]))
    so = sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=rd),
                                0x58: pystub(c, 1, this=True, ret=lambda em, k: r.choice(objs)),
                                0x114: pystub(c, 6, this=True, nullflag=(4,), ret=lambda em, k: r.getrandbits(32), side=side114)}, table_size=0xb00)
    tbl = e.r32(so + 0x9b)
    e.w32(tbl + 0xadc, holder)
    c44 = obj(c, 0x20, {0x84: pystub(c, 1, this=True, deref={0: 3})})
    me = obj(c, 0x200, {})
    e.w32(me + 0x44, c44)
    hook_rec(c, 0x5c21e0, 1, this=True)
    return [me]


def _g604570(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    alpha = b'aAbBc'
    nh = r.choice([0, 1, 2, 5, 8, 12])
    nn = r.choice([0, 1, 2, 2, 3, 4])
    hay = bytes(r.choice(alpha) for _ in range(nh))
    nd = bytes(r.choice(alpha) for _ in range(nn))
    if nn and nh >= nn and r.random() < 0.6:
        i = r.randrange(0, nh - nn + 1)
        hay = hay[:i] + nd.swapcase() + hay[i + nn:]
    h = e.alloc(0x20, 4)
    n = e.alloc(0x10, 4)
    e.wbytes(h, hay + bytes(r.getrandbits(8) for _ in range(0x20 - nh)))
    e.wbytes(n, nd + bytes(r.getrandbits(8) for _ in range(0x10 - nn)))
    return [h, h + nh, n, n + nn, r.getrandbits(32)]


S(0x5c17c0, 'GUESS init handlers from named config', 'thiscall', None, ret=None, gen=_g5c17c0, note='batch47007')
S(0x604570, 'GUESS case-insensitive substring search', 'fastcall', None, ret='eax', gen=_g604570, note='batch47007')
