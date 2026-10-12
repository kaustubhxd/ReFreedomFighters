"""specs_s218.py - unclaimed area 21: 0x558c00 (batch218). Stack pointers are never logged; only heap values and constants.
The original 0x4de7a0 (writes a stack block only) is stubbed as a no-op."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _vec_obj(c):
    p = _rnd(c, 0x40)
    q = _rnd(c, 0x40)
    c.emu.w32(p + 4, q)
    # 0x5003d0 (ecx = q, one stack word 0): stores ecx and the word, returns t (a heap block with a random dword)
    t = _rnd(c, 0x40)
    c_q, c_z = _cell(c), _cell(c)
    look = ss.code(c, b'\x89\x0d' + struct.pack('<I', c_q)                 # mov [c_q], ecx
                   + b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', c_z)   # mov edx, [esp+4]; mov [c_z], edx
                   + b'\xb8' + struct.pack('<I', t) + b'\xc2\x04\x00')    # mov eax, t; ret 4
    ss.patch(c, 0x5003d0, look)
    ss.patch(c, 0x4de7a0, ss.code(c, b'\xc3'))   # no-op: it only fills a stack block (its ecx is a stack address)
    # child: 0x58 logs its arg and returns x; x has 0x84 that logs the content of its pointer argument
    x_cell = [_cell(c), _cell(c)]
    x = ss.mkobj(c, {0x84: ss.code(c, b'\x89\x0d' + struct.pack('<I', x_cell[1])          # mov [x_cell1], ecx (the object)
                                   + b'\x8b\x54\x24\x04' + b'\x8b\x0a' + b'\x89\x0d' + struct.pack('<I', x_cell[0])
                                   + b'\xc2\x04\x00')}, size=0x40)
    child = ss.mkobj(c, {0x58: ss.rec(c, 1, ret=x, log=True)}, size=0xae0)
    y = [_cell(c) for _ in range(5)]      # [p2], [p3], p4, p5, [p3+8]
    obj2 = ss.mkobj(c, {0x238: ss.code(c, b'\x8b\x54\x24\x08' + b'\x8b\x0a' + b'\x89\x0d' + struct.pack('<I', y[0])   # [p2]
                                       + b'\x8b\x54\x24\x0c' + b'\x8b\x0a' + b'\x89\x0d' + struct.pack('<I', y[1])   # [p3]
                                       + b'\x8b\x54\x24\x10' + b'\x89\x15' + struct.pack('<I', y[2])                  # p4
                                       + b'\x8b\x54\x24\x14' + b'\x89\x15' + struct.pack('<I', y[3])                  # p5
                                       + b'\x8b\x54\x24\x0c' + b'\x8b\x4a\x08' + b'\x89\x0d' + struct.pack('<I', y[4])   # [p3+8]
                                       + b'\xc2\x14\x00')}, size=0x40)
    c.emu.w32(child + 0xadc, obj2)
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, child)
    c.emu.w32(0x70039c, rm)
    _flush(c)
    return [p]


S(0x558c00, 'vecLookup (GUESS)', 'stdcall', None, ret=None, gen=_vec_obj,
  note='batch218; 0x5003d0 lookup, child vtable 0x58 and 0x84, original 0x4de7a0 (stack block), vtable 0x238 with five words')
