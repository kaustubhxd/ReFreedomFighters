"""specs_s1415.py - unclaimed-14 batch 15 (residue 13): ZWindControl::Save (0x4c36d0) and ZFFActorActionThrow::Save (0x5eb710).

The save object (a ZSaveGame stand-in, 0x200 bytes) has a vtable whose slots are stubs (helper_stubs.stub, callee pops):
+0x3c, +0x4c (returns a sub-object R, or a random eax), +0x60, +0x64, +0x68 (returns a random eax), +0x6c. The sub-object R
has slot +0x4c. Values are random bit patterns for the floats. Both functions take one stack argument.

Limit: both calls to save.vt+0x4c in ZWindControl::Save hit the same stub, so the stub's checksum does not tell the two
apart by order; a mutant that swaps the two float arguments between them is not caught by the checksum alone. The field
offsets (+0x4c vs +0x54) and the sub-object calls are still checked."""
from pilot import S
import helper_stubs as hs


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt_save(c, ret4c):
    vt = c.emu.alloc(0x100, 4)
    for off, cnt, ret in [(0x3c, 1, 0), (0x60, 1, 0), (0x64, 1, 0), (0x68, 1, c.rng.getrandbits(32)), (0x6c, 1, 0)]:
        s, _, _ = hs.stub(c, cnt, ecx=True, edx=False, ret=ret)
        c.emu.w32(vt + off, s)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, ret=ret4c)
    c.emu.w32(vt + 0x4c, s)
    return vt


def _windsave(c):
    sub = c.emu.alloc(0x80, 4)
    vt_sub = c.emu.alloc(0x80, 4)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False)
    c.emu.w32(vt_sub + 0x4c, s)
    c.emu.w32(sub, vt_sub)
    save = _rnd(c, 0x200)
    c.emu.w32(save, _vt_save(c, sub))
    o = _rnd(c, 0x200)
    c.emu.w32(o + 4, c.rng.getrandbits(32))
    return [o, save]


def _throw(c):
    save = _rnd(c, 0x200)
    c.emu.w32(save, _vt_save(c, c.rng.getrandbits(32)))
    g = _rnd(c, 0x200)
    b = _rnd(c, 0x200)
    c.emu.w32(g + 0x9b, b)
    c.emu.w32(0x70039c, g)
    o = _rnd(c, 0x40)
    c.emu.w32(o + 0xc, c.rng.getrandbits(32))
    c.emu.wbytes(o + 0x14, bytes([c.rng.getrandbits(8)]))
    return [o, save]


S(0x4c36d0, 'ZWindControl::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_windsave,
  note='unclaimed-14 batch 15 (residue 13); save and sub-object vtable stubs')
S(0x5eb710, 'ZFFActorActionThrow::Save (unknown) thiscall', 'thiscall', None, ret='eax', gen=_throw,
  note='unclaimed-14 batch 15 (residue 13); save vtable stubs; global+0x9b object +0x44')
