"""specs_s213137.py - batch 213137: aim angle smoothing with wrap-around, rate limits and two log lines, Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5d2ab0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    rdf = lambda a: struct.unpack('<f', bytes(e.rbytes(a, 4)))[0]
    TWO, PI, NPI = rdf(0x68aef8), rdf(0x67da18), rdf(0x6ad238)
    C27, LIM, U, T7, T34, LO, A66 = rdf(0x67af28), rdf(0x6b4fe8), rdf(0x6a09e4), rdf(0x6ad1fc), rdf(0x6ad234), rdf(0x6b4fdc), rdf(0x6a066c)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))

    def ang():
        return r.choice([0.0, PI, NPI, PI + 0.5, NPI - 0.5, 1.0, -1.0, 3.0, -3.0, TWO, 0.1, r.uniform(-7, 7), r.uniform(-PI, PI), C27, C27 - 0.01, C27 + 0.01])

    def rate():
        return r.choice([0.0, 0.5, -0.5, 1.0, 5.0, LIM, U, LIM - 0.1, U + 0.1, T7, T34, T7 + 1, T34 - 1, r.uniform(-4, 4)])

    def gen_log(emu, name):
        pass
    # log objects
    O = obj(c, 0x40, {0x2c: e.stub_fn('logfmt', lambda em, res_: (em.calllog.append(('log', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3))), em.ret(eax=0, argbytes=0))[1])}, nslots=0x20)
    Lg = obj(c, 0x40, {0x20: pystub(c, 2, this=True, ret=O)}, nslots=0x20)
    e.w32(0x700390, Lg)
    eng = rnd(c, 0x100)
    e.w32(0x70039c, eng)
    this = rnd(c, 0xb10)
    sane = r.random() < 0.65
    nan = float('nan')
    sc = r.random()   # boundary scenario selector
    a54v, av = ang(), ang()
    if sane:
        a54v, av = f32(r.uniform(-PI, PI)), f32(r.uniform(-PI, PI))
    k1 = r.choice([0.0, 0.5, 1.0, 2.0, 3.0, 1.5, -1.0, r.uniform(1, 3)]) if sane else r.choice([0.0, 0.5, 1.0, 2.0, 0.1, 3.0, -1.0, r.uniform(0, 3)])
    g1 = r.uniform(0.1, 1.0) if sane else r.choice([0.0, 1.0, 2.0, -1.0, r.uniform(-2, 2)])
    g2 = r.uniform(0.1, 1.0) if sane else r.choice([0.0, 1.0, 0.5, -1.0, r.uniform(0, 2)])
    dtv = r.choice([0.016, 0.033, 0.0, 0.016, 0.1]) if sane else r.choice([0.0, 0.016, 0.5, 1.0, -0.016, 2.0, 0.1])
    a60v, af1v, af5v, a64v = rate(), rate(), rate(), rate()
    b45v = 1 if r.random() < 0.5 else 0
    k2v = r.choice([0.0, 0.5, 1.0, 2.0, A66, 3.0, -1.0, r.uniform(0, 3)])
    a5cv, aedv = ang(), ang()
    a96v = r.choice([-1.0, -0.5, 0.0, -2.0, LO, r.uniform(-3, 0)])
    a9av = r.choice([1.0, 0.5, 2.0, 0.0, r.uniform(-1, 3)])
    if sc < 0.06:       # d == PI exactly at the first wrap test
        av, a54v = NPI, 0.0
    elif sc < 0.12:     # d == -pi exactly
        av, a54v = TWO, NPI
    elif sc < 0.18:     # d == C27 exactly (report threshold)
        av, a54v = -1.0, f32(-1.0 + C27)
    elif sc < 0.24:     # m == T7 exactly (rate path off, rate = a60, dt = 1)
        k1, dtv, b45v, a60v = 0.0, 1.0, 0, T7
    elif sc < 0.30:     # m == T34 exactly
        k1, dtv, b45v, a60v = 0.0, 1.0, 0, T34
    elif sc < 0.36:     # k == 0 (gain path off)
        k1 = 0.0
    elif sc < 0.42:     # a60 NaN (minss operand order, clamp)
        k1, a60v, b45v = 0.0, nan, 1
    elif sc < 0.48:     # pitch angle NaN
        aedv = nan
    elif sc < 0.54:     # aed == a96 exactly with a9a < a96 and no pitch rate
        k2v, a64v, af5v = 0.0, 0.0, 0.0
        a96v, a9av = 0.5, -1.0
        aedv = 0.5
        a5cv = f32(0.5 - 0.01)
    elif sc < 0.60:     # pitch error exactly LO / exactly k2
        k2v, a64v = 1.0, 0.0
        a5cv, aedv = LO, 0.0
    elif sc < 0.66:
        k2v, a64v = 1.0, 0.0
        a5cv, aedv = 1.0, 0.0
    wf(this + 0xa54, a54v)
    w32u(this + 0xae9, 0)
    wf(this + 0xae9, av)
    wf(this + 0xa60, a60v)
    wf(this + 0xaf9, k1)
    wf(this + 0xb01, g1)
    wf(this + 0xadd, g2)
    wf(this + 0xaf1, af1v)
    wf(this + 0xa5c, a5cv)
    wf(this + 0xaed, aedv)
    wf(this + 0xaf5, af5v)
    wf(this + 0xafd, k2v)
    wf(this + 0xa64, a64v)
    wf(this + 0xa96, a96v)
    wf(this + 0xa9a, a9av)
    e.wbytes(this + 0xb45, bytes([b45v]))
    wf(eng + 0x48, dtv)
    return [this]


S(0x5d2ab0, 'aim_smoothing', 'thiscall', None, ret=None, gen=g5d2ab0)
