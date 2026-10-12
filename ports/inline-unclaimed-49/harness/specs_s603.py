"""specs_s603.py - area 49 batch 603: ZInputAction::AddNode (0x437900). Node/owner blocks, a lookup object (slot 0x64),
this's slot 4, and a debug logger whose slot 0x20 returns a stream per line (the stream's printf stub records its args)."""
from pilot import S
from pe_emu import F
from wkit import rnd, stub, obj, b, fedge  # noqa: F401


def _logger(c):
    streams = {}
    for line, nargs in ((0xfb4, 4), (0xfb5, 2), (0xfb6, 2), (0xfb7, 2)):
        st = obj(c, 0x20, {0x2c: stub(c, nargs, cdecl=True)})
        streams[line] = st

    def handler(e, r):
        line = e.arg32(1)
        e.ret(eax=streams[line], argbytes=8)

    lg = c.emu.fake_object('logger', 0x40, nslots=0x24, slots={0x20: handler})
    c.emu.w32(0x700390, lg)


def _addnode(c):
    r = c.rng
    _logger(c)
    # the lookup object T: slot 0x64 (one argument, the name) returns an index or -1
    t = obj(c, 0x40, {0x64: stub(c, 1, ret=r.choice((0xffffffff, 0, 3, 0xffffffff)))})
    q = rnd(c, 0x60)
    kind = r.choice((1, 3))
    if kind == 3:
        node = q + 4
        c.emu.w32(node, 3)
        c.emu.w32(q + 0x11, t)            # ecx = node - 4 = q; [q + 0x11] = t
    else:
        node = q + 4
        c.emu.w32(node, 1)
        y = q + 0x10
        c.emu.w32(node + 8, y)            # ecx = y - 4 = q + 0xc; [q + 0xc + 0x11] = [q + 0x1d] = t
        c.emu.w32(q + 0x1d, t)
    # this: +0xc = node, slot 4 = the matching handler (records index and flag)
    me = obj(c, 0x40, {4: stub(c, 2)})
    c.emu.w32(me + 0xc, node)
    name = c.emu.alloc(8, 4)
    c.emu.wbytes(name, b'Node\x00\x00\x00\x00')
    c.emu.w32(q + 4 + 4, r.getrandbits(32))   # node+4: the name pointer printed by the -1 path
    return [me, name, r.getrandbits(1)]


S(0x437900, 'ZInputAction::AddNode', 'thiscall', None, ret=None, gen=_addnode)
