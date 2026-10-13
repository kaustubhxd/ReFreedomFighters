"""specs_s2605.py - wider batch 2605. 0x53a9e0: this -> object whose slot 4 (thiscall, 1 arg, recorder) returns p. p is a valid block + 4 so the store lands in the heap,
or (30%) system+0x28 so that dst == system+0x40 and the copy is skipped. [0x70039c] is a random 0x200-byte object."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    blk = rnd(c, 0x80)
    p = (so + 0x28) if r.random() < 0.3 else (blk + 4)
    inner = obj(c, 0x40, {4: pystub(c, 1, this=True, ret=p)})
    me = rnd(c, 0x20)
    e.w32(me, inner)
    return [me]


S(0x53a9e0, 'GUESS FUN_0053a9e0 thiscall', 'thiscall', None, ret=None, gen=_gen, note='batch2605')
