"""specs_s5771.py - unclaimed-57, batch 71: 0x5d8cf0 (GUESS name unnamed_5d8cf0). Thiscall, one stack argument a (ret 4), no return
value. a is a plain random integer, only passed on (ECX of the helper calls). The original 0x610100 is a plain ret 4 and runs as
original code. Helpers 0x4e12e0, 0x4e11e0 and 0x4e12f0 are logging stubs (owned by another area): each logs ECX, the first argument
as an offset into this (or a tag for other pointers), and the value argument; none writes. The helper hooks are the same shape as in
batch 68 (0x5d5ae0)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d8cf0(c):
    e = c.emu
    arg = c.rng.getrandbits(32)
    self_obj = _rnd(c, 0x80)

    def helper(name):
        def h(em, r):
            p = em.arg32(0)
            rel = p - self_obj if self_obj <= p < self_obj + 0x80 else 'other'
            em.calllog.append((name, 0, em.reg('ecx'), (rel, em.arg32(1))))
            em.ret(eax=0, argbytes=8)
        return h

    e.hook(0x4e12e0, helper('12e0'))
    e.hook(0x4e11e0, helper('11e0'))
    e.hook(0x4e12f0, helper('12f0'))
    return [self_obj, arg]


S(0x5d8cf0, 'unnamed_5d8cf0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d8cf0,
  note='unclaimed-57 batch 71; helpers 0x4e12e0, 0x4e11e0, 0x4e12f0 hooked (log ECX, pointer offset, value); 0x610100 original')
