"""specs_s2302.py - unclaimed-23 batch 2 (docs/20-unclaimed-23.md): ZFFSearchLightAddActors::Init2 (0x5c5be0), thiscall, no
arguments. Every callee is a stub, rewritten each case (with a translation flush):
  * global 0x70039c -> rm; rm+0x9b -> o. o's slot +0x138 returns R; o's slot +0x114 records its four arguments and returns a
    random 32-bit value (the port takes its low 16 bits); o's slot +0x4c returns a random value;
  * R's slot +0x88 records its first argument and writes a value (0 or nonzero) through its second (the out pointer);
  * global 0x700390 -> G; G's slot +0x20 records its two arguments and returns X;
  * X's slot +0x2c records ECX and its two arguments (caller cleans, so 'ret');
  * this+0x44 -> M; M's slot +0x12c records its first, second and fourth arguments and the dword the third points to (the
    third argument is a local, so its contents are recorded, not its address);
  * this's slot +0x58 records ECX;
  * this+0x4c is 0 or nonzero (a dword), selecting the 0x114 arguments.
Stack-address arguments are recorded by contents only (see docs/20-unclaimed-23.md, lesson)."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)


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


def _arg(n):
    """mov eax,[esp+4n]: the value of argument n (1-based) into eax. The caller stores it."""
    return b'\x8b\x44\x24' + bytes([4 * n])


def _gen(c):
    self_ = _rnd(c, 0x800)
    rm = _rnd(c, 0x2000)
    o = _rnd(c, 0x400)
    R = _rnd(c, 0x400)
    G_ = _rnd(c, 0x400)
    X = _rnd(c, 0x400)
    M = _rnd(c, 0x400)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)
    c.emu.w32(0x700390, G_)
    c.emu.w32(self_ + 0x44, M)
    c.emu.w32(self_ + 0x48, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x4c, c.rng.choice([0, c.rng.getrandbits(32) | 1]))

    # o: slot 0x138 returns R; slot 0x114 records its four arguments, returns V; slot 0x4c returns V2
    vt_o = c.emu.alloc(0x400, 4)
    c.emu.w32(vt_o + 0x138, _stub(c, b'\xb8' + _le(R) + b'\xc3'))
    cells114 = _cell(c, 4)
    code = b''
    for i in range(4):
        code += _arg(i + 1) + b'\xa3' + _le(cells114 + 4 * i)           # mov eax,[esp+4(i+1)]; mov [cell_i],eax
    V = c.rng.getrandbits(32)
    code += b'\xb8' + _le(V) + b'\xc2\x10\x00'                          # mov eax, V; ret 16
    c.emu.w32(vt_o + 0x114, _stub(c, code))
    V2 = c.rng.getrandbits(32)
    c.emu.w32(vt_o + 0x4c, _stub(c, b'\xb8' + _le(V2) + b'\xc3'))
    c.emu.w32(o, vt_o)

    # R: slot 0x88 records its first argument, writes Z through the second (out pointer); ret 8
    vt_r = c.emu.alloc(0x400, 4)
    cell88 = _cell(c)
    Z = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    code = _arg(1) + b'\xa3' + _le(cell88) + _arg(2) + b'\xc7\x00' + _le(Z) + b'\xc2\x08\x00'
    c.emu.w32(vt_r + 0x88, _stub(c, code))
    c.emu.w32(R, vt_r)

    # G: slot 0x20 records its two arguments and returns X (ret 8)
    vt_g = c.emu.alloc(0x400, 4)
    cell20 = _cell(c, 2)
    code = _arg(1) + b'\xa3' + _le(cell20) + _arg(2) + b'\xa3' + _le(cell20 + 4)
    code += b'\xb8' + _le(X) + b'\xc2\x08\x00'
    c.emu.w32(vt_g + 0x20, _stub(c, code))
    c.emu.w32(G_, vt_g)

    # X: slot 0x2c records ECX and its two arguments; caller cleans, so 'ret'
    vt_x = c.emu.alloc(0x400, 4)
    cell2c = _cell(c, 3)
    code = (b'\x89\x0d' + _le(cell2c) + _arg(1) + b'\xa3' + _le(cell2c + 4) +
            _arg(2) + b'\xa3' + _le(cell2c + 8) + b'\xc3')
    c.emu.w32(vt_x + 0x2c, _stub(c, code))
    c.emu.w32(X, vt_x)

    # M: slot 0x12c records args 1, 2 and 4, and the dword that arg 3 points to; ret 16
    vt_m = c.emu.alloc(0x400, 4)
    cell12c = _cell(c, 4)
    code = (_arg(1) + b'\xa3' + _le(cell12c) + _arg(2) + b'\xa3' + _le(cell12c + 4) +
            b'\x8b\x54\x24\x0c' + b'\x8b\x02' + b'\xa3' + _le(cell12c + 8) +       # mov edx,[esp+12]; mov eax,[edx]
            _arg(4) + b'\xa3' + _le(cell12c + 12) + b'\xc2\x10\x00')
    c.emu.w32(vt_m + 0x12c, _stub(c, code))
    c.emu.w32(M, vt_m)

    # this: slot 0x58 records ECX; ret
    vt_s = c.emu.alloc(0x400, 4)
    cell58 = _cell(c)
    c.emu.w32(vt_s + 0x58, _stub(c, b'\x89\x0d' + _le(cell58) + b'\xc3'))
    c.emu.w32(self_, vt_s)
    return [self_]


S(0x5c5be0, 'ZFFSearchLightAddActors::Init2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-23 batch 2; stubs for rm/o/R/G/X/M/this vtables; asm call for the caller-cleaned +0x2c')
