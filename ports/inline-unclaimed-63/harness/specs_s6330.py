"""specs_s6330.py - unclaimed-63 gap-band batch 30: 0x4cc630 (A+D+E set, one stack argument s, ret 4). The string is a random
printable string of 0 to 0x90 characters, plus the 0x7c and 0x100 boundaries (both the inline copy and the allocation branch run). this is a 0x80-byte object; the
allocation 0x41e290 (cdecl, original) is stubbed: it records its argument and returns a 0x200-byte random buffer."""
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
    r = c.rng.random()
    if r < 0.35:
        n = c.rng.randint(0x7a, 0x7e)          # the 0x7c inline limit
    elif r < 0.6:
        n = c.rng.choice([0xfe, 0xff, 0x100, 0x101, 0x102])   # the 0x100 limit of the extra store
    else:
        n = c.rng.randint(0, 0x90)
    chars = bytes(c.rng.randint(0x21, 0x7e) for _ in range(n)) + b'\x00'
    sbuf = c.emu.alloc(len(chars) + 16, 4)
    c.emu.wbytes(sbuf, chars)
    ca = _cell(c)
    BUF = _rnd(c, 0x200)
    code = b'\x8b\x44\x24\x04\xa3' + _le(ca) + b'\xb8' + _le(BUF) + b'\xc3'
    ss.patch(c, 0x41e290, _stub(c, code))
    _flush(c)
    return [self_, sbuf]


S(0x4cc630, 'unnamed A+D+E 0x4cc630 thiscall', 'thiscall', None, ret=None, gen=_gen, note='unclaimed-63 band batch 30; 0x41e290 stubbed')
