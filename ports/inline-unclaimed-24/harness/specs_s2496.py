"""specs_s2496.py - decomp area 24, batch 2496 (residue 3, smallest first).
0x57ebb0 (GUESS): thiscall, ret 4. System table slot 0x4c (recorder, returns a value that depends on the call count) for this+8, then
for eight dwords at this+0xc: slot 0x3c of the argument (recorder, thiscall, one argument) with the table result.
0x4b0f30 (GUESS): thiscall, ret 4, AL = 1. Global at 0x7003b0 (recorder, cdecl, no arguments); slot 0x98 of this (recorder, one argument);
on the argument: slots 0x48, 0x58, 0x68 (recorders, one argument each) with this+0x48, +0x50, +0x6c."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks


def _paired(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=lambda emu, k: (0x1000 + 16 * k) & 0xffffffff)})
    arg = obj(c, 0x40, {0x3c: pystub(c, 1)})
    o = rnd(c, 0x60)
    e.w32(o + 8, r.getrandbits(32))
    for i in range(8):
        e.w32(o + 0xc + 4 * i, r.getrandbits(32))
    return [o, arg]


def _serialize(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, pystub(c, 0, pop=0))
    o = obj(c, 0x100, {0x98: pystub(c, 1)})
    e.w32(o + 4, r.getrandbits(32))
    arg = obj(c, 0x40, {0x48: pystub(c, 1), 0x58: pystub(c, 1), 0x68: pystub(c, 1)})
    return [o, arg]


S(0x57ebb0, 'GUESS paired table calls', 'thiscall', None, ret=None, gen=_paired, note='batch2496')
S(0x4b0f30, 'GUESS serialize fields', 'thiscall', None, ret='al', gen=_serialize, note='batch2496')
