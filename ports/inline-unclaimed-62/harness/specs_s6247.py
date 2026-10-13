"""specs_s6247.py - ragdoll side (claim 40): 0x644820 (Load2; thiscall, no argument; the name map gives CRagdoll2::Load2 and ZRagdollContainer::Load2
for this address). The record has a count in 0..3 (entries of 0x1df bytes at +0x25), and one entry at +0x29. The message table's slot 0x58 (one argument)
is a logged stub returning a random word. The setup helper 0x645000 (thiscall, the entry and one word) is a recording stub by address (GUESS: its body is
not part of this batch). Entry flags at +0x3e, +0x15 and +0x14 are random. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _entry(c):
    e = c.emu
    r = c.rng
    ent = e.alloc(0x1df + 0x40)
    e.wbytes(ent, bytes(r.getrandbits(8) for _ in range(0x1df)))
    e.w8(ent + 0x3e, r.choice([0, 1]))
    e.w8(ent + 0x15, r.choice([0, 1]))
    e.w8(ent + 0x14, r.choice([0, 1]))
    return ent


def _x(c):
    e = c.emu
    r = c.rng

    def stub645(em, rr):
        em.calllog.append(('645000', em.reg('ecx'), em.arg32(0)))
        em.ret(argbytes=4)
    e.hook(0x645000, stub645)
    msg = e.alloc(0x80)
    retv = r.getrandbits(32)
    e.w32(msg, vtable(c, 'msg644820', 0x80, impl={0x58: lambda em, a: retv}, argwords={0x58: 1}))
    eng = e.alloc(0x1000)
    e.w32(eng + 0x9b, msg)
    e.w32(0x70039c, eng)
    count = r.randint(0, 3)
    rec = rnd(c, 0x100)
    e.w32(rec + 0x21, count)
    base = e.alloc(0x1df * max(count, 1) + 0x40)
    for i in range(count):
        ent = _entry(c)
        e.wbytes(base + i * 0x1df, e.rbytes(ent, 0x1df))
    e.w32(rec + 0x25, base)
    e.w32(rec + 0x29, _entry(c))
    return [rec]


S(0x644820, 'unnamed 0x644820', 'thiscall', None, gen=_x, n=1000)
