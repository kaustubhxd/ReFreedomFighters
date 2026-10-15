"""specs_c108.py - climb thread batch 108: 0x5e2590 ZFFHeroMovementFall::GetActiveAnim (landing)."""
import struct
from pilot import S
from ckit import obj, rnd, floats, wfloats, cstr, crt_setup, rvt


def _fga(c):
    r = c.rng
    e = c.emu
    crt_setup(e)
    self_ = rnd(c, 0x5c0)
    e.w8(self_ + 0x555, r.choice([0, 1, 1]))
    e.w8(self_ + 0x556, r.choice([0, 1]))
    e.w8(self_ + 0x577, r.choice([0, 0, 1]))
    t0 = r.randint(0, 1 << 20)
    for off in (0x55b, 0x55f):
        wfloats(e, self_ + off, [(t0 - r.choice([0, 10, 100, 1000, r.randint(-100, 3000)])) / 1024.0])
    pos = c.fbuf(3)
    wfloats(e, self_ + 0x557, [e.rf32(pos + 4) + r.choice([0.0, 50.0, 300.0, -10.0, c.fv(-500, 500)])])
    wfloats(e, self_ + 0x54c, [r.choice([0.0, 100.0, 250.0, c.fv(0, 400)])])
    wfloats(e, self_ + 0x550, [r.choice([1.0, 0.5, c.fv(0, 3)])])
    for off in (0x563, 0x567):
        if r.random() < 0.8:
            an = rnd(c, 0x80)
            e.w32(an + 0x6c, r.choice([15, 25, 30, r.randint(0, 60)]))
            e.w32(an + 0x60, r.randint(0, 10))
            e.w32(an + 0x64, e.r32(an + 0x60) + r.randint(-2, 40))
            e.mu.mem_write(self_ + off, struct.pack('<I', an))
        else:
            e.mu.mem_write(self_ + off, struct.pack('<I', 0))
    # ray, splash and engine (as in specs_c107)
    hit = r.random() < 0.8
    co_fill = bytes(r.getrandbits(8) for _ in range(0x70))
    tri = [c.fv(-5, 5) for _ in range(9)]
    hp = [c.fv(-50, 50) for _ in range(3)]
    hitobj = obj(e, 'hitgeom', 0x10, {0x88: (1, lambda e, t, a: (0, None, floats(e, a[0], 3)))})
    holder = rnd(c, 0x60)
    e.w32(holder + 0x54, hitobj)

    def ray(e, t, a):
        log = (e.r32(a[0]), a[1], floats(e, a[2], 3), floats(e, a[3], 3), a[4], a[5], a[6], a[7])
        e.wbytes(a[0] + 4, co_fill[4:])
        wfloats(e, a[0] + 4, hp)
        e.w32(a[0] + 0x10, holder)
        wfloats(e, a[0] + 0x14, tri)
        return (r.choice([1, 0x101]) if hit else r.choice([0, 0x100]), None, log)
    rayobj = obj(e, 'ray', 0x10, {0x30: (8, ray)})
    coll = rnd(c, 0x20)
    e.w32(coll + 0x1c, rayobj)
    dbg = obj(e, 'dbg', 0x10, {0x188: (4, None, 0)})
    rv = [r.random() for _ in range(2)]

    def rand(e, t, a):
        return (0, rv.pop(0) if rv else 0.5, (a[0], a[1]))
    geoms = {}

    def gref(e, t, a):
        return (geoms.get(a[0], 0), None, (a[0],))
    g60s = {}

    def g60(e, t, a):
        if a[0] not in g60s:
            g60s[a[0]] = rnd(c, 0x90) if r.random() < 0.7 else 0
        return (g60s[a[0]], None, (a[0],))
    p = rnd(c, 0x20) if r.random() < 0.9 else 0
    db = obj(e, 'enginedb', 0x10, {0x4c: (1, lambda e, t, a: (0x4c4c0000 | (a[0] & 0xfff), None, (a[0],))),
                                   0x58: (1, gref), 0x60: (1, g60),
                                   0x160: (1, lambda e, t, a: (p, None, (a[0],)))})
    sys_ = obj(e, 'sys', 0x1b00, {0x190: (0, lambda e, t, a: (dbg, None, ())), 0x1c0: (2, rand)}, nslots=0x80, rng=r)
    e.mu.mem_write(sys_ + 0x9b, struct.pack('<I', db))
    e.mu.mem_write(sys_ + 0x40, struct.pack('<i', t0))
    snd = 0
    if r.random() < 0.6:
        snd = obj(e, 'snd', 0x10, {0x5c: (1, lambda e, t, a: (hash(bytes(e.rbytes(a[0], 8)).split(b'\0')[0]) & 0xffff, None,
                                                               (bytes(e.rbytes(a[0], 8)).split(b'\0')[0],))),
                                   0x58: (2, lambda e, t, a: ((a[0] * 3 + a[1]) & 0xffffffff, None, None))})
    e.mu.mem_write(sys_ + 0x1a9f, struct.pack('<I', snd))
    e.mu.mem_write(sys_ + 0x1aa3, struct.pack('<I', coll))
    e.w32(0x70039c, sys_)
    q = obj(e, 'splash', 0x20, {0x1bc: (7, lambda e, t, a: (0, None, (a[0], floats(e, a[1], 9), floats(e, a[2], 3)) + tuple(a[3:])))},
            nslots=0x80)
    cls = rnd(c, 0x30)
    if r.random() < 0.9:
        v = struct.unpack('<I', e.rbytes(cls + 0x23, 4))[0] | 0x100000
        e.mu.mem_write(cls + 0x23, struct.pack('<I', v))
    e.w32(q + 0xc, cls)
    if p:
        qref = 0x50000 | r.getrandbits(8)
        e.w32(p + 0x18, qref)
        if r.random() < 0.9:
            geoms[qref] = q
    groundref = 0x60000 | r.getrandbits(8)
    if r.random() < 0.9:
        ground = rnd(c, 0x10)
        nm = r.choice([b'WaterWalk_01', b'waterswim', b'WATERWALK', b'Road', b'WaterSwimDeep', None])
        e.w32(ground + 4, cstr(e, nm) if nm is not None else 0)
        geoms[groundref] = ground
    e.w32(0x7003b0, e.stub_fn('assert', lambda e, res: (e.calllog.append(('assert',)), e.ret())))
    owner = obj(e, 'owner', 0x10, {0x400: (1, None), 0x3f8: (1, lambda e, t, a: (0x70000 + a[0], None, (a[0],)))},
                )
    e.w32(self_ + 4, owner)
    offv = [c.fv(-100, 100) for _ in range(3)]

    def topos(e, t, a):
        v = [e.rf32(a[0] + 4 * i) + offv[i] for i in range(3)]
        log = floats(e, a[0], 3)
        wfloats(e, a[0], v)
        return (0, None, log)
    gr = r.choice([0, 1, 0x100])
    hero = obj(e, 'hero', 0x960, {0x84: (1, topos), 0x5a4: (0, lambda e, t, a: (gr, None, ())),
                                  0x428: (0, lambda e, t, a: (groundref, None, ())),
                                  0x3f4: (1, lambda e, t, a: (a[0] ^ 0x5a5a, None, (a[0],))),
                                  0x664: (1, lambda e, t, a: (0, None, floats(e, a[0], 12)))}, rng=r)
    wfloats(e, hero + 0x942, [r.choice([0.0, 4.0, 5.0, 6.0, c.fv(0, 20)])])
    e.mu.mem_write(hero + 0x7fb, struct.pack('<f', r.choice([1.0, 0.0, c.fv(0, 5)])))
    e.w32(hero + 8, rnd(c, 0x10))
    e.mu.mem_write(self_ + 0x36d, struct.pack('<I', hero))
    room = obj(e, 'room', 0x10, {0x94: (2, lambda e, t, a: (0, None, (floats(e, a[0], 9), floats(e, a[1], 3))))}, nslots=0x30) \
        if r.random() < 0.85 else 0

    def gor(e, res, room=room):
        e.calllog.append(('GetOwnerRoom', e.reg('ecx')))
        e.ret(eax=room)
    e.hook(0x4db3b0, gor)
    out = rnd(c, 8)
    return [self_, out, c.fbuf(3), c.fbuf(3), c.fbuf(3), pos]


S(0x5e2590, 'ZFFHeroMovementFall::GetActiveAnim', 'thiscall', None, ret='st0', gen=_fga,
  note='c108; GetOwnerRoom is a hook; striwcmp, createmat, vneg, PSVECAdd and the hit normal run as original')
