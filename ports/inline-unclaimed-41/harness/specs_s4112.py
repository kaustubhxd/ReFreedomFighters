"""specs_s4112.py - unclaimed-41 batch 12 (slice 13): 0x507510 (thiscall, one stack argument x, ret 4).

The accessor 0x5003d0 is original code: S = [x+4] = [D, offset 0, count 8], D = [T, _, limit 0x100], T = 0x100 random bytes
read as floats. The clamp constants C1 (0x67a284) and C2 (0x680a70) are read from the exe. The object o = [this+0x18] has four
slots: +0x624 (one float argument, checksum), +0x630 (one pointer argument: writes three random floats to it; the pointer is a
stack address, excluded from the checksum), +0x5e8 (one pointer argument, checksum, stack address excluded), +0x5e0 (two pointer
arguments, both stack addresses, checksum: the stack-address arguments are excluded). Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _vec_reader(c, nargs):
    """Stub for pointer arguments to 3-float vectors (stack addresses): sums the three dwords behind each pointer into
    acc[3*(k-1)+j] and counts calls. The sums are the observable content of the vectors (the pointers are not compared)."""
    acc = c.emu.alloc(4 * 3 * nargs, 4)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    for i in range(3 * nargs):
        c.emu.w32(acc + 4 * i, 0)
    b = b''
    for k in range(1, nargs + 1):
        b += b'\x8b\x44\x24' + bytes([4 * k])          # mov eax,[esp+4k]
        for j in range(3):
            disp = 4 * j
            b += b'\x8b\x50' + bytes([disp])            # mov edx,[eax+disp]
            b += b'\x01\x15' + ss.P(acc + 4 * (3 * (k - 1) + j))   # add [acc+..], edx
    b += b'\xff\x05' + ss.P(cnt)                       # inc dword [cnt]
    b += b'\x31\xc0'                                   # xor eax, eax
    b += b'\xc2' + bytes([4 * nargs, 0])
    return ss.code(c, b)


def _fn(c):
    vt = c.emu.alloc(0x100, 4)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1])
    c.emu.w32(vt + 0x624, s)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[], writes=[(1, 0, _f(c, -50, 50)), (1, 4, _f(c, -50, 50)), (1, 8, _f(c, -50, 50))])
    c.emu.w32(vt + 0x630, s)
    c.emu.w32(vt + 0x5e8, _vec_reader(c, 1))
    c.emu.w32(vt + 0x5e0, _vec_reader(c, 2))
    o = _rnd(c, 0x100)
    c.emu.w32(o, vt)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x18, o)

    tbl = c.emu.alloc(0x100, 4)
    for i in range(0x100 // 4):
        c.emu.w32(tbl + 4 * i, _f(c, -200, 200))
    d = c.emu.alloc(0x20, 4)
    c.emu.w32(d, tbl)
    c.emu.w32(d + 8, 0x100)
    st = c.emu.alloc(0x20, 4)
    c.emu.w32(st, d)
    c.emu.w32(st + 4, 0)
    c.emu.w32(st + 8, 8)
    x = _rnd(c, 0x20)
    c.emu.w32(x + 4, st)
    return [self_, x]


S(0x507510, 'fn507510 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_fn,
  note='unclaimed-41 batch 12; accessor original; four vt slots on this+0x18 (checksum; +0x630 writes v28)')
