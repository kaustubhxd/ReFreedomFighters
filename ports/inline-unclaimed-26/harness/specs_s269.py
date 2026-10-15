"""specs_s269.py - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list: 0x4afb50, message send through engine
slots 0x58 and 0x4c, the target's 0x1e0, 0x4c and 0x5c, and the object's 0x12c."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _send(c):
    e = c.emu
    # target t: slot 0x1e0 (returns the flag), t+0x18 -> child with slots 0x4c and 0x5c (out param = local)
    flag = c.rng.choice([0, 1])
    seq = [(c.rng.choice([0, 1]), c.rng.getrandbits(32)) for _ in range(c.rng.randrange(0, 4))] + [(0, c.rng.getrandbits(32))]
    k = [0]

    def write_local(em, a, v):
        em.w32(a[0], v)

    def out5c(em, a, seq=seq, k=k):
        lv, x = seq[min(k[0], len(seq) - 1)]
        k[0] += 1
        em.w32(a[0], lv)
        return (x, None)

    child_vt = e.logging_vtable('child4afb', 0x18, impl={0x4c: lambda em, a: (em.w32(a[0], 1) or 0, None),
                                                          0x5c: out5c}, argwords={0x4c: 1, 0x5c: 1})
    child = _rnd(c, 0x40)
    e.w32(child, child_vt)
    t_vt = e.logging_vtable('t4afb', 0x7a, impl={0x1e0: lambda em, a: (flag, None)}, argwords={0x1e0: 1})
    t = _rnd(c, 0x40)
    e.w32(t, t_vt)
    e.w32(t + 0x18, child)
    # the object at this+0x44 (p): slot 0x12c takes three arguments
    p_vt = e.logging_vtable('p4afb', 0x4c, impl={}, argwords={0x12c: 3})
    p = _rnd(c, 0x40)
    e.w32(p, p_vt)
    r4c = c.rng.getrandbits(32)
    o_vt = e.logging_vtable('eng4afb', 0x59, impl={0x58: lambda em, a: (t, None),
                                                    0x4c: lambda em, a: (r4c, None)},
                            argwords={0x58: 1, 0x4c: 1})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    self_ = _rnd(c, 0x80)
    e.w32(self_ + 0x4c, c.rng.getrandbits(32))
    e.w32(self_ + 0x44, p)
    e.w32(self_ + 0x48, c.rng.getrandbits(32))
    e.w8(self_ + 0x56, c.rng.choice([0, 1]))
    e.w8(self_ + 0x57, c.rng.choice([0, 1]))
    return [self_, c.rng.getrandbits(32)]


S(0x4afb50, 'sendMessage (GUESS)', 'thiscall', None, ret=None, gen=_send, note='batch269; residue-05 list; ret 4')
