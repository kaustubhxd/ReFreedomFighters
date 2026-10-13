"""specs_s1644.py - residue 13 batch 1644: CRagdoll2::GetLinkMatPos_global. The object's vtable +0x2cc returns a base
buffer and +0x98 is a recorder; the link table (+0x2e) is a random buffer. The mcpy 0x4de420 is exe code."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    base = rnd(c, 0x200)
    ragd = rnd(c, 0x100)
    o = obj(c, 0x80, {0x2cc: stub(c, seq, 0, ret=base), 0x98: stub(c, seq, 2)})
    c.emu.w32(ragd + 0x36, o)
    c.emu.w32(ragd + 0x2e, rnd(c, 0x200))
    idx = r.choice([0, 1, 2, 3, r.randint(0, 3)])
    p1 = rnd(c, 0x40)
    p2 = rnd(c, 0x20)
    p3 = rnd(c, 0x20) if r.random() < 0.7 else 0
    p4 = rnd(c, 0x20) if r.random() < 0.7 else 0
    return [ragd, idx, p1, p2, p3, p4]


S(0x641d90, 'CRagdoll2::GetLinkMatPos_global', 'thiscall', None, ret='al', gen=_gen, note='batch1644')
