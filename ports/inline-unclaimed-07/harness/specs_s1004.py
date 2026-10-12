"""specs_s1004.py - unclaimed-07 batch 4 (slice 6): ZRelayMessageList::Save (0x4b8b20) and the destructor
ZFFActorActionCloseCombat (0x5eaf20). The save object is a logging vtable (slot +0x4c records its float argument bits).
The CRT free helper 0x634273 is hooked to a logging stub that does not clean the stack (cdecl)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _relay_save(c):
    e = c.emu
    o = _rnd(c, 0x200)
    save = _rnd(c, 0x100)
    e.w32(save, e.logging_vtable('zsavegame', 0x50 // 4, impl={0x4c: lambda em, a: (0, None)}, argwords={0x4c: 1}))
    return [o, save]


def _free634273(em, r):
    em.calllog.append(('free634273', 0, None, (em.arg32(0), em.arg32(1))))
    em.ret(argbytes=0)


def _dtor(c):
    e = c.emu
    o = _rnd(c, 0x200)
    e.hook(0x634273, _free634273)
    return [o, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


S(0x4b8b20, 'ZRelayMessageList::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_relay_save,
  note='unclaimed-07 batch 4; clears bit 0x40 at +4; slot +0x4c with float at +0x54')
S(0x5eaf20, 'ZFFActorActionCloseCombat::~ (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-07 batch 4; vtable 0x685294; CRT free 0x634273(this, 0x51) when bit 0 set')
