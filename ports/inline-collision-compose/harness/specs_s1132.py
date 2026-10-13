"""specs_s1132.py - collision thread batch 1132: 0x4e31f0 (GUESS name). The sift-down 0x4e3230 is stubbed BY ADDRESS: a
recorder that logs ECX, EDX and its start argument and pops four bytes (its ret 4 exit). Its heap writes are not modelled, so
its body is not verified. The record array is 9-byte records; the count is 1..8."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _pop(c):
    e, r = c.emu, c.rng

    def sift(em, rr):
        em.calllog.append(('4e3230', em.reg('ecx') & 0xffffffff, em.reg('edx') & 0xffffffff, em.arg32(0)))
        em.ret(argbytes=4)

    _stub_addr(c, 0x4e3230, 'sift_4e3230', sift)
    base = e.alloc(0x200, 16)
    e.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x200)))
    out = e.alloc(0x10, 4)
    e.wbytes(out, bytes(r.getrandbits(8) for _ in range(0x10)))
    count = r.randrange(1, 9)
    return [base, count, out]


S(0x4e31f0, 'pop the first 9-byte record; sift-down stubbed by address (name GUESS)', 'fastcall', None, ret='eax',
  gen=_pop, note='batch1132')
