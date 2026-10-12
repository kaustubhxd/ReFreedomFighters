"""specs_s6315.py - unclaimed-63 batch 15 (docs/20-unclaimed-63.md): three thunks 0x558ae0, 0x558b10 (one argument P, ret 4)
and 0x558b40 (one unused argument, ret 4). Stubs, rewritten each case (with a flush):
  * 0x5003d0 (original, ss.patch): records ECX and its argument, returns F (a random buffer; its first dword is 0 in half the cases);
  * this+0x1c -> O; O's vtable slots +0x6fc and +0x700 record their argument and return (ret 4); +0x6e0 records ECX (ret);
  * P+4 is a random value."""
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


def _gen(c, with_unused=False):
    self_ = _rnd(c, 0x40)
    O = _rnd(c, 0x800)
    c.emu.w32(self_ + 0x1c, O)
    vt = c.emu.alloc(0x800, 4)
    c6fc, c700, c6e0 = _cell(c, 2), _cell(c, 2), _cell(c)
    c.emu.w32(vt + 0x6fc, _stub(c, b'\x89\x0d' + _le(c6fc) + b'\x8b\x44\x24\x04\xa3' + _le(c6fc + 4) + b'\xc2\x04\x00'))
    c.emu.w32(vt + 0x700, _stub(c, b'\x89\x0d' + _le(c700) + b'\x8b\x44\x24\x04\xa3' + _le(c700 + 4) + b'\xc2\x04\x00'))
    c.emu.w32(vt + 0x6e0, _stub(c, b'\x89\x0d' + _le(c6e0) + b'\xc3'))
    c.emu.w32(O, vt)
    P = _rnd(c, 0x20)
    c.emu.w32(P + 4, c.rng.getrandbits(32))
    cf = _cell(c, 2)
    F = _rnd(c, 0x20)
    if c.rng.random() < 0.5:
        c.emu.w32(F, 0)
    ss.patch(c, 0x5003d0, _stub(c, b'\x89\x0d' + _le(cf) + b'\x8b\x44\x24\x04\xa3' + _le(cf + 4) +
                                b'\xb8' + _le(F) + b'\xc2\x04\x00'))
    _flush(c)
    return [self_, c.rng.getrandbits(32)] if with_unused else [self_, P]


def _gen_a(c):
    return _gen(c)


def _gen_b(c):
    return _gen(c, with_unused=True)


S(0x558ae0, 'GUESS FUN_558ae0 thiscall', 'thiscall', None, ret=None, gen=_gen_a,
  note='unclaimed-63 batch 15; 0x5003d0 stubbed; tail call to vtbl+0x6fc as a call')
S(0x558b10, 'GUESS FUN_558b10 thiscall', 'thiscall', None, ret=None, gen=_gen_a,
  note='unclaimed-63 batch 15; as 0x558ae0 with slot +0x700')
S(0x558b40, 'GUESS FUN_558b40 thiscall', 'thiscall', None, ret=None, gen=_gen_b,
  note='unclaimed-63 batch 15; vtbl+0x6e0 with no arguments')
