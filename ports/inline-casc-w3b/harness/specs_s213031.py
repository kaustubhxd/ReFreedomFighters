"""specs_s213031.py - batch 213031: little-endian pair string compare; easing curve with x87/SSE and pow hook, Sonnet-w3b."""
import struct, math
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S, F, EDGE_F
from recruits_util import rnd, clear_hooks, hook_rec


def g6253b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [5, 6, 7, 5, 6, 7, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1d, 8, 0x10, 0x14, 9, 0x15, 0x1c]
    tab = [(r.choice(hot) if r.random() < 0.8 else r.getrandbits(8)) for _ in range(256)]
    tab[0] = 0x10
    e.wbytes(base + 0x4c, bytes(tab))
    n = r.randint(0, 12)
    sa = bytearray()
    for _ in range(n):
        x = r.random()
        if x < 0.6:
            sa += bytes([r.choice([r.getrandbits(8), r.randint(1, 20)]) or 1, 0])
        elif x < 0.8:
            sa += bytes([r.choice([0xfc, 0xfd, 0xfe, 0xff, r.getrandbits(8)]), r.randint(0xd8, 0xff)])
        else:
            sa += bytes(r.getrandbits(8) for _ in range(2))
    sb = bytearray(sa)
    for i in range(len(sb)):
        if r.random() < 0.05:
            sb[i] = r.getrandbits(8)
    ta = bytes(2)
    tb = bytes(2) if r.random() < 0.6 else bytes(r.getrandbits(8) for _ in range(2))
    if r.random() < 0.1:
        ta = bytes(r.getrandbits(8) for _ in range(2))
    a = bytes(sa) + ta + bytes(40)
    b = bytes(sb) + tb + bytes(40)
    pa = rnd(c, len(a))
    pb = rnd(c, len(b))
    e.wbytes(pa, a)
    e.wbytes(pb, b)
    return [base, pa, pb]


def g662940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def power(em, k):
        a = em.reg('xmm0') & ((1 << 64) - 1)
        b = em.reg('xmm1') & ((1 << 64) - 1)
        em.calllog.append(('pow', a, b))
        x = struct.unpack('<d', struct.pack('<Q', a))[0]
        y = struct.unpack('<d', struct.pack('<Q', b))[0]
        try:
            z = math.pow(x, y)
        except OverflowError:
            z = math.inf
        except ValueError:
            z = math.nan
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    hook_rec(c, 0x634db2, 0, side=power)
    this = rnd(c, 0x30)
    n = r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 12, r.randint(6, 100), r.getrandbits(32), 0x80000000, 0xffffffff, 0x80000001])
    e.wbytes(this + 0x15, struct.pack('<I', n))
    t = r.choice([r.uniform(0, 1), r.uniform(-2, 2), 0.0, 1.0, 0.5, -0.5, r.uniform(0, 1), r.uniform(0, 1)])
    return [this, F(t)]


S(0x6253b0, 'wide_le_string_equal', 'cdecl', None, ret='eax', gen=g6253b0)
S(0x662940, 'ease_curve', 'thiscall', None, ret='st0', gen=g662940)
