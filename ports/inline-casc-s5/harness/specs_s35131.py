"""specs_s35131.py - 0x4b8ec0 (thiscall(s) ret 4, ret='al'). s: slot 0x40 (1 arg, out pointer flag-recorded; writes a random dword), 0x68 (1 arg: writes a random byte), 0x44 (1 arg: writes a random word); engine table slot 0x58 (1 arg recorded) returns a random value; this: random 0x70 bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g4b8ec0(c):
    clear_hooks(c)
    r = c.rng
    s = obj(c, 0x20, {0x40: pystub(c, 1, nullflag=(0,), this=True, side=lambda em, k: em.w32(em.arg32(0), r.getrandbits(32))),
                      0x68: pystub(c, 1, nullflag=(0,), this=True, side=lambda em, k: em.wbytes(em.arg32(0), bytes([r.getrandbits(8)]))),
                      0x44: pystub(c, 1, nullflag=(0,), this=True, side=lambda em, k: em.wbytes(em.arg32(0), r.getrandbits(16).to_bytes(2, 'little')))}, nslots=0x1a)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    return [rnd(c, 0x70), s]


S(0x4b8ec0, 'GUESS read record with resolved id from stream', 'thiscall', None, ret='al', gen=_g4b8ec0, note='batch35131')
