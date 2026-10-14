"""specs_s34157.py - tier H. 0x4ddfa0: register args ecx = A, edx = B (3 floats each), hooked fastcall 0x43e920 (ecx, edx logged, the stack-local vector logged through deref). 0x54f150: three floats (equal / above / below within and beyond the tolerance), st0 result. 0x5a5ca0: floats at the +0x40/+0x44/+0x48 of the child at +8 (NaN edge cases), hooked 0x43df70, 0x4dd060 (vector logged) and the /GS check."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r, center=None):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    elif center is not None and k < 0.5:
        v = center + r.choice([0.0, 1e-6, -1e-6, 0.01, -0.01, 1.0, -1.0, 0.5])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _g4ddfa0(c):
    clear_hooks(c)
    r = c.rng

    def log_edx(em, k):
        em.calllog.append(('edx', em.reg('edx')))
    hook_rec(c, 0x43e920, 1, this=True, deref={0: 3}, side=log_edx, ret=r.getrandbits(32))
    A, B = rnd(c, 0x10), rnd(c, 0x10)
    for i in range(3):
        c.emu.w32(A + 4 * i, _fbits(r))
        c.emu.w32(B + 4 * i, _fbits(r))
    return [A, B]


def _g54f150(c):
    clear_hooks(c)
    r = c.rng
    base = r.uniform(-100, 100)
    tol = abs(r.choice([0.0, 0.5, 1.0, 10.0, r.uniform(0, 50)]))
    if r.random() < 0.3:   # exact integers: a - b == c exactly in both directions
        base = float(r.randint(-100, 100))
        tol = float(r.randint(0, 20))
    k = r.random()
    if k < 0.15:
        a = b = _fbits(r)
    else:
        b = struct.unpack('<I', struct.pack('<f', base))[0]
        d = r.choice([0.0, tol, tol * 0.5, tol * 2 + 1.0, tol + 1e-3, -tol, -tol * 2 - 1.0, r.uniform(-120, 120)])
        a = struct.unpack('<I', struct.pack('<f', base + d))[0]
        if r.random() < 0.1:
            a, b = _fbits(r), _fbits(r)
    cb = struct.unpack('<I', struct.pack('<f', tol))[0] if r.random() < 0.85 else _fbits(r)
    return [a, b, cb]


def _g5a5ca0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43df70, 0, this=True, pop=0)
    hook_rec(c, 0x4dd060, 1, this=True, deref={0: 3}, ret=r.getrandbits(32))
    hook_rec(c, 0x633654, 0, pop=0)
    o = rnd(c, 0x60)
    for off in (0x40, 0x44, 0x48):
        c.emu.w32(o + off, _fbits(r))
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, o)
    return [me]


S(0x4ddfa0, 'GUESS project vector', ('regs', ['ecx', 'edx']), None, ret=None, gen=_g4ddfa0, note='batch34157')
S(0x54f150, 'GUESS move toward with tolerance', 'stdcall', None, ret='st0', gen=_g54f150, note='batch34157')
S(0x5a5ca0, 'GUESS set max-derived vector', 'thiscall', None, ret=None, gen=_g5a5ca0, note='batch34157')
