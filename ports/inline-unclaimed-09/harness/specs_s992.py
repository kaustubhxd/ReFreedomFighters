"""specs_s992.py - area 56 claim A58 (0x4e8c00, CalcLineCollision). Helpers are GUESS stubs.

a1 is a pointer to 0x20 random bytes (floats in [-6, 6] at +0); a2 and a3 are pointers to 0x40-byte random blocks used as values
(the helpers receive them as dword values); a4 is random; this is a 0x80-byte object of random bytes. Output vectors come from a per-case
table; the boolean 0x4e8c80 depends on its inputs (the sum of L2 minus the sum of L1 plus a small table term), so both outcomes run.
ret='al'."""
import struct
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    T = [rng.uniform(-6.0, 6.0) for _ in range(512)]
    k = [0]

    def nf():
        v = T[k[0] % len(T)]
        k[0] += 1
        return v

    def write3(e2, addr):
        e2.wbytes(addr, struct.pack('<fff', nf(), nf(), nf()))

    def read3(e2, addr):
        return struct.unpack('<fff', e2.rbytes(addr, 12))

    def h43e920(e2, r):
        e2.calllog.append(('H43e920',))
        write3(e2, e2.reg('ecx'))
        e2.ret(argbytes=4)
    e.hook(0x43e920, h43e920)

    def h441a60(e2, r):
        e2.calllog.append(('H441a60',))
        inp = read3(e2, e2.reg('edx'))
        e2.wbytes(e2.reg('ecx'), struct.pack('<fff', *[0.5 * inp[i] + nf() for i in range(3)]))
        e2.ret(argbytes=0)
    e.hook(0x441a60, h441a60)

    def h459fc0(e2, r):
        e2.calllog.append(('H459fc0',))
        write3(e2, e2.reg('ecx'))
        e2.ret(argbytes=4)
    e.hook(0x459fc0, h459fc0)

    def h4e8c80(e2, r):
        e2.calllog.append(('H4e8c80',))
        l1 = read3(e2, e2.arg32(1))
        l2 = read3(e2, e2.arg32(2))
        v = (l2[0] + l2[1] + l2[2]) - (l1[0] + l1[1] + l1[2]) + 0.2 * nf()
        e2.ret(eax=1 if v > 0.0 else 0, argbytes=16)
    e.hook(0x4e8c80, h4e8c80)

    def h443ef0(e2, r):
        e2.calllog.append(('H443ef0', e2.arg32(0)))  # arg0 is the dword a3 (pushed last), arg1 is the float
        write3(e2, e2.reg('ecx'))
        e2.ret(argbytes=8)
    e.hook(0x443ef0, h443ef0)

    this = _rnd(c, 0x80)
    a1 = _rnd(c, 0x20)
    for i in range(3):
        e.w32(a1 + 4 * i, struct.unpack('<I', struct.pack('<f', rng.uniform(-6.0, 6.0)))[0])
    a2 = _rnd(c, 0x40)
    a3 = _rnd(c, 0x40)
    return [this, a1, a2, a3, rng.getrandbits(32)]


S(0x4e8c00, 'CalcLineCollision (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-56 A58; 0x43e920, 0x441a60, 0x459fc0, 0x4e8c80, 0x443ef0 are GUESS stubs')
