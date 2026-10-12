"""specs_s2413.py - decomp area 24, batch 2413: CHitpointControl::Load(ZLoadGame*) (0x584970), thiscall, returns AL = 1.
The DBREAD is a local dword (its stack address is passed to ZEventBase::GetInput (0x6352f0, recorder, stack pointer
marked) and to vtable slot 4 of this (recorder, stack pointer marked)). The load game's slots 0x50 (two calls with
+0x64 and +0x57) and 0x40 (+0x6c) are recorders. Recorded pointers are heap addresses, so mutants that change a
field offset are visible."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    h = obj(c, 0x100, {4: pystub(c, 1, stackmark=(0,))})
    hook_rec(c, 0x6352f0, 1, this=True, stackmark=(0,))
    ld = obj(c, 0x40, {0x50: pystub(c, 1), 0x40: pystub(c, 1)})
    return [h, ld]


S(0x584970, 'CHitpointControl::Load', 'thiscall', None, ret='al', gen=_gen, note='batch2413')
