"""specs_s66064.py - cascade s4 batch 66064: 0x51f600 (find the matching child, seed a region, apply two transforms)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, logger


def _g51f600(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    hook_rec(c, 0x5175a0, 0, this=True)
    n = r.choice([0, 1, 2, 3])
    kids = [e.alloc(0x70, 8) for _ in range(n)]
    for i, k in enumerate(kids):
        e.w32(k + 0x60, kids[i + 1] if i + 1 < n else 0)
    names = {k: rnd(c, 8) for k in kids}
    seq = [r.choice([0, 1, 5]) for _ in range(4)]
    st = {'i': 0}

    def nm(em, rr):
        em.calllog.append(('name', em.reg('ecx')))
        em.ret(eax=names[em.reg('ecx')], argbytes=0)

    def mt(em, rr):
        em.calllog.append(('match', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=seq[min(st['i'], 3)], argbytes=0)
        st['i'] += 1
    e.hook(0x4dc110, nm)
    e.hook(0x4cc850, mt)
    hook_rec(c, 0x4db670, 1, this=True)

    def d4(em, rr):                       # 0x4ddfa0 fastcall (ecx = dst, edx = src) plain ret
        d = em.reg('ecx')
        em.calllog.append(('h4ddfa0', em.reg('edx')))
        em.w32(d, em.r32(d) ^ 0x55)
        em.ret(eax=0, argbytes=0)
    e.hook(0x4ddfa0, d4)
    emb_vt = obj(c, 0x20, {4: pystub(c, 2, this=True)})
    t = e.alloc(0x1700, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x100)))
    e.w32(t + 4, r.choice([0, rnd(c, 8)]))
    e.w32(t + 0x50, kids[0] if kids else 0)
    for off in (0x6c, 0x70, 0x74):
        e.w32(t + off, r.getrandbits(32))
    for off in (0x1660, 0x1664, 0x1668):
        e.w32(t + off, r.getrandbits(32))
    e.w32(t + 0x1684, int.from_bytes(bytes(e.rbytes(emb_vt, 4)), 'little'))
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x8c, pystub(c, 1, this=True))
    e.w32(vt + 0x90, pystub(c, 1, this=True))
    e.w32(t, vt)
    return [t]


S(0x51f600, 'GUESS find the matching child and apply two transforms', 'thiscall', None, ret=None, gen=_g51f600, note='batch66064')
