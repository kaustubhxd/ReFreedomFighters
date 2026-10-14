"""specs_s32113.py - h2 () batch 32113: two tier H float / SSE functions. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g57f360(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x57f6b0, 0, this=True, pop=0, side=_log('f'))
    hook_rec(c, 0x57f750, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('tail'))
    o1 = obj(c, 0x20, {0xac: pystub(c, 1, this=True, side=_log('o1'))}, nslots=0xac // 4 + 1)
    o3 = obj(c, 0x20, {0xbc: pystub(c, 1, this=True, side=_log('o3'))}, nslots=0xbc // 4 + 1)
    seq = [o1, o3]
    so = sysobj(c, slots={0xbc: pystub(c, 0, ret=lambda emu, k: seq[min(k, 1)], this=True)})
    o2 = obj(c, 0x20, {0x314: pystub(c, 1, this=True, side=_log('o2'))}, nslots=0x314 // 4 + 1)
    tgt = obj(c, 0x20, {0x36c: pystub(c, 2, this=True, side=_log('t'))}, nslots=0x36c // 4 + 1)
    me = obj(c, 0x1a0, {0x84: pystub(c, 0, ret=o2, this=True, side=_log('s'))}, nslots=0x84 // 4 + 1)
    e.w32(me + 0x180, tgt)
    e.wbytes(me + 0x188, struct.pack('<f', r.choice([r.uniform(-50, 50), 0.0, 1.5, -2.5, 1e9, -1e9, _f(NAN)])))
    return [me]


def g4e7c50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    inner = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), pop=0, side=_log('log2'))})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))})
    e.w32(0x700390, g)
    p = rnd(c, 0x80)
    flags = r.choice([0, 0x40000000, 0x80000000, 0xc0000000, 0x3fffffff, r.getrandbits(32)])
    e.w32(p + 4, flags)
    sel = r.choice([8, 0x10, 0x20])
    e.w32(p + 8, sel)   # offset used when the flags select it
    bounds = {}
    for off in (8, 0x10, 0x20, 0x30):
        lo = r.randrange(-50, 50)
        hi = lo + r.randrange(1, 100)
        bounds[off] = (lo, hi)
        e.w32(p + off + 4, lo & 0xffffffff)
        e.w32(p + off + 8, hi & 0xffffffff)
    k = flags & 0xc0000000
    use = sel if k in (0x40000000, 0x80000000, 0xc0000000) else 8
    lo, hi = bounds.get(use, (0, 0))
    me = rnd(c, 0x30)
    e.wbytes(me + 9, (p if r.random() > 0.15 else 0).to_bytes(4, 'little'))
    n = r.choice([r.randrange(-100, 200), 0, 0x7fffffff, 0x80000000, r.getrandbits(32), lo & 0xffffffff, hi & 0xffffffff, (lo - 1) & 0xffffffff, (hi + 1) & 0xffffffff, lo & 0xffffffff, hi & 0xffffffff])
    return [me, n]


S(0x57f360, 'GUESS apply value through slots then tail', 'thiscall', None, ret='eax', gen=g57f360, nan_heap=True, note='batch32113')
S(0x4e7c50, 'GUESS clamp int to record range and store as float', 'thiscall', None, ret=None, gen=g4e7c50, nan_heap=True, note='batch32113')
