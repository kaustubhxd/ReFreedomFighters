"""specs_s32123.py - h2 () batch 32123: three tier H functions. Callees/slots are recorders (the matrix helpers 0x4deb20 / 0x4de4f0 run as exe code); order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g45ab60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fill(emu, k):
        base = emu.arg32(0)
        for i in range(3):
            if r.random() < 0.6:
                emu.w32(base + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
        emu.calllog.append(('fill',))
    me = obj(c, 0x30, {0x8c: pystub(c, 1, this=True, nullflag=(0,), side=fill),
                       0x214: pystub(c, 2, this=True, deref={0: 3}, side=_log('use'))}, nslots=0x214 // 4 + 1)
    inner = rnd(c, 0x60)
    e.wbytes(inner + 0x40, struct.pack('<f', r.choice([r.uniform(0.5, 9), 0.0, -2.0, _f(NAN)])))
    e.wbytes(inner + 0x44, struct.pack('<f', r.choice([r.uniform(0.5, 9), 0.0, -2.0])))
    e.w32(me + 8, inner)
    p = rnd(c, 0x10)
    for i in range(3):
        e.wbytes(p + 4 * i, struct.pack('<f', r.uniform(-9, 9)))
    return [me, p, r.getrandbits(32)]


def g5c34a0(c):
    clear_hooks(c)
    r = c.rng
    ints = [r.choice([0, 1, r.getrandbits(32)]) for _ in range(4)]
    ws = [r.getrandbits(32) for _ in range(3)]
    fl = [struct.unpack('<f', struct.pack('<f', r.uniform(-50, 50)))[0] for _ in range(4)]
    hook_rec(c, 0x4e6330, 1, this=True, pop=4, side=_log('s'))
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda emu, k: ints[min(k, 3)], side=_log('i'))
    hook_rec(c, 0x4e5e40, 0, this=True, pop=0, ret=lambda emu, k: ws[min(k, 2)], side=_log('w'))
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda emu, k: fl[min(k, 3)], side=_log('f'))
    return [rnd(c, 0x120), rnd(c, 0x20)]


def g501ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fill(emu, k):
        b1 = emu.arg32(0)
        for i in range(9):
            emu.w32(b1 + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-2, 2)))[0])
        b2 = emu.arg32(1)
        for i in range(3):
            emu.w32(b2 + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-2, 2)))[0])
        emu.calllog.append(('fill',))
    m = obj(c, 0x20, {0x80: pystub(c, 2, this=True, nullflag=(0, 1), side=fill),
                      0x7c: pystub(c, 2, this=True, deref={0: 9, 1: 3}, side=_log('use'))}, nslots=0x80 // 4 + 1)
    rr = rnd(c, 0x10)
    e.wbytes(rr, struct.pack('<f', r.uniform(-3.2, 3.2)))
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=rr, side=_log('lk'))
    me = rnd(c, 0x20)
    e.w32(me + 0xc, m)
    p = rnd(c, 0x20)
    e.w32(p + 4, rnd(c, 0x20))
    return [me, p]


S(0x45ab60, 'GUESS normalise a point by half-extents then apply (GS frame)', 'thiscall', None, ret=None, gen=g45ab60, nan_heap=True, note='batch32123')
S(0x5c34a0, 'GUESS read record fields from source (variant 4)', 'thiscall', None, ret=None, gen=g5c34a0, note='batch32123')
S(0x501ee0, 'GUESS rotate a matrix by an angle through helpers (GS frame)', 'thiscall', None, ret=None, gen=g501ee0, nan_heap=True, note='batch32123')
