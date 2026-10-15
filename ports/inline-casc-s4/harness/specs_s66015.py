"""specs_s66015.py - cascade s4 batch 66015: 0x4f04e0 (read a named reference record from a stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4f04e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = {}

    def mk(slot, kind):
        def h(em, rr):
            k = cnt.setdefault(slot, [0])
            kk = k[0]
            k[0] += 1
            p = em.arg32(0)
            em.calllog.append(('slot', slot, kk, p if 0x20000000 <= p < 0x30000000 else 0))
            if kind == 'str':
                n = r.choice([0, 1, 3, 8])
                s = e.alloc(0x20, 4)
                e.wbytes(s, bytes(r.randrange(1, 255) for _ in range(n)) + b'\0')
                em.w32(p, s)
            else:
                em.w32(p, (slot << 20) | (kk << 8) | r.getrandbits(8))
            em.ret(eax=0, argbytes=4)
        return e.stub_fn('s%x' % slot, h)
    s = obj(c, 0x80, {0x48: mk(0x48, 'v'), 0x40: mk(0x40, 'v'), 0x60: mk(0x60, 'str')})
    hook_rec(c, 0x4f05d0, 1, this=True, ret=r.choice([0, 1, 0x100, 0x101, 0x2ff]))
    hook_rec(c, 0x634273, 2, pop=0)
    objs = {}

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.setdefault(v, rnd(c, 8)), 4)

    def alloc(em, rr):
        n = em.arg32(0)
        em.calllog.append(('alloc', n))
        em.ret(e.alloc(max(n, 8), 4), 4)
    so = sysobj(c, slots={0xf8: e.stub_fn('alloc', alloc), 0xfc: pystub(c, 1, this=True)}, table_slots={0x58: e.stub_fn('find', find)})
    t = e.alloc(0xb0, 4)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0xb0)))
    e.w32(t + 0x9b, r.choice([0, 0, rnd(c, 8)]))
    return [t, s]


S(0x4f04e0, 'GUESS read a named reference record from a stream', 'thiscall', None, ret='al', gen=_g4f04e0, note='batch66015')
