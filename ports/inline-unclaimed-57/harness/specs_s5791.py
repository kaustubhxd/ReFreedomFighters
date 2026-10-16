"""specs_s5791.py - unclaimed-57, batch 91: 0x5d9810 (GUESS name unnamed_5d9810). Thiscall, one stack argument db (ret 4), no return value.
The reader 0x4e5e60 is hooked: each of its thirteen calls returns a per-call value XORed with the dword at its DBREAD pointer (db, a valid
allocation), so the call order and the pointer are both observable through the stored fields. The fields are checked by the heap comparison."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d9810(c):
    e = c.emu
    vals = [c.rng.getrandbits(32) for _ in range(13)]
    idx = [0]

    def h5e60(em, r):
        v = vals[idx[0] % 13]
        idx[0] += 1
        em.ret(eax=v ^ em.r32(em.reg('ecx')), argbytes=0)
    e.hook(0x4e5e60, h5e60)
    db = _rnd(c, 0x40)
    self_obj = _rnd(c, 0x100)
    return [self_obj, db]


S(0x5d9810, 'unnamed_5d9810 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d9810,
  note='unclaimed-57 batch 91; reader 0x4e5e60 hooked (per-call value XOR the dword at db); thirteen stores')
