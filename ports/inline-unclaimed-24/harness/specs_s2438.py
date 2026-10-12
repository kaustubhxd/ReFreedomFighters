"""specs_s2438.py - decomp area 24, batch 2438 (gap band 0x441000-0x461000).
0x449300 ZLIGHT::EffectLight() const, thiscall, AL: bit 1 of the dword at +0x18.
0x454550 ZGATE::PFEnableGate(bool), thiscall, ret 4: byte at +0x60 = low byte of the argument.
0x4451b0 ZROOM::SetRoomControl(unsigned int, unsigned int), thiscall, ret 8: +0xac = (+0xac & ~second) | first.
0x448f60 ZLIGHT::DisableParentBoundAdjust(), thiscall, AL: 0 when bit 0 of the byte at +0x14 is set, else bit 2 of
the byte at +0x18 inverted.
0x4609b0 (GUESS constructor), thiscall, eax = this: vtable 0x685288, floats -1.0 and 0x7e967699 at +4 and +8, zeros at +0xc
and +0x10."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _one(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    e.w32(o + 0x18, r.getrandbits(32))
    return [o]


def _pf(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x80), r.getrandbits(32)]


def _rc(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32)]


def _adj(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    e.w8(o + 0x14, r.getrandbits(8))
    e.w32(o + 0x18, r.getrandbits(32))
    return [o]


def _ctor(c):
    clear_hooks(c)
    return [rnd(c, 0x40)]


S(0x449300, 'ZLIGHT::EffectLight', 'thiscall', None, ret='al', gen=_one, note='batch2438')
S(0x454550, 'ZGATE::PFEnableGate', 'thiscall', None, ret=None, gen=_pf, note='batch2438')
S(0x4451b0, 'ZROOM::SetRoomControl', 'thiscall', None, ret=None, gen=_rc, note='batch2438')
S(0x448f60, 'ZLIGHT::DisableParentBoundAdjust', 'thiscall', None, ret='al', gen=_adj, note='batch2438')
S(0x4609b0, 'GUESS: constructor (0x4609b0)', 'thiscall', None, ret='eax', gen=_ctor, note='batch2438')
