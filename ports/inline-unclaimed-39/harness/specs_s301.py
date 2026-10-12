"""specs_s301.py - decomp area 39 (docs/20-unclaimed-39.md): 0x5266e0 loops over two child lists, calling exe 0x5166e0 and 0x52a1a0."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _track(c):
    obj = _rnd(c, 0x2000)
    # Counts are signed; -1 and 0 take the skip path (jle). Keep them small so the object covers every child record.
    c.emu.w32(obj + 0x8c, (c.rng.getrandbits(3) % 6 - 1) & 0xffffffff)
    c.emu.w32(obj + 0x90, (c.rng.getrandbits(3) % 6 - 1) & 0xffffffff)
    t = c.rng.uniform(-50.0, 50.0) if c.rng.random() < 0.8 else c.rng.getrandbits(32) / 2 ** 32
    t_bits = struct.unpack('<I', struct.pack('<f', t))[0]
    return [obj, t_bits]


S(0x5266e0, 'trackUpdate (GUESS)', 'thiscall', None, ret=None, gen=_track,
  note='batch301; one float stack arg t; ret 4; two child-record loops over exe 0x5166e0 and 0x52a1a0')
