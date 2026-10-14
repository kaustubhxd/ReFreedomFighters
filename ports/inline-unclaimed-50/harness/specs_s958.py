"""specs_s958.py - area 50 batch 958: 0x557c20 (thiscall, one arg, ret 4, void). Stand-ins (logged): 0x5003d0 (thiscall, one index arg; returns a
block drawn per (ECX, index); ECX is the argument's object at +4 or +8), 0x59dae0 (thiscall, five stack words, ret 0x14; returns a drawn dword) and
the setter 0x5002f0 (thiscall, one arg, ret 4)."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    a = rnd(c, 0x40)
    o4, o8 = rnd(c, 0x20), rnd(c, 0x20)
    e.w32(a + 4, o4)
    e.w32(a + 8, o8)
    blks = {}
    for key in [(o4, i) for i in range(4)] + [(o8, 0)]:
        b = rnd(c, 0x10)
        e.w32(b, r.getrandbits(32))
        blks[key] = b
    xv = r.getrandbits(32)

    def h5003(e, rr):
        ecx, idx = e.reg('ecx'), e.arg32(0)
        e.calllog.append(('5003d0', 'o4' if ecx == o4 else 'o8' if ecx == o8 else ecx, idx))
        e.ret(eax=blks.get((ecx, idx), 0), argbytes=4)

    def h59da(e, rr):
        e.calllog.append(('59dae0', e.reg('ecx') == self1c, tuple(e.arg32(k) for k in range(5))))
        e.ret(eax=xv, argbytes=0x14)

    def h5002(e, rr):
        e.calllog.append(('5002f0', e.reg('ecx') == blks[(o8, 0)], e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    only_hooks(c, {0x5003d0: h5003, 0x59dae0: h59da, 0x5002f0: h5002})
    self = rnd(c, 0x40)
    self1c = rnd(c, 0x20)
    e.w32(self + 0x1c, self1c)
    return [self, a]


S(0x557c20, 'four accessor dwords into 59dae0 then setter (no name in map; 5003d0, 59dae0, 5002f0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch958 (claimed)')
