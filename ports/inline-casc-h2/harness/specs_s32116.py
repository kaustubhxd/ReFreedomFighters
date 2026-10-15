"""specs_s32116.py - h2 (Sonnet) batch 32116: 0x6101b0. Slot 0xc8 is a recorder stub with three stdcall arguments (ECX there is the vtable, not recorded); the object field is rewritten between calls."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def g6101b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x1390)

    def mk(depth):
        def side(emu, k):
            if depth < 5 and r.random() < 0.6:
                emu.wbytes(me + 0x1377, mk(depth + 1).to_bytes(4, 'little'))
        return obj(c, 0x20, {0xc8: pystub(c, 3, ret=r.getrandbits(32), side=side)}, nslots=0xc8 // 4 + 1)
    e.wbytes(me + 0x1377, mk(0).to_bytes(4, 'little'))
    e.w32(0x724960, r.getrandbits(32))
    e.w32(0x724964, r.getrandbits(32))
    e.w32(0x724954, r.getrandbits(32))
    return [me, F(r.choice([r.uniform(-9, 9), 0.0, _f(NAN)])), F(r.choice([r.uniform(-9, 9), 1.0, _f(NAN)])), r.choice([0, 0xffffff, 0x12345678, r.getrandbits(32)])]


S(0x6101b0, 'GUESS set render globals and call slot 0xc8 five times', 'thiscall', None, ret=None, gen=g6101b0, nan_heap=True, note='batch32116')
