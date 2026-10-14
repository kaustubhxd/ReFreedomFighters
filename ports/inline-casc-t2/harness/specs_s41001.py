"""specs_s41001.py - t2 () batch 41001: 0x50ad50, 0x4bfb80. Callees 0x5003d0 and all vtable slots are recorders; the assert hook 0x7003b0 is always set."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g50ad50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ah_ret = r.getrandbits(32)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=ah_ret)
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    d = obj(c, 0x20, {0x58: pystub(c, 3, this=True)}, nslots=0x60 // 4)
    sysobj(c, table_slots={0x134: pystub(c, 0, this=True, ret=d)}, table_size=0x140)
    o = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)}, nslots=0x30 // 4)
    g = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=o)}, nslots=0x24 // 4)
    e.w32(0x700390, g)
    sub = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=0x38 // 4)
    fp = rnd(c, 0x10)
    e.wbytes(fp, struct.pack('<I', r.choice([_bits(r.uniform(-9, 9)), _bits(1.0), NAN, 0, r.getrandbits(32)])))
    el = rnd(c, 0x10)
    kind = r.choice([3, 4, 0, 1, 5, 2, 255])
    e.w32(el + 4, (r.getrandbits(24) << 8) | kind)
    if kind == 4:
        e.w32(el, sub)
    pp = rnd(c, 0x10)
    e.w32(pp + 4, rnd(c, 0x10))
    seq = [fp, el]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: seq[min(k, 1)])
    return [pp]


def g4bfb80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysb = sysobj(c)
    b = rnd(c, 0x90)
    ival = r.choice([0, 1, -1 & 0xffffffff, r.getrandbits(32), r.randrange(0, 5000), r.randrange(0, 1 << 20), 0x7fffffff, 0x80000000])
    e.w32(b + 0x6c, ival)
    b78 = r.choice([r.uniform(-9, 9), r.uniform(0, 600), 0.0, 1e12, -1e12])
    e.wbytes(b + 0x78, struct.pack('<I', NAN if r.random() < 0.03 else _bits(b78)))
    e.wbytes(b + 0x70, struct.pack('<I', _bits(r.choice([r.uniform(-50, 50), 0.0, 1.0, -1.0, r.uniform(0, 1e5)]))))
    t = int(((struct.unpack('<i', struct.pack('<I', ival))[0]) + b78 * 1024)) if abs(b78) < 1e9 else 0
    s30 = r.choice([t, t + 1, t - 1, t + r.randrange(0, 3000), t - r.randrange(0, 3000), r.getrandbits(32), 0, 0x7fffffff, 0x80000000])
    e.w32(sysb + 0x30, s30 & 0xffffffff)
    e.wbytes(sysb + 0x34, struct.pack('<I', _bits(r.choice([r.uniform(-50, 50), 0.0, 1.0, r.uniform(0, 1e5)]))))
    rv = r.choice([r.uniform(-9, 9), 0.0, 1.0, -1.0, 3.0, 1e-20, 1e30, r.uniform(0.01, 2000)])
    sl = obj(c, 0x40, {0x210: pystub(c, 1, this=True, side=_log('s210'))}, nslots=0x214 // 4)
    e.w32(sl + 0x18, b)
    me = obj(c, 0x80, {0x8c: pystub(c, 1, this=True, st0=rv)}, nslots=0x90 // 4)
    e.w32(me + 0x44, sl if r.random() < 0.9 else 0)
    e.w32(me + 0x64, r.choice([2, 3, 100, 1, 0, 0xffffffff, r.getrandbits(32), 2, 2]))
    return [me]


S(0x50ad50, 'GUESS push typed value to renderer slot', 'stdcall', None, ret=None, gen=g50ad50, nan_heap=True, note='batch41001')
S(0x4bfb80, 'GUESS timed progress update', 'thiscall', None, ret=None, gen=g4bfb80, nan_heap=True, note='batch41001')
