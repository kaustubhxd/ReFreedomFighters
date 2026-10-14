"""specs_s33085.py - h3 () batch 33085: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g4bb980(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e6330, 1, this=True)
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    s = rnd(c, 0x20)
    data = rnd(c, 8)
    e.wbytes(data, bytes([r.choice([0xff, 2, 0x42, 0x82, 0xc2, 0x22, 0x62, 0xe2, 0x01, 0x3f, 0, 0x03, 0x12, r.getrandbits(8)])]))
    e.w32(s, data)
    return [rnd(c, 0x110), s]


def _g537370(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    tab = rnd(c, 0x200)
    hi = r.choice([1, 2, 3, 7, 12])
    xs = r.choice([hi, hi, 0, 1, 2, 5])
    n = r.randrange(0, max(xs, 1))
    val = r.choice([0.0, 0.5, 0.999, 0.25, 0.9999999, r.uniform(0.0, 1.0), r.uniform(0.0, 1.0),
                    (n + 0.015) / max(xs, 1), (n + 0.005) / max(xs, 1)])
    val = min(val, 0.9999999)
    sysobj(c, rand=lambda em, k: val)
    me = rnd(c, 0x5310)
    off = r.choice([0, 0, 0x40, 0x80])
    e.w32(me + 0x5302, off)
    arg = rnd(c, 0x20)
    e.w32(arg + 0x10, tab + 0x40 - off)
    e.wbytes(arg + 8, struct.pack('<H', xs))
    return [me, arg]


def _g47bce0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = _b(360000.0)
    f = r.choice([base, base + 1, base - 1, 0, 0x7fc00000, _b(1e9), _b(-5.0), _b(c.fv(-1e6, 1e6, 0.1))])
    hook_rec(c, 0x4e0830, 0, this=True, st0=lambda em, k: struct.unpack('<f', struct.pack('<I', f))[0])
    s63c = pystub(c, 1, this=True)
    me = obj(c, 0x780, {0x63c: s63c})
    p = rnd(c, 0x20)
    e.w32(p + 8, r.choice([0, 1, 3, _w(c) & 0xfff]))
    e.w32(p + 0xc, rnd(c, 0x40))
    e.w32(me + 0x695, r.choice([p, p, p, 0]))
    return [me, rnd(c, 0x10)]


S(0x4bb980, 'GUESS read two matrices-ish then two floats when type 2', 'thiscall', None, ret=None, gen=_g4bb980, note='batch33085')
S(0x537370, 'GUESS random table pick', 'thiscall', None, ret='eax', gen=_g537370, note='batch33085')
S(0x47bce0, 'GUESS set vec3 + flag, maybe slot 0x63c', 'thiscall', None, ret=None, gen=_g47bce0, note='batch33085')
