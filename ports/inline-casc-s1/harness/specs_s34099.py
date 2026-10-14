"""specs_s34099.py - seven items.
0x5ed3d0: pointer array (unaligned begin / end at +0xcb / +0xcf) of 0..3 objects, index c in {-1, 0..2}, a / b equal to the object's fields in a half. 0x628c10: strings from the exe table at 0x6f4440 with random case flips (read with pefile) or random text.
0x54a0e0: random blocks. 0x5b58a0: small state bytes, sums around val. 0x628f30: six-byte tokens X/x, M/m, L/l with perturbations. 0x537270: base block with header, entries and pairs. 0x622270: entity names."""
import struct
import pefile
import pe_emu
from pilot import S
from recruits_util import rnd, clear_hooks

_pe = pefile.PE(pe_emu.DEFAULT_EXE)
_base = _pe.OPTIONAL_HEADER.ImageBase


def _cstr(va):
    out = b''
    while True:
        b = _pe.get_data(va - _base, 1)
        if b == b'\0':
            return out
        out += b
        va += 1


_TAB = [_cstr(struct.unpack('<I', _pe.get_data(0x6f4440 - _base + 4 * i, 4))[0]) for i in range(6)]


def _g5ed3d0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x100)
    k = r.choice([0, 1, 2, 3])
    arr = rnd(c, 0x20)
    a = r.getrandbits(32) if r.random() < 0.4 else r.randrange(0, 5)
    b = r.choice([0, 1, 0xffff, 0xffffffff, 0x10000, 5, r.getrandbits(32)])
    objs = []
    for i in range(k):
        o = rnd(c, 0x20)
        if r.random() < 0.5:
            c.emu.w32(o + 8, a)
            c.emu.wbytes(o + 0xe, (b & 0xffff).to_bytes(2, 'little'))
        c.emu.w32(arr + 4 * i, o)
        objs.append(o)
    c.emu.wbytes(me + 0xcb, arr.to_bytes(4, 'little'))
    c.emu.wbytes(me + 0xcf, (arr + 4 * k).to_bytes(4, 'little'))
    c_idx = 0xffffffff if (k == 0 or r.random() < 0.6) else r.randrange(0, k)
    if k == 0:
        c.emu.wbytes(me + 0xcf, arr.to_bytes(4, 'little'))
    return [me, a, b, c_idx]


def _g628c10(c):
    clear_hooks(c)
    r = c.rng
    if r.random() < 0.1:
        return [0]
    s = rnd(c, 0x30)
    if r.random() < 0.7:
        t = bytes(ch ^ 0x20 if r.random() < 0.4 and (65 <= ch <= 90 or 97 <= ch <= 122) else ch for ch in r.choice(_TAB))
        if r.random() < 0.2 and t:
            t = t[:-1] + bytes([(t[-1] + 1) & 0xff or 1])
    else:
        t = bytes(r.choice(b'abcXYZ') for _ in range(r.randrange(0, 6)))
    c.emu.wbytes(s, t + b'\0')
    return [s]


def _g54a0e0(c):
    clear_hooks(c)
    return [rnd(c, 0x70), rnd(c, 0x60)]


def _g5b58a0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    c.emu.wbytes(me, bytes([r.choice([0, 1]), r.choice([0, 1]), r.getrandbits(8), r.choice([0, 0, 1]), r.choice([0, 1])]))
    s5 = r.randrange(0, 10)
    s9 = r.randrange(0, 10)
    c.emu.wbytes(me + 5, s5.to_bytes(4, 'little'))
    c.emu.wbytes(me + 9, s9.to_bytes(4, 'little'))
    val = r.choice([s5 + s9 - 1, s5 + s9, s5 + s9 + 1, 0, 0xffffffff, 100])
    return [me, rnd(c, 0x10), rnd(c, 0x10), r.choice([0, 1, 1, 0x100, 0x101]), val & 0xffffffff]


def _g628f30(c):
    clear_hooks(c)
    r = c.rng
    p = rnd(c, 0x10)
    t = bytearray([r.choice(b'Xx'), 0, r.choice(b'Mm'), 0, r.choice(b'Ll'), 0])
    if r.random() < 0.3:
        t[r.randrange(6)] = r.choice([1, 0x41, 0x58, 0x78, 0x4d, 0x6c])
    c.emu.wbytes(p, bytes(t))
    return [r.getrandbits(32), p, p + r.choice([6, 6, 6, 5, 7, 0]), rnd(c, 0x10)]


def _g537270(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x5310)
    base = rnd(c, 0x400)
    a = r.randrange(1, 6)
    b = r.randrange(1, 6)
    if r.random() < 0.1:
        c.emu.wbytes(me + 0x5302, bytes(4))
        return [me, a, b]
    c.emu.w32(base, 0x100)
    n = r.choice([0, 1, 2, 3, 0xffffffff])
    h = base + 0x100
    c.emu.w32(h + 0x10, n)
    c.emu.w32(h + 0x28, 0x200)
    for i in range(3):
        c.emu.w32(base + 0x200 + 4 * i, 0x300 + 0x20 * i)
        e = base + 0x300 + 0x20 * i
        c.emu.w32(e + 8, r.getrandbits(32))
        x, y = r.choice([(a, b), (b, a), (r.randrange(1, 6), r.randrange(1, 6)), (0, b), (a, 0), (0, 0)])
        c.emu.w32(e + 0xc, x)
        c.emu.w32(e + 0x10, y)
    c.emu.wbytes(me + 0x5302, base.to_bytes(4, 'little'))
    return [me, a if r.random() > 0.15 else 0, b if r.random() > 0.15 else 0]


def _g622270(c):
    clear_hooks(c)
    r = c.rng
    p = rnd(c, 0x10)
    names = [b'lt', b'gt', b'amp', b'apos', b'quot', b'xx', b'l', b'ampp', b'lt;', b'ap', b'qout', b'aposs', b'gt']
    n = r.choice(names)
    if r.random() < 0.2:
        n = bytes(r.choice(b'agltmpqosu') for _ in range(r.randrange(2, 5)))
    c.emu.wbytes(p, n + b'\0\0\0')
    return [r.getrandbits(32), p, p + len(n)]


S(0x5ed3d0, 'GUESS update object fields and dirty flag', 'thiscall', None, ret=None, gen=_g5ed3d0, note='batch34099')
S(0x628c10, 'GUESS name to index case-insensitive', 'cdecl', None, ret='eax', gen=_g628c10, note='batch34099')
S(0x54a0e0, 'GUESS copy 22 dwords', 'stdcall', None, ret='eax', gen=_g54a0e0, note='batch34099')
S(0x5b58a0, 'GUESS edge detector state machine', 'thiscall', None, ret=None, gen=_g5b58a0, note='batch34099')
S(0x628f30, 'GUESS XML declaration token check', 'cdecl', None, ret='eax', gen=_g628f30, note='batch34099')
S(0x537270, 'GUESS find pair value', 'thiscall', None, ret='eax', gen=_g537270, note='batch34099')
S(0x622270, 'GUESS entity name to char', 'cdecl', None, ret='eax', gen=_g622270, note='batch34099')
