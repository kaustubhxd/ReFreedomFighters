"""specs_s33080.py - h3 () batch 33080: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fl(c):
    return F(c.fv(-10.0, 10.0, 0.25))


def _fbits(c):
    return struct.unpack('<I', struct.pack('<f', c.fv(-10.0, 10.0, 0.25)))[0]


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g4759b0(c):
    clear_hooks(c)
    e = c.emu
    s = pystub(c, 8, this=True, ret=lambda em, k: _w(c))
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0x1c, s)
    me = rnd(c, 0x360)
    e.w32(me + 0x34f, vt)
    return [me, _w(c), _w(c), _fl(c), _fl(c), _fl(c), _fl(c), _fl(c)]


def _g5166e0(c):
    clear_hooks(c)
    hook_rec(c, 0x4690b0, 0, this=True, side=lambda em, k: em.calllog.append(('n', em.reg('ecx'))))
    hook_rec(c, 0x5248e0, 1, this=True)
    me = rnd(c, 0x80)
    c.emu.wbytes(me + 0x11, bytes(16))
    return [me, _fl(c)]


def _g5eebf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5ee920, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    so = sysobj(c)
    g48 = r.choice([r.uniform(-5, 5), 1.0, 2.0, 3.0, 0.5, float('nan')])
    e.w32(so + 0x48, _b(g48 if g48 == g48 else 0x7fc00000 and 0.0) if g48 == g48 else 0x7fc00000)
    me = rnd(c, 0x90)
    cur = r.choice([0.0, 1.0, 2.5, 3.0, 3.0000002, _fbits(c)])
    e.w32(me + 0x41, cur if isinstance(cur, int) else _b(cur))
    e.w32(me + 0x11, r.choice([1, 1, 0, 2]))
    e.w32(me + 0x19, r.choice([0, 1, 2, 5]))
    e.wbytes(me + 0x77, bytes([r.choice([0, 0xff])]))
    return [me]


def _g470670(c):
    clear_hooks(c)
    e = c.emu
    s3c = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', 0x3c)))
    s4c = pystub(c, 1, this=True, side=lambda em, k: em.calllog.append(('v', 0x4c)))
    a = obj(c, 0x80, {0x3c: s3c, 0x4c: s4c})
    me = rnd(c, 0x80)
    e.w32(me + 0x56, _fbits(c))
    return [me, a]


def _g4f1d10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s250 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('v', 0x250)))
    s254 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('v', 0x254)))
    o = obj(c, 0x300, {0x250: s250, 0x254: s254})
    me = rnd(c, 0x1e0)
    e.w32(me + 0x6f, o)
    e.w32(me + 0x1d7, r.choice([0xbf800000, 0, 0x80000000, 0x7fc00000, _fbits(c), 0x3f800000, 0xbf800001]))
    return [me]


def _g534010(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    size = 0x78 + 0x400 * 0xfd + 0x20
    blk = e.alloc(size, 4)
    for _ in range(80):
        i = r.randrange(0, 0x400)
        ent = blk + 0x78 + i * 0xfd
        e.w32(ent - 0x68, r.choice([0, 1, _w(c)]))
        e.w32(ent, r.choice([0, 0x80000000, 0x7fc00000, _fbits(c), _fbits(c)]))
    me = rnd(c, 0x20)
    e.w32(me + 8, blk)
    return [me, _fl(c)]


def _g6550b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x655270, 0, this=True, side=lambda em, k: em.calllog.append(('o', 1)))
    e.w32(0x6761f0, pystub(c, 0, side=lambda em, k: em.calllog.append(('imp', 0))))
    so = sysobj(c)
    e.w32(so + 0x9ef, _fbits(c))
    sc8 = pystub(c, 0, this=True, side=lambda em, k: em.calllog.append(('v', 0xc8, em.rbytes(me + 0x1185, 1)[0])))
    me = rnd(c, 0x1200)
    vt = e.alloc(0x200, 4)
    e.w32(vt + 0xc8, sc8)
    e.w32(me, vt)
    e.w32(me + 0x137, r.choice([0, 1, _w(c)]))
    e.wbytes(me + 0x1185, bytes([r.choice([1, 0xff])]))
    return [me, r.choice([0, 1, 0xffff, 0x8000, 0x7fff, 0x12345, _w(c)])]


def _g473a10(c):
    clear_hooks(c)
    e = c.emu
    s = pystub(c, 5, this=True)
    me = obj(c, 0x400, {0x4b4: s})
    e.wbytes(me + 0x3e8, bytes([0xff]))
    return [me]


S(0x4759b0, 'GUESS subobject vcall with float and vec4', 'thiscall', None, ret=None, gen=_g4759b0, note='batch33080')
S(0x5166e0, 'GUESS init constants and forward float', 'thiscall', None, ret=None, gen=_g5166e0, note='batch33080')
S(0x5eebf0, 'GUESS accumulate time and tick counter', 'thiscall', None, ret=None, gen=_g5eebf0, note='batch33080')
S(0x470670, 'GUESS vcall 3c then vcall 4c with float field', 'thiscall', None, ret='al', gen=_g470670, note='batch33080')
S(0x4f1d10, 'GUESS vcall by float state', 'thiscall', None, ret=None, gen=_g4f1d10, note='batch33080')
S(0x534010, 'GUESS add to nonzero floats in table', 'thiscall', None, ret=None, gen=_g534010, note='batch33080')
S(0x6550b0, 'GUESS add short to global float then vcall', 'thiscall', None, ret=None, gen=_g6550b0, note='batch33080')
S(0x473a10, 'GUESS vcall 4b4 with constant vec', 'thiscall', None, ret=None, gen=_g473a10, note='batch33080')
