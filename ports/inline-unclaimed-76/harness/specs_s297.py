"""specs_s297.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x4e6dc0. Exe helpers 0x45e420, 0x48db70 and the
allocator 0x41e290 are GUESS call-recording stubs (the allocator fills with 0xA5). The embedded object at this+0xc has a
logged slot 4 (argument: the record)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _rec(c):
    e = c.emu
    ret_o = _rnd(c, 0x40)
    e.w32(ret_o + 4, c.rng.choice([0x40000000, 0x80000000, 0xc0000000, 0, 0x20000000]) | c.rng.getrandbits(16))
    e.w32(ret_o + 8, c.rng.randrange(0, 0x40))
    give = c.rng.random() < 0.8
    cnt = c.rng.randrange(1, 6)

    def h45e(em, r):
        em.calllog.append(('h45e420', 0x45e420, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=ret_o if give else 0, argbytes=4)

    def h48d(em, r):
        em.calllog.append(('h48db70', 0x48db70, em.reg('ecx'), ()))
        em.ret(eax=cnt, argbytes=0)

    def h41e(em, r):
        n = max(em.arg32(0), 1)
        p = em.alloc(n, 4)
        em.wbytes(p, b'\xa5' * n)
        em.ret(eax=p, argbytes=0)

    e.hook(0x45e420, h45e)
    e.hook(0x48db70, h48d)
    e.hook(0x41e290, h41e)
    emb_vt = e.logging_vtable('emb4e6', 0x5, impl={}, argwords={4: 1})
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0xc, emb_vt)
    x = c.rng.getrandbits(32)
    y = c.rng.choice([0x100001, 0x100002, 0x100003, 0x100000, c.rng.getrandbits(32)])
    return [self_, x, y]


S(0x4e6dc0, 'pushRec (GUESS)', 'thiscall', None, ret=None, gen=_rec, note='batch297; ret 8; exe helpers stubbed')
