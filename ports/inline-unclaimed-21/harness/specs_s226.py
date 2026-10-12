"""specs_s226.py - small leaves, slices 0/1 (batch226). Callee stubs store their words; 0x5003d0 returns a heap block."""
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


def _lookup_stub(c, buf):
    """0x5003d0 (ecx = a->[4], one stack word): stores ecx and the word, returns buf, ret 4."""
    cp, cz = _cell(c), _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', cp)
                   + b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cz)
                   + b'\xb8' + struct.pack('<I', buf) + b'\xc2\x04\x00')


def _args_obj(c, self_off, obj_size, vt_slots):
    """self with [self_off] -> obj (with the given vtable slots), a with [a+4] -> q and 0x5003d0 returning a block."""
    self_ = _rnd(c, 0x40)
    obj = ss.mkobj(c, vt_slots, size=obj_size)
    c.emu.w32(self_ + self_off, obj)
    a = _rnd(c, 0x40)
    q = _rnd(c, 0x40)
    c.emu.w32(a + 4, q)
    buf = _rnd(c, 0x40)
    ss.patch(c, 0x5003d0, _lookup_stub(c, buf))
    return self_, a, obj, buf


def _stdcall_obj(c):
    cells = [_cell(c) for _ in range(5)]
    body = b''
    for k, cell in enumerate(cells):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x15' + struct.pack('<I', cell)
    ss.patch(c, 0x4d2700, ss.code(c, body + b'\xc2\x14\x00'))
    _flush(c)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _word_obj(c):
    cz = _cell(c)
    obj_cell = _cell(c)
    stub = ss.code(c, b'\x89\x0d' + struct.pack('<I', obj_cell) + b'\x89\x15' + struct.pack('<I', cz) + b'\xc2\x04\x00')
    self_, a, obj, buf = _args_obj(c, 0x1c, 0x900, {0x5a2df0: stub})
    c.emu.w32(buf, c.rng.getrandbits(16))   # the word read through the block
    _flush(c)
    return [self_, a]


def _flag_obj(c):
    self_, a, obj, buf = _args_obj(c, 0x1c, 0x900, {})
    c.emu.w32(buf, c.rng.choice([0, 1, 0xffffffff]))
    _flush(c)
    return [self_, a]


def _float_obj(c):
    obj_cell = _cell(c)
    arg_cell = _cell(c)
    stub = ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', arg_cell) + b'\xc2\x04\x00')
    self_ = _rnd(c, 0x40)
    obj = ss.mkobj(c, {0x318: stub}, size=0x40)
    c.emu.w32(self_ + 0x14, obj)
    a = _rnd(c, 0x40)
    q = _rnd(c, 0x40)
    c.emu.w32(a + 4, q)
    buf = _rnd(c, 0x40)
    ss.patch(c, 0x5003d0, _lookup_stub(c, buf))
    _flush(c)
    return [self_, a]


S(0x4d3a00, 'wrapCall (GUESS)', 'stdcall', None, ret=None, gen=_stdcall_obj, note='batch226; ext 0x4d2700(a, 2, c, b, 0)')
S(0x55c940, 'wordCall (GUESS)', 'thiscall', None, ret=None, gen=_word_obj, note='batch226; 0x5003d0 then 0x5a2df0(obj, word)')
S(0x55ca80, 'flagStore (GUESS)', 'thiscall', None, ret=None, gen=_flag_obj, note='batch226; byte +0x8fa = (dword != 0)')
S(0x519b40, 'floatSlot (GUESS)', 'thiscall', None, ret=None, gen=_float_obj, note='batch226; obj vt 0x318 with a float from 0x5003d0')
