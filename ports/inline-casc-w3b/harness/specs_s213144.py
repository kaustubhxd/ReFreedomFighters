"""specs_s213144.py - batch 213144: string table select by an engine value (IAT atoi), Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g56f2d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    found = r.random() < 0.85

    def q(emu, k):
        emu.calllog.append(('q', emu.arg32(0)))
        emu.w32(emu.arg32(1), r.getrandbits(32))
    eng = obj(c, 0x40, {0x5c: pystub(c, 2, ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | (1 if found else 0), this=True, stackmark=(1,), side=q)}, nslots=0x20)
    e.w32(0x70039c, eng)
    e.w32(0x6762d8, pystub(c, 1, ret=lambda emu, k: r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0xffffffff, 0x80000000, r.getrandbits(32)]), pop=0))
    return [rnd(c, 0x200)]


S(0x56f2d0, 'string_by_level', 'thiscall', None, ret=None, gen=g56f2d0)
