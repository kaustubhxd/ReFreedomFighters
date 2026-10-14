"""specs_s37048.py - cascade s6 batch 37048: 0x600280. Chain of tables (spec blocks with the packed arrays the function reads); hooks: 0x600940 (8 args), 0x5ffb00, 0x5fe880 (3 args),
0x5ffc10; logger at 0x700390 and the assert hook are set."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g600280(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    hook_rec(c, 0x600940, 8, this=True, pop=0x20)
    hook_rec(c, 0x5ffb00, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x5fe880, 3, this=True, pop=0xc)
    hook_rec(c, 0x5ffc10, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    keys_all = []

    def mktab(parent):
        t = rnd(c, 0x120)
        n = r.choice([0, 1, 2, 3])
        keys = [r.randrange(0x100, 0x200) for _ in range(n)]
        keys_all.extend(keys)
        karr = e.alloc(0x20, 4)
        for i, k in enumerate(keys):
            e.w32(karr + 4 * i, k)
        e.w32(t + 0xcc, r.choice([0, 0x100, 0x150]))
        e.w32(t + 0xd0, n)
        e.w32(t + 0xe0, karr)
        e.w32(t + 0x9c, parent)
        pairs = e.alloc(0x40, 4)
        for i in range(8):
            e.w32(pairs + 4 * i, r.getrandbits(32))
        e.w32(t + 0xec, pairs)
        warr = e.alloc(0x20, 2)
        for i in range(4):
            e.wbytes(warr + 2 * i, r.choice([0, 1, 2, 3, 5, 0x10]).to_bytes(2, 'little'))
        e.w32(t + 0xf0, warr)
        e.w32(t + 0xa0, r.choice([0, 1, 2]))
        e.w32(t + 0xa8, r.choice([0, 2, 4]))
        imap = e.alloc(0x20, 4)
        for i in range(4):
            e.w32(imap + 4 * i, r.getrandbits(32))
        e.w32(t + 0xac, imap)
        e.w32(t + 0xb0, r.getrandbits(32))
        offs = e.alloc(0x20, 2)
        for i in range(4):
            e.wbytes(offs + 2 * i, (6 * r.randrange(3)).to_bytes(2, 'little'))
        e.w32(t + 0xf4, offs)
        names = e.alloc(0x40, 2)
        for i in range(3):
            e.wbytes(names + 6 * i, r.choice([0, 0, 2, 3]).to_bytes(2, 'little') + bytes(r.getrandbits(8) for _ in range(4)))
        e.w32(t + 0xfc, names)
        d4 = e.alloc(0x20, 4)
        for i in range(4):
            e.w32(d4 + 4 * i, r.getrandbits(32))
        e.w32(t + 0xe4, d4)
        return t
    parent = mktab(0) if r.random() < 0.6 else 0
    head = mktab(parent) if r.random() < 0.9 else 0
    key = r.choice(keys_all) if keys_all and r.random() < 0.85 else r.randrange(0x80, 0x200)
    out = rnd(c, 0x40)
    me = rnd(c, 0x20)
    return [me, r.getrandbits(32), key, out, head, r.getrandbits(32)]


S(0x600280, 'GUESS look up key in table chain', 'thiscall', None, ret='al', gen=_g600280, note='batch37048')
