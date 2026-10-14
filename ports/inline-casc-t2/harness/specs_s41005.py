"""specs_s41005.py - t2 () batch 41005: 0x565760. Slots are recorders (engine slot 0xc takes four float args)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g565760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4)
    a = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=t if r.random() < 0.9 else 0)}, nslots=0x260 // 4)
    so = sysobj(c, slots={0xc: pystub(c, 4, this=True)})
    dim = lambda: r.choice([r.randrange(1, 4000), 640, 480, 0x1c0, 0x280, 1, 1920, 1080, r.getrandbits(32), 0, 0xffffffff, 0x1bf, 0x1c1, 0x27f, 0x281, r.randrange(1, 100)])
    e.w32(so + 0x6f, dim())
    e.w32(so + 0x73, dim())
    me = rnd(c, 0xd00)
    e.wbytes(me + 0xc7e, (a if r.random() < 0.9 else 0).to_bytes(4, 'little'))
    return [me, r.choice([0, 1, 0x100, 0xff, r.getrandbits(32), 1])]


S(0x565760, 'GUESS set viewport rectangle', 'thiscall', None, ret=None, gen=g565760, nan_heap=True, note='batch41005')
