"""specs_s920.py - residue-9 slice, batch 920: 0x53b690 (thiscall, flag byte, ret 4, returns this) and 0x631810 (cdecl, two args, returns a
block pointer). Stand-ins (logged): 0x53b710, 0x4ccf60 (thiscall, no args), 0x634273 (cdecl, two words), 0x63a720 (cdecl, size; returns a
fresh block), 0x634d10 (cdecl, four words). The vtable word and the writes are compared; the returned pointers are compared by value."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen_init(c):
    e, r = c.emu, c.rng

    def h710(e, rr):
        e.calllog.append(('53b710', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    def h4cc(e, rr):
        e.calllog.append(('4ccf60', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    def h273(e, rr):
        e.calllog.append(('634273', e.arg32(0) != 0, e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x53b710: h710, 0x4ccf60: h4cc, 0x634273: h273})
    self = rnd(c, 0x80)
    return [self, r.choice([0, 1, 2, 0x100, r.getrandbits(32)])]


def _gen_alloc(c):
    e, r = c.emu, c.rng
    blk = rnd(c, 0x400)

    def h63a(e, rr):
        e.calllog.append(('63a720', e.arg32(0)))
        e.ret(eax=blk, argbytes=0)

    def h34d(e, rr):
        e.calllog.append(('634d10', e.arg32(0) != 0, e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x63a720: h63a, 0x634d10: h34d})
    return [r.getrandbits(32), r.choice([0, 1, 4, 0x10, r.getrandbits(12)]), r.choice([0, 1, 3, 0x100, r.getrandbits(8)])]


S(0x53b690, 'init flag (no name in map)', 'thiscall', None, ret='eax', gen=_gen_init, note='area50 batch920 (residue-9 slice)')
S(0x631810, 'alloc a*b (no name in map)', 'cdecl', None, ret='eax', gen=_gen_alloc, note='area50 batch920 (residue-9 slice)')
