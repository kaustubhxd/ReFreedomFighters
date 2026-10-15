"""specs_s32093.py - h2 (Sonnet) batch 32093: eight tier H small float functions. Float arguments are F(); float returns ret='st0'."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _fbits(c):
    r = c.rng
    return r.choice([struct.unpack('<I', struct.pack('<f', c.fv(-5, 5)))[0], NAN, 0x7f800000, 0xff800000, 0, 0x80000000, r.getrandbits(32)])


def g473b50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = struct.unpack('<f', struct.pack('<I', e.r32(0x67c198)))[0]
    me = rnd(c, 0x200)
    v = r.choice([k, k - 0.5, k + 0.5, 0.0, -1.0, 100.0, c.fv(-3, 3)])
    bits = r.choice([struct.unpack('<I', struct.pack('<f', v))[0], NAN, struct.unpack('<I', struct.pack('<f', k))[0]])
    e.wbytes(me + 0x1e2, bits.to_bytes(4, 'little'))
    return [me]


def g5243d0(c):
    clear_hooks(c)
    return [rnd(c, 0x20), F(c.fv(-100, 100))]


def g4ce680(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    arr = e.alloc(0x100, 4)
    for i in range(0x40):
        e.wf32(arr + 4 * i, c.fv(-50, 50))
    me = rnd(c, 0x40)
    e.w32(me + 0x18, r.randrange(3, 0x20))
    return [me, arr]


def g4ea8e0(c):
    clear_hooks(c)
    return [rnd(c, 0x80), F(c.fv(-100, 100)), F(c.fv(-100, 100))]


def g5370b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x5200)
    i = r.randrange(0, 0x80)
    for j in range(0x80):
        pass
    e.wbytes(me + i * 9 + 0x5159, struct.pack('<f', c.fv(-1000, 1000)))
    return [me, i]


def g5afce0(c):
    clear_hooks(c)
    return [rnd(c, 0x20), rnd(c, 0x30)]


def g5e0df0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5a83e0, 1, this=True, pop=4)
    me = rnd(c, 0x1d30)
    o = rnd(c, 0x20)
    e.wbytes(me + 0x1d0f, (o if r.random() < 0.7 else 0).to_bytes(4, 'little'))
    e.wbytes(me + 0x1d17, _fbits(c).to_bytes(4, 'little'))
    return [me]


def g515930(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x2f8: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x2f8 // 4 + 1)
    return [me, F(c.fv(-100, 100)), r.getrandbits(32)]


S(0x473b50, 'GUESS clamp float field up to 1.0 below constant', 'thiscall', None, ret=None, gen=g473b50, note='batch32093')
S(0x5243d0, 'GUESS set float field 0xc', 'thiscall', None, ret=None, gen=g5243d0, note='batch32093')
S(0x4ce680, 'GUESS indexed float getter', 'thiscall', None, ret='st0', gen=g4ce680, note='batch32093')
S(0x4ea8e0, 'GUESS set two float fields', 'thiscall', None, ret=None, gen=g4ea8e0, note='batch32093')
S(0x5370b0, 'GUESS scaled float element getter', 'thiscall', None, ret='st0', gen=g5370b0, note='batch32093')
S(0x5afce0, 'GUESS copy 20 bytes out', 'thiscall', None, ret=None, gen=g5afce0, note='batch32093')
S(0x5e0df0, 'GUESS forward float field to member', 'thiscall', None, ret=None, gen=g5e0df0, note='batch32093')
S(0x515930, 'GUESS slot 0x2f8 with float', 'thiscall', None, ret='eax', gen=g515930, note='batch32093')
