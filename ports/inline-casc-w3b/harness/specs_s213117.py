"""specs_s213117.py - batch 213117: stream loader with version-dependent reads, scaled vectors, saturating allocations and slot setup, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g4585b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def fv():
        return f32(r.choice([0.0, -0.0, 1.0, -1.0, 2.0, 0.5, 4.0, NAN, r.uniform(-5, 5)]))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    this = rnd(c, 0x380)
    stream = rnd(c, 0x20)
    e.wbytes(this + 0x18, struct.pack('<f', r.choice([0.0, -0.0, 1.0, NAN, r.uniform(-3, 3)])))
    dvals = [0, 1, 0x5555555, 0x5555556, 0x0fffffff, 0x10000000, 0x7fffffff, 0xffffffff, r.getrandbits(32), 5]
    pbuf1 = rnd(c, 0x20)
    pbuf2 = rnd(c, 0x20)

    def reader(emu, k):
        dst, cnt = emu.arg32(0), emu.arg32(1)
        if dst == this + 0x34 and cnt == 1:
            emu.w32(dst, r.choice(dvals))
        elif dst in (this + 0x28, this + 0x44, this + 0x50) and cnt == 3:
            emu.wbytes(dst, struct.pack('<fff', fv(), fv(), fv()))
        elif dst == this + 0x18 or dst in (this + 0x38, this + 0x3c) or cnt == 1:
            emu.wbytes(dst, struct.pack('<f', fv()))
        else:
            emu.wbytes(dst, bytes(r.getrandbits(8) for _ in range(4 * cnt)))
    hook_rec(c, 0x4e12f0, 2, pop=8, this=True, stackmark=(0,), side=reader)
    hook_rec(c, 0x4e12e0, 2, pop=8, this=True, stackmark=(0,), side=reader)

    def s1440(emu, k):
        emu.w32(emu.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x4e1440, 1, pop=4, this=True, stackmark=(0,), side=s1440)
    hook_rec(c, 0x4e1600, 0, pop=0, this=True, ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | r.choice([1, 2, 3, 3, 4, 0xff]))
    hook_rec(c, 0x4e1b30, 0, pop=0, this=True)
    hook_rec(c, 0x610100, 1, pop=4, this=True)

    def s0980(emu, k):
        lg(emu, 'a0980', emu.reg('ecx'), 12)
        lg(emu, 'b0980', emu.reg('edx'), 12)
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', fv(), fv(), fv()))
    hook_rec(c, 0x4e0980, 0, pop=0, this=True, side=s0980)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda emu, k: pbuf1 if k == 0 else pbuf2)

    def smem(emu, k):
        emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)))
    hook_rec(c, 0x634d10, 3, pop=0, side=smem)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, stream]


S(0x4585b0, 'stream_loader', 'thiscall', None, ret=None, gen=g4585b0)
