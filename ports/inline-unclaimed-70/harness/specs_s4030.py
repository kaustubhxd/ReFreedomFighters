"""specs_s4030.py - area 70 batch 4030: 0x5048d0 (GUESS name). The list accessor 0x5003d0 runs as exe code over three lists
(obj+4 for n and the pointer offset, obj+8 for the final call); n is drawn in -2..3 so both branches run. The error helper
0x5057e0 (ret 8) and 0x5002f0 (ret 4) are stubbed BY ADDRESS and record their arguments. Slot 0x5c on this returns a per-case
value and records its arguments (the pointer and two floats as bit patterns). The render manager's +0x44 is a data block."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _list(c, e, first):
    r = c.rng
    data = e.alloc(0x100, 16)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(0x100)))
    e.w32(data, first & 0xffffffff)
    base = e.alloc(0x20, 4)
    e.w32(base, data)
    e.w32(base + 8, 16)
    lst = e.alloc(0x20, 4)
    e.w32(lst, base)
    e.w32(lst + 4, 0)
    e.w32(lst + 8, 2 + r.randrange(0, 4))
    return lst


def _chain(c):
    e, r = c.emu, c.rng
    n = r.randrange(-2, 4)
    retv = r.getrandbits(32)
    eax2 = r.getrandbits(32)

    def err(em, rr):
        em.calllog.append(('5057e0', em.reg('ecx') & 0xffffffff, em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)

    def f5002(em, rr):
        em.calllog.append(('5002f0', em.reg('ecx') & 0xffffffff, em.arg32(0)))
        em.ret(eax=eax2, argbytes=4)

    _stub_addr(c, 0x5057e0, 'err_5057e0', err)
    _stub_addr(c, 0x5002f0, 'f_5002f0', f5002)

    def slot5c(em, rr):
        em.calllog.append(('5c', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=retv, argbytes=12)

    vt = e.fake_vtable('this_5048d0', 0x18, {0x5c: slot5c})
    self_ = e.alloc(0x40, 4)
    e.w32(self_, vt)
    rm44 = e.alloc(0x200, 16)
    e.wbytes(rm44, bytes(r.getrandbits(8) for _ in range(0x200)))
    rm = e.alloc(0x80, 4)
    e.w32(rm + 0x44, rm44)
    sys_ = e.alloc(0xc0, 16)
    e.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0xc0)))
    e.w32(sys_ + 0x9b, rm)
    e.w32(0x70039c, sys_)
    obj = e.alloc(0x40, 4)
    e.w32(obj + 4, _list(c, e, n))
    e.w32(obj + 8, _list(c, e, r.getrandbits(32)))
    return [self_, obj]


S(0x5048d0, 'list values feed a virtual call or the error helper, then 0x5002f0 (name GUESS)', 'thiscall', None,
  ret='eax', gen=_chain, note='batch4030')
