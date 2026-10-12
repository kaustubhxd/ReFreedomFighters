"""specs_s2414.py - decomp area 24, batch 2414: four small accessors (pointer chains and a sum).
0x49c670 CListUser::GetTotalBufferSize: sum of the dwords at +0x19, +0x21, +0x29 (thiscall, eax).
0x4dc130 ZBaseGeom::ParentGroup: pointer at +0x50; if set, the dword at (pointer)+0x54 (thiscall, eax).
0x65f570 ZDrawBuffer::GetCameraToRootMatrix: ((this+8)+8)+8 (thiscall, eax).
0x602d70 accessor: pointer at +0x24; if set, the dword at (pointer)+0x24, else 0 (thiscall, eax)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _sum(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    return [o]


def _parent(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x80)
    if r.random() < 0.7:
        p = rnd(c, 0x80)
        c.emu.w32(o + 0x50, p)
    else:
        c.emu.w32(o + 0x50, 0)
    return [o]


def _cam(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    p = rnd(c, 0x40)
    q = rnd(c, 0x40)
    c.emu.w32(o + 8, p)
    c.emu.w32(p + 8, q)
    return [o]


def _acc(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x40)
    if r.random() < 0.7:
        c.emu.w32(o + 0x24, rnd(c, 0x40))
    else:
        c.emu.w32(o + 0x24, 0)
    return [o]


S(0x49c670, 'CListUser::GetTotalBufferSize', 'thiscall', None, ret='eax', gen=_sum, note='batch2414')
S(0x4dc130, 'ZBaseGeom::ParentGroup', 'thiscall', None, ret='eax', gen=_parent, note='batch2414')
S(0x65f570, 'ZDrawBuffer::GetCameraToRootMatrix', 'thiscall', None, ret='eax', gen=_cam, note='batch2414')
S(0x602d70, 'accessor at 0x602d70 (+0x24 chain)', 'thiscall', None, ret='eax', gen=_acc, note='batch2414')
