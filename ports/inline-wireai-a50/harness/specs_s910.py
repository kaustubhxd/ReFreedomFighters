"""specs_s910.py - residue-9 slice, batch 910: 0x4976d0 (thiscall, one word arg, returns dword), 0x650fd0 (thiscall, float + dword,
void; the float is drawn equal to the constant at 0x6785d0, unequal, or NaN), 0x628e90 (cdecl wrapper of 0x628c80, four args; the
stand-in for 0x628c80 logs its six words and pops them)."""
from pilot import S, F
from anim_common import only_hooks, rnd


def _gen_idx(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x100)
    e.w32(self + 0x51, r.getrandbits(32))
    w = r.choice([0, 1, 2, 0x100, 0xffff, 0x10000, r.getrandbits(32)])
    return [self, w]


def _gen_set(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x100)
    const = e.rf32(0x6785d0)
    ch = r.random()
    f = const if ch < 0.4 else (const + 1.0 if ch < 0.7 else float('nan'))
    return [self, F(f), r.getrandbits(32)]


def _gen_wrap(c):
    e, r = c.emu, c.rng

    def h628c80(e, rr):
        e.calllog.append(('628c80',) + tuple(e.arg32(k) for k in range(6)))
        e.ret(eax=0, argbytes=0)     # cdecl: the caller pops the six words

    only_hooks(c, {0x628c80: h628c80})
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4976d0, 'index (no name in map)', 'thiscall', None, ret='eax', gen=_gen_idx, note='area50 batch910 (residue-9 slice)')
S(0x650fd0, 'set flag (no name in map)', 'thiscall', None, gen=_gen_set, note='area50 batch910 (residue-9 slice)')
S(0x628e90, 'wrapper of 0x628c80 (no name in map)', 'cdecl', None, gen=_gen_wrap, note='area50 batch910 (residue-9 slice)')
