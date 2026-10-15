"""specs_s43006.py - t4 (Sonnet) batch 43006. 0x58aaf0: slot stubs (this = vtable object); 0x54c8f0: 0x549780 / 0x5496e0 hooked, slots 0x3c / 0x44 stubs (stdcall);
0x650f34: table row and count are random per case."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _fl(r):
    k = r.random()
    if k < 0.06:
        return r.choice([0.0, -0.0, float('nan'), float('inf'), float('-inf')])
    if k < 0.2:
        return r.uniform(-1e5, 1e5)
    return r.uniform(-20, 20)


def _g58aaf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = obj(c, 0x40, {0x3c: pystub(c, 1, this=True), 0x68: pystub(c, 1, this=True, deref={0: 1}),
                       0x60: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True)})
    n = r.choice([0, 1, 2, 3, 4, 6])
    b = rnd(c, 4 + 0x15 * 6 + 0x10)
    e.w32(b, n)
    return [me, b]


def _g54c8f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x549780, 1, this=True, ret=lambda em, k: _w(c))
    nv = r.choice([0, 50, 99, 100, 101, 5000, 99999, 100000, 100001, 0x7fffffff, 0x80000000, 0xffffffff, _w(c)])
    hook_rec(c, 0x5496e0, 1, this=True, ret=nv)
    o = obj(c, 0x20, {0x3c: pystub(c, 2, stackmark=(0,)), 0x44: pystub(c, 2, stackmark=(0,))})
    me = rnd(c, 0x6400)
    e.w32(me + 0x63ec, o)
    e.wbytes(me + 0x63d7, struct.pack('<f', _fl(r)))
    return [me, rnd(c, 0x40)]


def _g650f30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    i = r.randrange(0, 4)
    for k in range(8):
        v = r.choice([float(r.randrange(0, 12)), r.uniform(0, 12), _fl(r)])
        e.w32(0x6c33b8 + i * 32 + 4 * k, _fb(v))
    e.w32(0x6f5a98, r.choice([0, 1, 2, 5, 8, 12, 20]))
    me = rnd(c, 0x40)
    e.w32(me + 0x10, rnd(c, 0x40))
    return [me, i]


S(0x58aaf0, 'GUESS replay recorded settings through slots', 'fastcall', None, ret='eax', gen=_g58aaf0, note='batch43006')
S(0x54c8f0, 'GUESS push two derived values into helper object', 'thiscall', None, ret=None, gen=_g54c8f0, note='batch43006')
S(0x650f30, 'GUESS bucket index per step from threshold row', 'thiscall', None, ret=None, gen=_g650f30, note='batch43006')
