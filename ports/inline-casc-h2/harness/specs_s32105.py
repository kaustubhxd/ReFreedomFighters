"""specs_s32105.py - h2 (Sonnet) batch 32105: three tier H float / SSE functions. Callees/slots are recorders; stack buffers are recorded with deref; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g449ae0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill(emu, k):
        base = emu.arg32(1)
        for i in range(9):
            emu.w32(base + 4 * i, r.getrandbits(32))
        emu.calllog.append(('fill',))
    t = obj(c, 0x20, {0x80: pystub(c, 2, this=True, nullflag=(1,), side=fill),
                      0x98: pystub(c, 2, this=True, deref={1: 9}, side=_log('apply'))}, nslots=0x98 // 4 + 1)
    so = sysobj(c)
    inner = rnd(c, 0x40)
    e.w32(inner + 0x18, t)
    e.wbytes(so + 0x1aa3, inner.to_bytes(4, 'little'))
    rec = rnd(c, 0x80)
    me = obj(c, 0x20, {0x238: pystub(c, 0, this=True, side=_log('a')), 0x220: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('z'))}, nslots=0x238 // 4 + 1)
    e.w32(me + 8, rec)
    return [me, F(r.uniform(-9, 9) if r.random() > 0.1 else _f(NAN))]


def g464400(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    m = obj(c, 0x20, {0x18: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('m'))}, nslots=0x18 // 4 + 1)
    me = obj(c, 0x80, {0x288: pystub(c, 5, ret=r.getrandbits(32), this=True, side=_log('s'))}, nslots=0x288 // 4 + 1)
    e.w32(me + 0x6c, m)
    p = rnd(c, 0x80)
    return [me, p, F(r.uniform(-9, 9)), F(r.uniform(-9, 9)), r.choice([0, 1, 0x100, 5]), r.getrandbits(32)]


def g47fea0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dd060, 1, this=True, pop=4, deref={0: 3}, side=_log('a'))
    hook_rec(c, 0x4dce50, 1, this=True, pop=4, side=_log('b'))
    hook_rec(c, 0x4dc600, 1, this=True, pop=4, deref={0: 3}, side=_log('c'))
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    me = rnd(c, 0x30)
    e.w32(me + 8, rnd(c, 0x20))
    e.wbytes(me + 0x1c, r.choice([struct.pack('<f', r.uniform(-9, 9)), struct.pack('<I', NAN), bytes(4)]))
    return [me]


S(0x449ae0, 'GUESS fill and apply render record with float', 'thiscall', None, ret='eax', gen=g449ae0, nan_heap=True, note='batch32105')
S(0x464400, 'GUESS scale by frame count and dispatch', 'thiscall', None, ret='eax', gen=g464400, note='batch32105')
S(0x47fea0, 'GUESS reset member with float vectors (GS frame)', 'thiscall', None, ret=None, gen=g47fea0, nan_heap=True, note='batch32105')
