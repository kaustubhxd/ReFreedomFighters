"""specs_s4318.py - area 73 batch 18 (gap band, GUESS names). Objects have logging vtables; the helpers 0x44edd0, 0x4ef660 (one
argument) and 0x4e1b30 (none) are hooked and logged with ECX. FUN_4ffbd0 is stdcall: its fourth argument is the object."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _hooks(c):
    e = c.emu

    def mk(name, nargs):
        def h(em, r):
            args = tuple(em.arg32(k) for k in range(nargs))
            em.calllog.append((name, 0, em.reg('ecx'), args))
            em.ret(argbytes=4 * nargs)
        return h

    e.hook(0x44edd0, mk('44edd0', 1))
    e.hook(0x4ef660, mk('4ef660', 1))
    e.hook(0x4e1b30, mk('4e1b30', 0))


def _fa100(c):
    e = c.emu
    _hooks(c)
    self_o = _rnd(c, 0x100)
    o = _rnd(c, 0x40)
    e.w32(o, e.logging_vtable('g4fa100o', 0x2f0 // 4, impl={0x2ec: _const(0)}, argwords={0x2ec: 1}))
    e.w32(self_o, e.logging_vtable('g4fa100s', 0x2c8 // 4, impl={0x2c4: _const(o)}, argwords={0x2c4: 0}))
    return [self_o]


def _ffbd0(c):
    e = c.emu
    obj = _rnd(c, 0x40)
    e.w32(obj, e.logging_vtable('g4ffbd0', 0x20 // 4, impl={0x18: _const(0)}, argwords={0x18: 3}))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), obj]


def _f52e0(c):
    _hooks(c)
    self_o = _rnd(c, 0x100)
    arg = _rnd(c, 0x100)
    return [self_o, arg]


S(0x4fa100, 'GUESS FUN_4fa100 (unknown) thiscall', 'thiscall', None, ret=None, gen=_fa100,
  note='area 73 batch 18; slot +0x2c4 gives o; o slot +0x2ec(this)')
S(0x4ffbd0, 'GUESS FUN_4ffbd0 (unknown) stdcall', 'stdcall', None, ret=None, gen=_ffbd0,
  note='area 73 batch 18; stdcall, slot +0x18 on arg4 with (arg3, arg1, arg2)')
S(0x4f52e0, 'GUESS FUN_4f52e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_f52e0,
  note='area 73 batch 18; 0x44edd0(arg) then 0x4e1b30(arg)')
S(0x4face0, 'GUESS FUN_4face0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_f52e0,
  note='area 73 batch 18; 0x4ef660(arg) then 0x4e1b30(arg)')
