"""specs_s4031.py - area 70 batch 4031: 0x4a80d0 (GUESS name; SEH frame not reproduced). Slot 0x34 of the render manager is a
fake that records its argument. 0x4690b0 (cdecl, (ptr, size)) is stubbed BY ADDRESS and records its arguments (the pointer is a
heap address, deterministic per case). The hook at 0x7003b0 is a recording cdecl stub. The flags byte covers all four
combinations of bits 0 and 2."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _init(c):
    e, r = c.emu, c.rng

    def slot34(em, rr):
        em.calllog.append(('34', em.arg32(0)))
        em.ret(argbytes=4)

    def free(em, rr):
        em.calllog.append(('4690b0', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=0)                    # cdecl

    def hook(em, rr):
        em.calllog.append(('hook',))
        em.ret(argbytes=0)

    _stub_addr(c, 0x4690b0, 'free_4690b0', free)
    h = e.stub_fn('hook_7003b0', hook)
    e.w32(0x7003b0, h)
    rvt = e.fake_vtable('rm_4a80d0', 0x40, {0x34: slot34})
    rm = e.alloc(0x40, 4)
    e.w32(rm, rvt)
    sys_ = e.alloc(0xc0, 16)
    e.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0xc0)))
    e.w32(sys_ + 0x9b, rm)
    e.w32(0x70039c, sys_)
    self_ = e.alloc(0x100, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    flags = r.getrandbits(8)
    flags = (flags & ~5) | r.choice([0, 1, 4, 5])      # all four bit-0/bit-2 combinations
    return [self_, flags]


S(0x4a80d0, 'init: fields and vtable, slot 0x34 of the render manager, then free (bit 2) or hook (bit 0) (name GUESS)',
  'thiscall', None, ret='eax', gen=_init, note='batch4031')
