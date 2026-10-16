"""specs_s213074.py - batch 213074: record reader loading an object, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

NAN = float('nan')


def g4a7380(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    if r.random() < 0.1:
        B = rnd(c, 0x700)
        this = B + 0x100
        eng = this + 0xf6 - 0x40
        for off in range(0, 0x200, 4):
            e.w32(this + off, r.getrandbits(32))
    else:
        this = rnd(c, 0x180)
        eng = rnd(c, 0x80)
    e.w32(0x70039c, eng) if False else None
    e.w32(0x70039c, eng)
    e.w32(eng + 0x40, r.getrandbits(32))
    objb = rnd(c, 0x20)
    inner = rnd(c, 0x20)
    e.w32(this + 0x44, objb)
    e.w32(objb + 8, inner)
    pool = []
    for _ in range(5):
        p = rnd(c, 8)
        e.wbytes(p, bytes([r.choice([0xff, 0x03, 0x43, 0x83, 0x0b, 0x4b, 0xcb, 0x2b, r.getrandbits(8)])]))
        pool.append(p)
    rd = rnd(c, 0x10)
    e.w32(rd, 0 if r.random() < 0.15 else r.choice(pool))

    def fl(emu, k):
        return r.choice([0.0, 0.5, 1.0, 1.0, 1.5, 2.0, 1e30, -1.0, NAN, float('inf'), r.uniform(-5, 5)])

    def ival(emu, k):
        return r.choice([0, 0, 1, 2, 0x100, 0xff, 0xffffff00, r.getrandbits(32)])

    def side_i(emu, k):
        if r.random() < 0.35:
            emu.w32(rd, r.choice(pool))
    R1 = hook_rec(c, 0x4e5e80, 0, this=True, st0=fl)
    R2 = hook_rec(c, 0x4e5e60, 0, this=True, ret=ival, side=side_i)
    import os
    if os.environ.get('DBGS'): print('ADDR this', hex(this), 'eng', hex(eng), 'rd', hex(rd), 'R1', hex(R1), 'R2', hex(R2), flush=True)

    def side_v(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<fff', *[fl(emu, 0) for _ in range(3)]))
    hook_rec(c, 0x4e6180, 1, this=True, side=side_v)

    def side_q(emu, k):
        emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(12)))
    hook_rec(c, 0x4e0a10, 0, this='mark', side=side_q)

    def side_q2(emu, k):
        emu.calllog.append(('q', bytes(emu.rbytes(emu.reg('ecx'), 12))))
    hook_rec(c, 0x4e0d00, 1, this='mark', side=side_q2)

    def side_f(emu, k):
        emu.calllog.append(('q', bytes(emu.rbytes(emu.reg('edx'), 12))))
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', *[fl(emu, 0) for _ in range(3)]))
    hook_rec(c, 0x4e0be0, 0, pop=0, this=True, side=side_f)
    hook_rec(c, 0x4db2c0, 2, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, r.getrandbits(32), rd]


S(0x4a7380, 'load_object_record', 'thiscall', None, ret=None, gen=g4a7380)
