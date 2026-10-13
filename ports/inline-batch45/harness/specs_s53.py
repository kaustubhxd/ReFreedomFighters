"""specs_s53.py - inline session batch 53: ZFFHERO::ControlWeapons and ZFFHERO::ForwardEventToFollowers.
The hero's and the weapon's vtable callees are heap stubs (saved args, call counts, per-input eax). The ZCamHelper at
hero+0x85a is the batch 52 camera setup, so GetFireAimPos runs as exe code with its whole aim chain."""
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


def _cam_base(c):
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




def _offset(c, cam):
    p2 = c.emu.alloc(16, 4)
    for j in range(3):
        c.emu.wf32(p2 + 4 * j, c.emu.rf32(cam + 0xd22 + 4 * j) + c.rng.uniform(-150.0, 150.0))
    return p2


def _actor(c, cam, p2=None, p1=None):
    r = c.rng
    if p1 is None:
        p1 = _vec(c, 3, -100.0, 100.0)
    if p2 is None:
        p2 = _offset(c, cam)
    t = _obj(c, 0x60, {0x438: _stub(c, 0, ret=r.getrandbits(32) & (0xffffff00 if r.random() < 0.9 else 0xffffffff)),
                       0x3a0: _stub(c, 1, fills=((0, p1, 3),), ret=r.getrandbits(32), skip=(0,)),
                       0x3a8: _stub(c, 1, fills=((0, p1, 3),), ret=r.getrandbits(32), skip=(0,)),
                       0x398: _stub(c, 1),
                       0x84: _stub(c, 1, adds=((0, p2, 3),), skip=(0,))})
    geom = _rnd(c, 0x40)
    fl = r.getrandbits(32)
    c.emu.w32(geom + 0x3c, fl & ~0x400 if r.random() < 0.8 else fl | 0x400)
    c.emu.w32(t + 8, geom)
    if r.random() < 0.3:
        c.emu.w32(t + 0x54, 0)
    else:
        team = _rnd(c, 0x10)
        c.emu.w32(team + 4, r.randint(0, 31) if r.random() < 0.9 else r.getrandbits(32))
        c.emu.w32(t + 0x54, team)
    return t


def _world(c):
    r = c.rng
    fields = [(0, 'd'), (4, 'd'), (8, 'd'), (0xc, 'd'), (0x10, 'd'), (0x14, 'd'), (0x34, 'd'), (0x44, 'd'), (0x6c, 'b')]
    w = _obj(c, 0x10, {0x2e0: _stub(c, 6, ret=r.getrandbits(32) & (0xffffff00 if r.random() < 0.5 else 0xffffffff),
                                    skip=(0,), copy=(0, fields))})
    rm = _obj(c, 0xae0, {0x4c: _stub(c, 1, ret=r.getrandbits(32))})
    c.emu.w32(rm + 0xadc, w)
    sysobj = _rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)


def _cam(c):
    r = c.rng
    cam = _cam_base(c)
    c.emu.w32(cam + 0xb50, r.getrandbits(32) | (0xffffffff if r.random() < 0.3 else 0))
    c.emu.wf32(cam + 0xe01, r.uniform(0.0, 90000.0))
    c.emu.wf32(cam + 0xdf9, r.uniform(0.0, 3.5))
    c.emu.wbytes(cam + 0xb45, bytes([0 if r.random() < 0.6 else r.randint(1, 255)]))
    for j in range(3):
        c.emu.wf32(cam + 0xcad + 4 * j, r.uniform(-100.0, 100.0))
    c.emu.w32(cam + 0x44, _actor(c, cam))
    _world(c)
    return cam


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _can(c):
    r = c.rng
    cam = _cam(c)
    if r.random() < 0.1:
        t = c.emu.r32(cam + 0x44)
    else:
        p1 = _vec(c, 3, -100.0, 100.0)
        p2 = _offset(c, cam)
        t = _actor(c, cam, p2, p1)
        if r.random() < 0.3:   # put the squared range right at this actor's distance (float order of vdist2)
            pos = [c.emu.rf32(p1 + 4 * j) for j in range(3)]
            pos[1] = _f(pos[1] + 10.0)
            pos = [_f(pos[j] + c.emu.rf32(p2 + 4 * j)) for j in range(3)]
            d = [_f(pos[j] - c.emu.rf32(cam + 0xd22 + 4 * j)) for j in range(3)]
            d2 = _f(_f(_f(d[0] * d[0]) + _f(d[1] * d[1])) + _f(d[2] * d[2]))
            c.emu.wf32(cam + 0xe01, r.choice((d2, _f(d2 * 0.9999999), _f(d2 + 50.0))))
    c.emu.mu.ctl_flush_tb()
    return [cam, t]


def _pick(c):
    r = c.rng
    cam = _cam(c)
    shared = _offset(c, cam) if r.random() < 0.3 else None   # several actors at one spot: equal angles test the tie rule
    game = _rnd(c, 0x4d0)
    n1 = r.randint(0, 4)
    c.emu.w32(game + 0x4b0, n1)
    for i in range(n1):
        if r.random() < 0.15:
            c.emu.w32(game + 0x4b4 + 4 * i, 0)
        else:
            rec = _rnd(c, 0x10)
            c.emu.w32(rec + 4, c.emu.r32(cam + 0x44) if r.random() < 0.1 else _actor(c, cam, shared))
            c.emu.w32(game + 0x4b4 + 4 * i, rec)
    n2 = r.randint(0, 4)
    c.emu.w32(game + 0x408, n2)
    for i in range(n2):
        c.emu.w32(game + 0x40c + 4 * i, 0 if r.random() < 0.15 else _actor(c, cam, shared))
    c.emu.w32(0x7003b8, game)
    c.emu.mu.ctl_flush_tb()
    return [cam]




def _hero_geom(c, cam):
    r = c.rng
    hero = c.emu.r32(cam + 0x44)
    geom = c.emu.r32(hero + 8)
    c.emu.w32(geom + 0x3c, r.getrandbits(32) & ~0xa000)   # no 0x2000 / 0x8000 (the render-list paths of SetControl)
    c.emu.w32(geom + 0x50, 0)
    return geom


def _ray_world(c, cam, geom):
    r = c.rng
    fields = [(0, 'd'), (4, 'd'), (8, 'd'), (0xc, 'd'), (0x10, 'd'), (0x14, 'd'), (0x34, 'd'), (0x6c, 'b')]
    hit = _vec(c, 4, -500.0, 500.0)
    hv = r.getrandbits(32)
    c.emu.w32(hit + 12, hv)
    w = _obj(c, 0x10, {0x2e0: _stub(c, 6, ret=r.getrandbits(32) & (0xffffff00 if r.random() < 0.4 else 0xffffffff),
                                    skip=(0,), copy=(0, fields), peeks=(geom + 0x3c,),
                                    ofills=((0, 0x28, hit, 3), (0, 0x44, hit + 12, 1)))})
    rm = _obj(c, 0xae0, {0x4c: _stub(c, 1, ret=r.getrandbits(32))})
    c.emu.w32(rm + 0xadc, w)
    sysobj = c.emu.r32(0x70039c)
    c.emu.w32(sysobj + 0x9b, rm)


def _find3d(c):
    r = c.rng
    cam = _cam(c)
    geom = _hero_geom(c, cam)
    _ray_world(c, cam, geom)
    out = _rnd(c, 0x10)
    frm = _vec(c, 3, -500.0, 500.0)
    dr = _vec(c, 3, -500.0, 500.0)
    mask = r.choice((2, 2, 1, 3, 0x10, 0x52, 0))
    c.emu.mu.ctl_flush_tb()
    return [cam, out, frm, dr, mask, r.getrandbits(32), r.getrandbits(32)]


def _fireaim_cam(c):
    r = c.rng
    cam = _cam(c)
    game = _rnd(c, 0x4d0)
    for base, cnt in ((0x4b4, 0x4b0), (0x40c, 0x408)):
        n = r.randint(0, 3)
        c.emu.w32(game + cnt, n)
        for i in range(n):
            a = _actor(c, cam)
            if base == 0x4b4:
                rec = _rnd(c, 0x10)
                c.emu.w32(rec + 4, a)
                a = rec
            c.emu.w32(game + base + 4 * i, a)
    c.emu.w32(0x7003b8, game)
    geom = _hero_geom(c, cam)
    _ray_world(c, cam, geom)
    # set-aim-target: render-manager slot 0x58 resolves the handle to an actor, whose slot 0x1e0 says if it counts
    rm = c.emu.r32(c.emu.r32(0x70039c) + 0x9b)
    tgt = _actor(c, cam)
    c.emu.w32(c.emu.r32(tgt) + 0x1e0, _stub(c, 1, ret=r.getrandbits(32) & (0xffffff00 if r.random() < 0.3 else 0xffffffff)))
    rvt = c.emu.alloc(0x60, 4)
    c.emu.w32(rvt + 0x4c, c.emu.r32(c.emu.r32(rm) + 0x4c))
    c.emu.w32(rvt + 0x58, _stub(c, 1, ret=tgt if r.random() < 0.8 else 0))
    c.emu.w32(rm, rvt)
    hero = c.emu.r32(cam + 0x44)
    team = _rnd(c, 0x10)
    c.emu.w32(hero + 0x54, team)
    c.emu.wbytes(cam + 0xd32, bytes([0 if r.random() < 0.5 else 1]))
    c.emu.wbytes(cam + 0xd33, bytes([0 if r.random() < 0.7 else 1]))
    c.emu.w32(cam + 0xad5, r.choice((4, 4, 5, 0)))
    for j in range(3):
        c.emu.wf32(cam + 0xd15 + 4 * j, r.uniform(-100.0, 100.0))
    return cam




def _followers(c, self):
    r = c.rng
    n = r.randint(0, 3)
    c.emu.w32(self + 0xa16, n)
    for i in range(n):
        f = _obj(c, 0x10, {0x128: _stub(c, 3)})
        c.emu.w32(self + 0xa1a + 0x30 * i, f)


def _fef(c):
    r = c.rng
    self = _rnd(c, 0xb00)
    _followers(c, self)
    c.emu.mu.ctl_flush_tb()
    return [self, r.getrandbits(32), r.getrandbits(32)]


def _b(c, p):
    return c.rng.getrandbits(32) & (0xffffff00 if c.rng.random() < p else 0xffffffff)


def _cw(c):
    r = c.rng
    cam = _fireaim_cam(c)
    mag = _obj(c, 0x10, {0x328: _stub(c, 0, ret=_b(c, 0.3))})
    ammo = r.choice((0, 0, 3, 7))
    w = _obj(c, 0x40, {0x1e0: _stub(c, 1, ret=_b(c, 0.3)), 0x350: _stub(c, 0, ret=mag),
                       0x35c: _stub(c, 0, ret=ammo), 0x354: _stub(c, 0, ret=_b(c, 0.6)),
                       0x364: _stub(c, 0, ret=r.choice((ammo, 7, 10)))})
    slots = {0x504: _stub(c, 0, ret=w if r.random() < 0.9 else 0),
             0x3f0: _stub(c, 0, ret=r.choice((0, 0, 0, 0xd, 2))),
             0x3dc: _stub(c, 0), 0x560: _stub(c, 1, ret=r.choice((0, 1, 0x100))),
             0x4f0: _stub(c, 1), 0x4ec: _stub(c, 1), 0x65c: _stub(c, 1, skip=(0,)), 0x518: _stub(c, 1),
             0x8c: _stub(c, 1, skip=(0,)), 0x4b0: _stub(c, 6, skip=(0,)), 0x4b4: _stub(c, 5)}
    self = _obj(c, 0xb00, slots)
    for off, p in ((0x669, 0.5), (0x66b, 0.5), (0x7f0, 0.8)):
        c.emu.wbytes(self + off, bytes([0 if r.random() < p else r.randint(1, 255)]))
    now = r.randint(0, 1 << 20)   # tick count small enough that (t + 1) * 1024 is exact in float
    c.emu.w32(c.emu.r32(0x70039c) + 0x40, now)
    x = r.random()
    if x < 0.4:
        c.emu.wf32(self + 0x813, 0.0)
    elif x < 0.7:   # a burst timer around now (seconds; the exe compares trunc((t + 1) * 1024) with the tick count)
        k = -1024 if r.random() < 0.4 else r.randint(-1100, 100)   # -1024: the timer ends exactly now
        c.emu.wf32(self + 0x813, (now + k) / 1024.0)
    else:
        c.emu.wf32(self + 0x813, r.uniform(-5.0, 5.0))
    c.emu.wf32(self + 0x829, r.uniform(0.0, 2.0))
    c.emu.w32(self + 0x85a, cam)
    _followers(c, self)
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x591820, 'ZFFHERO::ForwardEventToFollowers', 'thiscall', None, ret=None, gen=_fef, note='batch53')
S(0x590240, 'ZFFHERO::ControlWeapons', 'thiscall', None, ret='al', gen=_cw,
  note='batch53; shoot root; GetFireAimPos chain and ForwardEventToFollowers as exe code')
