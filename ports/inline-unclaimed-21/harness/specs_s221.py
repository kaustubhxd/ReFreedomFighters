"""specs_s221.py - core residue 0: 0x584580 (batch221). The original 0x4301c0 (stdcall, the buffer-grow path) is stubbed:
it logs its two words. The render-manager child and the list global are set up per run."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _init_obj(c):
    self_ = _rnd(c, 0x100)
    c.emu.wbytes(self_ + 0x63, bytes([c.rng.choice([0, 1])]))
    c.emu.wbytes(self_ + 0x56, bytes([c.rng.choice([0, 1])]))
    o = ss.mkobj(c, {0xbc: ss.rec(c, 1, ret=0, log=True)}, size=0x40)
    c.emu.w32(self_ + 0x44, o)
    # the list global: cnt in [0, 3], and the buffer pointers at ctr = list + 0x4a0
    lst = _rnd(c, 0x1000)
    c.emu.w32(lst + 0xb61, c.rng.choice([0, 1, 2]))
    buf = _rnd(c, 0x40)
    c.emu.w32(lst + 0x4a0 + 4, buf)
    c.emu.w32(lst + 0x4a0 + 8, buf if c.rng.random() < 0.3 else buf + 0x20)
    c.emu.w32(0x7003b8, lst)
    # the render-manager child: vt[0x4c] returns v (logs its argument)
    v = c.rng.getrandbits(32)
    child = ss.mkobj(c, {0x4c: ss.rec(c, 1, ret=v, log=True)}, size=0x40)
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, child)
    c.emu.w32(0x70039c, rm)
    # 0x4301c0 (stdcall): stores the buffer pointer word and the local's value in cells
    cell_p, cell_v = _cell(c), _cell(c)
    ss.patch(c, 0x4301c0, ss.code(c, b'\x8b\x44\x24\x04' + b'\xa3' + struct.pack('<I', cell_p)
                                  + b'\x8b\x44\x24\x08' + b'\x8b\x00' + b'\xa3' + struct.pack('<I', cell_v)
                                  + b'\xc2\x08\x00'))
    _flush(c)
    return [self_]


def _cell(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


S(0x584580, 'hitpointInit (GUESS)', 'thiscall', None, ret=None, gen=_init_obj,
  note='batch221; list append, vt 0x4c result into buffer or 0x4301c0 grow, vt 0xbc when [this+0x56]')
