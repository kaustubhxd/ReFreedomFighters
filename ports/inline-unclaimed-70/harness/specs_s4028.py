"""specs_s4028.py - area 70 batch 4028: 0x5f0050 (GUESS name). The base destructor 0x5ec7e0 (SEH-framed) and the free routine
0x634273 (cdecl, (ptr, size)) are stubbed BY ADDRESS. The free stub records its arguments and does not touch memory; the
destructor stub records ECX. Bit 0 of the flags is drawn for both paths."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _del(c):
    e, r = c.emu, c.rng

    def base_dtor(em, rr):
        em.calllog.append(('5ec7e0', em.reg('ecx') & 0xffffffff))
        em.ret(argbytes=0)

    def free(em, rr):
        em.calllog.append(('634273', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=0)                     # cdecl

    _stub_addr(c, 0x5ec7e0, 'base_dtor_5ec7e0', base_dtor)
    _stub_addr(c, 0x634273, 'free_634273', free)
    o = e.alloc(0x100, 16)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x100)))
    return [o, r.getrandbits(32)]


S(0x5f0050, 'deleting destructor shape: vtable, base dtor (stub), free of 0xdb bytes when bit 0 (name GUESS)', 'thiscall',
  None, ret='eax', gen=_del, note='batch4028')
