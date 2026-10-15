"""specs_s832.py - animation layer thread, batch 832: ZIKLNKOBJ IK bone queries (forwarders to the bone modifier)."""
from pilot import S
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _ik(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    mod = vt_object(c, 0x40, {0x10: vslot('mod.IK', 4)}, nslots=0x30, name='mod')
    o = vt_object(c, 0x200, {}, nslots=0x30, name='ziklnk')
    e.w32(o + 0x6c, mod)
    return [o, r.randint(0, 40) & 0xffffffff, rnd(c, 0x40), rnd(c, 0x40)]


S(0x466830, 'ZIKLNKOBJ::GetIKBoneMat', 'thiscall', None, gen=_ik, note='batch832')
S(0x466870, 'ZIKLNKOBJ::GetIKBoneMatPos', 'thiscall', None, gen=_ik, note='batch832')
S(0x466890, 'ZIKLNKOBJ::GetIKBonePos', 'thiscall', None, gen=_ik, note='batch832')
