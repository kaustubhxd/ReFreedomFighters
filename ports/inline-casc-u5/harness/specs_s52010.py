"""specs_s52010.py - tier H. 0x611820: this[0x115f] bit 0, the flag byte and v around 0x800 (0, 0x7ff, 0x800, 0x801, large) steer the three paths; device objects at 0x724a00 and [this+0x1377] (unaligned) have stdcall recorder slots 0xfc, 0xc8 and 0x94 (matrix by content); X = [[engine+0x1aa3]+0x14] slot 4 returns an object or 0; 0x60d840 / 0x60d8e0 return random st0 floats; 0x60feb0 is a custom recorder (ECX, EDX, two args); the real CRT float-to-int helper and 0x609a70 run."""
import struct
from pilot import S, EDGE_F, F
import recruits_util
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _f(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _g611820(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))

    def h(em, rr):
        em.calllog.append(('60feb0', em.reg('ecx'), em.reg('edx'), em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)
    e.hook(0x60feb0, h)
    recruits_util._HOOKED.add(0x60feb0)
    a = r.choice([0.0, 1.0, -1.0, 7.5, _f(r.uniform(-20, 20)), _f(r.uniform(-1, 1))])
    b = r.choice([0.0, 1.0, -1.0, 7.5, _f(r.uniform(-20, 20)), _f(r.uniform(-1, 1))])
    hook_rec(c, 0x60d840, 0, this=True, pop=0, st0=a)
    hook_rec(c, 0x60d8e0, 0, this=True, pop=0, st0=b)
    so = sysobj(c)
    s = rnd(c, 0x20) if r.random() < 0.7 else 0
    X = obj(c, 0x20, {4: pystub(c, 2, this=True, ret=s)}, nslots=0x10)
    Xo = rnd(c, 0x40)
    e.w32(Xo + 0x14, X)
    e.wbytes(so + 0x1aa3, Xo.to_bytes(4, 'little'))
    dev = obj(c, 0x20, {0xfc: pystub(c, 4), 0xc8: pystub(c, 3)}, nslots=0x100 // 4)
    e.w32(0x724a00, dev)
    D = obj(c, 0x20, {0xfc: pystub(c, 4), 0x94: pystub(c, 3, deref={2: 16})}, nslots=0x100 // 4)
    me = obj(c, 0x1400, {0x2a0: pystub(c, 3, this=True)}, nslots=0x2a4 // 4)
    e.wbytes(me + 0x115f, bytes([r.choice([0, 1, 1, 1, 3, r.getrandbits(8)])]))
    e.wbytes(me + 0x1377, D.to_bytes(4, 'little'))
    on = r.choice([0, 1, 1, 1, r.getrandbits(8)])
    v = r.choice([0, 0x7ff, 0x800, 0x801, 0x1000, 0x12345, 1, 5, r.getrandbits(32)])
    f = r.choice([0.0, 1.0, 0.5, 0.004, _f(r.uniform(0, 2)), _f(r.uniform(-1, 3)), 3.0e9])
    return [me, on, v, F(f), r.getrandbits(32)]


S(0x611820, 'GUESS overlay toggle through devices', 'thiscall', None, ret=None, gen=_g611820, note='batch52010')
