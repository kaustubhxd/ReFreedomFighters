"""specs_s35033.py - 0x5bf8a0 (thiscall, no args; all fields unaligned). Fields: +0x4c target (slots 0x214 (2 args), 0x128 (3 args)), +0x50 byte, +0x51 / +0x53 words, +0x59 dword (zero in half), +0x61 object whose
+0x18 points at an object with slot 0x14 (returns +0x6a in half the cases), +0x65 byte (set in half), +0x6a dword (zero in 1/4), +0x6e mode (1 in half, else 0 / 2 / random), +0x72 byte (0 or 1)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g5bf8a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x80)

    def w32(off, v):
        e.wbytes(me + off, (v & 0xffffffff).to_bytes(4, 'little'))
    f6a = 0 if r.random() < 0.25 else r.getrandbits(32) | 1
    t = obj(c, 0x20, {0x214: pystub(c, 2, this=True), 0x128: pystub(c, 3, this=True)}, nslots=0x90)
    w32(0x4c, t)
    e.wbytes(me + 0x50, bytes([r.choice([0, 1])]))
    e.wbytes(me + 0x51, r.getrandbits(16).to_bytes(2, 'little'))
    e.wbytes(me + 0x53, r.getrandbits(16).to_bytes(2, 'little'))
    w32(0x59, 0 if r.random() < 0.5 else r.getrandbits(32) | 1)
    k = obj(c, 0x10, {0x14: pystub(c, 0, this=True, ret=f6a if r.random() < 0.5 else r.getrandbits(32))}, nslots=8)
    o = rnd(c, 0x40)
    e.w32(o + 0x18, k)
    w32(0x61, o)
    e.wbytes(me + 0x65, bytes([r.choice([0, 1])]))
    w32(0x6a, f6a)
    w32(0x6e, 1 if r.random() < 0.5 else r.choice([0, 2, r.getrandbits(32)]))
    e.wbytes(me + 0x72, bytes([r.choice([0, 1])]))
    return [me]


S(0x5bf8a0, 'GUESS recompute on/off state', 'thiscall', None, ret=None, gen=_g5bf8a0, note='batch35033')
