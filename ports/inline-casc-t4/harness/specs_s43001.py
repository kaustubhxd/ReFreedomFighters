"""specs_s43001.py - t4 (Sonnet) batch 43001: tier H float/SSE functions. 0x4b0f90: pow stubbed (logged), 0x4e5e80 hooked with float returns;
0x52a300: 0x52cea0 / 0x52cf60 hooked; 0x5272e0: object floats chosen around the K threshold."""
import struct
import math
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1


def _w(c):
    return c.rng.getrandbits(32)


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _fl(r):
    k = r.random()
    if k < 0.06:
        return r.choice([0.0, -0.0, float('nan'), float('inf'), float('-inf')])
    if k < 0.2:
        return r.uniform(-1e5, 1e5)
    return r.uniform(-20, 20)


def _g5272e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    dt = r.choice([0.016, 0.033, 0.0, r.uniform(0, 0.2), _fl(r)])
    e.w32(so + 0x48, _fb(dt))
    me = rnd(c, 0x40)
    k = struct.unpack('<f', e.rbytes(0x679540, 4))[0]
    v = r.choice([0.0, -0.0, r.uniform(-5, 5), r.uniform(-1, 1), _fl(r)])
    f10 = r.choice([1.0, r.uniform(-3, 3), _fl(r)])
    t = r.choice([0.0, r.uniform(-10, 10), _fl(r)])
    # position that lands near the target +-K after the step, in most cases
    step = dt * f10 * v
    if r.random() < 0.8 and math.isfinite(step):
        p4 = t - step + r.choice([-2, -1, -0.5, -0.1, 0, 0.1, 0.5, 1, 2]) * (k if math.isfinite(k) else 1.0) + r.choice([0, 0, 1e-4, -1e-4])
    else:
        p4 = _fl(r)
    e.w32(me + 4, _fb(p4))
    e.w32(me + 8, _fb(t))
    e.w32(me + 0x10, _fb(f10))
    e.w32(me + 0x14, _fb(v))
    return [me]


def _g52a300(c):
    clear_hooks(c)
    hook_rec(c, 0x52cea0, 1, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x52cf60, 1, this=True, ret=lambda em, k: _w(c))
    return [rnd(c, 0x100), _w(c)]


def _g4b0f90(c):
    clear_hooks(c)
    r = c.rng
    vals = [_fl(r) for _ in range(4)]
    if r.random() < 0.5:
        vals[3] = r.uniform(-300, 300)
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: struct.unpack('<f', struct.pack('<f', vals[k % 4]))[0] if math.isfinite(vals[k % 4]) else vals[k % 4])

    def pw(em, res_):
        b = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
        x = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
        em.calllog.append(('pow', struct.pack('<d', b), struct.pack('<d', x)))
        try:
            y = math.pow(b, x)
        except (ValueError, OverflowError, ZeroDivisionError):
            y = float('nan')
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', y))[0])
        em.ret()
    c.emu.stub_import('_libm_sse2_pow_precise', pw)
    return [rnd(c, 0x80), rnd(c, 0x20)]


S(0x5272e0, 'GUESS advance position and clamp at target', 'thiscall', None, ret=None, gen=_g5272e0, note='batch43001')
S(0x52a300, 'GUESS init three sub blocks then copy defaults', 'thiscall', None, ret='eax', gen=_g52a300, note='batch43001')
S(0x4b0f90, 'GUESS read three floats and pow based value', 'thiscall', None, ret=None, gen=_g4b0f90, note='batch43001')
