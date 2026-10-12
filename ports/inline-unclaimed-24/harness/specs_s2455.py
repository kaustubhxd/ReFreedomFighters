"""specs_s2455.py - decomp area 24, batch 2455 (gap band): ZGATE::CopyData(const ZGEOM*), thiscall, ret 4.
ZGEOM::CopyData (0x45d5b0, recorder, the argument), then three 16-byte blocks are copied from the argument (+0x22, +0x32,
+0x42) into this (same offsets). The argument object is 0x60 bytes."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _gate(c):
    clear_hooks(c)
    hook_rec(c, 0x45d5b0, 1, this=True)
    return [rnd(c, 0x80), rnd(c, 0x60)]


S(0x4531b0, 'ZGATE::CopyData', 'thiscall', None, ret=None, gen=_gate, note='batch2455')
