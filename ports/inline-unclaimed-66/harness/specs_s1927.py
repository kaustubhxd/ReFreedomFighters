"""specs_s1927.py - unclaimed-66 batch 27 (gap band, GUESS names). Thiscall.

The CRT free 0x634273 is hooked by address (records ptr and size); the flag's bit 0 is random so the free runs. The base 0x500a10
of 0x5048a0 is a recording GUESS stub (hooked by address). The vtable +0x2e8 of the lazy getter is a logging stub (one argument,
returns a random dword). Objects are 0x40 random bytes."""
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


def _free_hook(c):
    def h(e, r):
        e.calllog.append(('CRT free 0x634273 (hook)', 0x634273, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, h)


def _dtor(c):
    _free_hook(c)
    def hb(e, r):
        e.calllog.append(('base 0x500a10 (GUESS stub)', 0x500a10, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x500a10, hb)
    return [_rnd(c, 0x40), c.rng.getrandbits(32)]


def _lazy(c):
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x1d1, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    vt = c.emu.fake_vtable('lazy obj', 0x2e8 // 4 + 1, slots={
        0x2e8: _slot('lazy obj +0x2e8 (stub)', 0x2e8, 1, lambda e, a: (c.rng.getrandbits(32), None))})
    c.emu.w32(obj, vt)
    return [obj]


S(0x509780, 'GUESS FUN_00509780 (scalar deleting dtor, vtable 0x69c968)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-66 batch 1927; gap band; CRT free hooked; flag bit 0 random')
S(0x5048a0, 'GUESS FUN_005048a0 (dtor over base 0x500a10)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-66 batch 1927; gap band; base 0x500a10 GUESS stub; CRT free hooked')
S(0x5144a0, 'GUESS FUN_005144a0 (lazy getter)', 'thiscall', None, ret='eax', gen=_lazy,
  note='unclaimed-66 batch 1927; gap band; vtable +0x2e8 stubbed')
