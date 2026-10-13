"""specs_s1133.py - collision thread batch 1133 (gap-list rows, GUESS names). 0x4d24e0 is stubbed BY ADDRESS (a recorder that logs
ECX and its four stack values, pops 0x10, returns a per-case EAX; its body is not verified). The two stores need only a buffer."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _s2(c):
    e, r = c.emu, c.rng
    out = e.alloc(0x20, 4)
    e.wbytes(out, bytes(r.getrandbits(8) for _ in range(0x20)))
    return [r.getrandbits(32), out, r.getrandbits(32)]


def _s2at(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [self_, r.getrandbits(32), r.getrandbits(32)]


def _w(c):
    e, r = c.emu, c.rng
    retv = r.getrandbits(32)

    def callee(em, rr):
        em.calllog.append(('4d24e0', em.reg('ecx') & 0xffffffff, tuple(em.arg32(i) for i in range(4))))
        em.ret(eax=retv, argbytes=0x10)

    _stub_addr(c, 0x4d24e0, 'callee_4d24e0', callee)
    return [e.alloc(0x40, 4), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4d2bc0, 'store c and b into out[0] and out[1] (name GUESS)', 'thiscall', None, gen=_s2, note='batch1133')
S(0x5ac640, 'store a and b at [this+0xd] and [this+0x15] (name GUESS)', 'thiscall', None, gen=_s2at, note='batch1133')
S(0x4d39c0, 'wrapper of 0x4d24e0 with ECX passed through, second argument 2 (name GUESS)', 'thiscall', None, ret='eax',
  gen=_w, note='batch1133')
