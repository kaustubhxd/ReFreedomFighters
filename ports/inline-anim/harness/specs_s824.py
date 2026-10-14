"""specs_s824.py - animation layer thread, batch 824: ZLNKOBJ::CopyAnimFilePointersFrom (0x461fa0)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, vslot


def _copy(c):
    e, r = c.emu, c.rng
    names = {}

    def gn(e2, res):
        p = e2.reg('ecx')
        e2.calllog.append(('GetAnimFileName', p))
        names.setdefault(p, r.getrandbits(32))
        e2.ret(eax=names[p], argbytes=0)
    only_hooks(c, {0x4e5330: gn})
    o = vt_object(c, 0x80, {0x2f4: vslot('lnk.FindAnimFile', 2, ret=lambda e2, a: a[0] ^ 0x5a5a5a5a)}, nslots=0xd2,
                  name='lnk')
    src = rnd(c, 0x80)
    for off in (0x5c, 0x60):
        e.w32(src + off, 0 if r.random() < 0.3 else rnd(c, 0x10))
    return [o, src]


S(0x461fa0, 'ZLNKOBJ::CopyAnimFilePointersFrom', 'thiscall', None, gen=_copy, note='batch824')
