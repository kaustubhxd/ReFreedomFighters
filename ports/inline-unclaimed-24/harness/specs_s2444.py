"""specs_s2444.py - decomp area 24, batch 2444 (gap band).
0x44b850 and 0x44b880 (GUESS owners), thiscall, ret 4: slot 0x12c of the object at (0x70039c)+0x1a9f is called with
(the dword at this+0x30 or +0x34, the argument); bit 0 of the dword at +0x40 is set; the result is stored back at the same
offset (+0x30 or +0x34). The slot is a recorder (two arguments)."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks


def _gen_for(off):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        so = sysobj(c)
        tab = obj(c, 0x40, {0x12c: pystub(c, 2, ret=lambda emu, k: r.getrandbits(32))})
        e.w32(so + 0x1a9f, tab)
        o = rnd(c, 0x80)
        return [o, r.getrandbits(32)]
    return gen


S(0x44b850, 'GUESS: sys slot 0x12c caller, +0x30 (0x44b850)', 'thiscall', None, ret=None, gen=_gen_for(0x30), note='batch2444')
S(0x44b880, 'GUESS: sys slot 0x12c caller, +0x34 (0x44b880)', 'thiscall', None, ret=None, gen=_gen_for(0x34), note='batch2444')
