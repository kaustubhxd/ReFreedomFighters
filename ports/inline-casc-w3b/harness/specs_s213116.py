"""specs_s213116.py - batch 213116: field serializer with typed stream slots and three helper writers, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5213f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x2720)
    for off in (0x2f0, 0x2f8, 0x25cd, 0x2618, 0x268d, 0x2691):
        if r.random() < 0.15:
            e.w32(this + off, r.choice([0x7fc00001, 0xffc12345, 0x80000000, 0x7f800000]))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    def sv(emu, k):
        lg(emu, 'vec', emu.arg32(0), 12)

    def sr(emu, k):
        lg(emu, 'raw', emu.arg32(0), 4)
    slots = {0x3c: pystub(c, 1, this=True), 0x44: pystub(c, 1, this=True), 0x64: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True),
             0x60: pystub(c, 1, this=True), 0x68: pystub(c, 1, this=True, side=sv), 0x10: pystub(c, 2, this=True, side=sr)}
    stream = obj(c, 0x20, slots, nslots=0x40)
    hook_rec(c, 0x515b70, 1, pop=4, this=True, ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | (0 if r.random() < 0.25 else r.choice([1, 2, 0x80])))
    hook_rec(c, 0x528c80, 1, pop=4, this=True)
    hook_rec(c, 0x5274f0, 1, pop=4, this=True)
    return [this, stream]


S(0x5213f0, 'serialize_fields_b', 'thiscall', None, ret='al', gen=g5213f0)
