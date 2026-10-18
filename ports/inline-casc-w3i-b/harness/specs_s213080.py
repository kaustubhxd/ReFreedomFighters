"""specs_s213080.py - batch 213080: timed actor state step with step table, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5d76f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    rb = lambda emu, k: r.choice([0, 0, 1, 0x100, 0xff, r.getrandbits(32)])
    X = obj(c, 0x20, {0x38: sl(2, rb)}, nslots=0x40)
    T = obj(c, 0x20, {0x4c: sl(1)}, nslots=0x40)
    eng = rnd(c, 0x1a00)
    e.w32(eng + 0x1907, X)
    e.w32(eng + 0x9b, T)
    clock = r.choice([0, 100, 1000, 5000, -5, r.getrandbits(32), 0x7fffffff])
    e.w32(eng + 0x40, clock & 0xffffffff)
    e.w32(0x70039c, eng)
    holder = []

    def clr(emu, k):
        if r.random() < 0.3:
            emu.wbytes(holder[0] + 0x1cc, bytes([0]))
    P = obj(c, 0x20, {0x14: sl(0, lambda emu, k: r.choice([0, 1, 2, 3, r.getrandbits(32)]), side=clr), 0x30: sl(1)}, nslots=0x40)
    Q = obj(c, 0x20, {0x128: sl(3, side=clr), 0x12c: sl(3), 0x130: sl(3, deref={2: 2})}, nslots=0x50)
    this = rnd(c, 0x240)
    holder.append(this)
    e.w32(this + 0x14e, P)
    e.w32(this + 0x44, Q)
    cl = lambda: (clock + r.choice([-10, -1, 0, 1, 10, 500, -500, 100000])) & 0xffffffff
    e.wbytes(this + 0x1cc, bytes([r.choice([0, 1, 1, 1, 0xff])]))
    e.w32(this + 0x1c8, cl())
    e.wbytes(this + 0x1c3, bytes([r.choice([0, 1, 1])]))
    e.w32(this + 0x156, r.choice([0, 1, 1, 2, 2, 3, -1 & 0xffffffff, 0x80000000, r.getrandbits(32)]))
    e.wbytes(this + 0x1e6, bytes([r.choice([0, 1, 1])]))
    e.wbytes(this + 0x142, struct.pack('<H', r.getrandbits(16)))
    e.wbytes(this + 0x14a, struct.pack('<H', r.getrandbits(16)))
    e.w32(this + 0x48, r.choice([0, 1, 2, 3, 5]))
    e.w32(this + 0x13c, r.choice([0, 0, 1, 2, 3, 4, 0x80000000, 0xffffffff]))
    if r.random() < 0.3:
        e.w32(this + 0x13c, struct.unpack('<I', bytes(e.rbytes(this + 0x48, 4)))[0])
    e.w32(this + 0x1c4, r.choice([clock - 40, clock - 100, clock - 200, clock - 400, clock - 1000, clock - r.randint(0, 3000), clock, r.getrandbits(32)]) & 0xffffffff)
    e.wbytes(this + 0x1d1, struct.pack('<I', r.choice([0, 0x1234, r.getrandbits(32)])))
    for i in range(6):
        e.w32(this + 0x4c + 12 * i, r.choice([-5, -5, -1, 0, 1, 2, 3, 4, 5, 6, 8, 10, 15, 25, 100, 100000, r.randint(0, 60), r.getrandbits(32)]) & 0xffffffff)
    # make a record time equal to the computed step value (exact boundary)
    c4 = struct.unpack('<I', bytes(e.rbytes(this + 0x1c4, 4)))[0]
    tk = struct.unpack('<i', struct.pack('<I', (clock - c4) & 0xffffffff))[0]
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    try:
        ev = int(f32(f32(f32(tk) * f32(1 / 1024.0)) * 25.0))
    except (OverflowError, ValueError):
        ev = 0
    ix = struct.unpack('<I', bytes(e.rbytes(this + 0x13c, 4)))[0]
    if r.random() < 0.5 and ix < 6 and -2**31 <= ev < 2**31:
        e.w32(this + 0x4c + 12 * ix, ev & 0xffffffff)
    hook_rec(c, 0x5d7e00, 0, this=True)
    hook_rec(c, 0x5d7bc0, 0, this=True)
    return [this]


S(0x5d76f0, 'actor_step', 'thiscall', None, ret=None, gen=g5d76f0)
