"""specs_s213087.py - batch 213087: target-follow step with stack vectors and nine helpers, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g518960(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    c0 = struct.unpack('<f', bytes(e.rbytes(0x69f1a0, 4)))[0]
    c1 = struct.unpack('<f', bytes(e.rbytes(0x69f1a8, 4)))[0]

    def fl():
        return r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 2.0, 100.0, c0, c1, NAN, r.uniform(-5, 5), r.uniform(-0.8, 0.8), r.uniform(-0.8, 0.8), r.uniform(0, 1)])

    def vec3():
        return struct.pack('<fff', fl(), fl(), fl())
    P = rnd(c, 0x60)
    e.wbytes(P + 8, vec3())
    e.wbytes(P + 0x24, struct.pack('<ff', fl(), fl()))
    e.wbytes(P + 0x39, struct.pack('<I', r.choice([0, 0, 1, r.getrandbits(32)])))
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)

    def d_side(emu, k):
        emu.calllog.append(('de', bytes(emu.rbytes(emu.arg32(0), 12)), bytes(emu.rbytes(emu.arg32(1), 12))))
        if r.random() < 0.5:
            emu.wbytes(emu.arg32(1), vec3())
    this = obj(c, 0x1700, {0x7c: sl(2, nullflag=(0, 1), side=d_side)}, nslots=0x60)
    e.w32(this + 0x5c, P)
    e.wbytes(this + 0x15fb, struct.pack('<f', fl()))
    e.wbytes(this + 0x15ff, struct.pack('<f', fl()))
    e.wbytes(this + 0x15eb, vec3())
    e.w32(this + 0x1650, r.choice([0, 1, 0, 1, 0, 1]))
    e.wbytes(this + 0x1614, bytes([r.choice([0, 1, 1, 0xff])]))
    e.wbytes(this + 0x60, vec3())
    hook_rec(c, 0x451890, 1, pop=4, nullflag=(), side=lambda emu, k: (emu.calllog.append(('a', bytes(emu.rbytes(emu.reg('ecx'), 12)), emu.reg('edx'))), emu.wbytes(emu.reg('ecx'), vec3())) and None)

    def bc_side(emu, k):
        emu.calllog.append(('abc', bytes(emu.rbytes(emu.arg32(0), 12))))
        emu.wbytes(emu.arg32(1), vec3())   # C
        emu.wbytes(emu.arg32(2), vec3())   # B
        if r.random() < 0.5:
            emu.wbytes(emu.arg32(0), vec3())
    hook_rec(c, 0x518380, 4, this=True, nullflag=(0, 1, 2), side=bc_side)
    hook_rec(c, 0x518190, 4, this=True, nullflag=(0, 1, 2), side=bc_side)

    def e_side(emu, k):
        emu.calllog.append(('c', bytes(emu.rbytes(emu.arg32(2), 12))))
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(24)))
        emu.wbytes(emu.arg32(1), vec3())
    hook_rec(c, 0x5251c0, 8, this=True, nullflag=(0, 1, 2), side=e_side)

    def e2_side(emu, k):
        emu.calllog.append(('edx', emu.reg('edx')))
        emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(24)))
    hook_rec(c, 0x4de040, 1, pop=4, side=e2_side)

    def f5172(emu, k):
        emu.calllog.append(('e', bytes(emu.rbytes(emu.arg32(2), 24)), bytes(emu.rbytes(emu.arg32(3), 12))))
    hook_rec(c, 0x5172e0, 4, this=True, nullflag=(2, 3), side=f5172)

    def f4de420(emu, k):
        emu.calllog.append(('e2', bytes(emu.rbytes(emu.reg('edx'), 24))))
    hook_rec(c, 0x4de420, 0, pop=0, this=True, side=f4de420)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x518960, 'follow_target_step', 'thiscall', None, ret=None, gen=g518960)
