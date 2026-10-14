"""specs_s34149.py - tier H floats as raw bit patterns (ordinary, edge, NaN). 0x5247e0: float cells behind the pointers at +0x18 and +0x1c; the mask at 0x67cd50 is the exe's. 0x598e10: callee 0x5eab20 hooked (3 args, one a float). 0x5d0c30: guard byte +0xb30 zero in half. 0x516040: unaligned float accumulators +0x41 and +0x55."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r):
    k = r.random()
    if k < 0.2:
        v = r.choice(EDGE_F)
    elif k < 0.27:
        return r.getrandbits(32)
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g5247e0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x30)
    a, b = rnd(c, 0x10), rnd(c, 0x10)
    c.emu.w32(a, _fbits(r))
    c.emu.w32(b, _fbits(r) if r.random() < 0.8 else c.emu.r32(a))
    if r.random() < 0.12:   # two different NaNs: the result takes the first operand's payload
        c.emu.w32(a, 0x7f800000 | (r.getrandbits(23) | 1) | (r.getrandbits(1) << 31))
        c.emu.w32(b, 0x7f800000 | (r.getrandbits(23) | 1) | (r.getrandbits(1) << 31))
    c.emu.w32(me + 0x18, a)
    c.emu.w32(me + 0x1c, b)
    return [me]


def _g598e10(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5eab20, 3, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x2300)
    c.emu.wbytes(me + 0x22d7, rnd(c, 0x20).to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32), _fbits(r)]


def _g5d0c30(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xb40)
    c.emu.wbytes(me + 0xb30, bytes([0 if r.random() < 0.5 else r.choice([1, 2, 0xff])]))
    i = r.choice([0, 1, -1, 100, -100, 0x7fffffff, -0x80000000, r.getrandbits(32), r.randrange(-5000, 5000)])
    return [me, i & 0xffffffff]


def _g516040(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x80)
    c.emu.wbytes(me + 0x41, _fbits(r).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x55, _fbits(r).to_bytes(4, 'little'))
    return [me, _fbits(r)]


S(0x5247e0, 'GUESS absolute float difference', 'thiscall', None, ret=None, gen=_g5247e0, note='batch34149')
S(0x598e10, 'GUESS forward float to sub object', 'thiscall', None, ret='eax', gen=_g598e10, note='batch34149')
S(0x5d0c30, 'GUESS store int over constant once', 'thiscall', None, ret=None, gen=_g5d0c30, note='batch34149')
S(0x516040, 'GUESS accumulate scaled float', 'thiscall', None, ret=None, gen=_g516040, note='batch34149')
