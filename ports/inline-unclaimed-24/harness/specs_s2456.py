"""specs_s2456.py - decomp area 24, batch 2456 (gap band).
0x45bfa0 ZProjectMarks::Load(ZLoadGame*), thiscall, ret 4, AL: slot 0x214 of this with no argument (recorder), then
ZGEOM::Load (0x45f3c0, recorder, the argument) and AL = (result != 0).
0x45b210 ZStdObjBox::CopyDataBlock(DBLK*), thiscall, ret 4: ZRenderGC::Init (0x610100, exe, bare ret 4), DBLK::NextBlock
(0x4e1b30, recorder), slot 0xb4 of this with 1 (recorder).
Not in this batch: 0x44a5e0 (ZLIST::RemoveGeom) makes a sys-table call with the argument still on the stack; the stack
contract of that slot is not settled (a pop-0 recorder faults the original, a pop-4 recorder makes the port fault), so it
is left unclaimed."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, hook_rec, clear_hooks


def _proj(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45f3c0, 1, this=True, ret=lambda emu, k: r.getrandbits(32))
    o = obj(c, 0x100, {0x214: pystub(c, 0)})
    return [o, rnd(c, 0x40)]


def _box(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e1b30, 0, this=True, ret=lambda emu, k: r.getrandbits(32))
    o = obj(c, 0x100, {0xb4: pystub(c, 1)})
    return [o, rnd(c, 0x40)]


S(0x45bfa0, 'ZProjectMarks::Load', 'thiscall', None, ret='al', gen=_proj, note='batch2456')
S(0x45b210, 'ZStdObjBox::CopyDataBlock', 'thiscall', None, ret=None, gen=_box, note='batch2456')
