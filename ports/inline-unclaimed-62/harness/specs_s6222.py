"""specs_s6222.py - unclaimed-62 claim 15 (slice 2): four leaves (see src/batch6222.cpp). 0x487650 returns this (eax compared). 0x59e610 is
given a count of 0..6 and random signed entries. 0x545e20 has a base buffer and a count of 0..4 (its loop writes compared). 0x4ce5b0 has a
linked chain of six nodes with a chunk size of 1..3 so the walk stays inside the chain; its result dword is compared. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _487650(c):
    r = c.rng
    rec = rnd(c, 0x100)
    return [rec, r.getrandbits(32), r.getrandbits(32)]


def _59e610(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    cnt = r.randint(0, 6)
    e.w32(rec + 0x7ce, cnt)
    for i in range(1, 8):
        e.w32(rec + i * 16 + 0x7c2, r.randint(-40, 40) & 0xffffffff)
    return [rec, r.randint(-40, 40) & 0xffffffff]


def _545e20(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    base = rec + 0x100
    e.w32(rec + 0xf, base)
    e.w32(rec + 0x28, r.randint(0, 4))
    e.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x14 + 0x34 * 5 + 0x10)))
    return [rec]


def _4ce5b0(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    chunk = r.randint(1, 3)
    nodes = [rnd(c, 0x100) for _ in range(6)]
    for k, nd in enumerate(nodes):
        e.w32(nd + 4, nodes[k + 1] if k + 1 < len(nodes) else 0)
        e.wbytes(nd + 0x10, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(rec + 4, nodes[0])
    e.w32(rec + 0xc, chunk)
    e.w32(rec + 0x14, 6 * chunk)
    e.w32(rec + 0x18, r.randint(1, 2))
    return [rec, r.randint(0, 5 * chunk - 1)]


S(0x487650, 'unnamed 0x487650', 'thiscall', None, ret='eax', gen=_487650, n=1000)
S(0x59e610, 'unnamed 0x59e610', 'thiscall', None, gen=_59e610, n=1000)
S(0x545e20, 'unnamed 0x545e20', 'thiscall', None, gen=_545e20, n=1000)
S(0x4ce5b0, 'unnamed 0x4ce5b0', 'thiscall', None, ret='eax', gen=_4ce5b0, n=1000)
