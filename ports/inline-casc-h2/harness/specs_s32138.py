"""specs_s32138.py - h2 (Sonnet) batch 32138: 0x45f8d0, 0x4e4ef0. Callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def g45f8d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.wbytes(so + 0x40, struct.pack('<I', r.choice([0, 1, 1000, 0xffffffff, 0x80000000, r.getrandbits(32), r.getrandbits(20)])))
    n = r.choice([0, 1, 2, 3, 4])
    elems = [rnd(c, 0x20) for _ in range(n)]
    for s in elems:
        e.w32(s + 0x10, rnd(c, 0x10))
    seqs = elems + [0]

    def fill(emu, k):
        a = emu.arg32(0)
        for i in range(3):
            emu.w32(a + 4 * i, r.getrandbits(32))
        emu.calllog.append(('init',))
    nxt = lambda emu, k: seqs[min(k, n)]
    cobj = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, nullflag=(0,), side=fill),
                         0x64: pystub(c, 1, this=True, nullflag=(0,), ret=nxt)}, nslots=0x68 // 4)
    holder = rnd(c, 0x30)
    e.w32(holder + 0x14, r.choice([cobj, cobj, cobj, 0]))
    me = rnd(c, 0x30)
    e.w32(me + 0x10, r.choice([holder, holder, holder, 0]))
    rets = [r.choice([0, 1, 5, r.getrandbits(32)]) for _ in range(6)]
    if r.random() < 0.5:
        rets[r.randrange(0, 4)] = 0

    def edx_log(emu, k):
        emu.calllog.append(('m', emu.reg('edx')))
    hook_rec(c, 0x4cc850, 0, this=True, pop=0, ret=lambda emu, k: rets[min(k, 5)], side=edx_log)
    return [me, rnd(c, 0x10)]


def g4e4ef0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e4bd0, 3, this=True, pop=12, deref={1: 3, 2: 3}, ret=r.getrandbits(32))
    me = rnd(c, 0x40)
    sc = r.choice([_bits(1.0), _bits(0.5), _bits(r.uniform(-4, 4)), _bits(100.0), NAN, 0, _bits(1e-3)])
    e.wbytes(me + 0x1d, struct.pack('<I', sc))
    org = [r.choice([_bits(r.uniform(-50, 50)), _bits(0.0), _bits(r.uniform(-5, 5))]) for _ in range(3)]
    for i in range(3):
        e.wbytes(me + 0x21 + 4 * i, struct.pack('<I', org[i]))

    def vec():
        p = rnd(c, 0x10)
        for i in range(3):
            v = r.choice([_bits(r.uniform(-60, 60)), _bits(r.uniform(-1, 1)), _bits(r.uniform(-1e5, 1e5)), _bits(r.uniform(-9, 9)), 0, NAN, _bits(1e30)])
            e.w32(p + 4 * i, v)
        return p
    return [me, r.getrandbits(32), vec(), vec()]


S(0x45f8d0, 'GUESS find entry by name and stamp time', 'thiscall', None, ret=None, gen=g45f8d0, nan_heap=True, note='batch32138')
S(0x4e4ef0, 'GUESS box to grid cell range', 'thiscall', None, ret='eax', gen=g4e4ef0, nan_heap=True, note='batch32138')
