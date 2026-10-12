"""specs_s1918.py - unclaimed-66 batch 1918: the base constructor 0x561020 (thiscall, no arguments).

The engine (ZSysInterface at *0x70039c): tick at +0x40, and the database at +0x9b with a float at +0xae0 (used by 0x469870, the
exe code this calls). The database's vtable +0x114 (four arguments, callee pops 0x10) is a logging stub returning a random word; +0x30 (one argument,
0x469870 calls it with the object) is a logging stub too.
The object is 0x1100 random bytes (the constructor writes up to +0xfc and reads nothing else)."""
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


def setup_engine(c):
    db_vt = c.emu.fake_vtable('engine db', 0x114 // 4 + 1, slots={
        0x114: _slot('engine db name to id (stub)', 0x114, 4, lambda e, a: (c.rng.getrandbits(16), None)),
        0x30: _slot('engine db +0x30 (stub, from 0x469870)', 0x30, 1, lambda e, a: (0, None))})
    db = _rnd(c, 0xb00)
    c.emu.w32(db, db_vt)
    c.emu.wf32(db + 0xae0, c.rng.uniform(0.5, 4.0))
    sys = _rnd(c, 0x1a00)
    c.emu.w32(sys + 0x40, c.rng.randint(0, 1 << 22))
    c.emu.w32(sys + 0x9b, db)
    c.emu.w32(0x70039c, sys)


def _ctor(c):
    c.emu.unhook(0x561020)           # a stub from an earlier spec must not stand in for the constructor
    setup_engine(c)
    return [_rnd(c, 0x1100)]


S(0x561020, 'base ctor 0x561020 (unknown class)', 'thiscall', None, ret=None, gen=_ctor,
  note='unclaimed-66 batch 1918; base constructor; calls 0x469870 (exe) and db +0x114 twice (stubbed)')
