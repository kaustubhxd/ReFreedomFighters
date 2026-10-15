"""specs_c107.py - climb thread batch 107: 0x581b60 COLI hit normal, 0x5e65b0 ZFFHeroMovementJump::Move."""
import struct
from pilot import S
from ckit import obj, rnd, floats, wfloats, cstr, crt_setup


def _hn(c):
    r = c.rng
    e = c.emu
    co = rnd(c, 0x70)
    pts = [[c.fv() for _ in range(3)] for _ in range(3)]
    k = r.random()
    if k < 0.15:
        pts[2] = list(pts[0])
    elif k < 0.5:
        pts = [[float(r.randint(-4, 4)) for _ in range(3)] for _ in range(3)]
    for i, p in enumerate(pts):
        wfloats(e, co + 0x14 + 12 * i, p)
    return [co, c.fbuf(3)]


S(0x581b60, 'COLI hit-triangle normal (guess)', 'thiscall', None, ret=None, gen=_hn, note='c107')


def _jm(c):
    r = c.rng
    e = c.emu
    crt_setup(e)
    self_ = rnd(c, 0x5c0)
    # own vtable: slot 0x40 and 0x48 move d (the new position)
    b = c.fbuf(3)
    bv = [e.rf32(b + 4 * i) for i in range(3)]
    planned = [bv[i] + r.choice([0.0, c.fv(-5, 5), c.fv(-5, 5)]) for i in range(3)]
    real = [bv[i] + (planned[i] - bv[i]) * r.choice([1.0, 0.5, 0.0, -0.5, 1.5, c.fv()]) for i in range(3)]

    def mk(vals):
        def f(e, t, a, vals=vals):
            wfloats(e, a[3], vals)
            return (0, None, None)
        return f
    vt_slots = {0x40: (5, mk(planned)), 0x48: (5, mk(real))}
    from ckit import rvt
    e.w32(self_, rvt(e, 'jump', vt_slots))
    wfloats(e, self_ + 0x5a3, [c.fv(-30, 30) for _ in range(3)])
    e.w8(self_ + 0x55e, 0 if r.random() < 0.8 else 1)
    e.w8(self_ + 0x559, 0 if r.random() < 0.8 else 1)
    # engine
    t0 = r.randint(0, 1 << 20)
    wfloats(e, self_ + 0x551, [(t0 - r.choice([0, 0xcc, 0xcd, 0x100, 5000, r.randint(-500, 500)])) / 1024.0])
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
    g60 = rnd(c, 0x80) if r.random() < 0.7 else 0
    p = rnd(c, 0x20) if r.random() < 0.9 else 0
    db = obj(e, 'enginedb', 0x10, {0x58: (1, gref), 0x60: (1, lambda e, t, a: (g60, None, (a[0],))),
                                   0x160: (1, lambda e, t, a: (p, None, (a[0],)))})
    sys_ = obj(e, 'sys', 0x1b00, {0x190: (0, lambda e, t, a: (dbg, None, ())), 0x1c0: (2, rand)}, nslots=0x80, rng=r)
    e.mu.mem_write(sys_ + 0x9b, struct.pack('<I', db))
    e.mu.mem_write(sys_ + 0x40, struct.pack('<i', t0))
    e.mu.mem_write(sys_ + 0x1a9f, struct.pack('<I', 0 if r.random() < 0.5 else 1))
    e.mu.mem_write(sys_ + 0x1aa3, struct.pack('<I', coll))
    e.w32(0x70039c, sys_)
    # splash template q and ground geom
    q = obj(e, 'splash', 0x20, {0x1bc: (7, lambda e, t, a: (0, None, (a[0], floats(e, a[1], 9), floats(e, a[2], 3)) + tuple(a[3:])))},
            nslots=0x80)
    cls = rnd(c, 0x30)
    if r.random() < 0.9:
        e.mu.mem_write(cls + 0x23, struct.pack('<I', e.r32(cls + 0x20) | 0))
        v = struct.unpack('<I', e.rbytes(cls + 0x23, 4))[0] | 0x100000
        e.mu.mem_write(cls + 0x23, struct.pack('<I', v))
    e.w32(q + 0xc, cls)
    if p:
        qref = 0x50000 | r.getrandbits(8)
        e.w32(p + 0x18, qref)
        if r.random() < 0.9:
            geoms[qref] = q
    groundref = 0x60000 | r.getrandbits(8)
    ground = rnd(c, 0x10)
    nm = r.choice([b'WaterWalk_01', b'waterswim', b'WATERWALK', b'Road', b'WaterSwimDeep', None])
    e.w32(ground + 4, cstr(e, nm) if nm is not None else 0)
    geoms[groundref] = ground
    e.w32(0x7003b0, e.stub_fn('assert', lambda e, res: (e.calllog.append(('assert',)), e.ret())))
    # owner and hero
    gr = r.choice([0, 1, 0x100])
    owner = obj(e, 'owner', 0x10, {0x5a4: (0, lambda e, t, a: (gr, None, ())), 0x400: (1, None),
                                   0x3f8: (1, lambda e, t, a: (0x70000 + a[0], None, (a[0],))),
                                   0x428: (0, lambda e, t, a: (groundref, None, ()))})
    e.w32(self_ + 4, owner)
    offv = [c.fv(-100, 100) for _ in range(3)]

    def topos(e, t, a):
        v = [e.rf32(a[0] + 4 * i) + offv[i] for i in range(3)]
        log = floats(e, a[0], 3)
        wfloats(e, a[0], v)
        return (0, None, log)
    hero = obj(e, 'hero', 0x960, {0x84: (1, topos)}, rng=r)
    wfloats(e, hero + 0x942, [r.choice([0.0, 4.0, 5.0, 6.0, c.fv(0, 20)])])
    e.w32(hero + 8, rnd(c, 0x10))
    e.mu.mem_write(self_ + 0x36d, struct.pack('<I', hero))
    room = obj(e, 'room', 0x10, {0x94: (2, lambda e, t, a: (0, None, (floats(e, a[0], 9), floats(e, a[1], 3))))}, nslots=0x30) \
        if r.random() < 0.85 else 0

    def gor(e, res, room=room):
        e.calllog.append(('GetOwnerRoom', e.reg('ecx')))
        e.ret(eax=room)
    e.hook(0x4db3b0, gor)
    return [self_, c.fbuf(3), b, c.fbuf(3), c.fbuf(3), c.fbuf(3)]


S(0x5e65b0, 'ZFFHeroMovementJump::Move', 'thiscall', None, ret=None, gen=_jm,
  note='c107; GetOwnerRoom is a hook; striwcmp, createmat, vneg, PSVEC helpers and the hit normal run as original')
