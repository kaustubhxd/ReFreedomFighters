"""specs_s1809.py - fresh-18 batch 9 (src/batch1809.cpp). 0x7003b0 is a logging stub where the code can assert."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)


def logger(c, nargs):
    lg = h.obj(c, {0x2c: h.L(c, 'log2c', nargs, regs=(), pops=0)})
    c.emu.w32(0x700390, h.obj(c, {0x20: h.L(c, 'log20', 2, ret=lg)}))


def assert_stub(c):
    c.emu.w32(0x7003b0, h.L(c, 'assert', 0, regs=()))


def g45b3a0(c):
    h.hk(c, 0x43de40, 'ZSTDOBJ', 3)
    def ms(e, rv, a):
        e.wbytes(a[0], bytes([a[1] & 0xff]) * a[2])
    h.hk(c, 0x634d10, 'memset', 3, pops=0, regs=(), wr=ms, ret=lambda e, rv, a: a[0])
    return [h.rnd(c, 0x960), R(c), R(c), R(c)]
S(0x45b3a0, 'GUESS ZSTDOBJ subclass constructor (vtable 0x684580)', 'thiscall', None, ret='eax', gen=g45b3a0)


def g63fc20(c):
    h.hk(c, 0x634273, 'delete', 2, pops=0, regs=())
    return [h.rnd(c, 0x240)]
S(0x63fc20, 'GUESS delete eight blocks', 'thiscall', None, gen=g63fc20)


def g50f120(c):
    assert_stub(c)
    logger(c, 3)
    p = h.rnd(c, 8)
    q = h.rnd(c, 8)
    c.emu.w8(q + 4, c.rng.choice([0, 1, 1, c.rng.randint(2, 255)]))
    h.hk(c, 0x5003d0, 'param', 1, ret=[p, q])
    h.hk(c, 0x5002f0, 'setint', 1)
    g = h.obj(c, {0x20: h.L(c, 'g20', 0, ret=R(c))})
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=c.rng.choice([0, g, g])), 0x4c: h.L(c, 'e4c', 1, ret=R(c))}))
    return [R(c), h.rnd(c, 0x10)]
S(0x50f120, 'ZScriptSceneInterface_t::GetParentForGeom', 'thiscall', None, gen=g50f120)


def g651ce0(c):
    pat = c.rng.randbytes(0x80)
    h.hk(c, 0x4cbe80, 'MYSTR', 1, wr=lambda e, rv, a: e.wbytes(rv[0], pat))
    h.hk(c, 0x4cbee0, 'MYSTR=', 1)
    h.hk(c, 0x4cbec0, '~MYSTR', 0)
    c.emu.w32(0x676414, h.L(c, '_stricmp', 2, regs=(), pops=0, ret=c.rng.choice([0, 1, 0xffffffff])))
    h.engine(c, 0x1e91, R(c))
    blk = c.emu.r32(0x70039c)
    big = h.rnd(c, 0x1aa0)
    c.emu.wbytes(big, c.emu.rbytes(blk, 0x1e91 + 4)[:0x1aa0])
    c.emu.w32(0x70039c, h.rnd(c, 0x1ed0))
    c.emu.w32(c.emu.r32(0x70039c) + 0x1e91, R(c))
    return [R(c), R(c)]
S(0x651ce0, 'GUESS set engine name', 'thiscall', None, gen=g651ce0)


def g5d9f60(c):
    h.hk(c, 0x469870, 'geombase', 0)
    h.engine(c, 0x9b, h.obj(c, {0x114: h.L(c, 'RegisterZMsg', 4, ret=lambda e, rv, a: R(c))}, size=0x120))
    return [h.rnd(c, 0x60)]
S(0x5d9f60, 'CTVStudioCam::CTVStudioCam', 'thiscall', None, ret='eax', gen=g5d9f60)


def tracker(c, blk):
    tag = R(c)
    fn = h.L(c, 'rangefn', 0, ret=R(c))
    m = h.obj(c, {0x20: h.L(c, 'm20', 1, ret=c.rng.choice([0, 0, 1])),
                  0xac: h.L(c, 'mac', 1, wr=lambda e, rv, a: e.w32(a[0] - 4, tag))})
    c.emu.w32(m + 8, c.rng.choice([0, fn]))
    c.emu.w32(m + 0xc, c.rng.choice([blk - 4, blk, blk + 1]))
    c.emu.w32(m + 0x10, c.rng.choice([blk, blk + 1, blk + 0x100]))
    c.emu.w32(0x70038c, m)


def g49f5a0(c):
    h.hk(c, 0x469870, 'geombase', 0)
    h.hk(c, 0x49f670, 'f49f670', 0)
    x = h.obj(c, {0x60: h.L(c, 'x60', 3)})
    h.engine(c, 0x9b, h.obj(c, {0x138: h.L(c, 'e138', 0, ret=x)}, size=0x140))
    s = h.rnd(c, 0x90) + 8
    c.emu.w32(s - 4, c.rng.choice([0, R(c)]))
    tracker(c, s)
    return [s]
S(0x49f5a0, 'GUESS constructor (vtable 0x68f560)', 'thiscall', None, ret='eax', gen=g49f5a0)


def g4320e0(c):
    t = h.rnd(c, 0x40)
    for i in range(3):
        st = c.rng.randint(-5, 40)
        c.emu.w32(t + 0x10 * i, st & 0xffffffff)
        c.emu.w32(t + 0x10 * i + 0xc, c.rng.randint(-3, 20) & 0xffffffff)
    for o in (0xc, 0x1c, 0x2c):
        if c.rng.random() < 0.7:
            c.emu.w32(t + o, c.rng.choice([0, 1, 5, 30, 0xffffffff]))
    blk = h.rnd(c, 0x1910)
    c.emu.w32(blk + 0x190b, t)
    c.emu.w32(0x70039c, blk)
    dev = c.rng.choice([0, 1, 2, 0x42, 0x42, 3, R(c) >> 16])
    v = (dev << 16) | c.rng.choice([0, 1, 3, 10, 25, R(c) & 0xffff])
    s = h.obj(c, {0x10: h.L(c, 's10', 1, ret=v & 0xffffffff)})
    return [s, c.rng.choice([0, 3, 20, 0xffffffff, R(c)])]
S(0x4320e0, 'CConfiguration::ExtractInputFromNode', 'thiscall', None, ret='eax', gen=g4320e0)


def g551160(c):
    prm = h.rnd(c, 0x20)
    ev = h.obj(c, {0x4c: h.L(c, 'ev4c', 0, ret=prm)})
    f = h.obj(c, {0x18: h.L(c, 'f18', 1, ret=c.rng.choice([0, ev, ev, ev]))})
    h.hk(c, 0x5003d0, 'param', 1, ret=lambda e, rv, a: R(c))
    h.hk(c, 0x500360, 'setfloat', 1)
    return [R(c), f, R(c), h.rnd(c, 0x18)]
S(0x551160, 'Signature_ffffff_EventTranslator_t::handleEventTranslation', 'thiscall', None, ret='eax', gen=g551160)


def g449920(c):
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=lambda e, rv, a: c.rng.choice([0, lt]))}))
    lt = h.obj(c, {0x230: h.L(c, 'l230', 1)}, size=0x240)
    def get(e, r):
        a0, a1 = e.arg32(0), e.arg32(1)
        e.calllog.append(('r84', (), (a0,)))
        e.wbytes(a1, c.rng.randbytes(0x38))
        e.ret(eax=0, argbytes=8)
    def put(e, r):
        a0, a1 = e.arg32(0), e.arg32(1)
        e.calllog.append(('ra0', (), (a0, e.rbytes(a1, 0x38).hex())))
        e.ret(eax=0, argbytes=8)
    rr = h.obj(c, {0x84: c.emu.stub_fn('r84', get), 0xa0: c.emu.stub_fn('ra0', put)}, size=0xb0)
    b2 = h.rnd(c, 0x20)
    c.emu.w32(b2 + 0x18, rr)
    blk = c.emu.r32(0x70039c)
    big = h.rnd(c, 0x1ab0)
    c.emu.wbytes(big, c.emu.rbytes(blk, 0x9b + 0x40))
    c.emu.w32(big + 0x1aa3, b2)
    c.emu.w32(0x70039c, big)
    cnt = c.rng.randint(0, 4)
    def start(e, rv, a):
        e.w32(a[0], cnt); e.w32(a[0] + 4, 0x1234); e.w32(a[0] + 8, R(c))
    def step(e, rv, a):
        e.w32(a[0], max(e.r32(a[0]) - 1, 0))
    t = h.obj(c, {0x4c: h.L(c, 'start', 1, wr=start), 0x5c: h.L(c, 'step', 1, wr=step, ret=lambda e, rv, a: R(c))})
    p8 = h.rnd(c, 0x70)
    s = h.obj(c, {0x238: h.L(c, 's238', 0), 0x220: h.L(c, 's220', 1)}, size=0x40)
    c.emu.w32(s + 8, p8)
    c.emu.w32(s + 0x1c, c.rng.choice([0, t, t]))
    return [s, F(c.fv())]
S(0x449920, 'ZGateLightSpotMaster::SetMultiplier', 'thiscall', None, gen=g449920, stack_arg_bytes=12)


def g424ee0(c):
    logger(c, c.rng.choice([2]))
    txt = c.rng.choice([b'', b'hello %d', bytes(c.rng.randint(0x41, 0x7a) for _ in range(c.rng.randint(1, 40)))])
    def vs(e, rv, a):
        e.wbytes(a[0], txt + b'\0')
    h.hk(c, 0x42abee, 'vsprintf', 3, pops=0, regs=(), wr=vs, ret=len(txt))
    c.emu.w32(0x6760f4, h.L(c, 'GlobalAddAtomA', 1, regs=(), ret=c.rng.choice([0, 0x10000, 0xc001, R(c)])))
    s = h.obj(c, {0x18: h.L(c, 's18', 3)}, size=0x30)
    c.emu.w32(s + 0x24, c.rng.choice([0, 1, 1, 1]))
    return [s, R(c), R(c), R(c)]
S(0x424ee0, 'ZSysComGC::DataToDebug', 'cdecl', None, gen=g424ee0)
