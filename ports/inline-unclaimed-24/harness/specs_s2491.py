"""specs_s2491.py - decomp area 24, batch 2491 (residue 3, smallest first).
0x574e30 (GUESS, ZBaseMap draw wrapper): thiscall, ret 8. Byte +0x88: DrawUpdate 0x573930 (recorder, thiscall, 2 args, callee pops 8)
with (cam, id); when id == 2 and byte +0x21b is set, helper 0x574ff0 (recorder, thiscall, no argument).
0x56fa70 (GUESS, CNewMenu window close): thiscall, ret 8. OnWindowClose 0x562e90 (recorder, thiscall, 2 args, pops 8) with (a, b);
when the low byte of b is set, GetStartZone 0x56f2d0 (recorder, thiscall, no argument, returns a fixed dword), byte +0x1ed = 0; always
byte +0x196 = 0.
0x4b0df0 (GUESS): thiscall, ret 8. Dword at system +0x40 copied to this+0x50 unless aliased; when the dword at system +0x1a9f is nonzero,
dword +0x60 = 0, byte +0x6c = 0 and float +0x68 = 0 - (float +0x64 * 0)."""
import struct
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks, hook_rec


def _fbits(r):
    return struct.unpack('<I', struct.pack('<f', r.uniform(-10.0, 10.0)))[0]


def _draw(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x573930, 2, this=True)
    hook_rec(c, 0x574ff0, 0, this=True)
    o = rnd(c, 0x240)
    e.wbytes(o + 0x88, bytes([r.choice([0, 1])]))
    e.wbytes(o + 0x21b, bytes([r.choice([0, 1])]))
    return [o, r.getrandbits(32), r.choice([0, 1, 2, 3])]


def _close(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x562e90, 2, this=True)
    hook_rec(c, 0x56f2d0, 0, this=True, ret=r.getrandbits(32))
    o = rnd(c, 0x200)
    return [o, r.getrandbits(32), r.getrandbits(32)]


def _copy(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x40, r.getrandbits(32))
    e.w32(so + 0x1a9f, r.choice([0, 1, 0x100]))
    o = rnd(c, 0x100)
    e.w32(o + 0x50, r.getrandbits(32))
    e.w32(o + 0x60, r.getrandbits(32))
    e.wbytes(o + 0x6c, bytes([r.getrandbits(8)]))
    e.w32(o + 0x64, _fbits(r))
    e.w32(o + 0x68, _fbits(r))
    return [o, r.getrandbits(32), r.getrandbits(32)]


S(0x574e30, 'GUESS ZBaseMap draw wrapper', 'thiscall', None, ret=None, gen=_draw, note='batch2491')
S(0x56fa70, 'GUESS CNewMenu window close', 'thiscall', None, ret=None, gen=_close, note='batch2491')
S(0x4b0df0, 'GUESS copy and clear', 'thiscall', None, ret=None, gen=_copy, note='batch2491')
