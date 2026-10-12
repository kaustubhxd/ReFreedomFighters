"""specs_s257.py - area 22, batch257 (src/batch257.cpp): CActionController::GetCurrentController(bool). The bool is passed
in ecx (random upper bytes). SetControl 0x4dc630 is hooked by address (GUESS stub, logged; the real body is blocked on the
render-manager object, docs/20)."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _pyvt, _hk, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _z(em, a):
    return (0, None)


def _g_4a0d40(c):
    e = c.emu
    _log_world(c)
    _hk(c, 0x4dc630, 'SetControl', 2)
    h = c.rng.choice([_r(c)] * 3 + [0])

    def find(em, r):
        name, out = em.arg32(0), em.arg32(1)
        em.calllog.append(('scene.88', 0x88, None, (em.rbytes(name, 20).split(b'\0')[0], em.r32(out))))
        em.w32(out, h)
        em.ret(eax=0, argbytes=8)
    scene = _rnd(c, 0x10)
    e.w32(scene, _pyvt(c, {0x88: find}))
    mgr = _rnd(c, 0x10)
    e.w32(mgr, _multi_vt(c, {0xcc: (lambda em, a, v=c.rng.choice([0, 0, _r(c)]): (v, None), 1)}))
    e.w32(0x70038c, mgr)
    lst = _rnd(c, 0x20)
    e.w32(lst, _multi_vt(c, {0x10c: (lambda em, a, v=c.rng.choice([_r(c)] * 4 + [0]): (v, None), 2),
                             0x154: (_z, 0), 0x124: (_z, 4)}))
    mk = _rnd(c, 0x10)
    e.w32(mk, _multi_vt(c, {0x294: (lambda em, a, l=lst: (l, None), 4)}))
    db = _rnd(c, 0xb00)
    e.w32(db, _multi_vt(c, {0x138: (lambda em, a, s=scene: (s, None), 0)}))
    e.w32(db + 0xadc, mk)
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    e.mu.ctl_flush_tb()
    return [(_r(c) & ~0xff) | c.rng.choice([0, 1, 1, 0x80])]


S(0x4a0d40, 'CActionController::GetCurrentController', 'thiscall', None, ret='eax', gen=_g_4a0d40,
  note='batch257; bool in cl; SetControl 0x4dc630 hooked by address (GUESS stub)')
