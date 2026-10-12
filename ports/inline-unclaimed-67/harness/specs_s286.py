"""specs_s286.py - unclaimed area 67: 0x439570 (lookup table helper). The table is read from the exe image (six records,
sizes 147, 12, 25, 25, 25, 25). x is drawn in [0, 259) (valid entries) and above (no entry), so no read goes before a record."""
from pilot import S


def _x(c):
    c.emu.mu.ctl_flush_tb()
    return [c.rng.choice([c.rng.randrange(0, 259), c.rng.randrange(0, 259), 259, 300, 0x7fffffff, 0x100])]


S(0x439570, 'FUN_439570 (lookupTable39570)', 'stdcall', None, ret='eax', gen=_x, note='batch286; table walk; x in valid range or past the end')
