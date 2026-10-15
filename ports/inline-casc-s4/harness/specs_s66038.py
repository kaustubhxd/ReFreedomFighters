"""specs_s66038.py - cascade s4 batch 66038: 0x4ce2d0 (bump the generation counter of a masked slot)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, logger


def _g4ce2d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    so = sysobj(c)
    e.wbytes(so + 0x9b7, bytes([r.choice([0, 1, 1])]))
    e._image_dirty = True
    mask = r.choice([0x0f, 0x07, 0xff, 0x3])
    a = r.choice([0, 1, 2, 3, 5, 0xf, 0x10, 0x11, 0x1f, 0xffff0003, mask, mask + 1, 0x7f])
    arr = e.alloc(4 * 0x100 + 4, 4)
    for i in range(0x100):
        e.w32(arr + 4 * i, r.getrandbits(32))
    o = obj(c, 0x20, {4: pystub(c, 1, this=True)})
    t = obj(c, 0x30, {0x14: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 0x101])), 0x18: pystub(c, 1, this=True)})
    e.w32(t + 4, arr)
    e.w32(t + 8, o)
    e.w32(t + 0x10, mask)
    e.w32(t + 0x14, r.choice([0, 1, 4, 8, 31, 32, 33]))
    e.wbytes(t + 0x18, bytes([r.choice([0, 1])]))
    return [t, a]


S(0x4ce2d0, 'GUESS bump the generation counter of a masked slot', 'thiscall', None, ret='al', gen=_g4ce2d0, note='batch66038')
