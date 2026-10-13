"""specs_s4016.py - area 70 batch 4016: 0x4ce810 (GUESS name). Exe callees 0x41e290 (cdecl allocator) and 0x634d10 (the memset
thunk) are stubbed BY ADDRESS: the allocator hands out one per-case block; the memset stub really fills the block (so the
written bytes are compared) and returns its destination. Both are plain cdecl (no clean-up in the stub)."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _alloc_or_inline(c):
    e, r = c.emu, c.rng
    block = e.alloc(0x200, 16)

    def alloc(em, rr):
        em.calllog.append(('41e290', em.arg32(0)))
        em.ret(eax=block, argbytes=0)            # cdecl: the caller cleans the argument

    def memset(em, rr):
        dst, val, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('634d10', dst == block, val, n))
        n = min(n, 0x200)
        em.wbytes(block, bytes([val & 0xff]) * n)
        em.ret(eax=dst, argbytes=0)              # cdecl

    _stub_addr(c, 0x41e290, 'callee_41e290', alloc)
    _stub_addr(c, 0x634d10, 'callee_memset', memset)
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(self_ + 4, 0 if r.random() < 0.3 else 1)
    e.w32(self_ + 0x10, r.randrange(0, 40))
    return [self_]


S(0x4ce810, 'inline buffer or block of 16 + 4*count bytes filled with 0x22 (name GUESS)', 'thiscall', None, ret='eax',
  gen=_alloc_or_inline, note='batch4016')
