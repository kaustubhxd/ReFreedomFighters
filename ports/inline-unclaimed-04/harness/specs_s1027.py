"""specs_s1027.py - unclaimed-04 batch 28 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
0x403ab0 (cdecl, two float arrays of 56): A[i] = B[i] when B[i] < A[i] or either is NaN (x87 fcomp, C0 on unordered).
0x6565b0 (thiscall, ret 8, dst and src): vtable slot 0x148 is called with (dst, src) (a recording stub), then the dwords at
src+0x18, +0x1c, +0x20 are copied into dst. The floats include NaN and equal pairs, so both compare outcomes come up."""
import struct

from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    return c.rng.choice([0.0, -0.0, 1.5, -1.5, float('nan'), c.rng.uniform(-50.0, 50.0), 3.25])


def _minpair(c):
    A = c.emu.alloc(56 * 4, 4)
    B = c.emu.alloc(56 * 4, 4)
    va = [_f(c) for _ in range(56)]
    vb = [v if c.rng.random() < 0.3 else _f(c) for v in va]
    c.emu.wbytes(A, b''.join(struct.pack('<f', x) for x in va))
    c.emu.wbytes(B, b''.join(struct.pack('<f', x) for x in vb))
    return [A, B]


def _copy(c):
    vt_ret = 0

    def h148(em, r):
        em.calllog.append(('vt.148', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=vt_ret, argbytes=8)

    vt = c.emu.fake_vtable('copy owner', 0x148 // 4 + 1, {0x148: h148})
    o = _rnd(c, 0x100)
    c.emu.w32(o, vt)
    dst = _rnd(c, 0x100)
    src = _rnd(c, 0x100)
    return [o, dst, src]


S(0x403ab0, 'unknown::min_copy_56 (unknown) cdecl', 'cdecl', None, ret=None, gen=_minpair,
  note='unclaimed-04 batch 28; x87 compare, NaN copies (GUESS)')
S(0x6565b0, 'unknown::vt148_copy_18_20 (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-04 batch 28; slot 0x148 recording stub (GUESS)')
