"""specs_s5819.py - unclaimed-57, batch 119: 0x5c1640 (CEnemyFlag::CopyEventDataBlock(DBREAD&), a vtable forwarder: a tail jump to 0x5c1dc0, thiscall with one
stack argument, ret 4). The callee 0x5c1dc0 (area 49's batch 605) is a logging stub with ECX and its argument (the DBREAD pointer is logged as the
dword it points at, never its address). The forwarder must pass ECX and the argument through and pop the same four bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    e = c.emu

    def h(em, r):
        p = em.arg32(0)
        em.calllog.append(('5c1dc0', 0, 'S' if em.reg('ecx') == self_obj else 'other', (em.rbytes(p, 4),)))
        em.ret(eax=0, argbytes=4)
    e.hook(0x5c1dc0, h)
    db = _rnd(c, 0x40)
    self_obj = _rnd(c, 0x100)
    return [self_obj, db]


S(0x5c1640, 'CEnemyFlag::CopyEventDataBlock (GUESS forwarder) thiscall', 'thiscall', None, ret=None, gen=_f,
  note='unclaimed-57 batch 119; forwarder to 0x5c1dc0 (area 49, batch 605), callee hooked (logs ECX and the DBREAD dword)')
