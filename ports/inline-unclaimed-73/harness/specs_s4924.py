"""specs_s4924.py - area 73 batch 49 (gap band, GUESS name). FUN_4e6420 advances the byte cursor stored at *this:
kind = (opcode & 0x3f) - 1 picks one of five cases through a jump table (kinds 5 and 11..unsigned big are no-ops).
Cases: +9, +5, skip a NUL-terminated string after the opcode (+2 + strlen), +1 + dword at +1, and the no-op. The buffer
always holds a NUL in bytes 1..0x30 so the string scan ends inside the case."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    buf = _rnd(c, 0x40)
    k = c.rng.randint(-1, 12)
    op = ((k + 1) & 0x3f) | (c.rng.getrandbits(2) << 6)
    e.wbytes(buf, bytes([op]))
    z = c.rng.randint(1, 0x30)
    e.wbytes(buf + z, b'\x00')
    slot = _rnd(c, 4)
    e.w32(slot, buf)
    return [slot]


S(0x4e6420, 'GUESS FUN_4e6420 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 49; bytecode cursor advance, jump table at 0x4e6474 with byte map at 0x4e6488')
