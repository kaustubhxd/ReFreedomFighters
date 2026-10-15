"""specs_s38087.py - cascade s8 batch 38087. thiscall(a, b, c) ret 0xc. this = 0x1500-byte random block (disabled byte +0x1e mostly 0, cached (a, c, b) at +0x141e / +0x1426 / +0x1422 sometimes equal to the arguments,
flag +0x115f, +0x1163, object +0x1377). The device object at 0x724a00 has stdcall slots 0xc8 (SetRenderState-like) and 0xfc (logging); the state cache globals 0x724928 ... 0x724968 start at random small values around the compared
constants. The real exe helpers 0x60fd70 ... 0x60ff30 run in both versions. ret=None."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g6113d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    D = obj(c, 0x200, {0xc8: e.stub_fn('rs', lambda em, res_: (em.calllog.append(('rs', em.arg32(0) != 0, em.arg32(1), em.arg32(2))), em.ret(eax=r.getrandbits(32), argbytes=12))),
                       0xfc: e.stub_fn('s4', lambda em, res_: (em.calllog.append(('s4', em.arg32(0) != 0, em.arg32(1), em.arg32(2), em.arg32(3))), em.ret(eax=0, argbytes=16)))})
    e.w32(0x724a00, D)
    for a in (0x724928, 0x72492c, 0x724930, 0x724934, 0x724938, 0x72493c, 0x724940, 0x72494c, 0x724950, 0x724954, 0x724968):
        e.w32(a, r.choice([0, 1, 2, 4, 5, 8, 0x22]))
    e.w32(0x724954, r.choice([0, 1, 7]))
    this = rnd(c, 0x1500)
    e.wbytes(this + 0x1e, bytes([r.choice([0, 0, 0, 0, 1])]))
    bits = [0x402607, 0x2000, 0x400, 2, 0x40000, 0x20000, 0x80000, 0x100000, 0x4000, 0x8000, 1, 4, 0x200000, 0x400000]
    a = 0
    for b in bits:
        if r.random() < 0.4:
            a |= b
    if r.random() < 0.25:
        a &= ~0x402607
    b = r.choice([0, 1, 0x1234, r.getrandbits(32)])
    cc = r.choice([0, 0, 3, r.getrandbits(32)])
    if r.random() < 0.2:
        e.wbytes(this + 0x141e, struct.pack('<I', a))
        e.wbytes(this + 0x1426, struct.pack('<I', cc))
        e.wbytes(this + 0x1422, struct.pack('<I', b if r.random() < 0.6 else b ^ 1))
    e.wbytes(this + 0x115f, struct.pack('<I', r.choice([0, 1, 1, 1])))
    e.wbytes(this + 0x1163, struct.pack('<I', r.choice([0, 1, 1])))
    e.wbytes(this + 0x1377, struct.pack('<I', D))
    return [this, a, b, cc]


S(0x6113d0, 'GUESS apply render mode word', 'thiscall', None, ret=None, gen=_g6113d0, note='batch38087')
