"""specs_s5772.py - unclaimed-57, batch 72: 0x5ddea0 (GUESS name unnamed_5ddea0). Thiscall, one stack argument (the DBREAD pointer db,
ret 4), no return value. Hooked readers: 0x4e5e80 (float in st0, three calls in order; folds in the dword at db) and 0x4e6180 (float
array: writes a count taken from the dword at ECX (db), mod 6, floats through its pointer; the result is not stored). The three
final divisions by 255.0f run as original code. Shapes are the same as batch 60 (0x5da280) and batch 61 (0x5d5ea0)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ddea0(c):
    e = c.emu
    fv = [c.rng.choice([0.0, 1.0, -2.5, 0.125, 3.75, 16.0]) for _ in range(3)]
    arr = [c.rng.choice([0.0, 1.0, -2.5, 0.125, 3.75, 16.0, 255.0]) for _ in range(6)]
    fi = [0]

    def float_fn(em, r):
        v = fv[fi[0] % 3]
        fi[0] += 1
        em.ret(st0=v + (em.r32(em.reg('ecx')) & 0xff) / 16.0, argbytes=0)
    e.hook(0x4e5e80, float_fn)

    def arr_fn(em, r):
        out = em.arg32(0)
        count = em.r32(em.reg('ecx')) % 6
        for i in range(count):
            em.wbytes(out + 4 * i, struct.pack('<f', arr[i]))
        em.ret(eax=count, argbytes=4)
    e.hook(0x4e6180, arr_fn)
    db = _rnd(c, 0x40)
    self_obj = _rnd(c, 0x100)
    return [self_obj, db]


S(0x5ddea0, 'unnamed_5ddea0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_ddea0,
  note='unclaimed-57 batch 72; readers 0x4e5e80 (float) and 0x4e6180 (float array, count from ECX) hooked; ret 4')
