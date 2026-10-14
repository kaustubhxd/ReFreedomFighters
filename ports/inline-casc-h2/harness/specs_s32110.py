"""specs_s32110.py - h2 () batch 32110: three tier H float / SSE functions. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g5c30c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5c3560, 2, this=True, pop=8, side=_log('t'))
    so = sysobj(c)
    e.w32(so + 0x40, r.randrange(0, 100000))
    me = obj(c, 0x120, {0x64: pystub(c, 1, this=True, side=_log('a')), 0x68: pystub(c, 2, this=True, side=_log('b'))}, nslots=0x68 // 4 + 1)
    w1 = r.getrandbits(16)
    w2 = r.choice([w1, r.getrandbits(16)])
    e.wbytes(me + 0xf5, w1.to_bytes(2, 'little'))
    e.wbytes(me + 0xf7, w2.to_bytes(2, 'little'))
    e.wbytes(me + 0xf9, bytes([r.choice([0, 1, 1])]))
    a = r.choice([w1, w2, r.getrandbits(16), r.getrandbits(32)])
    return [me, a, r.getrandbits(32)]


def g4a7fb0(c):
    clear_hooks(c)
    r = c.rng
    ints = [r.choice([0, 1, r.getrandbits(32)]) for _ in range(4)]
    fl = [_f(struct.unpack('<I', struct.pack('<f', r.uniform(-100, 100)))[0]) for _ in range(2)]
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda emu, k: ints[min(k, 3)], side=_log('i'))
    hook_rec(c, 0x4e5e40, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('w'))
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda emu, k: fl[min(k, 1)], side=_log('f'))
    hook_rec(c, 0x4e6180, 1, this=True, pop=4, side=_log('v'))
    return [rnd(c, 0x90), rnd(c, 0x20)]


def g4f70f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    o = obj(c, 0x20, {0xb8: pystub(c, 1, this=True, side=_log('a')), 0xac: pystub(c, 2, this=True, side=_log('b'))}, nslots=0xb8 // 4 + 1)
    e.wbytes(so + 0x190f, o.to_bytes(4, 'little'))
    rr = obj(c, 0x20, {0x32c: pystub(c, 1, this=True, side=_log('c'))}, nslots=0x32c // 4 + 1)
    me = obj(c, 0xb0, {0x2c4: pystub(c, 0, ret=rr, this=True), 0x358: pystub(c, 1, this=True, side=_log('d')),
                       0x370: pystub(c, 0, ret=r.getrandbits(32), this=True, side=_log('e'))}, nslots=0x370 // 4 + 1)
    p = rnd(c, 0x60)
    e.w32(p + 0x4c, r.choice([0, 1, 100, 0xffffff00, r.randrange(0, 5000), r.getrandbits(32)]))
    e.wbytes(me + 0x93, (p if r.random() < 0.8 else 0).to_bytes(4, 'little'))
    e.wbytes(me + 0xa7, bytes([r.choice([0, 0, 1])]))
    return [me]


S(0x5c30c0, 'GUESS dispatch by word id and update timer', 'thiscall', None, ret='eax', gen=g5c30c0, note='batch32110')
S(0x4a7fb0, 'GUESS read record fields from source (variant)', 'thiscall', None, ret=None, gen=g4a7fb0, note='batch32110')
S(0x4f70f0, 'GUESS activate pending record through slots', 'thiscall', None, ret=None, gen=g4f70f0, note='batch32110')
