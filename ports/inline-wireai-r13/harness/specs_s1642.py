"""specs_s1642.py - residue 13 batch 1642: ZActorIf::SetVisLightMultiplier. The render manager (sys+0x9b) slots +0x4c,
+0x114 and +0x58 and the actor's +0x130 are recorders. The register call's out pointer is a stack address, so it is
not recorded; the spec's view is the 1603 OpaqueCallParameters stand-in."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks


def view(c, nslots):
    """AppendStack-like view {stack*, base, count} over a stack {data*, ?, size}, slot 0 value at data+8*base."""
    r = c.rng
    base = r.randint(0, 3)
    size = base + nslots + r.randint(0, 2)
    data = rnd(c, 8 * size)
    st = rnd(c, 0x10)
    c.emu.w32(st, data)
    c.emu.w32(st + 8, size)
    v = rnd(c, 0x10)
    c.emu.w32(v, st)
    c.emu.w32(v + 4, base)
    c.emu.w32(v + 8, nslots)
    c.emu.wf32(data + 8 * base, r.uniform(-300, 300))
    return v, data + 8 * base


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    db = obj(c, 0x1000, {0x4c: stub(c, seq, 1, ret=r.getrandbits(32)),
                         0x114: stub(c, seq, 5, ret=r.getrandbits(32), skip=(4,)),
                         0x58: stub(c, seq, 2, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    e = obj(c, 0x1000, {0x130: stub(c, seq, 1)})
    c.emu.w32(e + 0x73a, r.getrandbits(32))
    self_ = rnd(c, 0x40)
    c.emu.w32(self_ + 0x18, e)
    v, a0 = view(c, 1)
    params = rnd(c, 0x20)
    c.emu.w32(params + 4, v)
    return [self_, params]


S(0x508410, 'ZActorIf::SetVisLightMultiplier', 'thiscall', None, ret=None, gen=_gen, note='batch1642')
