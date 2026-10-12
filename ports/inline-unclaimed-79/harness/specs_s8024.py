"""specs_s8024.py - unclaimed-79 unclaimed small row (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _slotobj(c, name, slots, size=0x40):
    o = _obj(c, size)
    vt = c.emu.fake_vtable(name, 0x60, slots)
    c.emu.w32(o, vt)
    return o

def _g48f540(c):
    def hlog(tag, argb):
        def h(e, r):
            e.calllog.append((tag, e.reg("ecx"), tuple(e.arg32(k) for k in range(argb // 4))))
            e.ret(eax=0, argbytes=argb)
        return h
    m_obj = _slotobj(c, "VtM24", {0x14c: hlog("slot 14c", 4)})
    a2 = _slotobj(c, "VtA24", {0: hlog("slot 0", 4)})
    c.emu.w32(a2 + 0x30, m_obj if c.rng.random() < 0.5 else 0)
    a1 = m_obj if c.rng.random() < 0.5 else 0
    o = _slotobj(c, "VtO24", {0x48: hlog("slot 48", 4)})
    self_ = _obj(c, 0x20)
    c.emu.w32(self_ + 0x8, o)
    return [self_, a1, a2]

S(0x48f540, '(GUESS) 0x48f540 slots 14c, 0, 48', 'thiscall', None, ret=None, gen=_g48f540,
  note='unclaimed-79 unclaimed small row: slot +0x14c of a1 (or a2+0x30), slot 0 of a2, slot +0x48 of this+8')
