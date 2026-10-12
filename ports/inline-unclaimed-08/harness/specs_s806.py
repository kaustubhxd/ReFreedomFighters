"""specs_s806.py - unclaimed-08 batch 806 (docs/20-unclaimed-08.md): two scalar deleting destructors of the hero movement
classes, thiscall with one stack argument (flags), return this (ret 4).

The object is 0x800 random bytes. The member destructors and the base destructor run the original code on it. Flags are
random with bit 0 clear, so the CRT free (delete this) is never taken: it faults on an emulator-heap object in both builds,
so that path is a documented gap, not verified."""
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


def _member(c, obj, off):
    """The member at obj+off: its +0x14 pointer (destroyed by 0x480fd0 through vtable slot 0 when non-null) is null
    (50%) or a fake object whose slot 0 logs its argument (virtual deleting destructor, stubbed)."""
    if c.rng.random() < 0.5:
        c.emu.w32(obj + off + 0x14, 0)
        return
    vt = c.emu.fake_vtable('member child', 4, slots={0: _slot('member child dtor (stub)', 0, 1,
                                                              lambda e, a: (0, None))})
    child = c.emu.fake_object('member child', 0x40, vtable=vt)
    c.emu.w32(obj + off + 0x14, child)


def _slot(name, off, nargs, impl):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        eax, st0 = impl(e, args)
        e.ret(eax=eax, argbytes=4 * nargs, st0=st0)
    return h


def _dtor(c):
    obj = _rnd(c, 0x800)
    for off in (0x523, 0x4ab, 0x3eb, 0x3d3, 0x55, 0x3d, 0x25):
        _member(c, obj, off)
    # Bit 0 (delete this) is random: the CRT free is hooked by address (records ptr and size), so the free path runs.
    _free_hook(c)
    return [obj, c.rng.getrandbits(32)]


S(0x5e12f0, 'ZFFHeroMovementBaseMove::~ZFFHeroMovementBaseMove (unknown)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-08 batch 6; 4 member dtors + base dtor original; free(this, 0x54c) on flag bit 0')
S(0x5e1570, 'ZFFHeroMovementOpenGate::~ZFFHeroMovementOpenGate (unknown)', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-08 batch 6; vtable 0x6b788c, then as above; free(this, 0x5bf) on flag bit 0')
