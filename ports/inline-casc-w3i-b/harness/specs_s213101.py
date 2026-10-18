"""specs_s213101.py - batch 213101: 3x3 matrix rotated by three euler angles (CRT sin/cos), Sonnet-w3b."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S
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


def g4dec90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    crt(c, 0x634d70, math.cos, 'cos')
    crt(c, 0x634d76, math.sin, 'sin')
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def mv():
        return f32(r.choice([0.0, 1.0, -1.0, 0.5, -0.5, 2.0, 3.0, r.uniform(-1, 1), r.uniform(-1, 1), r.uniform(-1, 1), r.uniform(-9, 9), 1e-30, -2.5]))

    def ang():
        return f32(r.choice([0.0, math.pi / 2, math.pi, -math.pi / 2, 1.0, -1.0, 0.5, 2.0, r.uniform(-4, 4), r.uniform(-4, 4), r.uniform(-4, 4), 100.0, 1e-6]))
    m = e.alloc(0x24, 4)
    mode = r.random()
    if mode < 0.15:
        vals = [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0]
    else:
        vals = [mv() for _ in range(9)]
    if r.random() < 0.02:
        vals[r.randrange(9)] = NAN
    e.wbytes(m, struct.pack('<9f', *vals))
    a = e.alloc(12, 4)
    angs = [ang(), ang(), ang()]
    if r.random() < 0.3:
        angs[r.randrange(3)] = 0.0
    if r.random() < 0.02:
        angs[r.randrange(3)] = NAN
    e.wbytes(a, struct.pack('<3f', *angs))
    return [m, a]


S(0x4dec90, 'euler_rotate_matrix', 'fastcall', None, ret=None, gen=g4dec90)
