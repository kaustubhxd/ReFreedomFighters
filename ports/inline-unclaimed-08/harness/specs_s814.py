"""specs_s814.py - unclaimed-08 batch 814 (docs/20-unclaimed-08.md): CBoxAutoFire::Init(ZGEOM*, DBREAD&), thiscall, two
stack arguments (ret 8), void.

Stubs (UNVERIFIED, stated in the doc): the DBREAD readers 0x4e5e80 (float) and 0x4e5e60 (dword) are hooked to return
random values (logged); the function at global 0x7003b0 is a logging stub; the engine db's vtable +0x114 (four arguments,
callee pops 0x10) is a logging stub returning a random dword. The game tick at sys+0x40 is random."""
import struct
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


def _hook(c, addr, name, impl):
    """Hook the exe function at addr: thiscall, no stack arguments; impl(e) -> (eax, st0)."""
    def h(e, r):
        e.calllog.append((name, addr, e.reg('ecx'), ()))
        eax, st0 = impl(e)
        e.ret(eax=eax, argbytes=0, st0=st0)
    c.emu.hook(addr, h)


def _init(c):
    self = _rnd(c, 0x100)
    geom = _rnd(c, 0x40)
    dbread = _rnd(c, 0x40)
    fv = c.rng.uniform(-100.0, 100.0)
    _hook(c, 0x4e5e80, 'DBREAD float (stub)', lambda e: (0, struct.unpack('<f', struct.pack('<f', fv))[0]))
    _hook(c, 0x4e5e60, 'DBREAD dword (stub)', lambda e: (c.rng.getrandbits(32), None))
    ok = c.emu.stub_fn('box auto fire hook (stub)', lambda e, r: (e.calllog.append(('hook 0x7003b0', 0, None, ())), e.ret(eax=0))[1])
    c.emu.w32(0x7003b0, ok)
    db = c.emu.fake_object('engine db', 0x40, vtable=c.emu.fake_vtable('engine db', 0x114 // 4 + 1, slots={
        0x114: _slot('engine db word (stub)', 0x114, 4, lambda e, a: (c.rng.getrandbits(16), None))}))
    sys = _rnd(c, 0x1a00)
    c.emu.w32(sys + 0x40, c.rng.getrandbits(32))
    c.emu.w32(sys + 0x9b, db)
    c.emu.w32(0x70039c, sys)
    return [self, geom, dbread]


S(0x5d4af0, 'CBoxAutoFire::Init (unknown)', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-08 batch 14; DBREAD readers 0x4e5e80/0x4e5e60, hook 0x7003b0 and engine db +0x114 are STUBS')
