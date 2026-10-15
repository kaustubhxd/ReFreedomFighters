"""specs_s32132.py - h2 (Sonnet) batch 32132: 0x516f40, 0x5c8d40, 0x435ed0. Callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _f32(f):
    return struct.unpack('<f', struct.pack('<I', _bits(f)))[0]


def g516f40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x80)
    p = rnd(c, 0x10)
    mode = r.random()
    for i in range(3):
        if mode < 0.2:
            v = 0
        elif mode < 0.5:
            v = r.choice([0, 0, 0, 0x80000000, _bits(1.0), _bits(r.uniform(-9, 9))])
        else:
            v = r.choice([_bits(r.uniform(-9, 9)), _bits(r.uniform(-1e3, 1e3)), _bits(1.0), _bits(-2.5), 0, 1, NAN,
                          0x7f800000, 0xff800000, _bits(1e30), _bits(1e-30)])
        e.w32(p + 4 * i, v)
    return [me, p]


def g5c8d40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x100)
    seti = r.random()

    def after12c(emu, k):
        if seti < 0.3:
            emu.w32(me + 0x88, r.choice([1, 5, 0x100]))
        emu.calllog.append(('s12c',))
    o44 = obj(c, 0x20, {0x12c: pystub(c, 3, this=True, side=after12c, ret=r.getrandbits(32)),
                        0x288: pystub(c, 3, this=True, ret=r.getrandbits(32))}, nslots=0x290 // 4)
    ret58 = r.choice([0, 1, r.getrandbits(32)])
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=ret58)})
    hook_rec(c, 0x5c9330, 1, this=True, pop=4)
    hook_rec(c, 0x5c8650, 0, this=True, pop=0)
    hook_rec(c, 0x5c8470, 1, this=True, pop=4, ret=r.choice([0, 1, 0x100, 0x1ff, 0xffffff00, r.getrandbits(32)]))
    hook_rec(c, 0x5c92a0, 0, this=True, pop=0)
    e.w32(me + 0x44, o44)
    e.w32(me + 0x88, r.choice([0, r.getrandbits(32), 1, 0x1234]))
    e.w32(me + 0x80, r.choice([0, 0, r.getrandbits(32), 7]))
    e.w32(me + 0x70, r.getrandbits(32))
    f = r.choice([0.0, 1.0, 0.5, r.uniform(0, 100), r.uniform(-100, 100), 1e30, -1e30, 3000.7, 1.0 / 1024, -0.0, _f32(0x7fc00000)])
    e.w32(me + 0x8c, _bits(f))
    e.wbytes(0x714380, struct.pack('<H', r.getrandbits(16)))
    t = struct.unpack('<f', struct.pack('<f', _f32(f) * 1024.0))[0] if f == f else float('nan')
    if t != t or abs(t) >= 2.0 ** 31:
        ti = -0x80000000
    else:
        ti = int(t)
    v = r.choice([ti - 1, ti, ti + 1, ti + 1, r.getrandbits(31), -r.getrandbits(31), 0x7fffffff, -0x80000000]) & 0xffffffff
    e.w32(so + 0x40, v)
    return [me]


def g435ed0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    p = rnd(c, 0x10)
    ia = r.choice([0, 1, 640, 480, 3, 1000, r.randrange(1, 2000), 0xffffffff, 0x7fffffff, r.getrandbits(32)])
    ib = r.choice([0, 1, 640, 480, 7, 1000, r.randrange(1, 2000), 0xffffffff, 0x80000000, r.getrandbits(32)])
    cam = obj(c, 0x20, {0xd8: pystub(c, 0, this=True, ret=ia), 0xdc: pystub(c, 0, this=True, ret=ib)}, nslots=0xe0 // 4)
    so = sysobj(c)
    e.w32(so + 0x190f, cam)
    holder = obj(c, 0x20, {0x10: pystub(c, 0, this=True, ret=r.choice([p, p, p, 0]))}, nslots=5)
    me = rnd(c, 0x80)
    e.w32(me + 0x10, holder)
    e.w32(me + 0x1c, r.choice([0, 1, r.getrandbits(32), 0x80000000]))
    sa = struct.unpack('<i', struct.pack('<I', ia))[0]
    sb = struct.unpack('<i', struct.pack('<I', ib))[0]

    def val(s):
        s = float(s)
        return r.choice([0.0, s, s * 0.5, s * 0.25, s * 0.75, s * 1.0 + 1.0, -s * 0.5, r.uniform(-2 * abs(s), 2 * abs(s)) if s else 1.0,
                         r.uniform(-1e3, 1e3), _f32(NAN) if False else struct.unpack('<f', struct.pack('<I', NAN))[0], 1e38, -1e38])
    e.w32(me + 0x64, _bits(val(sa)))
    e.w32(me + 0x68, _bits(val(sb)))
    out = rnd(c, 0x10)
    return [me, out]


S(0x516f40, 'GUESS copy vector and normalise', 'thiscall', None, ret=None, gen=g516f40, nan_heap=True, note='batch32132')
S(0x5c8d40, 'GUESS tick timed state', 'thiscall', None, ret=None, gen=g5c8d40, nan_heap=True, note='batch32132')
S(0x435ed0, 'GUESS cursor to normalised screen coords', 'thiscall', None, ret=None, gen=g435ed0, nan_heap=True, note='batch32132')
