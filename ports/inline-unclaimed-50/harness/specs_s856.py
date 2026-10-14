"""specs_s856.py - area 50, batch 856: 0x558150 (name GUESS), thiscall, one stack arg, ret 4.
Stand-ins (hooked, logged): the accessor 0x5003d0 (returns the address of a dword holding the key), the pair call 0x55eae0.
The import slot 0x67644c (rand) is a stub returning a generation-time value. The engine manager (+0x9b, vt +0x58) maps the key
to object B (or to Q, the entry found through B+0x18's vt +0x30), or to nothing. B+0x18 (O) gives a count (vt +0x14) and an
index value (vt +0x30); Q fills two arrays (vt +0x80) and answers vt +0x1e0. this+0x1c (F) answers vt +0x20 with an object E
(its dword at +4 is printed on the failure path) and takes the two arrays (vt +0x370). The engine logger's sink has vt +0x30
(cdecl, printf-like), logged."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0
    K1 = r.getrandbits(32) | 1          # the accessor's key: maps to B
    K2 = r.getrandbits(32) | 2          # the index value that maps to Q (success)
    N = r.randint(1, 4)
    rnd_r = r.randint(0, 1000)
    v_idx = K2 if r.random() < 0.6 else (r.getrandbits(32) | 4)
    flag = r.random() < 0.7
    vals9 = [fin(c.fv(-4, 4)) for _ in range(9)]
    vals3 = [fin(c.fv(-4, 4)) for _ in range(3)]

    def acc(e, rr):
        e.calllog.append(('acc.5003d0', e.arg32(0)))
        e.ret(eax=keyp, argbytes=4)

    def arrs(p, n):
        return [repr(e.rf32(p + 4 * i)) for i in range(n)]    # contents, not the frame addresses

    def pair(e, rr):
        q, a, b = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('pair.55eae0', e.reg('ecx'), q, arrs(a, 9), arrs(b, 3)))
        e.ret(eax=0, argbytes=12)

    def mgr58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('mgr.58', k))
        e.ret(eax=(B if k == K1 else Q if k == K2 else 0), argbytes=4)

    def o14(e, rr):
        e.calllog.append(('O.14',))
        e.ret(eax=N, argbytes=0)

    def o30(e, rr):
        e.calllog.append(('O.30', e.arg32(0)))
        e.ret(eax=v_idx, argbytes=4)

    def q80(e, rr):
        p34, p10 = e.arg32(0), e.arg32(1)
        for i in range(9):
            e.wf32(p34 + 4 * i, vals9[i])
        for i in range(3):
            e.wf32(p10 + 4 * i, vals3[i])
        e.calllog.append(('Q.80',))
        e.ret(eax=0, argbytes=8)

    def q1e0(e, rr):
        e.calllog.append(('Q.1e0', e.arg32(0)))
        e.ret(eax=1 if flag else 0, argbytes=4)

    def f20(e, rr):
        e.calllog.append(('F.20',))
        e.ret(eax=E, argbytes=0)

    def f370(e, rr):
        a, b = e.arg32(0), e.arg32(1)
        e.calllog.append(('F.370', arrs(a, 9), arrs(b, 3)))
        e.ret(eax=0, argbytes=8)

    def rand_stub(e, rr):
        e.calllog.append(('rand',))
        e.ret(eax=rnd_r, argbytes=0)

    def sink30(e, rr):
        e.calllog.append(('sink.30', e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=0)                       # cdecl: the caller pops its three words

    def logger20(e, rr):
        e.calllog.append(('log.20', e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)

    only_hooks(c, {0x5003d0: acc, 0x55eae0: pair})
    e.stub_import('rand', rand_stub)
    sink = e.fake_object('sink', 0x10, nslots=0x20, slots={0x30: sink30})
    logger = e.fake_object('logger', 0x10, nslots=9, slots={0x20: logger20})
    e.w32(0x700390, logger)

    keyp = rnd(c, 8)
    e.w32(keyp, K1)
    O = vt_object(c, 0x40, {0x14: o14, 0x30: o30}, nslots=0x20, name='O')
    B = vt_object(c, 0x40, {}, nslots=0x20, name='B')
    e.w32(B + 0x18, O)
    Q = vt_object(c, 0x40, {0x80: q80, 0x1e0: q1e0}, nslots=0x100, name='Q')
    E = vt_object(c, 0x40, {}, nslots=0x20, name='E')
    e.w32(E + 4, r.getrandbits(32))
    F = vt_object(c, 0x40, {0x20: f20, 0x370: f370}, nslots=0x200, name='F')
    mgr = vt_object(c, 0x40, {0x58: mgr58}, nslots=0x60, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    rec = rnd(c, 0x40)
    e.w32(rec + 4, rnd(c, 0x40))
    self = rnd(c, 0x40)
    e.w32(self + 0x1c, F)
    return [self, rec]


S(0x558150, 'Fn558150 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch856')
