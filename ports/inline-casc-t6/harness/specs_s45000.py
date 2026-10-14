"""specs_s45000.py - tier H slice 5. 0x451b30: this[8]=P with random floats at +0x40/+0x44/+0x48 (edge values, huge, negative = NaN sqrt); hooked 0x4dc600, 0x4dd060 (vector logged), 0x4dce50 (float arg logged as raw bits).
0x4483a0: P[0x6c] zero/non-zero, engine global 0x70039c -> unaligned +0x1aa3 -> +0x18 object with a stub in vtable slot 0x114 (id and both vectors logged)."""
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
        v = r.choice([0.0, 1.0, -1.0, 4.0, 9.0, 1e-3])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _p(c, withslot=False):
    r = c.rng
    o = rnd(c, 0x80)
    for off in (0x40, 0x44, 0x48):
        c.emu.w32(o + off, _fbits(r))
    return o


def _g451b30(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dc600, 1, this=True, deref={0: 3}, ret=r.getrandbits(32))
    hook_rec(c, 0x4dd060, 1, this=True, deref={0: 3}, ret=r.getrandbits(32))
    hook_rec(c, 0x4dce50, 1, this=True, ret=r.getrandbits(32))
    o = _p(c)
    me = rnd(c, 0x40)
    c.emu.w32(me + 8, o)
    return [me]


def _g4483a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dce50, 1, this=True, ret=r.getrandbits(32))
    o = _p(c)
    if r.random() < 0.3:
        c.emu.w32(o + 0x6c, 0)
    elif r.random() < 0.5:
        c.emu.w32(o + 0x6c, r.randint(1, 20))
    st = pystub(c, 3, this=True, deref={1: 3, 2: 3}, ret=r.getrandbits(32))
    cobj = obj(c, 0x40, {0x114: st}, nslots=0x120 // 4 + 1)
    a = rnd(c, 0x40)
    c.emu.w32(a + 0x18, cobj)
    eng = rnd(c, 0x1b00)
    c.emu.wbytes(eng + 0x1aa3, struct.pack('<I', a))
    c.emu.w32(0x70039c, eng)
    me = rnd(c, 0x40)
    c.emu.w32(me + 8, o)
    return [me]


S(0x451b30, 'GUESS set vectors then length', 'thiscall', None, ret=None, gen=_g451b30, note='batch45000')
S(0x4483a0, 'GUESS conditional slot 0x114 then length', 'thiscall', None, ret=None, gen=_g4483a0, note='batch45000')
