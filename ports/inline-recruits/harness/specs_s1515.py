"""specs_s1515.py - recruits thread batch 1515: ZFollowGeom Init, Save, FrameUpdate.
Exe code: GetCen (0x4daf90), PSVECSubtract, createmat, DBREAD (0x4e5e60, a fake reads a dword from a stream).
Recorders: the owner's position/matrix calls, the target's position, the object table (id -> target), the saver's
slot 0x68 (records the three dwords by content)."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj


def _gen_init(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    owner_geom = rnd(c, 0x40)
    e.w32(owner_geom + 0, 0)
    for k in range(3):
        e.w32(owner_geom + 0x24 + 4 * k, r.getrandbits(32))
    gowner = rnd(c, 0x20)          # the owner object: its +8 is the geom the offset is copied from
    e.w32(gowner + 8, owner_geom)
    fobj = rnd(c, 0x60)
    e.w32(fobj + 0x44, gowner)
    hook_rec(c, 0x4e5e60, 0, ret=r.getrandbits(32))
    return [fobj, rnd(c, 0x10), rnd(c, 0x10)]


def _gen_save(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f = rnd(c, 0x60)
    sg = obj(c, 0x40, {0x68: pystub(c, 1, deref={0: 3})})
    return [f, sg]


def _gen_fu(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f = rnd(c, 0x60)
    tid = r.getrandbits(32) | 1
    tgt_pos = [r.uniform(-300, 300) for _ in range(3)]
    tgt_geom = rnd(c, 0x20)
    tgt = obj(c, 0x40, {0x84: pystub(c, 1, nullflag=(0,), side=lambda em, k: [em.wf32(em.arg32(0) + 4 * i, tgt_pos[i]) for i in range(3)])})
    e.w32(tgt + 8, tgt_geom)
    own_pos = [r.uniform(-300, 300) for _ in range(3)]
    own = obj(c, 0x40, {0x84: pystub(c, 1, nullflag=(0,), side=lambda em, k: [em.wf32(em.arg32(0) + 4 * i, own_pos[i]) for i in range(3)]),
                        0x7c: pystub(c, 2, deref={0: 12, 1: 3})})
    e.w32(f + 0x44, own)
    e.w32(f + 0x48, tid)
    for k in range(3):
        e.wf32(f + 0x4c + 4 * k, r.uniform(-50, 50))
    hook_rec(c, 0x4daf90, 1, this=True, stackmark=(0,))   # GetCen(float*): one stack argument (a caller-stack pointer)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=0 if r.random() < 0.15 else tgt)})
    return [f]


S(0x4c58b0, 'ZFollowGeom::Init', 'thiscall', gen=_gen_init, note='batch1515')
S(0x4c59d0, 'ZFollowGeom::Save', 'thiscall', ret='al', gen=_gen_save, note='batch1515')
S(0x4c58e0, 'ZFollowGeom::FrameUpdate', 'thiscall', gen=_gen_fu, note='batch1515')
