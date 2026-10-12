"""specs_s2446.py - decomp area 24, batch 2446 (gap band).
0x452f80 (GUESS owner), thiscall, plain ret: the vtable is set to 0x681b24; the object at +0x52 (when set) gets slot 0 with
argument 1 (recorder); then the tail jump to 0x43de70 (recorder, no arguments) on this.
0x45c4f0 (GUESS, unnamed), cdecl, plain ret: the child at ([sys+0x9b]+8) gets slot 0x10 with (first argument, second
argument); the child is a recorder, two arguments, popped by the child (thiscall ret 8)."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, hook_rec, clear_hooks


def _vt(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x43de70, 0, this=True)
    o = rnd(c, 0x80)
    if r.random() < 0.7:
        child = obj(c, 0x40, {0: pystub(c, 1, pop=4)})
        e.w32(o + 0x52, child)
    else:
        e.w32(o + 0x52, 0)
    return [o]


def _fwd(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    tabobj = e.r32(so + 0x9b)
    inner = obj(c, 0x40, {0x10: pystub(c, 2)})
    e.w32(tabobj + 8, inner)
    return [r.getrandbits(32), r.getrandbits(32)]


S(0x452f80, 'GUESS: vtable set and tail jump 0x43de70 (0x452f80)', 'thiscall', None, ret=None, gen=_vt, note='batch2446')
S(0x45c4f0, 'GUESS: cdecl forwarder to sys child slot 0x10 (0x45c4f0)', 'cdecl', None, ret=None, gen=_fwd, note='batch2446')
