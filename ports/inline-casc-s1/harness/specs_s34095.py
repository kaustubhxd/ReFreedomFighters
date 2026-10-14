"""specs_s34095.py - seven items. 0x624650: three random bytes at p (the tables are exe data); 0x5ffe20: chain of 1..3 nodes with start/count around the argument; 0x658dc0: n in 0..4 entries, key equal in a half."""
from pilot import S
from recruits_util import rnd, clear_hooks
import struct
import pe_emu
import pefile

_pe = pefile.PE(pe_emu.DEFAULT_EXE)
_base = _pe.OPTIONAL_HEADER.ImageBase
_T2 = _pe.get_data(0x6bfc20 - _base, 256)
_T1 = struct.unpack('<%dI' % 256, _pe.get_data(0x6bf720 - _base, 1024))


def _filt(ids):
    def g(c):
        clear_hooks(c)
        r = c.rng
        a = rnd(c, 0x20)
        c.emu.w32(a + 0xc, r.choice([0, 0, 1, r.getrandbits(32)]))
        return [a, r.choice(ids + [0xf, 0x1c, 0x1c, 0, 0x1d, r.getrandbits(32), 0xffffffff])]
    return g


def _g658dc0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x50)
    n = r.choice([0, 1, 2, 4])
    c.emu.wbytes(me + 0x3d, bytes([n]))
    c.emu.wbytes(me + 0x3e, bytes([r.choice([0, 0xff, 1])]))
    tbl = rnd(c, 0x40)
    c.emu.w32(me + 0x40, tbl)
    a = r.getrandbits(32)
    for i in range(n):
        c.emu.w32(tbl + 8 * i + 4, a if r.random() < 0.3 else r.getrandbits(32))
    return [me, a]


def _g624650(c):
    clear_hooks(c)
    r = c.rng
    p = rnd(c, 0x10)
    b0, b1, b2 = r.getrandbits(8), r.getrandbits(8), r.getrandbits(8)
    if r.random() < 0.6:   # steer towards set bits so that the second-level index bits matter
        t = _T2[16 * (b0 & 0xf) + ((b1 >> 2) & 0xf)]
        i = (b1 & 3) + t * 4
        j = 2 * i + ((b2 >> 5) & 1)
        bits = [k for k in range(32) if _T1[j] >> k & 1]
        if bits:
            b2 = (b2 & 0xe0) | r.choice(bits)
    c.emu.wbytes(p, bytes([b0, b1, b2]))
    return [r.getrandbits(32), p]


def _g5ffe20(c):
    clear_hooks(c)
    r = c.rng
    k = r.randrange(1, 4)
    nodes = [rnd(c, 0x140) for _ in range(k)]
    a = r.choice([0, 5, 100, 0xffffffff, r.getrandbits(32)])
    for i, n in enumerate(nodes):
        start = (a + r.choice([-3, -1, 0, 1, 5, -20])) & 0xffffffff
        cnt = r.choice([0, 1, 2, 4, 10, 0xffffffff])
        c.emu.w32(n + 0x12a, start)
        c.emu.w32(n + 0x12e, cnt)
        c.emu.w32(n + 0x9c, nodes[i + 1] if i + 1 < k else 0)
    return [nodes[0], a]


S(0x62d110, 'GUESS event filter L', 'cdecl', None, ret='eax', gen=_filt([0x1b, 0x1b]), note='batch34095')
S(0x62d8f0, 'GUESS event filter M', 'cdecl', None, ret='eax', gen=_filt([0x1b, 0x1b]), note='batch34095')
S(0x62db10, 'GUESS event filter N', 'cdecl', None, ret='eax', gen=_filt([0x1b, 0x1b]), note='batch34095')
S(0x62dee0, 'GUESS event filter O', 'cdecl', None, ret='eax', gen=_filt([0x1b, 0x1b]), note='batch34095')
S(0x658dc0, 'GUESS find value by key', 'thiscall', None, ret='eax', gen=_g658dc0, note='batch34095')
S(0x624650, 'GUESS bit table test', 'cdecl', None, ret='eax', gen=_g624650, note='batch34095')
S(0x5ffe20, 'GUESS element address in chained ranges', 'thiscall', None, ret='eax', gen=_g5ffe20, note='batch34095')
