"""specs_s922.py - residue-9 slice, batch 922: 0x4d1f10 (thiscall, one arg, ret 4, returns a dword). Stand-ins (logged): 0x41e290 (cdecl, one
word; returns a block drawn as a fresh allocation or 0), 0x4d1320 (thiscall, three words, ret 12; logs its ECX identity and the words, returns
a drawn dword). Both branches (null and non-null block) run."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    blk = rnd(c, 0x80)
    rv = r.getrandbits(32)
    nul = r.random() < 0.3

    def h290(e, rr):
        e.calllog.append(('41e290', e.arg32(0)))
        e.ret(eax=0 if nul else blk, argbytes=0)

    def h1320(e, rr):
        e.calllog.append(('4d1320', e.reg('ecx') == blk, e.arg32(0), e.arg32(1) != 0, e.arg32(2)))
        e.ret(eax=rv, argbytes=12)

    only_hooks(c, {0x41e290: h290, 0x4d1320: h1320})
    self = rnd(c, 0x80)
    return [self, r.getrandbits(32)]


S(0x4d1f10, 'make4d1f10 (no name in map)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch922 (residue-9 slice)')
