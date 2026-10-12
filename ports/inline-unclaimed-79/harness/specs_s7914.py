"""specs_s7914.py - unclaimed-79 batch 14 (docs/20-unclaimed-79.md, gap band): (GUESS) 0x481260. p's dword is zero about a quarter of
the time. The object at this+0x14 has slot +4 that logs its argument and returns a fresh record block."""
from pilot import S, F
from helpers_trial import logged_slot


def _blk(c, n=0x200):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    self_ = _blk(c)
    p = _blk(c, 0x40)
    if c.rng.random() < 0.25:
        c.emu.w32(p, 0)
    rec = _blk(c, 0x40)
    vt = c.emu.fake_vtable('Guess481260-obj', 0x10, {0x4: logged_slot('Guess::slot4', eax=rec, argbytes=4)})
    obj = _blk(c, 0x40)
    c.emu.w32(obj, vt)
    c.emu.w32(self_ + 0x14, obj)
    delta = c.rng.choice([0.0, 1.5, -2.25, c.rng.uniform(-4, 4)])
    import struct
    dbits = struct.unpack('<f', struct.pack('<f', delta))[0]
    return [self_, p, c.rng.getrandbits(32), F(dbits)]


S(0x481260, '(GUESS) 0x481260 thiscall', 'thiscall', None, ret=None, gen=_f,
  note='unclaimed-79 batch 14 (GUESS name); conditional float update and record store through slot +4 result')
