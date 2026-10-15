"""specs_s32107.py - h2 (Sonnet) batch 32107: three tier H float / SSE functions. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _fbits(c, lo=-5, hi=5):
    r = c.rng
    return r.choice([_fb(r.uniform(lo, hi)), _fb(r.uniform(lo, hi)), _fb(r.uniform(lo, hi)), NAN, 0x7f800000, 0xff800000, 0, 0x80000000])


def g5d86d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def w(emu, k):
        base = emu.arg32(0)
        for i in range(3):
            emu.w32(base + 4 * i, _fbits(c, -9, 9))
    hook_rec(c, 0x4db500, 1, this=True, pop=4, nullflag=(0,), side=w)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    so = sysobj(c)
    e.wbytes(so + 0x48, struct.pack('<f', r.uniform(0, 0.2)))
    inner = rnd(c, 0x20)
    e.w32(inner + 8, rnd(c, 0x20))
    mem = obj(c, 0x20, {0x70: pystub(c, 1, this=True, deref={0: 3}, side=_log('s'))}, nslots=0x70 // 4 + 1)
    e.w32(mem + 8, inner)
    me = obj(c, 0x80, {0x84: pystub(c, 0, this=True, side=_log('a'))}, nslots=0x84 // 4 + 1)
    e.w32(me + 0x44, mem)
    e.wbytes(me + 0x54, bytes([r.choice([0, 1, 1])]))
    e.wbytes(me + 0x48, _fbits(c, -3, 3).to_bytes(4, 'little'))
    return [me]


def g44bc00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = _f(e.r32(0x678620))
    k2 = _f(e.r32(0x678858))
    t = r.randrange(-50, 5000)
    tb = struct.pack('<f', (t + r.choice([-2, -1, 0, 1, 2])) / k if k else 0.0)
    so = sysobj(c, table_slots={0xb8: pystub(c, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True, side=_log('b'))})
    e.w32(so + 0x40, t & 0xffffffff)
    e.wbytes(so + 0x20, struct.pack('<f', r.uniform(0, 0.3)))
    e.wbytes(so + 0x48, struct.pack('<f', r.uniform(0, 0.3)))
    me = rnd(c, 0x100)
    e.wbytes(me + 0xec, bytes([r.choice([0, 1, 1, 1])]))
    e.wbytes(me + 0xed, tb)
    d = r.uniform(0, 0.5)
    e.wbytes(me + 0xf1, struct.pack('<f', r.choice([k2 + d, k2 + 1e-3, k2, k2 - 0.5, 0.1, _f(NAN), 5.0])))
    e.wbytes(me + 0xf5, struct.pack('<f', r.choice([0.0, 0.5, 1.0, 2.0, 10.0, _f(NAN)])))
    return [me]


def g4f9600(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seq = [r.getrandbits(32) for _ in range(4)]
    p = obj(c, 0x20, {0x68: pystub(c, 1, ret=lambda emu, k: seq[min(k, 3)], this=True, side=_log('p'))}, nslots=0x68 // 4 + 1)
    so = sysobj(c)
    e.wbytes(so + 0x1a9f, (p if r.random() < 0.8 else 0).to_bytes(4, 'little'))
    return [rnd(c, 0x20)]


S(0x5d86d0, 'GUESS advance position by speed and apply (GS frame)', 'thiscall', None, ret=None, gen=g5d86d0, nan_heap=True, note='batch32107')
S(0x44bc00, 'GUESS fade timer step', 'thiscall', None, ret='al', gen=g44bc00, nan_heap=True, note='batch32107')
S(0x4f9600, 'GUESS look up four named entries', 'thiscall', None, ret='al', gen=g4f9600, note='batch32107')
