"""specs_s1692.py - residue 13 batch 1692: 0x464460 (flag byte; the manager's slots 0x114, 0x138, 0x4c, the camera's slot 0x88
and the object's slot 0x12c are recorders). Only al is compared (the flag path returns the flag)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    cam = obj(c, 0x40, {0x88: stub(c, seq, 2, skip=(1,))})   # arg 1 is a stack buffer
    mgr = obj(c, 0x100, {0x114: stub(c, seq, 4, ret=r.getrandbits(32)),
                         0x138: stub(c, seq, 0, ret=cam),
                         0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=mgr)
    me = obj(c, 0x100, {0x12c: stub(c, seq, 3, ret=r.getrandbits(32))})
    flag = r.choice([0, 0, 1, 0x80, 0x100, r.getrandbits(32)])
    return [me, flag]


S(0x464460, 'GUESS FUN_464460', 'thiscall', None, ret='al', gen=_gen, note='batch1692; flag byte; manager and camera recorders')
