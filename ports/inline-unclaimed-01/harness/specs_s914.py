"""specs_s914.py - unclaimed-01 claim 13 (docs/20-unclaimed-01.md): CCivilianPathList::Init2 (0x5be780). Fake vtables
log stack-address arguments as 'stk' (as in specs_s912.py). The sub-object at the global's +0x9b returns three fake
objects: X (slot +0x90 writes a per-case flag byte through its pointer; true about a third of the time, which skips the
rest), Y (slot +0x88 writes a per-case dword through its pointer), and the sub-object's slots +0x134, +0x138 and +0x58."""
import pe_emu
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _nostk(v):
    return 'stk' if isinstance(v, int) and pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP else v


def _fake(c, name, nslots, handlers):
    slots = {}
    for off, (n, fn) in handlers.items():
        def h(e, r, off=off, n=n, fn=fn):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(_nostk(a) for a in args)))
            e.ret(eax=fn(e, args), argbytes=4 * n)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _init2(c):
    flag = 1 if c.rng.random() < 0.33 else 0
    dword = c.rng.getrandbits(32)
    r58 = c.rng.getrandbits(32)

    def w90(e, args):
        e.w8(args[1], flag)
        return 0

    def w88(e, args):
        e.w32(args[1], dword)
        return 0

    X = _rnd(c, 0x40)
    c.emu.w32(X, _fake(c, 'ZCivX', 0x94, {0x90: (2, w90)}))
    Y = _rnd(c, 0x40)
    c.emu.w32(Y, _fake(c, 'ZCivY', 0x8c, {0x88: (2, w88)}))
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, _fake(c, 'ZCivSub', 0x60, {
        0x134: (0, lambda e, a: X),
        0x138: (0, lambda e, a: Y),
        0x58: (1, lambda e, a: r58),
    }))
    g = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, sub)
    c.emu.w32(0x70039c, g)
    return [_rnd(c, 0x1000)]


S(0x5be780, 'CCivilianPathList::Init2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_init2,
  note='unclaimed-01 claim 13; flag from slot +0x90 gates slots +0x138, +0x88, +0x58; result at +0x91a')
