"""specs_s5761.py - unclaimed-57, batch 61: 0x5d5ea0 (GUESS name unnamed_5d5ea0). Thiscall, one stack argument (the DBREAD
pointer db, ret 4), no return value. Hooked readers, both fold in the dword at their DBREAD pointer (ecx = db) so the call order
and the pointer are observable: 0x4e5e80 returns a float in st0 (three calls in order), 0x4e5e60 returns a dword (three calls)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _read(c):
    e = c.emu
    fv = [c.rng.choice([0.0, 1.0, -2.5, 0.125, 3.75, 16.0]) for _ in range(3)]
    dv = [c.rng.getrandbits(32) for _ in range(3)]
    fi = [0]
    di = [0]

    def float_fn(em, r):
        v = fv[fi[0] % 3]
        fi[0] += 1
        em.ret(st0=v + (em.r32(em.reg('ecx')) & 0xff) / 16.0, argbytes=0)
    e.hook(0x4e5e80, float_fn)

    def dword_fn(em, r):
        v = dv[di[0] % 3]
        di[0] += 1
        em.ret(eax=v ^ em.r32(em.reg('ecx')), argbytes=0)
    e.hook(0x4e5e60, dword_fn)
    self_obj = _rnd(c, 0x100)
    db = _rnd(c, 0x40)
    return [self_obj, db]


S(0x5d5ea0, 'unnamed_5d5ea0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_read,
  note='unclaimed-57 batch 61; readers 0x4e5e80 (float) and 0x4e5e60 (dword) hooked; ret 4')
