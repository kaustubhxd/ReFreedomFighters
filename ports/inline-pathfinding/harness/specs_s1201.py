"""specs_s1201.py - pathfinding batch 1201: local coordinates and the time slice."""
import math
import struct
from pilot import S, f32


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _sf(x):
    try:
        return f32(x)
    except OverflowError:
        return float('inf') if x > 0 else float('-inf')


def _octree(c):
    r = c.rng
    e = c.emu
    o = _rnd(c, 0x80)
    for k in range(3):
        lo = c.fv(-3000, 3000) if r.random() < 0.85 else c.fv()
        e.wf32(o + 6 + 4 * k, lo)
        e.wf32(o + 0x12 + 4 * k, _sf(lo + abs(c.fv(1, 4000))) if r.random() < 0.85 else c.fv())
    for off in (0x3c, 0x40, 0x44):
        e.w32(off + o, r.randint(1, 600) if r.random() < 0.9 else r.getrandbits(32))
    return o


def _vec(c, big=4000):
    a = c.emu.alloc(16, 4)
    for k in range(3):
        c.emu.wf32(a + 4 * k, c.fv(-big, big))
    return a


def _coords(c):
    o = _octree(c)
    return [o, _rnd(c, 8), _vec(c)]


S(0x530b60, 'ZPFOctree_packed::GetLocalCoords', 'thiscall', None, gen=_coords)


def _ceil(e, r):
    x = struct.unpack('<d', e.rbytes(e.reg('esp') + 4, 8))[0]
    y = x if (x != x or x in (float('inf'), float('-inf'))) else float(math.ceil(x))
    if y == 0 and (x < 0 or str(x).startswith('-')):
        y = -0.0
    e.ret(st0=y)


def _vector(c):
    c.emu.stub_import('ceil', _ceil)   # CRT ceil (exact; result fits a float for float inputs)
    if c.rng.random() < 0.5:
        c.emu.w32(0x72580c, 1)   # CRT SSE2 flag as in the running game
    o = _octree(c)
    return [o, _rnd(c, 8), _vec(c, 600)]


S(0x530db0, 'ZPFOctree_packed::GetLocalVector', 'thiscall', None, gen=_vector)


def _ctx(c):
    r = c.rng
    e = c.emu
    now = r.getrandbits(32) if r.random() < 0.3 else r.randint(0, 5000)
    vt = e.logging_vtable('ZSysInterface', 0x80, impl={0x1c8: lambda em, a: (now, None)}, argwords={0x1c8: 2})
    sysi = e.alloc(16)
    e.w32(sysi, vt)
    e.w32(0x70039c, sysi)
    ctx = _rnd(c, 0x50)
    k = r.random()
    if k < 0.15:
        e.w32(ctx + 0x44, 0)
    else:
        ts = _rnd(c, 0x14)
        e.w8(ts + 0x10, r.choice([0, 1, 1, 0x80]))
        e.w32(ts, r.randint(0, 5000))
        e.w32(ts + 4, r.choice([0, 10, 100, 1000, r.getrandbits(32)]))
        e.w32(ctx + 0x44, ts)
    return [ctx]


S(0x52b080, 'CContext::isTimeUp', 'thiscall', None, gen=_ctx)
