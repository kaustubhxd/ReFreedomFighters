"""specs_s1205.py - pathfinding batch 1205: ZPathfinderControl."""
from pilot import S
from pfspec import rnd, hooks, vtable, RET


def _det(e, a, n, salt):
    e.wbytes(a, bytes((salt * 131 + i * 29 + (salt >> 3)) & 0xff for i in range(n)))


def _msgs(c, ngeoms=4):
    e = c.emu
    geoms = []
    for k in range(ngeoms):
        g = rnd(c, 0x20)
        cnt = [0]

        def mp(em, a, k=k, cnt=cnt):
            cnt[0] += 1
            _det(em, a[0], 36, k * 7 + cnt[0])
            _det(em, a[1], 12, k * 11 + cnt[0] + 1)
        e.w32(g, vtable(c, 'geom%d' % k, 0x30, impl={0x80: mp}, argwords={0x80: 2}))
        e.w32(g + 8, rnd(c, 16))
        geoms.append(g)
    scene = e.alloc(16)
    pfref = c.rng.getrandbits(32)

    def find(em, a):
        em.w32(a[1], pfref)
    e.w32(scene, vtable(c, 'scene', 0x30, impl={0x88: find}, argwords={0x88: 2}))
    pf = c.rng.getrandbits(32)
    m = e.alloc(16)
    e.w32(m, vtable(c, 'msgtable', 0x50, impl={0x138: lambda em, a: scene,
                                                 0x58: lambda em, a: geoms[a[0] % ngeoms] if a[0] != pfref else pf},
                    argwords={0x58: 1}))
    sysi = rnd(c, 0xa0)
    e.w32(sysi + 0x9b, m)
    e.w32(0x70039c, sysi)
    return geoms


def _ctl(c):
    o = rnd(c, 0x60)
    return o


def _reftab(c, n):
    st = {'left': n}

    def init(em, a):
        st['left'] = n
        em.w32(a[0], 0x77)

    def nxt(em, a):
        if st['left'] > 0:
            st['left'] -= 1
            em.w32(a[0], c.rng.choice([1, 0x100, 0x80000000]))
            return 0x1000 + st['left'] * 3
        em.w32(a[0], 0)
        return c.rng.getrandbits(32)
    t = rnd(c, 0x1c)
    c.emu.w32(t, vtable(c, 'REFTAB', 0x20, impl={0x4c: init, 0x5c: nxt}, argwords={0x4c: 1, 0x5c: 1}))
    return t


def _setstate(c):
    hooks(c.emu, {0x4db7c0: ('ZBaseGeom::GetSize', 'this', 1, {'fill': {0: 12}})})
    _msgs(c)
    o = _ctl(c)
    c.emu.w32(o + 0x48, 0 if c.rng.random() < 0.1 else _reftab(c, c.rng.randint(0, 4)))
    pf = rnd(c, 0x10)
    c.emu.w32(pf, vtable(c, 'ZPathfinder3', 0x90, argwords={0x21c: 3}, opts={0x21c: {'peek': {0: 12, 1: 12}}}))
    c.emu.w32(o + 0x53, pf)
    return [o, c.rng.getrandbits(32)]


S(0x4c5770, 'ZPathfinderControl::SetPFLinkState', 'thiscall', None, gen=_setstate)


def _command(c):
    hooks(c.emu, {0x4c5770: ('SetPFLinkState', 'this', 1, {'mask': {0: 0xff}})})
    o = _ctl(c)
    r = c.rng
    ids = [r.getrandbits(16) for _ in range(3)]
    if r.random() < 0.2:
        ids[1] = ids[0]
    for k, v in enumerate(ids):
        c.emu.w16(o + 0x4c + 2 * k, v)
    c.emu.w8(o + 0x52, r.choice([0, 1, 2]))
    m = r.choice(ids + [r.getrandbits(16)]) | (r.getrandbits(16) << 16 if r.random() < 0.3 else 0)
    return [o, m, r.getrandbits(32)]


S(0x4c54d0, 'ZPathfinderControl::Command', 'thiscall', None, ret='eax', gen=_command)


def _init2(c):
    hooks(c.emu, {0x4c5770: ('SetPFLinkState', 'this', 1)})
    _msgs(c)
    return [_ctl(c)]


S(0x4c5620, 'ZPathfinderControl::Init2', 'thiscall', None, gen=_init2)


def _load2(c):
    hooks(c.emu, {0x4c5770: ('SetPFLinkState', 'this', 1)})
    return [_ctl(c)]


S(0x4c5680, 'ZPathfinderControl::Load2', 'thiscall', None, gen=_load2)


def _load(c):
    _msgs(c)
    lg = rnd(c, 0x10)
    c.emu.w32(lg, vtable(c, 'ZLoadGame', 0x40, argwords={0x68: 1}))
    return [_ctl(c), lg]


S(0x4c5690, 'ZPathfinderControl::Load', 'thiscall', None, ret='al', gen=_load)


def _save(c):
    sg = rnd(c, 0x10)
    c.emu.w32(sg, vtable(c, 'ZSaveGame', 0x40, argwords={0x60: 1}))
    return [_ctl(c), sg]


S(0x4c5750, 'ZPathfinderControl::Save', 'thiscall', None, ret='al', gen=_save)


def _readinput(c):
    hooks(c.emu, {0x4e5e40: ('DBREAD::u16', 'this', 0), 0x4e5e60: ('DBREAD::u32', 'this', 0),
                  0x4e6330: ('DBREAD::GetRefTab', 'this', 1)})
    RET[0x4e5e40] = c.rng.getrandbits(32)
    RET[0x4e5e60] = c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])
    return [_ctl(c), rnd(c, 0x10)]


S(0x4c5700, 'ZPathfinderControl::ReadInput', 'thiscall', None, gen=_readinput)
