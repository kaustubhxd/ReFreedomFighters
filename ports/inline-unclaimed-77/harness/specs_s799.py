"""specs_s799.py - unclaimed-77 claims 44 to 48 (docs/20-unclaimed-77.md), residue 4.
Functions: 0x41f680 (ZSysMemGC::FlushCache), 0x41f7c0 (ZSysMem::ExgRefs),
0x41fa40 (ZSysMemGC::SubLink), 0x427d80 (ZMovementAnimation::WantControl),
0x43f5c0 (ZGROUP::CalcCenSizeRecur).
"""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_41f680(c):
    # dword at self+0x31 (unaligned) is random; the result is that dword + 0x217
    o = ss.mkobj(c, {}, size=0x100)
    c.emu.wbytes(o + 0x31, bytes(c.rng.getrandbits(8) for _ in range(4)))
    return [o]


def _logger(c, ret, pop, args=0, shared=None, tag=0, logecx=True):
    """Stub that logs ecx (and `args` stack dwords) into a ring on the heap, returns ret, pops `pop` bytes."""
    P = lambda v: struct.pack('<I', v)
    if shared:
        cnt, ring = shared
    else:
        cnt = c.emu.alloc(4, 4); c.emu.w32(cnt, 0)
        ring = c.emu.alloc(128, 4); c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + P(ring) + (b'\x89\x08' if logecx else b'') + b'\xc7\x40\x0c' + P(tag)
         + (b'\x8b\x54\x24\x04\x89\x50\x04' if args >= 1 else b'') + (b'\x8b\x54\x24\x08\x89\x50\x08' if args >= 2 else b'') + b'\xff\x05' + P(cnt)
         + b'\xb8' + P(ret) + (b'\xc3' if pop == 0 else b'\xc2' + struct.pack('<H', pop)))
    return ss.code(c, b)


def _gen_41f7c0(c):
    # slots 0xec and 0xe8 log ecx (order is visible in a shared ring? no: separate rings, each logs this); 0x41ee20 logs
    # (ecx, arg) and returns a random dword.
    cnt = c.emu.alloc(4, 4); c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4); c.emu.wbytes(ring, bytes(128))
    sh = (cnt, ring)          # one shared ring, tagged per stub, so the call order is compared too
    ss.patch(c, 0x41ee20, _logger(c, c.rng.getrandbits(32), 4, args=1, shared=sh, tag=0x11))
    o = ss.mkobj(c, {0xec: _logger(c, 0, 0, shared=sh, tag=0x22), 0xe8: _logger(c, 0, 0, shared=sh, tag=0x33)}, size=0x100)
    return [o, c.rng.getrandbits(32)]


def _gen_41fa40(c):
    cnt = c.emu.alloc(4, 4); c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4); c.emu.wbytes(ring, bytes(128))
    sh = (cnt, ring)
    rng = c.rng
    r = rng.getrandbits(16)
    blk = _rnd(c, 0x400)
    lim = blk + 0x40
    k = rng.choice([0, 0, 4, 0x10, 0x20, 0x40, 0x80])
    size = rng.choice([k, k + 1, k + 4, k + 0x40, 0x10, 0x100, 0])
    mode = r % 4
    if mode == 0:       # p inside or at the edge of [lim, lim+size)
        p = lim + k
    elif mode == 1:     # p below lim
        p = lim - 0x20
    elif mode == 2:     # p above the end (or at it)
        p = lim + size + rng.choice([0, 4, 0x10])
        p = min(p, blk + 0x3f0)
    else:               # lim is zero: the range test is skipped
        p = blk + 0x100
        lim = 0
    c.emu.wbytes(lim - 8 if lim else blk, struct.pack('<I', (size | (rng.getrandbits(4) << 28)) & 0xffffffff)) if lim else None
    cnt_vals = [0, 1, 1, 2, -1 & 0xffffffff, 0x80000000, 0x7fffffff, 0xfffffffe]
    c.emu.wbytes(p - 0xc, struct.pack('<I', rng.choice(cnt_vals) if (r >> 2) & 3 else 1))
    rec = _rnd(c, 0x1d00)
    c.emu.wbytes(rec + 0x1c5d, struct.pack('<I', lim))
    si = _rnd(c, 0x100)
    c.emu.w32(0x70039c, si)
    c.emu.wbytes(si + 0x9b, struct.pack('<I', rec if (r >> 4) & 7 else 0))
    e = ss.mkobj(c, {0x20: _logger(c, 1 if (r >> 7) & 3 == 0 else 0, 4, args=1, shared=sh, tag=0x11)}, size=0x40)
    c.emu.w32(0x70038c, e)
    db = ss.mkobj(c, {0x34: _logger(c, 0, 0, args=2, shared=sh, tag=0x22)}, size=0x40)
    c.emu.w32(0x700390, db)
    c.emu.w32(0x7003b0, _logger(c, 0, 0, shared=sh, tag=0x33, logecx=False))
    ss.patch(c, 0x41f190, _logger(c, 0, 4, args=1, shared=sh, tag=0x44))
    return [ss.mkobj(c, {}, size=0x40), p]


def _gen_427d80(c):
    # three float* arguments, all ignored (the function is `xor al,al; ret 0xc`)
    return [ss.mkobj(c, {}, size=0x100), _rnd(c, 12), _rnd(c, 12), _rnd(c, 12)]


def _gen_43f5c0(c):
    # list of 0..4 nodes (0x70 bytes; +0x54 object or 0, +0x60 next); an object has +0xc -> a record whose dword at +0x23
    # holds (or not) the 0x100000 bit; vtable slot 0x2b8, node call 0x4da1d0 and slot 0 of self all log into one ring.
    cnt = c.emu.alloc(4, 4); c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4); c.emu.wbytes(ring, bytes(128))
    sh = (cnt, ring)
    ss.patch(c, 0x4da1d0, _logger(c, 0, 4, args=1, shared=sh, tag=0x11))
    nxt = 0
    for _ in range(c.rng.randint(0, 4)):
        n = _rnd(c, 0x70)
        o = 0
        if c.rng.getrandbits(2):
            o = ss.mkobj(c, {0x2b8: _logger(c, 0, 0, shared=sh, tag=0x22)}, size=0x20)
            rec = _rnd(c, 0x30)
            fl = c.rng.getrandbits(32)
            fl = (fl | 0x100000) if c.rng.getrandbits(1) else (fl & ~0x100000)
            c.emu.wbytes(rec + 0x23, struct.pack('<I', fl & 0xffffffff))
            c.emu.w32(o + 0xc, rec)
        c.emu.w32(n + 0x54, o)
        c.emu.w32(n + 0x60, nxt)
        nxt = n
    me = ss.mkobj(c, {0: _logger(c, c.rng.getrandbits(32), 0, shared=sh, tag=0x33)}, size=0x80)
    c.emu.w32(me + 0x50, nxt)
    return [me]


S(0x41f680, 'ZSysMemGC::FlushCache (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_41f680,
  note='unclaimed-77 claim 44; ZSysMemGC::FlushCache()')
S(0x41f7c0, 'ZSysMem::ExgRefs (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_41f7c0,
  note='unclaimed-77 claim 45; ZSysMem::ExgRefs(void*, void*)')
S(0x41fa40, 'ZSysMemGC::SubLink (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen_41fa40,
  note='unclaimed-77 claim 46; ZSysMemGC::SubLink(void*)')
S(0x427d80, 'ZMovementAnimation::WantControl (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen_427d80,
  note='unclaimed-77 claim 47; ZMovementAnimation::WantControl(const float*, const float*, const float*); returns int')
S(0x43f5c0, 'ZGROUP::CalcCenSizeRecur (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_43f5c0,
  note='unclaimed-77 claim 48; ZGROUP::CalcCenSizeRecur()')
