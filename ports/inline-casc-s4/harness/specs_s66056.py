"""specs_s66056.py - cascade s4 batch 66056: 0x401350 (read and validate a bit-packed stream header)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g401350(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [r.choice([0, 0, 0, 5]), r.choice([0, 1, 8, 0xfe, 0x80000001]), r.choice([0, 1, 100, 0x80000000]), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32),
            r.choice([2, 3, 4, 5, 6, 0x13]), r.choice([2, 3, 4, 5, 8, 0x14, 0x1f, 0x1f]), r.choice([0, 1, 1, 1, 2])]
    st = {'k': 0}

    def bits(em, rr):                     # 0x410de0 (stream, n) cdecl
        k = st['k']
        st['k'] += 1
        em.calllog.append(('bits', em.arg32(0), em.arg32(1)))
        em.ret(eax=vals[min(k, 8)], argbytes=0)
    e.hook(0x410de0, bits)
    hook_rec(c, 0x4010c0, 1, pop=0)
    a = e.alloc(0x40, 8)
    e.wbytes(a, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(a + 0x1c, 0 if r.random() < 0.1 else e.alloc(0x10, 8))
    return [a, rnd(c, 8)]


S(0x401350, 'GUESS read and validate a bit-packed stream header', 'cdecl', None, ret='eax', gen=_g401350, note='batch66056')
