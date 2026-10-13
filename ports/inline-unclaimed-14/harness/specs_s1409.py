"""specs_s1409.py - unclaimed-14 batch 9 (slice 13): ZFFFlak::Save (0x5dcfd0, thiscall, one stack argument, ret 4, returns al).

Each case: a random 0x200-byte flak (+4 random, floats at +0x48 and +0x4c as random bit patterns, +0x58 random) and a
random 0x200-byte save object with a vtable. Stubs: slot +0x4c stores its argument at save+0x60 and moves the previous
value of +0x60 to +0x6c, so both calls (first and second) are visible even though they use the same slot; slot +0x3c
stores its argument at save+0x70."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    m = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(m, code)
    return m


def _flak(c):
    f = _rnd(c, 0x200)
    sv = _rnd(c, 0x200)
    vt = c.emu.alloc(0x80, 4)
    # mov eax,[esp+4]; mov edx,[ecx+0x60]; mov [ecx+0x6c],edx; mov [ecx+0x60],eax; ret 4
    c.emu.w32(vt + 0x4c, _stub(c, b'\x8b\x44\x24\x04' + b'\x8b\x51\x60' + b'\x89\x51\x6c' + b'\x89\x41\x60' + b'\xc2\x04\x00'))
    # mov eax,[esp+4]; mov [ecx+0x70],eax; ret 4
    c.emu.w32(vt + 0x3c, _stub(c, b'\x8b\x44\x24\x04' + b'\x89\x41\x70' + b'\xc2\x04\x00'))
    c.emu.w32(sv, vt)
    return [f, sv]


S(0x5dcfd0, 'ZFFFlak::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_flak,
  note='unclaimed-14 batch 9; save stubs record slot +0x4c args (rotating) and slot +0x3c arg')
