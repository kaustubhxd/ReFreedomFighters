"""specs_s4015.py - area 70 batch 4015: 0x45f410 (thunk) and 0x5fa590 (GUESS names). Exe callees 0x4dc030 (recursive
scene walk) and 0x5fa0d0 (name lookup) are stubbed BY ADDRESS: the first five bytes are overwritten with a jump to a recording
stub (image restored per case). Virtual slots: 0x38 on the this object (returns a per-case value), 0x2c on the obj (records)."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _thunk(c):
    e, r = c.emu, c.rng
    retv = r.getrandbits(32)

    def callee(em, rr):
        em.calllog.append(('4dc030', em.reg('ecx') & 0xffffffff))
        em.ret(eax=retv, argbytes=0)

    _stub_addr(c, 0x4dc030, 'callee_4dc030', callee)
    child = e.alloc(0x40, 4)
    self_ = e.alloc(0x40, 4)
    e.w32(self_ + 8, child)
    return [self_]


def _fn5fa590(c):
    e, r = c.emu, c.rng
    retv = r.getrandbits(32)

    def callee(em, rr):
        em.calllog.append(('5fa0d0', em.reg('ecx') & 0xffffffff, em.arg32(0)))
        em.ret(eax=retv, argbytes=4)

    _stub_addr(c, 0x5fa0d0, 'callee_5fa0d0', callee)
    v38 = r.getrandbits(32)

    def slot38(em, rr):
        em.ret(eax=v38, argbytes=4)

    vt = e.fake_vtable('this_5fa590', 0x39, {0x38: slot38})
    self_ = e.alloc(0x40, 4)
    e.w32(self_, vt)
    e.w32(self_ + 4, r.getrandbits(32))
    vt2 = e.logging_vtable('obj_5fa590', 0x2e, impl={0x2c: lambda em, a: (None, None)}, argwords={0x2c: 1})
    obj = e.alloc(0x40, 4)
    e.w32(obj, vt2)
    arg2 = e.alloc(0x40, 4)
    e.wbytes(arg2, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [self_, obj, arg2]


S(0x45f410, 'thunk: tail jump to 0x4dc030 with ECX = [this+8] (name GUESS)', 'thiscall', None, ret='eax', gen=_thunk,
  note='batch4015')
S(0x5fa590, 'two vtable calls around 0x5fa0d0 name lookup (name GUESS)', 'thiscall', None, gen=_fn5fa590, note='batch4015')
