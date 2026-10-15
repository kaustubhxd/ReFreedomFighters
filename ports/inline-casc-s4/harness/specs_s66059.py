"""specs_s66059.py - cascade s4 batch 66059: 0x4bd720 (read a record from a stream)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g4bd720(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = {0x48: [0], 0x50: [0]}

    def mk(slot):
        def h(em, rr):
            p = em.arg32(0)
            k = cnt[slot][0]
            cnt[slot][0] += 1
            v = (slot << 20) | (k << 8) | r.getrandbits(8)
            em.calllog.append(('slot', slot, k, p if 0x20000000 <= p < 0x30000000 else 0))
            em.w32(p, v)
            em.ret(eax=0, argbytes=4)
        return e.stub_fn('s%x' % slot, h)
    s = obj(c, 0x80, {0x48: mk(0x48), 0x50: mk(0x50)})
    t = e.alloc(0x90, 4)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x90)))
    return [t, s]


S(0x4bd720, 'GUESS read a record from a stream (second)', 'thiscall', None, ret='al', gen=_g4bd720, note='batch66059')
