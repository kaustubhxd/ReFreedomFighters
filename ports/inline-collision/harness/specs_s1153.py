"""specs_s1153.py - collision thread batch 1153 (GUESS name): 0x4fc170, a jump to the camera update 0x4fdd20 (exe code). The
object is random bytes; the spec only checks the thunk's forwarding of ECX and the target's effects."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _cam(c):
    e, r = c.emu, c.rng

    def upd(em, rr):                        # GUESS stub for the camera update: records ECX, pops nothing
        em.calllog.append(('4fdd20', em.reg('ecx') & 0xffffffff))
        em.ret(argbytes=0)
    _stub_addr(c, 0x4fdd20, 'camera_4fdd20', upd)
    o = e.alloc(0x400, 16)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x400)))
    return [o]


S(0x4fc170, 'thunk to the camera update 0x4fdd20 (name GUESS)', 'thiscall', None, ret=None, gen=_cam, note='batch1153')
