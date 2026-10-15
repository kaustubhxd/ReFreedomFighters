"""specs_s67515.py - cascade s6 batch 67515 (0x535150, thiscall(ref, scale, posB, posA) ret 0x10, returns eax). 0x533e00 (this+0x8b) answers a slot id or 0; table slot 0x60 returns a
random-filled 0x100-byte record, slot 0x4c the handle of ref; the engine word at +0x1c comes from sysobj; this slot 0x4c accepts or refuses (al); 0x44b610 / 0x44b740 are recording
hooks; the two vectors are random 12-byte blocks."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g535150(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ident = r.choice([0, 7, 0x1234, 0xffffffff])
    hook_rec(c, 0x533e00, 0, this=True, ret=ident)
    rec = rnd(c, 0x100)
    hv = r.getrandbits(32)
    sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=rec), 0x4c: pystub(c, 1, this=True, ret=hv)}, table_size=0x70)
    hook_rec(c, 0x44b610, 0, this=True)
    hook_rec(c, 0x44b740, 1, pop=0)
    t = obj(c, 0x100, {0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100]))})
    va = rnd(c, 0x10)
    vb = rnd(c, 0x10)
    return [t, r.getrandbits(32), r.getrandbits(32), vb, va]


S(0x535150, 'GUESS init_record', 'thiscall', None, ret='eax', gen=_g535150, note='batch67515')
