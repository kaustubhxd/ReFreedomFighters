"""specs_u18_01.py - area 18, first group (unclaimed-18 thread)."""
from pilot import S
from ckit import obj, rnd


def _o(c, size=0x500):
    return [rnd(c, size)]


S(0x483ed0, 'ZPlayer::GetStatus', 'thiscall', None, ret='eax', gen=lambda c: _o(c), note='u18')
S(0x4f7f10, 'ZSlider::IsChanging', 'thiscall', None, ret='al', gen=lambda c: _o(c), note='u18')
S(0x64fc50, 'ZRender::GetSizeX', 'thiscall', None, ret='eax', gen=lambda c: _o(c), note='u18')
S(0x5d92d0, 'CTVOnOff::Init', 'thiscall', None, ret=None, gen=lambda c: _o(c), note='u18')


def _bones(c):
    r = c.rng
    o = rnd(c, 0x100)
    c.emu.w8(o + 0x3c, r.getrandbits(8))
    c.emu.w8(o + 0x3f, r.getrandbits(8))
    return [o]


S(0x658d50, 'ZGeomDrawEntry::BonesSize', 'thiscall', None, ret='eax', gen=_bones, note='u18')


def _bt(c):
    r = c.rng
    e = c.emu
    tree = rnd(c, 0x20)
    sent = rnd(c, 0x20)
    e.w32(tree + 8, sent)
    n = r.randint(1, 5)
    nodes = [rnd(c, 0x20) for _ in range(n)]
    for k in range(n - 1):
        e.w32(nodes[k] + 4, nodes[k + 1])
    e.w32(nodes[-1] + 4, sent)
    start = nodes[r.randrange(n)]
    return [tree, start]


S(0x4e83d0, 'ZBinTree::Minimum', 'thiscall', None, ret='eax', gen=_bt, note='u18; list of 1..5 nodes ending at the sentinel')
