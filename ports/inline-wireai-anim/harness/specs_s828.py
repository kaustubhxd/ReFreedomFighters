"""specs_s828.py - animation layer thread, batch 828: bone-anim callback <-> id map."""
from pilot import S
from anim_common import only_hooks


def _cb(c):
    only_hooks(c, {})
    r = c.rng
    return [r.getrandbits(32), r.choice([0x465710, 0, 1, r.getrandbits(32)])]   # this (ECX), fn (stack)


def _id(c):
    only_hooks(c, {})
    r = c.rng
    return [r.getrandbits(32), r.choice([0, 1, 2, r.getrandbits(32)])]   # this (ECX), id (stack)


S(0x465850, 'ZIKLNKOBJ::BoneAnimCallBackToId', 'thiscall', None, ret='eax', gen=_cb, note='batch828')
S(0x465870, 'ZIKLNKOBJ::BoneAnimIdToCallBack', 'thiscall', None, ret='eax', gen=_id, note='batch828')
