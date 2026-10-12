"""specs_s907.py - unclaimed-01 claim 6 (docs/20-unclaimed-01.md): CMoveAlongPath::FrameUpdate (0x523280).
The frame-time object at the global 0x70039c has a float at +0x48 (random edge values, NaN included). The object
has a pointer at +0x4b nonzero about 60% of the time. Its vtable is a logging fake (slot +0x20 logs its call, the
float argument and ecx), so the virtual call is compared. The callees 0x524180, 0x5230e0 and 0x524270 run as original code."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _frame(c):
    g = _rnd(c, 0x100)
    c.emu.wf32(g + 0x48, c.fv(0.0, 0.1))
    c.emu.w32(0x70039c, g)
    o = _rnd(c, 0x100)
    vt = c.emu.logging_vtable('CMoveAlongPath', 0x24, argwords={0x20: 1})
    c.emu.w32(o, vt)
    # The exe callees 0x524180 and 0x5230e0 read the pointer at +0x4f and the flag at +0x41; zero keeps them on the
    # paths that touch no further pointers (random values there fault in original code).
    c.emu.w32(o + 0x4f, 0)
    c.emu.w8(o + 0x41, 0)
    if c.rng.random() < 0.6:
        c.emu.w32(o + 0x4b, c.rng.getrandbits(32) | 1)
    else:
        c.emu.w32(o + 0x4b, 0)
    # Tail target 0x524270 is a state machine on the dword at +0x35 (cases 0..4); valid state 70% of the time, so the
    # tail call's effect is visible.
    # States 0, 2 and 3 of 0x524270 fault in original code (unmapped reads); 1, 4 and the out-of-table values do not.
    c.emu.w32(o + 0x35, c.rng.choice([1, 4, 5, 0x40, 0xffffffff]) if c.rng.random() < 0.7 else c.rng.getrandbits(32))
    # +0x63 is zero about a third of the time (the tail jump is skipped), else a nonzero value or NaN.
    r = c.rng.random()
    if r < 0.33:
        c.emu.wf32(o + 0x63, c.rng.choice([0.0, -0.0]))
    elif r < 0.4:
        c.emu.wf32(o + 0x63, float('nan'))
    # Equal end point about a fifth of the time: frame time 0, positive speed, and +0x24 equal to the limit +0x2c,
    # so the new position equals the limit exactly (the > versus >= boundary).
    if c.rng.random() < 0.2:
        lim = c.rng.uniform(-5.0, 5.0)
        c.emu.wf32(g + 0x48, 0.0)
        c.emu.wf32(o + 0x28, c.rng.uniform(0.5, 5.0))
        c.emu.wf32(o + 0x2c, lim)
        c.emu.wf32(o + 0x24, lim)
    return [o]


S(0x523280, 'CMoveAlongPath::FrameUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_frame,
  note='unclaimed-01 claim 6; original callees 0x524180, 0x5230e0, 0x524270; virtual slot +0x20 with a float')
