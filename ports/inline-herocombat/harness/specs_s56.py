"""specs_s56.py - inline session batch 56: ZFFHeroMovementClimb Move, AnimEnd, TerminateControl, GotControl.
Hero, movement and render-manager vtable calls are heap recorder stubs (the batch 53 kit). StashItem, mcpy, mreset,
mmul, vmmul and the PSVEC helpers run as exe code."""
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


def _sys(c):
    r = c.rng
    rm = _obj(c, 0x10, {0x4c: _stub(c, 1, ret=r.getrandbits(32))})
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(sysobj + 0x40, r.choice((r.randint(0, 64), r.randint(-50, 5000), r.getrandbits(32))) & 0xffffffff)
    c.emu.w32(0x70039c, sysobj)


def _hero(c):
    r = c.rng
    h = _obj(c, 0x900, {0x504: _stub(c, 0, ret=r.getrandbits(32) if r.random() < 0.6 else 0),
                        0x3dc: _stub(c, 0), 0x480: _stub(c, 1), 0x400: _stub(c, 1),
                        0x230: _stub(c, 2), 0x238: _stub(c, 3)})
    c.emu.wbytes(h + 0x24, b''.join(struct.pack('<f', r.uniform(-2.0, 2.0)) for _ in range(9)))
    c.emu.wbytes(h + 0x48, b''.join(struct.pack('<f', r.uniform(-5000.0, 5000.0)) for _ in range(3)))
    c.emu.w32(h + 0x836, r.choice((0, 0, 2, 1, r.getrandbits(32))))
    c.emu.w32(h + 0x832, r.choice((0, 0, r.getrandbits(32))))
    return h


def _self(c):
    s = _obj(c, 0x100, {0x48: _stub(c, 5)})
    c.emu.w32(s + 4, _hero(c))
    c.emu.w32(s + 8, _rnd(c, 0x10))
    c.emu.wbytes(s + 0x1d, bytes([c.rng.choice((0, 1, c.rng.randint(0, 255)))]))
    return s


def _move(c):
    _sys(c)
    s = _self(c)
    out = [s, _fl(c, 12, -2.0, 2.0), _fl(c, 3, -5000.0, 5000.0), _fl(c, 9), _fl(c, 3), _fl(c, 3)]
    c.emu.mu.ctl_flush_tb()
    return out


def _plain(c):
    _sys(c)
    s = _self(c)
    c.emu.mu.ctl_flush_tb()
    return [s]


def _term(c):
    _sys(c)
    s = _self(c)
    c.emu.mu.ctl_flush_tb()
    return [s, c.rng.getrandbits(32) & (0xffffff00 if c.rng.random() < 0.4 else 0xffffffff)]


S(0x5e5ec0, 'ZFFHeroMovementClimb::Move', 'thiscall', None, gen=_move, note='batch56; climb tree')
S(0x5e1760, 'ZFFHeroMovementClimb::AnimEnd', 'thiscall', None, gen=_plain, note='batch56; climb tree')
S(0x5e7190, 'ZFFHeroMovementClimb::TerminateControl', 'thiscall', None, ret='al', gen=_term, note='batch56; climb tree')
S(0x5e4900, 'ZFFHeroMovementClimb::GotControl', 'thiscall', None, gen=_plain, note='batch56; climb tree')
