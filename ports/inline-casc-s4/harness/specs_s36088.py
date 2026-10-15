"""specs_s36088.py - cascade s4 batch 36088: 0x529d70 (read an object record from a stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g529d70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = {}

    def mk(slot, nargs):
        def h(em, rr):
            k = cnt.setdefault(slot, [0])
            kk = k[0]
            k[0] += 1
            p = em.arg32(0)
            em.calllog.append(('slot', slot, kk, p if 0x20000000 <= p < 0x30000000 else 0, em.arg32(1) if nargs > 1 else 0))
            v = (slot << 20) | (kk << 8) | r.getrandbits(8)
            em.w32(p, v)
            em.ret(eax=0, argbytes=4 * nargs)
        return e.stub_fn('s%x' % slot, h)
    s = obj(c, 0x80, {0x6c: mk(0x6c, 1), 0x18: mk(0x18, 2), 0x50: mk(0x50, 1), 0x40: mk(0x40, 1), 0x68: mk(0x68, 1)})
    hook_rec(c, 0x516d10, 1, this=True)
    objs = {}

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.setdefault(v, rnd(c, 8)), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    t = e.alloc(0x120, 4)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x120)))
    return [t, s]


S(0x529d70, 'GUESS read an object record from a stream', 'thiscall', None, ret='al', gen=_g529d70, note='batch36088')
