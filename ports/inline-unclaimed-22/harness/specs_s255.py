"""specs_s255.py - area 22, batch255 (src/batch255.cpp): CInventory::GiveItem. The render manager (vt 0x14/0x10, byte
+0x9b7), the engine db (vt 0x138 scene, vt 0x58 handle map), the scene's vt[0x88](group, &h) (Python; logs the group name,
writes h), the inventory list at +0x11a (Python start/next as in specs_s251) and the geoms (vt 0x1e0 class test, name at +4,
vt 0x324 ammo) are logged; _stricmp goes through the IAT stub."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _pyvt, _stricmp_stub

NAMES = [b'Molotov', b'MOLOTOV', b'FragGrenade', b'fraggrenade', b'Pistol', b'Molotov2', b'', None]


def _r(c):
    return c.rng.getrandbits(32)


def _g_4abdd0(c):
    e = c.emu
    _stricmp_stub(c)
    n = c.rng.choice([0, 1, 2, 4, 6])
    ids = [_r(c) for _ in range(n)]
    hmap = {}
    for i in ids:
        if c.rng.random() < 0.15:
            hmap[i] = 0
            continue
        g = _rnd(c, 0x10)
        nm = c.rng.choice(NAMES)
        if nm is None:
            e.w32(g + 4, 0)
        else:
            s = e.alloc(len(nm) + 1, 4)
            e.wbytes(s, nm + b'\0')
            e.w32(g + 4, s)
        e.w32(g, _multi_vt(c, {0x1e0: (lambda em, a, v=(_r(c) & ~0xff) | c.rng.choice([1, 1, 0, 0x20]): (v, None), 1),
                               0x324: (lambda em, a: (0, None), 1)}))
        hmap[i] = g
    hs = {}
    for grp in (0x690ad0, 0x690adc):
        h = c.rng.choice([_r(c)] * 8 + [0])
        hs[grp] = h
        if h:
            hmap[h] = c.rng.choice([_rnd(c, 0x10)] * 8 + [0])

    def find(em, r):
        name, out = em.arg32(0), em.arg32(1)
        em.calllog.append(('scene.88', 0x88, None, (em.rbytes(name, 16).split(b'\0')[0],)))
        em.w32(out, hs.get(name, 0x5555))
        em.ret(eax=0, argbytes=8)
    scene = _rnd(c, 0x10)
    e.w32(scene, _pyvt(c, {0x88: find}))
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a, m=hmap: (m.get(a[0], 0), None), 1),
                            0x138: (lambda em, a, s=scene: (s, None), 0)}))
    rm = _rnd(c, 0xa00)
    e.w32(rm, _multi_vt(c, {0x10: (lambda em, a: (0, None), 0), 0x14: (lambda em, a: (0, None), 0)}))
    e.w32(rm + 0x9b, db)
    e.wbytes(rm + 0x9b7, bytes([c.rng.choice([0, 1, 0x80])]))
    e.w32(0x70039c, rm)
    st = {'k': 0}

    def start(em, r):
        em.calllog.append(('list.4c', 0x4c, None, ()))
        st['k'] = 0
        em.w32(em.arg32(0), 0x66000000)
        em.ret(eax=0x2468ace0, argbytes=4)

    def nxt(em, r):
        k = st['k']
        em.calllog.append(('list.5c', 0x5c, None, (em.r32(em.arg32(0)),)))
        if k < len(ids):
            em.w32(em.arg32(0), 0x66000001 + k)
            v = ids[k]
        else:
            em.w32(em.arg32(0), 0)
            v = 0x7777aaaa
        st['k'] = k + 1
        em.ret(eax=v, argbytes=4)
    self_ = _rnd(c, 0x200)
    e.w32(self_, _multi_vt(c, {0x88: (lambda em, a: (0, None), 2)}))
    e.w32(self_ + 0x11a, _pyvt(c, {0x4c: start, 0x5c: nxt}))
    e.mu.ctl_flush_tb()
    return [self_, _r(c)]


S(0x4abdd0, 'CInventory::GiveItem', 'thiscall', None, ret=None, gen=_g_4abdd0,
  note='batch255; void; stack cookie not reproduced; early exits skip the manager vt[0x10] call as in the exe')
