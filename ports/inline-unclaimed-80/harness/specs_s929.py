"""specs_s929.py - unclaimed-80 claim 9 (docs/20-unclaimed-80.md): CFireController::AddActorOnFire (0x581870). The table count
(0..6) and seven 28-byte entries are random; a1 equals an existing entry's first dword 40% of the time (the early return). The
sub-object's slot +0x58 returns b (a logging fake); b's slot +0x384 (two stack pointers, logged as 'stk') writes a per-case
3-float vector through its second pointer. The exe helper 0x466f60 is a logging stub returning a per-case value; the global flag
at 0x70039c+0x1a9f is zero half the time."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fire(c):
    import pe_emu
    def nostk(v):
        return 'stk' if isinstance(v, int) and pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP else v

    vec = [c.rng.getrandbits(32) for _ in range(3)]
    o = _rnd(c, 0x200)
    # Found path only: the id is always already an entry, so the exe returns early with balanced pops (see the doc for why
    # the new-entry path cannot be compared: it leaves ebx/esi/edi shuffled).
    count = c.rng.randint(1, 6)
    c.emu.w32(o + 0x4c, count)
    entries = [c.rng.getrandbits(32) for _ in range(count)]
    for k, e in enumerate(entries):
        c.emu.w32(o + 0x50 + 0x1c * k, e)
    c.emu.w32(o + 0xa5c, c.rng.getrandbits(32))
    a1 = c.rng.choice(entries)
    b = _rnd(c, 0x40)

    def write_vec(e, args, vec=vec):
        for k, v in enumerate(vec):
            e.w32(args[1] + 4 * k, v)
        return (0, None)

    def log_stk(name, off, n, impl):
        def h(e, r, off=off, n=n, impl=impl):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))
            eax, st0 = impl(e, args)
            e.ret(eax=eax, argbytes=4 * n)
        return h

    b_vt = c.emu.fake_vtable('ZFireB', 0x390, {0x384: log_stk('ZFireB', 0x384, 2, write_vec)})
    c.emu.w32(b, b_vt)
    sub = _rnd(c, 0x40)
    sub_vt = c.emu.fake_vtable('ZFireSub', 0x60, {0x58: log_stk('ZFireSub', 0x58, 0, lambda e, a, bb=b: (bb, None))})
    c.emu.w32(sub, sub_vt)
    g = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, sub)
    c.emu.w32(g + 0x1a9f, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    c.emu.w32(0x70039c, g)
    ss.patch(c, 0x466f60, ss.rec(c, 1, ret=c.rng.getrandbits(32)))
    return [o, a1, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x581870, 'CFireController::AddActorOnFire (unknown) thiscall', 'thiscall', None, ret=None, gen=_fire,
  note='unclaimed-80 claim 9; slot +0x58 and +0x384 (stack pointers normalised), 0x466f60 stubbed; cookie check omitted')
