"""specs_s66041.py - cascade s4 batch 66041: 0x55fe40 (bind two typed slots from the global state and set the third)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, logger


def _g55fe40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    box = {}

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        if box.get('swap'):
            e2.w32(box['h'] + 0x2c21, box['g2'])
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    g = e.alloc(0x80, 8)
    e.wbytes(g, bytes(r.getrandbits(8) for _ in range(0x80)))
    e.wbytes(g + 0x58, bytes([r.choice([0, 0, 1]), r.choice([0, 0, 3])]))
    holder = e.alloc(0x2c40, 8)
    e.w32(holder + 0x2c21, g)
    e.w32(0x7003b8, holder)
    g2 = e.alloc(0x80, 8)
    e.wbytes(g2, bytes(r.getrandbits(8) for _ in range(0x80)))
    e.wbytes(g2 + 0x58, bytes([r.choice([0, 1]), r.choice([0, 3])]))
    box.update({'h': holder, 'g2': g2, 'swap': r.random() < 0.5})
    e._image_dirty = True
    recs = []
    for _ in range(3):
        rec = e.alloc(0x10, 8)
        e.wbytes(rec + 4, bytes([r.choice([0, 2, 2, 0, 1, 3, 4, 0xff])]))
        e.w32(rec, r.getrandbits(32))
        recs.append(rec)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: recs[min(k, 2)])
    hook_rec(c, 0x5002f0, 1, this=True)
    p = rnd(c, 0x20)
    e.w32(p + 8, rnd(c, 8))
    return [p]


S(0x55fe40, 'GUESS bind two typed slots and set the third', 'stdcall', None, ret=None, gen=_g55fe40, note='batch66041')
