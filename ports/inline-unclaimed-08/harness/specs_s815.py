"""specs_s815.py - unclaimed-08 batch 815 (docs/20-unclaimed-08.md): ZBoundDeactivator::Init(ZGEOM*, DBREAD&), thiscall,
two stack arguments (ret 8), void.

The REFTAB constructor (0x4ccba0) and destructor (0x4ccf60) run the original code. DBREAD::GetRefTab (0x4e6330) is a
STUB (hook): it counts the call and records ECX, but not its stack argument (a stack address that differs between
builds) and writes nothing. The geometry argument is random and unread; the DBREAD object is random 0x40 bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _init(c):
    self = _rnd(c, 0x100)
    geom = _rnd(c, 0x40)
    dbread = _rnd(c, 0x40)

    n2 = c.emu.alloc(0x10); n1 = c.emu.alloc(0x10)
    c.emu.w32(n1 + 4, n2); c.emu.w32(n2 + 4, 0)     # two nodes; the REFTAB destructor walks them through +4
    def h(e, r):
        e.calllog.append(('DBREAD::GetRefTab (stub)', 0x4e6330, e.reg('ecx'), ()))
        tab = e.arg32(0)
        e.w32(tab + 4, n1)                    # the list head (the nodes were built once per case, in the generator)
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x4e6330, h)
    # the REFTAB destructor (0x4ccf60) stores the exe vtable 0x6957bc and calls its slot +0x7c on each node: record that target
    tgt = c.emu.r32(0x6957bc + 0x7c)
    def hslot(e, r):
        e.calllog.append(('REFTAB node slot +0x7c (hook)', tgt, None, (e.arg32(0),)))   # ECX is the REFTAB's stack address: not logged
        e.ret(eax=0, argbytes=4)
    c.emu.hook(tgt, hslot)
    return [self, geom, dbread]


S(0x4c7b30, 'ZBoundDeactivator::Init (unknown)', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-08 batch 15; REFTAB ctor/dtor original; DBREAD::GetRefTab STUBBED (no args logged, writes nothing)')
