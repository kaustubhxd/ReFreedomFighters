"""specs_s1902.py - unclaimed-66 batch 1902: GUESS FUN_6461d0 (table lookup by name), thiscall, one argument, ret 4.

The engine db at ZSysInterface+0x9b has a vtable +0x50 STUB: it logs its argument and returns the id chosen for the case
(a small number). The table at this+0x69 (count 0..4) has 0x38-byte entries; each entry's first dword is the id with 40%
probability (so both the match and the no-match paths run). The name is a heap string (same address in both builds)."""
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


def _lookup(c):
    self = _rnd(c, 0x200)
    name = c.emu.alloc(0x10)
    c.emu.wbytes(name, b'fn\0')
    ident = c.rng.randint(1, 6)
    cnt = c.rng.randint(0, 4)
    c.emu.w32(self + 0x69, cnt)
    for i in range(cnt):
        base = self + 0x6d + 0x38 * i
        c.emu.w32(base, ident if c.rng.random() < 0.4 else c.rng.randint(0, 6))
        c.emu.w32(base + 4, c.rng.getrandbits(32))
    # The entry just past the count holds the id half the time: the scan must stop at the count, not one entry later.
    base = self + 0x6d + 0x38 * cnt
    c.emu.w32(base, ident if c.rng.random() < 0.5 else 0x7fff0000)
    c.emu.w32(base + 4, 0x5a5a5a5a)
    vt = c.emu.fake_vtable('engine db', 0x50 // 4 + 1, slots={
        0x50: _slot('engine db name to id (stub)', 0x50, 1, lambda e, a: (ident, None))})
    db = c.emu.fake_object('engine db', 0x40, vtable=vt)
    sys = _rnd(c, 0x1a00)
    c.emu.w32(sys + 0x9b, db)
    c.emu.w32(0x70039c, sys)
    return [self, name]


S(0x6461d0, 'GUESS FUN_6461d0 (table lookup)', 'thiscall', None, ret='eax', gen=_lookup,
  note='unclaimed-66 batch 1902; GUESS name; engine db +0x50 stubbed')
