"""specs_s4022.py - area 70 batch 4022: 0x440ed0 (render-manager slot 0x58, then 0x610420 stubbed by address with four
arguments, ret 0x10) and 0x4d28d0 (0x4cee30 stubbed by address, ret 8; vtable slot 0xc on the object stored at +0x4008).
GUESS names. The engine global 0x70039c points to a heap fake; its +0x9b is the render manager."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _fn440(c):
    e, r = c.emu, c.rng
    rv58 = r.getrandbits(32) if r.random() < 0.8 else 0
    rv610 = r.getrandbits(32)

    def slot58(em, rr):
        em.calllog.append(('58', em.arg32(0)))
        em.ret(eax=rv58, argbytes=4)

    def callee(em, rr):
        em.calllog.append(('610420', em.reg('ecx') & 0xffffffff, tuple(em.arg32(i) for i in range(4))))
        em.ret(eax=rv610, argbytes=0x10)

    _stub_addr(c, 0x610420, 'callee_610420', callee)
    vt = e.fake_vtable('rm_440ed0', 0x24, {0x58: slot58})
    rm = e.alloc(0x40, 4)
    e.w32(rm, vt)
    e.w32(rm + 0x14, r.getrandbits(32))
    sys_ = e.alloc(0xc0, 16)
    e.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0xc0)))
    e.w32(sys_ + 0x9b, rm)
    e.w32(0x70039c, sys_)
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _fn4d2(c):
    e, r = c.emu, c.rng

    def callee(em, rr):
        em.calllog.append(('4cee30', em.reg('ecx') & 0xffffffff, em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)

    _stub_addr(c, 0x4cee30, 'callee_4cee30', callee)
    vt = e.fake_vtable('obj4008_4d28d0', 0x10, {0xc: lambda em, rr: em.ret(argbytes=0)})
    self_ = e.alloc(0x4100, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x4100)))
    e.w32(self_ + 0x4008, vt)
    return [self_]


S(0x440ed0, 'slot 0x58 on the render manager, then 0x610420 with four stack args (name GUESS)', 'stdcall', None, ret='al',
  gen=_fn440, note='batch4022')
S(0x4d28d0, 'init: 0x4cee30, vtable slot 0xc on [this+0x4008], store this+4 (name GUESS)', 'thiscall', None, gen=_fn4d2,
  note='batch4022')
