"""specs_s8014.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _loop(c):
    n = c.rng.randrange(0, 6)
    def hc(e, r):
        e.calllog.append(("count ac", e.reg("ecx")))
        e.ret(eax=n, argbytes=0)
    def h(e, r):
        e.calllog.append(("step a4", e.reg("ecx")))
        e.ret(eax=0, argbytes=0)
    o = _obj(c, 0x40)
    vt = c.emu.fake_vtable("VtS14", 0x50, {0xac: hc, 0xa4: h})
    c.emu.w32(o, vt)
    return [o]

S(0x4931a0, '(GUESS) 0x4931a0 count loop', 'thiscall', None, ret=None, gen=_loop,
  note='unclaimed-79 gap-band thiscall, calls slot +0xa4 count (from slot +0xac) times')
