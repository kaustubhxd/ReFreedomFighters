"""specs_s66070.py - cascade s4 batch 66070: 0x4f0690 (load a record table with pointer fixups from a stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g4f0690(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 3])
    m = r.choice([0, 1, 2, 4])
    vals = [n, m]
    cnt = {'k': 0}

    def s40(em, rr):                      # s->slot 0x40 (&out) ret 4
        k = cnt['k']
        cnt['k'] += 1
        p = em.arg32(0)
        em.calllog.append(('s40', k, p))
        em.w32(p, vals[min(k, 1)])
        em.ret(eax=0, argbytes=4)

    def s18(em, rr):                      # s->slot 6 (ptr, size) ret 8
        p, sz = em.arg32(0), em.arg32(1)
        em.calllog.append(('s18', p, sz))
        em.wbytes(p, bytes(((p + i) * 7 + 3) & 0x0f for i in range(sz)))
        em.ret(eax=0, argbytes=8)
    s = obj(c, 0x30, {0x40: e.stub_fn('s40', s40), 0x18: e.stub_fn('s18', s18)})

    def mk(name):
        def h(em, rr):
            sz = em.arg32(0)
            em.calllog.append((name, sz))
            em.ret(eax=e.alloc(max(min(sz * 40, 0x400), 32), 8), argbytes=4)
        return e.stub_fn(name, h)
    pool = obj(c, 0x40, {0x2c: mk('p2c'), 0x38: mk('p38'), 0x34: mk('p34')})
    holder = e.alloc(0x40, 8)
    e.w32(holder + 0x18, pool)
    so = sysobj(c)
    e.wbytes(so + 0x1aa3, holder.to_bytes(4, 'little'))
    t = obj(c, 0x100, {0x228: pystub(c, 0, this=True)})
    e.wbytes(t + 0x91, bytes([r.choice([0, 7])]))
    return [t, s]


S(0x4f0690, 'GUESS load a record table with pointer fixups from a stream', 'thiscall', None, ret=None, gen=_g4f0690, note='batch66070')
