"""specs_s45001.py - tier H slice 5, three /GS asm ports.
0x4fa910: engine(0x70038c) slot 0xcc stub returns an object (or null); hooked 0x4db500 writes random floats into the stack vector; index this[0x8f] in 0..3 (3 overwrites the cookie); slot 0x70 logs 4 dwords.
0x5b04e0: five random stack args (some zero), 0x5af1d0 runs for real, hooked 0x5af2a0.
0x57f6b0: stubs for engine slots 0xbc/0x190, object slots 0xa8 (st0 float), 0x198 (cdecl, writes random bytes into the buffer), this[0x180] slot 0x378 logs the buffer."""
import struct
from pilot import S, EDGE_F, F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g4fa910(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def fill(em, k):
        v = em.arg32(0)
        for i in range(3):
            em.w32(v + 4 * i, r.getrandbits(32) if r.random() < 0.1 else struct.unpack('<I', struct.pack('<f', r.uniform(-500, 500)))[0])
    hook_rec(c, 0x4db500, 1, this=True, side=fill)
    s4 = pystub(c, 1, ret=r.getrandbits(32), this=True, deref={0: 4})
    o2 = obj(c, 0x20, {0x70: s4}, nslots=0x74 // 4 + 1)
    e.w32(o2 + 8, rnd(c, 0x10))
    res = 0 if r.random() < 0.2 else o2
    s_cc = pystub(c, 1, ret=res, this=True)
    eng = obj(c, 0x20, {0xcc: s_cc}, nslots=0xd0 // 4 + 1)
    e.w32(0x70038c, eng)
    me = rnd(c, 0xc0)
    e.w32(me + 0x8f, r.choice([0, 1, 2, 3, 0, 1, 2]))
    e.wbytes(me + 0x8f, struct.pack('<I', r.choice([0, 1, 2, 3, 0, 1, 2])))
    if r.random() < 0.8:
        e.wbytes(me + 0xa7, struct.pack('<f', r.uniform(-1000, 1000)))
    e.wbytes(me + 0xaf, struct.pack('<i', r.choice([r.randint(-100000, 100000), 0, 7, -7])))
    return [me]


def _g5b04e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    hook_rec(c, 0x5af2a0, 2, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x40)
    args = [r.choice([0, r.getrandbits(32), r.getrandbits(32), r.randint(0, 3)]) for _ in range(5)]
    return [me] + args


def _g57f6b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def wr(em, k):
        b = em.arg32(1)
        em.wbytes(b, bytes(r.getrandbits(8) for _ in range(0x84)))
    cd = pystub(c, 4, ret=r.getrandbits(32), pop=0, side=wr, deref={1: 5})
    sobj = obj(c, 0x20, {0x198: cd}, nslots=0x19c // 4 + 1)
    fv = r.choice([0.0, 1.0, -1.0, 0.5, r.uniform(-100, 100), r.uniform(-1e6, 1e6), r.choice(EDGE_F)])
    s_a8 = pystub(c, 0, ret=r.getrandbits(32), this=True, st0=fv)
    o1 = obj(c, 0x20, {0xa8: s_a8}, nslots=0xac // 4 + 1)
    s_bc = pystub(c, 0, ret=o1, this=True)
    s_190 = pystub(c, 0, ret=sobj, this=True)
    eng = obj(c, 0x20, {0xbc: s_bc, 0x190: s_190}, nslots=0x194 // 4 + 1)
    e.w32(0x70039c, eng)
    s378 = pystub(c, 1, ret=r.getrandbits(32), this=True, deref={0: 33})
    t = obj(c, 0x20, {0x378: s378}, nslots=0x37c // 4 + 1)
    me = rnd(c, 0x190)
    e.w32(me + 0x180, t)
    return [me]


S(0x4fa910, 'GUESS /GS vector component set', 'thiscall', None, ret=None, gen=_g4fa910, note='batch45001')
S(0x5b04e0, 'GUESS /GS id chain copy', 'thiscall', None, ret=None, gen=_g5b04e0, note='batch45001')
S(0x57f6b0, 'GUESS /GS format scaled value', 'thiscall', None, ret=None, gen=_g57f6b0, note='batch45001')
