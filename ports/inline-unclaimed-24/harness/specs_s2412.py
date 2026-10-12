"""specs_s2412.py - decomp area 24, batch 2412: ZFFMortar::Save(ZSaveGame*) (0x5dd570), thiscall, returns AL = 1.
The saver's slot 0x60 (a byte) is called six times (+0x48, +0x75..+0x79) and slot 0x3c (a dword at +0x7a) once.
Both are recorders with one stack argument. The mortar object is random."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _gen(c):
    clear_hooks(c)
    f = rnd(c, 0x100)
    sg = obj(c, 0x40, {0x60: pystub(c, 1), 0x3c: pystub(c, 1)})
    return [f, sg]


S(0x5dd570, 'ZFFMortar::Save', 'thiscall', None, ret='al', gen=_gen, note='batch2412')
