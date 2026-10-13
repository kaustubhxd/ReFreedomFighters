"""specs_s68.py - inline session batch 68: ZProjectile::FrameUpdateBallistic and the in-place vector subtract 0x43e960.
The flight (ZParamParticle) is real data run by the batch 65 exe code; the world cast (slot 0x2e0) is a per-call stub
that logs the COLI ray and writes the hit (fraction, handle, point, triangle); the hit normal (0x45bfd0, vcross),
Explode with ShotImpact (stopped at its first check), GetMaterialDesc, GetOwnerRoom and AddSound3d (stopped by a zero
sound id from the sound system's slot 0x11c) run as exe code; the render manager's slot 0x58 maps the hit and owner
handles to recorder objects; everything else is a heap recorder stub."""
import math
import struct
from pilot import S, F
import specs_s53 as k53
import specs_s60 as k60

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_seq, _fv = k60._seq, k60._fv
XYZ = [(0, 'd'), (4, 'd'), (8, 'd')]
BLK = [(4 * i, 'd') for i in range(11)]
P = lambda v: struct.pack('<I', v & 0xffffffff)


def _cast(c, entries):
    """thiscall (coli, a, b, c, d, e), ret 0x18. Logs the ray and args per call; entries[i] = 16 dwords
    (ret, frac, handle, hit xyz, triangle 9 floats, pad) written into the COLI on call i."""
    tab = c.emu.alloc(64 * 4, 4)
    c.emu.wbytes(tab, b''.join(entries[i] if i < len(entries) else entries[-1] for i in range(4)))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(64 * 4, 4)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x03\xc1\xe0\x06\x05' + P(log) + b'\x8b\x54\x24\x04'
    for j in range(6):
        code += b'\x8b\x4a' + bytes([4 * j]) + b'\x89\x48' + bytes([4 * j])
    code += b'\x8b\x4a\x34\x89\x48\x18\x0f\xb6\x4a\x6c\x89\x48\x1c'
    for i in range(1, 6):
        code += b'\x8b\x4c\x24' + bytes([4 + 4 * i]) + b'\x89\x48' + bytes([0x1c + 4 * i])
    code += b'\xa1' + P(cnt) + b'\x83\xe0\x03\xc1\xe0\x06\x05' + P(tab)
    moves = [(4, 0x34), (8, 0x44)] + [(12 + 4 * j, 0x28 + 4 * j) for j in range(3)] + \
            [(24 + 4 * j, 0x48 + 4 * j) for j in range(9)]
    for s, d in moves:
        code += b'\x8b\x48' + bytes([s]) + b'\x89\x4a' + bytes([d])
    code += b'\x8b\x00\xff\x05' + P(cnt) + b'\xc2\x18\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _hmap(c, pairs):
    """Render-manager slot 0x58: logs handles; 0 for ShotImpact's call (return address 0x4ba836)."""
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(32, 4)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x8b\x54\x24\x04\x89\x90' + P(log) + b'\xff\x05' + P(cnt)
    code += b'\x81\x3c\x24' + P(0x4ba836) + b'\x75\x05\x31\xc0\xc2\x04\x00'
    for h, o in pairs:
        code += b'\x81\x7c\x24\x04' + P(h) + b'\x75\x08\xb8' + P(o) + b'\xc2\x04\x00'
    code += b'\x31\xc0\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _sendcmd(c, rid):
    """ZGEOM::SendCommand stub, thiscall (cmd, data, sender), ret 0xc: logs cmd, sender and the data's first three
    dwords per call, all eleven for the explosion message id rid."""
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(2 * 64, 4)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x01\xc1\xe0\x06\x05' + P(log)
    code += b'\x8b\x54\x24\x04\x89\x10\x8b\x54\x24\x0c\x89\x50\x04\x8b\x54\x24\x08'
    for j in range(3):
        code += b'\x8b\x4a' + bytes([4 * j]) + b'\x89\x48' + bytes([8 + 4 * j])
    tail = b''.join(b'\x8b\x4a' + bytes([4 * j]) + b'\x89\x48' + bytes([8 + 4 * j]) for j in range(3, 11))
    code += b'\x81\x7c\x24\x04' + P(rid & 0xffff) + b'\x75' + bytes([len(tail)]) + tail
    code += b'\xff\x05' + P(cnt) + b'\xc2\x0c\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _rndstub(c, vals):
    """thiscall (file, line), ret 8, a per-call float in ST0; logs the arguments."""
    tab = c.emu.alloc(16, 4)
    c.emu.wbytes(tab, b''.join(struct.pack('<f', v) for v in (vals * 4)[:4]))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(32, 4)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x03\xc1\xe0\x03\x05' + P(log)
    code += b'\x8b\x54\x24\x04\x89\x10\x8b\x54\x24\x08\x89\x50\x04'
    code += b'\xa1' + P(cnt) + b'\x83\xe0\x03\xd9\x04\x85' + P(tab) + b'\xff\x05' + P(cnt) + b'\xc2\x08\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _vs(c):
    r = c.rng
    c.emu.alloc(0x40, 16)
    d = _fv(c, [r.choice((r.uniform(-1e3, 1e3), 0.0, -0.0, c.fv(), math.inf)) for _ in range(3)])
    s = _fv(c, [r.choice((r.uniform(-1e3, 1e3), 0.0, c.fv(), math.nan)) for _ in range(3)])
    return [d, r.choice((s, s, s, d))]


def _particle(c, t0):
    r = c.rng
    pp = c.emu.alloc(0x30, 4)
    drag = r.choice((0.0, 0.0, 0.0, r.uniform(0.001, 3.0)))
    slow = r.random() < 0.35   # slow rolls and small bounces: the rest speed, the volume range and the sound gap
    if slow:
        vals = r.choice(([0.0, 0.0, 0.0], [r.uniform(-20, 20) for _ in range(3)]))
    else:
        vals = [0.0, -491.0, 0.0] if r.random() < 0.6 else [r.uniform(-600, 600) for _ in range(3)]
    sv = r.choice((40.0, 100.0, 300.0)) if slow else 800.0
    vals += [drag] + [r.uniform(-1500, 1500) for _ in range(3)] + [r.uniform(-sv, sv) for _ in range(3)] + [t0]
    c.emu.wbytes(pp, b''.join(struct.pack('<f', v) for v in vals))
    return pp


def _entry(c, handle):
    r = c.rng
    hit = 1 if r.random() < 0.6 else r.choice((0, 0, 0x100))
    frac = r.choice((r.random(), 0.0, 1.0, r.random()))
    pt = [r.uniform(-1500, 1500) for _ in range(3)]
    tri = [r.uniform(-50, 50) for _ in range(9)]
    if r.random() < 0.08:
        tri = [tri[0], tri[1], tri[2]] * 3
    return struct.pack('<If', (r.getrandbits(32) & ~0xff) | hit if r.random() < 0.3 else hit, frac) + P(handle) + \
        b''.join(struct.pack('<f', v) for v in pt + tri) + P(0)


def _fub(c):
    r = c.rng
    now = r.choice((r.randint(1 << 10, 1 << 22), r.randint(1 << 10, 1 << 16), r.randint(2, 400)))
    prev = now - r.choice((r.randint(1, 100), 1, r.randint(1, 2000)))
    nows, prevs = now / 1024.0, prev / 1024.0
    hh, oh = r.getrandbits(32) | 1, r.getrandbits(32) | 2
    rid = r.getrandbits(32)
    # hit object and its geometry
    hgeom = _rnd(c, 0x60)
    c.emu.w32(hgeom + 0x3c, r.choice((0, 2, 0x40000, 0x40002, 0x40, 0x40000000, 0x40000002, r.getrandbits(32))))
    c.emu.w32(hgeom + 0x50, 0)
    c.emu.w32(hgeom + 0x54, 0)
    c.emu.wbytes(hgeom + 0x5c, struct.pack('<H', r.randint(1, 3)))   # room index (GetOwnerRoom with flag 0x40000000)
    hit = _obj(c, 0x20, {0x88: _stub(c, 1, skip=(0,), copy=(0, XYZ),
                                     adds=((0, _fv(c, [r.choice((0.0, r.uniform(-1, 1))) for _ in range(3)]), 3),)),
                         0x20: _stub(c, 0, ret=r.choice((0, 1, 1, r.getrandbits(32))))})
    c.emu.w32(hit + 8, hgeom)
    o2 = _obj(c, 0x20, {0x318: _stub(c, 0, ret=r.choice((0, 1, 2, r.getrandbits(32))))})
    own = _obj(c, 0x20, {0x2e8: _stub(c, 0, ret=r.choice((o2, o2, 0)))})
    mat = _rnd(c, 0x40)
    h = _rnd(c, 0x90)
    rm = _obj(c, 0xae0, {0x58: _hmap(c, [(hh, hit), (oh, own if r.random() < 0.8 else 0)]),
                         0x60: _seq(c, 1, [r.choice((h, h, 0))]),
                         0x114: _stub(c, 4, ret=rid),
                         0x160: _seq(c, 1, [r.choice((mat, mat, 0)), mat])})
    entries = [_entry(c, hh) for _ in range(4)]
    world = _obj(c, 0x20, {0x2e0: _cast(c, entries)})
    c.emu.w32(rm + 0xadc, world)
    rooms = _rnd(c, 3 * 0x70)
    for i in range(3):
        c.emu.wbytes(rooms + 0x70 * i + 0x5c, struct.pack('<H', r.choice((0, 0, r.randint(1, 9)))))
    rq = _rnd(c, 0x20)
    c.emu.w32(rm + 8, _obj(c, 0x60, {0x4c: _stub(c, 0, ret=rooms), 0x5c: _stub(c, 1, ret=r.choice((rq, rq, 0)))}))
    # the game object
    gobj = _obj(c, 0x1ab0, {0x1c0: _rndstub(c, [r.choice((r.random(), 0.0, 1.0, 0.5)) for _ in range(2)])})
    c.emu.w32(gobj + 0x40, now)
    c.emu.w32(gobj + 0x44, prev)
    c.emu.w32(gobj + 0x9b, rm)
    c.emu.wf32(gobj + 0x9c7, 0.0)
    rt = _rnd(c, 0x20)
    mt = _rnd(c, 0x10)
    c.emu.w32(rt + 0x1c, _obj(c, 0x10, {0x74: _stub(c, 1, ret=r.getrandbits(32))}))
    c.emu.w32(rt + 0x18, _obj(c, 0x10, {0xf8: _stub(c, 1, ret=r.choice((mt, mt, 0)))}))
    c.emu.w32(gobj + 0x1aa3, rt)
    ss = _obj(c, 0x20, {0x58: _seq(c, 2, [r.choice((0, r.getrandbits(32))), r.getrandbits(32)]),
                        0x5c: _stub(c, 1, ret=r.getrandbits(32)), 0x11c: _stub(c, 4, skip=(2,), copy=(2, [(4 * i, 'd') for i in range(9)]), ret=0)})
    c.emu.w32(gobj + 0x1a9f, ss if r.random() < 0.85 else 0)
    c.emu.w32(0x70039c, gobj)
    # the projectile's geometry
    stick = _obj(c, 0x10, {0x68: _stub(c, 2)})
    geom = _obj(c, 0x20, {0x80: _stub(c, 2, skip=(0, 1), fills=((0, _fv(c, [r.uniform(-1, 1) for _ in range(9)]), 9),
                                                    (1, _fv(c, [r.uniform(-1500, 1500) for _ in range(3)]), 3))),
                          0x7c: _stub(c, 2, skip=(0, 1), copy=(1, XYZ)),
                          0x128: _sendcmd(c, rid),
                          0x100: _stub(c, 1, ret=r.choice((stick, stick, 0))),
                          0xbc: _stub(c, 1), 0x28: _stub(c, 0)})
    self = _rnd(c, 0xa0)
    c.emu.w32(self + 0x44, geom)
    c.emu.w32(self + 0x4c, 0)
    c.emu.w32(self + 0x61, r.choice((oh, oh, r.getrandbits(32))))
    c.emu.w32(self + 0x6d, _particle(c, r.choice((prevs, prevs - r.uniform(0, 2), nows))))
    c.emu.w32(self + 0x8d, _rnd(c, 0x70))
    c.emu.wf32(self + 0x48, r.choice((0.0, 0.0, r.uniform(0.5, 4.0), 3.0)))
    c.emu.wf32(self + 0x81, nows - r.uniform(-1, 4))
    c.emu.wf32(self + 0x85, r.choice((0.0, nows - r.uniform(0, 0.4), nows)))
    fl = r.getrandbits(32) & r.choice((0x76, 0x74, 0x34, 0x30, 0x60, 0xff))
    c.emu.w32(self + 0x89, fl | (r.getrandbits(32) & 0xffff0000 if r.random() < 0.2 else 0))
    c.emu.wbytes(self + 0x50, bytes([r.choice((0, 1))]))
    c.emu.wbytes(self + 0x9d, struct.pack('<H', (rid + r.randint(1, 0xfffe)) & 0xffff))
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x43e960, 'vsubInPlace', 'fastcall', None, ret=None, gen=_vs, note='batch68')
S(0x4b9940, 'ZProjectile::FrameUpdateBallistic', 'thiscall', None, ret=None, gen=_fub,
  note='batch68; GetPos, Init, Explode, GetMaterialDesc, GetOwnerRoom and AddSound3d as exe code')
