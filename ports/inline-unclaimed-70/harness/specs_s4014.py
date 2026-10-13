"""specs_s4014.py - area 70 batch 4014: 0x558a10 (GUESS name). 0x5003d0 is exe code (a bounded element accessor): the list
object gives a base with a count, so indices 0 and 1 are in range. 0x59e690 is stubbed BY ADDRESS (E9 jump to a recording
stub, image restored per case); its ret 8 is the caller's convention (no esp fix-up after the call)."""
import struct
from pilot import S, F

CALLEE = 0x59e690


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _take(c):
    e, r = c.emu, c.rng
    retv = r.getrandbits(32)   # unused by the callee's result (void)

    def callee(em, rr):
        em.calllog.append(('59e690', em.reg('ecx') & 0xffffffff, em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)

    _stub_addr(c, CALLEE, 'callee_59e690', callee)
    data = e.alloc(0x200, 16)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(0x200)))
    base = e.alloc(0x20, 4)
    e.w32(base, data)
    e.w32(base + 8, 16)
    lst = e.alloc(0x20, 4)
    e.w32(lst, base)
    e.w32(lst + 4, r.randrange(0, 4))
    e.w32(lst + 8, 2 + r.randrange(0, 6))
    src = e.alloc(0x20, 4)
    e.w32(src + 4, lst)
    self_ = e.alloc(0x80, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x80)))
    return [self_, src]


S(0x558a10, 'takes entries 0 and 1 of the list at [src+4] (name GUESS)', 'thiscall', None, gen=_take, note='batch4014')
