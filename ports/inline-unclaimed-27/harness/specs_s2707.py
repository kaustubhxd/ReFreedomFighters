"""specs_s2707.py - unclaimed-27 claim 7 (docs/20-unclaimed-27.md): ZBaseGeom::DetachFromDynamicContainer (0x4da720, thiscall,
ret 4). Stubs, NOT verified: 0x4daff0 (the lookup) is replaced for each case by a hook returning either 0 or a fresh object P
(the port calls the same hooked address; the hook records its key in ecx); P's vtable slot +0x320 (one argument) records its argument and a counter.
The object's +0x50 is always a node N whose +0x54 is M (valid), so the argument-0 path never reads address 8. The argument, if
nonzero, is a fresh object whose +8 is random. The dword at +0x64 is zero in about half the cases, and the byte at +0x3c is zero in about a third."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _bgdc(c):
    cnt = c.emu.alloc(0x10, 4)
    rec = c.emu.alloc(0x10, 4)
    # P's vtable slot +0x320 (thiscall, one argument, ret 4): record the argument at rec, count calls at cnt
    pvt = c.emu.alloc(0x400, 4)
    c.emu.w32(pvt + 0x320, _stub(c, b'\xff\x05' + cnt.to_bytes(4, 'little')
                                 + b'\x8b\x44\x24\x04' + b'\xa3' + rec.to_bytes(4, 'little') + b'\xc2\x04\x00'))
    p = _rnd(c, 0x400)
    c.emu.w32(p, pvt)
    ret = p if c.rng.random() < 0.6 else 0
    lrec = c.emu.alloc(0x10, 4)   # the hook records the key it is given (ecx) so a wrong key is visible
    c.emu.hook(0x4daff0, lambda e, r, ret=ret, lrec=lrec: (e.w32(lrec, e.reg('ecx')), e.ret(eax=ret, argbytes=0)))
    # the object
    o = _rnd(c, 0x800)
    n = _rnd(c, 0x100)
    m = _rnd(c, 0x100)
    c.emu.w32(n + 0x54, m)
    c.emu.w32(o + 0x50, n)
    c.emu.w32(o + 0x64, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    c.emu.wbytes(o + 0x3c, bytes([c.rng.choice([0, 1, 0xff])]))
    if c.rng.random() < 0.5:
        grp = 0
    else:
        grp = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, grp]


S(0x4da720, 'ZBaseGeom::DetachFromDynamicContainer (unknown) thiscall', 'thiscall', None, ret=None, gen=_bgdc,
  note='unclaimed-27 claim 7; 0x4daff0 is hooked (stub); P slot +0x320 is a stub')
