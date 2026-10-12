"""specs_s1936.py - unclaimed-66 batch 36 (gap band, GUESS names). Thiscall(X), ret 4, returns EAX.

0x5003d0 (another area's helper) is hooked: it returns a fixed object P whose first dword is 0, 1 or random (the bool source). The
sub-objects at this+0x14, +0x18 and +0x1c have vtables whose slots (+0xbc, +0x61c, +0x36c; one argument) are logging stubs that return a
random dword. X+4 holds a holder."""
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


def _gap(c):
    P = _rnd(c, 0x40)
    c.emu.w32(P, c.rng.choice([0, 1, c.rng.getrandbits(32)]))

    def h5003(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=P, argbytes=4)

    c.emu.hook(0x5003d0, h5003)

    def sub(off, name):
        return c.emu.fake_object(name, 0x40, vtable=c.emu.fake_vtable(name, (off + 4) // 4 + 1, slots={
            off: _slot(name + ' +%x (stub)' % off, off, 1, lambda e, a: (c.rng.getrandbits(32), None))}))

    self = _rnd(c, 0x200)
    c.emu.w32(self + 0x14, sub(0xbc, 'subbc'))
    c.emu.w32(self + 0x18, sub(0x61c, 'sub61c'))
    c.emu.w32(self + 0x1c, sub(0x36c, 'sub36c'))
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, _rnd(c, 0x20))
    return [self, x]


S(0x5083a0, 'GUESS FUN_005083a0 (bool to vtable +0x61c)', 'thiscall', None, ret='eax', gen=_gap,
  note='unclaimed-66 batch 1936; gap band; 0x5003d0 another area: HOOKED')
S(0x519730, 'GUESS FUN_00519730 (bool to vtable +0xbc)', 'thiscall', None, ret='eax', gen=_gap,
  note='unclaimed-66 batch 1936; gap band; 0x5003d0 another area: HOOKED')
S(0x51b0b0, 'GUESS FUN_0051b0b0 (bool to vtable +0x36c)', 'thiscall', None, ret='eax', gen=_gap,
  note='unclaimed-66 batch 1936; gap band; 0x5003d0 another area: HOOKED')
