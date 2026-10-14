"""specs_s859.py - area 50, batch 859: 0x5434d0 (name GUESS), FASTCALL with three float stack args (ret 0xc), no result.
The helpers (0x43e920, 0x4e0d40, 0x451890, 0x443ef0) run as exe code; the CRT sqrt is the import slot 0x676330. The engine
object (0x70039c, vt +0x1c4, a logger that returns a float in ST0) gives three samples per loop round from a list fixed at
generation time (with (file, line) logged). Some cases start with A almost equal to B so that the sampling loop runs."""
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object
import struct


def struct_f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0
    samples = [r.uniform(-1.0, 1.0) for _ in range(96)]
    _sm = samples
    st = {'i': 0}

    def s1c4(e, rr):
        i = st['i']
        st['i'] += 1
        e.calllog.append(('eng.1c4', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8, st0=samples[i % len(samples)])

    only_hooks(c, {})
    eng = vt_object(c, 0x1b00, {0x1c4: s1c4}, nslots=0x100, name='engine')
    e.w32(0x70039c, eng)

    def vec(vals=None):
        a = rnd(c, 16)
        for i in range(3):
            e.wf32(a + 4 * i, vals[i] if vals else fin(c.fv(-3, 3)))
        return a

    K = struct_f32(1e-6)
    mode = r.choice(['rand', 'rand', 'rand', 'near', 'eqd', 'eqloop'])
    if mode == 'eqd':
        B = vec([0.0, 0.0, 0.0])
        A = vec([K, 0.0, 0.0])                   # d == 1e-6 exactly: the first test is not "greater"
    elif mode == 'eqloop':
        B = vec()
        A = vec([e.rf32(B + 4 * i) for i in range(3)])   # v == 0: the sampling loop runs, and its first sample has d == 1e-6
        samples[0:3] = [K, 0.0, 0.0]
    else:
        B = vec()
        if mode == 'near':
            A = vec([e.rf32(B + 4 * i) + r.uniform(-1e-7, 1e-7) for i in range(3)])
        else:
            A = vec()
    p1 = r.choice([0.5, 1.0, 2.0, fin(c.fv(0.1, 3.0))])
    p2 = r.choice([0.5, 1.0, fin(c.fv(0.1, 3.0))])
    p3 = r.choice([0.0, 0.25, fin(c.fv(-1, 2))])
    return [B, A, F(p1), F(p2), F(p3)]     # floats are pushed as floats only when wrapped in F


S(0x5434d0, 'Fn5434d0 (GUESS name)', 'fastcall', None, gen=_gen, note='area50 batch859')
