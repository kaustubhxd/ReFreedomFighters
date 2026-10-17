"""specs_s213149.py - batch 213149: zlib inflate() state machine (header, dictionary id, blocks hook, adler trailer), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g62f5d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def r32u(addr):
        return struct.unpack('<I', bytes(e.rbytes(addr, 4)))[0]
    z = rnd(c, 0x60)
    st = rnd(c, 0x20)
    blocks = rnd(c, 0x20)
    mode = r.choice([0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 8, 9, 10, 11, 12, 13, 14, 0x20, 7, 8])
    wbits = r.choice([8, 9, 12, 15, 15, 10])
    # stream bytes: favour a valid header in the first two bytes
    m = r.choice([0x78, 0x78, 0x08, 0x18, 0x28, 0x38, 0x48, 0x58, 0x68, 0x88, 0x07, 0xf8, 0x78])
    cands = [b for b in range(256) if ((m << 8) + b) % 31 == 0]
    b = r.choice(cands) if r.random() < 0.7 else r.getrandbits(8)
    data = bytearray([m, b]) + bytes(r.getrandbits(8) for _ in range(6))
    if mode in (1,):
        pass
    n = r.choice([0, 0, 1, 1, 2, 3, 4, 5, 6, 8])
    buf = e.alloc(64, 4)
    e.wbytes(buf, bytes(data) + bytes(r.getrandbits(8) for _ in range(40)))
    if mode >= 2 and mode != 7:
        e.wbytes(buf, bytes(r.getrandbits(8) for _ in range(40)))
    w32u(z, buf)
    w32u(z + 4, n)
    w32u(z + 8, r.choice([0, 5, 0xffffffff, rb()]))
    w32u(z + 0x1c, st)
    w32u(z + 0x18, 0)
    w32u(st, mode)
    w32u(st + 4, r.choice([0x78, 0x08, 0x58, 0x88, 0x18, rb() & 0xff]))
    w32u(st + 8, rb())
    w32u(st + 0xc, r.choice([0, 0, 1]))
    w32u(st + 0x10, wbits)
    w32u(st + 0x14, blocks)
    zc = {'z': z}

    def blocks_side(emu, k):
        zz = emu.arg32(1)
        emu.calllog.append(('blk_r', emu.arg32(2)))
        avail = r32u(zz + 4)
        take = r.choice([0, 0, 1, 2, 3, 4, 6]) if avail else 0
        take = min(take, avail)
        w32u(zz, r32u(zz) + take)
        w32u(zz + 4, avail - take)
        w32u(zz + 8, r32u(zz + 8) + take)

    def blocks_ret(emu, k):
        return r.choice([0, 0, 1, 1, 1, 1, 0xfffffffd, 0xfffffffb, 2, 0xfffffffc, 0xfffffffe]) & 0xffffffff
    hook_rec(c, 0x631850, 3, pop=0, ret=blocks_ret, side=blocks_side)

    def reset_side(emu, k):
        zz, was = emu.arg32(1), emu.arg32(2)
        ni = r32u(zz)
        nb = bytes(emu.rbytes(ni, 4))
        val = struct.unpack('>I', nb)[0]
        w32u(was, val if r.random() < 0.6 else (val ^ r.choice([1, 0x100, 0x1000000, rb()])))
    hook_rec(c, 0x6322e0, 3, pop=0, ret=0, side=reset_side, stackmark=(2,) if False else ())
    f = r.choice([0, 0, 1, 2, 4, 4, 3, 0xffffffff, 5])
    if r.random() < 0.03:
        w32u(z, 0)
    elif r.random() < 0.03:
        w32u(z + 0x1c, 0)
    return [z, f]


S(0x62f5d0, 'inflate', 'stdcall', None, ret='eax', gen=g62f5d0)
