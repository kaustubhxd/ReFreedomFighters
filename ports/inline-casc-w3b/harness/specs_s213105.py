"""specs_s213105.py - batch 213105: field serializer writing to a stream object through typed slots, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5ca270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x470)
    # a few NaN / special dwords so raw bit preservation is visible
    for off in (0x2f6, 0x2fa, 0x330, 0x334, 0x338, 0x33c, 0x340):
        if r.random() < 0.15:
            e.w32(this + off, r.choice([0x7fc00001, 0xffc12345, 0x80000000, 0x7f800000]))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    def sv(emu, k):
        lg(emu, 'vec', emu.arg32(0), 12)

    def sm(emu, k):
        lg(emu, 'mat', emu.arg32(0), 36)
    slots = {0x3c: pystub(c, 1, this=True), 0x44: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True), 0x60: pystub(c, 1, this=True),
             0x68: pystub(c, 1, this=True, side=sv), 0x70: pystub(c, 1, this=True, side=sm)}
    stream = obj(c, 0x20, slots, nslots=0x40)
    hook_rec(c, 0x4fb2f0, 1, pop=4, this=True, ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | (0 if r.random() < 0.25 else r.choice([1, 2, 0x80])))
    return [this, stream]


S(0x5ca270, 'serialize_fields', 'thiscall', None, ret='al', gen=g5ca270)
