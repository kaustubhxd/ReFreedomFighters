"""specs_s1410.py - unclaimed-14 batch 10 (slice 13): ZInputActions::CheckActionCheat (0x4380d0, thiscall, two stack
arguments, ret 8, result in al).

Each case: a random 0x200-byte object with a vtable; the global at 0x70039c points to a 0xa00-byte block whose byte
at +0x9b9 is zero in about 1 case in 3. Stubs: slot +0x58 stores its argument at self+0x78 and returns a random eax;
slot +0x2c stores its two arguments at self+0x7c and self+0x80 and returns a random eax. The second argument of the
function is random and unread by the PC code."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    m = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(m, code)
    return m


def _cheat(c):
    o = _rnd(c, 0x200)
    vt = c.emu.alloc(0x80, 4)
    r58 = c.rng.getrandbits(32)
    r2c = c.rng.getrandbits(32)
    # mov eax,[esp+4]; mov [ecx+0x78],eax; mov eax,imm32; ret 4
    c.emu.w32(vt + 0x58, _stub(c, b'\x8b\x44\x24\x04' + b'\x89\x41\x78' + b'\xb8' + r58.to_bytes(4, 'little') + b'\xc2\x04\x00'))
    # mov eax,[esp+4]; mov [ecx+0x7c],eax; mov eax,[esp+8]; mov [ecx+0x80],eax (disp32: 0x80 is negative as disp8); mov eax,imm32; ret 8
    c.emu.w32(vt + 0x2c, _stub(c, b'\x8b\x44\x24\x04' + b'\x89\x41\x7c' + b'\x8b\x44\x24\x08' + b'\x89\x81\x80\x00\x00\x00'
                               + b'\xb8' + r2c.to_bytes(4, 'little') + b'\xc2\x08\x00'))
    c.emu.w32(o, vt)
    g = _rnd(c, 0xa00)
    flag = 0 if c.rng.random() < 0.33 else c.rng.randint(1, 255)
    c.emu.wbytes(g + 0x9b9, bytes([flag]))
    c.emu.w32(0x70039c, g)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4380d0, 'ZInputActions::CheckActionCheat (unknown) thiscall', 'thiscall', None, ret='al', gen=_cheat,
  note='unclaimed-14 batch 10; global byte +0x9b9 gates; slots +0x58 and +0x2c are stubs')
