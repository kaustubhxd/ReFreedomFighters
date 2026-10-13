"""specs_s6214.py - unclaimed-62 claim 7 (slice 1): unnamed 0x5594d0 (thiscall, ret 4). b = {+4: vector A, +8: vector B}; a vector is
{hdr, offset, count} and hdr is {base, total}, element 8 bytes (dword, state byte at +4 in {0, 1}). The exe lookups 0x559380 and 0x589a10 are
hooked by address (GUESS stubs: they write an object pointer and a flag byte chosen from the call-log position, the same in both builds).
The engine's message table answers slot 0x4c with a value chosen the same way. 0x5003d0 and 0x5002f0 run as exe code."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, reporter, vtable


def _vec(c, offset, count):
    e = c.emu
    r = c.rng
    total = offset + count + r.randint(0, 3)
    base = e.alloc(8 * total)
    for k in range(total):
        e.w32(base + 8 * k, r.getrandbits(32))
        e.w8(base + 8 * k + 4, r.choice([0, 1]))
    hdr = e.alloc(16)
    e.w32(hdr, base)
    e.w32(hdr + 8, total)
    obj = e.alloc(16)
    e.w32(obj, hdr)
    e.w32(obj + 4, offset)
    e.w32(obj + 8, count)
    return obj


def _gen(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    fakes = []
    for _ in range(4):
        f = e.alloc(16)
        e.w32(f, r.getrandbits(32))
        fakes.append(f)
    outlist = [0, fakes[0], fakes[1], 0, fakes[2], fakes[3]]
    flist = [r.choice([0, 1]) for _ in range(64)]
    mlist = [r.getrandbits(32) for _ in range(64)]

    def pick(em, tab):
        return tab[len(em.calllog) % len(tab)]

    def h559380(em, rr):
        em.calllog.append(('559380',))
        em.w32(em.arg32(1), pick(em, outlist))
        em.w8(em.arg32(2), pick(em, flist))
        em.ret(argbytes=12)

    def h589a10(em, rr):
        em.calllog.append(('589a10',))
        em.w32(em.arg32(2), pick(em, outlist))
        em.w8(em.arg32(3), pick(em, flist))
        em.ret(argbytes=16)

    e.hook(0x559380, h559380)
    e.hook(0x589a10, h589a10)

    msg = e.alloc(0x80)
    e.w32(msg, vtable(c, 'msgtable', 0x60, impl={0x4c: lambda em, a: pick(em, mlist)}, argwords={0x4c: 1}))
    sysi = rnd(c, 0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)

    self_ = rnd(c, 0x100)
    x = rnd(c, 0x1000)
    e.w32(self_ + 0x1c, x)
    e.w32(x + 0x921, r.choice([0, 0x1000 + r.getrandbits(8)]))

    b = e.alloc(16)
    off_a = r.randint(0, 2)
    e.w32(b + 4, _vec(c, off_a, 2))
    e.w32(b + 8, _vec(c, r.randint(0, 2), 2))
    return [self_, b]


S(0x5594d0, 'unnamed 0x5594d0', 'thiscall', None, gen=_gen, n=1000)
