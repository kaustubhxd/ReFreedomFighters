"""specs_s34163.py - tier H. 0x563490: s with slots 0x3c / 0x44, chain of objects with slots 0x4c (float bits) and 0x60 (1 arg). 0x650e00: table [0x70039c]+0x9b slot 0x4c, object [this+0x8c] with slots 0x28 / 0x2c / 0xa0 (results zero in a third). 0x532850: register args ecx = A, edx = B, words including extremes; st0 result. 0x4f6e90: hooked 0x4f9c90, 0x4e11e0 / 0x4e12e0 (write a random int through the stack pointer argument), 0x4e1b30; [0x70038c] slot 0xcc."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g563490(c):
    clear_hooks(c)
    r = c.rng
    o2 = obj(c, 0x20, {0x60: pystub(c, 1, this=True)}, nslots=0x64 // 4)
    o1 = obj(c, 0x20, {0x60: pystub(c, 1, this=True, ret=o2)}, nslots=0x64 // 4)
    r1 = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, ret=o1)}, nslots=0x50 // 4)
    s = obj(c, 0x20, {0x3c: pystub(c, 1, this=True, ret=r1), 0x44: pystub(c, 1, this=True)}, nslots=0x48 // 4)
    me = rnd(c, 0x100)
    c.emu.w32(me + 4, r.getrandbits(32))
    c.emu.w32(me + 0x48, r.getrandbits(32))
    c.emu.w32(me + 0x64, struct.unpack('<I', struct.pack('<f', r.uniform(-100, 100)))[0] if r.random() < 0.8 else r.getrandbits(32))
    c.emu.wbytes(me + 0x84, bytes([r.choice([0, 1, 0xff, r.getrandbits(8)]), r.choice([0, 1, 0xff, r.getrandbits(8)])]))
    c.emu.w32(me + 0xf0, r.getrandbits(32))
    c.emu.w32(me + 0xdc, r.getrandbits(32))
    return [me, s]


def _g650e00(c):
    clear_hooks(c)
    r = c.rng
    tbl = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, nslots=0x50 // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    o = obj(c, 0x20, {0x28: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 7])),
                      0x2c: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 9])),
                      0xa0: pystub(c, 2, this=True)}, nslots=0xa4 // 4)
    me = rnd(c, 0xa0)
    c.emu.w32(me + 0x8c, o)
    f = struct.unpack('<I', struct.pack('<f', r.uniform(-100, 100)))[0] if r.random() < 0.8 else r.getrandbits(32)
    return [me, r.getrandbits(32), f]


def _g532850(c):
    clear_hooks(c)
    r = c.rng
    A, B = rnd(c, 0x10), rnd(c, 0x10)
    vals = [0, 1, 0x7fff, 0x8000, 0xffff, r.getrandbits(16)]
    c.emu.wbytes(A, b''.join((r.choice(vals) if r.random() < 0.6 else r.getrandbits(16)).to_bytes(2, 'little') for _ in range(3)))
    c.emu.wbytes(B, b''.join((r.choice(vals) if r.random() < 0.6 else r.getrandbits(16)).to_bytes(2, 'little') for _ in range(3)))
    return [A, B]


def _g4f6e90(c):
    clear_hooks(c)
    r = c.rng

    def wr(em, k):
        em.w32(em.arg32(0), r.choice([0, 1, -1, 12345, 0x7fffffff, -0x80000000, 0x1000001, r.getrandbits(32)]) & 0xffffffff)
    hook_rec(c, 0x4f9c90, 1, this=True)
    hook_rec(c, 0x4e11e0, 2, this=True, pop=8, stackmark=(0,), side=wr)
    hook_rec(c, 0x4e12e0, 2, this=True, pop=8, stackmark=(0,), side=wr)
    hook_rec(c, 0x4e1b30, 0, this=True, pop=0)
    eng = obj(c, 0x20, {0xcc: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, nslots=0xd0 // 4)
    c.emu.w32(0x70038c, eng)
    return [rnd(c, 0xa0), rnd(c, 0x20)]


S(0x563490, 'GUESS configure slot chain', 'thiscall', None, ret='al', gen=_g563490, note='batch34163')
S(0x650e00, 'GUESS resolve two handles and forward a float', 'thiscall', None, ret=None, gen=_g650e00, note='batch34163')
S(0x532850, 'GUESS manhattan distance of word triples', ('regs', ['ecx', 'edx']), None, ret='st0', gen=_g532850, note='batch34163')
S(0x4f6e90, 'GUESS read two ints as floats and an id', 'thiscall', None, ret=None, gen=_g4f6e90, note='batch34163')
