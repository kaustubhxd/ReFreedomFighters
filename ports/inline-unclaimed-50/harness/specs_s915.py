"""specs_s915.py - residue-9 slice, batch 915: 0x62d210 (cdecl: object pointer, code; returns a dword). Codes 0x0f, 0x11, 0x1c, 0x1d and
a random value; the object's +0xc word is drawn zero or not so the 0x1c branch runs both ways."""
from pilot import S
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    obj = rnd(c, 0x20)
    e.w32(obj + 0xc, r.choice([0, 0, 1]))
    code = r.choice([0xf, 0x11, 0x1c, 0x1d, 0, r.getrandbits(32)])
    return [obj, code]


S(0x62d210, 'code to status (no name in map)', 'cdecl', None, ret='eax', gen=_gen, note='area50 batch915 (residue-9 slice)')
