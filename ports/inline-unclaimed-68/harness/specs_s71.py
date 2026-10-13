"""specs_s71.py - unclaimed-68 batch 71 (slice 7). Names GUESS (FUN_addr).
0x4d7530 / 0x5eeb30 / 0x650fb0 store the one stack argument (dword / dword / byte); 0x64a6b0 copies the dword at [[0x70039c]+0x3c]
to this+0x1829d; 0x4aff30 forwards its second argument to this's slot +0x84 and returns that result; 0x4d1db0 calls slot +0x3c
with its argument and returns the double at the pointer it gets back (ST0)."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _ob(c, size=0x100):
    o = zero_obj(c, size)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return o


def _setter(c):
    return [_ob(c), c.rng.getrandbits(32)]


def _g64a6b0(c):
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x3c, c.rng.getrandbits(32))
    set_global(c, 0x70039c, eng)
    o = zero_obj(c, 0x18400)
    return [o, c.rng.getrandbits(32)]


def _g4aff30(c):
    vt_ret = c.rng.getrandbits(32)
    o = zero_obj(c, 0x100)
    vt = c.emu.logging_vtable('FwdObj71', 0x90, impl={0x84: (lambda v: (lambda e, a: (v, None)))(vt_ret)},
                              argwords={0x84: 1})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g4d1db0(c):
    p = c.emu.alloc(16, 8)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(16)))
    o = zero_obj(c, 0x100)
    vt = c.emu.logging_vtable('DblObj71', 0x90, impl={0x3c: (lambda v: (lambda e, a: (v, None)))(p)}, argwords={0x3c: 1})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32)]


S(0x4d7530, 'FUN_4d7530 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_setter, note='unclaimed-68 batch 71: dword this+0xd = arg')
S(0x5eeb30, 'FUN_5eeb30 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_setter, note='unclaimed-68 batch 71: dword this+0x56 = arg')
S(0x650fb0, 'FUN_650fb0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_setter, note='unclaimed-68 batch 71: byte this+0x82 = arg')
S(0x64a6b0, 'FUN_64a6b0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g64a6b0,
  note='unclaimed-68 batch 71: dword this+0x1829d = [[0x70039c]+0x3c]')
S(0x4aff30, 'FUN_4aff30 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g4aff30,
  note='unclaimed-68 batch 71: returns vt slot +0x84 (arg2)')
S(0x4d1db0, 'FUN_4d1db0 (GUESS) thiscall', 'thiscall', None, ret='st0', gen=_g4d1db0,
  note='unclaimed-68 batch 71: double at vt slot +0x3c result, ST0')
