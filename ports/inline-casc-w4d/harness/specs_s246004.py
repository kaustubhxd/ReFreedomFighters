"""specs_s246004.py - w4d batch 246004: 0x53aae0."""
import pe_emu
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g53aae0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    em = c.emu
    st = lambda emu: emu.r32(emu.r32(pe_emu.TEB) + 8)
    sr = [seh_record(c, 2) for _ in range(8)]

    def log(emu, k, tag, j, *extra):
        emu.calllog.append((tag, st(emu)) + extra)
        sr[j](emu, k)

    THIS = rnd(c, 0x40)
    OBJ = rnd(c, 0x20)
    OVT = rnd(c, 0x100)
    em.w32(OBJ, OVT)
    em.w32(OVT + 0x70, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, stackmark=(0,),
                              side=lambda emu, k: log(emu, k, 'o70', 0, emu.reg('ecx') - OBJ)))
    # registry
    G = rnd(c, 0x100)
    em.w32(0x70039c, G)
    REG = rnd(c, 0x10)
    RVT = rnd(c, 0x100)
    em.w32(REG, RVT)
    em.w32(G + 0x9b, REG)
    nkeys = r.choice([0, 1, 2, 3, 4])
    keys = [r.getrandbits(32) for _ in range(nkeys)]
    # resolved objects
    objs = []
    for _ in range(3):
        o = rnd(c, 0x10)
        vt = rnd(c, 0x200)
        em.w32(o, vt)

        def s1e0(emu, k, o=o):
            log(emu, k, 'x1e0', 1, emu.reg('ecx') - o, emu.arg32(0))
        em.w32(vt + 0x1e0, pystub(c, 1, ret=r.choice([0, 1, 0x100, 0x101, 0xffffff00, 0x55, 0x10, 0x1f0]), pop=4, this=True, side=s1e0))
        objs.append(o)
    mapping = {}
    for kk in keys:
        mapping[kk] = r.choice([0] + objs + objs)

    def s58(emu, k):
        kk = emu.arg32(0)
        log(emu, k, 'r58', 2, emu.reg('ecx') - REG, kk)
        return mapping.get(kk, 0)
    em.w32(RVT + 0x58, pystub(c, 1, ret=s58, pop=4, this=True))
    # list this[4]
    LST = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LST, LVT)
    em.w32(THIS + 4, LST)
    items = []
    for _ in range(r.choice([0, 1, 2, 3])):
        e = rnd(c, 0x10)
        em.w32(e + 4, r.choice(objs + [r.getrandbits(32)]))
        items.append(e)
    pos = [0]

    def s4c(emu, k):
        pos[0] = 0
        log(emu, k, 'l4c', 3, emu.reg('ecx') - LST)

    def s64(emu, k):
        i = pos[0]
        pos[0] += 1
        log(emu, k, 'l64', 3, i)
        return items[i] if i < len(items) else 0
    em.w32(LVT + 0x4c, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s4c))
    em.w32(LVT + 0x64, pystub(c, 1, ret=s64, pop=4, this=True, stackmark=(0,)))
    blocks = []

    def s4(emu, k):
        b = rnd(c, 0x30)
        blocks.append(b)
        log(emu, k, 'l4', 4, emu.reg('ecx') - LST, emu.arg32(0))
        return b + 4
    em.w32(LVT + 4, pystub(c, 1, ret=s4, pop=4, this=True))
    # existing chain at this+0xe (unaligned)
    chain = []
    for _ in range(r.choice([0, 0, 1, 2, 3])):
        nd = rnd(c, 0x20)
        em.w32(nd + 0xc, 0)
        if chain:
            em.w32(chain[-1] + 0xc, nd)
        chain.append(nd)
    em.w32(THIS + 0xe, chain[0] if chain else 0)
    # iterator vtable installed by the ctor hook
    IVT = rnd(c, 0x100)
    ipos = [0]

    def i4c(emu, k):
        ipos[0] = 0
        log(emu, k, 'i4c', 5)

    def i5c(emu, k):
        i = ipos[0]
        ipos[0] += 1
        if i < len(keys):
            emu.w32(emu.arg32(0), 1)
            log(emu, k, 'i5c', 5, i)
            return keys[i]
        emu.w32(emu.arg32(0), 0)
        log(emu, k, 'i5c', 5, -1)
        return r.getrandbits(32)
    em.w32(IVT + 0x4c, pystub(c, 1, ret=0, pop=4, this='mark', stackmark=(0,), side=i4c))
    em.w32(IVT + 0x5c, pystub(c, 1, ret=i5c, pop=4, this='mark', stackmark=(0,)))

    def ctor(emu, k):
        emu.w32(emu.reg('ecx'), IVT)
        log(emu, k, 'ictor', 6)
    hook_rec(c, 0x4ccba0, 0, ret=lambda emu, k: 0, pop=0, this='mark', side=ctor)
    hook_rec(c, 0x4ccf60, 0, ret=lambda emu, k: 0, pop=0, this='mark', side=lambda emu, k: log(emu, k, 'idtor', 7))
    return [THIS, OBJ]


S(0x53aae0, 'GUESS FUN_53aae0', 'thiscall', None, ret='al', gen=g53aae0, note='batch246004')
