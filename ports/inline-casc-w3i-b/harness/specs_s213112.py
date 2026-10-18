"""specs_s213112.py - batch 213112: two clamped sample vectors, normalised, compared by an x87 helper, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g523f50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    thr = struct.unpack('<f', bytes(e.rbytes(0x69f1a0, 4)))[0]

    def fv():
        return f32(r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 2.0, 3.0, 1e-20, r.uniform(-5, 5), r.uniform(-1, 1)]))

    def vec3():
        return struct.pack('<fff', fv(), fv(), fv())

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    this = rnd(c, 0x80)
    f04 = f32(r.choice([-1.0, -0.5, 0.0, -0.0, -0.0, 0.25, 0.5, 1.0, 1.5, 2.0, NAN, r.uniform(-2, 2)]))
    simple = r.random() < 0.5
    f63, f24, f20, f53 = (1.0, 1.0, 1.0, 1.0) if simple else (fv(), fv(), fv(), f32(r.choice([0.0, 1.0, 2.0, -1.0, r.uniform(0.1, 3)])))
    for off, v in ((0x63, f63), (0x24, f24), (0x20, f20), (0x53, f53), (4, f04)):
        e.wbytes(this + off, struct.pack('<f', v))

    def s88(emu, k):
        lg(emu, 'v88', emu.arg32(0), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.arg32(0), vec3())
    O = obj(c, 0x40, {0x88: pystub(c, 1, this=True, nullflag=(0,), side=s88)}, nslots=0x60)
    e.w32(this + 0x4b, 0 if r.random() < 0.15 else O)

    def s0b60(emu, k):
        emu.wbytes(emu.arg32(0), vec3() if r.random() < 0.8 else struct.pack('<fff', 0.0, 0.0, 0.0))
    hook_rec(c, 0x460b60, 2, pop=8, this=True, nullflag=(0,), side=s0b60)

    def sd00(emu, k):
        lg(emu, 'cd00', emu.reg('ecx'), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x4e0d00, 1, pop=4, this='mark', side=sd00)

    def s0030(emu, k):
        lg(emu, 'a0030', emu.reg('ecx'), 12)
        lg(emu, 'b0030', emu.reg('edx'), 12)
        return None

    def st0v(emu, k):
        return f32(r.choice([thr, thr, f32(thr * 1.0001), f32(thr * 0.9999), 0.0, 1.0, -1.0, NAN, r.uniform(-2, 2)]))
    hook_rec(c, 0x4e0030, 0, pop=0, side=s0030, st0=st0v)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x523f50, 'two_sample_compare', 'thiscall', None, ret='eax', gen=g523f50)
