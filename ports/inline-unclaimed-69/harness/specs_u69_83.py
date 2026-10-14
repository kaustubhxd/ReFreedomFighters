"""specs_u69_83.py - area 69, residue-8 scalar deleting destructors 0x54cd40 and 0x551d40.
GUESS stub: 0x634273 (CRT sized delete, cdecl, two args) is a logging hook, as in the other areas. It logs whether the pointer is the object and the size (booleans and small ints only)."""
from pilot import S
from ckit import rnd


def _dtor(c):
    _hook_delete(c)
    obj = rnd(c, 0x40)
    return [obj, c.rng.getrandbits(32)]   # thiscall: ECX = obj, one stack arg (flags)


def _hook_delete(c):
    e = c.emu
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', e.arg32(1))), e.ret(argbytes=0)))


S(0x54cd40, 'dtor54cd40 (scalar deleting, ZSoundListener)', 'thiscall', None, ret='eax', gen=_dtor, note='u69 group 83; sized delete 0x634273 is a GUESS hook')
S(0x551d40, 'dtor551d40 (scalar deleting, CFFTools_if)', 'thiscall', None, ret='eax', gen=_dtor, note='u69 group 83; sized delete 0x634273 is a GUESS hook')
