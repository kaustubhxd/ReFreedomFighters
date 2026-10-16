"""specs_s386.py - area 76, residue 17, batch 386 (thiscall; GUESS), see batch386.cpp.
0x663610: this is a block whose +0x1218c sub-object has slots 0xc (no words) and 0x14 (no words, returns 0 or a per-run value), both logged;
[0x700394] -> an object whose slot 0x134 (four words) is logged; [0x70039c] -> block, [+0x9b] (unaligned) -> block, [+0xae4] -> an object
whose slot 0 (no words, returns a per-run value) is logged. The argument is a block that may receive 0xf."""
from pilot import S


def _gen_663(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)
    rc = rng.getrandbits(32)
    rg = rng.getrandbits(32)
    r14 = 0 if rng.random() < 0.5 else rng.getrandbits(32)

    def h0c(em, r):
        em.calllog.append(('sub', 0xc, em.reg('ecx'), ()))
        em.ret(eax=rc)

    def h14(em, r):
        em.calllog.append(('sub', 0x14, em.reg('ecx'), ()))
        em.ret(eax=r14)

    def hq0(em, r):
        em.calllog.append(('q', 0, em.reg('ecx'), ()))
        em.ret(eax=rv)

    def hg(em, r):
        em.calllog.append(('g', 0x134, em.reg('ecx'), tuple(em.arg32(i) for i in range(4))))
        em.ret(eax=rg, argbytes=16)

    this = e.alloc(0x12200, 4)
    e.wbytes(this + 0x12180, rng.randbytes(0x40))
    e.w32(this + 0x1218c, e.fake_vtable('sub663', 0x10, {0xc: h0c, 0x14: h14}))
    g = e.alloc(0x40, 4)
    e.w32(g, e.fake_vtable('g663', 0x50, {0x134: hg}))
    e.w32(0x700394, g)
    q = e.alloc(0x40, 4)
    e.w32(q, e.fake_vtable('q663', 0x4, {0: hq0}))
    p = e.alloc(0xb00, 4)
    e.w32(p + 0xae4, q)
    b = e.alloc(0x100, 4)
    e.w32(b + 0x9b, p)
    e.w32(0x70039c, b)
    arg = e.alloc(0x40, 4)
    e.wbytes(arg, rng.randbytes(0x40))
    return [this, arg]


S(0x663610, 'check663610 (GUESS)', 'thiscall', None, ret='al', gen=_gen_663, note='area 76 batch 386; residue 17')
