"""specs_s36087.py - cascade s4 batch 36087: 0x4f0190 (/GS-protected: build two transforms and dispatch them to child nodes)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4f0190(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def dw(em, p, n):
        return bytes(em.rbytes(p, 4 * n))

    def h1(em, rr):                       # 0x43e8e0: ecx = &A, edx = b, [esp+4] = x (callee pops 4)
        a = em.reg('ecx')
        em.calllog.append(('h1', em.reg('edx'), em.arg32(0)))
        for i in range(3):
            em.w32(a + 4 * i, (em.reg('edx') + 0x11 * (i + 1)) & 0xffffffff)
        em.ret(eax=0, argbytes=4)

    def h2(em, rr):                       # 0x4419f0: ecx = &A, edx = o (fastcall, plain ret)
        a = em.reg('ecx')
        em.calllog.append(('h2', em.reg('edx'), dw(em, a, 3)))
        for i in range(3):
            em.w32(a + 4 * i, (em.r32(a + 4 * i) ^ em.reg('edx') ^ (i + 7)) & 0xffffffff)
        em.ret(eax=0, argbytes=0)

    def h3(em, rr):                       # 0x4de440: ecx = &B, edx = c, [esp+4] = x (callee pops 4)
        b = em.reg('ecx')
        em.calllog.append(('h3', em.reg('edx'), em.arg32(0)))
        for i in range(9):
            em.w32(b + 4 * i, (em.reg('edx') * 3 + em.arg32(0) + i) & 0xffffffff)
        em.ret(eax=0, argbytes=4)
    e.hook(0x43e8e0, h1)
    e.hook(0x4419f0, h2)
    e.hook(0x4de440, h3)
    # child objects: slot 0x1e0 (flag test, 1 arg), 0x2cc / 0x22c (a, &A, &B)
    def mkchild():
        flags = {0x10002e: r.choice([0, 1, 1, 0x100, 0x1ff]), 0x20002c: r.choice([0, 1, 1, 0x100])}

        def tst(em, rr):
            k = em.arg32(0)
            em.calllog.append(('test', k))
            em.ret(eax=flags.get(k, 0), argbytes=4)

        def disp(name):
            def h(em, rr):
                em.calllog.append((name, em.arg32(0), dw(em, em.arg32(1), 3), dw(em, em.arg32(2), 9)))
                em.ret(eax=0, argbytes=12)
            return e.stub_fn(name, h)
        ch = obj(c, 0x40, {0x1e0: e.stub_fn('test', tst), 0x2cc: disp('d2cc'), 0x22c: disp('d22c')})
        e.w32(ch + 0x30, r.choice([0, 0x400, 0x401, 0x7ff]))
        return ch
    n = r.choice([0, 1, 2, 3, 4])
    nodes = []
    for i in range(n):
        nd = e.alloc(0x70, 4)
        e.w32(nd + 0x3c, r.choice([0, 0, 0x400, 0x800, 0x1, 0xc00, 0x200]))
        e.w32(nd + 0x54, 0 if r.random() < 0.15 else mkchild())
        nodes.append(nd)
    for i, nd in enumerate(nodes):
        e.w32(nd + 0x60, nodes[i + 1] if i + 1 < n else 0)
    me = obj(c, 0x80, {})
    e.w32(me + 8, rnd(c, 0x30))
    e.w32(me + 0x50, nodes[0] if nodes else 0)
    return [me, r.getrandbits(32) | 1, r.getrandbits(32), r.getrandbits(32)]


S(0x4f0190, 'GUESS /GS dispatch of two transforms to child nodes', 'thiscall', None, ret=None, gen=_g4f0190, note='batch36087')
