"""specs_s4722.py - area 73 batch 22 (gap band, GUESS names). FUN_4f3ff0 stores the render control's slot +0x4c result at this+0x60.
FUN_4e83b0 walks a chain built per case (1 to 3 nodes, the last one's +8 equal to this+8, so it terminates)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f3ff0(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    ctl = _rnd(c, 0x100)
    rv = c.rng.getrandbits(32)
    e.w32(ctl, e.logging_vtable('ctl4c', 0x50 // 4, impl={0x4c: lambda em, a: (rv, None)}, argwords={0x4c: 1}))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)
    return [self_o, c.rng.getrandbits(32)]


def _e83b0(c):
    self_o = _rnd(c, 0x100)
    target = c.rng.getrandbits(32)
    e = c.emu
    e.w32(self_o + 8, target)
    n = c.rng.randint(1, 3)
    nodes = [_rnd(c, 0x40) for _ in range(n)]
    # chain: nodes[0] -> nodes[1] -> ... -> nodes[-1] -> (+8 = target, which is a value, not a node)
    for i, nd in enumerate(nodes):
        nxt = nodes[i + 1] if i + 1 < n else target
        e.w32(nd + 8, nxt)
    # the last node's +8 must equal this+8 (the target), so walk ends there
    return [self_o, nodes[0]]


S(0x4f3ff0, 'GUESS FUN_4f3ff0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_f3ff0,
  note='area 73 batch 22; this+0x60 = render control slot +0x4c(arg)')
S(0x4e83b0, 'GUESS FUN_4e83b0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_e83b0,
  note='area 73 batch 22; chain walk until +8 equals this+8')
