"""specs_s1012.py - unclaimed-07 batch 12 (slice 6): CActionController::Add (0x49f8a0).
The engine object at 0x70038c is a fake per case: slot +0x20 (already-known test) and +0xac (void) are logging stubs,
and +8/+0xc/+0x10 give the optional callback and its address range. The callback is a logged stub (ECX recorded).
Values come from one small pool, so the duplicate-search branches are hit. The action block has its header at a-4."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _add(c):
    e = c.emu
    pool = [c.rng.getrandbits(32) | 0x10 for _ in range(4)] + [0]
    pick = lambda: c.rng.choice(pool)

    def cb(em, r):
        em.calllog.append(('actcb', 0, em.reg('ecx'), ()))
        em.ret(eax=cb_ret)

    cb_ret = pick()
    fn = e.stub_fn('actcb', cb)

    g = _rnd(c, 0x100)
    e.w32(g, e.logging_vtable('engine', 0xb0 // 4 + 1,
                              impl={0x20: _const(c.rng.choice([0, 0, 1])), 0xac: _const(0)},
                              argwords={0x20: 1, 0xac: 1}))
    e.w32(g + 8, fn if c.rng.random() < 0.5 else 0)
    if c.rng.random() < 0.5:
        e.w32(g + 0xc, 0)
        e.w32(g + 0x10, 0xffffffff)
    else:
        e.w32(g + 0xc, 0xffffffff)
        e.w32(g + 0x10, 0)
    e.w32(0x70038c, g)

    block = _rnd(c, 0x40)
    e.w32(block, pick())
    a = block + 4
    if c.rng.random() < 0.3:
        # the upper bound is exactly a: the test is 'a < g+0x10', so a == bound must not take the callback
        e.w32(g + 8, fn)
        e.w32(g + 0xc, 0)
        e.w32(g + 0x10, a)

    self_o = _rnd(c, 0x900)
    e.w32(self_o + 0x88c, c.rng.randint(0, 5))
    for i in range(6):
        e.w32(self_o + 0x70 + 4 * i, pick())
    n = c.rng.randint(0, 3)
    e.w32(self_o + 0x48, n)
    for b in range(n):
        obj = _rnd(c, 0x900)
        e.w32(obj + 0x820, c.rng.randint(0, 3))
        for j in range(4):
            e.w32(obj + 4 + 4 * j, pick())
        e.w32(self_o + 0x5c + 4 * b, obj)
    return [self_o, a]


S(0x49f8a0, 'CActionController::Add (unknown) thiscall', 'thiscall', None, ret=None, gen=_add,
  note='unclaimed-07 batch 12; engine 0x70038c slot +0x20/+0xac, callback at g+8, list appends')
