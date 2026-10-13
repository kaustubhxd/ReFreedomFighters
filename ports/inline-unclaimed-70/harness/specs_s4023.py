"""specs_s4023.py - area 70 batch 4023: 0x4a0150 (GUESS name). Exe callee 0x4a0e40 is stubbed BY ADDRESS: it returns a per-case
position in [1, 15] (records ECX and its argument). The arrays are small so every index stays in range."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _move(c):
    e, r = c.emu, c.rng
    b = r.randrange(1, 16)

    def callee(em, rr):
        em.calllog.append(('4a0e40', em.reg('ecx') & 0xffffffff, em.arg32(0)))
        em.ret(eax=b, argbytes=4)

    _stub_addr(c, 0x4a0e40, 'callee_4a0e40', callee)
    o = e.alloc(0xa00, 16)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0xa00)))
    for k in range(0, 16):
        e.w32(o + 4 + 4 * k, r.randrange(0, 16))          # values: small positions
        e.w32(o + 0x804 + 4 * k, r.randrange(0, 16) if r.random() < 0.5 else r.randrange(1, 4))
    for k in range(16):
        if r.random() < 0.5:
            e.w32(o + 0x804 + 4 * k, e.r32(o + 0x804 + 4 * b))   # equal counts for the decrement loop
    return [o, r.randrange(0, 16)]


S(0x4a0150, 'move a list entry to the front and drop one count (name GUESS)', 'thiscall', None, gen=_move, note='batch4023')
