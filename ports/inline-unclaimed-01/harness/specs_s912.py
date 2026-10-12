"""specs_s912.py - unclaimed-01 claim 11 (docs/20-unclaimed-01.md): ZFFPRIVATESTDOBJ::Load (0x5aa140). Stack-address
arguments are logged as 'stk' by the fake vtables (the same normalisation as inline-ai/specs_s705.py), so the two
runs compare equal where only the stack address differs. The load object has +0x10 pointing at a record that
0x45f3c0 writes into; its slot +0x40 writes a per-case dword through a pointer argument (0 about a third of the time,
so 0x45f3c0's branch on that value goes both ways). The global's +0x9b object's slot +0x58 returns a per-case value."""
import pe_emu
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _nostk(v):
    return 'stk' if isinstance(v, int) and pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP else v


def _fake(c, name, nslots, handlers, unlogged=()):
    """handlers: {byte_off: (nargs, fn(emu, args) -> eax)}; logs the call with stack addresses normalised.
    unlogged: slots whose arguments are not logged (the call's arguments are whatever the exe's caller left on the
    stack; the call itself and its ecx are still logged)."""
    slots = {}
    for off, (n, fn) in handlers.items():
        def h(e, r, off=off, n=n, fn=fn):
            args = [e.arg32(k) for k in range(n)]
            logged = () if off in unlogged else tuple(_nostk(a) for a in args)
            e.calllog.append((name, off, e.reg('ecx'), logged))
            e.ret(eax=fn(e, args), argbytes=4 * n)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _load(c):
    v = 0 if c.rng.random() < 0.33 else c.rng.getrandbits(32)
    r58 = c.rng.getrandbits(32)

    def w40(e, args):
        e.w32(args[0], v)
        return 0

    def wself(e, args):
        # Writes nothing: this call's argument is the exe's stack leftover, which is not the same in both runs.
        return 0

    self_o = _rnd(c, 0x100)
    # The exe calls this slot with no argument pushed (0x45f3c0's last call), so the fake returns with no argument bytes.
    c.emu.w32(self_o, _fake(c, 'ZFFPRIVATESTDOBJ', 0x48, {0x40: (0, wself)}, unlogged=(0x40,)))
    c.emu.w32(self_o + 0x10, _rnd(c, 0x40))
    obj = _rnd(c, 0x40)
    rec = _rnd(c, 0x40)
    c.emu.w32(obj + 0x10, rec)
    c.emu.w32(obj, _fake(c, 'ZLoadGame', 0x48, {0x40: (1, w40)}))
    o = _rnd(c, 0x100)
    g = _rnd(c, 0x100)
    m = _rnd(c, 0x40)
    c.emu.w32(m, _fake(c, 'ZLoadSub', 0x60, {0x58: (1, lambda e, a: r58)}))
    c.emu.w32(g + 0x9b, m)
    c.emu.w32(0x70039c, g)
    return [self_o, obj]


S(0x5aa140, 'ZFFPRIVATESTDOBJ::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-01 claim 11; original 0x45f3c0 first; stack pointers logged as stk')
