"""specs_s2729.py - unclaimed-27 batch 31: FUN_59c4a0 (GUESS, void, no arguments). The global 0x70039c is a fresh 0x2000-byte object G
with G+0x9b = engine E (0xc00 bytes) and G+0x1aa3 = O, whose vtable slot +0x94 (thiscall, no args) is a STUB returning one fixed
record pointer R (0x100 bytes). The stub is not verified. Limit: both calls return the same R, so a mutant that swaps the two
calls' targets is not caught here."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _f4a0(c):
    R = _rnd(c, 0x100)
    vt = c.emu.alloc(0x200, 4)
    c.emu.w32(vt + 0x94, _stub(c, b'\xb8' + R.to_bytes(4, 'little') + b'\xc3'))   # mov eax, R; ret
    O = _rnd(c, 0x100)
    c.emu.w32(O, vt)
    E = _rnd(c, 0xc00)
    G = _rnd(c, 0x2000)
    c.emu.w32(G + 0x9b, E)
    c.emu.w32(G + 0x1aa3, O)
    c.emu.w32(0x70039c, G)
    c.emu.mu.ctl_flush_tb()
    return []


S(0x59c4a0, 'FUN_59c4a0 (GUESS) cdecl-void', 'cdecl', None, ret=None, gen=_f4a0, reg_values=True,
  note='unclaimed-27 batch 31; vtable slot +0x94 is a stub returning a fixed record')
