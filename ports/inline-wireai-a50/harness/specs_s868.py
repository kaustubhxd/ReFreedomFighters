"""specs_s868.py - area 50, batch 868: three small setters (thiscall).
0x47bed0 SetMoveSet(p): p is a pointer to a dword index. 0x5a2c50 SetCloseCombatEnable(on): one byte. 0x47bd90 SetEndDir(v):
v is a pointer to three floats, or null; 0x44c840 (exe, a float result that is dropped) runs as is on the object. The object
gets a vtable-free block of 0x800 bytes; the index for SetMoveSet is kept small."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen_movset(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    self = rnd(c, 0x800)
    p = rnd(c, 16)
    e.w32(p, r.randint(0, 40))
    return [self, p]


def _gen_cc(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    self = rnd(c, 0x800)
    return [self, r.choice([0, 1, 2, 0x100, 0x01])]


def _gen_dir(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    self = rnd(c, 0x800)
    for off in range(0, 0x20, 4):
        e.wf32(self + 0x20 + off, r.uniform(-2, 2))
    v = rnd(c, 16)
    for i in range(3):
        e.wf32(v + 4 * i, r.uniform(-2, 2))
    return [self, v if r.random() < 0.85 else 0]


S(0x47bed0, 'ZActor::SetMoveSet (GUESS table index)', 'thiscall', None, gen=_gen_movset, note='area50 batch868')
S(0x5a2c50, 'ZFFActor::SetCloseCombatEnable', 'thiscall', None, gen=_gen_cc, note='area50 batch868')
S(0x47bd90, 'ZActor::SetEndDir', 'thiscall', None, gen=_gen_dir, note='area50 batch868')
