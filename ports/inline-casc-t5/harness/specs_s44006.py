"""specs_s44006.py - t5 (Sonnet) batch 44006: 0x5e0410."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g5e0410(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4614d0, 3, this=True, pop=0xc, ret=r.getrandbits(32))
    hook_rec(c, 0x466f60, 1, this=True, pop=4, ret=r.getrandbits(32))
    rv = r.choice([r.uniform(0, 1), r.uniform(0, 100), 0.0, 1.0, r.uniform(-5, 5)])
    tgt = rnd(c, 0x90)
    t = r.choice([tgt, tgt, 0])
    so = sysobj(c, rand=rv, table_slots={0x60: pystub(c, 1, this=True, ret=t)})
    sub = obj(c, 0x20, {0x60: pystub(c, 1, this=True, ret=r.getrandbits(32))}, nslots=0x64 // 4)
    e.wbytes(so + 0x1a9f, struct.pack('<I', sub))
    holder = obj(c, 0x20, {0x228: pystub(c, 5, this=True, ret=r.getrandbits(32)),
                           0x578: pystub(c, 1, this=True, ret=r.getrandbits(32))}, nslots=0x57c // 4)
    me = rnd(c, 0x20)
    e.w32(me + 8, holder)
    return [me]


S(0x5e0410, 'GUESS init effect and set state', 'thiscall', None, ret='al', gen=g5e0410, nan_heap=True, note='batch44006')
