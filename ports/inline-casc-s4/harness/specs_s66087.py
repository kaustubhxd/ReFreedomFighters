"""specs_s66087.py - cascade s4 batch 66087: 0x4dddf0 (/GS triangle test: transform three points by d, plane normal, edge tests via 0x4ddb20, distance via 0x4dd930; all callees run for real)."""
import struct
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _fl(x):
    return struct.pack('<f', x)


def _g4dddf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))
    pal = [0.0, 0.5, 1.0, -1.0, 2.0, -3.0, 0.25, 4.0, 1e-3, float('nan'), float('inf')]
    big = r.random() < 0.5

    def fill(p, n, lo):
        for k in range(n):
            e.wbytes(p + 4 * k, _fl(r.choice(pal) if r.random() < 0.7 else r.uniform(lo, -lo)))
    for addr, vals in ((0x678858, [0.01, 1.0, 4.0]), (0x679540, [1e-6, 0.01, 1.0]), (0x678610, [0.001, 0.5, 2.0, 100.0])):
        pass
    e.wbytes(0x678858, _fl(r.choice([1e-6, 1e-6, 1e-4, 0.01, 1.0, 4.0])))
    e.wbytes(0x679540, _fl(r.choice([1e-6, 0.01, 1.0])))
    e.wbytes(0x678610, struct.pack('<d', r.choice([0.001, 0.5, 2.0, 100.0])))
    e._image_dirty = True
    a, b, cc = (e.alloc(0x20, 8) for _ in range(3))
    mode = r.random()
    for p in (a, b, cc):
        for k in range(3):
            if mode < 0.8:
                v = r.choice([r.uniform(-4, 4), r.uniform(-4, 4), r.uniform(-1, 1), r.uniform(-0.3, 0.3), 0.5, -1.0, 2.0, 1.0, 0.0])
            else:
                v = r.choice(pal)
            e.wbytes(p + 4 * k, _fl(v))
    if r.random() < 0.35:                  # p0 in the plane of (p1, p2): dot product exactly zero or tiny
        src = r.choice([b, cc])
        e.wbytes(a, bytes(e.rbytes(src, 12)))
    elif r.random() < 0.2:
        e.wbytes(a, bytes(e.rbytes(b, 12)))
        e.wbytes(cc, bytes(e.rbytes(b, 12)))
    t = e.alloc(0x60, 8)
    fill(t, 0x18, -4.0)
    t0 = t
    d = e.alloc(0x60, 8)
    fill(d, 0x18, -4.0)
    for k in range(3):
        e.wbytes(d + 0x18 + 4 * k, _fl(r.choice([1.0, 1.0, 2.0, -1.0, 0.5, 0.0])))
    forced = False
    if r.random() < 0.6:                   # axis-aligned triangle: |n|^2 and |dot| hit the thresholds exactly
        u, v = r.choice([1.0, 2.0]), r.choice([1.0, 2.0])
        w = r.choice([0.5, 2.0, 1.0, -2.0])
        sz = r.choice([0.0, 0.0, 1.0, 2.0])
        nn = u * u * (sz * sz + v * v)
        for k in range(9):
            e.wbytes(d + 4 * k, _fl(1.0 if k in (0, 4, 8) else 0.0))
        e.wbytes(b, _fl(u) + _fl(0.0) + _fl(w))
        e.wbytes(cc, _fl(u) + _fl(v) + _fl(w + sz))
        e.wbytes(a, _fl(0.0) + _fl(0.0) + _fl(w))
        e.wbytes(t0, b'\0' * 12)
        e.wbytes(0x679540, _fl(r.choice([(u * v) ** 2, (u * v) ** 2, (u * v) ** 2, 1.5 * (u * v) ** 2, 1.5 * (u * v) ** 2, 0.5 * (u * v) ** 2, 0.5 * (u * v) ** 2, 4.0])))
        e.wbytes(0x678610, struct.pack('<d', r.choice([abs(w), abs(w), abs(w), 0.5, 2.0] if sz == 0.0 else [0.5, 2.0, 100.0])))
        e.wbytes(0x678858, _fl(r.choice([1e-6, 1e-4])))
        forced = True
    e._image_dirty = True
    hmode = r.random()
    f930 = r.random() < 0.6 or forced
    cnt = {'n': 0}

    def h4ddb20(em, rr):                  # thiscall-ish (ecx = vec, edx = vec) returns al
        k = cnt['n']
        cnt['n'] += 1
        cb, db = bytes(em.rbytes(em.reg('ecx'), 12)), bytes(em.rbytes(em.reg('edx'), 12))
        em.calllog.append(('h4ddb20', cb, db))
        h = (sum(cb) * 7 + sum(db) * 3) % 100
        em.ret(eax=0x100 | (1 if h < (0 if forced else (12 if hmode < 0.7 else 40)) else 0), argbytes=0)

    def h4dd930(em, rr):                  # fastcall (ecx = vec, edx = vec) + 1 stack arg ret 4
        cb, db = bytes(em.rbytes(em.reg('ecx'), 12)), bytes(em.rbytes(em.reg('edx'), 12))
        em.calllog.append(('h4dd930', cb, db, bytes(em.rbytes(em.arg32(0), 12))))
        em.ret(eax=0x300 | (1 if f930 else (sum(cb) + sum(db)) & 1), argbytes=4)
    if forced or r.random() < 0.8:
        e.hook(0x4ddb20, h4ddb20)
        e.hook(0x4dd930, h4dd930)
    # args: ecx = t, edx = d, then a, b, c (thiscall + edx); the harness passes [this, a, b, c]; d goes in edx via the spec
    return [t, d, a, b, cc]


S(0x4dddf0, 'GUESS triangle plane/edge test against a transformed frame', ('regs', ['ecx', 'edx', 's', 's', 's']), None, ret='al', gen=_g4dddf0, note='batch66087')
