"""specs_s1002.py - unclaimed-07 batch 2 (docs/20-unclaimed-07.md): ZActionControlMap::Init (0x5b3dd0),
CActionController::End (0x4a0780) and ZInputActions::GetActionMapStatus (0x438260).

The engine interface at global 0x70039c is a fake object per case: slot +0xbc returns two fake objects in turn, and
the field at +0x9b is a fake controller whose slot +0x138 returns a fake object with a logging slot +0xa0. Every slot
is a logging stub (arguments and ECX are recorded), so a wrong order or argument shows up in the call log."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, impl, argwords=None, nslots=64):
    return c.emu.logging_vtable('unclaimed7', nslots, impl=impl, argwords=argwords or {})


def _const(v):
    return lambda e, a: (v, None)


def _init(c):
    e = c.emu
    o = _rnd(c, 0x200)
    a = _rnd(c, 0x100)
    b = _rnd(c, 0x100)
    e.w32(a, _vt(c, {0xb8: _const(c.rng.getrandbits(32))}))
    e.w32(b, _vt(c, {0xc0: _const(c.rng.getrandbits(32))}))
    seq = [a, b]
    sys = _rnd(c, 0x200)
    e.w32(sys, _vt(c, {0xbc: lambda em, args: (seq.pop(0), None)}))
    e.w32(0x70039c, sys)
    return [o]


def _end(c):
    e = c.emu
    o = _rnd(c, 0x800)
    d = _rnd(c, 0x100)
    e.w32(d, _vt(c, {0xa0: _const(0)}, {0xa0: 2}))
    ctl = _rnd(c, 0x100)
    e.w32(ctl, _vt(c, {0x138: lambda em, args: (d, None)}, nslots=0x140 // 4))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)
    return [o]


def _status(c):
    e = c.emu
    o = _rnd(c, 0x2000)
    buf = _rnd(c, 0x100)                  # object B; the entry P is B + 4, so P - 4 is a real object
    v = c.rng.getrandbits(32)
    e.w32(buf, _vt(c, {0x30: _const(v)}))
    p = buf + 4
    e.w32(p, c.rng.choice([3, 0, c.rng.getrandbits(32)]))
    e.w32(o, _vt(c, {0x58: _const(p)}, {0x58: 1}))
    return [o, c.rng.getrandbits(32)]


S(0x5b3dd0, 'ZActionControlMap::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-07 batch 2; g_sys slot +0xbc twice; bytes to +0x55 and +0x56')
S(0x4a0780, 'CActionController::End (unknown) thiscall', 'thiscall', None, ret=None, gen=_end,
  note='unclaimed-07 batch 2; ECX unused; sys+0x9b slot +0x138 then slot +0xa0 twice')
S(0x438260, 'ZInputActions::GetActionMapStatus (unknown) thiscall', 'thiscall', None, ret='eax', gen=_status,
  note='unclaimed-07 batch 2; slot +0x58 pointer; first dword 3 calls slot +0x30 on p-4')
