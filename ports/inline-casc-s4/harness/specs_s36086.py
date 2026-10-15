"""specs_s36086.py - cascade s4 batch 36086: 0x4d4300 (store a name copy and find its prefix match in a string list)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g4d4300(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4])
    found = r.choice([-1, -1, 0, 1, 2, 3])
    cn = [0]

    def sc(em, res):
        k = cn[0]
        cn[0] += 1
        em.calllog.append(('nicmp', bytes(em.rbytes(em.arg32(0), 8)), em.arg32(1), em.arg32(2)))
        em.ret(eax=(0 if k == found else r.choice([-1, 1, 0x100])), argbytes=0)
    e.stub_import('_strnicmp', sc)
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: e.alloc(0x40, 4))
    arr = e.alloc(4 * 5, 4)
    for i in range(n):
        s = e.alloc(0x10, 4)
        e.wbytes(s, bytes(r.randrange(1, 255) for _ in range(r.choice([0, 1, 3]))) + b'\0')
        e.w32(arr + 4 * i, s)
    t = rnd(c, 0x20)
    e.w32(t + 4, arr)
    e.w32(t + 8, n)
    e.w32(t + 0xc, 0 if r.random() < 0.5 else e.alloc(0x10, 4))
    e.w32(t + 0x10, r.getrandbits(32))
    if r.random() < 0.15:
        sp = 0
    else:
        sp = e.alloc(0x20, 4)
        e.wbytes(sp, bytes(r.randrange(1, 255) for _ in range(r.choice([0, 1, 2, 5, 9]))) + b'\0')
    return [t, sp]


S(0x4d4300, 'GUESS store a name copy and find a prefix match in a list', 'thiscall', None, ret='eax', gen=_g4d4300, note='batch36086')
