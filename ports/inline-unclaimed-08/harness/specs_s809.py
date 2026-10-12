"""specs_s809.py - unclaimed-08 batch 809 (docs/20-unclaimed-08.md): CHitpointControl scalar deleting destructor (thiscall,
one stack flag argument, returns this, ret 4).

The object is 0x100 random bytes. ZSysInterface at *0x70039c has +0x9b pointing at a fake object whose vtable +0x34 is a
logging stub (one argument, callee pops). Flags are random with bit 0 clear, so the *0x7003b0 call is never made (gap)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot(name, off, nargs, impl):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        eax, st0 = impl(e, args)
        e.ret(eax=eax, argbytes=4 * nargs, st0=st0)
    return h


def _dtor(c):
    obj = _rnd(c, 0x100)
    vt = c.emu.fake_vtable('engine db', 0x38 // 4 + 1, slots={
        0x34: _slot('engine db (stub)', 0x34, 1, lambda e, a: (0, None))})
    db = c.emu.fake_object('engine db', 0x40, vtable=vt)
    sys = _rnd(c, 0x1a00)
    c.emu.w32(sys + 0x9b, db)
    c.emu.w32(0x70039c, sys)
    # The flag tail calls *0x7003b0 when bit 0 is set and bit 2 is clear: that global is a recording stub here.
    def hook(e, r):
        e.calllog.append(('0x7003b0 hook (stub)', 0x7003b0, None, ()))
        e.ret(eax=0, argbytes=0)
    c.emu.w32(0x7003b0, c.emu.stub_fn('0x7003b0 hook (stub)', hook))
    return [obj, c.rng.getrandbits(32)]


S(0x5817b0, 'CHitpointControl::~CHitpointControl (unknown)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-08 batch 9; stores +0x44, +0x30, vtable 0x686874, vcall +0x34(this) on the engine db; bit0 clear (gap)')


S(0x5b9430, 'CFriendlyControl::~CFriendlyControl (unknown)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-08 batch 9; same body as 0x5817b0 (identical PC bytes, checked by disassembly)')


S(0x4a61b0, 'ZRequireMatPosSpeed::~ZRequireMatPosSpeed (unknown)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-08 batch 9; same template as 0x5817b0')
S(0x469670, 'ZWeaponTest::~ZWeaponTest (unknown)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-08 batch 9; same template as 0x5817b0')
