"""specs_s1516.py - recruits thread batch 1516: ZFollowShape Init and Save.
DBREAD reads (0x4e5e60 unsigned, 0x4e5e80 float) are recorder hooks returning fixed values in order (the file
stream). The owner geom (slots 0x80, 0x7c: position/matrix setters), the physics object (system table +0xadc,
slot 0x28c) and the saver's slots are recorders."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj


def _init(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    uvals = [r.getrandbits(32) for _ in range(6)]
    # reads: 0x54, 0x58, 0x59, 0x5e (tested against 1 for the shape flag), 0x62
    uvals[3] = r.choice([0, 1, 1, 2])
    fvals = [r.uniform(-10, 300), r.uniform(-10, 300)]
    hook_rec(c, 0x4e5e60, 0, ret=lambda em, k: uvals[min(k, 5)])
    hook_rec(c, 0x4e5e80, 0, st0=lambda em, k: fvals[min(k, 1)])
    owner_geom = rnd(c, 0x20)
    mvals = [r.uniform(-1, 1) for _ in range(12)]

    def fill_mat(em, k):   # the owner's getter fills the matrix (12 floats) and the position (3)
        for i, v in enumerate(mvals):
            em.wf32(em.arg32(0) + 4 * i, v)
        for i in range(3):
            em.wf32(em.arg32(1) + 4 * i, mvals[i])
    owner = obj(c, 0x80, {0x80: pystub(c, 2, nullflag=(0, 1), side=fill_mat),
                          0x7c: pystub(c, 2, deref={0: 12, 1: 3})})
    e.w32(owner + 8, owner_geom)
    f = rnd(c, 0x80)
    e.w32(f + 0x44, owner)
    so = sysobj(c, table_slots={}, table_size=0xae0)
    phys = obj(c, 0x20, {0x28c: pystub(c, 3, this=True)})
    e.w32(e.r32(so + 0x9b) + 0xadc, phys)
    e.w32(so + 0x40, r.getrandbits(32))
    e.w32(f + 0x4c, r.getrandbits(32))
    return [f, rnd(c, 0x20), rnd(c, 0x10)]


def _save(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f = rnd(c, 0x80)
    e.w32(f + 0x5a, r.getrandbits(32))
    e.w8(f + 0x66, r.randint(0, 1))
    e.w32(f + 0x67, r.getrandbits(32))
    e.w32(f + 0x4c, r.getrandbits(32))
    sg = obj(c, 0x80, {0x44: pystub(c, 1), 0x60: pystub(c, 1), 0x54: pystub(c, 1)})
    return [f, sg]


S(0x4c5d00, 'ZFollowShape::Init', 'thiscall', gen=_init, note='batch1516', teb=True)
S(0x4c5cb0, 'ZFollowShape::Save', 'thiscall', ret='al', gen=_save, note='batch1516')
