"""specs_s41003.py - t2 () batch 41003: 0x52d3f0, 0x4bf110. The CRT sqrt thunk runs as exe code; vtable slots are recorders; engine slot 0x1c0 returns a float on st0."""
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


def _fl(r):
    return r.choice([r.uniform(-9, 9), r.uniform(0, 1000), 0.0, 1.0, -0.0, NAN_F, 1e30, r.uniform(0, 5)])


NAN_F = struct.unpack('<f', struct.pack('<I', NAN))[0]


def _w(e, a, v):
    e.wbytes(a, struct.pack('<I', v & 0xffffffff))


def g52d3f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x40)
    big = r.random() < 0.15
    for off in (4, 8, 0xc):
        _w(e, me + off, r.choice([r.randrange(-5000, 5000), r.randrange(-100, 100), 0, r.getrandbits(32)]) if not big else r.getrandbits(32))
    _w(e, me + 0x1c, _bits(r.choice([r.uniform(0, 8000), 1e30, 0.0, r.uniform(-5, 5), NAN, 1e9, 7000.0])))
    _w(e, me + 0x20, _bits(r.choice([r.uniform(0, 3), 1.0, 0.0, -1.0, 1e10, NAN])))
    p = rnd(c, 0x10)
    if r.random() < 0.2:
        _w(e, p, 0)
    else:
        _w(e, p, r.getrandbits(32) | 1)
    pt = rnd(c, 0x10)
    for i in range(3):
        _w(e, pt + 4 * i, r.choice([r.randrange(-5000, 5000), r.randrange(-100, 100), 0, r.getrandbits(32), 0x80000000, 0x7fffffff]))
    if r.random() < 0.25:   # exact tie: pt = this + (k, 0, dz) with |dz| * scale = 0 -> w = k, [this+0x1c] = k
        k = r.choice([0, 3, 5, 100, 7])
        base = [int.from_bytes(e.rbytes(me + o, 4), 'little') for o in (4, 8, 0xc)]
        for i, d in enumerate((k, 0, 0)):
            _w(e, pt + 4 * i, base[i] + d)
        _w(e, me + 0x1c, _bits(float(k)) if r.random() < 0.7 else _bits(float(k) + 1.0))
        _w(e, p, 1)
    return [me, r.getrandbits(32), p, r.getrandbits(32), pt, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g4bf110(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fv = r.choice([r.uniform(-3, 3), 0.0, 1.0, -0.5, NAN_F])
    sysobj(c, rand=fv)
    q = rnd(c, 0x90)
    e.wbytes(q + 0x40, bytes([r.choice([0, 8, 0xff, 0xf7, r.getrandbits(8)])]))
    m = rnd(c, 0x20)
    e.w32(m + 0x18, q)
    me = obj(c, 0x90, {0x84: pystub(c, 0, this=True, side=_log('s84')), 0x64: pystub(c, 1, this=True)}, nslots=0x90 // 4)
    e.w32(me + 0x44, m if r.random() < 0.9 else 0)
    a = r.choice([r.getrandbits(32), r.getrandbits(16), 0x1234, 0, 0xffff])
    w1 = a & 0xffff if r.random() < 0.55 else r.getrandbits(16)
    w2 = a & 0xffff if r.random() < 0.4 else r.getrandbits(16)
    e.wbytes(me + 0x4c, struct.pack('<H', w1))
    e.wbytes(me + 0x4e, struct.pack('<H', w2))
    e.wbytes(me + 0x50, bytes([r.choice([0, 0, 1, 0xff])]))
    e.wbytes(me + 0x71, bytes([r.choice([0, 1, 0xff])]))
    e.wbytes(me + 0x6d, struct.pack('<I', _bits(r.choice([fv, fv + 1.0, fv - 1.0, 0.0, 5.0, -5.0, NAN_F]) if fv == fv else 0.0)))
    e.wbytes(me + 0x65, struct.pack('<I', _bits(r.choice([0.0, -0.0, 1.0, -2.0, NAN_F, 1e-30]))))
    return [me, a, r.getrandbits(32)]


S(0x52d3f0, 'GUESS closer-point test', 'thiscall', None, ret='eax', gen=g52d3f0, nan_heap=True, note='batch41003')
S(0x4bf110, 'GUESS handle input event', 'thiscall', None, ret='eax', gen=g4bf110, nan_heap=True, note='batch41003')
