"""specs_s41008.py - t2 (Sonnet) batch 41008: 0x5c7830, 0x507630. Vtable slots are recorders; 0x5003d0 and 0x633654 are scripted recorders."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g5c7830(c):
    clear_hooks(c)
    r = c.rng
    slots = {0x3c: pystub(c, 1, this=True), 0x6c: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True),
             0x64: pystub(c, 1, this=True), 0x60: pystub(c, 1, this=True)}
    o = obj(c, 0x20, slots, nslots=0x70 // 4)
    p = rnd(c, 0x30)
    for off in (0x14, 0x18, 0x24, 0x28):
        c.emu.wbytes(p + off, struct.pack('<I', r.choice([_bits(r.uniform(-9, 9)), NAN, 0x7f800001, 0, r.getrandbits(32)])))
    return [p, o]


def g507630(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    # K1 = [0x67a284], K2 = [0x680a70]: choose x around them
    k1 = struct.unpack('<f', struct.pack('<I', e.r32(0x67a284)))[0]
    k2 = struct.unpack('<f', struct.pack('<I', e.r32(0x680a70)))[0]
    xs = [k1, k2, k1 - 1.0, k1 + 1.0, k2 + 1.0, k2 - 1.0, (k1 + k2) / 2, 0.0, -1.0, 1e30, -1e30, r.uniform(-9, 9)]
    xv = _bits(r.choice(xs)) if r.random() < 0.93 else r.choice([NAN, 0x7f800000, 0xff800000, r.getrandbits(32)])
    blks = []
    for i in range(4):
        b = rnd(c, 8)
        e.w32(b, xv if i == 3 else r.getrandbits(32))
        blks.append(b)
    order = [blks[2], blks[1], blks[0], blks[3]]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: order[min(k, 3)])
    wv = [r.getrandbits(32) for _ in range(3)]

    def fill(emu, k):
        b = emu.arg32(0)
        for i in range(3):
            emu.w32(b + 4 * i, wv[i])
        emu.calllog.append(('fill',))
    bo = obj(c, 0x20, {0x624: pystub(c, 1, this=True), 0x630: pystub(c, 1, this=True, nullflag=(0,), side=fill),
                       0x5e8: pystub(c, 1, this=True), 0x5e0: pystub(c, 2, this=True, deref={0: 3, 1: 3})}, nslots=0x634 // 4)
    me = rnd(c, 0x40)
    e.w32(me + 0x18, bo)
    a = rnd(c, 0x10)
    e.w32(a + 4, rnd(c, 0x10))
    return [me, a]


S(0x5c7830, 'GUESS replay recorded render state', 'stdcall', None, ret=None, gen=g5c7830, nan_heap=True, note='batch41008')
S(0x507630, 'GUESS set light from record', 'thiscall', None, ret=None, gen=g507630, nan_heap=True, note='batch41008')
