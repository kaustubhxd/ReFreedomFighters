"""specs_s52002.py - tier H. 0x480120: A and B objects with recorder slots (A 0x88/0xdc/0x24, B 0x270/0x274 writing random floats through their out pointer), hooked 0x47ff20, 0x480640, /GS check; six float entries (zero, -0.0, NaN, normal) and object pointers."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-50, 50)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g480120(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x47ff20, 2, this=True, ret=(r.getrandbits(32) | 1) if r.random() > 0.15 else r.choice([0, 1]))
    hook_rec(c, 0x480640, 4, this=True, deref={3: 2}, ret=r.getrandbits(32))
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))

    t2 = [[_fbits(r), _fbits(r)] for _ in range(4)]
    t3 = [[_fbits(r) for _ in range(r.choice([1, 2, 3, 3]))] for _ in range(16)]

    def w2(em, k):
        v = em.arg32(0)
        for i, x in enumerate(t2[min(k, 3)]):
            em.w32(v + 4 * i, x)

    def w3(em, k):
        v = em.arg32(0)
        for i, x in enumerate(t3[min(k, 15)]):
            em.w32(v + 4 * i, x)
    A = obj(c, 0x20, {0x88: pystub(c, 3, this=True), 0xdc: pystub(c, 3, this=True),
                      0x24: pystub(c, 6, this=True, deref={1: 9, 2: 3, 3: 3})}, nslots=0xe0 // 4)
    B = obj(c, 0x60, {0x270: pystub(c, 2, this=True, side=w2, stackmark=(0,)), 0x274: pystub(c, 2, this=True, deref={1: 2}, side=w3, stackmark=(0,))}, nslots=0x278 // 4)
    c.emu.w32(B + 0x48, r.getrandbits(32) if r.random() < 0.5 else (r.getrandbits(32) | 0x10000))
    d = rnd(c, 0x20)
    d8 = r.choice([5.0, 4.9, 5.1, 100.0, 1e30, -1.0, float('nan'), float('inf'), 6.0, 7.5]) if r.random() < 0.9 else r.uniform(-10, 10)
    c.emu.w32(d + 8, struct.unpack('<I', struct.pack('<f', d8))[0])
    me = rnd(c, 0x100)
    c.emu.w32(me + 8, r.getrandbits(32))
    c.emu.wbytes(me + 0x14, bytes([r.getrandbits(8)]))
    for k in range(6):
        x = r.choice([0, 0x80000000, 0x7fc00000, _fbits(r), _fbits(r)])
        c.emu.w32(me + 0x34 + 12 * k, x)
        if r.random() < 0.7:
            c.emu.w32(me + 0x30 + 12 * k, _fbits(r))
        o = rnd(c, 0x20)
        q = rnd(c, 0x20)
        c.emu.w32(o + 4, q)
        c.emu.w32(me + 0x74 + 4 * k, o)
    return [me, A, B, r.getrandbits(32), d]


S(0x480120, 'GUESS emit six scaled entries', 'thiscall', None, ret=None, gen=_g480120, note='batch52002')
