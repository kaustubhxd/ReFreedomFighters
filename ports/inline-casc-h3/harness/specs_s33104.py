"""specs_s33104.py - h3 (Sonnet) batch 33104: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g5ebca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    arr = rnd(c, 0x28 * 6 + 8)
    hdr = rnd(c, 0x10)
    e.w32(hdr + 4, arr)
    me = rnd(c, 0x70)
    e.w32(me + 0x3a, hdr)
    e.w32(me + 0x3e, n)
    e.w32(me + 0x42, _w(c))
    e.w32(me + 0x52, r.choice([0, 1, 0x7fffffff, 0x80000000, 0xffffffff, _w(c), 0x01000001, 0xfffffff0]))
    e.w32(me + 0x56, r.choice([0, 1, 0x7fffffff, 0x80000000, 0xffffffff, _w(c), 0x01000001]))
    return [me]


def _g466290(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x467c40, 0, this=True)
    hook_rec(c, 0x466f60, 1, this=True, ret=lambda em, k: _w(c))
    pa = rnd(c, 0x90)
    e.w32(pa + 0x70, r.choice([0, 0x80000000, 0x7fc00000, _b(1.0), _b(-2.0)]))
    pb = rnd(c, 0x90)
    fa = r.random() < 0.8
    fb = r.random() < 0.8
    s60 = pystub(c, 1, this=True, ret=lambda em, k: (pa if fa else 0) if k == 0 else (pb if fb else 0))
    sysobj(c, table_slots={0x60: s60})
    me = rnd(c, 0x150)
    e.wbytes(me + 0x13a, bytes([r.choice([0, 1, 1, 1, 0xff])]))
    return [me, _w(c), r.choice([0, 1, 0x100, 0xff, _w(c)])]


def _g49a5d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s98 = pystub(c, 3, this=True)
    sc = pystub(c, 0, this=True)
    o = obj(c, 0xa0, {0x98: s98, 0xc: sc})
    n = r.choice([0, 1, 2, 3, 4])

    def put(em, k):
        em.w32(em.arg32(0), _w(c))

    def putn(em, k):
        em.w32(em.arg32(0), n)
    s14 = pystub(c, 1, this=True, stackmark=(0,), side=putn)
    s40 = pystub(c, 1, this=True, stackmark=(0,), side=put)
    s50 = pystub(c, 1, this=True, stackmark=(0,), side=put)
    me = obj(c, 0x60, {0x14: s14, 0x40: s40, 0x50: s50})
    return [me, o]


S(0x5ebca0, 'GUESS init keyframe array defaults', 'thiscall', None, ret=None, gen=_g5ebca0, note='batch33104')
S(0x466290, 'GUESS replace table entry and fade', 'thiscall', None, ret='eax', gen=_g466290, note='batch33104')
S(0x49a5d0, 'GUESS replay recorded vertices into target', 'thiscall', None, ret=None, gen=_g49a5d0, note='batch33104')
