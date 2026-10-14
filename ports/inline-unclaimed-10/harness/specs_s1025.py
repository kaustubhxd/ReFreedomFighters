"""specs_s1025.py - unclaimed-10, batch 21 (residue-10 list): CCheckInsideBox::Save (0x5b82e0) and CCheckVisible::Load (0x4aace0).
Thiscall, one argument, returns al = 1. Their save/load objects have logging vtables (the slots they call are unverified stubs):
Save: slots +0x3c and +0x64 (one argument each). Load: slots +0x18 (two arguments), +0x40 and +0x50 (one argument each)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    e = c.emu
    vt = e.logging_vtable('chkbox_save', 32, argwords={0x3c: 1, 0x64: 1})
    sv = _rnd(c, 0x40)
    e.w32(sv, vt)
    return [_rnd(c, 0x800), sv]


def _load(c):
    e = c.emu
    vt = e.logging_vtable('chkvis_load', 32, argwords={0x18: 2, 0x40: 1, 0x50: 1})
    ld = _rnd(c, 0x40)
    e.w32(ld, vt)
    return [_rnd(c, 0x16000), ld]


S(0x5b82e0, 'CCheckInsideBox::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-10 batch 21; save->vt[+0x3c] and [+0x64] stubbed; returns 1')
S(0x4aace0, 'CCheckVisible::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-10 batch 21; load->vt[+0x18], [+0x40], [+0x50] stubbed; returns 1')
