"""specs_s33077.py - h3 (Sonnet) batch 33077: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fl(c):
    return F(c.fv(-10.0, 10.0, 0.25))


def _fbits(c):
    return struct.unpack('<I', struct.pack('<f', c.fv(-10.0, 10.0, 0.25)))[0]


def _ints(c):
    return c.rng.choice([0, 1, 0xffffffff, 127, 0x7fffffff, 0x80000000, _w(c), c.rng.randrange(-1000, 1000) & 0xffffffff])


def _g5184d0(c):
    clear_hooks(c)
    hook_rec(c, 0x525e20, 2, this=True)
    return [rnd(c, 0x300), _fl(c), _w(c)]


def _g63f070(c):
    clear_hooks(c)
    hook_rec(c, 0x65f1e0, 2, this=True)
    return [rnd(c, 0x20), _w(c), _fl(c)]


def _g4dc5d0(c):
    clear_hooks(c)
    return [rnd(c, 0x60), _fl(c), _fl(c), _fl(c)]


def _g537860(c):
    clear_hooks(c)
    p = rnd(c, 0x20)
    c.emu.w32(p + 0xc, _fbits(c))
    return [c.rng.choice([p, p, 0])]


def _g5d0ba0(c):
    clear_hooks(c)
    me = rnd(c, 0xb40)
    c.emu.wbytes(me + 0xb30, bytes([c.rng.choice([0, 0, 1, 0xff])]))
    return [me, _ints(c)]


def _g487a50(c):
    clear_hooks(c)
    p = rnd(c, 0x80)
    c.emu.w32(p + 0x5c, _ints(c))
    c.emu.w32(p + 0x6c, _ints(c))
    return [p]


def _g5ea840(c):
    clear_hooks(c)
    return [rnd(c, 0x1d20), _fl(c)]


def _g523180(c):
    clear_hooks(c)
    s8 = pystub(c, 2, this=True)
    me = obj(c, 0x80, {8: s8})
    c.emu.w32(me + 0x57, _fbits(c))
    c.emu.w32(me + 0x5b, _fbits(c))
    return [me]


S(0x5184d0, 'GUESS forward float and arg to sub-object', 'thiscall', None, ret=None, gen=_g5184d0, note='batch33077')
S(0x63f070, 'GUESS forward arg and float to sub-object', 'thiscall', None, ret=None, gen=_g63f070, note='batch33077')
S(0x4dc5d0, 'GUESS store three floats and flag', 'thiscall', None, ret=None, gen=_g4dc5d0, note='batch33077')
S(0x537860, 'GUESS float field or zero', 'stdcall', None, ret='st0', gen=_g537860, note='batch33077')
S(0x5d0ba0, 'GUESS once int over -127', 'thiscall', None, ret=None, gen=_g5d0ba0, note='batch33077')
S(0x487a50, 'GUESS ratio of two int fields', 'stdcall', None, ret='st0', gen=_g487a50, note='batch33077')
S(0x5ea840, 'GUESS clamp negative float to zero', 'thiscall', None, ret=None, gen=_g5ea840, note='batch33077')
S(0x523180, 'GUESS vcall 8 with two float fields', 'thiscall', None, ret=None, gen=_g523180, note='batch33077')
