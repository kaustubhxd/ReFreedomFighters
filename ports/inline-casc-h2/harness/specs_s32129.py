"""specs_s32129.py - h2 (Sonnet) batch 32129: 0x457760 and 0x4e3230. The vector helpers run as exe code; the engine integer slot is a recorder returning a sequence."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g457760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seq = [r.choice([0, 1, 0x7fff, 0x7fffffff, 0xffff8000, r.getrandbits(32), r.randrange(0, 65536)]) for _ in range(3)]
    sysobj(c, slots={0x1bc: pystub(c, 2, ret=lambda emu, k: seq[min(k, 2)], this=True, side=_log('rnd'))})
    me = rnd(c, 0x70)
    for off in range(0x44, 0x5c, 4):
        e.wbytes(me + off, struct.pack('<f', r.uniform(-9, 9)))
    return [me, rnd(c, 0x10)]


def g4e3230(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, 8, 12])
    base = rnd(c, (n + 2) * 9 + 8)
    vals = [r.uniform(-9, 9) for _ in range(n + 3)]
    for i in range(n + 3):
        v = r.choice([vals[i], vals[i], vals[max(0, i - 1)], 0.0])
        e.wbytes(base + 9 * i, struct.pack('<f', v))
    return [base, n, r.randrange(0, n + 1)]


S(0x457760, 'GUESS random point in unit cube transformed by two helpers', 'thiscall', None, ret=None, gen=g457760, nan_heap=True, note='batch32129')
S(0x4e3230, 'GUESS min-heap sift-down over 9-byte records', 'fastcall', None, ret=None, gen=g4e3230, note='batch32129')
