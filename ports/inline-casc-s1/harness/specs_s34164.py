"""specs_s34164.py - tier H. 0x58aaf0: register args ecx = this (vtable slots 0x3c, 0x4c, 0x60, 0x68 recorders), edx = p {count 0..4, records of 0x15 bytes at +4 with random bytes}; returns this. 0x54c8f0: hooked 0x549780 / 0x5496e0 (this and arg logged), the object [this+0x63ec] with vtable slots 0x3c / 0x44 (stdcall 2 args, ecx not logged), values around 100 and 100000. 0x650f30: the exe float table at 0x6c33b8 (sometimes overwritten with random floats), the count at 0x6f5a98 set per case to 0..9, output byte array at [this+0x10]."""
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
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g58aaf0(c):
    clear_hooks(c)
    r = c.rng
    vt = c.emu.alloc(0x100, 4)
    for off in (0x3c, 0x4c, 0x60, 0x68):
        c.emu.w32(vt + off, pystub(c, 1, this=True))
    me = rnd(c, 0x20)
    c.emu.w32(me, vt)
    n = r.choice([0, 1, 2, 3, 4])
    p = rnd(c, 4 + 0x15 * 5 + 8)
    c.emu.w32(p, n)
    return [me, p]


def _g54c8f0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x549780, 1, this=True, ret=r.getrandbits(32))
    vals = [0, 50, 99, 100, 101, 5000, 99999, 100000, 100001, 0x7fffffff, -1 & 0xffffffff, 0x80000000]
    hook_rec(c, 0x5496e0, 1, this=True, ret=lambda em, k: r.choice(vals))
    vt = c.emu.alloc(0x100, 4)
    c.emu.w32(vt + 0x3c, pystub(c, 2, pop=8))
    c.emu.w32(vt + 0x44, pystub(c, 2, pop=8))
    o = rnd(c, 0x20)
    c.emu.w32(o, vt)
    me = rnd(c, 0x6400)
    c.emu.w32(me + 0x63ec, o)
    c.emu.wbytes(me + 0x63d7, _fbits(r).to_bytes(4, 'little'))
    a = rnd(c, 0x40)
    c.emu.w32(a + 0x28, r.getrandbits(32))
    return [me, a]


def _g650f30(c):
    clear_hooks(c)
    r = c.rng
    i = r.randrange(4)
    cnt = r.choice([0, 1, 2, 3, 5, 9])
    c.emu.w32(0x6f5a98, cnt)
    if r.random() < 0.4:
        for j in range(8):
            c.emu.w32(0x6c33b8 + 32 * i + 4 * j, _fbits(r) if r.random() < 0.6 else struct.unpack('<I', struct.pack('<f', float(r.randrange(0, 12))))[0])
    me = rnd(c, 0x20)
    c.emu.w32(me + 0x10, rnd(c, 0x20))
    return [me, i]


S(0x58aaf0, 'GUESS apply 21-byte records', ('regs', ['ecx', 'edx']), None, ret='eax', gen=_g58aaf0, note='batch34164')
S(0x54c8f0, 'GUESS clamped count to slot', 'thiscall', None, ret=None, gen=_g54c8f0, note='batch34164')
S(0x650f30, 'GUESS bucket thresholds', 'thiscall', None, ret=None, gen=_g650f30, note='batch34164')
