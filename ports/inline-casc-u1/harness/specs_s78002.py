"""Spec for batch 78002: 0x50f850 object transform wrapper."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub, hook_rec, sysobj

def _g50f850(c):
    clear_hooks(c)
    em, r = c.emu, c.rng
    hook_rec(c, 0x7003b0, 0, pop=0, ret=lambda e, k: e.reg('eax'))

    def fill(emu, k):
        p0, p1 = emu.arg32(0), emu.arg32(1)
        for j in range(0, 0x24, 4):
            emu.w32(p0 + j, (0x31415927 + j * 0x10203) & 0xffffffff)
        for j in range(0, 0x0c, 4):
            emu.w32(p1 + j, (0x3f000000 + j * 0x10101) & 0xffffffff)

    shared = rnd(c, 0x100)
    vt = em.alloc(0x90, 4)
    em.w32(shared, vt)
    em.w32(vt + 0x80, pystub(c, 2, this=True, side=fill, stackmark=(0,1)))
    em.w32(vt + 0x74, pystub(c, 2, this=True, stackmark=(0,1)))
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=shared, this=True)})

    data = em.alloc(3 * 8, 4)
    for i in range(3):
        em.w32(data + 8*i, 0x10 + i)
        em.w32(data + 8*i + 4, 0)
    vec = rnd(c, 0x20)
    em.w32(vec, data)
    em.w32(vec + 8, 3)
    store = rnd(c, 0x20)
    em.w32(store, vec)
    em.w32(store + 4, 0)
    em.w32(store + 8, 3)
    selfp = rnd(c, 0x20)
    em.w32(selfp + 4, store)
    return [selfp]

S(0x50f850, 'GUESS transform selected object', 'stdcall', None, ret=None, gen=_g50f850)
