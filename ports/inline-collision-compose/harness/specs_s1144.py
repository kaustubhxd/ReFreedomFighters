"""specs_s1144.py - collision thread batch 1144 (GUESS name): 0x43fb00. Fakes: holder (slot 0x274, one argument, logged); A (slot
0x20 is called twice: first with no arguments, returns 1; then with two arguments, returns a per-case value; slot 0x1b8 with five
arguments, returns a per-case value, logged); C (slot 0x25c: the first call returns the head node, later calls return the
argument (the next node) so the chain is followed; the head chain is forward-only and ends in zero). The 0x20 fake pops by its
call count (0 or 8 bytes)."""
import struct
from pilot import S, F


def _find(c):
    e, r = c.emu, c.rng
    # nodes: flags at +0x30, next at +8; forward-only chain of 1..4
    n = r.randrange(1, 5)
    nodes = [e.alloc(0x40, 16) for _ in range(n)]
    for i, nd in enumerate(nodes):
        e.wbytes(nd, bytes(r.getrandbits(8) for _ in range(0x40)))
        fl = r.getrandbits(32)
        fl = (fl | 0x800) if r.random() < 0.6 else (fl & ~0x800)
        e.w32(nd + 0x30, fl)
        e.w32(nd + 8, nodes[i + 1] if i + 1 < n else 0)
    head = nodes[0] if r.random() < 0.9 else 0

    calls20 = [0]
    r1v = r.getrandbits(32)
    r1000 = r.getrandbits(32)

    def a20(em, rr):
        k = calls20[0]
        calls20[0] += 1
        if k == 0:
            em.ret(eax=1, argbytes=0)               # first call: no arguments; nonzero, so the lookup goes on
        else:
            em.calllog.append(('a20', em.arg32(0), em.arg32(1)))
            em.ret(eax=r1v, argbytes=8)

    def a1b8(em, rr):
        em.calllog.append(('1b8', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4)))
        em.ret(eax=r1000, argbytes=20)

    avt = e.fake_vtable('A_43fb00', 0x70, {0x20: a20, 0x1b8: a1b8})
    A = e.alloc(0x20, 4)
    e.w32(A, avt)
    e.w32(A + 4, r.choice([0, 0x20000100]))                   # the string (default when zero)

    lookups = [0]

    def c25c(em, rr):
        k = lookups[0]
        lookups[0] += 1
        em.calllog.append(('25c', em.arg32(0), k == 0))
        if k == 0:
            em.ret(eax=head, argbytes=8)
        else:
            em.ret(eax=em.arg32(1), argbytes=8)

    cvt = e.fake_vtable('C_43fb00', 0x100, {0x25c: c25c})
    C = e.alloc(0x20, 4)
    e.w32(C, cvt)
    argB = e.alloc(8, 4)
    e.w32(argB, C)

    def h274(em, rr):
        em.calllog.append(('274', em.arg32(0)))
        em.ret(argbytes=4)

    hvt = e.fake_vtable('holder_43fb00', 0x9f, {0x274: h274})
    holder = e.alloc(0x40, 4)
    e.w32(holder, hvt)
    return [holder, A, argB, r.getrandbits(32)]


S(0x43fb00, 'slot 0x20 check, lookup chain on the 0x25c object with flag 0x800, fallback slot 0x1b8 (name GUESS)', 'thiscall',
  None, ret='eax', gen=_find, note='batch1144')
