"""specs_s4017.py - area 70 batch 4017: 0x45fdd0 (thunk into 0x4dd8f0, GUESS name). 0x4dd8f0 runs as exe code; its direct
callee 0x4419f0 (fastcall ECX = argument, EDX = this; no stack arguments) is stubbed BY ADDRESS and records both registers."""
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
        em.calllog.append(('4419f0', em.reg('ecx') & 0xffffffff, em.reg('edx') & 0xffffffff))
        em.ret(eax=retv, argbytes=0)

    _stub_addr(c, 0x4419f0, 'callee_4419f0', callee)
    child = e.alloc(0x40, 4)
    self_ = e.alloc(0x40, 4)
    e.w32(self_ + 8, child)
    return [self_, r.getrandbits(32)]


S(0x45fdd0, 'thunk: ECX = [this+8] and the argument into 0x4dd8f0 (name GUESS)', 'thiscall', None, ret='eax', gen=_thunk,
  note='batch4017')
