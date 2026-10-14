"""specs_s948.py - area 50 batch 948: 0x5ee920 (thiscall, no args, plain ret). Stand-in (logged): 0x5edcb0 (fastcall: ECX, EDX, then three stack words;
ret 0xc). The flag at this+0x19 is drawn zero or not, the word at +0x11 is drawn 1 or another value, and the list bounds (+5, +9) are drawn with 0 to 4
elements (and one case with the end before the begin, which the signed shift handles)."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng

    def hcb(e, rr):
        e.calllog.append(('5edcb0', e.reg('ecx'), e.reg('edx'), e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=12)

    only_hooks(c, {0x5edcb0: hcb})
    self = rnd(c, 0x80)
    e.w32(self + 0x19, r.choice([0, 1, r.getrandbits(32)]))
    e.w32(self + 0x11, r.choice([1, 0, 2, r.getrandbits(32)]))
    b = rnd(c, 0x40)
    if r.random() < 0.1:
        end = b - 4 * r.randint(1, 2)          # end before begin
    else:
        end = b + 4 * r.randint(0, 4)
    e.w32(self + 5, b)
    e.w32(self + 9, end & 0xffffffff)
    e.w32(self + 0x41, r.getrandbits(32))
    return [self]


S(0x5ee920, 'reset after bounded call (no name in map; 5edcb0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch948 (label D)')
