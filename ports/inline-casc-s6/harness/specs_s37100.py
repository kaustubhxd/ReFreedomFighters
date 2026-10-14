"""specs_s37100.py - cascade s6 batch 37100 (0x575f90, thiscall(msg, arg) ret 8, returns eax). Table slot 0x114 (4 args) maps registered names to ids (the high half of its result is
random, only the low 16 bits are compared); the message is one of the four ids, or none, with random high bits. 0x576a30 / 0x573860 hooks, logger at 0x700390."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g575f90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = {0x6a77ac: r.randrange(1, 0x1000), 0x6a77a0: r.randrange(0x1000, 0x2000), 0x6a6698: r.randrange(0x2000, 0x3000), 0x6a9300: r.randrange(0x3000, 0x4000)}
    hi = {k: r.getrandbits(16) << 16 for k in ids}

    def lookup(em, k):
        nm = em.arg32(0)
        return ids.get(nm, 0) | hi.get(nm, 0)

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    so = sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lookup), 0xb4: pystub(c, 1, this=True)}, table_size=0x130)
    win = obj(c, 0x20, {0x138: pystub(c, 1, this=True)})
    _w(c, so + 0x1a9f, win if r.random() < 0.7 else 0)
    hook_rec(c, 0x576a30, 1, this=True)
    hook_rec(c, 0x573860, 2, this=True, ret=lambda em, k: r.getrandbits(32))
    own = obj(c, 0x20, {0x2fc: pystub(c, 1, this=True)})
    t = obj(c, 0x220, {0x84: pystub(c, 0, this=True, ret=own)})
    _w(c, t + 0x94, r.getrandbits(32))
    _w(c, t + 0x44, r.getrandbits(32))
    pick = r.random()
    if pick < 0.8:
        msg = r.choice(list(ids.values()))
    else:
        msg = r.randrange(0, 0x5000)
    msg |= r.getrandbits(16) << 16 if r.random() < 0.5 else 0
    arg = r.choice([0, 0, r.getrandbits(32)])
    return [t, msg, arg]


S(0x575f90, 'GUESS handle_message', 'thiscall', None, ret='eax', gen=_g575f90, note='batch37100')
