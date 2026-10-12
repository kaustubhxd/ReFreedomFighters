"""specs_s212.py - unclaimed area 21 (docs/20-unclaimed-21.md): 0x4dc9c0 and 0x5922c0 (batch212).

The render-manager child (global 0x70039c -> +0x9b -> +8) and this-object vtables are raw stubs (see specs_s210.py).
"""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _buf(c, n=0x40):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a + 0x10


def _cell(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _stub_ret_arg_cell_val(c, cell, val):
    """thiscall slot with one stack word (ret 4): stores the word in cell, returns val in eax."""
    return ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x15' + struct.pack('<I', cell)
                   + b'\xb8' + struct.pack('<I', val & 0xffffffff) + b'\xc2\x04\x00')


def _stub_log_seq(c, val, n=4):
    """thiscall slot with one stack word (ret 4): appends the word to a log of n words (ptr walks it), returns val."""
    log = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(log, bytes(4 * n))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, log)
    return ss.code(c, b'\xa1' + struct.pack('<I', ptr)                      # mov eax, [ptr]
                   + b'\x8b\x54\x24\x04'                                  # mov edx, [esp+4]
                   + b'\x89\x10'                                           # mov [eax], edx
                   + b'\x83\x05' + struct.pack('<I', ptr) + b'\x04'        # add dword [ptr], 4
                   + b'\xb8' + struct.pack('<I', val & 0xffffffff) + b'\xc2\x04\x00')


def _stub_ret_val(c, val):
    """thiscall slot with no argument: returns val in eax."""
    return ss.code(c, b'\xb8' + struct.pack('<I', val & 0xffffffff) + b'\xc3')


def _stub_ret_val_arg(c, val):
    """thiscall slot with one stack word (ret 4): returns val in eax."""
    return ss.code(c, b'\xb8' + struct.pack('<I', val & 0xffffffff) + b'\xc2\x04\x00')


def _stub_log_arg2(c, val):
    """thiscall slot with two stack words (ret 8): stores the second word (the value) in a cell, returns val."""
    cell = c.emu.alloc(4, 4)
    c.emu.w32(cell, 0)
    return ss.code(c, b'\x8b\x54\x24\x08' + b'\x89\x15' + struct.pack('<I', cell)
                   + b'\xb8' + struct.pack('<I', val & 0xffffffff) + b'\xc2\x08\x00')


def _stub_ret_none(c):
    """thiscall slot with one stack word (ret 4) and no result."""
    return ss.code(c, b'\xc2\x04\x00')


def _rm_child(c, obj):
    """Sets global 0x70039c -> rm, rm+0x9b -> a, a+8 -> obj (the child used by both functions)."""
    rm = _rnd(c, 0x100)
    a = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, a)
    c.emu.w32(a + 8, obj)
    c.emu.w32(0x70039c, rm)


def _pair_obj(c):
    self_ = _rnd(c, 0x80)
    f = c.rng.getrandbits(32)
    if c.rng.random() < 0.7:
        f |= 0x40000 | 0x4000
        if c.rng.random() < 0.8:
            f &= ~0x200c00
    c.emu.w32(self_ + 0x3c, f)
    w = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(16)
    c.emu.wbytes(self_ + 0x5c, struct.pack('<H', w))
    # child: slot 0x5c returns the value V (logs its word argument), slot 0x50 returns X
    ret5c = _buf(c) if c.rng.random() < 0.6 else 0
    x = c.rng.getrandbits(32)
    v58 = c.rng.getrandbits(32)                 # 0x4dce70 (exe code) calls child->vt[0x58](child, w) and stores the low word
    obj = ss.mkobj(c, {0x5c: _stub_log_seq(c, ret5c, n=2), 0x50: _stub_ret_val(c, x), 0x58: ss.rec(c, 1, ret=v58, log=True)}, size=0x40)
    _rm_child(c, obj)
    _flush(c)
    return [self_, c.rng.getrandbits(32)]


def _call_obj(c):
    arg = c.rng.getrandbits(32)
    o = ss.mkobj(c, {0x1e0: ss.rec(c, 1, ret=1 if c.rng.random() < 0.6 else 0, log=True),
                     0x34c: ss.rec(c, 1, ret=0, log=True)}, size=0x40)
    r = o if c.rng.random() < 0.8 else 0
    v3 = c.rng.getrandbits(32)
    slots = {
        0x504: _stub_ret_val(c, r),                                           # returns o (or 0)
        0x3a0: _stub_log_arg2(c, v3),                                          # ret 8: logs arg2, returns v3
        0x390: ss.rec(c, 1, ret=0, log=True),
        0x84: ss.rec(c, 1, ret=0, log=True),
    }
    self_ = ss.mkobj(c, slots, size=0x80)   # this
    _flush(c)
    return [self_, arg]


S(0x4dc9c0, 'pairStore (GUESS)', 'thiscall', None, ret=None, gen=_pair_obj,
  note='batch212; flag gate, child vtable 0x5c and 0x50, original 0x4dce70 call, store at base+0x18 or 0x18')
S(0x5922c0, 'callIfOk (GUESS)', 'thiscall', None, ret=None, gen=_call_obj,
  note='batch212; vtable 0x504, then 0x1e0 (bool) and 0x34c')
