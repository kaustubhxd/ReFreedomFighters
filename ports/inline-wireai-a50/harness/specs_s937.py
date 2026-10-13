"""specs_s937.py - batch 937: 0x477740 (ZActor::ActivateBaseMove, thiscall, two stack args (a, flag byte), ret 8, returns al = 1). Stand-ins (logged):
this's slot +0x5a8 (one arg; returns a drawn pointer r whose first word is nonzero, the second word has bit 3 drawn), this's slot +0x268 (two args).
The manager (g+0x9b, +0x44) is set so that the block at mgr+0x44+ecx holds small integers at +0x5c, +0x60, +0x64, +0x6c (the divisor is nonzero) and a
pointer at +0x7c. this+0x650 is drawn equal to a (the early exit) or not, and the flag is drawn zero or not. The float at this+0x755 is drawn finite."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, install_fmod


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    install_fmod(c)          # _CIfmod import (the exe calls it through 0x634dc4)
    area = rnd(c, 0x100)
    ecx = 0x10
    for off, v in ((0x5c, r.randint(-50, 50)), (0x60, r.randint(-50, 50)), (0x64, r.randint(-50, 50)), (0x6c, r.randint(1, 50))):
        e.w32(area + off, v & 0xffffffff)
    e.w32(area + 0x7c, rnd(c, 0x10))
    mgr = rnd(c, 0x100)
    e.w32(mgr + 0x44, (area - ecx) & 0xffffffff)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    rec = rnd(c, 0x40)
    e.w32(rec, ecx)
    e.w32(rec + 4, r.getrandbits(32) | (8 if r.random() < 0.5 else 0))
    rec2 = rec

    def h5a8(e, rr):
        e.calllog.append(('self.5a8', e.arg32(0)))
        e.ret(eax=rec2, argbytes=4)

    def h268(e, rr):
        e.calllog.append(('self.268', e.arg32(0) == area, e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    self = vt_object(c, 0x800, {0x5a8: h5a8, 0x268: h268}, nslots=0x200, name='self')
    for off in (0x755, 0x759, 0x769):
        e.wf32(self + off, r.uniform(-300.0, 300.0))
    a = r.getrandbits(16)
    if r.random() < 0.4:
        e.w32(self + 0x650, a)
    else:
        e.w32(self + 0x650, r.getrandbits(16))
    flag = r.choice([0, 1, 8, 0x10])
    return [self, a, flag]


S(0x477740, 'ZActor::ActivateBaseMove (named)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch937 (core slice)')
