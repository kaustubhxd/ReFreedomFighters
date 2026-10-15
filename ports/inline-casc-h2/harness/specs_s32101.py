"""specs_s32101.py - h2 (Sonnet) batch 32101: three tier H float / SSE functions. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _fbits(c, lo=-5, hi=5):
    r = c.rng
    return r.choice([_fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), NAN, 0x7f800000, 0xff800000, 0, 0x80000000])


def g475a20(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4658d0, 1, this=True, pop=4, side=_log('a'))
    hook_rec(c, 0x467aa0, 3, this=True, pop=0xc, side=_log('b'))
    hook_rec(c, 0x4678e0, 4, this=True, pop=0x10, side=_log('c'))
    hook_rec(c, 0x467b00, 2, this=True, pop=8, side=_log('d'))
    hook_rec(c, 0x466600, 1, this=True, pop=4, ret=r.getrandbits(32), side=_log('e'))
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), F(c.fv(-10, 10)),
            r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g4f1000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = 255.0
    p = rnd(c, 0x10)
    for i in range(3):
        v = r.choice([r.uniform(0, k), r.uniform(0, k), k, 0.0, r.uniform(-k, 2 * k), _f(NAN), r.uniform(0, k) * 1.0001, 1e-3, float(r.randrange(0, 256)), float(r.randrange(0, 256)), float(r.randrange(0, 256))])
        e.wbytes(p + 4 * i, _fb(v).to_bytes(4, 'little'))
    me = obj(c, 0x20, {0x248: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x248 // 4 + 1)
    return [me, p]


def g5b7eb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0x64: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('i')),
                      0x4c: pystub(c, 1, this=True, side=_log('f'))}, nslots=0x64 // 4 + 1)
    me = rnd(c, 0x20)
    e.wbytes(me + 4, _fbits(c, -9, 9).to_bytes(4, 'little'))
    e.wbytes(me + 8, _fbits(c, -9, 9).to_bytes(4, 'little'))
    return [me, o]


S(0x475a20, 'GUESS set up sub-object via five calls', 'thiscall', None, ret='eax', gen=g475a20, note='batch32101')
S(0x4f1000, 'GUESS pack float rgb into packed int slot 0x248', 'thiscall', None, ret='eax', gen=g4f1000, note='batch32101')
S(0x5b7eb0, 'GUESS apply record through slots', 'thiscall', None, ret='eax', gen=g5b7eb0, note='batch32101')
