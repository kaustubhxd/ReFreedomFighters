"""specs_s33084.py - h3 (Sonnet) batch 33084: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fb(c, lo=-10.0, hi=10.0):
    return _b(c.fv(lo, hi, 0.25))


def _g4bb260(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s128 = pystub(c, 3, this=True, ret=lambda em, k: _w(c))
    o = obj(c, 0x20, {0x128: s128})
    flag = r.random() < 0.7
    s58 = pystub(c, 1, this=True, ret=lambda em, k: o if flag else 0)
    sysobj(c, table_slots={0x58: s58})
    s68 = pystub(c, 2, this=True)
    me = obj(c, 0x100, {0x68: s68})
    inner = rnd(c, 0x80)
    e.w32(inner + 0x74, r.choice([0, 0x80000000, 0x7fc00000, _b(1.0), _fb(c)]))
    mid = rnd(c, 0x20)
    e.w32(mid + 0x18, inner)
    e.w32(me + 0x44, mid)
    return [me]


def _g4f80a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x560360, 1, this=True)

    def side(em, k):
        # callee changes [this+0x9f]
        t = em.reg('ecx')
        if r.random() < 0.8:
            em.w32(t + 0x9f, _fb(c))
    s370 = pystub(c, 1, this=True, side=side)
    me = obj(c, 0x400, {0x370: s370})
    e.w32(me + 0x9f, _fb(c))
    e.w32(me + 0xa3, r.choice([_fb(c), _b(2.0), _b(0.5), 0, 0x80000000]))
    e.w32(me + 0xcf, _fb(c))
    p = rnd(c, 8)
    e.w32(p, _fb(c))
    return [me, p]


def _g6560c0(c):
    clear_hooks(c)
    r = c.rng
    inp = rnd(c, 8)
    c.emu.wbytes(inp, bytes(r.choice([0, 255, 1, 128, r.getrandbits(8)]) for _ in range(4)))
    return [rnd(c, 0x10), inp]


S(0x4bb260, 'GUESS maybe slot 0x128 on table object then slot 0x68', 'thiscall', None, ret=None, gen=_g4bb260, note='batch33084')
S(0x4f80a0, 'GUESS slot 0x370 with scaled delta, adjust offset', 'thiscall', None, ret=None, gen=_g4f80a0, note='batch33084')
S(0x6560c0, 'GUESS bytes to float colour 0..1', 'stdcall', None, ret=None, gen=_g6560c0, note='batch33084')
