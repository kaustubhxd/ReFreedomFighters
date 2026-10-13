"""specs_s798.py - unclaimed-77 claims 39 to 43 (docs/20-unclaimed-77.md), residue 4.
Functions: 0x4b0a40 (CCutSequenceSoundInRoot::Run), 0x48f700 (ZEngineDataBase::DumpUsedResources),
0x565080 (CFileWindow::ResetMessageTime), 0x4cc600 (QSortAlphaCompare), 0x564680 (CFileWindow::ConstructControlPrompt).
Stubs: 0x4cc400 (comparison helper called by QSortAlphaCompare, replaced by logger that returns 0/1/-1).
"""
from pilot import S
import struct
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _logger(c, ret, pop, args=2):
    """Stub that logs ecx and the first two stack dwords into a 16-entry-per-8 ring (heap, so the memory compare sees
    them), returns ret in eax, and pops `pop` bytes."""
    import struct
    P = lambda v: struct.pack('<I', v)
    cnt = c.emu.alloc(4, 4); c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4); c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + P(ring) + b'\x89\x08'
         + ((b'\x8b\x54\x24\x04\x89\x50\x04' if args >= 1 else b'') + (b'\x8b\x54\x24\x08\x89\x50\x08' if args >= 2 else b'')) + b'\xff\x05' + P(cnt)
         + b'\xb8' + P(ret) + (b'\xc3' if pop == 0 else b'\xc2' + struct.pack('<H', pop)))
    return ss.code(c, b)


def _gen_4b0a40(c):
    # g_pSysInterface (0x70039c) -> random object; the unaligned dword at +0x1a9f is 0 (1 in 4) or an object whose
    # vtable slot 0xc4 logs ecx and returns 0 or a buffer (byte +0x1209 is 0 half the time).
    si = _rnd(c, 0x1b00)
    c.emu.w32(0x70039c, si)
    r = c.rng.getrandbits(8)
    o = 0
    if r & 3:
        buf = _rnd(c, 0x1300)
        if r & 4:
            c.emu.wbytes(buf + 0x1209, b'\x00')
        o = ss.mkobj(c, {0xc4: _logger(c, buf if r & 8 else 0, 0, args=0)})
    c.emu.wbytes(si + 0x1a9f, struct.pack('<I', o))
    return [ss.mkobj(c, {}, size=0x40), _rnd(c, 0x20), _rnd(c, 0x20)]


def _gen_48f700(c):
    # [0x700390] = db whose slot 0x20 logs (ecx, 2 args) and returns o (pops 8); o's slot 0x2c logs (ecx, 2 args), cdecl.
    o = ss.mkobj(c, {0x2c: _logger(c, 0, 0)})
    db = ss.mkobj(c, {0x20: _logger(c, o, 8)})
    c.emu.w32(0x700390, db)
    return []


def _fl(c):
    r = c.rng.getrandbits(8)
    if r < 100:
        return c.rng.uniform(-3000.0, 3000.0)
    if r < 160:
        return c.rng.uniform(-1e9, 1e9)
    if r < 180:
        return float(c.rng.choice([0.0, -0.0, 1e30, -1e30, 3.4e38, 1e-40]))
    return struct.unpack('<f', struct.pack('<I', c.rng.getrandbits(32)))[0]


def _gen_565080(c):
    # self random 0xd00 object with a float at +0xcaa; g_pSysInterface (0x70039c) random 0x2000 object (dword +0x30 read)
    si = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, si)
    if c.rng.getrandbits(1):
        c.emu.wbytes(si + 0x30, struct.pack('<i', c.rng.randint(-100000, 100000)))
    o = ss.mkobj(c, {}, size=0xd00)
    c.emu.wbytes(o + 0xcaa, struct.pack('<f', _fl(c)))
    return [o]


def _cmp_stub(c):
    """Register helper stand-in (ecx, edx): logs both into an 8-entry ring, returns the next of eight eax values
    (some with al = 0 but eax nonzero, so al versus eax shows)."""
    import struct
    P = lambda v: struct.pack('<I', v)
    cnt = c.emu.alloc(4, 4); c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4); c.emu.wbytes(ring, bytes(64))
    tab = c.emu.alloc(32, 4)
    c.emu.wbytes(tab, b''.join(P(v) for v in [0, 1, 0x100, 0x101, 0xff, 0x80, 0, 2]))
    b = (b'\xa1' + P(cnt) + b'\x83\xe0\x07' + b'\x8d\x04\xc5' + P(ring) + b'\x89\x08\x89\x50\x04'
         + b'\xa1' + P(cnt) + b'\x83\xe0\x07\x8b\x04\x85' + P(tab) + b'\xff\x05' + P(cnt) + b'\xc3')
    return ss.code(c, b)


def _gen_4cc600(c):
    # QSortAlphaCompare(const void*, const void*) - cdecl; each argument points at a dword (an element pointer).
    ss.patch(c, 0x4cc400, _cmp_stub(c))
    p1 = c.emu.alloc(4, 4); c.emu.w32(p1, c.rng.getrandbits(32))
    p2 = c.emu.alloc(4, 4); c.emu.w32(p2, c.rng.getrandbits(32))
    return [p1, p2]


def _gen_564680(c):
    # self: 0xcb0-byte object, vtable slot 0xc8 logs (ecx, arg) and pops 4; 0x561e80 patched with the same logger.
    ss.patch(c, 0x561e80, _logger(c, 0, 4, args=1))
    o = ss.mkobj(c, {0xc8: _logger(c, 0, 4, args=1)}, size=0xcb0)
    r = c.rng.getrandbits(8)
    c.emu.w32(o + 0xc9a, 10 if r & 3 else c.rng.getrandbits(32))
    c.emu.wbytes(o + 0x18a, bytes([0 if r & 4 else c.rng.getrandbits(8) | 1]))
    return [o, c.rng.getrandbits(32)]


S(0x4b0a40, 'CCutSequenceSoundInRoot::Run (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4b0a40,
  note='unclaimed-77 claim 39; CCutSequenceSoundInRoot::Run(REFTAB*, REFTAB*); ret 8')
S(0x48f700, 'ZEngineDataBase::DumpUsedResources (unknown) static', 'cdecl', None, ret=None, gen=_gen_48f700,
  note='unclaimed-77 claim 40; ZEngineDataBase::DumpUsedResources(); static function')
S(0x565080, 'CFileWindow::ResetMessageTime (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_565080,
  note='unclaimed-77 claim 41; CFileWindow::ResetMessageTime(); SSE float math')
S(0x4cc600, 'QSortAlphaCompare (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen_4cc600,
  note='unclaimed-77 claim 42; QSortAlphaCompare(const void*, const void*); returns int')
S(0x564680, 'CFileWindow::ConstructControlPrompt (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_564680,
  note='unclaimed-77 claim 43; CFileWindow::ConstructControlPrompt(char*); returns u32')
