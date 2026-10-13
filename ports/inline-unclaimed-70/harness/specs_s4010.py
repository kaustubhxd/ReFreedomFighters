"""specs_s4010.py - area 70 batch 4010: 0x4d3d10 (wrapper). The callee 0x4d2700 is stubbed BY ADDRESS: the first five bytes of
its entry are overwritten (in the exe image, which is restored before every case) with a jump to a recording stub. The stub
logs its five stack arguments and ECX, returns a per-case value and pops 0x14 (its ret 0x14 path). GUESS stub."""
import struct
from pilot import S, F

CALLEE = 0x4d2700


def _stub_addr(c, addr, name, handler, argbytes):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _wrap(c):
    e, r = c.emu, c.rng
    retv = r.getrandbits(32)
    def callee(em, rr):
        args = [em.arg32(k) for k in range(5)]
        em.calllog.append(('d2700', em.reg('ecx') & 0xffffffff, tuple(args)))
        em.ret(eax=retv, argbytes=0x14)
    _stub_addr(c, CALLEE, 'callee_d2700', callee, 0x14)
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [self_, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4d3d10, 'wrapper around 0x4d2700 (stubbed by address; GUESS)', 'thiscall', None, ret='eax', gen=_wrap, note='batch4010')
