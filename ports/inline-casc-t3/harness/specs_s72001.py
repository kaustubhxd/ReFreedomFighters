"""specs_s72001.py - Haiku t3 batch 72001. 0x43e740: conditional float vector length calc with hooked callees."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
from pe_emu import F


def g43e740(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Create self object
    me = rnd(c, 0x100)

    # Set up the flag [self + 0x18] & 4 (50/50 chance)
    flag = r.choice([0, 4])
    e.wbytes(me + 0x18, bytes([flag]))

    # Setup [self + 0x34] and [self + 0x38] as output fields
    e.wf32(me + 0x34, r.uniform(-1000, 1000))
    e.wbytes(me + 0x38, struct.pack('<I', r.getrandbits(32)))

    # Hook the callees
    hook_rec(c, 0x43e920, 2, this=True, pop=0)  # thiscall(self, edx=?, ecx=?)
    hook_rec(c, 0x4de040, 2, this=True, pop=0)
    hook_rec(c, 0x43e8e0, 2, this=True, pop=0)
    hook_rec(c, 0x4e0d00, 1, this=True, pop=0)
    hook_rec(c, 0x4690b0, 1, this=True, pop=0)  # 1 byte thunk

    # Setup vtable for self
    vt = rnd(c, 0x100)
    e.wbytes(me, struct.pack('<I', vt))
    hook_rec(c, vt + 0x74, 2, ret=None, pop=8, this=True)

    # Setup [self + 8]
    e.wbytes(me + 8, struct.pack('<I', r.getrandbits(32)))

    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x43e740, 'GUESS conditional vector length calc', 'thiscall', None, ret=None, gen=g43e740, note='batch72001')
