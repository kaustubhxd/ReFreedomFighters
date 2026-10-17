"""specs_s213153.py - batch 213153: packed-record progress interpolation (SSE ints/floats, minss clamp, idiv remainder), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g4e7930(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', v))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    hook_rec(c, 0x4de7a0, 0, pop=0, this=True)

    def side89(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<3I', rb(), rb(), rb()))
    hook_rec(c, 0x4e89d0, 6, pop=0x18, this='mark', side=side89)

    def side87(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<3I', rb(), rb(), rb()))
    hook_rec(c, 0x4e87b0, 6, pop=0x18, this='mark', stackmark=(0,), side=side87)
    hook_rec(c, 0x4df1e0, 0, pop=0, this=True,
             side=lambda emu, k: emu.calllog.append(('df', bytes(emu.rbytes(emu.reg('edx'), 12)))))
    kk = r.choice([0, 1, 5, 0x100, 0xffffffff, rb() & 0xffff])
    T = obj(c, 0x20, {0x17c: pystub(c, 0, this=True, ret=kk)}, nslots=0x60)
    E = rnd(c, 0x100)
    w32u(E + 0x9b, T)
    e.w32(0x70039c, E)
    # P record
    P = rnd(c, 0x100)
    top = r.choice([0, 0x40000000, 0x80000000, 0xc0000000, 0x40000000, 0x80000000, 0xc0000000])
    w32u(P + 4, top | (rb() & 0x3fffffff))
    off = r.choice([0x10, 0x20, 0x28, 0x30])
    w32u(P + 8, off)
    base = P + (off if top else 8)
    cnt = r.choice([0, 1, 2, 5, 30, 100, 1000, 0xffffffff, 0x80000000])
    w32u(base, cnt)
    w32u(base + 4, r.choice([0, 1, 5, 100, 0xfffffff0, 1000]))
    w32u(base + 0xc, r.choice([1, 2, 5, 10, 100, 0, 0xfffffffe]))
    # this record
    this = rnd(c, 0x40)
    f0 = r.choice([0.0, 1.0, 2.0, -1.5, 0.5, 100.0, 3.25, 7.0, -4.0])
    delta = r.choice([0.0, 0.0, 1.0, 2.0, 5.0, -1.0, -3.0, 10.0, -7.5, 1.5])
    f1 = f32(f0 + delta)
    start = r.choice([0, 5, 100, 1000, -3])
    step = r.choice([0.0, 1.0, 2.0, 3.0, 10.0, 100.0, 2.5])
    mode = r.choice([0, 0, 0, 1, 2, 0xff])
    P_ = P if r.random() > 0.08 else 0
    e.wbytes(this, struct.pack('<i', start))
    wf(this + 4, step)
    e.wbytes(this + 8, bytes([mode]))
    w32u(this + 9, P_)
    wf(this + 0xd, f0)
    wf(this + 0x11, f1)
    t = start + r.choice([-5, -1, -1, 0, 1, 2, 3, 7, 50, 200, 1000, 5000])
    if r.random() < 0.4 and P_:
        # flag2 boundary: make edi land on f1 * 1024 (+-1) so the two comiss tests meet equality
        f1b = r.choice([1.0, 2.0, 3.0, 5.0, 10.0])
        f0b = f1b + r.choice([0.0, 0.0, 1.0, 2.0, -1.0, -3.0])
        delta2 = r.choice([0, 0, 0, 1, -1])
        Y = int(f1b * 1024)
        edi_t = Y + delta2
        flag_ = f0b > f1b
        rhs = (int(f0b * 1024) - edi_t) if flag_ else (edi_t + int(-1024 * f0b))
        if rhs >= 0:
            wf(this + 4, 1.0)
            e.wbytes(this + 8, bytes([0]))
            wf(this + 0xd, f0b)
            wf(this + 0x11, f1b)
            e.wbytes(this, struct.pack('<i', start))
            t = start + rhs
    vec = rnd(c, 0x30)
    out = rnd(c, 0x20)
    return [this, t & 0xffffffff, vec, out, 0]


S(0x4e7930, 'progress_interp', 'thiscall', None, ret='st0', gen=g4e7930, stack_arg_bytes=12)
