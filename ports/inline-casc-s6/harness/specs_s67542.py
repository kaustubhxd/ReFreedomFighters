"""specs_s67542.py - cascade s6 batch 67542 (0x557230, stdcall(req) ret 4, return value unused). 0x5003d0 (node by (owner, index)) is a hook returning the id node first, then the count node (byte +4
0 / 1 / other); the object table slot 0x58 maps the id to an object (or 0) whose slot 0x1e0 (bool) and slot 0x50 (cursor update through a stack-marked pointer, writes the next child from a short list)
drive the walk; 0x4db9a0 and 0x5002f0 are hooks; logger at 0x700390 (slot 0x20 -> object with cdecl slot 0x2c, 3 args for fmt 0x69c6b0, else 2); assert hook set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g557230(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg2c(em, res_):
        n = 2 if em.arg32(1) == 0x69c6b0 else 1
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(1, n + 1))))
        em.ret(eax=0, argbytes=0)
    x = obj(c, 0x20, {0x2c: e.stub_fn('recorder', lg2c)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=x)}))
    kids = [rnd(c, 0x20) for _ in range(4)]
    nxt = [r.choice(kids + [0]) for _ in range(5)]

    def side(em, k):
        em.wbytes(em.arg32(0), (nxt[k] if k < 5 else 0).to_bytes(4, 'little'))
    o = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 1, 0x100])),
                      0x50: pystub(c, 1, this=True, stackmark=(0,), side=side)})
    e.wbytes(o + 8, r.choice(kids + [0]).to_bytes(4, 'little'))
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: r.choice([o, o, o, 0]))})
    n1 = rnd(c, 0x10)
    n2 = rnd(c, 0x10)
    e.wbytes(n2 + 4, bytes([r.choice([0, 1, 2, 0x80])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: [n1, n2][min(k, 1)])
    hook_rec(c, 0x5002f0, 1, this=True)
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 5]))
    req = rnd(c, 0x20)
    return [req]


S(0x557230, 'GUESS count_flagged_children', 'stdcall', None, ret=None, gen=_g557230, note='batch67542')
