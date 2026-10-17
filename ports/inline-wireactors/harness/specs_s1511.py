"""specs_s1511.py - recruits thread batch 1511: CFormationControl::CheckRegroup, formation key of a group (0x5b6ab0).
Members and leader are fake actors (IsKindOf answers per class id, dead flag, geom with the inactive bit 10);
REFTABs are recruits_util.reftab fakes; CRT memset is a Python stand-in; IsDerivedFrom is a recorder."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj, reftab, logger, stub_memset
from unicorn.x86_const import UC_X86_REG_EDX


def _actor(c):
    r = c.rng
    actor = r.random() < 0.85
    cls2 = r.random() < 0.3

    def kind(em, k):
        a = em.arg32(0)
        return 1 if (a == 0x200074 and actor) or (a == 0x2003e8 and cls2) else 0
    info = rnd(c, 0x40)
    c.emu.w32(info + 0x3c, r.getrandbits(32) & ~0x400 if r.random() < 0.8 else 0x400)
    geo = rnd(c, 0x10)
    c.emu.w32(geo + 8, info)
    return obj(c, 0x40, {0x1e0: pystub(c, 1, ret=kind), 0x438: pystub(c, 0, ret=r.choice([0, 0, 0, 1])),
                         0x20: pystub(c, 0, ret=geo), 0x128: pystub(c, 3, deref={1: 1})})


def _check(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memset(c)
    logger(c, 2, slot=0x30)
    stamp = r.getrandbits(64)

    def setedx(em, k):
        em.mu.reg_write(UC_X86_REG_EDX, (stamp >> 32) + k)
    objs = {}

    def look(em, rr):
        em.ret(objs.get(em.arg32(0), 0), 4)
    so = sysobj(c, slots={0x1c8: pystub(c, 2, ret=stamp & 0xffffffff, side=setedx),
                          0x178: pystub(c, 3), 0x17c: pystub(c, 3)},
                table_slots={0x58: e.stub_fn('id->obj', look)})
    e.wf32(so + 0x9c7, r.choice([0.0, 1.0]))
    e.wf32(so + 0x9c3, r.choice([0.0, 1.0]))
    f = rnd(c, 0x40)
    lid = r.getrandbits(32) | 1
    objs[lid] = _actor(c)
    e.w32(f, lid)
    for k in range(12):
        e.w32(f + 0xc + 4 * k, r.choice([0, 1]))
    mems = []
    for i in range(r.randint(0, 6)):
        mid = r.getrandbits(32) | 1
        objs[mid] = _actor(c)
        m = rnd(c, 0x10)
        e.w32(m, mid)
        e.w32(m + 4, r.choice([-1, r.randint(0, 11), r.randint(0, 11)]) & 0xffffffff)
        mems.append(m)
    e.w32(f + 4, reftab(c, mems) if r.random() < 0.9 else 0)
    s = rnd(c, 0x60)
    return [s, f]


def _key(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    kids = [rnd(c, 0x10) for _ in range(r.randint(0, 4))]
    rec = {k: r.random() < 0.6 for k in kids}
    hook_rec(c, 0x4db9a0, 1, ret=lambda em, k: 1 if rec.get(em.reg('ecx')) else 0, this=True)
    nxt = {kids[i]: (kids[i + 1] if i + 1 < len(kids) else 0) for i in range(len(kids))}

    def adv(em, k):
        p = em.arg32(0)
        em.w32(p, nxt.get(em.r32(p), 0))
    grp = obj(c, 0x20, {0x50: pystub(c, 1, nullflag=(0,), side=adv)})
    e.w32(grp + 8, kids[0] if kids else 0)
    ids = {k: r.getrandbits(32) for k in kids}
    keys = {ids[k]: 1 for k in kids if r.random() < 0.4}
    sysobj(c, table_slots={0x50: pystub(c, 1, ret=lambda em, k: ids.get(em.arg32(0), 0))})
    s = rnd(c, 0x60)
    e.w32(s + 0x48, reftab(c, [], find=keys))
    return [s, grp]


S(0x5b5d60, 'CFormationControl::CheckRegroup', 'thiscall', ret='al', gen=_check, note='batch1511')
S(0x5b6ab0, 'formation key of a group (0x5b6ab0)', 'thiscall', ret='eax', gen=_key, note='batch1511')
