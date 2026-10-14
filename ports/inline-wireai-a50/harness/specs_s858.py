"""specs_s858.py - area 50, batch 858: 0x43f610 (name GUESS), thiscall, three stack args (ret 0xc), bool.
The range and transform helpers (0x4de7a0, 0x4df330, 0x441a60, 0x4de4b0, 0x43e920) are exe code: pure math, run as they are.
Stood in (vt calls on fake objects, logged): the container at this+0x44 (vt +0x4c, +0x5c with a flag and an id, +0x44), the
engine manager's vt +0x58 (id to entry), and the entry's vt +0x188 (iterator, point, c). The iterator and the point are
logged by content (their addresses differ between the runs)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    _f = lambda x: x if x == x and abs(x) < 1e6 else 0.0
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0
    n = r.randint(0, 3)
    ids = [r.getrandbits(32) | 1 for _ in range(n)]
    st = {'i': 0}
    keep = set(i for i in ids if r.random() < 0.6)
    ents = {}
    res = [r.random() < 0.4 for _ in range(12)]
    cnt = {'k': 0}

    def fl(p, k):
        return [repr(e.rf32(p + 4 * i)) for i in range(k)]

    def o4c(e, rr):
        e.calllog.append(('O.4c',))
        e.w32(e.arg32(0), 1)
        e.ret(eax=0, argbytes=4)

    def o5c(e, rr):
        p = e.arg32(0)
        if st['i'] < len(ids):
            v = ids[st['i']]
            st['i'] += 1
            e.w32(p, 1)
            e.calllog.append(('O.5c', v))
            e.ret(eax=v, argbytes=4)
        else:
            e.w32(p, 0)
            e.calllog.append(('O.5c', 0))
            e.ret(eax=0, argbytes=4)

    def o44(e, rr):
        e.calllog.append(('O.44',))
        e.w32(e.arg32(0), 1)
        e.ret(eax=0, argbytes=4)

    def m58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('mgr.58', k))
        e.ret(eax=ents.get(k, 0), argbytes=4)

    def v188(e, rr):
        it, p, cv = e.arg32(0), e.arg32(1), e.arg32(2)
        cnt['k'] += 1
        e.calllog.append(('S.188', fl(it, 9), fl(p, 3), fl(cv, 3)))
        e.ret(eax=1 if res[cnt['k'] % len(res)] else 0, argbytes=12)

    only_hooks(c, {})
    O = vt_object(c, 0x40, {0x4c: o4c, 0x5c: o5c, 0x44: o44}, nslots=0x100, name='container')
    mgr = vt_object(c, 0x40, {0x58: m58}, nslots=0x60, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    for k in ids:
        if k in keep or r.random() < 0.3:
            s = vt_object(c, 0x40, {0x188: v188}, nslots=0x100, name='S')
            sub = rnd(c, 0x80)
            for i in range(0x20):
                e.wf32(sub + 4 * i, fin(c.fv(-2, 2)))
            e.w32(s + 8, sub)
            ents[k] = s
    self = rnd(c, 0x100)
    scale = r.choice([2000.0, 20000.0])     # the range scale: large ranges let the test pass often
    for off in range(0x18, 0x30, 4):
        e.wf32(self + off, fin(c.fv(-1, 1)) * scale)
    e.wf32(self + 0x18, 50.0 * scale)
    for off in (0x1c, 0x20, 0x28, 0x2c):
        e.wf32(self + off, 40.0 * scale)                 # a large positive first block
    e.w32(self + 0x44, O if r.random() < 0.9 else 0)      # no container: the test passes with no entry
    a = rnd(c, 0x40)
    b = rnd(c, 0x40)
    small = True
    for i in range(3):
        e.wf32(a + 4 * i, fin(c.fv(-2, 2)) * (0.01 if small else 1.0))
        # b sits near the range's second block (self+0x24): the point is then inside the box more often
        e.wf32(b + 4 * i, _f(e.rf32(self + 0x24 + 4 * i) + r.uniform(-0.05, 0.05)))
    cv = rnd(c, 16)                                   # c is a vector pointer too (the range test reads it)
    for i in range(3):
        e.wf32(cv + 4 * i, fin(c.fv(-2, 2)) * (0.01 if small else 1.0))
    return [self, a, b, cv]


S(0x43f610, 'Walk43f610 (GUESS name)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch858')
