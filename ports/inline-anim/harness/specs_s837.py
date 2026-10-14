"""specs_s837.py - animation layer thread, batch 837: ZLNKOBJ::DisplayBone, ZIKLNKOBJ::ActivateRagdoll. KillAllSounds is
hooked and logged; the modifier and vtable calls are logged slots."""
from pilot import S
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _db(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    count = r.randint(1, 6)
    tab = rnd(c, 0x18 * count + 0x20)
    for i in range(count):
        flags = r.getrandbits(32) & ~8
        if r.random() < 0.5:
            flags |= 8
        e.w32(tab + 0x18 * i + 4, flags)
    o = vt_object(c, 0x200, {}, nslots=0x30, name='lnk')
    e.w32(o + 0x1c, tab)
    e.w32(o + 0x20, count)
    bone = r.randint(0, count - 1)
    on = r.choice([0, 1, 0x100, r.getrandbits(32)])
    return [o, bone, on]


def _rag(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x466ce0: logged_fn('ZIKLNKOBJ::KillAllSounds', 0)})
    mod = vt_object(c, 0x40, {0x30: vslot('mod.Ragdoll', 4, ret=r.choice([0, 1, 0x100]))}, nslots=0x30, name='mod')
    o = vt_object(c, 0x200, {0x220: vslot('vt220', 1)}, nslots=0x120, name='ziklnk')
    e.w32(o + 0x6c, mod)
    a = r.choice([0, 1, 0x100, r.getrandbits(32)])
    b = r.choice([0, 1, r.getrandbits(32)])
    return [o, a, b]


S(0x4625c0, 'ZLNKOBJ::DisplayBone', 'thiscall', None, ret='al', gen=_db, note='batch837')
S(0x465760, 'ZIKLNKOBJ::ActivateRagdoll', 'thiscall', None, ret='al', gen=_rag, note='batch837')
