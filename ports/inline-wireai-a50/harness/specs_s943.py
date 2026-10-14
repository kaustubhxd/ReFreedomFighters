"""specs_s943.py - area 50 batch 943: 0x562020 (thiscall, one word arg, ret 4, void). Stand-ins (logged): 0x562140 (thiscall: this, two words; ret 8)
and 0x5ac5b0 (thiscall: the object, one float; callee pops 4 assumed). The argument is drawn across the unsigned range, including values with the top bit set,
and the object chain (this+0xf8, then +0x644) is drawn null or set."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng

    def h140(e, rr):
        e.calllog.append(('562140', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    def h5ac(e, rr):
        e.calllog.append(('5ac5b0', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    only_hooks(c, {0x562140: h140, 0x5ac5b0: h5ac})
    self = rnd(c, 0x100)
    e.w32(self + 0x54, r.getrandbits(32))
    o = rnd(c, 0x800)
    ch = r.random()
    if ch < 0.25:
        e.w32(self + 0xf8, 0)
    else:
        e.w32(self + 0xf8, o)
        if ch < 0.6:
            e.w32(o + 0x644, 0)
        else:
            e.w32(o + 0x644, rnd(c, 0x20))
    v = r.choice([0, 1, 254, 255, 256, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32)])
    return [self, v]


S(0x562020, 'entry with float value (no name in map; 562140 and 5ac5b0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch943 (label D)')
