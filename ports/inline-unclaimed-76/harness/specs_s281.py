"""specs_s281.py - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 leaves: 0x5eebb0 (dword store at +0x6f) and
0x59d3f0 (four calls on the stack argument: slot 0x10 twice with (ptr, 4), slot 0x3c twice with one dword)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _store(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _send(c):
    e = c.emu
    a_vt = e.logging_vtable('a59d3', 0x11, impl={}, argwords={0x10: 2, 0x3c: 1})
    A = _rnd(c, 0x40)
    e.w32(A, a_vt)
    self_ = _rnd(c, 0x40)
    return [self_, A]


S(0x5eebb0, 'setField6f (GUESS)', 'thiscall', None, ret=None, gen=_store, note='batch281; ret 4')
S(0x59d3f0, 'sendRec (GUESS)', 'thiscall', None, ret='al', gen=_send, note='batch281; ret 4')
