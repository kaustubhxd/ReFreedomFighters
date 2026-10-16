"""specs_s66084.py - cascade s4 batch 66084: 0x4ddb20 (vector length / direction test with SSE and x87 arithmetic)."""
import struct
from pilot import S
from recruits_util import clear_hooks


def _fl(x):
    return struct.pack('<f', x)


def _g4ddb20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [0.0, 0.0, 0.5, 1.0, -1.0, 2.0, -3.0, 0.25, 7.5, float('nan'), float('inf')]
    e.wbytes(0x678858, _fl(r.choice([0.01, 1.0, 4.0, 1e-6])))
    e._image_dirty = True
    st = {'k': 0}
    seq = [[r.choice(vals) for _ in range(3)] for _ in range(4)]
    seq2 = [[r.choice([0.0, 0.5, 1.0, -1.0, 2.0, 1.5]) for _ in range(3)] for _ in range(4)]
    mode = r.random()
    thr = r.choice([1.0, 4.0, 0.25])
    e.wbytes(0x678858, _fl(thr))
    exact = None
    if r.random() < 0.3:
        exact = [0.0, 0.0, 0.0]
        exact[r.randrange(3)] = thr

    def h43e920(em, rr):                  # fastcall (ecx = out vec) + 1 stack arg (this) ret 4
        k = st['k']
        st['k'] += 1
        d = em.reg('ecx')
        em.calllog.append(('h43e920', em.arg32(0)))
        src = seq2 if mode < 0.5 else seq
        for j in range(3):
            em.wbytes(d + 4 * j, _fl(src[k % 4][j]))
        em.ret(eax=0, argbytes=4)

    def h441940(em, rr):                  # fastcall (ecx = vec, edx = this): adjust the vector in place
        d = em.reg('ecx')
        em.calllog.append(('h441940', em.reg('edx')))
        for j in range(3):
            x = struct.unpack('<f', bytes(em.rbytes(d + 4 * j, 4)))[0]
            if exact is not None:
                em.wbytes(d + 4 * j, _fl(exact[j]))
            else:
                em.wbytes(d + 4 * j, _fl(x + (0.25, 0.5, -0.125)[j]))
        em.ret(eax=0, argbytes=0)
    e.hook(0x43e920, h43e920)
    e.hook(0x441940, h441940)
    t = e.alloc(0x20, 8)
    pool = [0.0, 0.5, 1.0, -1.0, 2.0, 3.0, 0.1, 0.001]
    for j in range(3):
        e.wbytes(t + 4 * j, _fl(r.choice(pool if r.random() < 0.8 else vals)))
    if r.random() < 0.25:
        k = r.randrange(3)
        for j in range(3):
            e.wbytes(t + 4 * j, _fl({1.0: 1.0, 4.0: 2.0, 0.25: 0.5}[thr] if j == k else 0.0))
    return [t]


S(0x4ddb20, 'GUESS vector length and direction test', 'thiscall', None, ret='al', gen=_g4ddb20, note='batch66084')
