"""specs_s1903.py - unclaimed-66 batch 1903 (residue 5): CEnemyFlag scalar deleting destructor, thiscall, one flag argument,
returns this (ret 4). The object is 0x100 random bytes. The engine db (ZSysInterface+0x9b) vtable +0x34 is a logging stub
(one argument, callee pops). Flags are random: the *0x7003b0 call (bit 0 set, bit 2 clear) is a recording stub here."""
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
    db = c.emu.fake_object('engine db', 0x40, vtable=c.emu.fake_vtable('engine db', 0x38 // 4 + 1, slots={
        0x34: _slot('engine db (stub)', 0x34, 1, lambda e, a: (0, None))}))
    sys = _rnd(c, 0x1a00)
    c.emu.w32(sys + 0x9b, db)
    c.emu.w32(0x70039c, sys)
    def hook(e, r):                 # the flag tail calls *0x7003b0 when bit 0 is set and bit 2 clear: a recording stub here
        e.calllog.append(('0x7003b0 hook (stub)', 0x7003b0, None, ()))
        e.ret(eax=0, argbytes=0)
    c.emu.w32(0x7003b0, c.emu.stub_fn('0x7003b0 hook (stub)', hook))
    return [obj, c.rng.getrandbits(32)]


S(0x5c0e90, 'CEnemyFlag::~CEnemyFlag (unknown)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-66 batch 1903 (residue 5); same template as 0x5817b0; flag bit0 clear (gap)')
