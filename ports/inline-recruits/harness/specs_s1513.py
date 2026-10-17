"""specs_s1513.py - recruits thread batch 1513: CFormationControl ctor, InitWrapper, AddToFormationRef.
operator new (0x41e290) is a recorder returning blocks from a pre-allocated pool (sometimes null); REFTAB's
constructor, mreset run as exe code; CRT memset is a Python stand-in; the base constructor, the group lookup
(0x5b6ab0), IsDerivedFrom, MYSTR helpers, name table, object manager and log are recorders. The SEH prologues need
the fake TEB (teb=True)."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj, reftab, logger, stub_memset


def _pool(c, n, null=0.1):
    r = c.rng
    blocks = [0 if r.random() < null else rnd(c, 0x1c) for _ in range(n)]
    hook_rec(c, 0x41e290, 1, ret=lambda em, k: blocks[min(k, n - 1)], pop=0)


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x469870, 0, ret=0, this=True)
    sysobj(c, table_slots={0x114: pystub(c, 4, ret=lambda em, k: r.getrandbits(32))})
    return [rnd(c, 0x60)]


def _initw(c):
    clear_hooks(c)
    r = c.rng
    _pool(c, 2)
    names = obj(c, 0x80, {0x60: pystub(c, 3)})
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=names), 0x4c: pystub(c, 1, ret=r.getrandbits(32))})
    base = rnd(c, 0x70)
    s = base + 0x10
    om = obj(c, 0x20, {0x20: pystub(c, 1, ret=r.choice([0, 0, 1])), 0xac: pystub(c, 1)})
    k = r.random()
    if k < 0.4:
        c.emu.w32(om + 8, pystub(c, 0, ret=r.getrandbits(32), this=True))
        c.emu.w32(om + 0xc, s - r.choice([0, 0x10, -4]))
        c.emu.w32(om + 0x10, s + r.choice([0x10, 0, 4]))
    else:
        c.emu.w32(om + 8, 0)
    c.emu.w32(s - 4, r.choice([0, r.getrandbits(32)]))
    c.emu.w32(0x70038c, om)
    return [s]


def _add(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memset(c)
    logger(c, 4, slot=0x30)
    # no null from operator new here: a null member table is then called through, which with the fake TEB at page 0
    # reads the SEH chain (the port has no SEH frame), and in the game would crash anyway
    _pool(c, 3, null=0.0)
    strp = e.alloc(8, 4)
    hook_rec(c, 0x4cc1d0, 0, ret=strp, this=True)
    hook_rec(c, 0x4cbec0, 0, this='mark')
    # group with children for the no-key path
    kids = [rnd(c, 0x60) for _ in range(r.randint(0, 3))]
    rec = {k: r.random() < 0.7 for k in kids}
    for k in kids:
        e.w32(k + 0x54, obj(c, 0x20, {0x128: pystub(c, 3, deref={1: 1})}) if r.random() < 0.8 else 0)
    hook_rec(c, 0x4db9a0, 1, ret=lambda em, kk: 1 if rec.get(em.reg('ecx')) else 0, this=True)
    nxt = {kids[i]: (kids[i + 1] if i + 1 < len(kids) else 0) for i in range(len(kids))}

    def adv(em, kk):
        p = em.arg32(0)
        em.w32(p, nxt.get(em.r32(p), 0))
    grp = obj(c, 0x20, {0x50: pystub(c, 1, nullflag=(0,), side=adv)})
    e.w32(grp + 8, kids[0] if kids else 0)
    mys = rnd(c, 0x10)
    a = obj(c, 0x200, {0x20: pystub(c, 0, ret=grp), 0x1d8: pystub(c, 2, ret=mys, stackmark=(0,))})
    o = obj(c, 0x40, {0x20: pystub(c, 0, ret=a)})

    def mp(em, k):
        for i in range(9):
            em.wf32(em.arg32(0) + 4 * i, float(i))
        for i in range(3):
            em.wf32(em.arg32(1) + 4 * i, 10.0 * (i + 1))
    L = obj(c, 0x40, {0x80: pystub(c, 2, side=mp)})
    key = r.getrandbits(32) | 1
    look = {key: L}
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: look.get(em.arg32(0), o))})
    hook_rec(c, 0x5b6ab0, 1, ret=r.choice([0, 0, key]), this=True)
    # formation table: existing formation for the key or not; add returns a fresh formation block
    ent = rnd(c, 0xa0)
    members = obj(c, 0x20, {4: pystub(c, 1, ret=rnd(c, 0x14))})
    e.w32(ent + 4, members)
    for i in range(12):
        e.w32(ent + 4 + 8 + 4 * i, r.choice([0, 0, 1]))
    newf = rnd(c, 0xa0)
    found = {key: ent} if r.random() < 0.5 else {}

    def fnd(em, rr):
        em.ret(found.get(em.arg32(0), 0), 4)
    ft = obj(c, 0x20, {0x2c: e.stub_fn('formation find', fnd), 4: pystub(c, 1, ret=newf)})
    s = rnd(c, 0x60)
    e.w32(s + 0x48, ft)
    p = rnd(c, 12)
    e.w32(p, r.choice([0, key, key]))
    e.w32(p + 4, r.getrandbits(32))
    e.w32(p + 8, r.choice([0, -1, r.randint(1, 12), r.randint(1, 12), 13]) & 0xffffffff)
    # REFTAB's constructor is a recorder that returns fake tables (with a recording 'add'), so a new formation's
    # member add does not run the real REFTAB code on half-initialised memory
    fakes = [obj(c, 0x20, {4: pystub(c, 1, ret=rnd(c, 0x14))}) for _ in range(2)]
    hook_rec(c, 0x4ccbe0, 2, ret=lambda em, k: fakes[min(k, 1)], this=True)
    return [s, p]


S(0x5b5930, 'CFormationControl::CFormationControl', 'thiscall', ret='eax', gen=_ctor, note='batch1513', teb=True)
S(0x5b6d00, 'CFormationControl::InitWrapper', 'thiscall', gen=_initw, note='batch1513', teb=True)
S(0x5b59e0, 'CFormationControl::AddToFormationRef', 'thiscall', ret='eax', gen=_add, note='batch1513', teb=True)
