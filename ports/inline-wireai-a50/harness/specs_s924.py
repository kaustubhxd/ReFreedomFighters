"""specs_s924.py - batch 924: 0x45f960 (thiscall, one stream arg, ret 4, returns al = 1). The stream's slot +0x3c receives this+0x14 and then the
word at this+0x10 -> +0x18 (or 0). Null sub-object and zero word are drawn too. Stream stub logs its argument and pops 4."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng

    def s3c(e, rr):
        e.calllog.append(('stream.3c', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    stream = vt_object(c, 0x40, {0x3c: s3c}, nslots=0x20, name='stream')
    self = rnd(c, 0x40)
    e.w32(self + 0x14, r.getrandbits(32))
    ch = r.random()
    if ch < 0.2:
        e.w32(self + 0x10, 0)
    else:
        x = rnd(c, 0x40)
        e.w32(x + 0x18, 0 if ch < 0.4 else r.getrandbits(32))
        e.w32(self + 0x10, x)
    return [self, stream]


S(0x45f960, 'write45f960 (no name in map)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch924 (residue-9 / dependency slice)')
