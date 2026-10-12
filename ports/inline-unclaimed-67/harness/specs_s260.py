"""specs_s260.py - unclaimed area 67, slice 6: six leaves (FUN_ names; bodies checked from the PC bytes)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x4f0020, 'FUN_4f0020 (getByte20)', 'thiscall', None, ret='al', gen=_obj, note='batch260; byte at +0x20')
S(0x54bba0, 'FUN_54bba0 (addr2c)', 'thiscall', None, ret='eax', gen=_obj, note='batch260; this+0x2c')
S(0x5acfe0, 'FUN_5acfe0 (addr8)', 'thiscall', None, ret='eax', gen=_obj, note='batch260; this+8')
S(0x4986e0, 'FUN_4986e0 (setByte50)', 'thiscall', None, ret=None, gen=_obj, note='batch260; byte at +0x50 := 1')
S(0x5060a0, 'FUN_5060a0 (constTableAddr)', 'thiscall', None, ret='eax', gen=_obj, note='batch260; returns 0x69c754')
S(0x5696a0, 'FUN_5696a0 (readGlobal6ec680)', 'thiscall', None, ret='eax', gen=_obj, note='batch260; dword at 0x6ec680')
