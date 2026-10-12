"""specs_s8018.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _g(c, slot):
    self_ = _obj(c, 0x20)
    child = _obj(c, 0x20) if c.rng.random() < 0.6 else 0
    c.emu.w32(self_ + 0x8, child)
    def h(e, r):
        e.calllog.append(("global slot %x" % slot, e.reg("ecx")))
        e.ret(eax=0, argbytes=0)
    g = _obj(c, 0x40)
    vt = c.emu.fake_vtable("GlobVt18", 0x50, {slot: h})
    c.emu.w32(g, vt)
    c.emu.w32(0x70038c, g)
    return [self_]

S(0x48cee0, '(GUESS) 0x48cee0 global slot 0x40 then tail', 'thiscall', None, ret=None,
  gen=lambda c: _g(c, 0x40),
  note='unclaimed-79 gap-band thiscall, slot +0x40 of 0x70038c then tail to 0x4690b0 if this+8')

S(0x48cf00, '(GUESS) 0x48cf00 global slot 0x44 then tail', 'thiscall', None, ret=None,
  gen=lambda c: _g(c, 0x44),
  note='unclaimed-79 gap-band thiscall, slot +0x44 of 0x70038c then tail to 0x4690b0 if this+8')
