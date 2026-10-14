"""specs_s1506.py - recruits thread batch 1506: ZGameOSD::CommandRecruit.
Recorders: camera helper aim/normal/scout-point calls (they write their output), SetRecruitMode, the actor's sound,
the level collision ray (records the COLI's start, direction and constructor fields; on a hit writes the hit point,
hit object id and a triangle), the event to the actor (records the event block by content; for the form order only
the first 5 dwords, the rest is stack garbage in the original). Exe code: the actor-mode getter, COLI::COLI, the
triangle normal (x87), the order-object setters 0x5b7ce0 / 0x5b7d30."""
import struct
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj

FORM_ID = 0x5555


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x2400)
    for off, v in ((0x1d31, 0x1111), (0x1d33, 0x2222), (0x1d35, 0x3333), (0x1d37, 0x4444), (0x1d39, FORM_ID)):
        e.w16(s + off, v)
    hero = obj(c, 0x40, {0x84: pystub(c, 1, nullflag=(0,),
                                      side=lambda em, k: [em.wf32(em.arg32(0) + 4 * i, v) for i, v in enumerate(hp)])})
    hp = [r.uniform(-100, 100) for _ in range(3)]
    e.w32(s + 0x1d0b, hero)
    cam = rnd(c, 0xd20)
    e.w8(cam + 0xb45, 1 if r.random() < 0.4 else 0)
    e.w32(s + 0x1d03, cam)
    aim = [r.uniform(-100, 100) for _ in range(6)]

    def put(vals):
        def f(em, k):
            p = em.arg32(0)
            for i, v in enumerate(vals):
                em.wf32(p + 4 * i, v)
        return f
    hook_rec(c, 0x5cfa00, 1, ret=r.choice([0, 1, 0x100, 1]), this=True, nullflag=(0,), side=put(aim[:3]))
    hook_rec(c, 0x5cf3e0, 1, this=True, nullflag=(0,), side=put(aim[3:]))
    hook_rec(c, 0x5cfae0, 1, this=True, nullflag=(0,), side=put([r.uniform(-100, 100) for _ in range(3)]))
    hook_rec(c, 0x5a2e20, 4, this=True)
    hook_rec(c, 0x5a1ac0, 3, this=True)

    # level collision ray
    hit = r.choice([0, 1, 0x100])
    tri = [r.uniform(-10, 10) for _ in range(9)]
    hp2 = [r.uniform(-100, 100) for _ in range(3)]
    hid = r.getrandbits(32)
    crec = e.alloc(4 * 10, 4)

    def ray(em, rr):
        cp = em.arg32(0)
        for i in range(6):
            em.w32(crec + 4 * i, em.r32(cp + 4 * i))
        em.w32(crec + 24, em.r32(cp + 0x34))
        em.w32(crec + 28, em.r32(cp + 0x44))
        em.w32(crec + 32, em.r8(cp + 0x6c) | (em.arg32(1) << 8))
        em.w32(crec + 36, em.r32(crec + 36) + 1)
        if hit & 0xff:
            for i in range(3):
                em.wf32(cp + 0x28 + 4 * i, hp2[i])
            em.w32(cp + 0x44, hid)
            for i in range(9):
                em.wf32(cp + 0x48 + 4 * i, tri[i])
        em.ret(hit, 0x18)
    coll = obj(c, 0x20, {0x2e0: e.stub_fn('coli ray', ray)})
    hitobj = obj(c, 0x20, {0x88: pystub(c, 1, deref={0: 3})})
    so = sysobj(c, table_slots={0x4c: pystub(c, 1, ret=r.getrandbits(32)), 0x58: pystub(c, 1, ret=hitobj)},
                rand=r.choice([0.25, 0.5, 0.75, r.random()]), table_size=0xae0)
    e.w32(e.r32(so + 0x9b) + 0xadc, coll)
    e.w32(so + 0x40, r.getrandbits(32))
    e.wf32(so + 0x9c7, r.choice([0.0, 0.0, 1.0, -0.0]))
    # active list
    lst = obj(c, 0x20, {0x2c: pystub(c, 1, ret=r.choice([0, 1])), 4: pystub(c, 1)})
    e.w32(s + 0x5c, lst)
    # the recruit's actor and candidate entry
    rec_ev = e.alloc(4 * 12, 4)

    def evrec(em, rr):
        p = em.arg32(1)
        n = 5 if em.arg32(0) == FORM_ID else (3 if em.arg32(0) == 0x4444 else 8)
        em.w32(rec_ev, em.arg32(0))
        em.w32(rec_ev + 4, 1 if p else 0)
        if p:
            for i in range(n):
                em.w32(rec_ev + 8 + 4 * i, em.r32(p + 4 * i))
        em.w32(rec_ev + 44, em.r32(rec_ev + 44) + 1)
        em.ret(0, 12)
    actor = obj(c, 0x800, {0x128: e.stub_fn('actor event', evrec)})
    e.w32(actor + 0x77f, 5 if r.random() < 0.1 else r.randint(0, 4))
    idv = r.getrandbits(32)
    m = r.randint(1, 4)
    tab = e.alloc(4 * m, 4)
    pos = r.randint(0, m - 1)
    for i in range(m):
        ent = rnd(c, 0x20)
        e.w32(ent, idv if i == pos else r.getrandbits(32))
        e.w32(ent + 4, actor)
        e.w32(ent + 0xc, rnd(c, 0x30))
        e.w32(ent + 0x14, rnd(c, 0x30))
        e.w32(tab + 4 * i, ent)
    e.w32(s + 0x1da2, tab)
    e.w32(s + 0x1da6, tab + 4 * m)
    cmd = r.choice([0, 0, 3, 3, 4, 5, 1, 2, 9])
    al = r.getrandbits(32)
    return [s, cmd, idv, al]


S(0x597050, 'ZGameOSD::CommandRecruit', 'thiscall', gen=_gen, note='batch1506')
