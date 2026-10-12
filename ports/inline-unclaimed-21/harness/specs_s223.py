"""specs_s223.py - core residue 5: ZFFWindowCoordinator::StartPressed (batch223). The six helpers are stubs that store
their register arguments (or their result byte); the two render-manager vtable slots log their argument."""
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


def _fast_store(c):
    """fastcall (ecx, edx): stores both; returns (no result)."""
    a, b = _cell(c), _cell(c)
    return ss.code(c, b'\x89\x0d' + struct.pack('<I', a) + b'\x89\x15' + struct.pack('<I', b) + b'\xc3')


def _fast_log2(c):
    """fastcall (ecx, edx) for a helper called twice: appends (ecx, edx) to a two-entry log."""
    log = c.emu.alloc(16, 4)
    c.emu.wbytes(log, bytes(16))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, log)
    return ss.code(c, b'\xa1' + struct.pack('<I', ptr)                    # mov eax, [ptr]
                   + b'\x89\x08' + b'\x89\x50\x04'                       # mov [eax], ecx; mov [eax+4], edx
                   + b'\x83\x05' + struct.pack('<I', ptr) + b'\x08'         # add dword [ptr], 8
                   + b'\xc3')


def _this_store(c, ret_al=None):
    """thiscall (ecx): stores ecx; optionally returns al."""
    a = _cell(c)
    body = b'\x89\x0d' + struct.pack('<I', a)
    if ret_al is not None:
        body += b'\xb0' + bytes([ret_al])
    return ss.code(c, body + b'\xc3')


def _dispatch_obj(c):
    self_ = _rnd(c, 0x40)
    if c.rng.random() < 0.6:
        c.emu.wbytes(self_, b'\x00')
    if c.rng.random() < 0.6:
        c.emu.wbytes(self_ + 1, b'\x00')
    c.emu.wbytes(self_ + 2, bytes([c.rng.choice([0, 1])]))
    ecx = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32)
    c.emu.w32(self_ + 3, ecx)
    if c.rng.random() < 0.4:
        c.emu.w32(self_ + 0x13, ecx)
    if c.rng.random() < 0.2:
        c.emu.w32(self_ + 0xb, ecx)
    # helpers (exe addresses)
    ss.patch(c, 0x5f0db0, _fast_log2(c))   # called twice per run: a two-entry log keeps both arguments
    ss.patch(c, 0x5f0d80, _fast_store(c))
    ss.patch(c, 0x5f0cd0, _fast_store(c))
    ss.patch(c, 0x5f0d30, _this_store(c))
    ss.patch(c, 0x5f0ff0, _this_store(c, ret_al=c.rng.choice([0, 1])))
    ss.patch(c, 0x5f0c70, _this_store(c, ret_al=c.rng.choice([0, 1])))
    # render-manager objects: rm -> +0x9b (vt 0xb4 and 0x138 log), rm -> +0x1a9f (0 or an object with vt 0x138)
    rm = _rnd(c, 0x1b00)
    o1 = ss.mkobj(c, {0xb4: ss.rec(c, 1, ret=0, log=True)}, size=0x40)
    c.emu.w32(rm + 0x9b, o1)
    if c.rng.random() < 0.7:
        o2 = ss.mkobj(c, {0x138: ss.rec(c, 1, ret=0, log=True)}, size=0x40)
        c.emu.w32(rm + 0x1a9f, o2)
    else:
        c.emu.w32(rm + 0x1a9f, 0)
    c.emu.w32(0x70039c, rm)
    # global 0x7003b8 -> g; g+0x2c15 -> h; h+0x103f is the flag byte
    h = _rnd(c, 0x1050)
    c.emu.wbytes(h + 0x103f, bytes([c.rng.choice([0, 1])]))
    g = _rnd(c, 0x2c20)
    c.emu.w32(g + 0x2c15, h)
    c.emu.w32(0x7003b8, g)
    _flush(c)
    return [self_, c.rng.getrandbits(32)]


S(0x5f0e10, 'StartPressed (map name)', 'thiscall', None, ret=None, gen=_dispatch_obj,
  note='batch223; flag dispatch with six helpers stubbed and two render-manager vtable calls')
