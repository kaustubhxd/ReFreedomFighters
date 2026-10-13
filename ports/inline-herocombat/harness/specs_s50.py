"""specs_s50.py - inline session batch 50: ZCamHelper aim helpers under GetFireAimPos (shoot tree).
Vtable callees are heap stubs: they save their non-frame args, count calls, fill out-vectors from per-input buffers,
return a per-input eax, or load a per-input float onto the x87 stack (camera slot 0xac). The ray stub copies the
COLI fields the caller initialises (from, dir, +0x34, +0x44, byte +0x6c) into its record."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vec(c, n, lo, hi):
    a = c.emu.alloc(4 * n + 0x10, 4)
    for i in range(n):
        c.emu.wf32(a + 4 * i, c.rng.uniform(lo, hi))
    return a


def _stub(c, nargs, fills=(), ret=0, skip=(), fld=None, copy=None):
    """copy = (argidx, [(off, 'd'|'b'), ...]) copies fields of the struct an arg points to into the record."""
    nrec = nargs + 1 + (len(copy[1]) if copy else 0)
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


def _posobj(c, extra=None):
    """An actor whose slots 0x3a8 / 0x398 / 0x84 report a position (0x3a8 and 0x84 fill different vectors)."""
    r = c.rng
    p1 = _vec(c, 3, -100.0, 100.0)
    p2 = _vec(c, 3, -100.0, 100.0)
    slots = {0x3a8: _stub(c, 1, fills=((0, p1, 3),), ret=r.getrandbits(32), skip=(0,)),
             0x398: _stub(c, 1),
             0x84: _stub(c, 1, fills=((0, p2, 3),), skip=(0,))}
    if extra:
        slots.update(extra)
    return _obj(c, 0x40, slots)


def _cam(c):
    r = c.rng
    cam = _rnd(c, 0xe10)
    c.emu.w32(cam + 0xad5, 5 if r.random() < 0.4 else r.choice((0, 1, 4, 6)))
    c.emu.w32(cam + 0xa4c, 1 if r.random() < 0.5 else r.choice((0, 2)))
    for off in (0xa72, 0xa76, 0xa7a, 0xcdd, 0xce1, 0xce5, 0xd22, 0xd26, 0xd2a):
        c.emu.wf32(cam + off, r.uniform(-1.0, 1.0) if off < 0xd22 else r.uniform(-100.0, 100.0))
    camsrc = _vec(c, 3, -100.0, 100.0)
    fv = c.emu.alloc(4, 4)
    c.emu.wf32(fv, r.uniform(0.0, 500.0))
    camobj = _obj(c, 0x20, {0x94: _stub(c, 1, fills=((0, camsrc, 3),), skip=(0,)), 0xac: _stub(c, 0, fld=fv)})
    c.emu.w32(cam + 0xb54, camobj)
    c.emu.w32(cam + 0x44, _posobj(c))
    return cam


def _origin(c):
    cam = _cam(c)
    out = _rnd(c, 0x10)
    c.emu.mu.ctl_flush_tb()
    return [cam, out]


def _target(c):
    r = c.rng
    cam = _cam(c)
    o = _posobj(c, {0x1e0: _stub(c, 1, ret=r.getrandbits(32) & (0xffffff00 if r.random() < 0.3 else 0xffffffff))})
    rm = _obj(c, 0x10, {0x58: _stub(c, 1, ret=o if r.random() < 0.8 else 0)})
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    c.emu.mu.ctl_flush_tb()
    return [cam, r.getrandbits(32) if r.random() < 0.85 else 0]


def _angle(c):
    cam = _cam(c)
    p = _vec(c, 3, -100.0, 100.0)
    c.emu.mu.ctl_flush_tb()
    return [cam, p]


def _ray(c):
    r = c.rng
    cam = _cam(c)
    fields = [(0, 'd'), (4, 'd'), (8, 'd'), (0xc, 'd'), (0x10, 'd'), (0x14, 'd'), (0x34, 'd'), (0x44, 'd'), (0x6c, 'b')]
    w = _obj(c, 0x10, {0x2e0: _stub(c, 6, ret=r.getrandbits(32) & (0xffffff00 if r.random() < 0.5 else 0xffffffff),
                                    skip=(0,), copy=(0, fields))})
    rm = _rnd(c, 0xae0)
    c.emu.w32(rm + 0xadc, w)
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    p = _vec(c, 3, -100.0, 100.0)
    c.emu.mu.ctl_flush_tb()
    return [cam, p]


S(0x5cf420, 'ZCamHelper aim origin', 'thiscall', None, ret=None, gen=_origin, note='batch50')
S(0x5d2630, 'ZCamHelper set aim target', 'thiscall', None, ret=None, gen=_target, note='batch50')
S(0x5cf520, 'ZCamHelper aim angle to point', 'thiscall', None, ret='st0', gen=_angle, note='batch50; aim origin, vangle as exe code')
S(0x5cd750, 'ZCamHelper ray clear', 'thiscall', None, ret='al', gen=_ray, note='batch50; COLI ctor as exe code')
