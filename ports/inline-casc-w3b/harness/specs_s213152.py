"""specs_s213152.py - batch 213152: zlib inflate_codes (state machine over literal/length/distance codes with hooked flush / inflate_fast), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import clear_hooks, hook_rec, rnd


def g632aa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def r32u(addr):
        return struct.unpack('<I', bytes(e.rbytes(addr, 4)))[0]
    # window
    WSZ = r.choice([64, 64, 400])
    W = e.alloc(WSZ + 16, 4)
    e.wbytes(W, bytes(r.getrandbits(8) for _ in range(WSZ + 16)))
    WEND = W + WSZ
    # huffman tables: top table + 4 sub tables of 32 entries
    def entry(sub_starts, here, depth_ok, bits_max, isdist=False):
        t = r.random()
        bits = r.randint(1, bits_max)
        if t < 0.25:
            if isdist:
                return (0x50 | r.randint(0, 4), bits, r.randint(1, 30))
            return (0, bits, rb() & 0xff)                      # literal
        if t < 0.45:
            return (0x50 | r.randint(0, 5 if isdist else 13), bits, r.randint(3, 30))   # extra bits
        if t < 0.6 and depth_ok:
            tgt = r.choice(sub_starts)
            return (r.randint(1, 5), bits, tgt - here)         # next level (base is an entry offset)
        if t < 0.72:
            return (96, bits, 0)                               # end of block
        if t < 0.84:
            return (64, bits, 0)                               # invalid
        return (r.choice([0x11, 0x14, 0x15, 0x52, 0x54]), bits, r.randint(3, 30))

    def build(nbits, isdist=False):
        top_n = 1 << nbits
        total = top_n + 4 * 32
        base = e.alloc(8 * total + 16, 4)
        subs = [top_n + 32 * i for i in range(4)]
        for i in range(total):
            ex, bits, bs = entry([base + 8 * s_ for s_ in subs], base + 8 * i, True, min(nbits, 5) if i >= top_n else nbits, isdist)
            if (ex & 0x40) == 0 and ex != 0 and (ex & 0x10) == 0:
                tgt = r.choice(subs)
                bs = (tgt - i) & 0xffffffff
            e.wbytes(base + 8 * i, struct.pack('<BBHI', ex, bits, 0, bs & 0xffffffff))
        return base
    lbits = r.choice([2, 3, 5, 7, 8])
    dbits = r.choice([2, 3, 4, 5])
    lt = build(lbits)
    dt = build(dbits, True)
    cs = e.alloc(0x20, 4)
    mode = r.choice([0, 0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10, 0x20])
    w32u(cs, mode)
    w32u(cs + 4, r.randint(0, 24))
    if mode == 1:
        w32u(cs + 8, lt)
        w32u(cs + 0xc, r.choice([lbits, 1, 2, 3, 5]))
    elif mode == 2:
        w32u(cs + 8, r.randint(0, 5))
    elif mode == 3:
        w32u(cs + 8, dt)
        w32u(cs + 0xc, r.choice([dbits, 1, 2, 3]))
    elif mode == 4:
        w32u(cs + 8, r.randint(0, 4))
        w32u(cs + 0xc, r.randint(1, 20))
    elif mode == 5:
        w32u(cs + 0xc, r.randint(1, 40))
    elif mode == 6:
        w32u(cs + 8, rb())
    e.wbytes(cs + 0x10, bytes([lbits, dbits]))
    w32u(cs + 0x14, lt)
    w32u(cs + 0x18, dt)
    # input
    buf = e.alloc(64, 4)
    e.wbytes(buf, bytes(r.getrandbits(8) for _ in range(64)))
    z = rnd(c, 0x40)
    w32u(z, buf)
    nin = r.choice([0, 1, 2, 3, 4, 6, 9, 10, 10, 11, 12, 20])
    w32u(z + 4, nin)
    w32u(z + 8, r.choice([0, 7, rb()]))
    w32u(z + 0x18, 0)
    s = rnd(c, 0x40)
    w32u(s + 4, cs)
    k0 = r.choice([0, 0, 1, 3, 5, 8, 9, 12, 16])
    w32u(s + 0x1c, k0)
    w32u(s + 0x20, rb() & ((1 << k0) - 1) if k0 else 0)
    w32u(s + 0x28, W)
    w32u(s + 0x2c, WEND)
    q = r.choice([W, W + 1, W + 10, W + 30, W + 62, WEND, WEND, W + 63] + ([WEND - 258, WEND - 258, WEND - 257, WEND - 259, W + 100] if WSZ > 64 else []))
    rd = r.choice([W, W, WEND, W + 5, q, W + 40, q + 1 if q < WEND else W] + ([W, W, W] if WSZ > 64 else []))
    w32u(s + 0x30, rd)
    w32u(s + 0x34, q)

    def flush_side(emu, k):
        ss = emu.arg32(0)
        qq = r32u(ss + 0x34)
        emu.calllog.append(('flush_in', emu.arg32(2), qq, r32u(ss + 0x30)))
        nr = r.choice([W, qq, qq, W + 7, WEND, W + 50, W + 20])
        if qq == WEND and r.random() < 0.5:
            qq = W
            w32u(ss + 0x34, qq)
        if r.random() < 0.7:
            w32u(ss + 0x30, nr)

    def flush_ret(emu, k):
        return r.choice([0, 0, 1, 0xfffffffd, 0xfffffffb, 0xfffffffe, 2]) & 0xffffffff
    hook_rec(c, 0x6331d0, 3, pop=0, ret=flush_ret, side=flush_side)

    def fast_side(emu, k):
        ss, zz = emu.arg32(4), emu.arg32(5)
        t = min(r32u(zz + 4), r.choice([0, 3, 7, 10]))
        w32u(zz, r32u(zz) + t)
        w32u(zz + 4, r32u(zz + 4) - t)
        w32u(zz + 8, r32u(zz + 8) + t)
        w32u(ss + 0x1c, r.choice([0, 3, 7]))
        w32u(ss + 0x20, r.choice([0, 5, rb() & 7]))
        w32u(ss + 0x34, r.choice([W + 3, W + 60, WEND, W + 20]))
        w32u(ss + 0x30, r.choice([W, W + 2, W + 30]))
    hook_rec(c, 0x6332d0, 6, pop=0, ret=lambda emu, k: r.choice([0, 0, 1, 0xfffffffd, 2]) & 0xffffffff, side=fast_side)
    scen = r.random()
    if scen < 0.08 and WSZ > 64:
        # inflate_fast boundary: START with exactly 256..259 free bytes and 9..11 input bytes
        w32u(cs, 0)
        qq2 = WEND - r.choice([256, 257, 258, 259])
        w32u(s + 0x34, qq2)
        w32u(s + 0x30, W)
        w32u(z + 4, r.choice([9, 10, 10, 11]))
    elif scen < 0.16:
        # COPY boundary: distance exactly equal to the bytes already written
        dd2 = r.randint(1, 40)
        w32u(cs, 5)
        w32u(cs + 4, r.randint(1, 5))
        w32u(cs + 0xc, dd2)
        w32u(s + 0x34, W + dd2 + r.choice([0, 0, 0, 1, -1]))
        w32u(s + 0x30, W)
    rr = r.choice([0, 0, 0, 1, 0xfffffffb, 2, rb()])
    return [s, z, rr]


S(0x632aa0, 'inflate_codes', 'cdecl', None, ret='eax', gen=g632aa0, stack_arg_bytes=12)
