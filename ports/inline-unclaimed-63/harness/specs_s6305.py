"""specs_s6305.py - unclaimed-63 batch 5 (docs/20-unclaimed-63.md): the three destructors 0x49f720, 0x5db760 and 0x5dd060.
Each is thiscall with one argument (the flags byte, ret 4). Stubs, rewritten each case (with a translation flush):
  * global 0x70039c -> rm; rm+0x9b -> o; o's slot +0x34 records its argument (this) and returns (ret 4);
  * the hook at 0x7003b0 is a cdecl stub that counts its calls in a heap cell (it is always set: the PC faults if it is null);
  * 0x4690b0 (original, ss.patch): a cdecl stub that records its two arguments (this and the constant).
The flags are drawn from 0..7, so the hook and 0x4690b0 paths both run, and the flags-and-1 clear path too."""
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
    self_ = _rnd(c, 0x100)
    flags = c.rng.randint(0, 7) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    rm = _rnd(c, 0x200)
    o = _rnd(c, 0x80)
    vt_o = c.emu.alloc(0x200, 4)
    co = _cell(c)
    c.emu.w32(vt_o + 0x34, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(co) + b'\xc2\x04\x00'))
    c.emu.w32(o, vt_o)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)
    chook = _cell(c)
    c.emu.w32(0x7003b0, _stub(c, b'\xff\x05' + _le(chook) + b'\xc3'))
    c4690 = _cell(c, 2)
    ss.patch(c, 0x4690b0, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(c4690) + b'\x8b\x44\x24\x08\xa3' + _le(c4690 + 4) + b'\xc3'))
    _flush(c)
    return [self_, flags]


S(0x49f720, 'CAction::~CAction (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-63 batch 5; SEH frame not reproduced; 0x4690b0 stubbed; hook 0x7003b0 stub')
S(0x5db760, 'ZFireDamageBox::~ZFireDamageBox (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-63 batch 5; as CAction with constant 0x8c')
S(0x5dd060, 'ZFFMortar::~ZFFMortar (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-63 batch 5; as CAction with constant 0x7e')
