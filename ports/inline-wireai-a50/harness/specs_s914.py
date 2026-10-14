"""specs_s914.py - residue-9 slice, batch 914: 0x5b7790 (thiscall, no args, returns this). Base constructor 0x469870 stood in (logs its ECX
is this). The object's words at +4, +0x44, +0x48 are drawn first, so the writes show in the heap compare."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng

    def h469(e, rr):
        e.calllog.append(('base.469870', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x469870: h469})
    self = rnd(c, 0x80)
    e.w32(self + 4, r.getrandbits(32))
    e.w32(self + 0x44, r.getrandbits(32))
    e.w32(self + 0x48, r.getrandbits(32))
    return [self]


S(0x5b7790, 'init (no name in map)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch914 (residue-9 slice)')
