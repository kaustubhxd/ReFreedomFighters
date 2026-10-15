"""specs_s370.py - area 76, batch 370: 0x4dfa30 (fastcall: ECX = out, EDX = E, stack A, Q, R; ret 0xc; bool in AL; GUESS).
The vectors are random floats in [-10, 10]; a quarter of the cases make R exactly orthogonal to A (d == 0) so the false branch runs.
0x441940 (called with the output in ECX) is hooked: it logs ECX and writes nothing."""
import struct
from pilot import S


def _f(x):
    return struct.pack('<f', x)


def _gen(c):
    e = c.emu
    rng = c.rng

    def h441940(em, r):
        em.calllog.append(('h441940', 0x441940, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x441940, h441940)

    def vec():
        return [rng.uniform(-10.0, 10.0) for _ in range(3)]

    out = e.alloc(0x40, 4)
    e.wbytes(out, bytes(0x40))
    E = e.alloc(0x40, 4)
    e.wbytes(E, b''.join(_f(v) for v in vec()))
    A = e.alloc(0x40, 4)
    Av = vec()
    e.wbytes(A, b''.join(_f(v) for v in Av))
    Q = e.alloc(0x40, 4)
    e.wbytes(Q, b''.join(_f(v) for v in vec()))
    R = e.alloc(0x40, 4)
    Rv = vec()
    if rng.random() < 0.25:
        Rv = [Av[1], -Av[0], 0.0]            # exactly orthogonal to A: the false branch (d == 0)
    e.wbytes(R, b''.join(_f(v) for v in Rv))
    return [out, E, A, Q, R]


S(0x4dfa30, 'plane4dfa30 (GUESS)', 'fastcall', None, ret='al', gen=_gen,
  note='area 76 batch 370; lower half of label D; 0x441940 hooked')
