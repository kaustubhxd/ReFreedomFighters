"""specs_s256.py - area 22, batch256 (src/batch256.cpp): ZFFHERO::Resurrect. Unported callees are hooked by address and
logged (GUESS stubs, not the real bodies): 0x595100 SetupInventoryBindingList, 0x59a850 RemoveActorActionMarker,
0x5e0dd0 SetHealth (float passed as bits). Vtable callees are logged slots with the exe's pushed arities."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _z(em, a):
    return (0, None)


def _g_594600(c):
    e = c.emu
    _hk(c, 0x595100, 'SetupInventoryBindingList', 0)
    _hk(c, 0x59a850, 'RemoveActorActionMarker', 1)
    _hk(c, 0x5e0dd0, 'SetHealth', 1)
    self_ = _rnd(c, 0xa00)
    e.w32(self_, _multi_vt(c, {0x438: (lambda em, a, v=(_r(c) & ~0xff) | c.rng.choice([1, 1, 1, 0, 0x10]): (v, None), 0),
                               0x128: (_z, 3), 0x644: (_z, 1), 0x588: (_z, 0), 0x36c: (_z, 0)}))
    ctl = _rnd(c, 0x10)
    e.w32(ctl, _multi_vt(c, {0x30: (_z, 4)}))
    e.w32(self_ + 0x6c, ctl)
    e.wbytes(self_ + 0x9e7, bytes([c.rng.choice([0, 1, 0x40])]))
    e.w32(self_ + 0x852, c.rng.choice([_rnd(c, 0x10)] * 3 + [0]))
    tab = _rnd(c, 0x500)
    n = c.rng.choice([0, 1, 2, 4])
    e.w32(tab + 0x408, n)
    for i in range(n):
        ent = 0
        if c.rng.random() < 0.75:
            ent = _rnd(c, 0x860)
            e.w32(ent + 0x852, _rnd(c, 0x10))
        e.w32(tab + 0x40c + 4 * i, ent)
    e.w32(0x7003b8, tab)
    blocks = [_rnd(c, 0x20), _rnd(c, 0x20)]
    osd = _rnd(c, 0x10)
    e.w32(osd, _multi_vt(c, {0x94: (lambda em, a, b=blocks: (b.pop(0) if b else 0x7777, None), 0)}))
    h = c.rng.choice([_r(c)] * 4 + [0])
    g = 0
    if c.rng.random() < 0.8:
        m = _rnd(c, 0x10)
        e.w32(m, _multi_vt(c, {0x300: (_z, 0)}))
        g = _rnd(c, 0x10)
        e.w32(g, _multi_vt(c, {0x2c4: (lambda em, a, m=m: (m, None), 0)}))

    def find(em, r):
        name, out = em.arg32(0), em.arg32(1)
        em.calllog.append(('scene.88', 0x88, None, (em.rbytes(name, 16).split(b'\0')[0], em.r32(out))))
        em.w32(out, h)
        em.ret(eax=0, argbytes=8)
    scene = _rnd(c, 0x10)
    e.w32(scene, _pyvt(c, {0x88: find}))
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a: (g if a[0] == h else 0, None), 1),
                            0x114: (lambda em, a, v=_r(c): (v, None), 4),
                            0x138: (lambda em, a, s=scene: (s, None), 0)}))
    rm = _rnd(c, 0x1b00)
    e.w32(rm + 0x9b, db)
    e.w32(rm + 0x1aa3, osd)
    e.w32(0x70039c, rm)
    e.mu.ctl_flush_tb()
    return [self_]


S(0x594600, 'ZFFHERO::Resurrect', 'thiscall', None, ret=None, gen=_g_594600,
  note='batch256; void; 0x595100, 0x59a850, 0x5e0dd0 hooked by address (GUESS stubs)')
