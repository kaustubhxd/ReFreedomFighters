"""specs_s67544.py - cascade s6 batch 67544 (0x555b30, stdcall(req) ret 4, return value unused). 0x5003d0 (hook) returns the id node (byte +4 0 / 1 / other), then a node whose two dwords the
log path reads, then the result node; 0x5002f0 (hook) records the result value. Object table slot 0x58 maps the id to an object (or 0); object slot 0x1e0 (bool, answers vary per call); the
selection list lives at [0x7003b8] + 0x2c55; logger at 0x700390 (cdecl slot 0x2c: 3 args for fmt 0x69c6b0, 4 for 0x6a5de8); assert hook set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g555b30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg2c(em, res_):
        n = 2 if em.arg32(1) == 0x69c6b0 else 3
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(1, n + 1))))
        em.ret(eax=0, argbytes=0)
    x = obj(c, 0x20, {0x2c: e.stub_fn('recorder', lg2c)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=x)}))
    objs = [obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100]))}) for _ in range(4)]
    pick = r.choice(objs + [0])
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: pick)})
    blk = e.alloc(0x2d00, 4)
    e.wbytes(blk, bytes(0x2d00))
    n = r.choice([0, 1, 2, 5, 11, 12])
    e.w32(blk + 0x2c55, n)
    for i in range(n):
        e.w32(blk + 0x2c55 + 4 + 4 * i, r.choice(objs + [rnd(c, 0x10)]) if r.random() < 0.8 else r.choice(objs))
    e.w32(0x7003b8, blk)
    n1 = rnd(c, 0x10)
    e.wbytes(n1 + 4, bytes([r.choice([0, 1, 1, 2, 0x80])]))
    nl = rnd(c, 0x10)
    nr = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: [n1, nl, nr][min(k, 2)])
    hook_rec(c, 0x5002f0, 1, this=True)
    return [rnd(c, 0x20)]


S(0x555b30, 'GUESS selection_can_add', 'stdcall', None, ret=None, gen=_g555b30, note='batch67544')
