"""specs_s32135.py - h2 () batch 32135: 0x60f0b0, 0x504ac0, 0x526610. Callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def g60f0b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    out = rnd(c, 0x40)
    inp = rnd(c, 0x40)
    for i in range(16):
        v = r.choice([_bits(r.uniform(-5, 5)), _bits(r.uniform(-5, 5)), _bits(r.uniform(-5, 5)), 0, 0x80000000, NAN, 0x7f800000, _bits(1e30)])
        e.w32(inp + 4 * i, v)
    return [out, inp]


def g504ac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda emu, k: emu.reg('eax'))

    def fill(emu, k):
        a = emu.arg32(0)
        for i in range(9):
            emu.w32(a + 4 * i, _bits(r.uniform(-9, 9)))
        b = emu.arg32(1)
        for i in range(3):
            emu.w32(b + 4 * i, _bits(r.uniform(-9, 9)))
        emu.calllog.append(('fill',))
    RV = r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32)])
    o = obj(c, 0x20, {0x80: pystub(c, 2, this=True, nullflag=(0, 1), side=fill),
                      0x37c: pystub(c, 7, this=True, deref={3: 9, 4: 3}, ret=RV)}, nslots=0x380 // 4)
    me = rnd(c, 0x40)
    e.w32(me + 0x14, o)
    a = r.choice([0, rnd(c, 0x10), rnd(c, 0x10), r.getrandbits(32)])
    return [me, a, F(r.choice([0.0, 1.0, r.uniform(-9, 9), struct.unpack('<f', struct.pack('<I', NAN))[0]])), F(r.uniform(-9, 9))]


def g526610(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x1800)
    n1 = r.choice([0, 1, 2, 3, 4, 0xffffffff, 0x80000000])
    n2 = r.choice([0, 1, 2, 3, 4, 0xffffffff])
    e.w32(me + 0x8c, n1)
    e.w32(me + 0x90, n2)

    def side(emu, k):
        if r.random() < 0.15:
            emu.w32(me + 0x8c, r.choice([0, 1, 2, 3]))
        if r.random() < 0.15:
            emu.w32(me + 0x90, r.choice([0, 1, 2, 3]))
        emu.calllog.append(('s', k))
    hook_rec(c, 0x516690, 1, this=True, pop=4)
    hook_rec(c, 0x52a1c0, 0, this=True, pop=0, side=side)
    return [me, F(r.choice([0.0, 1.0, r.uniform(-9, 9), struct.unpack('<f', struct.pack('<I', NAN))[0]]))]


S(0x60f0b0, 'GUESS invert rigid matrix', 'fastcall', None, ret=None, gen=g60f0b0, nan_heap=True, note='batch32135')
S(0x504ac0, 'GUESS forward query with out buffers', 'thiscall', None, ret='eax', gen=g504ac0, nan_heap=True, note='batch32135')
S(0x526610, 'GUESS update two arrays of entries', 'thiscall', None, ret=None, gen=g526610, nan_heap=True, note='batch32135')
