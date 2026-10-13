"""specs_s9005.py - wire-ai batch 9005: ConstrainedParticleSystem::ComputeDistances 0x544e10. 16 particle records (0x34 bytes, position at
+0xc) spread like a body or random, sometimes coincident pairs; a distance list of 0..24 entries with indices 0..15; a special list of 13+
entries; the special count below, at or above 13 (the error path logs through a 2-argument printf and calls the assert hook, always set:
a null hook would be int3 in both builds); the engine random (slot 0x1c0, ST0, float) around 0.5 (exactly 0.5 included).
PSVECSubtract runs as exe code; the CRT sqrt is the emulator's (correctly rounded, as the port's)."""
import struct
from pilot import S, f32
from specs_s701 import _rnd


def _cd(c):
    e = c.emu
    eng = _rnd(c, 0x200)

    def draw(em, r):
        em.calllog.append(('rand', 0x1c0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=8, st0=c.rng.choice([0.5, 0.0, 0.9999, c.rng.random(), c.rng.random(), f32(0.5 - 2 ** -25)]))
    e.w32(eng, e.fake_vtable('engine', 0x80, {0x1c0: draw}))
    e.w32(0x70039c, eng)
    logobj = _rnd(c, 16)

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, (em.arg32(1),)))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)

    def opn(em, r):
        em.calllog.append(('logger.20', 0x20, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=logobj, argbytes=8)
    e.w32(lg, e.fake_vtable('logger', 16, {0x20: opn}))
    e.w32(0x700390, lg)
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))
    recs = _rnd(c, 16 * 0x34)
    s = c.rng.choice([1.0, 30.0, 100.0])
    for i in range(16):
        p = [c.rng.uniform(-s, s) for _ in range(3)]
        e.wbytes(recs + 0x34 * i + 0xc, struct.pack('<3f', *[f32(x) for x in p]))
    if c.rng.random() < 0.2:
        a, b = c.rng.randrange(16), c.rng.randrange(16)
        e.wbytes(recs + 0x34 * b + 0xc, e.rbytes(recs + 0x34 * a + 0xc, 12))
    n = c.rng.choice([0, 1, 5, 17, 24])
    dl = _rnd(c, 0xc * max(n, 1))
    for k in range(n):
        e.w32(dl + 0xc * k, c.rng.randrange(16))
        e.w32(dl + 0xc * k + 4, c.rng.randrange(16))
    sl = _rnd(c, 0xc * 16)
    ps = _rnd(c, 0x80)
    e.w32(ps + 0xf, recs)
    e.w32(ps + 0x13, dl)
    e.w32(ps + 0x17, sl)
    e.w32(ps + 0x2c, n)
    e.w32(ps + 0x30, c.rng.choice([13, 13, 16, 12, 0, 0xffffffff]))
    return [ps]


S(0x544e10, 'ConstrainedParticleSystem::ComputeDistances', 'thiscall', None, ret=None, gen=_cd, note='b9005; PSVECSubtract as exe code')
