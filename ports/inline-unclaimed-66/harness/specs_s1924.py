"""specs_s1924.py - unclaimed-66 batch 1924: GUESS FUN_00656490 (thiscall, two arguments, ret 8, returns AL = 1) and GUESS FUN_0054cd10
(scalar deleting dtor, thiscall with a flag argument, ret 4, returns this).

Vtable +0xc (one argument, random dword) and +0x158 (two arguments, void) are logging stubs for 0x656490. For 0x54cd10 the flag is kept
with bit 0 clear, so the CRT free (0x634273) is not run: that path is a documented gap."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _free_hook(c):
    """The CRT free (cdecl free(ptr, size)) at 0x634273 is hooked by address: it records (ptr, size) and does nothing."""
    def h(e, r):
        e.calllog.append(('CRT free 0x634273 (hook)', 0x634273, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, h)


def _slot(name, off, nargs, impl):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        eax, st0 = impl(e, args)
        e.ret(eax=eax, argbytes=4 * nargs, st0=st0)
    return h


def _chain(c):
    vt = c.emu.fake_vtable('leaf656490 obj', 0x158 // 4 + 1, slots={
        0xc: _slot('leaf656490 obj +0xc (stub)', 0xc, 1, lambda e, a: (c.rng.getrandbits(32), None)),
        0x158: _slot('leaf656490 obj +0x158 (stub)', 0x158, 2, lambda e, a: (0, None))})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _dtor(c):
    _free_hook(c)
    obj = _rnd(c, 0x40)
    return [obj, c.rng.getrandbits(32)]


S(0x656490, 'GUESS FUN_00656490 (vtable +0xc then +0x158, returns true)', 'thiscall', None, ret='al', gen=_chain,
  note='unclaimed-66 batch 1924; slice-5 (GUESS); both vtable slots stubbed')
S(0x54cd10, 'GUESS FUN_0054cd10 (scalar deleting dtor, flag bit 0 clear)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-66 batch 1924; slice-5 (GUESS); CRT free path not run (gap)')
