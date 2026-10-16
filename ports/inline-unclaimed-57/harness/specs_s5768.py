"""specs_s5768.py - unclaimed-57, batch 68: 0x5d5ae0 (GUESS name unnamed_5d5ae0). Thiscall, one stack argument a (ret 4), no return
value. The argument is a plain random integer: nothing in the original dereferences it, so it is only passed on (ECX of the helper
calls, and the first argument of the engine sub-object's slot). Hooked: 0x4e12e0 and 0x4e14a0 are logging stubs that log ECX and the
second argument, never the first (a pointer that differs between runs), and write nothing (owned by another area). The engine (global
0x70039c) has a sub-object at +0x9b whose fake slot +0x58 (one argument) logs its argument and returns a per-case value stored at
this+0x25. The original 0x610100 is a plain ret 4 and runs as original code."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5ae0(c):
    e = c.emu
    rv = c.rng.getrandbits(32)
    arg = c.rng.getrandbits(32)
    self_obj = _rnd(c, 0x80)

    def helper(name):
        # the first argument is logged as an offset into self when it points into self, else as a tag (stack pointers differ)
        def h(em, r):
            p = em.arg32(0)
            rel = p - self_obj if self_obj <= p < self_obj + 0x80 else 'other'
            em.calllog.append((name, 0, em.reg('ecx'), (rel, em.arg32(1))))
            em.ret(eax=0, argbytes=8)
        return h

    def h58(em, r):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=rv, argbytes=4)

    e.hook(0x4e12e0, helper('12e0'))
    e.hook(0x4e14a0, helper('14a0'))
    vt_sub = e.fake_vtable('d5ae0_sub', 160, {0x58: h58})
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    return [self_obj, arg]


S(0x5d5ae0, 'unnamed_5d5ae0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d5ae0,
  note='unclaimed-57 batch 68; helpers 0x4e12e0 and 0x4e14a0 hooked (log ECX and the value, write nothing); sub slot +0x58 fake')
