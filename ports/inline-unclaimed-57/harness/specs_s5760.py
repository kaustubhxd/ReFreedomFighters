"""specs_s5760.py - unclaimed-57, batch 60: 0x5da280 (GUESS name unnamed_5da280). Thiscall, one stack argument (the DBREAD
pointer, ret 4), no return value. Hooked callees: 0x4e5e60 (dword reader, called four times in order, each result XORed with the
dword at its DBREAD pointer argument so the call order is observable) and 0x4e6180 (float array reader: writes a per-case count of
floats through its pointer argument, returns the count in eax, which the caller does not store)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _read(c):
    e = c.emu
    vals = [c.rng.getrandbits(32) for _ in range(4)]
    idx = [0]
    floats = [c.rng.choice([0.0, 1.0, -2.5, 0.125, 3.75, 16.0]) for _ in range(6)]

    def dword_fn(em, r):
        v = vals[idx[0] % 4]
        idx[0] += 1
        em.ret(eax=v ^ em.r32(em.reg('ecx')), argbytes=0)
    e.hook(0x4e5e60, dword_fn)

    def arr_fn(em, r):
        out = em.arg32(0)
        # the count comes from the dword at the reader object (ecx), so a wrong ecx changes what is written
        count = em.r32(em.reg('ecx')) % 6
        for i in range(count):
            em.wbytes(out + 4 * i, struct.pack('<f', floats[i]))
        em.ret(eax=count, argbytes=4)
    e.hook(0x4e6180, arr_fn)
    db = _rnd(c, 0x40)
    self_obj = _rnd(c, 0x100)
    return [self_obj, db]


S(0x5da280, 'unnamed_5da280 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_read,
  note='unclaimed-57 batch 60; readers 0x4e5e60 and 0x4e6180 hooked (dword and float array); ret 4')
