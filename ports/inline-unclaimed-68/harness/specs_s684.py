"""specs_s684.py - unclaimed-68 batches 4 and 5 (claim 4): ZMoveOnSpline::SetPath (0x514430) and CSharedCom::SetVal (0x4d3cf0).
SetPath: the object's +0x5c is a block the callee 0x523cc0 writes into (original code, zeroed). SetVal: the name, the value
block and the count are random; 0x4d24e0 runs original code on the arguments, so the harness compares its effects as memory."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _engine(c):
    r = logged_obj(c, 'ZEngineResult', 0x200, impl={0x1e0: lambda e, a: (0, None)}, argwords={0x1e0: 1})
    en = logged_obj(c, 'ZEngineSet', 0x200, impl={0x58: lambda e, a: (r, None)}, argwords={0x58: 1})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    log = logged_obj(c, 'ZAssertLog2', 0x80, impl={}, argwords={})
    set_global(c, 0x700390, log)


def _setpath(c):
    _engine(c)
    o = zero_obj(c, 0x400)
    tgt = logged_obj(c, 'ZSplineTarget', 0x200, impl={}, argwords={})
    c.emu.w32(o + 0x5c, tgt)
    idx = c.rng.getrandbits(32)
    f = struct.unpack('<I', struct.pack('<f', c.fv(-100.0, 100.0)))[0]
    return [o, idx, f]


def _setval(c):
    name = c.emu.alloc(16, 4)
    c.emu.wbytes(name, bytes(c.rng.getrandbits(8) for _ in range(16)))
    n = c.rng.randrange(0, 5)
    vals = c.emu.alloc(max(4 * n, 4), 4)
    c.emu.wbytes(vals, bytes(c.rng.getrandbits(8) for _ in range(max(4 * n, 4))))
    _engine(c)
    obj = zero_obj(c, 0x400)
    return [obj, name, vals, n]


S(0x514430, 'ZMoveOnSpline::SetPath (unknown) thiscall', 'thiscall', None, ret=None, gen=_setpath,
  note='unclaimed-68 batch 4; forwards (index, float) to this+0x5c via 0x523cc0 (original)')
S(0x4d3cf0, 'CSharedCom::SetVal (unknown) thiscall', 'thiscall', None, ret=None, gen=_setval,
  note='unclaimed-68 batch 5; GUESS-level name (low); forwards to 0x4d24e0 (original, stdcall ret 0x10)')
