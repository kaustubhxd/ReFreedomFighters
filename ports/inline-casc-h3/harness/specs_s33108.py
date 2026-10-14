"""specs_s33108.py - h3 () batch 33108: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


_V = [0.0, 1.0, 0.5, -0.5, 2.0, 0.25, 0.9999999, float('nan'), -0.0, 1e-3]


def _vb(r, c):
    x = r.choice(_V + [c.fv(-3, 3, 0.1)])
    return 0x7fc00000 if x != x else _b(x)


def _g5eff00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5eeab0, 1, this=True)
    so = sysobj(c)
    e.w32(so + 0x48, _vb(r, c))
    me = rnd(c, 0xa0)
    e.wbytes(me + 4, bytes([r.choice([0, 1, 1, 1, 0xff])]))
    e.w32(me + 0x94, r.choice([0, 1, 2, 3, 0, 1, 2]))
    e.w32(me + 0x84, _vb(r, c))
    e.w32(me + 0x88, _vb(r, c))
    e.w32(me + 0x8c, _vb(r, c))
    e.w32(me + 0x90, _vb(r, c))
    e.wbytes(me + 0x98, bytes([r.choice([0, 1, 0xff])]))
    return [me]


def _g5267b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x516780, 1, this=True)
    hook_rec(c, 0x52a200, 0, this=True)
    me = rnd(c, 0xd39 + 0x133 * 4 + 0x20)
    e.w32(me + 0x8c, r.choice([0, 1, 2, 3, 0xffffffff, 0x80000000 | 5]))
    e.w32(me + 0x90, r.choice([0, 1, 2, 3, 4, 0xfffffffe]))
    return [me, _w(c)]


def _setlog(c):
    e = c.emu
    r = c.rng

    def side(em, k):
        if em.arg32(1) == 0x6a215c:
            em.calllog.append(('hi', em.arg32(3)))
    slog = pystub(c, 3, pop=0, ret=lambda em, k: _w(c), side=side)
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))


def _g5354a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c)
    cnt = r.choice([1, 2, 4])
    arr = rnd(c, 0xa4 * 4 + 16)
    o = rnd(c, 0x1210)
    e.w32(o + 0x11e9, cnt)
    e.w32(o + 0x11f9, arr)
    me = rnd(c, 0x5310)
    e.w32(me + 0x52fe, o if r.random() < 0.9 else 0)
    idx = r.choice([0, cnt - 1, cnt, cnt + 1, 0xffffffff, 0, cnt - 1, 0x80000000])
    return [me, idx, _vb(r, c)]


S(0x5eff00, 'GUESS fade state machine update', 'thiscall', None, ret=None, gen=_g5eff00, note='batch33108')
S(0x5267b0, 'GUESS update two arrays of sub-objects', 'thiscall', None, ret=None, gen=_g5267b0, note='batch33108')
S(0x5354a0, 'GUESS set float field of indexed record with range checks', 'thiscall', None, ret=None, gen=_g5354a0, note='batch33108')
