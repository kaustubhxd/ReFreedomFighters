"""specs_s213081.py - batch 213081: direction clamp with CRT trig calls, Sonnet-w3b."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S, F
from recruits_util import rnd, clear_hooks, hook_rec

NAN = float('nan')


def crt(c, addr, fn, name):
    def side(em, k):
        a = em.reg('xmm0') & ((1 << 64) - 1)
        x = struct.unpack('<d', struct.pack('<Q', a))[0]
        em.calllog.append((name, a))
        try:
            z = fn(x)
        except (ValueError, OverflowError):
            z = math.nan
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    hook_rec(c, addr, 0, side=side)


def g4e1f00(c):
    clear_hooks(c)
    r = c.rng
    crt(c, 0x634d70, math.cos, 'cos')
    crt(c, 0x634d76, math.sin, 'sin')
    crt(c, 0x634d7c, math.sqrt, 'sqrt')
    crt(c, 0x634dbe, math.acos, 'acos')
    crt(c, 0x634de2, math.atan, 'atan')

    def comp():
        return r.choice([0.0, -0.0, 1.0, -1.0, 0.5, -0.5, 2.0, r.uniform(-1, 1), r.uniform(-1, 1), r.uniform(-1, 1), r.uniform(-9, 9), NAN, 1e-30, float('inf')])
    mode = r.random()
    if mode < 0.15:
        vec = (0.0, 0.0, 0.0)
    elif mode < 0.3:
        vec = (comp(), comp(), r.choice([0.0, 1.0, -1.0, 0.999, -0.999, 2.0, -2.0, 0.5, comp()]))
    else:
        vec = (comp(), comp(), comp())
    v = rnd(c, 0x10)
    c.emu.wbytes(v, struct.pack('<fff', *vec))
    out = 0 if r.random() < 0.15 else rnd(c, 8)

    def sc():
        return r.choice([1.0, 2.0, 0.5, 0.0, -1.0, 3.0, r.uniform(0.1, 5), r.uniform(-3, 3), 1e-30, NAN])
    args = [F(sc()), F(sc()), F(sc()), F(sc())]
    if r.random() < 0.1:
        # exact equality of the limit and the radius: z = -1 gives thr = pi, x = y = 0 gives r = |a|
        c.emu.wbytes(v, struct.pack('<fff', 0.0, 0.0, -1.0))
        pif = struct.unpack('<f', struct.pack('<f', math.pi))[0]
        args[0] = F(r.choice([pif, pif, struct.unpack('<f', struct.pack('<I', struct.unpack('<I', struct.pack('<f', pif))[0] + 1))[0],
                              struct.unpack('<f', struct.pack('<I', struct.unpack('<I', struct.pack('<f', pif))[0] - 1))[0]]))
    return [v, out] + args


S(0x4e1f00, 'direction_clamp', 'fastcall', None, ret='eax', gen=g4e1f00)
