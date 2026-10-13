"""specs_s350.py - decomp area 64 (docs/20-unclaimed-64.md): exe helper 0x5002f0 (tagged set); logger 0x700390 and hook 0x7003b0 stubbed."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _set(c):
    e = c.emu
    # Logger L: its slot 0x2c is cdecl (three words, the caller pops): a recorder stub copies them to a heap cell and returns.
    rec = e.alloc(0xc, 4)
    e.wbytes(rec, bytes(0xc))
    code = b''
    for i in range(3):
        code += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x15' + ss.P(rec + 4 * i)   # mov edx,[esp+4+4i]; mov [rec+4i], edx
    code += b'\xc3'
    L_vt = _rnd(c, 0x40)
    e.w32(L_vt + 0x2c, ss.code(c, code))
    L = _rnd(c, 0x40)
    e.w32(L, L_vt)
    # Logger G3 at 0x700390: slot 0x20 takes two words and returns L.
    G3_vt = e.logging_vtable('g3_5002', 0x40, argwords={0x20: 2}, impl={0x20: lambda em, a: (L, None)})
    G3 = _rnd(c, 0x40)
    e.w32(G3, G3_vt)
    e.w32(0x700390, G3)
    # Hook at 0x7003b0: a cdecl no-argument stub that bumps a counter (so a call or a missing call is visible).
    cnt = e.alloc(4, 4)
    e.wbytes(cnt, bytes(4))
    hook = ss.code(c, b'\xff\x05' + ss.P(cnt) + b'\xc3')
    e.w32(0x7003b0, hook)

    self_ = _rnd(c, 0x20)
    tag = c.rng.choice([0, 1, 2, 5, 0xff, c.rng.getrandbits(8)])
    e.wbytes(self_ + 0x4, bytes([tag]))
    return [self_, c.rng.getrandbits(32)]


S(0x5002f0, 'setValue (GUESS)', 'thiscall', None, ret='eax', gen=_set,
  note='batch350; one stack word v; ret 4; logger 0x700390 (slot 0x20, L slot 0x2c) and hook 0x7003b0 stubbed')
