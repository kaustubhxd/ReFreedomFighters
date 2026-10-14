"""specs_s34146.py - this slots 0x30 (returns a big block, null in a fifth) and 0x28 (returns n in 1..5, ret 0 args); byte at +0x10; list head at +8 (0 in a third, else a node whose +0xc points to a node with +8)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x400)
    ret_blk = 0 if r.random() < 0.2 else blk
    n = r.choice([1, 2, 3, 4, 5])
    me = obj(c, 0x20, {0x30: pystub(c, 0, this=True, ret=ret_blk), 0x28: pystub(c, 0, this=True, ret=n)}, nslots=0x34 // 4)
    e.wbytes(me + 0x10, bytes([r.getrandbits(8)]))
    if r.random() < 0.65:
        tail = rnd(c, 0x20)
        head = rnd(c, 0x20)
        e.w32(head + 0xc, tail)
        e.w32(me + 8, head)
    else:
        e.w32(me + 8, 0)
    return [me]


S(0x615650, 'GUESS pool block link D', 'thiscall', None, ret='al', gen=_g, note='batch34146')
