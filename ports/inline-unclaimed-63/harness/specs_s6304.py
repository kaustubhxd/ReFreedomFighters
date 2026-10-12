"""specs_s6304.py - unclaimed-63 batch 4 (docs/20-unclaimed-63.md): CImpactResponse::End (0x5dc3e0) and 0x647320 (GUESS).
Stubs, rewritten each case (with a translation flush):
  * 0x5dc3e0: global 0x6762ec -> a stub (cdecl) that records its argument and returns;
  * 0x647320: global 0x70039c -> rm; rm+0x190f -> M; M's slot +0x20 records its argument and returns V;
    0x63eab0 (ss.patch) records ECX and returns E (0 or a random object); 0x658d00 (ss.patch) records ECX and returns a random
    0x200-byte buffer B; the argument x+8 -> y with y+0x5a a word that is zero in one case of four; [this+0x11] is 0..3
    (a dword at an unaligned offset)."""
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


def _gen_end(c):
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x4c, c.rng.getrandbits(32))
    cc = _cell(c)
    c.emu.w32(0x6762ec, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(cc) + b'\xc3'))
    return [self_]


def _gen_647(c):
    self_ = _rnd(c, 0x80)
    c.emu.wbytes(self_ + 0x11, bytes([c.rng.randint(0, 3), 0, 0, 0]))
    x = _rnd(c, 0x40)
    y = _rnd(c, 0x80)
    c.emu.w32(x + 8, y)
    word = bytes([0, 0]) if c.rng.random() < 0.25 else bytes([c.rng.getrandbits(8) | 1, c.rng.getrandbits(8)])
    c.emu.wbytes(y + 0x5a, word)
    rm = _rnd(c, 0x2000)
    M = _rnd(c, 0x80)
    c.emu.w32(rm + 0x190f, M)
    c.emu.w32(0x70039c, rm)
    vt_m = c.emu.alloc(0x200, 4)
    cm = _cell(c, 2)
    V = c.rng.getrandbits(32)
    c.emu.w32(vt_m + 0x20, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(cm) + b'\xb8' + _le(V) + b'\xc2\x04\x00'))
    c.emu.w32(M, vt_m)
    # 0x63eab0: records ECX, returns E
    ce = _cell(c)
    E = _rnd(c, 0x80) if c.rng.random() < 0.7 else 0
    ss.patch(c, 0x63eab0, _stub(c, b'\x89\x0d' + _le(ce) + b'\xb8' + _le(E) + b'\xc3'))
    _flush(c)
    # 0x658d00: records ECX, returns B
    cb = _cell(c)
    B = _rnd(c, 0x200, 4)
    ss.patch(c, 0x658d00, _stub(c, b'\x89\x0d' + _le(cb) + b'\xb8' + _le(B) + b'\xc3'))
    _flush(c)
    return [self_, x]


S(0x5dc3e0, 'CImpactResponse::End (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_end,
  note='unclaimed-63 batch 4; global 0x6762ec cdecl stub records its argument')
S(0x647320, 'GUESS FUN_647320 thiscall', 'thiscall', None, ret=None, gen=_gen_647,
  note='unclaimed-63 batch 4; 0x63eab0 and 0x658d00 stubbed; M vtbl+0x20 stub')
