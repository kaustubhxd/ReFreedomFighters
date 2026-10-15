"""specs_s32128.py - h2 (Sonnet) batch 32128: 0x52d1c0 and 0x5b9780. The distance helper 0x4e0870 runs as exe code; slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g52d1c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    A = rnd(c, 0x20)
    e.w32(A + 0xc, rnd(c, 0x100))
    e.w32(A + 0x10, rnd(c, 0x40))
    e.w32(A + 0x14, rnd(c, 0x40))
    N = rnd(c, 8)
    e.w32(N, r.choice([0, 0, 1, 2, 3]))
    ACC = rnd(c, 8)
    e.wbytes(ACC, struct.pack('<f', r.choice([r.uniform(-9, 9), 0.0, _f(NAN)])))
    P = rnd(c, 0x10)
    Q = rnd(c, 0x10)
    for p in (P, Q):
        for i in range(3):
            e.wbytes(p + 4 * i, struct.pack('<f', r.choice([r.uniform(-9, 9), 0.0, 1e20])))
    return [A, N, ACC, P, Q, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g5b9780(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fill(emu, k):
        base = emu.arg32(0)
        for i in range(3):
            if r.random() < 0.7:
                emu.w32(base + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
        emu.calllog.append(('v',))
    oo = obj(c, 0x20, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=fill)}, nslots=0x84 // 4 + 1)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=oo, this=True, side=_log('lk'))})
    tgt = obj(c, 0x20, {0x128: pystub(c, 3, this=True, deref={1: 4}, side=_log('use'))}, nslots=0x128 // 4 + 1)
    me = obj(c, 0x70, {0x84: pystub(c, 2, ret=r.choice([0, 0, r.getrandbits(32)]), this=True, side=_log('r'))}, nslots=0x84 // 4 + 1)
    inner = rnd(c, 0x20)
    e.w32(me + 0x50, inner)
    e.w32(me + 0x58, r.getrandbits(32))
    e.w32(me + 0x44, tgt)
    e.wbytes(me + 0x60, r.getrandbits(16).to_bytes(2, 'little'))
    return [me]


S(0x52d1c0, 'GUESS append path point with accumulated length', 'stdcall', None, ret=None, gen=g52d1c0, nan_heap=True, note='batch32128')
S(0x5b9780, 'GUESS resolve object and publish its position (GS frame)', 'thiscall', None, ret=None, gen=g5b9780, nan_heap=True, note='batch32128')
