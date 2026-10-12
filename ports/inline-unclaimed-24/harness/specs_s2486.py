"""specs_s2486.py - decomp area 24, batch 2486.
0x4a1d80 CAction::SetPriority(int) and 0x4a1db0 CAction::SetType(int): thiscall, ret 4. Store the argument (+0x52 / +0x48); when the
byte at +0x63 is set, slot 0x128 of the child at +0x44 gets (word at 0x7002c8, 1, child), callee pops.
0x5dc3e0 CImpactResponse::End(): thiscall, void. Calls the cdecl function pointer stored at 0x6762ec with the dword at +0x4c."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _setter(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    child = obj(c, 0x40, {0x128: pystub(c, 3, stackmark=(2,))})
    o = rnd(c, 0x80)
    e.w32(o + 0x44, child)
    e.wbytes(o + 0x63, bytes([r.choice([0, 1])]))
    e.w32(0x7002c8, r.getrandbits(32))
    return [o, r.getrandbits(32)]


def _end(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x6762ec, pystub(c, 1, pop=0, stackmark=(0,)))
    o = rnd(c, 0x80)
    e.w32(o + 0x4c, rnd(c, 0x20))
    return [o]


S(0x4a1d80, 'CAction::SetPriority', 'thiscall', None, ret=None, gen=_setter, note='batch2486')
S(0x4a1db0, 'CAction::SetType', 'thiscall', None, ret=None, gen=_setter, note='batch2486')
S(0x5dc3e0, 'CImpactResponse::End', 'thiscall', None, ret=None, gen=_end, note='batch2486')
