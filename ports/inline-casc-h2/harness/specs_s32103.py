"""specs_s32103.py - h2 (Sonnet) batch 32103: three tier H float / SSE functions. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g515c70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x515950, 0, this=True, pop=0, side=_log('a'))
    hook_rec(c, 0x515d00, 0, this=True, pop=0, side=_log('b'))
    hook_rec(c, 0x523180, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('tail'))
    k = _f(e.r32(0x679540))
    inner = rnd(c, 0x60)
    e.w32(inner + 0x3c, r.choice([0, 0x1000, 0x1000, r.getrandbits(32)]))
    o = rnd(c, 0x20)
    e.w32(o + 8, inner)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=(o if r.random() < 0.8 else 0), this=True)})
    e.wbytes(so + 0x48, struct.pack('<f', r.uniform(0, 0.2)))
    me = rnd(c, 0x240)
    e.wbytes(me + 0x133, bytes([r.choice([0, 0, 0, 1])]))
    ch = rnd(c, 0x60)
    e.wbytes(ch + 0x46, bytes([r.choice([0, 1, 1])]))
    e.w32(me + 0x5c, ch)
    fv = r.choice([k + 0.5, k + 1e-3, k, k - 0.5, 0.0, -1.0, 5.0, _f(NAN)])
    e.wbytes(me + 0x233, struct.pack('<f', fv))
    return [me]


def g4703b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x40, r.randrange(0, 100000))
    o = obj(c, 0x20, {0x338: pystub(c, 0, this=True, st0=struct.unpack('<f', struct.pack('<f', r.uniform(-100, 100)))[0], side=_log('f'))}, nslots=0x338 // 4 + 1)
    me = obj(c, 0xe0, {0x358: pystub(c, 1, this=True, side=_log('a')), 0x350: pystub(c, 0, ret=o, this=True, side=_log('b'))}, nslots=0x358 // 4 + 1)
    return [me]


def g597e90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = _f(e.r32(0x67a6ac))
    hook_rec(c, 0x593f40, 1, this=True, pop=4, side=_log('a'))
    hook_rec(c, 0x594040, 2, this=True, pop=8, ret=r.getrandbits(32), side=_log('c'))
    hook_rec(c, 0x596d70, 2, this=True, pop=8, ret=r.getrandbits(32), side=_log('d'))
    fv = struct.unpack('<f', struct.pack('<f', r.choice([k + 1.0, k - 1.0, k, r.uniform(-5, 5), 0.0])))[0]
    so = sysobj(c, slots={0x1c0: pystub(c, 2, this=True, st0=fv, side=_log('b'))})
    me = rnd(c, 0x1d20)
    e.wbytes(me + 0x1d0b, rnd(c, 0x20).to_bytes(4, 'little'))
    return [me]


S(0x515c70, 'GUESS decay timer and fire follow-ups', 'thiscall', None, ret=None, gen=g515c70, nan_heap=True, note='batch32103')
S(0x4703b0, 'GUESS compute float field from slots and time', 'thiscall', None, ret=None, gen=g4703b0, note='batch32103')
S(0x597e90, 'GUESS init sequence with random threshold', 'thiscall', None, ret='eax', gen=g597e90, note='batch32103')
