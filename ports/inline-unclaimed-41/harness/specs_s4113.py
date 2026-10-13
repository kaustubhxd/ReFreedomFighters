"""specs_s4113.py - unclaimed-41 batch 13 (slice 13): 0x507f10 (thiscall, one stack argument x, ret 4).

Accessor 0x5003d0: original code. S = [x+4] = [D, offset 0, count 8], D = [T, _, limit 0x100]; T entries are 8 bytes: a random
float at +0 and a flag byte at +4 from {0, 1, 2, 3} (so the error path is taken about half the time). Logger L (0x700390) has a
vtable slot +0x20 (two arguments, returns an object Ob); Ob's vtable slot +0x2c is a checksum stub with three stack arguments, the
caller cleans (plain ret); the vtable's ecx is the vtable pointer, as in the PC. The hook (0x7003b0) is a counter stub (inc
dword [count]; ret), always set: the exe traps when it is zero (not modelled). The object o = [this+0x18] has a slot +0x60c with
one pointer argument to a vector (a reader stub sums the three dwords; the pointer is a stack address). Faulting cases must be 0."""
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
    acc = c.emu.alloc(4 * 3 * nargs, 4)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    for i in range(3 * nargs):
        c.emu.w32(acc + 4 * i, 0)
    b = b''
    for k in range(1, nargs + 1):
        b += b'\x8b\x44\x24' + bytes([4 * k])
        for j in range(3):
            b += b'\x8b\x50' + bytes([4 * j])
            b += b'\x01\x15' + ss.P(acc + 4 * (3 * (k - 1) + j))
    b += b'\xff\x05' + ss.P(cnt) + b'\x31\xc0' + b'\xc2' + bytes([4 * nargs, 0])
    return ss.code(c, b)


def _fn(c):
    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + ss.P(hook_cnt) + b'\xc3'))

    # logger L (global 0x700390): vtable slot +0x20 returns Ob; Ob's vtable slot +0x2c records its three arguments (caller cleans)
    vt_ob = c.emu.alloc(0x100, 4)
    s, _, _ = hs.stub(c, 3, ecx=True, edx=False, cleanup=False, mask=[1, 2, 3])
    c.emu.w32(vt_ob + 0x2c, s)
    ob = _rnd(c, 0x40)
    c.emu.w32(ob, vt_ob)
    vt_l = c.emu.alloc(0x100, 4)
    s, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], ret=ob)
    c.emu.w32(vt_l + 0x20, s)
    lg = _rnd(c, 0x40)
    c.emu.w32(lg, vt_l)
    c.emu.w32(0x700390, lg)

    # this and o = this+0x18 (slot +0x60c takes one pointer to a vector)
    vt_o = c.emu.alloc(0x800, 4)
    c.emu.w32(vt_o + 0x60c, _vec_reader(c, 1))
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt_o)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x18, o)

    # the accessor structure: 8 records of 8 bytes
    t = c.emu.alloc(0x100, 4)
    for i in range(8):
        c.emu.w32(t + 8 * i, _f(c, -100, 100))
        c.emu.wbytes(t + 8 * i + 4, bytes([c.rng.choice([0, 1, 2, 3, 2, 0])]))
    d = c.emu.alloc(0x20, 4)
    c.emu.w32(d, t)
    c.emu.w32(d + 8, 0x100)
    st = c.emu.alloc(0x20, 4)
    c.emu.w32(st, d)
    c.emu.w32(st + 4, 0)
    c.emu.w32(st + 8, 8)
    x = _rnd(c, 0x20)
    c.emu.w32(x + 4, st)
    return [self_, x]


S(0x507f10, 'fn507f10 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_fn,
  note='unclaimed-41 batch 13; error path (logger, hook); hook set to a counter stub (the exe traps when it is zero)')
