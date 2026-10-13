"""specs_s2601.py - wider batch 2601: 0x53e900 CRigidBody::Disable with its callees hooked (the batch 171 spec ran them as exe code on random
objects, which faulted in ~80% of cases): 0x635490 (thiscall, no args), 0x634273 (cdecl (ptr, n), caller pops), 0x6352a0 (thiscall, 2 args, pops 8)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _gen(c):
    clear_hooks(c)
    hook_rec(c, 0x635490, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x6352a0, 2, this=True, pop=8)
    obj = rnd(c, 0x200)
    c.emu.w32(obj + 0x62, rnd(c, 0x100) if c.rng.random() < 0.6 else 0)
    return [obj]


S(0x53e900, 'CRigidBody::Disable', 'thiscall', None, ret=None, gen=_gen, note='batch2601 (src batch171)')
