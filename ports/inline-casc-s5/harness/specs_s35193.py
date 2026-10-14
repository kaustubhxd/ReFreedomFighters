"""specs_s35193.py - 0x40fe70 (cdecl(coef, n, out), ret='eax'). coef: n + 1 float coefficients of a polynomial built from real roots in [-3, 3] (or a chosen quadratic with complex roots, or random coefficients); n in -1..5 (more often 1..5). The generator simulates the algorithm in Python (IEEE double = x87 at 53-bit precision) and
only emits inputs that terminate within 300 iterations per root. out: 8 random floats."""
import math
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _fl(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _sim(coef, n, K):
    C0, C1, C2, C3, C4 = K
    D = [float(c) for c in coef]
    m = n
    base = 0
    steps = 0
    while m > 0:
        x = C0
        for it in range(300):
            f = d = C0
            b = D[base + m]
            for k in range(m, 0, -1):
                f, d, b = f * x + d, d * x + b, b * x + D[base + k - 1]
            disc = ((m - 1) * d * d - m * f * b) * (m - 1)
            if not (disc >= C0):
                return True
            sq = math.sqrt(disc)
            if d > C0:
                den = d + sq
                if not (den >= C1):
                    den = C1
            else:
                den = d - sq
                if den > C2:
                    den = C2
            if den == 0:
                return False
            dx = (m * b) / den
            x1 = x - dx
            if not (dx >= C0):
                dx = dx * C3
            if x1 == 0:
                r = float('inf')
            else:
                r = abs(dx / x1)
            x = x1
            if not (r >= C4):
                break
        else:
            return False
        for k in range(m, 0, -1):
            D[base + k - 1] = x * D[base + k] + D[base + k - 1]
        base += 1
        m -= 1
    return True


def _g40fe70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    K = tuple(struct.unpack('<d', bytes(e.rbytes(a, 8)))[0] for a in (0x6be098, 0x6be128, 0x6be120, 0x6be118, 0x6be110))
    for _ in range(50):
        n = r.choice([-1, 0, 1, 2, 2, 3, 3, 4, 5])
        t = r.random()
        if n <= 0:
            coef = [_fl(r.uniform(-3, 3)) for _ in range(max(n + 1, 1))]
        elif t < 0.25 and n >= 2:
            # f (x^2 coefficient) zero or tiny and the x coefficient tiny: the first denominators are below the clamp constants
            eps = r.choice([1e-8, 1e-7, 3e-7, 8e-7, 2e-6]) * r.choice([-1, 1])
            coef = [_fl(r.uniform(-2, 2)), _fl(eps), _fl(r.choice([0.0, 0.0, r.uniform(-1, 1)]))] + [_fl(r.uniform(0.5, 2)) for _ in range(n - 2)]
        elif t < 0.7:
            roots = [round(r.uniform(-3, 3), 2) for _ in range(n)]
            if n >= 2 and r.random() < 0.3:
                roots[1] = -roots[0]   # symmetric pair: the first derivative at the start value is zero
            if r.random() < 0.15:
                roots[0] = 0.0
            lead = r.choice([1.0, 2.0, -1.5, 0.5])
            poly = [1.0]
            for rt in roots:
                nxt = [0.0] * (len(poly) + 1)
                for i, a in enumerate(poly):
                    nxt[i] += a * (-rt)
                    nxt[i + 1] += a
                poly = nxt
            coef = [_fl(lead * a) for a in poly]
        elif t < 0.85:
            coef = [_fl(r.uniform(0.5, 4)) for _ in range(n + 1)]   # often complex roots
        else:
            coef = [_fl(r.uniform(-4, 4)) for _ in range(n + 1)]
        if n <= 0 or _sim(coef, n, K):
            break
    else:
        n, coef = 1, [_fl(-1.0), _fl(2.0)]
    cp = rnd(c, 4 * 8)
    for i, v in enumerate(coef):
        e.w32(cp + 4 * i, struct.unpack('<I', struct.pack('<f', v))[0])
    return [cp, n & 0xffffffff, rnd(c, 4 * 8)]


S(0x40fe70, 'GUESS real roots of a polynomial by Laguerre iteration', 'cdecl', None, ret='eax', gen=_g40fe70, note='batch35193')
