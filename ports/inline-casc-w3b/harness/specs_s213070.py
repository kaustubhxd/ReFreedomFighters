"""specs_s213070.py - batch 213070: vector follow step with float helper results, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

T = struct.unpack('<f', struct.pack('<I', 0x3dcccccd))[0]


def g662c50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x60)
    a = rnd(c, 0x10)
    e.wbytes(this + 0x34, struct.pack('<f', r.choice([0.0, 1.0, -2.5, r.uniform(-100, 100), float('nan'), float('inf')])) if r.random() < 0.9 else bytes(4))
    d = r.choice([T, -T, 0.0, -0.0, 1.0, 0.1, 0.1000001, 0.0999999, T * 1.0000001, T * 0.9999999, r.uniform(-1, 1), r.uniform(0, 50),
                  float('nan'), float('inf'), -float('inf')])
    hook_rec(c, 0x4e0830, 0, pop=0, this=True, st0=d, side=lambda emu, k: emu.calllog.append(('edx', emu.reg('edx'))))
    hook_rec(c, 0x662cf0, 0, this=True)

    def side6(emu, k):
        if r.random() < 0.5:
            emu.w32(emu.arg32(0), r.choice([0x3f800000, 0, r.getrandbits(32), 0x7fc00000]))
    hook_rec(c, 0x6627c0, 1, this=True, deref={0: 1}, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32)]), side=side6)

    def side4(emu, k):
        emu.calllog.append(('edx', emu.reg('edx')))
        emu.calllog.append(('p', bytes(emu.rbytes(emu.reg('ecx'), 12))))
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', r.uniform(-9, 9), r.uniform(-9, 9), r.uniform(-9, 9)) if r.random() < 0.8 else bytes(12))
    hook_rec(c, 0x443ef0, 2, pop=8, this=True, side=side4)
    return [this, a]


S(0x662c50, 'vector_follow_step', 'thiscall', None, ret='al', gen=g662c50)
