"""specs_s32118.py - h2 (Sonnet) batch 32118: tier H functions. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g4a39c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slots = {0x64: pystub(c, 1, this=True, side=_log('a')), 0x68: pystub(c, 1, this=True, side=_log('b')),
             0x4c: pystub(c, 1, this=True, side=_log('c')), 0x3c: pystub(c, 1, this=True, side=_log('d'))}
    o = obj(c, 0x20, slots)
    me = rnd(c, 0x130)
    return [me, o]


def g519280(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    thr = _f(e.r32(0x69f198))
    dv = struct.unpack('<f', struct.pack('<f', r.choice([r.uniform(-1, 1), thr, -thr, thr * 1.0001, 0.0, 0.5, -3.0])))[0]
    hook_rec(c, 0x522f60, 2, this=True, pop=8, st0=dv, side=_log('g'))
    inner = rnd(c, 0x40)
    e.wbytes(inner + 0x24, struct.pack('<f', r.choice([r.uniform(-9, 9), 0.0, _f(NAN)])))
    me = rnd(c, 0x1620)
    e.w32(me + 0x5c, inner)
    e.wbytes(me + 0x358, struct.pack('<f', r.choice([0.0, -0.0, 1.0, _f(NAN)])))
    return [me]


def g5515f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    q = rnd(c, 0x20)
    r0, r1, r2 = rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10)
    seq = [r0, r1, r2]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: seq[min(k, 2)], side=_log('lk'))
    hook_rec(c, 0x500360, 1, this=True, pop=4, side=_log('f'))
    hook_rec(c, 0x5002f0, 1, this=True, pop=4, side=_log('i'))
    b = obj(c, 0x20, {0x4c: pystub(c, 0, ret=q, this=True, side=_log('q'))}, nslots=0x4c // 4 + 1)
    p = obj(c, 0x20, {0x18: pystub(c, 1, ret=(b if r.random() < 0.8 else 0), this=True, side=_log('b'))}, nslots=0x18 // 4 + 1)
    return [p, r.getrandbits(32), rnd(c, 0x10)]


S(0x4a39c0, 'GUESS clear bit 6, record fields through slots, true', 'thiscall', None, ret='al', gen=g4a39c0, note='batch32118')
S(0x519280, 'GUESS derive angle-based factor and flag', 'thiscall', None, ret=None, gen=g519280, nan_heap=True, note='batch32118')
S(0x5515f0, 'GUESS look up object and set three vector components (variant)', 'stdcall', None, ret='eax', gen=g5515f0, note='batch32118')
