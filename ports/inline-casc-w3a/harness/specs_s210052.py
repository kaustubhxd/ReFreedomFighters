"""specs_s210052.py - Sonnet-w3a: 0x4a02e0. Manager slot 0x4c(obj) is a hooked stub returning ids from a small pool by object (so equal ids appear), list at this+0x6e (unaligned), count at this+0x6a."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g4a02e0(c):
    clear_hooks(c)
    e = c.emu
    ah = e.stub_fn('assert hook', lambda e2, r_: (e2.calllog.append(('assert',)), e2.ret(eax=0)))
    e.w32(0x7003b0, ah)
    e.wbytes(0x7002c0, (_r(c) & 0xffff).to_bytes(2, 'little'))
    pool = [c.rng.choice([1, 2, 3, 0x1234, _r(c)]) for _ in range(4)]
    cap = c.rng.choice([0, 1, 0x100, 0x2ff])
    tgt = obj(c, 0x40, {0x130: pystub(c, 3, ret=_r(c), this=True)}, nslots=0x60)
    o = obj(c, 0x40, {0x1e0: pystub(c, 1, ret=cap, this=True)}, nslots=0x90)
    ids = {}

    def idof(emu, k):
        return pool[c.rng.randrange(4)] if False else pool[k % 4]
    mg = obj(c, 0x40, {0x4c: pystub(c, 1, ret=idof, this=True)}, nslots=0x30)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    s = rnd(c, 0x100)
    e.wbytes(s + 0x5e, bytes([c.rng.choice([0, 1, 1, 1, 2])]))
    e.w32(s + 0x44, tgt)
    n = c.rng.choice([0, 0, 1, 2, 2, 3])
    e.wbytes(s + 0x6a, n.to_bytes(4, 'little'))
    for i in range(4):
        e.wbytes(s + 0x6e + 4 * i, c.rng.choice(pool + [_r(c)]).to_bytes(4, 'little'))
    return [s, o]


S(0x4a02e0, 'register_id_in_list', 'thiscall', None, ret=None, gen=g4a02e0, note='batch210052')
