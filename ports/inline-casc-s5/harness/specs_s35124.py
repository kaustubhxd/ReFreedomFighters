"""specs_s35124.py - 0x5eef20 (thiscall(s) ret 4). this: random 0x30 bytes with three child objects at +4, +8, +0xc (slot 0xc, 1 arg); s: slots 0x68 (1 arg: writes one random byte through its pointer), 0x40 (1 arg: out pointer flag-recorded, writes a random dword), 0x48 (1 arg: writes a random dword); 0x5eecd0 hooked (thiscall)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5eef20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5eecd0, 0, this=True)
    s = obj(c, 0x20, {0x68: pystub(c, 1, this=True, side=lambda em, k: em.wbytes(em.arg32(0), bytes([r.getrandbits(8)]))),
                      0x40: pystub(c, 1, nullflag=(0,), this=True, side=lambda em, k: em.w32(em.arg32(0), r.getrandbits(32))),
                      0x48: pystub(c, 1, this=True, side=lambda em, k: em.wbytes(em.arg32(0), r.getrandbits(32).to_bytes(4, 'little')))}, nslots=0x1a)
    me = rnd(c, 0x30)
    for off in (4, 8, 0xc):
        e.w32(me + off, obj(c, 0x10, {0xc: pystub(c, 1, this=True)}, nslots=4))
    return [me, s]


S(0x5eef20, 'GUESS read record from stream, children read too', 'thiscall', None, ret=None, gen=_g5eef20, note='batch35124')
