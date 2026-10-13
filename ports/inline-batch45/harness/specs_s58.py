"""specs_s58.py - inline session batch 58: ZFFHeroMovementClimb::GetAnims and ZFFHeroMovementGuide::CalculateLadder. GetAnims' slot 0x58 is a stub that logs each name pointer and returns a value
derived from it, so the order of the lookups and stores shows. CalculateLadder's shape transforms (slots 0x84 and
0x88) are recorder stubs that add an offset, the spline samplers run as exe code, and the _CIfmod import slot is
pointed at a heap fprem loop (fmod is exact, so this is the CRT's result)."""
import struct
from pilot import S, F


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




def _ga(c):
    r = c.rng
    log = c.emu.alloc(4 * 17, 4)
    k = r.getrandbits(32)
    # mov eax,[log]; mov edx,[esp+4]; mov [log+4+eax*4],edx; inc dword [log]; lea eax,[edx+eax*?]: return name ^ k + count
    code = b'\xa1' + struct.pack('<I', log) + b'\x83\xe0\x0f\x8b\x54\x24\x04\x89\x14\x85' + struct.pack('<I', log + 4)
    code += b'\xff\x05' + struct.pack('<I', log) + b'\x01\xc2\x81\xf2' + struct.pack('<I', k) + b'\x89\xd0\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    vt = c.emu.alloc(0x60, 4)
    c.emu.w32(vt + 0x58, a)
    self = c.emu.alloc(0x60, 4)
    c.emu.wbytes(self, bytes(r.getrandbits(8) for _ in range(0x60)))
    c.emu.w32(self, vt)
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x5e4380, 'ZFFHeroMovementClimb::GetAnims', 'thiscall', None, gen=_ga, note='batch58; climb tree')


def _fv(c, vals):
    a = c.emu.alloc(4 * len(vals) + 4, 4)
    c.emu.wbytes(a, b''.join(struct.pack('<f', v) for v in vals))
    return a


def _coef(c):
    r = c.rng
    x = r.random()
    if x < 0.1:
        return [0.0] * 14
    if x < 0.2:
        return [r.choice((0.0, 1e-5, -1e-5, 1.2e-4, 1.3e-4, -1.25e-4)) for _ in range(14)]
    return [r.uniform(-300, 300) for _ in range(14)]


def _t(c):
    r = c.rng
    return r.choice((r.uniform(0, 1), r.uniform(-2, 2), 0.0, 1.0, 0.5, 0.25, 0.999, 1.0001))


def _seg(c):
    return [_fv(c, _coef(c)), _fv(c, [9.0, 9.0, 9.0]), F(_t(c))]


def _shape(c, n=None):
    r = c.rng
    n = n if n is not None else r.choice((1, 1, 2, 3, 5))
    segs = c.emu.alloc(0x38 * n, 4)
    for i in range(n):
        c.emu.wbytes(segs + 0x38 * i, b''.join(struct.pack('<f', v) for v in _coef(c)))
    b = _rnd(c, 0x20)
    c.emu.w32(b + 0xc, segs)
    c.emu.w32(b + 0x10, n)
    return b


def _spv(c):
    return [_shape(c), _fv(c, [9.0] * 3), _fv(c, [9.0] * 3), F(_t(c))]


FMOD = b'\xd9\xc9\xd9\xf8\xdf\xe0\x9e\x7a\xf9\xdd\xd9\xc3'


def _ladder(c):
    r = c.rng
    fm = c.emu.alloc(32, 16)
    c.emu.wbytes(fm, FMOD)
    c.emu.w32(0x676358, fm)
    offs = lambda: [r.uniform(-2000, 2000), r.choice((r.uniform(-500, 500), float(r.randint(-300, 300)))), r.uniform(-2000, 2000)]
    dv = lambda: r.choice(([r.uniform(-1, 1) for _ in range(3)], [0.0, 0.0, -1.0], [0.0, 0.0, 0.0], [0.0, 0.0, 1.5]))
    sh = _obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), copy=(0, [(0, 'd'), (4, 'd'), (8, 'd')]), adds=((0, _fv(c, offs()), 3),)),
                       0x88: _stub(c, 1, skip=(0,), copy=(0, [(0, 'd'), (4, 'd'), (8, 'd')]), adds=((0, _fv(c, dv()), 3),))})
    b = _shape(c)
    c.emu.wbytes(sh + 0x1c, bytes(c.emu.mu.mem_read(b, 0x20)))
    hero = _rnd(c, 0x450)
    c.emu.wbytes(hero + 0x43d, struct.pack('<f', r.choice((r.uniform(0, 250), 110.0, float(r.randint(0, 200))))))
    self = _rnd(c, 0x580)
    c.emu.w32(self + 4, hero)
    c.emu.w32(self + 0x550, sh)
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x5e1c50, 'ZFFHeroMovementGuide::CalculateLadder', 'thiscall', None, gen=_ladder, note='batch58; ladder tree')
