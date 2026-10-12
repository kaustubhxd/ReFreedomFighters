"""specs_s601.py - damage batch 601: ZFFActor::CanBreakHitAnim (PC 0x59dfd0). _CIfmod runs as exe code."""
from pilot import S
from wkit import rnd
import struct


# _CIfmod stand-in in heap code: fxch; L: fprem; fnstsw ax; sahf; jp L; fstp st(1); ret. fprem gives the exact
# truncated remainder (what fmod returns); a zero divisor gives the x87 default NaN. Both builds call it through the
# same IAT slot 0x676358, so it only has to be deterministic.
FMOD = bytes.fromhex('d9c9' 'd9f8' 'dfe0' '9e' '7af9' 'ddd9' 'c3')


def _fmod_stub(c):
    a = c.emu.alloc(32, 16)
    c.emu.wbytes(a, FMOD)
    c.emu.w32(0x676358, a)


def _gen(c):
    r = c.rng
    _fmod_stub(c)
    a = rnd(c, 0xa00)
    holder = rnd(c, 0x40)
    anim = rnd(c, 0x80)
    c.emu.w32(a + 0x1c, holder)
    c.emu.w32(holder + 0x14, anim)
    k = r.random()
    hid = 0 if k < 0.15 else r.getrandbits(32)
    c.emu.w32(a + 0x90f, hid)
    c.emu.w32(anim + 0x48, hid if r.random() < 0.75 else r.getrandbits(32))
    start = r.choice((0.0, 0.0, r.uniform(0, 50)))
    t = start + r.choice((r.uniform(0, 40), r.uniform(0, 400), 17.9999, 18.0, 18.0001, r.uniform(-5, 0), float('nan')))
    c.emu.wf32(anim + 4, t)
    c.emu.wf32(anim + 0x30, start)
    c.emu.w32(anim + 0xc, r.choice((0, 1, 12, 18, 19, 25, 30, 40, 60, r.randrange(1, 200), -30)) & 0xffffffff)
    return [a]


S(0x59dfd0, 'ZFFActor::CanBreakHitAnim', 'thiscall', ret='al', gen=_gen)
