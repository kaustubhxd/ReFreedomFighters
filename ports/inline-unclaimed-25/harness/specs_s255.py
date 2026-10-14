"""specs_s255.py - unclaimed area 25: 0x4b89d0 ZRelayMessageList::FrameUpdate (ext 0x4b8ab0 original; vslot 0x68 logged)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _frame(c):
    eng = _rnd(c, 0x80)
    c.emu.w32(eng + 0x40, c.rng.choice([0x80000000, 0x7fffffff, 0, 5]))   # below v: early return; at or above: the calls
    c.emu.w32(0x70039c, eng)
    # ext 0x4b8ab0 walks the container at +0x4c (slots 0x4c and 0x5c, each with a flag out-pointer) and calls
    # slot 0x12c of the object at +0x44 for each item. The ext runs as original code on both sides.
    items = [_rnd(c, 0x40) for _ in range(c.rng.choice([0, 1, 2]))]
    st = {'i': 0}

    def s5c(e, args):
        if st['i'] < len(items):
            it = items[st['i']]
            st['i'] += 1
            e.w32(args[0], 1)
            return (it, None)
        e.w32(args[0], 0)
        return (0, None)

    cvt = c.emu.logging_vtable('Cont', 0x140, impl={0x5c: s5c}, argwords={0x4c: 2, 0x5c: 1})
    cont = _rnd(c, 0x40)
    c.emu.w32(cont, cvt)
    hvt = c.emu.logging_vtable('Hit', 0x140, argwords={0x12c: 3})
    h44 = _rnd(c, 0x40)
    c.emu.w32(h44, hvt)
    vt = c.emu.logging_vtable('Relay', 0x140, argwords={0x68: 2})
    obj = _rnd(c, 0x100)
    c.emu.w32(obj, vt)
    c.emu.w32(obj + 0x4c, cont)
    c.emu.w32(obj + 0x44, h44)
    c.emu.wbytes(obj + 0x50, bytes([0x00, 0x00, c.rng.choice([0x80, 0x00, 0x3f]), 0x41]))
    c.emu.wbytes(obj + 0x54, bytes([0x00, 0x00, 0x80, 0x3f]))
    c.emu.mu.ctl_flush_tb()
    return [obj]


S(0x4b89d0, 'ZRelayMessageList::FrameUpdate', 'thiscall', None, ret=None, gen=_frame,
  note='batch255; ext 0x4b8ab0 (original) and logged vslot 0x68')
