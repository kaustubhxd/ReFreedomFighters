"""specs_s1020.py - unclaimed-10, batch 16: two save-game load routines (0x4b8a10 ZRelayMessageList::Load, 0x4c4e50
ZAnimSequence::Load). Thiscall, one argument (the ZLoadGame), return al = 1. The load object has a logging vtable whose slots
+0x50, +0x58, +0x68, +0x70 (one argument each) are the unverified callees; the arguments are logged, so the field addresses and
the dword read from +0x6a are compared."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    e = c.emu
    vt = e.logging_vtable('zload', 32, argwords={0x50: 1, 0x58: 1, 0x68: 1, 0x70: 1})
    ld = _rnd(c, 0x40)
    e.w32(ld, vt)
    return [_rnd(c, 0x800), ld]


S(0x4b8a10, 'ZRelayMessageList::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-10 batch 16; load->vt[+0x50] stubbed; returns 1')
S(0x4c4e50, 'ZAnimSequence::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-10 batch 16; load->vt[+0x58], [+0x68], [+0x70] stubbed; returns 1')
