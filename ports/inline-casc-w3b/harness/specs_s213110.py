"""specs_s213110.py - batch 213110: config-driven reset with five optional keys, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g4fb040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    # per-key presence: C.slot 0xa4(key, 0) -> al
    def ret_a4(emu, k):
        return (r.getrandbits(32) & ~0xff) | (0 if r.random() < 0.4 else r.choice([1, 2, 0x80]))
    # R object: [0] = Ro (slots 0x84, 0x9c), [4] = id
    def s84(emu, k):
        if r.random() < 0.2:
            return
        emu.wbytes(emu.arg32(1), struct.pack('<I', r.choice([0x7fc00001, 0x80000000, 0x3f800000, 0x42c80000, r.getrandbits(32)])))
    Q = rnd(c, 0x10)
    Ro = obj(c, 0x20, {0x84: pystub(c, 2, this=True, nullflag=(1,), side=s84), 0x9c: pystub(c, 2, this=True, ret=Q)}, nslots=0x60)
    R = rnd(c, 0x10)
    e.w32(R, Ro)
    C = obj(c, 0x20, {0xa4: pystub(c, 2, this=True, ret=ret_a4), 0x94: pystub(c, 2, this=True, nullflag=(0,), ret=R)}, nslots=0x60)
    T = obj(c, 0x20, {0x138: pystub(c, 0, this=True, ret=C)}, nslots=0x60)
    eng = obj(c, 0x100, {}, nslots=4)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    # this and its sub object
    O44 = obj(c, 0x40, {0x214: pystub(c, 1, this=True), 0x218: pystub(c, 1, this=True), 0x220: pystub(c, 1, this=True),
                        0x21c: pystub(c, 1, this=True), 0x224: pystub(c, 1, this=True)}, nslots=0x100)
    this = obj(c, 0x70, {0x84: pystub(c, 0, this=True)}, nslots=0x60)
    e.w32(this + 0x44, O44)
    return [this]


S(0x4fb040, 'config_reset', 'thiscall', None, ret=None, gen=g4fb040)
