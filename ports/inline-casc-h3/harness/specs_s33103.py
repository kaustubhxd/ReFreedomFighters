"""specs_s33103.py - h3 () batch 33103: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g43dac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x43d020, 0, this=True)
    s48 = pystub(c, 1, this=True)
    s4c = pystub(c, 1, this=True)
    inner = obj(c, 0x60, {0x48: s48, 0x4c: s4c})
    s10 = pystub(c, 0, this=True)
    s14 = pystub(c, 0, this=True)
    me = obj(c, 0x360, {0x10: s10, 0x14: s14})
    e.w32(me + 4, inner)
    e.wbytes(me + 0x349, bytes([r.choice([0, 0, 0, 1])]))
    e.w32(me + 0x80, r.choice([0, 1, 1, _w(c)]))
    e.wbytes(me + 0x90, bytes([r.choice([0, 1, 0xff])]))
    g = rnd(c, 0x90)
    e.wbytes(g + 0x7a, bytes([r.choice([0, 1, 1, 1, 0xff])]))
    e.w32(0x7003a0, g)
    so = sysobj(c)
    e.w32(so + 0x48, r.choice([0, 0x80000000, 0x7fc00000, _b(1.0), _b(-3.0), 0, 0]))
    return [me, _w(c)]


def _g4fd9a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s3c = pystub(c, 1, this=True)
    s60 = pystub(c, 1, this=True)
    s4c = pystub(c, 1, this=True)
    s = obj(c, 0x80, {0x3c: s3c, 0x60: s60, 0x4c: s4c})
    n = r.choice([0, 1, 2, 3, 5])
    nodes = [rnd(c, 0x20) for _ in range(n)]
    for i, nd in enumerate(nodes):
        e.w32(nd + 0xc, nodes[i + 1] if i + 1 < n else 0)
    me = rnd(c, 0x60)
    e.w32(me + 0x48, nodes[0] if n else 0)
    e.w32(me + 0x50, r.choice(nodes + [0, rnd(c, 4)]) if n else r.choice([0, 1]))
    return [me, s]


def _g5ddc10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s258 = pystub(c, 2, this=True, deref={0: 2})
    s70 = pystub(c, 1, this=True, deref={0: 3})
    s250 = pystub(c, 1, this=True)
    sbc = pystub(c, 1, this=True)
    o = obj(c, 0x260, {0x258: s258, 0x70: s70, 0x250: s250, 0xbc: sbc})
    so = sysobj(c)
    e.w32(so + 0x6f, r.choice([0, 640, 1280, 1024, 768, _w(c), 1, 0xffffff00]))
    e.w32(so + 0x73, r.choice([0, 480, 960, 1024, _w(c), 1]))
    me = rnd(c, 0x70)
    e.w32(me + 0x44, o)
    e.w32(me + 0x54, _b(c.fv(-3, 3, 0.1)))
    e.w32(me + 0x58, _b(c.fv(-3, 3, 0.1)))
    return [me]


S(0x43dac0, 'GUESS enable or reset widget scroll values', 'thiscall', None, ret=None, gen=_g43dac0, note='batch33103')
S(0x4fd9a0, 'GUESS serialise linked list with selected index', 'thiscall', None, ret='al', gen=_g4fd9a0, note='batch33103')
S(0x5ddc10, 'GUESS apply scale/position from screen size', 'thiscall', None, ret=None, gen=_g5ddc10, note='batch33103')
