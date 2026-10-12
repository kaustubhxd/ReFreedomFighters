"""specs_s812.py - unclaimed-08 batch 812 (docs/20-unclaimed-08.md): ZFFSearchLightGroup::LoadSpot(tagSPOTINFO&, ZLoadGame*),
stdcall (ret 8). The spot record is 0x30 random bytes. The load game's vtable slots +0x40, +0x50, +0x68, +0x70 are
logging stubs (one argument each, callee pops). The engine database's +0x58 is a logging stub returning a random dword.
The argument slot of the load game (&lg) is the caller's stack: its address matches in both builds, because the harness
sets the arguments at the same stack place."""
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


def _load(c):
    spot = _rnd(c, 0x30)
    lg_vt = c.emu.fake_vtable('ZLoadGame', 0x70 // 4 + 1, slots={
        off: _slot('ZLoadGame read (stub)', off, 1, lambda e, a: (0, None)) for off in (0x40, 0x50, 0x68, 0x70)})
    lg = c.emu.fake_object('ZLoadGame', 0x40, vtable=lg_vt)
    db_vt = c.emu.fake_vtable('engine db', 0x58 // 4 + 1, slots={
        0x58: _slot('engine db ref (stub)', 0x58, 1, lambda e, a: (c.rng.getrandbits(32), None))})
    db = c.emu.fake_object('engine db', 0x40, vtable=db_vt)
    sys = _rnd(c, 0x1a00)
    c.emu.w32(sys + 0x9b, db)
    c.emu.w32(0x70039c, sys)
    return [spot, lg]


S(0x5c73f0, 'ZFFSearchLightGroup::LoadSpot (unknown)', 'stdcall', None, ret=None, gen=_load,
  note='unclaimed-08 batch 12; loader vtable calls and engine db +0x58 stubbed; stdcall ret 8')
