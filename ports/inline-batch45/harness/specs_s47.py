"""specs_s47.py - inline session batch 47: 0x487fc0 ZMovementBase::CheckCollision (walk tree, called by Move).
Callee stand-ins (both runs call the same ones), all heap stubs that save their stack args to a buffer, count calls,
optionally fill out-vectors from a per-input buffer, and return a fixed per-input eax:
  mover vtable slot 0x80 (fills the mover position), this vtable slots 0x4c (collision, returns al) and 0x5c (floor
  probe, fills position and normal), the collision manager's slots 0x74 and 0xf8, the render manager's slot 0x160,
  and the player's slot 0x5a8. mreset, GetSize, PSVECSubtract, vneg, vscalar and PSVECAdd run as exe code."""
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


def _stub(c, nargs, fills=(), ret=0, skip=()):
    """thiscall stub: save the stack args (except those in skip: pointers into the caller's frame differ between the
    exe and the port), copy (argidx, src, ndwords) fills, count the call, eax=ret, ret 4*nargs."""
    rec = c.emu.alloc(4 * nargs + 4, 4)
    code = b''
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    for ai, src, nd in fills:
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(nd):
            code += b'\x8b\x15' + struct.pack('<I', src + 4 * j) + b'\x89\x50' + bytes([4 * j])
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
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


def _cc(c):
    r = c.rng
    a3 = _vec(c, 3, -20.0, 20.0)
    p = _obj(c, 0x600, {0x5a8: _stub(c, 1)})
    if r.random() < 0.4:
        c.emu.w32(p + 0x41b, 0)
        c.emu.w32(p + 0x41f, 0 if r.random() < 0.7 else r.getrandbits(32))
    c.emu.wbytes(p + 0x423, bytes([0 if r.random() < 0.5 else r.randint(1, 255)]))
    game = _rnd(c, 0x440)
    n = r.choice((0, 1, 2, 3, 4))
    c.emu.w32(game + 0x408, n)
    for i in range(n):
        if r.random() < 0.15:
            ent = p
        else:
            src = c.emu.alloc(12, 4)
            for j in range(3):   # mover position near the new position, so the push-out path runs
                c.emu.wf32(src + 4 * j, c.emu.rf32(a3 + 4 * j) + r.uniform(-6.0, 6.0))
            ent = _obj(c, 0x40, {0x80: _stub(c, 2, fills=((1, src, 3),), skip=(0, 1))})
            geom = _rnd(c, 0x50)
            c.emu.wf32(geom + 0x40, r.uniform(0.0, 10.0))
            c.emu.wf32(geom + 0x44, r.uniform(0.0, 5.0))
            c.emu.wf32(geom + 0x48, r.uniform(0.0, 10.0))
            fl = r.getrandbits(32)
            c.emu.w32(geom + 0x3c, fl & ~0x400 if r.random() < 0.7 else fl | 0x400)
            c.emu.w32(ent + 8, geom)
        c.emu.w32(game + 0x40c + 4 * i, ent)
    c.emu.w32(0x7003b8, game)
    fsrc = c.emu.alloc(24, 4)
    for j in range(6):
        c.emu.wf32(fsrc + 4 * j, r.uniform(-20.0, 20.0))
    this = _obj(c, 0x40, {0x4c: _stub(c, 6, ret=r.getrandbits(32)),
                          0x5c: _stub(c, 4, fills=((0, fsrc, 3), (1, fsrc + 12, 3)), skip=(0, 1),
                                      ret=r.getrandbits(32) & (0xffffff00 if r.random() < 0.4 else 0xffffffff))})
    c.emu.w32(this + 4, p)
    t = _rnd(c, 0x40)
    m = _rnd(c, 0x10)
    rm = _obj(c, 0x10, {0x160: _stub(c, 1, ret=t if r.random() < 0.7 else 0)})
    x = _obj(c, 0x10, {0x74: _stub(c, 1, ret=r.getrandbits(32))})
    y = _obj(c, 0x10, {0xf8: _stub(c, 1, ret=m if r.random() < 0.7 else 0)})
    coll = _rnd(c, 0x20)
    c.emu.w32(coll + 0x18, y)
    c.emu.w32(coll + 0x1c, x)
    sysobj = _rnd(c, 0x1ab0)
    c.emu.w32(sysobj + 0x1aa3, coll)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    a0 = _rnd(c, 0x30)
    a1 = _rnd(c, 0x10)
    a2 = _rnd(c, 0x30)
    a4 = _rnd(c, 0x10)
    c.emu.mu.ctl_flush_tb()   # stub code changes per input at reused heap addresses; drop unicorn's translated blocks
    return [this, a0, a1, a2, a3, a4]


S(0x487fc0, 'ZMovementBase::CheckCollision', 'thiscall', None, ret='al', gen=_cc,
  note='batch47; walk tree; all vtable callees are recorder stubs; push-out math, GetSize and vector helpers as exe code')
