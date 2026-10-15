"""specs_s45003.py - tier H slice 5. 0x4616c0: hooked 0x43df70, 0x4db7c0 (writes 3 random floats incl. edge values), 0x4dce50 (float logged as bits), 0x4dd060 (vector logged), /GS 0x633654.
0x561f70: state 0..7 (3 and 5 mostly), hooked 0x4f9680 and 0x563750, engine global 0x70039c with a random +0x30, child objects at +0x4c/+0x50 (null sometimes) and slot 0xd4 of this.
0x49a560: A and this with stub slots; slot 0x14 writes a count 0..4 (sometimes large-ish), slots 0x40/0x50 write a value/float, A slot 0xc and 0x98 log."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    elif k < 0.3:
        v = r.choice([0.0, 1.0, -1.0, 4.0])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g4616c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    hook_rec(c, 0x43df70, 0, this=True, pop=0)

    def fill(em, k):
        p = em.arg32(0)
        for i in range(3):
            em.w32(p + 4 * i, _fbits(r))
    hook_rec(c, 0x4db7c0, 1, this=True, side=fill)
    hook_rec(c, 0x4dce50, 1, this=True)
    hook_rec(c, 0x4dd060, 1, this=True, deref={0: 3})
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, rnd(c, 0x20))
    return [me]


def _g561f70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4f9680, 1, this=True)
    hook_rec(c, 0x563750, 2, this=True)
    eng = rnd(c, 0x40)
    e.w32(0x70039c, eng)
    me = rnd(c, 0xe8)
    st = r.choice([3, 5, 3, 5, 0, 1, 2, 4, 6, 7, r.getrandbits(32)])
    e.w32(me + 0xdc, st)
    s = pystub(c, 1, ret=r.getrandbits(32), this=True)
    sl = obj(c, 0x20, {0xbc: s}, nslots=0xc0 // 4)
    for off in (0x4c, 0x50):
        e.w32(me + off, 0 if r.random() < 0.3 else sl)
    s2 = pystub(c, 1, ret=r.getrandbits(32), this=True)
    vt = e.alloc(0xd8, 4)
    e.wbytes(vt, bytes(r.getrandbits(8) for _ in range(0xd8)))
    e.w32(vt + 0xd4, s2)
    e.w32(me, vt)
    return [me]


def _g49a560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def cnt(em, k):
        em.w32(em.arg32(0), r.choice([0, 1, 2, 3, 4, 0, 5]))

    def wv(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))

    def wf(em, k):
        em.w32(em.arg32(0), _fbits(r))
    t = obj(c, 0x20, {0x14: pystub(c, 1, this=True, side=cnt, nullflag=(0,)), 0x40: pystub(c, 1, this=True, side=wv, nullflag=(0,)),
                      0x50: pystub(c, 1, this=True, side=wf, nullflag=(0,))}, nslots=0x54 // 4)
    a = obj(c, 0x20, {0xc: pystub(c, 0, this=True), 0x98: pystub(c, 3, this=True)}, nslots=0x9c // 4)
    return [t, a]


S(0x4616c0, 'GUESS /GS set uniform vector from max component', 'thiscall', None, ret=None, gen=_g4616c0, note='batch45003')
S(0x561f70, 'GUESS finish state 3/5 transition', 'thiscall', None, ret=None, gen=_g561f70, note='batch45003')
S(0x49a560, 'GUESS replay entries to receiver', 'thiscall', None, ret=None, gen=_g49a560, note='batch45003')
