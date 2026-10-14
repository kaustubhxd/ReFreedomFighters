"""specs_s34013.py - cascade tier E, batch 34013: scalar deleting destructors 0x4573a0 (members +0xd0 size 0x10, +0xcc size 0x18, base 0x43de70, stub size 0x354) and
0x476560 (members +0x64, +0x68 size 4, base 0x43ea20, stub size 0x77). Member pointers are null in half the cases (any other value, the free is a recorder);
callees are recorders (0x634273 / 0x4690b0 cdecl 2 args, 0x45c510 cdecl 1 arg, bases thiscall no args); flags cover all bit combinations."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _gen(m1, m2, base):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, 0x634273, 2, pop=0)
        hook_rec(c, 0x4690b0, 2, pop=0)
        hook_rec(c, 0x45c510, 1, pop=0)
        hook_rec(c, base, 0, this=True)
        me = rnd(c, 0x100)
        for off in (m1, m2):
            c.emu.w32(me + off, 0 if r.random() < 0.5 else r.getrandbits(32) | 0x10000000)
        return [me, r.choice([0, 1, 2, 3, 4, 5, 6, 7, 0x100, r.getrandbits(32)])]
    return g


S(0x4573a0, 'GUESS scalar deleting dtor (members +0xd0/+0xcc)', 'thiscall', None, ret='eax', gen=_gen(0xd0, 0xcc, 0x43de70), note='batch34013')
S(0x476560, 'GUESS scalar deleting dtor (members +0x64/+0x68)', 'thiscall', None, ret='eax', gen=_gen(0x64, 0x68, 0x43ea20), note='batch34013')
