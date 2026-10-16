"""specs_s213100.py - batch 213100: message handler with timer, vector-limit test and four message codes, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')
INF = float('inf')


def f32(x):
    try:
        return struct.unpack('<f', struct.pack('<f', x))[0]
    except OverflowError:
        return x


def g5153e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s16 = lambda: r.getrandbits(16)
    # engine
    t = r.choice([r.randrange(-1000000, 1000000), 0, 1000, -1000, 0x7ffffff0, -0x7ffffff0, r.randrange(-100000, 100000)])
    eng = rnd(c, 0x100)
    e.w32(eng + 0x40, t & 0xffffffff)
    e.w32(0x70039c, eng)
    this = obj(c, 0x300, {}, nslots=0x100)   # vtable allocated below (slots filled after the stubs exist)
    # message codes
    codes = [s16() for _ in range(4)]   # 0x2ca, 0x2cc, 0x207, 0x2d0
    if r.random() < 0.15:
        codes[r.randrange(4)] = codes[r.randrange(4)]
    for off, v in zip((0x2ca, 0x2cc, 0x207, 0x2d0), codes):
        e.wbytes(this + off, struct.pack('<H', v))
    w = r.random()
    pick = 0 if w < 0.4 else 1 if w < 0.5 else 2 if w < 0.62 else 3 if w < 0.75 else None
    low = codes[pick] if pick is not None else s16()
    arg0 = (r.getrandbits(16) << 16) | low
    # this[0x5c] object: byte +0x46, float +0x47
    objB = rnd(c, 0x60)
    e.wbytes(objB + 0x46, bytes([0 if r.random() < 0.3 else r.choice([1, 2, 0xff])]))
    delta = r.choice([7167, 7168, 7169, 7168 + r.randrange(-3, 4), 0, -5000, 20000, r.randrange(-30000, 30000)])
    mode = r.random()
    if mode < 0.06:
        fval = NAN
    elif mode < 0.1:
        fval = 1e30
    elif mode < 0.14:
        fval = -1e30
    else:
        fval = f32((t - delta) / 1024.0) if abs(t - delta) < (1 << 24) else 0.0
    e.wbytes(objB + 0x47, struct.pack('<f', fval))
    e.w32(this + 0x5c, objB)
    e.w32(this + 0x2c4, r.choice([t, t + 1, t - 1, t + 0x800, r.randrange(-1000000, 1000000), 0x7fffffff, -0x80000000, t - 0x800]) & 0xffffffff)
    e.w32(this + 0x233, r.getrandbits(32))
    e.wbytes(this + 0x2c3, bytes([0 if r.random() < 0.5 else 1]))
    lims = [r.choice([0.0, 0.5, 1.0, 2.0, 10.0, NAN]) for _ in range(3)]
    for off, v in zip((0x21b, 0x22b, 0x223), lims):
        e.wbytes(this + off, struct.pack('<f', v))

    def vals():
        out = []
        for lim in lims:
            lm = lim if lim == lim else 1.0
            out.append(f32(r.choice([0.0, lm, -lm, lm * 2, -lm * 2, lm * 0.5, -lm * 0.5, NAN, INF, -INF, r.uniform(-3, 3)])))
        return struct.pack('<fff', *out)

    def x84_side(emu, k):
        v = emu.arg32(0)
        emu.calllog.append(('x84', bytes(emu.rbytes(v, 12))))
        emu.wbytes(v, vals())

    def s8c_side(emu, k):
        v = emu.arg32(0)
        emu.calllog.append(('s8c', bytes(emu.rbytes(v, 12))))
        if r.random() < 0.5:
            emu.wbytes(v, vals())
    X = [obj(c, 0x20, {0x84: pystub(c, 1, this=True, nullflag=(0,), side=x84_side)}, nslots=0x40) for _ in range(2)]

    def t58_ret(emu, k):
        rr = r.random()
        if rr < 0.2:
            return 0
        if rr < 0.4:
            return this
        return r.choice(X)
    T = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=t58_ret)}, nslots=0x40)
    e.w32(eng + 0x9b, T)
    # this vtable slots
    vtp = e.r32(this)
    e.w32(vtp + 0x84, pystub(c, 1, this=True, nullflag=(0,), side=x84_side))
    e.w32(vtp + 0x8c, pystub(c, 1, this=True, nullflag=(0,), side=s8c_side))
    e.w32(vtp + 0x368, pystub(c, 1, this=True, ret=lambda emu, k: r.getrandbits(32)))
    p = rnd(c, 0x10)
    zc = r.random()
    z = -1.0 if zc < 0.4 else NAN if zc < 0.5 else 0.0 if zc < 0.6 else f32(r.uniform(-3, 3))
    e.wbytes(p + 4, struct.pack('<f', f32(r.uniform(-5, 5))))
    e.wbytes(p + 8, struct.pack('<f', z))
    hook_rec(c, 0x5122f0, 2, pop=8, this=True, ret=lambda emu, k: r.getrandbits(32))
    hook_rec(c, 0x523ec0, 1, pop=4, this=True)
    hook_rec(c, 0x523180, 0, pop=0, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, arg0, p]


S(0x5153e0, 'timer_vector_message', 'thiscall', None, ret='eax', gen=g5153e0)
