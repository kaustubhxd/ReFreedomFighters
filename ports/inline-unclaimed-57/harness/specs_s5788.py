"""specs_s5788.py - unclaimed-57, batch 88: 0x5de430 (GUESS name unnamed_5de430). Thiscall, one stack argument obj (ret 4), returns al = 1.
obj has fake slots: +0x18 (two args: a pointer into this, logged as an offset from this, and a value), +0x40 (one pointer to the stack
argument's own slot: in about half the cases it writes a random dword there, so the later read of the slot sees the new value),
+0x50 (one pointer into this, logged as an offset). The engine sub-object's fake slot +0x58 (one argument, logged) returns a per-case
dword stored at this+0x114. Writes into this are checked by the heap comparison."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5de430(c):
    e = c.emu
    self_obj = _rnd(c, 0x200)
    write40 = c.rng.random() < 0.5
    new_slot = c.rng.getrandbits(32)
    rv58 = c.rng.getrandbits(32)

    def rel(p):
        return p - self_obj if self_obj <= p < self_obj + 0x200 else 'other'

    def h18(em, r):
        em.calllog.append(('18', 0, None, (rel(em.arg32(0)), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h40(em, r):
        em.calllog.append(('40', 0, None, ()))
        if write40:
            em.w32(em.arg32(0), new_slot)
        em.ret(eax=0, argbytes=4)

    def h50(em, r):
        em.calllog.append(('50', 0, None, (rel(em.arg32(0)),)))
        em.ret(eax=0, argbytes=4)

    def h58(em, r):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=rv58, argbytes=4)

    vt_o = e.fake_vtable('d5de430_o', 160, {0x18: h18, 0x40: h40, 0x50: h50})
    vt_sub = e.fake_vtable('d5de430_sub', 160, {0x58: h58})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    return [self_obj, obj]


S(0x5de430, 'unnamed_5de430 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_d5de430,
  note='unclaimed-57 batch 88; obj slots +0x18, +0x40 (may write the stack argument slot), +0x50 fake; engine sub slot +0x58 fake')
