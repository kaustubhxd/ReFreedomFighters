"""specs_s8013.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _counter(c):
    o = _obj(c, 0x5d3d)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x5d39, 0)
    return [o]

def _list491e80(c):
    # this: vtable slot 0x158 returns the head of a 3-node list; a key is taken from a node half the time
    nodes = [_obj(c, 0x30) for _ in range(3)]
    keys = [c.rng.getrandbits(32) for _ in range(3)]
    for i, n in enumerate(nodes):
        c.emu.w32(n + 0x23, keys[i])
        c.emu.w32(n + 0xc, nodes[i + 1] if i < 2 else 0)
    head = nodes[0]
    def h(e, r):
        e.calllog.append(("slot 158", e.reg("ecx"), (e.arg32(0),)))
        e.ret(eax=head, argbytes=4)
    o = _obj(c, 0x40)
    vt = c.emu.fake_vtable("VtS13", 0x160, {0x158: h})
    c.emu.w32(o, vt)
    k = keys[c.rng.randrange(3)] if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    return [o, c.rng.getrandbits(32), k]

S(0x48f730, '(GUESS) 0x48f730 decrement if nonzero', 'thiscall', None, ret=None, gen=_counter,
  note='unclaimed-79 gap-band thiscall, decrements this+0x5d39 when nonzero')

S(0x491e80, '(GUESS) 0x491e80 list scan via slot 0x158', 'thiscall', None, ret='al', gen=_list491e80,
  note='unclaimed-79 gap-band thiscall, vtable list head then key scan, bool result')
