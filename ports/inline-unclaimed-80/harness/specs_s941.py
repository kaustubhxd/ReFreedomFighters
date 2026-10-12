"""specs_s941.py - unclaimed-80 (docs/20-unclaimed-80.md): ZGROUP::CorrectCenSizeRecur (0x43fa70). The list at this+0x50 has 0..3 nodes
(next at +0x60); each object at +0x54 is null 20% of the time (flags 0x200002, no call) or a logging-fake object whose +0xc points at a
record with a random dword at +0x23 (bit 0x100000 set half the time: the object's slot +0x27c is called). This's slot +0x280 is a
logging fake (no arguments). The flags are chosen so both calls occur."""
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


def _recur(c):
    self_o = _rnd(c, 0x100)
    c.emu.w32(self_o, _fake(c, 'ZGroupSelf', 0x290, {0x280: (0, lambda e, a: (0, None))}))
    head = 0
    nodes = []
    for _ in range(c.rng.randint(0, 3)):
        nodes.append(_rnd(c, 0x80))
    for i, nd in enumerate(nodes):
        nxt = nodes[i + 1] if i + 1 < len(nodes) else 0
        c.emu.w32(nd + 0x60, nxt)
        if c.rng.random() < 0.2:
            c.emu.w32(nd + 0x54, 0)
        else:
            obj = _rnd(c, 0x40)
            q = _rnd(c, 0x40)
            c.emu.w32(obj + 0xc, q)
            flags = c.rng.getrandbits(32)
            flags = (flags | 0x100000) if c.rng.random() < 0.5 else (flags & ~0x100000 & 0xffffffff)
            c.emu.w32(q + 0x23, flags)
            c.emu.w32(obj, _fake(c, 'ZGroupObj', 0x290, {0x27c: (0, lambda e, a: (0, None))}))
            c.emu.w32(nd + 0x54, obj)
    if nodes:
        head = nodes[0]
    c.emu.w32(self_o + 0x50, head)
    return [self_o]


S(0x43fa70, 'ZGROUP::CorrectCenSizeRecur (unknown) thiscall', 'thiscall', None, ret=None, gen=_recur,
  note='unclaimed-80; list walk; slot +0x27c per flagged node; this slot +0x280 (tail, no args)')
