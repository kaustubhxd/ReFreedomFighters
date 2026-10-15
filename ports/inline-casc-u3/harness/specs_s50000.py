"""specs_s50000.py - u3 (Sonnet) batch 50000, tier H. 0x463da0: p = [[this+0x1c]+0x14] holds scale / int step / limit; 0x463a30 hooked (recorder, fills both
outputs (matrix 36 bytes, vec3 12 bytes) with random floats through its two pointer args), 0x441940 / 0x4de480 / 0x4de7a0 run for real, /GS check 0x633654 keeps eax, fmod import
(_CIfmod, slot 0x676358) is a guest x87 stub, this slot 0x340 is a recorder."""
import struct
from pilot import S, F, EDGE_F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _fmod_stub(c):
    code = bytes([0xd9, 0xc9, 0xd9, 0xf8, 0xdd, 0xd9, 0xc3])
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    c.emu.mu.ctl_flush_tb()
    c.emu.w32(0x676358, a)


def _fl(r):
    return struct.unpack('<I', struct.pack('<f', r.uniform(-50, 50)))[0]


def _fv(r):
    return struct.unpack('<f', struct.pack('<f', r))[0]


def _g463da0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _fmod_stub(c)
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))

    def fill(em, k):
        for i, n in ((0, 9), (1, 3)):   # first output: 3x3 matrix, second: vec3
            ptr = em.arg32(i)
            for j in range(n):
                # the destinations inside the object get only some floats so the loop's matrix / vector updates stay visible afterwards
                if mepos[0] <= ptr < mepos[0] + 0x80 and r.random() < 0.7:
                    r.getrandbits(1)
                    continue
                em.w32(ptr + 4 * j, _fl(r))
    mepos = [0]
    hook_rec(c, 0x463a30, 3, this=True, pop=0xc, side=fill, stackmark=(0, 1))
    me = obj(c, 0x120, {0x340: pystub(c, 2, this=True)}, nslots=0x344 // 4)
    mepos[0] = me
    q = rnd(c, 0x40)
    p = rnd(c, 0x40)
    e.w32(me + 0x1c, q)
    e.w32(q + 0x14, p)
    step = r.choice([1, 2, 3, 5, 10, 30, 0, -3, r.randrange(1, 100)])
    s = r.choice([0.5, 1.0, 2.0, 4.0, r.uniform(0.01, 8.0), -1.0, 0.0, r.uniform(0.1, 30.0)])
    mode = r.random()
    b = r.uniform(-5, 60) if mode < 0.9 else r.choice([x for x in EDGE_F if x == x and abs(x) < 1e6])
    kind = r.random()
    if kind < 0.3:
        L = float(step)
    elif kind < 0.5:
        L = _fv(b + r.choice([0.0, 0.001, -0.001, 1, -1]))
    elif kind < 0.55:
        L = float('nan')
    else:
        L = r.uniform(-5, 80)
    k = r.random()
    if k < 0.35:
        a = _fv(b - r.uniform(0, 0.4) / max(abs(s), 0.01))
    elif k < 0.97:
        a = _fv(b - r.uniform(0, 25) / max(abs(s), 0.01))
    else:
        a = r.choice([x for x in EDGE_F if x == x and abs(x) < 1e6])
    e.w32(p + 0xc, step & 0xffffffff)
    e.wbytes(p + 0x18, struct.pack('<f', L))
    e.wbytes(p + 0x20, struct.pack('<f', s))
    return [me, F(a), F(b)]


S(0x463da0, 'GUESS advance transforms across float interval', 'thiscall', None, ret=None, gen=_g463da0, nan_heap=True, note='batch50000')
