"""specs_s826.py - animation layer thread, batch 826: ZIKLNKOBJ flags, bone-id getters, ZTARGET accessors."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, vslot


def _obj(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    o = vt_object(c, 0x200, {0x2b4: vslot('bones.ByIdLookup', 1, ret=lambda e, a: (a[0] * 7 + 3) & 0xff)},
                  nslots=0xc0, name='ziklnk')
    e.w32(o + 0x136, r.getrandbits(32))
    e.w8(o + 0x158, r.getrandbits(8))
    return [o]


def _tgt(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    t = rnd(c, 0x60)
    e.w32(t + 0x39, r.getrandbits(32))
    e.wf32(t + 0x35, r.choice([0.0, -0.5, 0.5, c.fv(-3, 3)]))
    e.w32(t + 0x25, r.choice([0x7fffffff, r.getrandbits(32)]))
    return [t]


S(0x466470, 'ZIKLNKOBJ::DisableIK', 'thiscall', None, gen=_obj, note='batch826')
S(0x466620, 'ZIKLNKOBJ::EnableIK', 'thiscall', None, gen=_obj, note='batch826')
S(0x466610, 'ZIKLNKOBJ::EnableFacing', 'thiscall', None, gen=_obj, note='batch826')
S(0x466d70, 'ZIKLNKOBJ::PelvisBoneIndex', 'thiscall', None, ret='eax', gen=_obj, note='batch826')
S(0x466d80, 'ZIKLNKOBJ::RHandBoneIndex', 'thiscall', None, ret='eax', gen=_obj, note='batch826')
S(0x466f40, 'ZIKLNKOBJ::HeadBoneIndex', 'thiscall', None, ret='eax', gen=_obj, note='batch826')
S(0x466f50, 'ZIKLNKOBJ::NeckBoneIndex', 'thiscall', None, ret='eax', gen=_obj, note='batch826')
S(0x4673f0, 'ZIKLNKOBJ::LHandBoneIndex', 'thiscall', None, ret='eax', gen=_obj, note='batch826')
S(0x467400, 'ZIKLNKOBJ::LToeBoneIndex', 'thiscall', None, ret='eax', gen=_obj, note='batch826')
S(0x4666d0, 'ZTARGET::Geom', 'thiscall', None, ret='eax', gen=_tgt, note='batch826')
S(0x467700, 'ZTARGET::Removing', 'thiscall', None, ret='al', gen=_tgt, note='batch826')
S(0x4673c0, 'ZTARGET::Pos', 'thiscall', None, ret='eax', gen=_tgt, note='batch826')
