"""specs_s2460.py - decomp area 24, batch 2460 (gap band).
0x45b180 ZBoxPrimitive::CopyData(const ZGEOM*), thiscall, ret 4: ZGEOM::CopyData (0x45d5b0, recorder), dwords +0x18, +0x1c,
+0x20 copied from the argument, then slot 0xb4 of this with 1 (recorder).
0x454870 ZInstance::CopyData(const ZGEOM*), thiscall, ret 4: ZGROUP::CopyData (0x43f8c0, recorder); slot 0x1e0 of the
ARGUMENT with 0x1000ea (recorder, returns a random dword); when AL is set, +0x5c is copied from the argument to this.
0x44d320 ZBoneParticle::OwnerDraw(7 dwords), thiscall, ret 28: FindParticles (0x44d200, recorder, geom and flag), and unless it
returns -1, slot 0x214 of this with (index, geom, the 4th to 6th arguments) (recorder, six arguments)."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _box(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45d5b0, 1, this=True)
    o = obj(c, 0x100, {0xb4: pystub(c, 1)})
    return [o, rnd(c, 0x40)]


def _inst(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43f8c0, 1, this=True)
    src = obj(c, 0x100, {0x1e0: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32))})
    return [rnd(c, 0x100), src]


def _owner(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x44d200, 2, this=True, ret=lambda emu, k: r.choice([0xffffffff, r.randint(0, 9)]))
    o = obj(c, 0x100, {0x214: pystub(c, 6)})
    return [o] + [r.getrandbits(32) for _ in range(7)]


S(0x45b180, 'ZBoxPrimitive::CopyData', 'thiscall', None, ret=None, gen=_box, note='batch2460')
S(0x454870, 'ZInstance::CopyData', 'thiscall', None, ret=None, gen=_inst, note='batch2460')
S(0x44d320, 'ZBoneParticle::OwnerDraw', 'thiscall', None, ret=None, gen=_owner, note='batch2460')
