"""specs_s32109.py - h2 () batch 32109: three tier H float / SSE functions. Callees/slots are recorders; order pinned with calllog."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g4f72c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = r.getrandbits(32)
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=(a if r.random() < 0.7 else r.getrandbits(32)), this=True)})
    me = obj(c, 0xb0, {0x388: pystub(c, 1, ret=r.choice([0, 5, 1000, 0xfffffff0, r.getrandbits(32)]), this=True, side=_log('n')),
                       0x374: pystub(c, 1, this=True, side=_log('x'))}, nslots=0x388 // 4 + 1)
    e.wbytes(me + 0x8f, r.choice([0, 1, r.getrandbits(32)]).to_bytes(4, 'little'))
    e.wbytes(me + 0x9f, struct.pack('<f', r.choice([0.0, 3.7, -3.7, 100.0, 1e9, -1e9, _f(NAN)])))
    return [me, a, F(r.choice([0.5, 2.0, -1.0, 0.0, _f(NAN)]))]


def g520bb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill(emu, k):
        base = emu.arg32(0)
        for i in range(4):
            emu.w32(base + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x5233a0, 2, this=True, pop=8, nullflag=(0,), side=fill)
    hook_rec(c, 0x521600, 1, this=True, pop=4, deref={0: 4}, side=lambda emu, k: emu.calllog.append(('use', emu.r32(emu.reg('ecx') + 0x216))))
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    vt = e.alloc(0x20, 4)
    e.w32(vt, pystub(c, 3, this=True, side=_log('emb')))
    me = rnd(c, 0x26a0)
    e.wbytes(me + 0x2695, vt.to_bytes(4, 'little'))
    e.w32(me + 0x5c, rnd(c, 0x20))
    return [me, F(r.choice([r.uniform(-9, 9), _f(NAN), 0.0])), r.choice([0, 1, 0x1ff, r.getrandbits(32)])]


def g5295d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5168b0, 0, this=True, pop=0, side=_log('r'))
    me = rnd(c, 0x2400)
    e.wbytes(me + 0x68, struct.pack('<f', r.choice([0.0, 50.0, 100.0, 100.5, 250.0, 1000.0, _f(NAN)])))
    e.wbytes(me + 0x6c, struct.pack('<f', r.choice([0.0, 49.0, 50.0, 51.0, 200.0, _f(NAN)])))
    e.w32(me + 0x22c0, r.choice([0, 1, 2, 4, 0xffffffff, 0x80000000]))
    return [me]


S(0x4f72c0, 'GUESS apply scaled delta when ids match', 'thiscall', None, ret='al', gen=g4f72c0, note='batch32109')
S(0x520bb0, 'GUESS store parameters, build record, apply (GS frame)', 'thiscall', None, ret=None, gen=g520bb0, nan_heap=True, note='batch32109')
S(0x5295d0, 'GUESS update step for each record', 'thiscall', None, ret=None, gen=g5295d0, nan_heap=True, note='batch32109')
