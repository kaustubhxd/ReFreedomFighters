"""specs_s1151.py - collision thread batch 1151 (GUESS name): 0x4e3c20, ZOctreeCompiled::CheckPoint. this holds the scale and the
origin (+4, +8, +0xc), the scale at +0x10 and a pointer at +0x14 to a block whose first dword is a small offset. The out record
is 0x60 bytes. The callee 0x4e3ae0 (batch 239) is stubbed BY ADDRESS (GUESS): it records its node and stack words and pops 0x10; its body is not verified here."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _cp(c):
    e, r = c.emu, c.rng

    def walk(em, rr):                       # GUESS stub for 0x4e3ae0 (records node and its stack words; pops 0x10)
        em.calllog.append(('4e3ae0', em.reg('ecx') & 0xffffffff, tuple(em.arg32(i) for i in range(4))))
        em.ret(argbytes=0x10)
    _stub_addr(c, 0x4e3ae0, 'walk_4e3ae0', walk)
    blk = e.alloc(0x200, 16)
    e.wbytes(blk, bytes(r.getrandbits(8) for _ in range(0x200)))
    e.w32(blk, r.randrange(0, 0x40))          # a small first dword (the offset added in out+0x10)
    self_ = e.alloc(0x40, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.wf32(self_ + 4, r.uniform(-50, 50))
    e.wf32(self_ + 8, r.uniform(-50, 50))
    e.wf32(self_ + 0xc, r.uniform(-50, 50))
    e.wf32(self_ + 0x10, r.uniform(0.001, 0.05))
    e.w32(self_ + 0x14, blk)
    out = e.alloc(0x60, 16)
    e.wbytes(out, bytes(r.getrandbits(8) for _ in range(0x60)))
    v = e.alloc(0x10, 4)
    for i in range(3):
        e.wf32(v + 4 * i, r.uniform(-200, 200))
    return [self_, out, v]


S(0x4e3c20, 'octree CheckPoint: scaled and offset coordinates into out, pointers, then the cell traverse (name GUESS)', 'thiscall',
  None, ret=None, gen=_cp, note='batch1151')
