"""specs_s2436.py - decomp area 24, batch 2436 (slice 11 leaves).
0x59a570 ZGameOSD::InvalidateView(), thiscall, plain ret: when the dword at +0x1d0f is set, its +0x368 is cleared.
0x5f2ef0 LoadSerialInfo_t::loadint16(short&), thiscall, ret 4: tail jump to slot 0x4c of the object at +0x15 (recorder, one
argument, which pops it). 0x5f32b0 SaveSerialInfo_t::saveuint16(unsigned short), thiscall, ret 4: tail jump to slot 0x40 of
the object at +0x15 (recorder, one argument).
0x43e0f0 ZSTDOBJ::ClassInit(), thiscall, plain ret: when bit 0x40000000 of the dword at ([+8])+0x3c is set, ZBaseGeom::
SetControl(0x2000000, 0) (0x4dc630, recorder, two arguments) is called on that object."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _osd(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x1d20)
    if r.random() < 0.7:
        inner = rnd(c, 0x400)
        e.w32(o + 0x1d0f, inner)
    else:
        e.w32(o + 0x1d0f, 0)
    return [o]


def _ser(slot):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        o = rnd(c, 0x40)
        t = obj(c, 0x40, {slot: pystub(c, 1)})
        e.w32(o + 0x15, t)
        return [o, r.getrandbits(32)]
    return gen


def _cls(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    inner = rnd(c, 0x40)
    e.w32(inner + 0x3c, r.getrandbits(32) if r.random() < 0.5 else (r.getrandbits(32) | 0x40000000))
    e.w32(o + 8, inner)
    hook_rec(c, 0x4dc630, 2, this=True)
    return [o]


S(0x59a570, 'ZGameOSD::InvalidateView', 'thiscall', None, ret=None, gen=_osd, note='batch2436')
S(0x5f2ef0, 'LoadSerialInfo_t::loadint16', 'thiscall', None, ret='eax', gen=_ser(0x4c), note='batch2436')
S(0x5f32b0, 'SaveSerialInfo_t::saveuint16', 'thiscall', None, ret='eax', gen=_ser(0x40), note='batch2436')
S(0x43e0f0, 'ZSTDOBJ::ClassInit', 'thiscall', None, ret=None, gen=_cls, note='batch2436')
