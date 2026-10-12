"""specs_s1005.py - unclaimed-07 batch 5 (slice 6): ZMovementGuide::Save (0x489d20), ~ZCollisionBase (0x4eb3e0) and
CEnemyFlag::Load2 (0x5c1b20). Save and load objects are logging vtables. The CRT free helper 0x634273 (cdecl) and
0x4690b0 (thiscall, no arguments) are hooked to logging stubs. The sys object at 0x70039c is a fake per case."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _save(c):
    e = c.emu
    o = _rnd(c, 0x400)
    save = _rnd(c, 0x100)
    e.w32(save, e.logging_vtable('zsave', 0x70 // 4, impl={0x4c: _const(0), 0x64: _const(0)},
                                 argwords={0x4c: 1, 0x64: 1}))
    return [o, save]


def _free634273(em, r):
    em.calllog.append(('free634273', 0, None, (em.arg32(0), em.arg32(1))))
    em.ret(argbytes=0)


def _h4690b0(em, r):
    em.calllog.append(('ext4690b0', 0, em.reg('ecx'), ()))
    em.ret()


def _dtor(c):
    e = c.emu
    o = _rnd(c, 0x200)
    e.hook(0x634273, _free634273)
    e.hook(0x4690b0, _h4690b0)
    return [o, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


def _load2(c):
    e = c.emu
    o = _rnd(c, 0x200)
    use = c.rng.random() < 0.8
    r_obj = _rnd(c, 0x100)
    e.w32(r_obj, e.logging_vtable('enemyflag_r', 0x104 // 4, impl={0x100: _const(c.rng.getrandbits(32))},
                                  argwords={0x100: 1}))
    b = _rnd(c, 0x100)
    e.w32(b, e.logging_vtable('enemyflag_b', 0x260 // 4,
                              impl={0x25c: _const(r_obj if use else 0)}, argwords={0x25c: 2}))
    a = _rnd(c, 0x1000)
    e.w32(a + 0xadc, b)
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, a)
    e.w32(0x70039c, sys)
    return [o]


S(0x489d20, 'ZMovementGuide::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-07 batch 5; slot +0x4c float at +0xc, slot +0x64 dword at +0x375')
S(0x4eb3e0, 'ZCollisionBase::~ (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-07 batch 5; vtable 0x697738; 0x4690b0(this+4); free 0x634273 when bit 0 set')
S(0x5c1b20, 'CEnemyFlag::Load2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_load2,
  note='unclaimed-07 batch 5; sys+0x9b+0xadc slot +0x25c then slot +0x100 stored at +0xec')
