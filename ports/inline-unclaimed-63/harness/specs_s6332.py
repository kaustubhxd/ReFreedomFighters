"""specs_s6332.py - unclaimed-63 gap-band batch 32: 0x4ce0c0 (C-set; thiscall, one stack argument target, ret 4, returns a node pointer or 0).
The iterator is the object's vtable: slot +0x4c records ECX (ret 4); slot +0x64 records ECX and returns the next node of a short ring
(0 at the end). Each node is a 0x10-byte heap cell whose first dword is its value; the target is one of those values in half the cases.
Stubs are rewritten each case (with a flush)."""
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


def _gen_ce0c(c):
    self_ = _rnd(c, 0x40)
    n = c.rng.randint(0, 3)
    vals = [c.rng.getrandbits(32) | 1 for _ in range(n)]
    nodes = []
    for v in vals:
        nd = c.emu.alloc(0x10, 4)
        c.emu.wbytes(nd, bytes(12))
        c.emu.w32(nd, v)
        nodes.append(nd)
    target = c.rng.choice(vals) if vals and c.rng.random() < 0.5 else (c.rng.getrandbits(32) | 2)
    tab = c.emu.alloc(16, 4)
    for i in range(4):
        c.emu.w32(tab + 4 * i, nodes[i] if i < n else 0)
    vt = c.emu.alloc(0x100, 4)
    cnt = _cell(c)
    c4c, c64 = _cell(c), _cell(c)
    # slot +0x4c: records ECX, ret 4
    c.emu.w32(vt + 0x4c, _stub(c, b'\x89\x0d' + _le(c4c) + b'\xc2\x04\x00'))
    # slot +0x64: records ECX, returns tab[cnt] and advances cnt
    body64 = (b'\x89\x0d' + _le(c64) + b'\x8b\x15' + _le(cnt) + b'\x8b\x04\x95' + _le(tab) + b'\xff\x05' + _le(cnt) +
              b'\xc2\x04\x00')
    c.emu.w32(vt + 0x64, _stub(c, body64))
    c.emu.w32(self_, vt)
    _flush(c)
    return [self_, target]


S(0x4ce0c0, 'unnamed C-set 0x4ce0c0 thiscall', 'thiscall', None, ret='eax', gen=_gen_ce0c,
  note='unclaimed-63 band batch 32')
