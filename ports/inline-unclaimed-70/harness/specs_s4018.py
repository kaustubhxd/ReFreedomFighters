"""specs_s4018.py - area 70 batch 4018: 0x51b210 and 0x55c710 (GUESS names). 0x5003d0 runs as exe code over a list object
(base with count; indices 0 in range). 0x5002f0 and 0x5a2f10 are stubbed BY ADDRESS (each records ECX and its argument and
returns a per-case EAX; ret 4). Slot 0x380 on [this+0x1c] (51b210) returns a per-case value."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _stubs(c, tag):
    e, r = c.emu, c.rng
    retv = r.getrandbits(32)

    def rec(name):
        def f(em, rr):
            em.calllog.append((name, em.reg('ecx') & 0xffffffff, em.arg32(0)))
            em.ret(eax=retv, argbytes=4)
        return f

    _stub_addr(c, 0x5002f0, 'callee_5002f0_' + tag, rec('5002f0'))
    _stub_addr(c, 0x5a2f10, 'callee_5a2f10_' + tag, rec('5a2f10'))


def _list(c, e):
    r = c.rng
    data = e.alloc(0x100, 16)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(0x100)))
    base = e.alloc(0x20, 4)
    e.w32(base, data)
    e.w32(base + 8, 16)
    lst = e.alloc(0x20, 4)
    e.w32(lst, base)
    e.w32(lst + 4, 0)
    e.w32(lst + 8, 2 + r.randrange(0, 6))
    return lst


def _left(c):
    e, r = c.emu, c.rng
    _stubs(c, 'l')
    rv = r.getrandbits(32)
    vt = e.fake_vtable('o380_51b210', 0xe1, {0x380: lambda em, rr: em.ret(eax=rv, argbytes=0)})
    o = e.alloc(0x40, 4)
    e.w32(o, vt)
    self_ = e.alloc(0x40, 4)
    e.w32(self_ + 0x1c, o)
    obj = e.alloc(0x40, 4)
    e.w32(obj + 8, _list(c, e))
    return [self_, obj]


def _right(c):
    e, r = c.emu, c.rng
    _stubs(c, 'r')
    o = e.alloc(0x40, 4)
    self_ = e.alloc(0x40, 4)
    e.w32(self_ + 0x1c, o)
    obj = e.alloc(0x40, 4)
    e.w32(obj + 4, _list(c, e))
    return [self_, obj]


S(0x51b210, 'element 0 of obj+8 into 0x5002f0 with the slot-0x380 value (name GUESS)', 'thiscall', None, ret='eax',
  gen=_left, note='batch4018')
S(0x55c710, 'element 0 of obj+4 into 0x5a2f10 with [this+0x1c] (name GUESS)', 'thiscall', None, ret='eax', gen=_right,
  note='batch4018')
