"""specs_s1152.py - collision thread batch 1152 (GUESS name): 0x4edb80, the buffer install. The allocator 0x41e290 is stubbed BY
ADDRESS (cdecl; returns successive 0x40-byte blocks from an arena, logs its size). The Init callee 0x4e3d60 runs as exe code on the
block (batch 1150's port exists). A count of -1 returns at once (about one case in five)."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _inst(c):
    e, r = c.emu, c.rng
    arena = e.alloc(0x400, 16)
    e.wbytes(arena, bytes(0x400))
    k = [0]

    def alloc(em, rr):
        em.calllog.append(('41e290', em.arg32(0)))
        ptr = arena + 0x40 * k[0]
        k[0] += 1
        em.ret(eax=ptr, argbytes=0)                # cdecl: the caller cleans the argument
    _stub_addr(c, 0x41e290, 'alloc_41e290_4edb80', alloc)
    self_ = e.alloc(0x200, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
    X = e.alloc(0x20, 16)
    e.wbytes(X, bytes(r.getrandbits(8) for _ in range(0x20)))
    for i in range(3):
        e.wf32(X + 4 + 4 * i, r.uniform(-100, 100))
    count = 0xffffffff if r.random() < 0.2 else r.getrandbits(32)
    return [self_, X, count]


S(0x4edb80, 'install a collision buffer: allocate 0x18 bytes, vtable, Init (name GUESS)', 'thiscall', None, ret=None,
  gen=_inst, note='batch1152')
