"""specs_s6303.py - unclaimed-63 batch 3 (docs/20-unclaimed-63.md): 0x4dcda0 (GC name ZBaseGeom::SetPrev, medium) and
0x4d9ce0 (ZBaseGeom::AttachToDynamicContainer). Stubs, rewritten each case (with a translation flush):
  * 0x4dcda0: global 0x70039c -> rm; rm+0x9b -> o; o+8 -> p; p's slot +0x4c returns a random V. The argument is random, or
    0 in one case of five;
  * 0x4d9ce0: this+0x3c is 0 or 1; this+0x50 -> a (always set when the byte is set: the PC reads [0+8] otherwise, a fault);
    a+0x54 -> b; b+8 -> c; 0x4daff0 (original, ss.patch) records ECX and returns p (or 0); p's slot +0x318 records ECX and its
    argument and returns W; this+0x64 receives W when p is nonzero.
The callee 0x4daff0 is stubbed; the rest of the chain is heap objects."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c, n=1):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _le(v):
    return v.to_bytes(4, 'little')


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _gen_setprev(c):
    self_ = _rnd(c, 0x80)
    a = 0 if c.rng.random() < 0.2 else c.rng.getrandbits(32)
    rm = _rnd(c, 0x200)
    o = _rnd(c, 0x40)
    p = _rnd(c, 0x40)
    c.emu.w32(o + 8, p)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)
    vt_p = c.emu.alloc(0x100, 4)
    c.emu.w32(vt_p + 0x4c, _stub(c, b'\xb8' + _le(c.rng.getrandbits(32)) + b'\xc3'))
    c.emu.w32(p, vt_p)
    return [self_, a]


def _gen_attach(c):
    self_ = _rnd(c, 0x100)
    c.emu.wbytes(self_ + 0x3c, bytes([c.rng.choice([0, 1, 1])]))
    A = _rnd(c, 0x80)
    B = _rnd(c, 0x80)
    C = _rnd(c, 0x80)
    c.emu.w32(A + 0x54, B)
    c.emu.w32(B + 8, C)
    c.emu.w32(self_ + 0x50, A)
    # 0x4daff0: records ECX, returns p (or 0)
    c_ecx = _cell(c)
    p = _rnd(c, 0x80) if c.rng.random() < 0.8 else 0
    ss.patch(c, 0x4daff0, _stub(c, b'\x89\x0d' + _le(c_ecx) + b'\xb8' + _le(p) + b'\xc3'))
    _flush(c)
    # p's slot +0x318: records ECX and its argument, returns W
    if p:
        vt_p = c.emu.alloc(0x400, 4)
        c318 = _cell(c, 2)
        W = c.rng.getrandbits(32)
        code = (b'\x89\x0d' + _le(c318) + b'\x8b\x44\x24\x04\xa3' + _le(c318 + 4) +
                b'\xb8' + _le(W) + b'\xc2\x04\x00')
        c.emu.w32(vt_p + 0x318, _stub(c, code))
        c.emu.w32(p, vt_p)
    return [self_]


S(0x4dcda0, 'ZBaseGeom::SetPrev (GC name; unknown body) thiscall', 'thiscall', None, ret=None, gen=_gen_setprev,
  note='unclaimed-63 batch 3; rm/o/p chain, p vtbl+0x4c stub')
S(0x4d9ce0, 'ZBaseGeom::AttachToDynamicContainer (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_attach,
  note='unclaimed-63 batch 3; 0x4daff0 stubbed; p vtbl+0x318 stub')
