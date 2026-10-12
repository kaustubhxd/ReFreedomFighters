"""specs_s240.py - batch240 (0x5ebf10). The allocator 0x41e290 (cdecl) is hooked by address with a bump allocator (distinct
64-byte blocks in a pool, the same addresses in both runs). B's vtable: 0x74, 0x6c, 0x68, 0x48 log ecx and one word (ring);
0x18 logs ecx and both words (ring, two stack words); 0x40 (one out pointer) writes table[k] through the pointer, k the call
index (10 calls per run; table[9] is the loop count, a spec input 0..3). ext 0x5fe3b0 logs ecx and its first word only (the
second word is a stack address)."""
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


def _ring(c, nwords, ret_bytes):
    n = 1 + nwords
    ring = c.emu.alloc(4 * n * 16, 4)
    c.emu.wbytes(ring, bytes(4 * n * 16))
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, ring)
    body = b'\xa1' + struct.pack('<I', ptr) + b'\x89\x08'
    for k in range(nwords):
        body += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x50' + bytes([4 * (k + 1)])
    body += b'\x83\x05' + struct.pack('<I', ptr) + bytes([4 * n])
    return ss.code(c, body + b'\xc2' + struct.pack('<H', ret_bytes))


def _out_table(c, table):
    cnt = _cell(c)
    tbl = c.emu.alloc(4 * len(table), 4)
    for k, v in enumerate(table):
        c.emu.w32(tbl + 4 * k, v)
    return ss.code(c, b'\x8b\x0d' + struct.pack('<I', cnt)            # mov ecx, [cnt]
                   + b'\x8b\x04\x8d' + struct.pack('<I', tbl)         # mov eax, [ecx*4 + tbl]
                   + b'\x8b\x54\x24\x04' + b'\x89\x02'                # mov edx, [esp+4]; mov [edx], eax
                   + b'\x83\x05' + struct.pack('<I', cnt) + b'\x01'   # add dword [cnt], 1
                   + b'\xc2\x04\x00')


def _alloc_stub(c, pool):
    """cdecl allocator (caller pops): logs its size in a ring of 8 words, returns a fresh 64-byte block from the pool."""
    ptr = c.emu.alloc(4, 4)
    c.emu.w32(ptr, pool)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    lp = c.emu.alloc(4, 4)
    c.emu.w32(lp, ring)
    return ss.code(c, b'\x8b\x15' + struct.pack('<I', lp)                     # mov edx, [lp]
                   + b'\x8b\x4c\x24\x04' + b'\x89\x0a'                      # mov ecx, [esp+4]; mov [edx], ecx
                   + b'\x83\x05' + struct.pack('<I', lp) + b'\x04'            # add dword [lp], 4
                   + b'\xa1' + struct.pack('<I', ptr)                          # mov eax, [ptr]
                   + b'\x83\x05' + struct.pack('<I', ptr) + b'\x40'           # add dword [ptr], 0x40
                   + b'\xc3')


def _gen(c):
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x3e, c.rng.randrange(0, 4))
    Sobj = _rnd(c, 0x20)
    c.emu.w32(self_ + 0x3a, Sobj)
    lst = _rnd(c, 0x20)
    c.emu.w32(self_ + 0x66, lst)
    c.emu.w32(self_ + 0x6a, lst + 4 * c.rng.randrange(0, 4))
    pool = c.emu.alloc(0x400, 4)
    c.emu.wbytes(pool, bytes(0x400))
    ss.patch(c, 0x41e290, _alloc_stub(c, pool))
    count = c.rng.randrange(0, 4)
    table = [c.rng.getrandbits(32) for _ in range(9)] + [count]
    ring1 = lambda: _ring(c, 1, 4)
    B = ss.mkobj(c, {0x74: ring1(), 0x6c: ring1(), 0x68: ring1(), 0x48: ring1(),
                     0x40: _out_table(c, table), 0x18: _ring(c, 2, 8)}, size=0x40)
    cc, cp = _cell(c), _cell(c)
    ss.patch(c, 0x5fe3b0, ss.code(c, b'\x89\x0d' + struct.pack('<I', cc) + b'\x8b\x54\x24\x04'
                                  + b'\x89\x15' + struct.pack('<I', cp) + b'\xc2\x08\x00'))
    _flush(c)
    return [self_, B]


S(0x5ebf10, 'vecSerialize5ebf (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch240; mirror of 0x5ec190: vt calls writing this, allocator hooked, loop over count from a spec input')
