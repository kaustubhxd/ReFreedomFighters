"""specs_s889.py - area 50, batch 889: 0x47aad0 (GUESS name Remove47aad0), thiscall, two stack args (value, object), ret 8, void.
The list at this+4 (records of 8: object K at +0, value V at +4; count at +0x50). Stand-ins: K's and a2's slot 0x20 (return
sub-objects whose +4 is a name, or null); the logger is installed after only_hooks; the sink's printf logs its words.
Cases: a1 is one of the values or not; the record found by a1 has K == a2 or not (the removal and both printf shapes run)."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    # the two printf shapes differ in argument count (five words on the removal-miss path, four otherwise), so the sink
    # logs five words only for the format of the five-argument call
    def sinkp(e, rr):
        nw = 5 if e.arg32(1) == 0x68a7f0 else 4
        e.calllog.append(('log.printf',) + tuple(e.arg32(k) for k in range(nw)))
        e.ret(eax=0, argbytes=0)

    def logw(e, rr):
        e.calllog.append(('log.where', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=sink_obj, argbytes=8)

    sink_obj = e.fake_object('sink', 0x10, nslots=12, slots={0x2c: sinkp})
    logger_obj = e.fake_object('logger', 0x10, nslots=9, slots={0x20: logw})
    e.w32(0x700390, logger_obj)

    def name_obj(tag):
        o = rnd(c, 0x40)
        e.w32(o + 4, e.cstr(r.choice(['alpha', 'beta', 'g'])) if r.random() < 0.6 else 0)
        return o

    def mk_k(i):
        X = name_obj('X%d' % i)

        def h20(e, rr, X=X, i=i):
            e.calllog.append(('K.20', i))
            e.ret(eax=X, argbytes=0)
        K = rnd(c, 0x40)
        e.w32(K, e.fake_vtable('K%d' % i, 0x20, {0x20: h20}))
        return K

    n = r.randint(0, 4)
    Ks = [mk_k(i) for i in range(n)]
    Vs = [r.getrandbits(32) | 0x10 for _ in range(n)]
    Y = name_obj('Y')

    def ha20(e, rr):
        e.calllog.append(('a2.20',))
        e.ret(eax=Y, argbytes=0)
    a2 = rnd(c, 0x40)
    e.w32(a2, e.fake_vtable('a2', 0x20, {0x20: ha20}))

    self = rnd(c, 0x200)
    e.w32(self + 0x50, n)
    for i in range(n):
        e.w32(self + 4 + 8 * i, Vs[i])
        e.w32(self + 8 * i, Ks[i])
    if n and r.random() < 0.6:
        j = r.randrange(n)
        a1 = Vs[j]
        if r.random() < 0.5:
            e.w32(self + 8 * j, a2)          # the record found by a1 has K == a2: removal path
    else:
        a1 = r.getrandbits(32) | 0x20         # not found: the logger path
    return [self, a1, a2]


S(0x47aad0, 'Remove47aad0 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch889')
