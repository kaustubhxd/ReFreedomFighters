"""specs_s40002.py - tier H. 0x5ec120: table [unaligned [this+0x62]] of random records, cached (a, b) equal to the stored words a third of the time, 16-bit sizes include 0.
0x5f3db0 / 0x500360: kind byte 0/1/2/3/255, assert hook always set, system object [0x700390] slot 0x20 -> object slot 0x2c (cdecl). 0x523ec0: slot 0x24 returns on st0 a float around |[this+0x28]|, slot 8 recorded, flag byte at +0x46, system +0x40.
0x5bf550: unaligned width/height in the system object, [this+0x44] slot 0x70 records the 3 floats, this slot 0x58, /GS cookie check real. 0x4e7be0: object slots 0x54/0x4c/0x60 recorded."""
import struct
from pilot import S, EDGE_F, F
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, hook_rec


def _fb(v):
    try:
        return struct.unpack('<I', struct.pack('<f', v))[0]
    except OverflowError:
        return 0x7f800000 if v > 0 else 0xff800000


def _rf(r):
    k = r.random()
    if k < 0.15:
        return _fb(r.choice(EDGE_F))
    if k < 0.2:
        return r.getrandbits(32)
    return _fb(r.uniform(-1000, 1000))


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g5ec120(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    arr = rnd(c, 0x40)
    recs = [rnd(c, 0x40) for _ in range(4)]
    for i, t in enumerate(recs):
        e.w32(arr + 4 * i, t)
        e.wbytes(t + 4, struct.pack('<HH', r.choice([0, 1, 7, 64, 255, 65535]), r.choice([0, 1, 9, 32, 256, 65535])))
    idx = r.randrange(0, 4)
    a = r.choice([0, 1, 5, 100, 0xffff, 0x10000, 0x12345, -1 & 0xffffffff, -7 & 0xffffffff, r.randrange(0, 2000)])
    b = r.choice([0, 1, 5, 100, 0xffff, 0x10001, -1 & 0xffffffff, r.randrange(0, 2000)])
    if r.random() < 0.35:
        e.wbytes(recs[idx] + 0x28, struct.pack('<HH', a & 0xffff, b & 0xffff))
    elif r.random() < 0.3:
        e.wbytes(recs[idx] + 0x28, struct.pack('<HH', a & 0xffff, (b + 1) & 0xffff))
    me = rnd(c, 0x100)
    e.wbytes(me + 0x62, arr.to_bytes(4, 'little'))
    return [me, a, b, idx]


def _gkind(c, line_obj=True):
    r = c.rng
    e = c.emu
    _assert_hook(c)
    o2 = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)}, nslots=0x30 // 4)
    s2 = obj(c, 0x20, {0x20: pystub(c, 2, ret=o2, this=True)}, nslots=0x24 // 4)
    e.w32(0x700390, s2)
    me = rnd(c, 0x20)
    me_kind = r.choice([0, 0, 2, 2, 1, 3, 255, r.getrandbits(8)])
    e.wbytes(me + 4, bytes([me_kind]))
    return me


def _g5f3db0(c):
    clear_hooks(c)
    me = _gkind(c)
    return [me, rnd(c, 0x10)]


def _g500360(c):
    clear_hooks(c)
    me = _gkind(c)
    return [me, F(struct.unpack('<f', struct.pack('<I', _rf(c.rng)))[0])]


def _g523ec0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = None

    def st0(em, k):
        x = struct.unpack('<f', em.rbytes(me + 0x28, 4))[0]
        if x != x or x in (float('inf'), float('-inf')):
            return r.choice([0.0, 1.0, -3.5])
        return abs(x) * r.choice([0.0, 0.5, 1.0, 1.0, 2.0, 1.0000001, 0.9999999]) * r.choice([1, 1, -1])
    me = obj(c, 0x80, {0x24: pystub(c, 2, this=True, st0=st0), 0x8: pystub(c, 2, this=True)}, nslots=0x28 // 4)
    e.w32(me + 0x28, _fb(r.choice([0.0, 1.0, -2.5, 100.0, r.uniform(-50, 50), r.uniform(-1e-3, 1e-3)])) if r.random() < 0.9 else r.getrandbits(32))
    e.wbytes(me + 0x46, bytes([r.choice([0, 1, 1, 7])]))
    so = sysobj(c)
    e.w32(so + 0x40, r.choice([0, 1, 1000, 123456, 0x7fffffff, 0x80000000, r.getrandbits(32)]))
    return [me, F(struct.unpack('<f', struct.pack('<I', _rf(r)))[0])]


def _g5bf550(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c)
    so = e.r32(0x70039c)
    e.wbytes(so + 0x6f, struct.pack('<ii', r.choice([0, 1, -1, 640, 1919, -1920, 0x7fffffff, -0x80000000, r.randrange(-3000, 3000)]),
                                   r.choice([0, 1, -1, 480, 1081, 0x7fffffff, -0x80000000, r.randrange(-3000, 3000)])))
    tgt = obj(c, 0x20, {0x70: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x74 // 4)
    me = obj(c, 0x80, {0x58: pystub(c, 0, this=True)}, nslots=0x5c // 4)
    e.w32(me + 0x44, tgt)
    return [me]


def _g4e7be0(c):
    clear_hooks(c)
    me = rnd(c, 0x40)
    o = obj(c, 0x20, {0x54: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True), 0x60: pystub(c, 1, this=True)}, nslots=0x64 // 4)
    return [me, o]


S(0x5ec120, 'GUESS set cached size ratio', 'thiscall', None, ret=None, gen=_g5ec120, note='batch40002')
S(0x5f3db0, 'GUESS accumulate float state', 'thiscall', None, ret=None, gen=_g5f3db0, note='batch40002')
S(0x523ec0, 'GUESS float update step', 'thiscall', None, ret=None, gen=_g523ec0, note='batch40002')
S(0x500360, 'GUESS set float state', 'thiscall', None, ret='eax', gen=_g500360, note='batch40002')
S(0x5bf550, 'GUESS center on screen', 'thiscall', None, ret=None, gen=_g5bf550, note='batch40002')
S(0x4e7be0, 'GUESS copy settings to object', 'thiscall', None, ret=None, gen=_g4e7be0, note='batch40002')
