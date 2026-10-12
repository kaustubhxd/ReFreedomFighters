"""specs_s6225.py - unclaimed-62 claim 18 (larger, 103 instructions): 0x4bb6b0 (thiscall, one argument; returns al). The engine's message
table (eng+0x9b) has its +0xadc object set to the argument in about a third of the cases, and its slot 0x58 answers with the argument (a match)
or a random word. Sub-objects A (this+0xf4) and B (this+0x48) are logged vtable objects: slot 0x14 gives a signed value, slots 0x4c and 0x5c write
the &loc word through their argument (a counter bounds the walk, so each walk ends) and 0x5c returns a word. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _x(c):
    e = c.emu
    r = c.rng
    arg = r.getrandbits(32) if r.random() < 0.8 else 0
    if r.random() < 0.1:
        arg = 0
    msg = e.alloc(0xb00)
    eng = e.alloc(0x1000)
    e.w32(eng + 0x9b, msg)
    e.w32(0x70039c, eng)
    e.w32(msg + 0xadc, arg if r.random() < 0.35 else r.getrandbits(32))
    walks = [r.randint(0, 3), r.randint(0, 3)]
    counts = [0, 0]

    def sub(idx, v14):
        def loc_set(em, a):
            counts[idx] += 1
            em.w32(a[0], 1 if counts[idx] <= walks[idx] else 0)
            return 0
        def ret5c(em, a):
            counts[idx] += 0
            em.w32(a[0], 1 if counts[idx] < walks[idx] else 0)
            counts[idx] += 1
            return r.getrandbits(32)
        # the exe's sub-objects are embedded: their vtable pointer sits at this+0xf4 / this+0x48 itself
        return vtable(c, 'sub4bb%d' % idx, 0x100, impl={0x14: lambda em, a: v14, 0x4c: loc_set, 0x5c: ret5c},
                      argwords={0x14: 0, 0x4c: 1, 0x5c: 1})

    rec = rnd(c, 0x1000)
    vA = r.randint(-20, 20) & 0xffffffff
    vB = r.randint(-20, 20) & 0xffffffff
    e.w32(rec + 0xf4, sub(0, vA))
    e.w32(rec + 0x48, sub(1, vB))
    msgval = [arg if r.random() < 0.3 else r.getrandbits(32) for _ in range(4)]
    e.w32(msg, vtable(c, 'msg4bb', 0x80, impl={0x58: lambda em, a: msgval[len(em.calllog) % 4]}, argwords={0x58: 1}))
    return [rec, arg]


S(0x4bb6b0, 'unnamed 0x4bb6b0', 'thiscall', None, ret='al', gen=_x, n=300)
