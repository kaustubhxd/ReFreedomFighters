"""specs_s2431.py - decomp area 24, batch 2431: ZDamageBox::~ZDamageBox(unsigned char) (0x5daff0), thiscall, ret 4.
SEH frame not reproduced: the original installs an exception frame on fs:[0]; the port does not.
The body call (0x5daf20, thiscall, plain ret) and the render state call (0x4690b0, cdecl, two arguments) are recorders.
The global function pointer at 0x7003b0 is set to a recorder (cdecl, no arguments) so the int3 path never runs.
The flag bits: bit 0 gates the whole delete step; bit 2 picks the render-state call, else the global pointer."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self_ = obj(c, 0x200, {})
    hook_rec(c, 0x5daf20, 0, this=True)
    hook_rec(c, 0x4690b0, 2, pop=0)
    e.w32(0x7003b0, pystub(c, 0, pop=0))
    return [self_, r.randint(0, 7)]


S(0x5daff0, 'ZDamageBox::~ZDamageBox (SEH frame not reproduced)', 'thiscall', None, ret='eax', gen=_gen,
  note='batch2431: SEH frame not reproduced')
