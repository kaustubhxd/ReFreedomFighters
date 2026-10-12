"""specs_s2306.py - unclaimed-23 batch 6 (docs/20-unclaimed-23.md): ZRepositionCharacter::Init (0x5c41a0), thiscall, no
arguments, ret. this is a heap object with 4 readable bytes before it, or 0 (one case in five). Stubs, rewritten each case
(with a translation flush):
  * global 0x70039c -> rm; rm+0x9b -> o; o's slot +0x138 returns R;
  * R's slot +0x60 records its three stack arguments (ret 12);
  * global 0x70038c -> M; M's slot +0x20 records ECX and its argument and returns Z (0 or nonzero); M's slot +0xac records
    ECX and its argument (ret 4);
  * M+8 is a bare function (no arguments) that records ECX and returns V; M+0xc and M+0x10 are the bounds, set so the
    direct-call branch is taken about half the time;
  * the 4 bytes before this (this-4) hold a random value."""
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
    return b'\x8b\x44\x24' + bytes([4 * n])


def _gen(c):
    base = _rnd(c, 0x810)
    if c.rng.random() < 0.2:
        this = 0
    else:
        this = base + 0x10
        c.emu.w32(this - 4, c.rng.choice([0, c.rng.getrandbits(32)]))
    rm = _rnd(c, 0x2000)
    o = _rnd(c, 0x400)
    R = _rnd(c, 0x400)
    M = _rnd(c, 0x400)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)
    c.emu.w32(0x70038c, M)

    vt_o = c.emu.alloc(0x400, 4)
    c.emu.w32(vt_o + 0x138, _stub(c, b'\xb8' + _le(R) + b'\xc3'))
    c.emu.w32(o, vt_o)

    vt_r = c.emu.alloc(0x400, 4)
    cr = _cell(c, 3)
    code = b''
    for i in range(3):
        code += _arg(i + 1) + b'\xa3' + _le(cr + 4 * i)
    code += b'\xc2\x0c\x00'
    c.emu.w32(vt_r + 0x60, _stub(c, code))
    c.emu.w32(R, vt_r)

    # M: slot +0x20 records ECX and arg 1, returns Z; slot +0xac records ECX and arg 1 (ret 4)
    vt_m = c.emu.alloc(0x400, 4)
    cm20 = _cell(c, 2)
    Z = c.rng.choice([0, c.rng.getrandbits(32) | 1])
    code = (b'\x89\x0d' + _le(cm20) + _arg(1) + b'\xa3' + _le(cm20 + 4) +
            b'\xb8' + _le(Z) + b'\xc2\x04\x00')
    c.emu.w32(vt_m + 0x20, _stub(c, code))
    cmac = _cell(c, 2)
    code = b'\x89\x0d' + _le(cmac) + _arg(1) + b'\xa3' + _le(cmac + 4) + b'\xc2\x04\x00'
    c.emu.w32(vt_m + 0xac, _stub(c, code))
    c.emu.w32(M, vt_m)
    # M+8: bare function, records ECX, returns V
    cfn = _cell(c)
    V = c.rng.getrandbits(32)
    fn = _stub(c, b'\x89\x0d' + _le(cfn) + b'\xb8' + _le(V) + b'\xc3')
    c.emu.w32(M + 8, fn if c.rng.random() < 0.8 else 0)
    if c.rng.random() < 0.5:
        c.emu.w32(M + 0xc, 0)              # this >= 0 always: the bound check passes
        c.emu.w32(M + 0x10, 0xffffffff)    # this < max: passes
    else:
        c.emu.w32(M + 0xc, c.rng.getrandbits(32))
        c.emu.w32(M + 0x10, c.rng.getrandbits(32))
    if this and c.rng.random() < 0.3:
        c.emu.w32(M + 0x10, this)          # the boundary: this == M+0x10 takes the else branch ('>=' vs '>')
        c.emu.w32(M + 0xc, 0)
    return [this]


S(0x5c41a0, 'ZRepositionCharacter::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-23 batch 6; stubs: o vtbl+0x138, R vtbl+0x60, M vtbl+0x20/+0xac, M+8 function')
