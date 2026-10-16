"""specs_s213023.py - batch 213023: pending action finisher with stack locals and a /GS check, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g47b7a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill57c(emu, k):
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(0x24)))
        emu.wbytes(emu.arg32(1), struct.pack('<fff', r.uniform(-9, 9), r.uniform(-9, 9), r.uniform(-9, 9)))

    def fill620(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<fff', r.uniform(-9, 9), r.uniform(-9, 9), r.uniform(-9, 9)))

    slots = {
        0x640: pystub(c, 1, ret=r.getrandbits(32), this=True),
        0x644: pystub(c, 1, ret=r.getrandbits(32), this=True),
        0x648: pystub(c, 1, ret=r.getrandbits(32), this=True),
        0x64c: pystub(c, 1, ret=r.getrandbits(32), this=True),
        0x57c: pystub(c, 2, ret=r.getrandbits(32), this=True, nullflag=(0, 1), side=fill57c),
        0x620: pystub(c, 3, ret=r.getrandbits(32), this=True, deref={0: -12}, side=fill620),
        0x578: pystub(c, 2, ret=r.getrandbits(32), this=True, deref={0: -36, 1: -12}),
    }
    this = obj(c, 0x740, slots, nslots=0x19a)
    pend = r.choice([0, 1, 2, 3, 4, 5, r.getrandbits(32), 1, 2, 3, 4])
    e.wbytes(this + 0x727, struct.pack('<I', pend))
    e.wbytes(this + 0x695, struct.pack('<I', r.choice([0, 0, 1, r.getrandbits(32)])))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    flag = r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)])
    return [this, flag]


S(0x47b7a0, 'finish_pending_action', 'thiscall', None, ret=None, gen=g47b7a0)
