"""specs_s37.py - inline session batch 37 (Haiku, night): shoot-tree leaves 0x4db840 (getter with a sub-object dword)
and 0x4da360 (recursive flag setter over a sibling list at +0x50)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _get(c):
    r = c.rng
    obj = _rnd(c, 0x80)
    if r.random() < 0.3:
        c.emu.w32(obj + 0x54, 0)
    else:
        sub = _rnd(c, 0x40)
        leaf = _rnd(c, 0x40)
        c.emu.w32(sub + 0xc, leaf)
        c.emu.w32(obj + 0x54, sub)
    return [obj]


def _set(c):
    r = c.rng
    obj = _rnd(c, 0x80)
    prev = None
    nodes = []
    for _ in range(r.randint(0, 3)):
        n_ = _rnd(c, 0x80)
        nodes.append(n_)
    head = nodes[0] if nodes else 0
    c.emu.w32(obj + 0x50, head)
    for i, n_ in enumerate(nodes):
        nxt = nodes[i + 1] if i + 1 < len(nodes) else 0
        c.emu.w32(n_ + 0x50, nxt)
    a0 = r.getrandbits(32) if r.random() < 0.7 else (r.getrandbits(32) & 0xffffff00)
    a1 = 0 if r.random() < 0.6 else r.getrandbits(32)
    return [obj, a0, a1]


S(0x4db840, 'ZBaseGeom::GetWordFromChild', 'thiscall', None, ret='eax', gen=_get,
  note='batch37; dword at +0x23 of the sub-object at (this+0x54)+0xc; constant 0x200002 when this+0x54 is null')
S(0x4da360, 'ZBaseGeom::SetFlagTree', 'thiscall', None, ret=None, gen=_set,
  note='batch37; recursive over the sibling list at +0x50; byte at +0x3c replaced, other bytes kept')
