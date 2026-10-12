"""specs_s1001.py - unclaimed-07 batch 1 (docs/20-unclaimed-07.md): ZInputActions small functions, 0x438780 to 0x438880.

Each case gets a fresh 0x2000-byte object whose first dword is a fresh vtable. The vtable slots the functions call
are stubs (mov eax, imm32; ret N) with random results, so the exe and the port call the same stubs and get the same
answers. Pointer-returning stubs return either 0 or a random 0x100-byte buffer whose first dword is 0 or random, so
both branches of every test are reached. Stubs pop their own arguments (ret 4 / ret 8), as thiscall callees do.
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ptr_result(c):
    if c.rng.random() < 0.3:
        return 0
    b = _rnd(c, 0x100)
    if c.rng.random() < 0.5:
        c.emu.w32(b, 0)
    return b


def _obj(c, slots):
    """slots: {offset: (value_fn, nargs)}. Each slot is a logging stub: it records its arguments and the ecx it was
    called with (so a port that passes the wrong argument or calls the wrong slot shows up in the call log), pops its
    own arguments, and returns value_fn(c) in eax. Slots not listed stop the run ('unstubbed virtual call')."""
    o = _rnd(c, 0x2000)
    impl, argw = {}, {}
    for off, (vfn, nargs) in slots.items():
        v = vfn(c)
        impl[off] = (lambda v: (lambda e, a: (v, None)))(v)
        argw[off] = nargs
    vt = c.emu.logging_vtable('input', 64, impl=impl, argwords=argw)
    c.emu.w32(o, vt)
    return o


def _rnd32(c):
    return c.rng.getrandbits(32)


def _enable(c):
    return [_obj(c, {})]


def _disable(c):
    o = _obj(c, {0x58: (_ptr_result, 1)})
    return [o, c.rng.getrandbits(32)]


def _log(c):
    """The engine log at global 0x700390: slot +0x20 returns a stream object, whose cdecl slot +0x2c is a printf-style
    stub (logged, no stack cleanup by the callee)."""
    e = c.emu
    stream = _rnd(c, 16)

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    e.w32(stream, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (stream, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)


def _ignorelock(c):
    _log(c)
    o = _obj(c, {0x58: (_ptr_result, 1), 0x60: (_ptr_result, 1)})
    return [o, c.rng.getrandbits(32)]


def _remove_def(c):
    o = _obj(c, {0x5c: (_ptr_result, 1), 0x10: (_rnd32, 1)})
    return [o, c.rng.getrandbits(32)]


def _remove_name(c):
    o = _obj(c, {0x60: (_ptr_result, 1), 0x10: (_rnd32, 1)})
    return [o, c.rng.getrandbits(32)]


def _getvalue(c):
    o = _obj(c, {0x58: (_ptr_result, 1), 0xa0: (_rnd32, 1)})
    return [o, c.rng.getrandbits(32)]


def _forceset(c):
    o = _obj(c, {0x58: (_ptr_result, 1), 0x4c: (_rnd32, 2)})
    return [o, c.rng.getrandbits(32), c.rng.choice([0, 1, c.rng.getrandbits(32)])]


S(0x438780, 'ZInputActions::EnableActions (unknown) thiscall', 'thiscall', None, ret=None, gen=_enable,
  note='unclaimed-07 batch 1; inc dword at +0x120c')
S(0x438360, 'ZInputActions::DisableActions (unknown) thiscall', 'thiscall', None, ret=None, gen=_disable,
  note='unclaimed-07 batch 1; GUESS name; slot +0x58 pointer, byte +0x0c cleared when non-null')
S(0x43af70, 'ZInputActions::SetActionIgnoreLockOnSave (unknown) thiscall', 'thiscall', None, ret=None,
  gen=_ignorelock, note='unclaimed-07 batch 1; slot +0x58, byte +0x30 set when first dword is 0')
S(0x43a7c0, 'ZInputActions::RemoveActionMap def (unknown) thiscall', 'thiscall', None, ret=None,
  gen=_remove_def, note='unclaimed-07 batch 1; slot +0x5c then slot +0x10')
S(0x43a7e0, 'ZInputActions::RemoveActionMap name (unknown) thiscall', 'thiscall', None, ret=None,
  gen=_remove_name, note='unclaimed-07 batch 1; slot +0x60 then slot +0x10')
S(0x438f30, 'ZInputActions::GetActionValue (unknown) thiscall', 'thiscall', None, ret='eax',
  gen=_getvalue, note='unclaimed-07 batch 1; returns slot +0xa0 of slot +0x58 result')
S(0x438880, 'ZInputActions::ForceSetAction (unknown) thiscall', 'thiscall', None, ret=None,
  gen=_forceset, note='unclaimed-07 batch 1; slot +0x58 then slot +0x4c(ptr, bool)')
