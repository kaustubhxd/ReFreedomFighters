"""specs_s269.py - unclaimed area 67, GUESS name for 0x439320. When flag != 0, calls ext 0x439380.
Otherwise uses slots 0x14/0x30 on the object at p+0x11 via a table walk with ext 0x439570.
Now sets up the globals that 0x439380 expects (record table, pair table, engine)."""
from pilot import S
from specs_s293 import _rnd
import pe_emu

TBL, PAIRS, ENG, FREE = 0x6e48c0, 0x6e4928, 0x70039c, 0x634273


def _nostk(v):
    return 'stk' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP else v


LOOKUP_HOOK = 0x439570


def _lookup_stub(e, r):
    x = e.arg32(0)
    e.calllog.append(('lookup439570', x))
    e.ret(eax=(x & 0xff), argbytes=4)


def _case(c):
    e, R = c.emu, c.rng
    e.hook(FREE, lambda em, r: (em.calllog.append(('free', em.arg32(0), em.arg32(1))), em.ret())[-1])
    e.hook(LOOKUP_HOOK, _lookup_stub)

    p = _rnd(c, 0x100)
    if c.rng.random() < 0.8:
        c.emu.w32(p, 0)
    else:
        c.emu.w32(p, 1)

    # Set up globals for 0x439380 (batch 294): record table, pair table, engine, owner handle
    nrec = R.randint(1, 4)
    special = R.randrange(nrec)
    recs, total = [], 0
    for k in range(nrec):
        cnt = R.choice([1, 2, 3, 5, 8])
        base = 0x6e41d0 if k == special else _rnd(c, 12 * cnt)
        recs.append((base, cnt))
        e.w32(TBL + 16 * k, base)
        e.w32(TBL + 16 * k + 4, cnt)
        e.w32(TBL + 16 * k + 8, R.getrandbits(32))
        e.w32(TBL + 16 * k + 12, R.getrandbits(32))
        total += cnt
    e.w32(TBL + 16 * nrec, 0)

    # entries in the 0x6e41d0 record: {x, id, value}
    keys = [R.choice([0xb8, 0x10, 0x22, R.getrandbits(32)]) for _ in range(3)]
    b, cnt = recs[special]
    for j in range(cnt):
        e.w32(b + 12 * j, R.getrandbits(32))
        e.w32(b + 12 * j + 4, R.choice(keys + [0xb8, R.getrandbits(16)]))
        e.w32(b + 12 * j + 8, R.getrandbits(32))

    # pair table {val, key}, val 0 ends it
    npair = R.randint(0, 3)
    for k in range(npair):
        e.w32(PAIRS + 8 * k, R.choice([0xb8, 0x77, R.getrandbits(32) | 1]))
        e.w32(PAIRS + 8 * k + 4, R.choice(keys))
    e.w32(PAIRS + 8 * npair, 0)

    # owner handle at p+0xc (p is the argument that points to the object containing p+0xc and p+0x11)
    # For batch 269, p is the main object being tested, so we set up p+0xc as a tag handle
    owner = _rnd(c, 0x40)
    h = _rnd(c, 0x20)
    if R.random() < 0.5:
        e.w32(h, 3)
        h = owner + 4
        e.w32(h, 3)
    else:
        e.w32(h, 1)
        e.w32(h + 8, owner + 4)
    e.w32(p + 0xc, h)
    X = _rnd(c, 0x1400)
    L = _rnd(c, 10 * total + 16)
    e.w32(X + 0x1344, L)
    e.w32(owner + 0x11, X)
    e.w32(p + 4, R.choice([0, 0, 1]))
    for i in range(total):
        nodes = []
        for _ in range(R.choice([0, 0, 1, 2, 3])):
            n = _rnd(c, 12)
            r = R.random()
            if r < 0.4:
                e.w32(n, p + 4)                    # names p (matches when [p+4] == 0)
            else:
                it = _rnd(c, 8)
                e.w32(it, R.choice([0, 0, 2]))
                e.w32(n, it)
            e.w8(n + 4, R.choice([0, 1]))
            nodes.append(n)
        for k, n in enumerate(nodes):
            e.wbytes(n + 5, (nodes[k + 1] if k + 1 < len(nodes) else 0).to_bytes(4, 'little'))
        e.wbytes(L + 10 * i + 4, (nodes[0] if nodes else 0).to_bytes(4, 'little'))

    # engine: byte flag at +0x6e, slot 0xdc(out, id) fills the MYSTR at out and returns it
    g = _rnd(c, 0x100)
    e.w8(g + 0x6e, R.choice([0, 1]))

    def dc(em, r):
        out, ident = em.arg32(0), em.arg32(1)
        em.calllog.append(('eng', 0xdc, _nostk(em.reg('ecx')), _nostk(out), ident))
        s = _rnd(c, 0x20)
        em.w32(out, s)
        em.ret(eax=out, argbytes=8)
    e.w32(g, e.fake_vtable('eng', 0x100, {0xdc: dc}))
    e.w32(ENG, g)

    # selector object at p+0x11 (for the non-flag path): slots 0x14 and 0x30
    if c.rng.random() < 0.8:
        r0 = c.rng.choice([0, 3, 0x10, c.rng.getrandbits(32)])
        vt = c.emu.logging_vtable('Sel', 0x140, impl={0x14: lambda e, a: (r0, None),
                                                    0x30: lambda e, a: (c.rng.getrandbits(32), None)},
                                  argwords={0x30: 1})
        m = _rnd(c, 0x40)
        c.emu.w32(m, vt)
        c.emu.w32(p + 0x11, m)
    else:
        c.emu.w32(p + 0x11, 0)

    c.emu.mu.ctl_flush_tb()
    return [p, c.rng.choice([0, 1, 5, 0x10, c.rng.getrandbits(32)]), c.rng.choice([0, 1, 0x100])]


S(0x439320, 'GUESS guessSlotPick (0x439320)', 'stdcall', None, ret='eax', gen=_case,
  note='batch269; now sets up globals for flag path (0x439380/batch294); non-flag path uses slots 0x14/0x30 and ext 0x439570')
