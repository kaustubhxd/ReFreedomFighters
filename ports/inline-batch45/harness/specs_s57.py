"""specs_s57.py - inline session batch 57: ZFFHeroMovementClimb::WantControl (the climb ledge test).
Hero, list, collision world, render manager and logger calls are heap stubs (the batch 53 kit). The ray stub is
stateful: each call returns its own hit flag and hit point from a per-input table and logs the COLI fields the
caller set. COLI::COLI, the vector helpers, vcross, mcpy and the hit-triangle normal (0x45bfd0) run as exe code."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, nargs, fills=(), ret=0, skip=(), fld=None, copy=None, adds=(), ofills=(), peeks=()):
    """copy = (argidx, [(off, 'd'|'b'), ...]) copies fields of the struct an arg points to into the record."""
    nrec = nargs + 1 + (len(copy[1]) if copy else 0) + len(peeks)
    rec = c.emu.alloc(4 * nrec, 4)
    code = b''
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    if copy:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * copy[0]])
        for k, (off, kind) in enumerate(copy[1]):
            code += (b'\x8b\x50' if kind == 'd' else b'\x0f\xb6\x50') + bytes([off])
            code += b'\x89\x15' + struct.pack('<I', rec + 4 * (nargs + 1 + k))
    for k, addr in enumerate(peeks):   # record a dword of memory at call time
        code += b'\xa1' + struct.pack('<I', addr) + b'\xa3' + struct.pack('<I', rec + 4 * (nrec - len(peeks) + k))
    for ai, off, src, nd in ofills:   # out = [arg]+off, filled from src
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([off + 4 * j])
    for ai, src, nd in adds:   # out[j] += src[j] (SSE single adds), like a local-to-world offset
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\xf3\x0f\x10\x40' + bytes([4 * j]) + b'\xf3\x0f\x58\x05' + struct.pack('<I', src + 4 * j)
            code += b'\xf3\x0f\x11\x40' + bytes([4 * j])
    for ai, src, nd in fills:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([4 * j])
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    if fld is not None:
        code += b'\xd9\x05' + struct.pack('<I', fld)
    code += b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _obj(c, size, slots):
    o = _rnd(c, size)
    vt = c.emu.alloc(max(slots) + 4, 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def _fl(c, n, lo=-200.0, hi=200.0):
    a = c.emu.alloc(4 * n + 4, 4)
    c.emu.wbytes(a, b''.join(struct.pack('<f', c.rng.uniform(lo, hi)) for _ in range(n)))
    return a


def _f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _ray(c, hits, tri, handle):
    """hits: list of (x, y, z, al). Logs from, dir, +0x34, byte +0x6c and args 1 to 5 per call (64-byte records)."""
    n = len(hits)
    tab = c.emu.alloc(16 * n, 4)
    c.emu.wbytes(tab, b''.join(struct.pack('<fffI', *h) for h in hits))
    trib = c.emu.alloc(4 * 10, 4)
    c.emu.wbytes(trib, b''.join(struct.pack('<f', v) for v in tri) + struct.pack('<I', handle))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(64 * 16, 4)
    code = b'\xa1' + struct.pack('<I', cnt) + b'\x3d' + struct.pack('<I', n - 1) + b'\x76\x05'
    code += b'\xb8' + struct.pack('<I', n - 1) + b'\xc1\xe0\x04\x05' + struct.pack('<I', tab)
    code += b'\x8b\x4c\x24\x04'
    for k, off in enumerate((0x28, 0x2c, 0x30)):
        code += b'\x8b\x50' + bytes([4 * k]) + b'\x89\x51' + bytes([off])
    code += b'\xff\x70\x0c'   # push the hit flag
    for k in range(9):
        code += b'\x8b\x15' + struct.pack('<I', trib + 4 * k) + b'\x89\x51' + bytes([0x48 + 4 * k])
    code += b'\x8b\x15' + struct.pack('<I', trib + 36) + b'\x89\x51\x44'
    code += b'\xa1' + struct.pack('<I', cnt) + b'\x83\xe0\x0f\xc1\xe0\x06\x05' + struct.pack('<I', log)
    for k, off in enumerate((0, 4, 8, 0xc, 0x10, 0x14, 0x34)):
        code += b'\x8b\x51' + bytes([off]) + b'\x89\x50' + bytes([4 * k])
    code += b'\x0f\xb6\x51\x6c\x89\x50\x1c'
    for i in range(5):   # args 1..5, at [esp + 4 + 4 * (i + 1)] plus the pushed flag
        code += b'\x8b\x54\x24' + bytes([12 + 4 * i]) + b'\x89\x50' + bytes([0x20 + 4 * i])
    code += b'\xff\x05' + struct.pack('<I', cnt) + b'\x58\xc2\x18\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _iter(c, k):
    cnt = c.emu.alloc(8, 4)
    c.emu.w32(cnt, k + 1)
    base = c.rng.getrandbits(32) & 0x7fff0000
    code = b'\xa1' + struct.pack('<I', cnt) + b'\x48\xa3' + struct.pack('<I', cnt) + b'\x8b\x4c\x24\x04\x89\x01'
    code += b'\x05' + struct.pack('<I', base) + b'\xff\x05' + struct.pack('<I', cnt + 4) + b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _cdecl(c, nargs, ret=0):
    a = _stub(c, nargs, ret=ret)
    code = bytes(c.emu.mu.mem_read(a, 400))
    i = code.index(b'\xc2' + struct.pack('<H', 4 * nargs))
    c.emu.wbytes(a + i, b'\xc3\x90\x90')
    return a


def _fv(c, vals):
    a = c.emu.alloc(4 * len(vals) + 4, 4)
    c.emu.wbytes(a, b''.join(struct.pack('<f', v) for v in vals))
    return a


def _wc(c):
    r = c.rng
    ints = r.random() < 0.5
    num = (lambda lo, hi: float(r.randint(int(lo), int(hi)))) if ints else r.uniform
    foot = num(-20, 120)
    P = [num(-3000, 3000), num(-500, 800), num(-3000, 3000)]
    p1 = _f32(_f32(P[1]) - _f32(foot))
    ang = r.uniform(0, 6.283)
    import math
    row0 = [math.cos(ang), 0.0, math.sin(ang)] if not ints else r.choice(([1.0, 0.0, 0.0], [0.0, 0.0, -1.0], [0.6, 0.0, 0.8]))
    M = row0 + [r.uniform(-1, 1) for _ in range(6)]
    X = [num(0, 40), num(0, 100), num(0, 60)]
    T = r.choice((r.uniform(0, 260), float(r.choice((25, 26, 90, 91, 140, 141, 200, 201, 220, 221, 300))), num(-30, 240)))
    if ints and r.random() < 0.6:   # land the ledge exactly on a height edge
        T = float(r.choice((25, 90, 140, 200, 220)))
    hs = []
    for i in range(4):
        if ints and i == 0 and r.random() < 0.5:
            hs.append(T)
            continue
        x = r.random()
        if x < 0.45:
            hs.append(T + (r.uniform(-14, 14) if not ints else float(r.choice((0, 1, -1, 14, -14, 15, -15, 16)))))
        elif x < 0.6 and hs:
            hs.append(hs[-1] + r.choice((15.0, -15.0, 14.0, 0.0)))
        else:
            hs.append(num(-50, 300))
    hits = []
    for i in range(4):
        hits.append((r.uniform(-3000, 3000), _f32(p1 + hs[i]), r.uniform(-3000, 3000), 1 if r.random() < 0.85 else 0))
    for pr in (0.2, 0.2, 0.85):
        hits.append((num(-3000, 3000), r.uniform(-500, 800), num(-3000, 3000), r.choice((1, 0x101, 0x37)) if r.random() < pr else r.choice((0, 0x100))))
    tri = [r.uniform(-100, 100) for _ in range(9)] if r.random() < 0.9 else [5.0] * 9
    rmobj = _obj(c, 0x10, {0x88: _stub(c, 1, skip=(0,), copy=(0, [(0, 'd'), (4, 'd'), (8, 'd')]),
                                      adds=((0, _fv(c, [r.uniform(-1, 1) for _ in range(3)]), 3),))})
    rm = _obj(c, 0xb00, {0x58: _stub(c, 1, ret=rmobj)})
    world = _obj(c, 0x10, {0x220: _stub(c, 1), 0x2e0: _ray(c, hits, tri, r.getrandbits(32))})
    c.emu.w32(rm + 0xadc, world)
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    logobj = _obj(c, 0x10, {0x2c: _cdecl(c, 4)})
    lg = _obj(c, 0x10, {0x20: _stub(c, 2, ret=logobj)})
    c.emu.w32(0x700390, lg)
    lst = _obj(c, 0x10, {0x4c: _stub(c, 1, skip=(0,)), 0x5c: _iter(c, r.choice((0, 0, 1, 3))), 0xc: _stub(c, 0)})
    hero = _obj(c, 0x500, {0x5b4: _stub(c, 0, fld=_fv(c, [foot])),
                           0x5a0: _stub(c, 3, skip=(0, 1, 2), fills=((0, _fv(c, M), 9), (1, _fv(c, P), 3), (2, _fv(c, X), 3)))})
    c.emu.w32(hero + 0x417, (r.getrandbits(32) | 0x80000) if r.random() < 0.92 else (r.getrandbits(32) & ~0x80000))
    self = _rnd(c, 0x100)
    c.emu.w32(self + 4, hero)
    c.emu.w32(self + 0x76, lst)
    c.emu.wbytes(self + 0x1d, bytes([0 if r.random() < 0.93 else r.randint(1, 255)]))
    for off in range(0x1e, 0x3e, 4):
        c.emu.w32(self + off, 0 if r.random() < 0.1 else r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [self, _fv(c, [1, 2, 3]), _fv(c, [4, 5, 6]), _fv(c, [7, 8, 9])]


S(0x5e75a0, 'ZFFHeroMovementClimb::WantControl', 'thiscall', None, ret='al', gen=_wc, note='batch57; climb tree')
