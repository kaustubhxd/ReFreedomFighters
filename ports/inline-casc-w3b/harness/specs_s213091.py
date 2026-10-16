"""specs_s213091.py - batch 213091: triangle list proximity test with two in-place transforms, Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g49b9a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fl():
        return r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 2.0, 3.0, r.uniform(-2, 2), r.uniform(-2, 2), NAN])

    def vec3():
        return (fl(), fl(), fl())

    def tri():
        a, b, cc = vec3(), vec3(), vec3()
        x = r.random()
        if x < 0.12:
            b = a
        elif x < 0.24:
            cc = b
        elif x < 0.36:
            cc = a
        elif x < 0.40:
            b = (a[0], a[1], r.choice([a[2], -a[2], 5.0]))
        return a, b, cc
    items = []
    for _ in range(r.choice([0, 1, 2, 3, 4, 5])):
        p = rnd(c, 0x30)
        a, b, cc = tri()
        e.wbytes(p + 4, struct.pack('<9f', *(a + b + cc)))
        items.append(p)
    state = {'i': 0}

    def l4c(emu, rr):
        state['i'] = 0
        emu.calllog.append(('l4c',))
        emu.ret(eax=r.getrandbits(32), argbytes=4)

    def l64(emu, rr):
        i = state['i']
        state['i'] += 1
        it = items[i] if i < len(items) else 0
        emu.calllog.append(('l64', it))
        emu.ret(eax=it, argbytes=4)
    L = obj(c, 0x20, {0x4c: e.stub_fn('l4c', l4c), 0x64: e.stub_fn('l64', l64)}, nslots=0x40)
    M = rnd(c, 0x20)
    N = rnd(c, 0x20)

    def pv():
        return struct.pack('<fff', *[r.choice([0.0, 0.3, -0.3, 1.0, 5.0, r.uniform(-3, 3), r.uniform(-1, 1), NAN]) for _ in range(3)])

    rv = r.choice([0.5, 1.0, 2.0, 0.0, 3.0, r.uniform(0, 3), -1.0, NAN])
    exact_k = r.choice([None, None, 0, 1, 2])
    cnt2 = [0]

    def mk(tag):
        def side(emu, k):
            emu.calllog.append((tag, emu.reg('edx'), bytes(emu.rbytes(emu.reg('ecx'), 12))))
            if tag == 't2' and exact_k is not None and rv == rv and rv >= 0:
                j = cnt2[0] % 3
                cnt2[0] += 1
                emu.wbytes(emu.reg('ecx'), struct.pack('<fff', rv if j == exact_k else 100.0, 0.0, 0.0))
            else:
                emu.wbytes(emu.reg('ecx'), pv())
        return side
    hook_rec(c, 0x4419f0, 0, pop=0, side=mk('t1'))
    hook_rec(c, 0x441940, 0, pop=0, side=mk('t2'))
    return [M, N, F(rv), 0 if r.random() < 0.1 else L]


S(0x49b9a0, 'triangle_list_near', 'fastcall', None, ret='al', gen=g49b9a0)
