"""specs_s32131.py - h2 (Sonnet) batch 32131: 0x503670, 0x5ec670, 0x4a3710. Callees/slots are recorders; the vector subtract runs as exe code."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g503670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fill(emu, k):
        a = emu.arg32(0)
        for i in range(9):
            emu.w32(a + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
        v = emu.arg32(1)
        for i in range(3):
            if r.random() < 0.7:
                emu.w32(v + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
        emu.calllog.append(('fill',))
    m = obj(c, 0x20, {0x80: pystub(c, 2, this=True, nullflag=(0, 1), side=fill),
                      0x7c: pystub(c, 2, this=True, deref={0: 9, 1: 3}, side=_log('use'))}, nslots=0x80 // 4 + 1)
    comps = [rnd(c, 0x10) for _ in range(3)]
    for p in comps:
        e.wbytes(p, struct.pack('<f', r.uniform(-9, 9)))
    seq = [comps[2], comps[1], comps[0]]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: seq[min(k, 2)], side=_log('lk'))
    me = rnd(c, 0x20)
    e.w32(me + 0xc, m)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x20))
    return [me, p]


def g5ec670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3])
    objs = rnd(c, 4 * (n + 3))        # object pointer array with a slot before element 0 (index -1)
    arr = objs + 4
    for i in range(-1, n + 1):
        o = rnd(c, 0x20)
        e.w32(arr + 4 * i, o)
    rows = rnd(c, 40 * (n + 3) + 0x40)    # rows with one row of slack before element 0
    me = rnd(c, 0xb0)
    e.w32(me + 0x3e, n)
    e.w32(me + 0x62, arr)
    holder = rnd(c, 0x10)
    e.w32(holder + 4, rows + 40)
    e.w32(me + 0x3a, holder)
    e.w32(me + 0x52, r.choice([0, 1, 640, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32)]))
    e.w32(me + 0x56, r.choice([0, 1, 480, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32)]))
    idx = r.choice([0xffffffff, 0xffffffff, 0] + ([1] if n > 1 else []) + ([2] if n > 2 else []))
    return [me, F(r.choice([r.uniform(-3, 3), 0.0, 1.0, _f(NAN)])), idx]


def g4a3710(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x80)
    a = [r.uniform(-9, 9) for _ in range(3)]
    b = list(a) if r.random() < 0.3 else [r.choice([x, r.uniform(-9, 9), x + 1e-3]) for x in a]
    e.wbytes(me + 0x4c, struct.pack('<fff', *a))
    e.wbytes(me + 0x58, struct.pack('<fff', *b))
    return [me]


S(0x503670, 'GUESS transform vector components through slots (GS frame)', 'thiscall', None, ret=None, gen=g503670, nan_heap=True, note='batch32131')
S(0x5ec670, 'GUESS scale one or all sprite rows by a factor', 'thiscall', None, ret=None, gen=g5ec670, nan_heap=True, note='batch32131')
S(0x4a3710, 'GUESS direction vector between two points, normalised', 'thiscall', None, ret=None, gen=g4a3710, nan_heap=True, note='batch32131')
