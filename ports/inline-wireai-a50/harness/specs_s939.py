"""specs_s939.py - area 50 batch 939: three derived-class ctors (thiscall, two stack args, ret 8, returns this): 0x5e11c0, 0x5e1200, 0x5e10a0.
Stand-in (logged, writes nothing): the base ctor 0x5e0e10 (thiscall: this, a, b; ret 8). The object is a random block so every stored field is checked."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen_for(kind):
    def gen(c):
        e, r = c.emu, c.rng

        def hbase(e, rr):
            e.calllog.append(('base.5e0e10', e.reg('ecx') != 0, e.arg32(0), e.arg32(1)))
            e.ret(eax=0, argbytes=8)

        only_hooks(c, {0x5e0e10: hbase})
        self = rnd(c, 0x800)
        a, b = r.getrandbits(32), r.getrandbits(32)
        return [self, a, b]
    return gen


S(0x5e11c0, 'ctor (no name in map; base 5e0e10 stood in)', 'thiscall', None, ret='eax', gen=_gen_for('a'), note='area50 batch939 (label D)')
S(0x5e1200, 'ctor (no name in map; base 5e0e10 stood in)', 'thiscall', None, ret='eax', gen=_gen_for('b'), note='area50 batch939 (label D)')
S(0x5e10a0, 'ctor (no name in map; base 5e0e10 stood in)', 'thiscall', None, ret='eax', gen=_gen_for('c'), note='area50 batch939 (label D)')
