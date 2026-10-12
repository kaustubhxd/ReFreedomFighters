"""specs_s2417.py - decomp area 24, batch 2417: two tail-jump forwarders.
0x452bb0 ZENVIRONMENT::CopyData(const ZGEOM*): jmp to ZLIGHT::CopyData (0x4487f0), recorded here.
0x5f0170 CSpriteDivide2D::Save(ZSaveGame*): jmp to CSprite2D::Save (0x5ed170), recorded here.
The forwarders keep the stack arguments, so the target's return is the forwarder's return; the spec compares eax."""
from pilot import S
from recruits_util import rnd, obj, hook_rec, clear_hooks


def _copy(c):
    clear_hooks(c)
    g = rnd(c, 0x40)
    o = rnd(c, 0x40)
    hook_rec(c, 0x4487f0, 1, this=True, ret=lambda e, a: 0x1234 + (a and 0))
    return [o, g]


def _save(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    sg = rnd(c, 0x40)
    hook_rec(c, 0x5ed170, 1, this=True, ret=lambda e, a: 0x4321)
    return [o, sg]


S(0x452bb0, 'ZENVIRONMENT::CopyData', 'thiscall', None, ret='eax', gen=_copy, note='batch2417')
S(0x5f0170, 'CSpriteDivide2D::Save', 'thiscall', None, ret='eax', gen=_save, note='batch2417')
