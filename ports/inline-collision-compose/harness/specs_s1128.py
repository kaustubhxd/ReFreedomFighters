"""specs_s1128.py - collision thread batch 1128: ZCollisionBase::FreeSceneMemory (0x4ecaa0). The two sub-objects are
fake objects whose slot 0x28 logs its argument. The 0x14-byte block is a heap block; the CRT delete (0x634273) runs as
exe code. It is not exercised here (see the note in the gen function)."""
from pilot import S, F
from specs_s1110 import _vt


def _free(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x200, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
    def slot28(em, a):
        em.calllog.append(('sub28', a[0]))
        return 0, ()
    for off in (0x19d, 0x1a1):
        if r.random() < 0.8:
            o = e.alloc(0x20, 4)
            e.w32(o, _vt(c, 'sub', {0x28: (1, slot28)}, 0x2c // 4))
            e.w32(self_ + off, o)
        else:
            e.w32(self_ + off, 0)
    # +0x1a5 stays 0: the CRT delete (0x634273) cannot run on the harness heap (every run with a block faulted in
    # both builds: 234 of 300). That branch is therefore NOT verified; see docs/20-collision.md batch 1128.
    e.w32(self_ + 0x1a5, 0)
    return [self_]


S(0x4ecaa0, 'ZCollisionBase::FreeSceneMemory', 'thiscall', None, gen=_free, note='batch1128')
