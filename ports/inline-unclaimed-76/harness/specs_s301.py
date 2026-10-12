"""specs_s301.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x502030. Exe helper 0x5003d0 runs as original code
(a table, as in batch195). Stubs: the logger (0x700390, slot 0x20 returns a report object), the report (slot 0x2c, cdecl, logged),
the dispatch callback (0x7003b0, a code stub, always set: the exe asserts when it is null), the engine's slot 0x114 and the
object's slot 0x134 (logged), and the object at +0x34 (slot 0x34 returns a value)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _disp(c):
    e = c.emu
    rep_vt = e.fake_vtable('rep502', 0x2c // 4 + 1, {0x2c: lambda em, r: _rep(em)})
    rep = _rnd(c, 0x40)
    e.w32(rep, rep_vt)

    def lg_get(em, r):
        em.calllog.append(('lg502', 0x20, (em.arg32(0), em.arg32(1))))
        em.ret(eax=rep, argbytes=8)

    lg_vt = e.fake_vtable('lg502', 0x20 // 4 + 1, {0x20: lg_get})
    lg = _rnd(c, 0x40)
    e.w32(lg, lg_vt)
    e.w32(0x700390, lg)

    def cbh(em, r):
        em.calllog.append(('cb502', 0x7003b0, ()))
        em.ret(eax=0, argbytes=0)
    cb = e._new_stub('cb502', cbh)
    e.w32(0x7003b0, cb)

    ret114 = c.rng.getrandbits(16)
    eng_vt = e.logging_vtable('eng502', 0x47, impl={0x114: lambda em, a: (ret114, None)}, argwords={0x114: 4})
    eng9b = _rnd(c, 0x40)
    e.w32(eng9b, eng_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, eng9b)
    e.w32(0x70039c, eng)

    vals34 = c.rng.getrandbits(32)
    o34_vt = e.logging_vtable('o34_502', 0x0e, impl={0x34: lambda em, a: (vals34, None)}, argwords={0x34: 0})
    o34 = _rnd(c, 0x40)
    e.w32(o34, o34_vt)

    obj134_vt = e.logging_vtable('obj134', 0x4e, impl={}, argwords={0x134: 3})
    obj134 = _rnd(c, 0x40)
    e.w32(obj134, obj134_vt)

    # the table (as in batch195): [T] = inner, [T+4] = base, [T+8] = count; inner[0] = data pointer, inner[+8] = size
    data = _rnd(c, 0x1000)
    inner = _rnd(c, 0x200)
    e.w32(inner, data)
    e.w32(inner + 8, 0x100)
    table = _rnd(c, 0x40)
    e.w32(table, inner)
    base = c.rng.randrange(0, 0x40)
    e.w32(table + 4, base)
    e.w32(table + 8, 0x10)
    for k in range(3):
        ent = data + 8 * (base + k)
        e.w8(ent + 4, c.rng.choice([3, 4, 2, 5]))
        ptr = o34 if c.rng.random() < 0.5 else c.rng.getrandbits(32)
        e.w32(ent, o34 if (k == 1 and e.r8(ent + 4) == 4) else c.rng.getrandbits(32))
    arg = _rnd(c, 0x40)
    e.w32(arg + 4, table)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0xc, obj134)
    return [self_, arg]


def _rep(em):
    args = tuple(em.arg32(k) for k in range(3))
    em.calllog.append(('rep502', 0x2c, args))
    em.ret(eax=0, argbytes=0)


S(0x502030, 'dispatch (GUESS)', 'thiscall', None, ret=None, gen=_disp, note='batch301; ret 4; exe 0x5003d0; cb always set')
