"""specs_s857.py - area 50, batch 857: 0x545690 (name GUESS), FASTCALL with five stack args (ret 0x14), bool.
The vectors P, Q, A and E, the float outputs B and D and the radius C live in generated memory. Stood in (hooked, logged):
0x547430 (the post step on E, only when D <= 1e-6). The exe's vector subtract, the x87 0x443ef0, the scale 0x4e0d00 and the
CRT sqrt (import slot 0x676330) run as they are. Most cases use random vectors; some use exact boundary configurations so
that the equality tests run: P = A (t == s), A = Q (s == 0 and t == 0, a NaN ratio), P = Q with C = 0 (E == 0, |E|^2 == C^2),
and P = Q + (1e-6, 0, 0) with A = Q - (1, 0, 0) (t < 0, D == 1e-6 exactly)."""
import struct
from pilot import S
from anim_common import only_hooks, rnd


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0

    def vec(vals=None):
        a = rnd(c, 16)
        for i in range(3):
            e.wf32(a + 4 * i, vals[i] if vals else fin(c.fv(-3, 3)))
        return a

    def post(e, rr):
        e.calllog.append(('post.547430', e.reg('ecx')))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x547430: post})
    mode = r.choice(['rand', 'rand', 'rand', 'rand', 'eqAB', 'zeroAQ', 'zeroPQ', 'k'])
    K = _f32(1e-6)
    if mode == 'eqAB':
        P = vec([_f32(0.5), _f32(-1.25), _f32(2.0)])
        Q = vec([_f32(0.25), _f32(0.75), _f32(-0.5)])
        A = vec([_f32(1.5), _f32(0.5), _f32(-0.75)])
        e.wbytes(P, e.rbytes(A, 12))          # P = A: V1 == V2 exactly, so t == s
        Cp_v = 1.0
    elif mode == 'zeroAQ':
        Q = vec([_f32(0.5), _f32(-0.25), _f32(1.0)])
        P = vec()
        A = Q
        e.wbytes(A, e.rbytes(Q, 12))          # A = Q: V2 == 0, so t == s == 0
        Cp_v = 1.0
    elif mode == 'zeroPQ':
        Q = vec([_f32(0.5), _f32(-0.25), _f32(1.0)])
        P = Q
        e.wbytes(P, e.rbytes(Q, 12))          # P = Q: V1 == 0, so E == 0 on the divide path
        A = vec()
        Cp_v = 0.0
    elif mode == 'k':
        Q = vec([0.0, 0.0, 0.0])
        P = vec([K, 0.0, 0.0])
        A = vec([-1.0, 0.0, 0.0])
        Cp_v = 1.0
    else:
        P, Q, A = vec(), vec(), vec()
        Cp_v = r.choice([0.0, 0.5, c.fv(0, 8), 2.0])
    Bo = rnd(c, 8)
    Dp = rnd(c, 8)
    Cp = rnd(c, 8)
    e.wf32(Cp, Cp_v)
    E = vec()
    return [P, Q, A, Bo, Cp, Dp, E]


S(0x545690, 'Fn545690 (GUESS name)', 'fastcall', None, ret='al', gen=_gen, note='area50 batch857')
