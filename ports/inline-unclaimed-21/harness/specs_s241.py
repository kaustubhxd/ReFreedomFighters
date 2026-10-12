"""specs_s241.py - batch241 (0x437b00). SEH not reproduced. Hooks by address: the allocator 0x41e290 (cdecl bump pool with a
size ring), 0x4ccbe0 (thiscall, ecx and two words, ret 8: logs them, returns RkObj), 0x4382e0 (thiscall, ecx: logs, returns R).
Objects: P (vt 0x64: logs ecx and its argument, returns idx), Bk / RkObj (vt 4: logs, returns a Q block with Q-4 writable), the
base object (tag 3 at +4) with P at +0x11, a table T at P+0x1344 (10-byte entries)."""
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


def _ring_val(c, nwords, ret_bytes, val):
    """thiscall with nwords stack words: logs ecx and the words to a ring of 8; returns val."""
    n = 1 + nwords
    ring = c.emu.alloc(4 * n * 8, 4)
    c.emu.wbytes(ring, bytes(4 * n * 8))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
    for k in range(nwords):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x50' + bytes([4 * (k + 1)])
    body += b'\x83\x05' + struct.pack('<I', ptr) + bytes([4 * n])
    body += b'\xb8' + struct.pack('<I', val & 0xffffffff)
    return ss.code(c, body + b'\xc2' + struct.pack('<H', ret_bytes))


def _alloc_hook(c, pool):
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, pool)
    ring = c.emu.alloc(16, 4)
    c.emu.wbytes(ring, bytes(16))
    lp = c.emu.alloc(4, 4)
    c.emu.w32(lp, ring)
    return ss.code(c, b'\x8b\x15' + struct.pack('<I', lp) + b'\x8b\x4c\x24\x04' + b'\x89\x0a'
                   + b'\x83\x05' + struct.pack('<I', lp) + b'\x04'
                   + b'\xa1' + struct.pack('<I', ptr) + b'\x83\x05' + struct.pack('<I', ptr) + b'\x40' + b'\xc3')


def _q_obj(c):
    buf = _rnd(c, 0x40)
    Q = buf + 8
    return ss.mkobj(c, {4: _ring_val(c, 1, 4, Q)}, size=0x40)


def _gen(c):
    self_ = _rnd(c, 0x100)
    base = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        M = base + 4
        c.emu.w32(M, 3)                               # tag 3: base = M - 4
    else:
        M = _rnd(c, 0x40)                             # tag 1: base = [M+8] - 4
        c.emu.w32(M, 1)
        c.emu.w32(M + 8, base + 4)
    c.emu.w32(self_ + 8, M)
    idx = c.rng.randrange(0, 4)
    P = _rnd(c, 0x1400)
    c.emu.w32(base + 0x11, P)
    c.emu.w32(P + 0x1210, c.rng.choice([0xffffffff, 0, 1, 2, 3, 5]))
    T = _rnd(c, 0x40)
    c.emu.w32(P + 0x1344, T)
    Pvt = c.emu.alloc(0x80, 4)
    c.emu.w32(Pvt + 0x64, _ring_val(c, 1, 4, idx))   # P->vt[0x64](A) returns idx
    c.emu.w32(P, Pvt)
    bk = _q_obj(c) if c.rng.random() < 0.5 else 0      # [this+0xd]: a block with vt 4, or zero (allocated)
    c.emu.w32(self_ + 0xd, bk)
    rk = _q_obj(c)                                     # what 0x4ccbe0 returns (a block with vt 4)
    pool = c.emu.alloc(0x100, 4)
    c.emu.wbytes(pool, bytes(0x100))
    ss.patch(c, 0x41e290, _alloc_hook(c, pool))
    ss.patch(c, 0x4ccbe0, _ring_val(c, 2, 8, rk))
    R = _rnd(c, 0x20)
    ss.patch(c, 0x4382e0, _ring_val(c, 0, 0, R))
    _flush(c)
    return [self_, c.rng.getrandbits(32)]


S(0x437b00, 'searchAlloc437 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch241; SEH not reproduced; P vt 0x64 index, 0x41e290 allocator, 0x4ccbe0, table entry at T + 10*idx')
