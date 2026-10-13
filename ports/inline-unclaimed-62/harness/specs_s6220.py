"""specs_s6220.py - unclaimed-62 claim 13 (slice 2): eight call-free leaves (see src/batch6220.cpp). Records are 0x1000 bytes of random data;
the spec sets the fields each leaf reads. The chain for 0x440cc0 is 0..4 nodes ending in null. The two bool returns compare al; the
two counts/values compare eax. Writes into the records are compared."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _e6400(c):
    e = c.emu
    rec = rnd(c, 0x1000)
    byte = e.alloc(16)
    e.w8(byte, c.rng.choice([0xff, c.rng.getrandbits(8)]))
    e.w32(rec, byte)
    return [rec]


def _cc0(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    nodes = [rnd(c, 0x100) for _ in range(r.randint(0, 4))]
    for k, nd in enumerate(nodes):
        e.w32(nd + 0x50, nodes[k + 1] if k + 1 < len(nodes) else 0)
    e.w32(rec + 8, nodes[0] if nodes else 0)
    return [rec]


def _f100(c):
    rec = rnd(c, 0x1000)
    dst = rnd(c, 0x100)
    return [rec, dst]


def _f40(c):
    rec = rnd(c, 0x1000)
    return [rec, c.rng.getrandbits(32)]


def _f60(c):
    rec = rnd(c, 0x1000)
    c.emu.w32(rec + 0x750, c.rng.randint(0, 12))
    return [rec, c.rng.getrandbits(32)]


def _f600(c):
    rec = rnd(c, 0x1000)
    return [rec] + [c.rng.getrandbits(32) for _ in range(4)]


def _e6e0(c):
    rec = rnd(c, 0x1000)
    r = c.rng
    v = r.getrandbits(32)
    c.emu.w32(rec + 0x9d3, v)
    c.emu.w8(rec + 0x66c, r.choice([0, 1, 7]))
    return [rec, v if r.random() < 0.6 else r.getrandbits(32)]


def _f570(c):
    e = c.emu
    rec = rnd(c, 0x1000)
    e.w32(rec + 0x18, c.rng.randint(0, 3))
    pp = rnd(c, 0x40)
    e.w32(pp, c.rng.choice([0, c.rng.randint(1, 0x10000)]))
    return [rec, pp]


S(0x4e6400, 'unnamed 0x4e6400', 'thiscall', None, ret='al', gen=_e6400, n=1000)
S(0x440cc0, 'unnamed 0x440cc0', 'thiscall', None, ret='eax', gen=_cc0, n=1000)
S(0x4cf100, 'unnamed 0x4cf100', 'thiscall', None, gen=_f100, n=1000)
S(0x594f40, 'unnamed 0x594f40', 'thiscall', None, gen=_f40, n=1000)
S(0x581960, 'unnamed 0x581960', 'thiscall', None, gen=_f60, n=1000)
S(0x5ac600, 'unnamed 0x5ac600', 'thiscall', None, gen=_f600, n=1000)
S(0x5966e0, 'unnamed 0x5966e0', 'thiscall', None, ret='al', gen=_e6e0, n=1000)
S(0x4cf570, 'unnamed 0x4cf570', 'thiscall', None, ret='eax', gen=_f570, n=1000)
