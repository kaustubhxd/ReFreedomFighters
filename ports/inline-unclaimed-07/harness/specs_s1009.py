"""specs_s1009.py - unclaimed-07 batch 9 (slice 6): ZItem::GetMainItemRootTM (0x46e8e0).
Three fake objects: the item (this), its root chain (R1, then R2) and the flag object at this+8. Every slot is a
logging stub, so the call order, the arguments and ECX are all compared. The flag bit 0x200000 is random per case."""
from pilot import S

NSLOTS = 0x300 // 4


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _item(c):
    e = c.emu
    flag_set = c.rng.random() < 0.6
    flag = c.rng.getrandbits(32)
    flag = (flag | 0x200000) if flag_set else (flag & ~0x200000 & 0xffffffff)
    o1 = _rnd(c, 0x100)
    e.w32(o1 + 0x3c, flag)

    chk = c.rng.choice([0, 1, 0xff00, c.rng.getrandbits(32)])
    r2 = _rnd(c, 0x100)
    e.w32(r2, e.logging_vtable('root2', NSLOTS, impl={0x2a4: _const(0), 0x98: _const(0)},
                               argwords={0x2a4: 3, 0x98: 2}))
    r2_ret = r2
    r1 = _rnd(c, 0x100)
    e.w32(r1, e.logging_vtable('root1', NSLOTS,
                               impl={0x1e0: _const(chk), 0x2f4: _const(r2_ret), 0x2a4: _const(0), 0x98: _const(0)},
                               argwords={0x1e0: 1, 0x2f4: 0, 0x2a4: 3, 0x98: 2}))
    e.w32(r1 + 8, _rnd(c, 0x40))   # a different object: the chk path reads its pointer, not this's
    e.w32(r2 + 8, _rnd(c, 0x40))
    root_ret = r1 if c.rng.random() < 0.8 else 0
    item = _rnd(c, 0x100)
    e.w32(item, e.logging_vtable('item', NSLOTS,
                                 impl={0x2f4: _const(root_ret), 0x2e0: _const(0), 0x98: _const(0)},
                                 argwords={0x2f4: 0, 0x2e0: 2, 0x98: 2}))
    e.w32(item + 8, o1)
    a1 = _rnd(c, 0x40)
    a2 = _rnd(c, 0x40)
    return [item, a1, a2]


S(0x46e8e0, 'ZItem::GetMainItemRootTM (unknown) thiscall', 'thiscall', None, ret=None, gen=_item,
  note='unclaimed-07 batch 9; flag 0x200000 at [this+8]+0x3c picks slots 0x2e0+0x98 or root chain 0x2f4/0x1e0/0x2a4/0x98')
