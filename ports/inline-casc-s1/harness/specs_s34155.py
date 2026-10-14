"""specs_s34155.py - tier H. 0x5186d0: float f1 (0.0 in a sixth), pow import stubbed in Python (xmm0 base, xmm1 exponent), logging both. 0x46d290: hooked 0x4e5e80 (st0 float) and 0x4e5e60 (eax 0 / non-zero). 0x4e7880: hooked 0x4e7ce0 / 0x4e7c50 (1 arg, ecx recorded). 0x535990: three floats around the 1.0 / b comparison."""
import math
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec
from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1


def _f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _fval(r):
    k = r.random()
    if k < 0.2:
        v = r.choice([x for x in EDGE_F if x == x])
    else:
        v = r.uniform(-1000, 1000)
    return _f32(v) if abs(v) < 3e38 or v != v else v


def _fbits(r, center=None):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    elif center is not None and k < 0.5:
        v = center + r.choice([0.0, 1e-6, -1e-6, 0.01, -0.01, 1.0, -1.0, 0.5, 2.0])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g5186d0(c):
    clear_hooks(c)
    r = c.rng

    def pw(em, res_):
        b = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
        e = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
        em.calllog.append(('pow', struct.pack('<d', b), struct.pack('<d', e)))
        try:
            y = math.pow(b, e)
        except (ValueError, OverflowError):
            y = float('nan')
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', y))[0])
        em.ret()
    c.emu.stub_import('_libm_sse2_pow_precise', pw)
    me = rnd(c, 0x1660)
    f1 = 0 if r.random() < 0.17 else (0x80000000 if r.random() < 0.05 else _fbits(r))
    return [me, f1, _fbits(r), r.getrandbits(32)]


def _g46d290(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda em, k: _fval(r))
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x80000000, r.getrandbits(32)]))
    return [rnd(c, 0x60), rnd(c, 0x20)]


def _g4e7880(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e7ce0, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4e7c50, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), _fbits(r)]


def _g535990(c):
    clear_hooks(c)
    r = c.rng
    b = _fbits(r, 1.0)
    bf = struct.unpack('<f', struct.pack('<I', b))[0]
    a = 0 if r.random() < 0.15 else (_fbits(r, bf) if bf == bf and abs(bf) < 1e30 else _fbits(r))
    return [a, b, _fbits(r)]


S(0x5186d0, 'GUESS store pow-scaled float', 'thiscall', None, ret=None, gen=_g5186d0, note='batch34155')
S(0x46d290, 'GUESS read three values from source', 'thiscall', None, ret=None, gen=_g46d290, note='batch34155')
S(0x4e7880, 'GUESS set up an entry', 'thiscall', None, ret=None, gen=_g4e7880, note='batch34155')
S(0x535990, 'GUESS score from three floats', 'stdcall', None, ret='eax', gen=_g535990, note='batch34155')
