"""specs_s38031.py - cascade s8 batch 38031. Device object (unaligned pointer at this+0x1377) with logging stdcall slots (every call is logged in order, the generic recorder keeps only 8 rows) 0xc8 (3 args), 0xf4 (3), 0xfc (4), 0x14c (4), 0x154 (3), 0x130 (2),
0x160 (2); the global state tables (0x724848.., 0x724928.., 0x7249b0..) get random dwords, the stage count 0x724a08 is 0..6 (so the zero-stage skip and the loop both run), 0x72494c is zero half of the time."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g610ba0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for a in range(0x724848, 0x724a00, 4):
        e.w32(a, r.getrandbits(32))
    e.w32(0x724a08, r.choice([0, 1, 2, 3, 6]))
    if r.random() < 0.5:
        e.w32(0x72494c, 0)
    def slot(name, n):
        def h(em, res_):
            em.calllog.append((name,) + tuple(em.arg32(i) for i in range(n)))
            em.ret(eax=0, argbytes=4 * n)
        return e.stub_fn(name, h)
    dev = obj(c, 0x40, {0xc8: slot('c8', 3), 0xf4: slot('f4', 3), 0xfc: slot('fc', 4), 0x14c: slot('14c', 4), 0x154: slot('154', 3),
                        0x130: slot('130', 2), 0x160: slot('160', 2)})
    me = rnd(c, 0x1400)
    e.wbytes(me + 0x1377, struct.pack('<I', dev))
    return [me]


S(0x610ba0, 'GUESS push cached render state to device', 'thiscall', None, ret=None, gen=_g610ba0, note='batch38031')
