"""specs_s270.py - unclaimed area 67: the switch at 0x573ba0 (stdcall, one argument; table of constants)."""
from pilot import S


def _x(c):
    c.emu.mu.ctl_flush_tb()
    return [c.rng.choice([0, 1, 2, 5, 9, 12, 13, 14, 0x7fffffff, 0xffffffff, c.rng.getrandbits(32)])]


S(0x573ba0, 'FUN_573ba0 (switchConst)', 'stdcall', None, ret='eax', gen=_x, note='batch270; switch table 0x573c30, default 0')
