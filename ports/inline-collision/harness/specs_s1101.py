"""specs_s1101.py - collision thread batch 1101: 0x4eb100 solve3 (Cramer), 0x4eaf10 random unit vector,
0x4e9780 sphere vs segment. The engine's random-float slot 0x1c0 of [0x70039c] is a Python stub returning a
per-case sequence in ST0 (logged with its args)."""
import struct
from pilot import S, F

EPS = 1e-6


def _vec(c, n, lo, hi, edge=0.05):
    a = c.emu.alloc(4 * n + 0x10, 4)
    for i in range(n + 4):
        c.emu.wf32(a + 4 * i, c.fv(lo, hi, edge))
    return a


def _sys(c):
    """[0x70039c] = an object whose slot 0x1c0 returns the next float of a per-case sequence."""
    r = c.rng
    seq = []
    for _ in range(r.choice([1, 1, 1, 2, 3])):
        k = r.random()
        if k < 0.25:
            seq += [0.5, 0.5, 0.5]                       # zero vector: the loop runs again
        elif k < 0.4:
            seq += [0.5 + r.choice([1, -1]) * r.uniform(0, 1e-6) for _ in range(3)]   # near the 1e-6 edge
        else:
            seq += [r.random() for _ in range(3)]
    seq += [r.random() for _ in range(3)]
    state = {'i': 0}

    def rnd(e, args):
        i = state['i']
        state['i'] = i + 1
        return None, seq[i] if i < len(seq) else 0.25 + 0.001 * i
    vt = c.emu.logging_vtable('sys', 0x1d0 // 4, impl={0x1c0: rnd}, argwords={0x1c0: 2})
    o = c.emu.alloc(0x40, 4)
    c.emu.w32(o, vt)
    c.emu.w32(0x70039c, o)
    c.emu._image_dirty = True
    return o


def _solve(c):
    r = c.rng
    m = _vec(c, 9, -3.0, 3.0)
    if r.random() < 0.25:     # (nearly) singular: row 2 = row 0 + row 1 (+ tiny)
        for j in range(3):
            v = c.emu.rf32(m + 4 * j) + c.emu.rf32(m + 12 + 4 * j)
            c.emu.wf32(m + 24 + 4 * j, v + (r.uniform(-1e-4, 1e-4) if r.random() < 0.5 else 0.0))
    if r.random() < 0.15:     # diag(d, 1, 1) with d within a few ulps of 1e-6, so det sits on the edge
        for j in range(9):
            c.emu.wf32(m + 4 * j, 0.0)
        d = struct.unpack('<f', struct.pack('<I', 0x358637bd + r.randint(-3, 3)))[0]
        c.emu.wf32(m, d if r.random() < 0.7 else -d)
        c.emu.wf32(m + 16, 1.0)
        c.emu.wf32(m + 32, 1.0)
    b = _vec(c, 3, -50.0, 50.0)
    x = b if r.random() < 0.2 else _vec(c, 3, -1.0, 1.0)
    return [m, b, x]


def _unit(c):
    _sys(c)
    return [c.emu.alloc(0x10, 4), _vec(c, 3, -1.0, 1.0)]


def _seg(c):
    r = c.rng
    _sys(c)
    this = c.emu.alloc(0x40, 4)
    a = _vec(c, 3, -20.0, 20.0)
    b = _vec(c, 3, -20.0, 20.0) if r.random() < 0.9 else a
    p = _vec(c, 3, -20.0, 20.0)
    k = r.random()
    if k < 0.15:   # p exactly on an endpoint (zero distance: random direction)
        src = a if r.random() < 0.5 else b
        for i in range(3):
            c.emu.wf32(p + 4 * i, c.emu.rf32(src + 4 * i))
    elif k < 0.3:   # a = 0, b on the y axis, p = (e, 0, 0) with e within a few ulps of 1e-6: |dir| on the edge
        for i in range(3):
            c.emu.wf32(a + 4 * i, 0.0)
            c.emu.wf32(b + 4 * i, 0.0)
            c.emu.wf32(p + 4 * i, 0.0)
        c.emu.wf32(b + 4, r.uniform(1.0, 5.0))
        c.emu.wf32(p, struct.unpack('<f', struct.pack('<I', 0x358637bd + r.randint(-3, 3)))[0])
    t = c.emu.alloc(0x10, 4)
    rad = c.emu.alloc(0x10, 4)
    c.emu.wf32(rad, c.fv(0.0, 30.0) if r.random() < 0.9 else -r.uniform(0, 30))
    dist = c.emu.alloc(0x10, 4)
    d = _vec(c, 3, -1.0, 1.0)
    return [this, p, a, b, t, rad, dist, d, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4eb100, 'solve3 (guessed; Cramer 3x3)', 'stdcall', None, ret='al', gen=_solve, note='batch1101')
S(0x4eaf10, 'random unit vector (guessed)', 'thiscall', None, gen=_unit, note='batch1101')
S(0x4e9780, 'sphere vs segment (guessed)', 'thiscall', None, ret='eax', gen=_seg, note='batch1101')
