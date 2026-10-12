"""specs_s1016.py - unclaimed-04 batch 17 (docs/20-unclaimed-04.md): CEntityTracker builder 0x5c0500 (thiscall, no args).
The harness gives the builder a manager M (global 0x70039c, field +0x9b) whose field +0xadc is an object O with slot 0x25c
returning X1; X1+0x18 is S, with slots 0x14 (capacity N), 0x4c and 0x5c (a list of L nodes, with an out flag). The manager's
slot 0x58 maps a node to an entity E (or 0); E has slot 0x1e0 (a flag) and slot 0x80 (writes a position vector to dst
and 0 to out). qsort (IAT 0x676450) is a Python stub that sorts the records with the same comparator as 0x5bfdd0, so the
port and the exe get the same order. 0x41e290 is a zeroed-allocation hook. Out pointers are stack addresses (they differ
between the exe and the port), so the call logs carry only heap arguments. GUESS for all stubs' meanings."""
import functools
import struct

from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _setup(c):
    e = c.emu

    def alloc41(em, r):
        size = em.arg32(0)
        em.calllog.append(('41e290', 0, 0, (size,)))
        p = em.alloc(max(size, 4), 4)
        em.wbytes(p, bytes(max(size, 4)))
        em.ret(eax=p, argbytes=0)

    def qsort_stub(em, r):
        base, n, size, cmpf = em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)
        em.calllog.append(('qsort', 0, 0, (n, size, cmpf)))
        recs = [em.rbytes(base + i * size, size) for i in range(n)]

        def key(b):
            return struct.unpack('<f', b[4:8])[0]

        def cmp(a, b):
            return 1 if key(a) > key(b) else -1

        recs.sort(key=functools.cmp_to_key(cmp))
        for i, b in enumerate(recs):
            em.wbytes(base + i * size, b)
        em.ret(eax=0, argbytes=0)

    e.hook(0x41e290, alloc41)
    e.stub_import('qsort', qsort_stub)


def _args(c):
    e = c.emu
    L = c.rng.randrange(0, 7)
    N = c.rng.randrange(L, 9)
    G = _rnd(c, 0x100)
    e.w32(G + 0x40, c.rng.choice([0x1400, 0x1400 + c.rng.randrange(0, 400), c.rng.getrandbits(32)]))
    M = _rnd(c, 0x1000)
    e.w32(G + 0x9b, M)
    e.w32(0x70039c, G)
    X1 = _rnd(c, 0x40)
    Sx = _rnd(c, 0x40)
    e.w32(X1 + 0x18, Sx)
    O = _rnd(c, 0x40)
    e.w32(M + 0xadc, O)

    nodes = [_rnd(c, 0x20) for _ in range(L)]
    ent_of = {}
    ent_info = {}
    for Y in nodes:
        if c.rng.random() < 0.15:
            ent_of[Y] = 0
            continue
        E = _rnd(c, 0x80)
        e.w32(E + 0x54, 0 if c.rng.random() < 0.2 else 4)
        flag = c.rng.choice([0, 1, 1, 1])
        pos = (_f(c.rng.uniform(-100.0, 100.0)), _f(c.rng.uniform(-100.0, 100.0)), _f(c.rng.uniform(-100.0, 100.0)))
        ent_of[Y] = E
        ent_info[E] = (flag, pos)

    state = {'k': 0}

    def h25c(em, r):
        em.calllog.append(('O.25c', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=X1, argbytes=8)

    def h58(em, r):
        em.calllog.append(('M.58', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=ent_of.get(em.arg32(0), 0), argbytes=4)

    def h14(em, r):
        em.calllog.append(('S.14', 0, em.reg('ecx'), ()))
        em.ret(eax=N, argbytes=0)

    def h4c(em, r):
        em.calllog.append(('S.4c', 0, em.reg('ecx'), ()))
        em.w32(em.arg32(0), 1)
        em.ret(eax=0, argbytes=4)

    def h5c(em, r):
        k = state['k']
        state['k'] = k + 1
        em.calllog.append(('S.5c', 0, em.reg('ecx'), (k,)))
        em.w32(em.arg32(0), 1 if k < L else 0)
        em.ret(eax=nodes[k] if k < L else 0, argbytes=4)

    def h1e0(em, r):
        E = em.reg('ecx')
        em.calllog.append(('E.1e0', 0, E, (em.arg32(0),)))
        em.ret(eax=ent_info[E][0], argbytes=4)

    def h80(em, r):
        E = em.reg('ecx')
        em.calllog.append(('E.80', 0, E, (em.arg32(1),)))
        em.wbytes(em.arg32(1), struct.pack('<fff', *ent_info[E][1]))
        em.w32(em.arg32(0), 0)
        em.ret(eax=0, argbytes=8)

    e.w32(O, e.fake_vtable('O', 0x25c // 4 + 1, {0x25c: h25c}))
    e.w32(M, e.fake_vtable('M', 0x58 // 4 + 1, {0x58: h58}))
    e.w32(Sx, e.fake_vtable('S', 0x5c // 4 + 1, {0x14: h14, 0x4c: h4c, 0x5c: h5c}))
    ent_vt = e.fake_vtable('E', 0x1e0 // 4 + 1, {0x1e0: h1e0, 0x80: h80})  # slot 0x1e0 must be inside the table
    for E in ent_info:
        e.w32(E, ent_vt)
    tracker = _rnd(c, 0x800)
    return [tracker]


S(0x5c0500, 'CEntityTracker builder (unknown) thiscall', 'thiscall', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 17; qsort and 0x41e290 stubbed (GUESS); manager and entity slots are recording fakes')
