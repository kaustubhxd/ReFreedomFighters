"""specs_s4025.py - area 70 batch 4025: 0x4d2c90 (GUESS name). Slot 0xb0 on this (two args, logged constants) returns a per-case
object p or zero. The memmove thunk 0x634d22 is stubbed BY ADDRESS: a cdecl stub that really copies the bytes (so the
destination is compared) and returns dst."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _copy(c):
    e, r = c.emu, c.rng

    def memmove(em, rr):
        dst, src, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('634d22', n))
        em.wbytes(dst, em.rbytes(src, n))
        em.ret(eax=dst, argbytes=0)           # cdecl

    _stub_addr(c, 0x634d22, 'memmove_634d22', memmove)
    p = e.alloc(0x200, 16)
    e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x200)))
    w = r.randrange(0, 0x40)
    e.w32(p, w)
    e.w32(p + 8, r.randrange(0, 0x40))

    ret_p = p if r.random() < 0.8 else 0     # decided per case, not per run

    def slot_b0(em, rr):
        em.calllog.append(('b0', em.arg32(0), em.arg32(1)))
        em.ret(eax=ret_p, argbytes=8)

    vt = e.fake_vtable('this_4d2c90', 0x2d, {0xb0: slot_b0})
    self_ = e.alloc(0x40, 4)
    e.w32(self_, vt)
    dst = e.alloc(0x100, 16)
    e.wbytes(dst, bytes(r.getrandbits(8) for _ in range(0x100)))
    return [self_, dst, r.getrandbits(32), r.getrandbits(32)]


S(0x4d2c90, 'copy p->[p+8] bytes from p + p[0] + 0xc, p from slot 0xb0 (name GUESS)', 'thiscall', None, ret='eax',
  gen=_copy, note='batch4025')
