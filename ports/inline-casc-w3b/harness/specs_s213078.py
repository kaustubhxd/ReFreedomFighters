"""specs_s213078.py - batch 213078: nearest active entry search and list slot update, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

THR = None


def g559f90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    thr = struct.unpack('<f', bytes(e.rbytes(0x692798, 4)))[0]

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    M = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    L = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, L)

    def posside(emu, k):
        if r.random() < 0.7:
            emu.wbytes(emu.arg32(0), struct.pack('<fff', r.uniform(-5, 5), r.uniform(-5, 5), r.uniform(-5, 5)))
    A = obj(c, 0x20, {0x84: sl(1, nullflag=(0,), side=posside)}, nslots=0x60)
    this = rnd(c, 0x40)
    e.w32(this + 0x1c, A)
    Y = obj(c, 0x20, {0x84: sl(1, nullflag=(0,), side=posside)}, nslots=0x60)
    T = obj(c, 0x20, {0x58: sl(1, Y)}, nslots=0x60)
    eng = rnd(c, 0x100)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    N = r.choice([0, 1, 2, 3, 4, 4])
    P = rnd(c, 0xc6d + 9 * 6 + 8)
    e.w32(0x7003b8, P)
    e.w32(P + 0xc69, N)
    for i in range(6):
        e.wbytes(P + 0xc6d + 9 * i + 8, bytes([r.choice([0, 1, 1, 0xff])]))
    # list vector V -> H -> array
    arr = rnd(c, 8 * 8)
    for i in range(8):
        e.wbytes(arr + 8 * i + 4, bytes([r.choice([0, 1, 0, 1, 2, 0xff])]))
    H = rnd(c, 0x10)
    e.w32(H, arr)
    cap = r.choice([0, 1, 3, 5, 8])
    e.w32(H + 8, cap)
    V = rnd(c, 0x10)
    e.w32(V, H)
    e.w32(V + 4, r.choice([0, 1, 2, cap, cap + 1, 7]))
    e.w32(V + 8, r.choice([0, 1, 2, 5]))
    rec = rnd(c, 0x10)
    e.w32(rec + 8, V)
    # 5003d0 result
    p0 = rnd(c, 8)
    e.wbytes(p0 + 4, bytes([r.choice([0, 1, 0, 1, 2, 0xff])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=p0)

    def dval(emu, k):
        if r.random() < 0.3:
            emu.w32(P + 0xc69, 6)
        emu.calllog.append(('v', bytes(emu.rbytes(emu.reg('ecx'), 12)), bytes(emu.rbytes(emu.reg('edx'), 12))))
        return r.choice([thr * 0.5, thr * 2, thr, 0.0, -1.0, float('nan'), r.uniform(0, thr * 2)])
    hook_rec(c, 0x4e0830, 0, pop=0, st0=dval, ret=0)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, rec]


S(0x559f90, 'nearest_active_entry', 'thiscall', None, ret=None, gen=g559f90)
