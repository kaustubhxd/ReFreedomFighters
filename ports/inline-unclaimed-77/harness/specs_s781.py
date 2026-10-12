"""specs_s781.py - unclaimed-77 claim 11 (docs/20-unclaimed-77.md): CEntityTracker::UpdateEntity(ZEntityInfo*). Thiscall, one argument,
ret 4. This+0x4c is an array A of 64 dwords in [0, 7]; this+0x50 is an array B of 8 records of 0x17 bytes (float at +4 random, word at
+0x15 in [8, 15] so the loops' increments and decrements stay inside A); this+0x54 = 8. The info block holds a pointer to an object O
(its vtable has counting stubs at 0x57c and 0x80 that log their second argument only); O+0x54 points to a descriptor whose dword +8 is
4 in half the cases. The info word at +0x15 is 0 to 6, its float at +4 is random. The CRT cookie check is not reproduced."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _log_second(c):
    """Thiscall stub with two stack arguments (ret 8): logs its second argument in an 8-entry ring, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x08\x89\x10'                 # mov edx, [esp+8]; mov [eax], edx
         + b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc2\x08\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x100)
    A = _rnd(c, 64 * 4)
    for k in range(64):
        c.emu.w32(A + 4 * k, c.rng.randint(0, 7))
    B = _rnd(c, 0x17 * 8 + 0x20)
    info = _rnd(c, 0x40)
    x_bits = struct.pack('<f', c.rng.uniform(-50.0, 50.0))
    c.emu.wbytes(info + 4, x_bits)
    for r in range(8):
        base = B + 0x17 * r
        c.emu.wbytes(base + 0x15, struct.pack('<H', c.rng.randint(8, 15)))
        if c.rng.random() < 0.4:
            c.emu.wbytes(base + 4, x_bits)          # equal floats: the >= and > boundary runs
    c.emu.w32(self + 0x4c, A)
    c.emu.w32(self + 0x50, B)
    c.emu.w32(self + 0x54, 8)
    D = _rnd(c, 0x20)
    c.emu.w32(D + 8, 4 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    O = ss.mkobj(c, {0x57c: _log_second(c), 0x80: _log_second(c)}, size=0x100)
    c.emu.w32(O + 0x54, D)
    c.emu.w32(info, O)
    c.emu.wbytes(info + 0x15, struct.pack('<H', c.rng.randint(0, 6)))
    return [self, info]


S(0x5c0900, 'CEntityTracker::UpdateEntity (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-77 claim 11; virtual slots 0x57c and 0x80 stubbed (GUESS); CRT cookie check not reproduced')
