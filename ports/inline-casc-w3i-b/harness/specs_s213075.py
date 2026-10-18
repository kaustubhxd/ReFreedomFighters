"""specs_s213075.py - batch 213075: UI element state push through engine table slots, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g572be0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    S1 = obj(c, 0x20, {0x60: sl(2)}, nslots=0x20)
    S2 = obj(c, 0x20, {0x60: sl(3)}, nslots=0x20)
    X = obj(c, 0x20, {0x90: sl(2, nullflag=(1,), side=lambda emu, k: (emu.wbytes(emu.arg32(1), bytes([r.choice([0, 1, 1, 0xff])])) if r.random() < 0.7 else None))}, nslots=0x30)
    Y = obj(c, 0x20, {0x70: sl(1, deref={0: 3}), 0xbc: sl(1)}, nslots=0x60)
    tret = [S1, S2]
    T = obj(c, 0x20, {0x138: pystub(c, 0, ret=lambda emu, k: tret[min(k, 1)], this=True), 0x4c: sl(2),
                      0x134: sl(0, X), 0x58: sl(1, lambda emu, k: 0 if r.random() < 0.3 else Y)}, nslots=0x60)
    w44 = obj(c, 0x20, {0x70: sl(1, deref={0: 3}), 0xbc: sl(1)}, nslots=0x60)
    e.w32(w44 + 8, rnd(c, 0x10))
    eng = rnd(c, 0x1a00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, T)
    pX = rnd(c, 0x90)
    e.wbytes(pX + 0x81, bytes([r.choice([0, 1, 0xff])]))
    px_sel = r.choice([0, pX, pX])
    e.w32(eng + 0x190f, px_sel)
    if px_sel == 0:
        try:
            e.wbytes(0x81, bytes([1]))
        except Exception:
            pass
    e.w32(eng + 0x73, r.choice([0, 100, 480, 1000, 0x7fffffff, 0x80000000, r.getrandbits(32), r.randint(1, 2000)]))
    base = rnd(c, 0x8a0)
    this = base + 8
    e.w32(this + 0x44, w44)
    e.wbytes(this + 0x87e, bytes([r.choice([0, 1, 1, 0xff])]))
    e.w32(this + 0x87a, r.getrandbits(32))
    e.w32(base + 4, r.choice([0, 0x12345678]))
    # name lookup table object (0x70038c)
    cbk = sl(0)
    Eo = obj(c, 0x20, {0x20: sl(1, lambda emu, k: r.choice([0, 0, 0, 1, r.getrandbits(32)])), 0xac: sl(1)}, nslots=0x60)
    e.w32(Eo + 8, r.choice([cbk, cbk, 0]))
    e.w32(Eo + 0xc, this - r.choice([0, 1, 100]) if r.random() < 0.8 else this + 1)
    e.w32(Eo + 0x10, this + r.choice([1, 100]) if r.random() < 0.8 else this)
    e.w32(0x70038c, Eo)

    def comp():
        return r.choice([0.0, -0.0, 1.0, 100.0, -50.5, 1e10, 3e9, NAN, float('inf'), r.uniform(-1000, 1000), r.uniform(0, 1000)])

    def side_v(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<fff', comp(), comp(), comp()))
    hook_rec(c, 0x4db500, 1, this=True, nullflag=(0,), side=side_v)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x572be0, 'ui_state_push', 'thiscall', None, ret=None, gen=g572be0)
