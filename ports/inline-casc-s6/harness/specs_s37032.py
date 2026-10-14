"""specs_s37032.py - cascade s6 batch 37032: 0x4e4050 (octree box node). 0x41e290 returns a spec node buffer; 0x4e3f60 hooked (records the 7-dword request, whose
first word is this+4). Coordinates: mostly in range, sometimes above 0xffff or negative so the clamp runs."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4e4050(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    node = rnd(c, 0x30)
    hook_rec(c, 0x41e290, 1, pop=0, ret=node)
    hook_rec(c, 0x4e3f60, 1, pop=4, deref={0: 7})
    me = rnd(c, 0x40)

    def coord():
        return r.choice([0, 1, 5, 100, 0x1000, 0xfffe, 0xffff, r.randrange(0x10000)])
    if r.random() < 0.15:
        v = []
        for _ in range(2):
            a, b = coord(), coord()
            v.append((min(a, b), max(a, b)))
        z0 = coord()
        args = [v[0][0], v[1][0], z0, v[0][1], v[1][1], r.choice([0x10000, 0x10001, 0xffffffff, 0x80000000, 0xffff, 0xfffe])]
    elif r.random() < 0.65:
        v = []
        for _ in range(3):
            a, b = coord(), coord()
            v.append((min(a, b), max(a, b)))
        args = [v[0][0], v[1][0], v[2][0], v[0][1], v[1][1], v[2][1]]
    else:
        args = [r.choice([coord(), 0x10000, 0x20000, r.getrandbits(32)]) for _ in range(5)]
        args.append(r.choice([coord(), 0x10000, 0xffffffff, 0x7fffffff, r.getrandbits(32)]))
        args = [a & 0xffffffff for a in args]
        # order: x0 y0 z0 x1 y1 z1
    return [me] + args + [r.getrandbits(32)]


S(0x4e4050, 'GUESS create octree box node', 'thiscall', None, ret='eax', gen=_g4e4050, note='batch37032')
