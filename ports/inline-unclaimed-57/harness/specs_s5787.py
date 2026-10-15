"""specs_s5787.py - unclaimed-57, batch 87: 0x5de4c0 (GUESS name unnamed_5de4c0). Thiscall, one stack argument obj (ret 4), returns al = 1.
obj has fake slots: +0x10 (two args: a pointer into this, logged as an offset from this, and a value, logged), +0x64 (one dword, logged)
and +0x4c (one float, logged as its bit pattern). The float values are random bit patterns, so NaN payloads occur as well."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c4c0(c):
    e = c.emu
    self_obj = _rnd(c, 0x200)

    def h10(em, r):
        p = em.arg32(0)
        rel = p - self_obj if self_obj <= p < self_obj + 0x200 else 'other'
        em.calllog.append(('10', 0, 'O' if em.reg('ecx') == obj else 'other', (rel, em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h64(em, r):
        em.calllog.append(('64', 0, 'O' if em.reg('ecx') == obj else 'other', (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h4c(em, r):
        em.calllog.append(('4c', 0, 'O' if em.reg('ecx') == obj else 'other', (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    vt_o = e.fake_vtable('c4c0_o', 160, {0x10: h10, 0x64: h64, 0x4c: h4c})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    return [self_obj, obj]


S(0x5de4c0, 'unnamed_5de4c0 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_c4c0,
  note='unclaimed-57 batch 87; obj fake slots +0x10 (pointer logged as an offset), +0x64, +0x4c (logged)')
