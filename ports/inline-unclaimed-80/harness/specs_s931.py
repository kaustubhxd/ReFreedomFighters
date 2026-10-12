"""specs_s931.py - unclaimed-80 claim 11 (docs/20-unclaimed-80.md): CActionController::Remove (0x4a1630). The helper 0x4a1710 is a
logging thiscall stub (one argument, ret 4). The table object at 0x70038c is a logging fake: slot +0x20 (one argument) returns zero
half the time, slot +0xac (one argument) logs; +8 is a rec stub returning a per-case value (zero 10%); the bounds +0xc/+0x10 are
around the argument (in range 50%). The argument points 4 bytes into a buffer (so [a-4] is valid) or is null 20% of the time. The
count at +0x88c is 0..5 (its entries are random, one equal to the argument 40%); this+0x48 is 0..2 entries whose objects have a
count at +0x820 of 0..3."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fake(c, name, nslots, handlers):
    slots = {}
    for off, (n, fn) in handlers.items():
        def h(e, r, off=off, n=n, fn=fn):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
            eax, st0 = fn(e, args)
            e.ret(eax=eax, argbytes=4 * n)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _remove(c):
    ss.patch(c, 0x4a1710, ss.rec(c, 1, ret=0))
    buf = _rnd(c, 0x40)
    a = 0 if c.rng.random() < 0.2 else buf + 4
    V = c.rng.getrandbits(32)            # the resolved value when a is not in range (a = [a-4])
    R = c.rng.getrandbits(32)            # the resolved value from fn (in range)
    if a:
        c.emu.w32(buf, V if c.rng.random() < 0.7 else 0)
    v20 = 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    t = _rnd(c, 0x40)
    t_vt = _fake(c, 'ZActionTable', 0x50, {0x20: (1, lambda e, args, v=v20: (v, None)),
                                          0xac: (1, lambda e, args: (0, None))})
    c.emu.w32(t, t_vt)
    fn = ss.rec(c, 0, ret=R) if c.rng.random() < 0.9 else 0
    c.emu.w32(t + 8, fn)
    if a:
        if c.rng.random() < 0.5:
            c.emu.w32(t + 0xc, a if c.rng.random() < 0.5 else a - 4)   # lo == a sometimes (inclusive bound)
            c.emu.w32(t + 0x10, a + 4)
        else:
            c.emu.w32(t + 0xc, a + 4)
            c.emu.w32(t + 0x10, a + 8)
    else:
        c.emu.w32(t + 0xc, 0)
        c.emu.w32(t + 0x10, 0)
    g = _rnd(c, 0x100)
    c.emu.w32(g, 0)
    c.emu.w32(0x70038c, t)
    self_o = _rnd(c, 0x1000)
    cnt1 = c.rng.randint(0, 5)
    c.emu.w32(self_o + 0x88c, cnt1)
    for k in range(cnt1 + 1):
        pick = c.rng.random()
        val = V if pick < 0.3 else (R if pick < 0.6 else c.rng.getrandbits(32))
        c.emu.w32(self_o + 0x70 + 4 * k, val)
    n2 = c.rng.randint(0, 2)
    c.emu.w32(self_o + 0x48, n2)
    for i in range(n2):
        p = _rnd(c, 0x900)
        c.emu.w32(p + 0x820, c.rng.randint(0, 3))
        for k in range(4):
            pick = c.rng.random()
            val = V if pick < 0.2 else (R if pick < 0.35 else c.rng.getrandbits(32))
            c.emu.w32(p + 4 + 4 * k, val)
        c.emu.w32(self_o + 0x5c + 4 * i, p)
    return [self_o, a]


S(0x4a1630, 'CActionController::Remove (unknown) thiscall', 'thiscall', None, ret=None, gen=_remove,
  note='unclaimed-80 claim 11; helper 0x4a1710 stubbed (logged); table object 0x70038c fake (slots 0x20, 0xac, +8 fn)')
