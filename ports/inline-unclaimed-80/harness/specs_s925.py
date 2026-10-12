"""specs_s925.py - unclaimed-80 claim 5 (docs/20-unclaimed-80.md): GUESS FUN_5c39f0 (0x5c39f0). Every branch is reached:
the null argument (25%); the in-range fn call (table fn
at +8 is a rec stub returning a per-case value; zero 10%); the out-of-range path (its [esi-4] dword zero about half the
time, which calls the table's slot +0xac). Objects are logging fakes (slot +0x138 on the sub-object, +0x60 on the edi object,
+0x20 and +0xac on the table object). The argument points 8 bytes into a random buffer so esi-4 is valid."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fn(c):
    edi = _rnd(c, 0x40)
    c.emu.w32(edi, c.emu.logging_vtable('ZEdi', 0x30, argwords={0x60: 3}))
    # Slot +0x20 is always zero here: a nonzero result takes the exe's flag path, where the exe pushes esi at 5c3a27 and
    # then the shared tail at 5c3a0d pops one dword too few, so the original returns to a garbage address (see the doc).
    v20 = 0
    t = _rnd(c, 0x40)
    fn = ss.rec(c, 0, ret=c.rng.getrandbits(32)) if c.rng.random() < 0.9 else 0
    c.emu.w32(t + 8, fn)
    c.emu.w32(t, c.emu.logging_vtable('ZTable', 0x30, impl={0x20: (lambda e, a, v=v20: (v, None))},
                                     argwords={0x20: 0, 0xac: 1}))
    buf = _rnd(c, 0x40)
    # Only the null argument is exercised: every non-null path returns to a garbage address in the original (its push at
    # 5c3a27 is never popped before the shared tail), so the comparison cannot check those paths (see the doc).
    esi = 0
    if esi != 0:
        c.emu.w32(buf + 4, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
        r = c.rng.random()
        if r < 0.5:
            lo, hi = esi - 4, esi + 4          # in range
        elif r < 0.75:
            lo, hi = esi + 4, esi + 8          # lo > esi: out
        else:
            lo, hi = esi - 8, esi - 4          # esi >= hi: out
        c.emu.w32(t + 0xc, lo)
        c.emu.w32(t + 0x10, hi)
    else:
        c.emu.w32(t + 0xc, 0)
        c.emu.w32(t + 0x10, 0)
    c.emu.w32(0x70038c, t)
    obj = edi
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, c.emu.logging_vtable('ZSysSub3', 0x50, impl={0x138: (lambda e, a, o=obj: (o, None))},
                                       argwords={0x138: 0}))
    g = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, sub)
    c.emu.w32(0x70039c, g)
    return [esi]


S(0x5c39f0, 'GUESS FUN_5c39f0 thiscall', 'thiscall', None, ret=None, gen=_fn,
  note='unclaimed-80 claim 5; GUESS name; full branch set (null, flag, in-range fn, out-of-range slot +0xac)')
