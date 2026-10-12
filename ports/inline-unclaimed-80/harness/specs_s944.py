"""specs_s944.py - unclaimed-80 (docs/20-unclaimed-80.md): ZGROUP::SendCommandRecursive (0x441820). this's vtable slot +0x128 is a logging
fake (three arguments, callee-cleaned). The list at this+0x50 has 0..3 nodes; each node's object (70% nonzero) has a logging fake vtable
whose slot +0x138 takes three arguments (callee-cleaned). Every call logs its ecx and its three arguments."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fake(c, name, nslots, handlers):
    slots = {}
    for off, (n, cleanup, fn) in handlers.items():
        def h(e, r, off=off, n=n, cleanup=cleanup, fn=fn):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
            eax, st0 = fn(e, args)
            e.ret(eax=eax, argbytes=cleanup)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _send(c):
    self_o = _rnd(c, 0x100)
    c.emu.w32(self_o, _fake(c, 'ZGroupSend', 0x130, {0x128: (3, 12, lambda e, a: (0, None))}))
    nodes = [_rnd(c, 0x80) for _ in range(c.rng.randint(0, 3))]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 0x60, nodes[i + 1] if i + 1 < len(nodes) else 0)
        if c.rng.random() < 0.7:
            obj = _rnd(c, 0x40)
            c.emu.w32(obj, _fake(c, 'ZGroupNodeObj', 0x140, {0x138: (3, 12, lambda e, a: (0, None))}))
            c.emu.w32(nd + 0x54, obj)
        else:
            c.emu.w32(nd + 0x54, 0)
    c.emu.w32(self_o + 0x50, nodes[0] if nodes else 0)
    return [self_o, c.rng.getrandbits(16), _rnd(c, 16), _rnd(c, 16)]


S(0x441820, 'ZGROUP::SendCommandRecursive (unknown) thiscall', 'thiscall', None, ret=None, gen=_send,
  note='unclaimed-80; slot +0x128 (this) and slot +0x138 (each node object), three arguments, callee-cleaned')
