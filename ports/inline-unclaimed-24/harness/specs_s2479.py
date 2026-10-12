"""specs_s2479.py - decomp area 24, batch 2479.
0x45b460 (GUESS constructor): base 0x43de40 (recorder, three arguments), vtable 0x684358, 8.0f at +0x28, 10.0f at +0x2c, zeros at
+0x38, +0x3c, +0x30, +0x34, +0x24, +0x1c, +0x20, +0x18; ret 12, eax = this.
0x447920 (SEH frame not reproduced): vtable 0x67dc30; ZBaseGeom::LightNotifyPotentialDetachment(false) (0x4dbb00, recorder) on
the geometry at +8; then the SEH destructor body 0x45c3e0 (recorder) on this. The original installs an exception frame on fs:[0];
the port does not. Thiscall, plain ret."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de40, 3, this=True)
    return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _seh(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x4dbb00, 1, this=True)
    hook_rec(c, 0x45c3e0, 0, this=True)
    o = rnd(c, 0x100)
    e.w32(o + 8, rnd(c, 0x80))
    return [o]


S(0x45b460, 'GUESS: ZSTDOBJ-derived constructor (0x45b460)', 'thiscall', None, ret='eax', gen=_ctor, note='batch2479')
S(0x447920, 'GUESS: destructor body (0x447920; SEH frame not reproduced)', 'thiscall', None, ret=None, gen=_seh, note='batch2479: SEH frame not reproduced')
