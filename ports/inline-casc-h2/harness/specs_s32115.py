"""specs_s32115.py - h2 (Sonnet) batch 32115: tier H functions. Imports are stubs written into the IAT slot (pystub with st0 for an x87 float result); slots/callees are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g6581c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fv = struct.unpack('<f', struct.pack('<f', r.uniform(-100, 100)))[0]
    e.w32(0x6762d4, pystub(c, 1, pop=0, st0=fv, side=_log('imp')))
    tgt = obj(c, 0x20, {0x1e8: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('set')),
                        0x1ec: pystub(c, 0, this=True, st0=fv, side=_log('get'))}, nslots=0x1ec // 4 + 1)
    inner = obj(c, 0x20, {0x2c: pystub(c, 4, ret=r.getrandbits(32), pop=0, side=_log('log2'))})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))})
    e.w32(0x700390, g)
    me = rnd(c, 0x110)
    e.w32(me + 0x104, tgt)
    return [me, 0 if r.random() < 0.35 else rnd(c, 0x20)]


def g5b87f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5b8d80, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('tail'))
    s = obj(c, 0x20, {0x128: pystub(c, 1, this=True, side=_log('s128'))}, nslots=0x128 // 4 + 1)
    so = sysobj(c, table_slots={0x114: pystub(c, 6, ret=r.getrandbits(32), this=True, side=_log('t114'))})
    t40, t44 = r.randrange(0, 100000), r.randrange(0, 100000)
    e.w32(so + 0x40, t40)
    e.w32(so + 0x44, t44)
    k = _f(e.r32(0x6785e4))
    me = rnd(c, 0xf0)
    e.wbytes(me + 0xdd, bytes([r.choice([0, 0, 0, 1])]))
    e.wbytes(me + 0xb2, bytes([r.choice([0, 0, 1])]))
    x0 = r.choice([r.uniform(-1, 1), 0.0, _f(NAN)])
    e.wbytes(me + 0xb3, struct.pack('<f', x0))
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    x2 = f32(f32(x0) + f32(f32(float(t40 - t44)) * k))
    thr = r.choice([0.0, r.uniform(-1, 1), 0.5, -1.0, _f(NAN), x2, x2, x2, f32(x2 - 1e-3)])
    e.wbytes(me + 0x5c, struct.pack('<f', thr))
    e.wbytes(me + 0xe2, (s if r.random() < 0.75 else 0).to_bytes(4, 'little'))
    return [me]


S(0x6581c0, 'GUESS parse text to float and set, or log current value', 'thiscall', None, ret='eax', gen=g6581c0, note='batch32115')
S(0x5b87f0, 'GUESS timer advance and fire', 'thiscall', None, ret=None, gen=g5b87f0, nan_heap=True, note='batch32115')
