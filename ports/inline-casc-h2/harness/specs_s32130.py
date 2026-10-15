"""specs_s32130.py - h2 (Sonnet) batch 32130: 0x4def50 (quaternion product), 0x449100, 0x5d9210. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g4def50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    out = rnd(c, 0x20)
    b = rnd(c, 0x20)
    a = rnd(c, 0x20)
    for p in (b, a):
        for i in range(4):
            v = r.choice([r.uniform(-2, 2), r.uniform(-1e3, 1e3), 0.0, 1.0, _f(NAN)]) if r.random() > 0.03 else 1e30
            e.wbytes(p + 4 * i, struct.pack('<f', v))
    return [out, b, a]


def g449100(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill(emu, k):
        base = emu.arg32(1)
        for i in range(18):
            emu.w32(base + 4 * i, struct.unpack('<I', struct.pack('<f', r.uniform(-9, 9)))[0])
        emu.calllog.append(('fill',))
    t = obj(c, 0x20, {0x88: pystub(c, 2, this=True, nullflag=(1,), side=fill)}, nslots=0x88 // 4 + 1)
    inner = rnd(c, 0x40)
    e.w32(inner + 0x18, t)
    so = sysobj(c)
    e.wbytes(so + 0x1aa3, inner.to_bytes(4, 'little'))
    T = obj(c, 0x20, {0xa0: pystub(c, 5, this=True, side=_log('a0')), 0xa4: pystub(c, 5, this=True, side=_log('a4'))}, nslots=0xa4 // 4 + 1)
    me = rnd(c, 0x20)
    e.w32(me + 8, rnd(c, 0x80))
    e.wbytes(me + 0x14, bytes([r.choice([0, 1, 1, 3, 2])]))
    return [me, T, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g5d9210(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5d92e0, 1, this=True, pop=4, side=_log('s'))
    oo = rnd(c, 0x20)

    def setflag(emu, k):
        emu.w8(emu.arg32(1), r.choice([0, 1, 2]))
        emu.calllog.append(('flag',))
    f = obj(c, 0x20, {0x90: pystub(c, 2, this=True, nullflag=(1,), side=setflag)}, nslots=0x90 // 4 + 1)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=(oo if r.random() < 0.7 else 0), this=True, side=_log('lk')), 0x134: pystub(c, 0, ret=f, this=True)})
    g = rnd(c, 0x90)
    e.wbytes(g + 0x81, bytes([r.choice([0, 0, 1, 0x80])]))
    e.wbytes(so + 0x190f, (g if r.random() < 0.6 else 0).to_bytes(4, 'little'))
    sub = obj(c, 0x20, {0x254: pystub(c, 0, this=True, side=_log('t'))}, nslots=0x254 // 4 + 1)
    me = rnd(c, 0x70)
    e.w32(me + 0x44, sub)
    e.w32(me + 0x54, r.getrandbits(32))
    return [me]


S(0x4def50, 'GUESS quaternion product (register ABI)', 'fastcall', None, ret=None, gen=g4def50, nan_heap=True, note='batch32130')
S(0x449100, 'GUESS publish two triples of floats through slots', 'thiscall', None, ret=None, gen=g449100, nan_heap=True, note='batch32130')
S(0x5d9210, 'GUESS setup viewport margins from flags', 'thiscall', None, ret=None, gen=g5d9210, note='batch32130')
