"""specs_s46.py - inline session batch 46: 0x487a80 ZMovementBase::CalcNewPosAndSpeed (walk tree, called by Move).
Callee stand-in (both runs call the same one): this vtable slot 0x3c (CalcNewSpeed in the real vtable) is a heap stub
that saves its two pointer args and fills the two out vectors (move, turn) from a per-input buffer.
mcpy, the angle rotation 0x4de7e0, vnorm, vcross, vscalar, both vaddscalar forms, PSVECAdd and
ZPlayer::AdjustMovePoolSpeed (with a pool of 0 to 4 random entries) run as exe code."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vec(c, n, lo, hi):
    a = c.emu.alloc(4 * n + 0x10, 4)
    for i in range(n):
        c.emu.wf32(a + 4 * i, c.rng.uniform(lo, hi))
    return a


def _speed_stub(c, src):
    # thiscall (a0, a1, move, turn), ret 0x10: save a0 and a1 to rec, copy six floats from src to move and turn
    rec = c.emu.alloc(8, 4)
    code = b''
    for i in range(2):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    for k, off in enumerate((0x0c, 0x10)):
        code += b'\x8b\x44\x24' + bytes([off])                               # mov eax, [esp+off]
        for j in range(3):
            code += b'\x8b\x15' + struct.pack('<I', src + 12 * k + 4 * j)    # mov edx, [src]
            code += b'\x89\x50' + bytes([4 * j])                             # mov [eax+4j], edx
    code += b'\xc2\x10\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _cnps(c):
    r = c.rng
    obj = _rnd(c, 0x100)
    src = c.emu.alloc(24, 4)
    for i in range(3):
        c.emu.wf32(src + 4 * i, r.uniform(-2.0, 2.0))
    mode = r.random()
    for i in range(3):   # turn: all zero (no rotation), one or two zero lanes, or random
        z = mode < 0.3 or (mode < 0.6 and r.random() < 0.5)
        c.emu.wf32(src + 12 + 4 * i, 0.0 if z else r.uniform(-0.1, 0.1))
    vt = c.emu.alloc(0x40, 4)
    c.emu.w32(vt + 0x3c, _speed_stub(c, src))
    c.emu.w32(obj, vt)
    c.emu.wf32(obj + 0x18, 0.0 if r.random() < 0.5 else r.uniform(0.0, 0.1))
    p = _rnd(c, 0x700)
    c.emu.wbytes(p + 0x5ff, bytes([0 if r.random() < 0.5 else r.randint(1, 255)]))
    for i in range(3):
        c.emu.wf32(p + 0x42d + 4 * i, r.uniform(-3.0, 3.0))
    a1 = _vec(c, 3, -20.0, 20.0)
    n = r.choice((0, 0, 1, 2, 4))
    c.emu.w32(p + 0x4f1, n if r.random() < 0.9 else 0xffffffff)
    for i in range(4):
        e = _rnd(c, 0x40)
        for j in range(3):
            c.emu.wf32(e + 8 + 4 * j, c.emu.rf32(a1 + 4 * j) + r.uniform(-25.0, 25.0))
        c.emu.wf32(e + 0x38, r.uniform(0.0, 20.0))
        c.emu.w32(p + 0x4e1 + 4 * i, e)
    c.emu.w32(obj + 4, p)
    q = _rnd(c, 0x80)
    c.emu.w32(obj + 8, q)
    sysobj = _rnd(c, 0x100)
    c.emu.wf32(sysobj + 0x48, r.uniform(0.001, 0.1))
    c.emu.w32(0x70039c, sysobj)
    a0 = _vec(c, 9, -1.0, 1.0)
    a2 = _rnd(c, 0x30)
    a3 = _rnd(c, 0x10)
    a4 = _vec(c, 3, -5.0, 5.0)
    c.emu.mu.ctl_flush_tb()   # stub code changes per input at reused heap addresses; drop unicorn's translated blocks
    return [obj, a0, a1, a2, a3, a4]


S(0x487a80, 'ZMovementBase::CalcNewPosAndSpeed', 'thiscall', None, ret=None, gen=_cnps,
  note='batch46; walk tree; vtable slot 0x3c stand-in fills move and turn; AdjustMovePoolSpeed runs as exe code')
