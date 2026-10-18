"""specs_s213109.py - batch 213109: box extent vectors with a normalised x87 direction, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g5c9910(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def fv():
        return f32(r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 2.0, 3.0, 1e-20, 1e20, r.uniform(-5, 5), r.uniform(-5, 5), r.uniform(-1, 1)]))

    def vec3(zero=False):
        if zero:
            return struct.pack('<fff', *[r.choice([0.0, -0.0]) for _ in range(3)])
        return struct.pack('<fff', fv(), fv(), fv())

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    this = rnd(c, 0x460)
    e.wbytes(this + 0x2fa, struct.pack('<f', fv() if r.random() < 0.9 else NAN))
    e.wbytes(this + 0x30c, vec3())
    e.wbytes(this + 0x444, vec3())

    def s88(emu, k):
        lg(emu, 'v88', emu.arg32(0), 12)
    O = obj(c, 0x20, {0x88: pystub(c, 1, this=True, side=s88)}, nslots=0x40)
    e.w32(this + 0x44, O)

    def s1940(emu, k):
        lg(emu, 'a1940', emu.reg('ecx'), 12)
        lg(emu, 'b1940', emu.reg('edx'), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x441940, 0, pop=0, this=True, side=s1940)

    def s3e920(emu, k):
        lg(emu, 'b3e920', emu.reg('edx'), 12)
        lg(emu, 'c3e920', emu.arg32(0), 12)
        m = r.random()
        if m < 0.2:
            emu.wbytes(emu.reg('ecx'), vec3(zero=True))
        elif m < 0.3:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', 0.0, 0.0, fv()))
        elif m < 0.4:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', 0.0, fv(), 0.0))
        elif m < 0.45:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', NAN, 0.0, 0.0))
        else:
            emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x43e920, 1, pop=4, this=True, side=s3e920)

    def sd00(emu, k):
        lg(emu, 'cd00', emu.reg('ecx'), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x4e0d00, 1, pop=4, this=True, side=sd00)

    def s1890(emu, k):
        lg(emu, 'c1890', emu.reg('ecx'), 12)
    hook_rec(c, 0x451890, 1, pop=4, this=True, side=s1890)
    return [this]


S(0x5c9910, 'box_extents_dir', 'thiscall', None, ret=None, gen=g5c9910)
