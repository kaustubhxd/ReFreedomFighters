"""specs_s33098.py - h3 () batch 33098: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g5c3310(c):
    clear_hooks(c)
    s60 = pystub(c, 1, this=True)
    s4c = pystub(c, 1, this=True)
    o = obj(c, 0x80, {0x60: s60, 0x4c: s4c})
    return [rnd(c, 0x130), o]


def _g4805a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4804e0, 0, this=True)
    blocks = [rnd(c, 0x20) for _ in range(12)]
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: blocks[min(k, 11)])
    me = rnd(c, 0x90)
    for i in range(6):
        v = r.choice([0, 0x80000000, 0x7fc00000, _b(1.0), _b(-2.5), _w(c), 0, 0])
        e.w32(me + 0x34 + 12 * i, v)
    return [me]


def _g471ad0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s328 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0xff, _w(c)]))
    inner = obj(c, 0x340, {0x328: s328})
    rv = c.fv(-20.0, 20.0, 0.25)
    fv = lambda em, k: rv
    s338 = pystub(c, 0, this=True, st0=fv)
    inner2 = obj(c, 0x340, {0x338: s338})
    cnt = [0]

    def s350(em, k):
        pass
    sy = pystub(c, 0, this=True, ret=lambda em, k: inner if k % 2 == 0 else inner2)
    me = obj(c, 0x100, {0x350: sy})
    so = sysobj(c)
    e.wbytes(me + 0xbf, bytes([r.choice([0, 1, 0xff, 1, 1])]))
    fl = c.fv(-20.0, 20.0, 0.25)
    e.w32(me + 0xd1, _b(fl))
    try:
        x = struct.unpack('<f', struct.pack('<f', (rv + struct.unpack('<f', struct.pack('<f', fl))[0]) * 1024.0))[0]
        k = 0 if x != x or abs(x) >= 2147483648.0 else int(x)
    except OverflowError:
        k = 0
    t = r.choice([k, k + 1, k - 1, k, k + 2, _w(c), 0, 0x7fffffff, 0x80000000])
    e.w32(so + 0x40, t & 0xffffffff)
    return [me]


S(0x5c3310, 'GUESS write five parameters through stream slots', 'thiscall', None, ret='al', gen=_g5c3310, note='batch33098')
S(0x4805a0, 'GUESS allocate six optional channel records', 'thiscall', None, ret=None, gen=_g4805a0, note='batch33098')
S(0x471ad0, 'GUESS deadline-reached predicate', 'thiscall', None, ret='al', gen=_g471ad0, note='batch33098')
