"""specs_s303.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x45dcb0, a wrapper that forwards five arguments to
exe helper 0x4daaf0 on the object at this+8. 0x4daaf0 is a GUESS call-recording stub (logs its five arguments)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _wrap(c):
    e = c.emu

    def h(em, r):                      # GUESS call-recording stub for 0x4daaf0: logs its five arguments and returns 0
        em.calllog.append(('h4daaf0', 0x4daaf0, em.reg('ecx'), tuple(em.arg32(k) for k in range(5))))
        em.ret(eax=0, argbytes=0x14)
    e.hook(0x4daaf0, h)
    self_ = _rnd(c, 0x40)
    obj = _rnd(c, 0x200)
    e.w32(self_ + 8, obj)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x45dcb0, 'wrap (GUESS)', 'thiscall', None, ret='eax', gen=_wrap, note='batch303; ret 0x10; exe 0x4daaf0')
