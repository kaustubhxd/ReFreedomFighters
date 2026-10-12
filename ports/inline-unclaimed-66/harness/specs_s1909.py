"""specs_s1909.py - unclaimed-66 batch 1909: three slice-5 leaves (GUESS names). Thiscall.

0x5e0dd0 takes one float argument (ret 4). 0x5ab950 calls the engine db's vtable +0x58 (a logging stub with one argument,
callee pops 4) and returns its EAX; the db is a fake object pointed to by ZSysInterface+0x9b."""
import struct
from pilot import S, F


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


def _obj(c):
    return [_rnd(c, 0x2000)]


def _float_arg(c):
    v = c.rng.choice([0.0, -0.0, float('nan'), -3.5, 2.25, float('inf')]) if c.rng.random() < 0.3 else c.rng.uniform(-10, 10)
    return [_rnd(c, 0x2000), F(v)]


def _sys_db(c):
    vt = c.emu.fake_vtable('engine db', 0x58 // 4 + 1, slots={
        0x58: _slot('engine db +0x58 (stub)', 0x58, 1, lambda e, a: (c.rng.getrandbits(32), None))})
    db = c.emu.fake_object('engine db', 0x40, vtable=vt)
    sys = _rnd(c, 0x1a00)
    c.emu.w32(sys + 0x9b, db)
    c.emu.w32(0x70039c, sys)
    self = _rnd(c, 0x100)
    c.emu.w32(self + 4, c.rng.getrandbits(32))
    return [self]


S(0x555550, 'GUESS FUN_00555550 (three zero stores)', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-66 batch 1909; slice-5 leaf (GUESS)')
S(0x5e0dd0, 'GUESS FUN_005e0dd0 (max with zero to +0x1d17)', 'thiscall', None, ret=None, gen=_float_arg,
  note='unclaimed-66 batch 1909; slice-5 leaf (GUESS); MAXSS order')
S(0x5ab950, 'GUESS FUN_005ab950 (engine db +0x58 forward)', 'thiscall', None, ret='eax', gen=_sys_db,
  note='unclaimed-66 batch 1909; slice-5 leaf (GUESS); engine db slot stubbed')
