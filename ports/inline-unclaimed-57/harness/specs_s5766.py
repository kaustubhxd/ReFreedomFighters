"""specs_s5766.py - unclaimed-57, batch 66: 0x5d5620 (GUESS name unnamed_5d5620). Thiscall, no stack args, no return value; the
original ends with a tail jump (jmp [vt+0x250]) to the first object's slot, which takes no arguments. The engine (global 0x70039c)
has a sub-object at +0x9b with a fake vtable whose slot +0x58 (one argument) returns object e on its first call and a plain object o
on its second. Object e has fake slots +0x27c (one argument, logged) and +0x250 (no arguments, logged). Writes into e and o are checked
through the heap comparison. Slot logs hold the argument values only."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d620(c):
    e_ = c.emu
    calls = [0]
    e_obj = _rnd(c, 0x80)
    o_obj = _rnd(c, 0x80)

    def h58(em, r):
        calls[0] += 1
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=e_obj if calls[0] == 1 else o_obj, argbytes=4)

    def h27c(em, r):
        em.calllog.append(('27c', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h250(em, r):
        em.calllog.append(('250', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    vt_sub = e_.fake_vtable('d5620_sub', 160, {0x58: h58})
    vt_e = e_.fake_vtable('d5620_e', 160, {0x27c: h27c, 0x250: h250})
    e_.w32(e_obj, vt_e)
    sub = _rnd(c, 0x40)
    e_.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e_.w32(eng + 0x9b, sub)
    e_.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x80)
    e_.w32(self_obj + 0x48, c.rng.getrandbits(32))
    e_.w32(self_obj + 0x4c, c.rng.getrandbits(32))
    return [self_obj]


S(0x5d5620, 'unnamed_5d5620 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d620,
  note='unclaimed-57 batch 66; tail jump via e->vt[+0x250] called last; engine sub slot +0x58 fake (e then o); e slots logged')
