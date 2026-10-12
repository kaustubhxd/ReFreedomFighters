"""specs_s6326.py - unclaimed-63 gap-band batch 26: 0x4cde20 (no return value) and 0x4cdf70 (returns 0 or 1), each thiscall with one
stack argument (target, ret 4). The iterator is the object's vtable: slot +0x4c and +0x44 are plain stubs (+0x44 records ECX);
slot +0x64 returns a ring of node values (0 at the end, the target is one of them in half the cases) and records ECX; slot +0x5c
writes a flag through its pointer argument (1 while the ring has values, 0 at its end) and returns a node value from the same ring.
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


def _ring_vals(c):
    n = c.rng.randint(0, 3)
    nodes = [c.rng.getrandbits(32) | 0x1000 for _ in range(n)]
    return nodes + [0]


def _gen(c, ret_flag):
    self_ = _rnd(c, 0x40)
    vals = _ring_vals(c)
    target = c.rng.choice(vals + [c.rng.getrandbits(32) | 0x2000]) if vals else c.rng.getrandbits(32)
    vt = c.emu.alloc(0x400, 4)
    cnt = _cell(c)
    ring = _cell(c, 4)
    tab = c.emu.alloc(16, 4)
    for i in range(4):
        c.emu.w32(tab + 4 * i, vals[i] if i < len(vals) else 0)
    c44 = _cell(c)
    # slot +0x4c: plain ret 4; slot +0x44: records ECX, ret 4
    c.emu.w32(vt + 0x4c, _stub(c, b'\xc2\x04\x00'))
    c.emu.w32(vt + 0x44, _stub(c, b'\x89\x0d' + _le(c44) + b'\xc2\x04\x00'))
    # slot +0x64: ring of records (ECX at ring index), returns tab[cnt]; slot +0x5c: writes flag via its arg, returns tab[cnt]
    # the flag is 1 while the ring has values and 0 at its end (the terminator), so the loop stops where the ring does
    ftab = c.emu.alloc(16, 4)
    for i in range(4):
        c.emu.w32(ftab + 4 * i, 1 if i < len(vals) else 0)
    body64 = (b'\x8b\x15' + _le(cnt) + b'\x8b\x04\x95' + _le(tab) + b'\xff\x05' + _le(cnt) + b'\xc2\x04\x00')
    c.emu.w32(vt + 0x64, _stub(c, body64))
    body5c = (b'\x8b\x15' + _le(cnt) + b'\x8b\x04\x95' + _le(ftab) + b'\x8b\x4c\x24\x04\x89\x01' +
              b'\x8b\x04\x95' + _le(tab) + b'\xff\x05' + _le(cnt) + b'\xc2\x04\x00')
    c.emu.w32(vt + 0x5c, _stub(c, body5c))
    c.emu.w32(self_, vt)
    _flush(c)
    return [self_, target]


def _gen_de20(c):
    return _gen(c, False)


def _gen_df70(c):
    return _gen(c, True)


S(0x4cde20, 'unnamed C-set 0x4cde20 thiscall', 'thiscall', None, ret=None, gen=_gen_de20, note='unclaimed-63 band batch 26')
S(0x4cdf70, 'unnamed C-set 0x4cdf70 thiscall', 'thiscall', None, ret='eax', gen=_gen_df70, note='unclaimed-63 band batch 26')
