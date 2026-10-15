"""specs_s32117.py - h2 (Sonnet) batch 32117: tier H functions. Imports are stubs written into the IAT slot; slots/callees are recorders; the 0x4de420 copy runs as exe code."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g654940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    seq = [r.getrandbits(32), r.getrandbits(32)]
    e.w32(0x676244, pystub(c, 1, ret=lambda emu, k: seq[min(k, 1)], side=_log('dec')))
    e.w32(0x67621c, pystub(c, 4, ret=r.getrandbits(32), deref={2: 15}, side=_log('send')))
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    me = rnd(c, 0x140)
    return [me, rnd(c, 0x30), rnd(c, 0x10), rnd(c, 0x10)]


def g485f90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x467410, 6, this=True, pop=0x18, side=_log('big'))
    s = obj(c, 0x20, {0x2d0: pystub(c, 2, this=True, side=_log('s'))}, nslots=0x2d0 // 4 + 1)
    m = obj(c, 0x20, {0x10: pystub(c, 0, ret=s, this=True, side=_log('m10')), 8: pystub(c, 2, this=True, side=_log('m8'))})
    o = obj(c, 0x20, {0x4f4: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('o'))}, nslots=0x4f4 // 4 + 1)
    me = rnd(c, 0x20)
    e.w32(me + 8, o)
    e.w32(me + 0xc, m)
    return [me]


def g5230e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fv = struct.unpack('<f', struct.pack('<f', r.uniform(-9, 9)))[0]
    me = obj(c, 0x70, {0x24: pystub(c, 2, this=True, st0=fv, side=_log('g')), 8: pystub(c, 2, this=True, side=_log('s'))}, nslots=0x24 // 4 + 1)
    e.wbytes(me + 0x41, bytes([r.choice([0, 1, 1, 1])]))
    e.w32(me + 0x39, r.choice([1, 1, 1, 0, 2, 0xffffffff]))
    e.wbytes(me + 0x5f, struct.pack('<f', r.choice([0.0, r.uniform(0.01, 5), -1.0, _f(NAN)])))
    f24 = r.uniform(-5, 5)
    e.wbytes(me + 0x24, struct.pack('<f', f24))
    k = _f(e.r32(0x67a6ac))
    # make the computed g sometimes equal the threshold exactly
    x2 = struct.unpack('<f', bytes(e.rbytes(me + 0x5f, 4)))[0]
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    thr = r.choice([r.uniform(-1, 20), 0.0, _f(NAN)])
    if x2 not in (0.0,) and x2 == x2:
        g = f32(f32(f32(f24 * f24) / x2) * k)
        thr = r.choice([thr, g, g, f32(g - 1e-3)])
    e.wbytes(me + 0x30, struct.pack('<f', thr))
    return [me]


S(0x654940, 'GUESS send 15-dword record message through decoded handle', 'thiscall', None, ret=None, gen=g654940, note='batch32117')
S(0x485f90, 'GUESS reset sub-object and notify owner', 'thiscall', None, ret='eax', gen=g485f90, note='batch32117')
S(0x5230e0, 'GUESS advance state when threshold reached', 'thiscall', None, ret=None, gen=g5230e0, nan_heap=True, note='batch32117')
