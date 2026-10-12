"""specs_s305.py - unclaimed-03 batch 5 (docs/20-unclaimed-03.md): unnamed function 0x46ba60. Its vtable slot +0x324 is a
fresh stub per case that copies its stack argument into a heap cell (mov eax,[esp+4]; mov [cell],eax; ret 4), so the
argument is compared. The low word of a1 equals the word at +0x92 in half the cases, so both branches run. The callee
0x46b800 is STUBBED in both runs (it dereferences game globals that the spec does not model): the stub copies its two
stack arguments into heap cells and returns with ret 8. So 0x46ba60 is verified against that stub, not against the real
0x46b800 body; the callee is not verified here."""
from pilot import S

def _flush(c):
    """Stub code is written into the heap and the exe image at the same addresses each case. Drop Unicorn's translations
    for both so the new bytes run (see docs/20-unclaimed-20.md, harness note; added here, batch 11 review)."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
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


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _gen(c):
    o = _rnd(c, 0x800)
    vt = c.emu.alloc(0x400, 4)
    cell = c.emu.alloc(8, 4)
    c.emu.w32(cell, 0)
    code = b'\x8b\x44\x24\x04' + b'\xa3' + cell.to_bytes(4, 'little') + b'\xc2\x04\x00'
    c.emu.w32(vt + 0x324, _stub(c, code))
    c.emu.w32(o, vt)
    # stub for the callee 0x46b800: record a1 (first) and a2 (second) in heap cells, then ret 8
    ca1 = c.emu.alloc(8, 4)
    ca2 = c.emu.alloc(8, 4)
    c.emu.w32(ca1, 0)
    c.emu.w32(ca2, 0)
    stub = (b'\x8b\x44\x24\x04\xa3' + ca1.to_bytes(4, 'little') +
            b'\x8b\x44\x24\x08\xa3' + ca2.to_bytes(4, 'little') + b'\xc2\x08\x00')
    ss.patch(c, 0x46b800, _stub(c, stub))
    _flush(c)
    a1 = c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        w = int.from_bytes(c.emu.rbytes(o + 0x92, 2), 'little')
        a1 = (a1 & 0xffff0000) | w
    return [o, a1, c.rng.getrandbits(32)]


S(0x46ba60, 'unnamed (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-03 batch 5; low word of a1 vs +0x92; slot +0x324 stub; tail to 0x46b800 (original)')
