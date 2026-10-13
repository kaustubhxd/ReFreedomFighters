"""specs_s1405.py - unclaimed-14 batch 5 (slice 13): CMsgForward::Init (0x49ef10, thiscall, no arguments).

Each case: a random 0x200-byte forwarder whose byte at +4 is random (bit 0x2 set about half the time). The object at +0x44
is a fresh object with a stub in vtable slot +0x20 returning a random eax. The global at 0x70039c points to object A
(0x200 bytes); A+0x9b points to object B, whose vtable slot +0x4c stub stores its argument at B+0x30 and returns a random
eax. So both calls and their results reach the heap."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    m = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(m, code)
    return m


def _init(c):
    f = _rnd(c, 0x200)
    flag = c.rng.getrandbits(8)
    c.emu.wbytes(f + 4, bytes([flag | 2 if c.rng.random() < 0.5 else flag & ~2 & 0xff]))
    # object P (this+0x44): vtable slot +0x20 returns an immediate in eax
    p = _rnd(c, 0x200)
    vtp = c.emu.alloc(0x60, 4)
    r1 = c.rng.getrandbits(32)
    c.emu.w32(vtp + 0x20, _stub(c, b'\xb8' + r1.to_bytes(4, 'little') + b'\xc3'))
    c.emu.w32(p, vtp)
    c.emu.w32(f + 0x44, p)
    # object B (global A+0x9b): slot +0x4c stores [esp+4] at B+0x30 and returns an immediate
    a = _rnd(c, 0x200)
    b = _rnd(c, 0x200)
    vtb = c.emu.alloc(0x60, 4)
    r2 = c.rng.getrandbits(32)
    code = b'\x8b\x44\x24\x04' + b'\x89\x41\x30' + b'\xb8' + r2.to_bytes(4, 'little') + b'\xc2\x04\x00'
    c.emu.w32(vtb + 0x4c, _stub(c, code))
    c.emu.w32(b, vtb)
    c.emu.w32(a + 0x9b, b)
    c.emu.w32(0x70039c, a)
    return [f]


S(0x49ef10, 'CMsgForward::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-14 batch 5; stubs: P slot +0x20 (no args), global B slot +0x4c (one arg, stores it at B+0x30)')
