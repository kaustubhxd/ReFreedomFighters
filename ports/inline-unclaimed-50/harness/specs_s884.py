"""specs_s884.py - area 50, batch 884: 0x59e3d0 (GUESS name Walk59e3d0), thiscall, no stack args, void. SEH frame and the stack
cookie check are not reproduced. Stand-ins (hooked, logged): 0x58b930, 0x477ff0, 0x59db90, 0x5a0290 (no args), 0x4cbec0 (dtor).
Real exe code runs for 0x4e0830 (squared distance) and 0x4cc1d0 (mov eax,[ecx]; ret). The logger (install_logger, four words)
receives the printf of the pair. Objects: this (vt: +0x20 -> X, +0x1d8 -> a sub-object), X (vt +0x20 -> the list head B), list
nodes (vt +0x20 -> next, +0x1d8 -> a sub-object; node+8 points to a vector at +0x24, random so both branches run), the manager's
+0xadc object M (vt +0x25c -> E or 0), E (vt +0x100 -> a flag value, +0x10c -> R2), R2 (vt +0x8, +0x4c, +0x54; flags at +4).
Pointers from the sub-objects are not logged; their identities are logged by label."""
from pilot import S
from anim_common import only_hooks, rnd, install_logger


def _gen(c):
    e, r = c.emu, c.rng
    labels = {}
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0

    def lg(name, nargs):
        def h(e, rr):
            ecx = e.reg('ecx')
            e.calllog.append((name, labels.get(ecx, 'other')) + tuple(e.arg32(k) for k in range(nargs)))
            e.ret(eax=0, argbytes=4 * nargs)
        return h

    only_hooks(c, {0x58b930: lg('h.58b930', 0), 0x477ff0: lg('h.477ff0', 0), 0x59db90: lg('h.59db90', 0),
                   0x5a0290: lg('h.5a0290', 0), 0x4cbec0: lg('h.4cbec0', 0)})
    install_logger(c, nargs=4)          # after only_hooks: only_hooks restores the globals it knows about (0x700390 among them)

    R2 = rnd(c, 0x40)
    R2_flags = r.getrandbits(32)
    e.w32(R2 + 4, R2_flags)
    e.w32(R2 + 0x30, r.getrandbits(32))
    R2vt = e.fake_vtable('R2', 0x40, {
        0x8: lambda e, rr: (e.calllog.append(('R2.8',)), e.ret(eax=0, argbytes=0)),
        0x4c: lambda e, rr: (e.calllog.append(('R2.4c',)), e.ret(eax=0, argbytes=0)),
        0x54: lambda e, rr: (e.calllog.append(('R2.54', e.arg32(0))), e.ret(eax=0, argbytes=4)),
    })
    e.w32(R2, R2vt)
    labels[R2] = 'R2'

    r100 = r.choice([0, r.getrandbits(32) | 1])
    E = rnd(c, 0x40)
    Evt = e.fake_vtable('E', 0x80, {
        0x100: lambda e, rr: (e.calllog.append(('E.100', e.arg32(0))), e.ret(eax=r100, argbytes=4)),
        0x10c: lambda e, rr: (e.calllog.append(('E.10c', e.arg32(0), e.arg32(1))), e.ret(eax=R2, argbytes=8)),
    })
    e.w32(E, Evt)
    labels[E] = 'E'

    Mret = E if r.random() < 0.8 else 0
    M = rnd(c, 0x40)
    Mvt = e.fake_vtable('M', 0x100, {
        0x25c: lambda e, rr: (e.calllog.append(('M.25c', e.arg32(0), e.arg32(1))), e.ret(eax=Mret, argbytes=8)),
    })
    e.w32(M, Mvt)
    labels[M] = 'M'
    mgr = rnd(c, 0x1000)
    e.w32(mgr + 0xadc, M)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)

    # list: nodes built with their vtables after their addresses are known
    nn = r.randint(0, 3)
    nodes = [rnd(c, 0x40) for _ in range(nn)]
    subs = [rnd(c, 0x40) for _ in range(nn)]
    vecs = []
    for i, nd in enumerate(nodes):
        vec = rnd(c, 0x40)
        if i == 0 and r.random() < 0.5:
            comps = [2.0 ** -7, 2.0 ** -7, 0.0]     # squared distance 2**-13 == the threshold: the equality boundary
        else:
            comps = [fin(r.uniform(-12.0, 12.0)) for _ in range(3)]
        for k in range(3):
            e.wf32(vec + 0x24 + 4 * k, comps[k])
        e.w32(nd + 8, vec)
        labels[nd] = 'N%d' % i
        labels[subs[i]] = 'Q%d' % i
        nxt = nodes[i + 1] if i + 1 < nn else 0
        def n20(e, rr, nxt=nxt, nm='N%d' % i):
            e.calllog.append(('N.20', nm))
            e.ret(eax=nxt, argbytes=0)
        def n1d8(e, rr, sub=subs[i], nm='N%d' % i):
            e.calllog.append(('N.1d8', nm, e.arg32(1)))
            e.ret(eax=sub, argbytes=8)
        nvt = e.fake_vtable('N%d' % i, 0x100, {0x20: n20, 0x1d8: n1d8})
        e.w32(nd, nvt)
        e.w32(subs[i] , r.getrandbits(32))
    B = nodes[0] if nn else 0

    X = rnd(c, 0x40)
    Xvt = e.fake_vtable('X', 0x40, {0x20: lambda e, rr: (e.calllog.append(('X.20',)), e.ret(eax=B, argbytes=0))})
    e.w32(X, Xvt)
    labels[X] = 'X'

    self = rnd(c, 0x1000)
    S2 = rnd(c, 0x40)
    e.w32(S2, r.getrandbits(32))
    svt = e.fake_vtable('self', 0x100, {
        0x20: lambda e, rr: (e.calllog.append(('self.20',)), e.ret(eax=X, argbytes=0)),
        0x1d8: lambda e, rr: (e.calllog.append(('self.1d8', e.arg32(1))), e.ret(eax=S2, argbytes=8)),
    })
    e.w32(self, svt)
    labels[self] = 'self'
    e.w32(self + 0x788, 0)
    return [self]


S(0x59e3d0, 'Walk59e3d0 (GUESS name; SEH frame and cookie not reproduced)', 'thiscall', None, gen=_gen, note='area50 batch884')
