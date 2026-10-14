"""specs_s34150.py - tier H. 0x4c61a0/0x5ddad0: hooked 0x4e5e80 (plain, ecx recorded, float in st0, a different value per call) and 0x4e5e60 (random eax). 0x59a5b0: callee 0x5aaa50 hooked, field +0x1d0f zero in a fifth. 0x4dfde0: register args ecx = A (2 floats), edx = B (4 floats). 0x537f80: engine object [0x70039c] with an int at +0x1c."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _fval(r):
    k = r.random()
    if k < 0.2:
        v = r.choice([x for x in EDGE_F if x == x])
    else:
        v = r.uniform(-1000, 1000)
    return _f32(v) if abs(v) < 3e38 or v != v else v


def _fbits(r):
    k = r.random()
    if k < 0.2:
        v = r.choice(EDGE_F)
    elif k < 0.27:
        return r.getrandbits(32)
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g4c61a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda em, k: _fval(r))
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x60), rnd(c, 0x20)]


def _g5ddad0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda em, k: _fval(r))
    return [rnd(c, 0x60), rnd(c, 0x20)]


def _g59a5b0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5aaa50, 3, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x1d20)
    c.emu.wbytes(me + 0x1d0f, (0 if r.random() < 0.2 else rnd(c, 0x20)).to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32), _fbits(r)]


def _g4dfde0(c):
    clear_hooks(c)
    r = c.rng
    A, B = rnd(c, 0x10), rnd(c, 0x20)
    for i in range(2):
        c.emu.w32(A + 4 * i, _fbits(r))
    for i in range(4):
        c.emu.w32(B + 4 * i, _fbits(r))
    return [A, B]


def _g537f80(c):
    clear_hooks(c)
    r = c.rng
    so = rnd(c, 0x40)
    c.emu.w32(so + 0x1c, r.choice([0, 1, -1, 1000, 0x7fffffff, r.getrandbits(32)]) & 0xffffffff)
    c.emu.w32(0x70039c, so)
    return [rnd(c, 0x5200), r.getrandbits(32), _fbits(r)]


S(0x4c61a0, 'GUESS use x87 getter and int getter', 'thiscall', None, ret=None, gen=_g4c61a0, note='batch34150')
S(0x5ddad0, 'GUESS read two floats', 'thiscall', None, ret=None, gen=_g5ddad0, note='batch34150')
S(0x59a5b0, 'GUESS forward float to child', 'thiscall', None, ret=None, gen=_g59a5b0, note='batch34150')
S(0x4dfde0, 'GUESS 2x2 transform', ('regs', ['ecx', 'edx']), None, ret=None, gen=_g4dfde0, note='batch34150')
S(0x537f80, 'GUESS store floats and scaled int', 'thiscall', None, ret=None, gen=_g537f80, note='batch34150')
