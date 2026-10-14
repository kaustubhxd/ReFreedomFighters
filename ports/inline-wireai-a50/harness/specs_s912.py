"""specs_s912.py - residue-9 slice, batch 912: 0x4d2190 (thiscall, two stack args, ret 8, void) and 0x5f1490 (thiscall, flag byte, ret 4,
returns this). Stand-ins: the object's slots +0x10 (one arg, logs) and +0xc (one pointer arg, logs the dword it points to); 0x634273
(cdecl, two words, logs; the caller pops). The flag's bit 0 is drawn both ways."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen_pair(c):
    e, r = c.emu, c.rng

    def h10(e, rr):
        e.calllog.append(('o.10', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def hc(e, rr):
        p = e.arg32(0)
        e.calllog.append(('o.0c', e.r32(p)))
        e.ret(eax=0, argbytes=4)

    o = vt_object(c, 0x40, {0x10: h10, 0xc: hc}, nslots=0x20, name='o')
    return [o, r.getrandbits(32), r.getrandbits(32)]


def _gen_init(c):
    e, r = c.emu, c.rng

    def h273(e, rr):
        e.calllog.append(('634273', e.arg32(0) != 0, e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x634273: h273})
    self = rnd(c, 0x40)
    return [self, r.choice([0, 1, 2, 3, 0x100, r.getrandbits(32)])]


S(0x4d2190, 'pair (no name in map)', 'thiscall', None, gen=_gen_pair, note='area50 batch912 (residue-9 slice)')
S(0x5f1490, 'init flag (no name in map)', 'thiscall', None, ret='eax', gen=_gen_init, note='area50 batch912 (residue-9 slice)')
