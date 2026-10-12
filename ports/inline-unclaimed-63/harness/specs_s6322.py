"""specs_s6322.py - unclaimed-63 batch 22 (docs/20-unclaimed-63.md): 0x5e0ee0 (GUESS constructor), thiscall with two stack arguments
(ret 8; returns this). The object is 0x80 random bytes. Stubs (original callees, rewritten each case with a flush):
  * 0x4876a0 (thiscall, two stack arguments, ret 8): records ECX and its two arguments;
  * 0x41e290 (cdecl, one argument): records its argument and returns P, a random 0x1c-byte buffer (0 in one case of four);
  * 0x4ccbe0 (thiscall, two stack arguments, ret 8): records ECX and its arguments, returns R (a random value).
The SEH frame of the PC is not reproduced; no exception is raised on these paths."""
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


def _gen(c):
    self_ = _rnd(c, 0x80)
    a1, a2 = c.rng.getrandbits(32), c.rng.getrandbits(32)
    c4876 = _cell(c, 3)
    ss.patch(c, 0x4876a0, _stub(c, b'\x89\x0d' + _le(c4876) + b'\x8b\x44\x24\x04\xa3' + _le(c4876 + 4) +
                                b'\x8b\x44\x24\x08\xa3' + _le(c4876 + 8) + b'\xc2\x08\x00'))
    c41e = _cell(c)
    P = _rnd(c, 0x20) if c.rng.random() < 0.75 else 0
    ss.patch(c, 0x41e290, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(c41e) + b'\xb8' + _le(P) + b'\xc3'))
    c4cc = _cell(c, 3)
    R = c.rng.getrandbits(32)
    ss.patch(c, 0x4ccbe0, _stub(c, b'\x89\x0d' + _le(c4cc) + b'\x8b\x44\x24\x04\xa3' + _le(c4cc + 4) +
                                b'\x8b\x44\x24\x08\xa3' + _le(c4cc + 8) + b'\xb8' + _le(R) + b'\xc2\x08\x00'))
    _flush(c)
    return [self_, a1, a2]


S(0x5e0ee0, 'GUESS constructor thiscall (vptr 0x6b7678)', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-63 batch 22; SEH frame not reproduced; 0x4876a0, 0x41e290, 0x4ccbe0 stubbed')
