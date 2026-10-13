"""specs_s4019.py - area 70 batch 4019: 0x594ed0 (pure flag setter), 0x55ce90 (list element 0 through 0x5003d0, exe code) and
0x5e1190 (initialiser; its callee 0x5e0e10 is stubbed BY ADDRESS: records ECX and the two arguments, ret 8). GUESS names."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _flag(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x500, 16)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x500)))
    f = e.r32(o + 0x417) & ~0xe000000          # random dwords have bits 25..27 set 7 times in 8: clear them for most cases
    if r.random() < 0.3:                      # so the write path runs; sometimes a bit in 25..27 stays set (early return)
        f |= 1 << r.randrange(25, 28)
    e.w32(o + 0x417, f)
    flag = r.getrandbits(32)
    if r.random() < 0.5:
        flag &= ~0xff                          # low byte zero: the clear branch (the flag is a byte)
    return [o, flag]


def _list(c, e):
    r = c.rng
    data = e.alloc(0x100, 16)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(0x100)))
    if r.random() < 0.5:
        e.w32(data, 0)
    base = e.alloc(0x20, 4)
    e.w32(base, data)
    e.w32(base + 8, 16)
    lst = e.alloc(0x20, 4)
    e.w32(lst, base)
    e.w32(lst + 4, 0)
    e.w32(lst + 8, 2)
    return lst


def _nz(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x1000, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x1000)))
    t = e.alloc(0x1000, 16)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x1000)))
    e.w32(self_ + 0x1c, t)
    obj = e.alloc(0x40, 4)
    e.w32(obj + 4, _list(c, e))
    return [self_, obj]


def _init(c):
    e, r = c.emu, c.rng

    def callee(em, rr):
        em.calllog.append(('5e0e10', em.reg('ecx') & 0xffffffff, em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)

    _stub_addr(c, 0x5e0e10, 'callee_5e0e10', callee)
    self_ = e.alloc(0x600, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x600)))
    return [self_, r.getrandbits(32), r.getrandbits(32)]


S(0x594ed0, 'set or clear bit 0x400 of [this+0x417] unless bits 25..27 are set (name GUESS)', 'thiscall', None,
  gen=_flag, note='batch4019')
S(0x55ce90, 'byte at [[this+0x1c]+0x920] from element 0 of [obj+4] (name GUESS)', 'thiscall', None, gen=_nz,
  note='batch4019')
S(0x5e1190, 'initialiser: 0x5e0e10 then vtable 0x6b78f8 (name GUESS)', 'thiscall', None, ret='eax', gen=_init,
  note='batch4019')
