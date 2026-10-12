"""specs_s294.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x508070 and 0x519d70. Both read a table entry
through exe helper 0x5003d0 (runs as original code) and then use an object at this+0x18 or this+0x14."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _table_arg(c):
    e = c.emu
    data = _rnd(c, 0x1000)
    inner = _rnd(c, 0x200)
    e.w32(inner, data)
    e.w32(inner + 8, 0x100)
    table = _rnd(c, 0x40)
    e.w32(table, inner)
    e.w32(table + 4, c.rng.randrange(0, 0x80))
    e.w32(table + 8, 0x10)
    e.w32(data + 8 * e.r32(table + 4), c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    arg = _rnd(c, 0x40)
    e.w32(arg + 4, table)
    return arg


def _fwd(c):
    e = c.emu
    arg = _table_arg(c)
    r = c.rng.getrandbits(32)
    obj_vt = e.logging_vtable('obj508', 0x610 // 4 + 1, impl={}, argwords={0x610: 1})
    obj = _rnd(c, 0x40)
    e.w32(obj, obj_vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x18, obj)
    return [self_, arg]


def _flag(c):
    e = c.emu
    arg = _table_arg(c)
    obj = _rnd(c, 0x140)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x14, obj)
    return [self_, arg]


S(0x508070, 'forwardTable (GUESS)', 'thiscall', None, ret=None, gen=_fwd, note='batch294; ret 4; exe 0x5003d0')
S(0x519d70, 'flagTable (GUESS)', 'thiscall', None, ret=None, gen=_flag, note='batch294; ret 4; exe 0x5003d0')
