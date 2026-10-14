"""specs_s894.py - gap-band slice, batch 894: 0x420030 (GUESS name Flush420030), thiscall, one stack arg (a flag, bit 0 tested),
ret 4, returns this (eax). Stand-ins (hooked, logged): 0x41fed0 (thiscall, no args) and 0x634273 (cdecl, two words, pops its own
words in the caller's convention: argbytes 0)."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng

    def h_fed0(e, rr):
        e.calllog.append(('fed0', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    def h_273(e, rr):
        e.calllog.append(('273', e.arg32(0) != 0, e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x41fed0: h_fed0, 0x634273: h_273})
    self = rnd(c, 0x40)
    flag = r.choice([0, 1, 2, 3, 0x100, r.getrandbits(32)])
    return [self, flag]


S(0x420030, 'Flush420030 (GUESS name)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch894 (band slice)')
