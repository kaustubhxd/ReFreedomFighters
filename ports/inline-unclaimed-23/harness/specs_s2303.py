"""specs_s2303.py - unclaimed-23 batch 3 (docs/20-unclaimed-23.md): ZActorIf::SetVisRangeSpeed (0x5084a0), thiscall, one
stack argument (ret 4). Stubs, rewritten each case (with a translation flush):
  * global 0x70039c -> rm; rm+0x9b -> o. o's slot +0x4c records its argument and returns V4; o's slot +0x114 records its
    first four arguments and writes W through its fifth (the out pointer), returns R16; o's slot +0x58 records its two
    arguments and returns R58;
  * this+0x18 -> A; A's slot +0x130 records ECX and its argument, ret 4;
  * 0x5003d0 (original, ss.patch): records ECX and its argument, returns F (a random float buffer);
  * params+4 -> P (the argument of 0x5003d0)."""
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


def _arg(n):
    return b'\x8b\x44\x24' + bytes([4 * n])            # mov eax,[esp+4n]


def _gen(c):
    self_ = _rnd(c, 0x800)
    params = _rnd(c, 0x20)
    rm = _rnd(c, 0x2000)
    o = _rnd(c, 0x400)
    A = _rnd(c, 0x800)
    P = _rnd(c, 0x40)
    F = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x18, A)
    c.emu.w32(params + 4, P)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)
    c.emu.w32(A + 0x73a, c.rng.getrandbits(32))

    # o: slot 0x4c records its argument, returns V4 (ret 4)
    vt_o = c.emu.alloc(0x400, 4)
    c1 = _cell(c)
    V4 = c.rng.getrandbits(32)
    c.emu.w32(vt_o + 0x4c, _stub(c, _arg(1) + b'\xa3' + _le(c1) + b'\xb8' + _le(V4) + b'\xc2\x04\x00'))
    # slot 0x114: records args 1..4, writes W through arg 5, returns R16 (ret 20)
    c114 = _cell(c, 4)
    code = b''
    for i in range(4):
        code += _arg(i + 1) + b'\xa3' + _le(c114 + 4 * i)
    W = c.rng.getrandbits(32)
    R16 = c.rng.getrandbits(32)
    code += b'\x8b\x44\x24\x14' + b'\xc7\x00' + _le(W)              # mov eax,[esp+20]; mov dword [eax], W
    code += b'\xb8' + _le(R16) + b'\xc2\x14\x00'
    c.emu.w32(vt_o + 0x114, _stub(c, code))
    # slot 0x58 records args 1 and 2, returns R58 (ret 8)
    c58 = _cell(c, 2)
    R58 = c.rng.getrandbits(32)
    code = _arg(1) + b'\xa3' + _le(c58) + _arg(2) + b'\xa3' + _le(c58 + 4) + b'\xb8' + _le(R58) + b'\xc2\x08\x00'
    c.emu.w32(vt_o + 0x58, _stub(c, code))
    c.emu.w32(o, vt_o)

    # A: slot 0x130 records ECX and its argument, ret 4
    vt_a = c.emu.alloc(0x400, 4)
    ca_ecx, ca_arg = _cell(c), _cell(c)
    c.emu.w32(vt_a + 0x130, _stub(c, b'\x89\x0d' + _le(ca_ecx) + _arg(1) + b'\xa3' + _le(ca_arg) + b'\xc2\x04\x00'))
    c.emu.w32(A, vt_a)

    # 0x5003d0: records ECX and its argument, returns F (ret 4)
    c5 = _cell(c, 2)
    code = b'\x89\x0d' + _le(c5) + _arg(1) + b'\xa3' + _le(c5 + 4) + b'\xb8' + _le(F) + b'\xc2\x04\x00'
    ss.patch(c, 0x5003d0, _stub(c, code))
    _flush(c)
    return [self_, params]


S(0x5084a0, 'ZActorIf::SetVisRangeSpeed (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-23 batch 3; o vtbl +0x4c/+0x114/+0x58, A vtbl +0x130, 0x5003d0 stubbed')
