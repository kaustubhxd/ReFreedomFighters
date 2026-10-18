"""specs_s213103.py - batch 213103: packed animation track sampler with bit streams and blend call, Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, clear_hooks, hook_rec


def set_bits(buf, off, w, k, val):
    """Store val (w bits) as the k-th (1-based) value of the stream starting at buf[off] (width byte), MSB first from byte off+1."""
    bp = (k - 1) * w
    for i in range(w):
        bit = (val >> (w - 1 - i)) & 1
        pos = bp + i
        byte = off + 1 + (pos >> 3)
        m = 0x80 >> (pos & 7)
        if bit:
            buf[byte] |= m
        else:
            buf[byte] &= ~m & 0xff


def g4e87b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    n = r.choice([0, 1, 2, 3, 5, 10, 20])
    ti = r.choice([0, 0, 1, 2, n - 2, n - 1, n, n + 1, r.randrange(0, 22), -1, -2])
    frac = r.choice([0.0, 0.0, 0.25, 0.5, 0.999])
    t = f32(ti + frac) if ti >= 0 else f32(ti - frac)
    ti = int(t)    # truncation toward zero, as cvttss2si
    wA = r.choice([1, 2, 3, 4, 5, 6, 7, 7, 10, 11, 11, 12])
    wB = r.choice([1, 2, 3, 6, 8, 11, 11, 12])
    PAD = 32
    A = bytearray(r.getrandbits(8) for _ in range(PAD + 64))
    B = bytearray(r.getrandbits(8) for _ in range(PAD + 6300))
    A[PAD] = wA
    B[PAD] = wB
    i0 = 0
    b0 = 0
    if ti != 0:
        i0 = 0 if r.random() < 0.15 else r.randrange(1, (1 << wA))
        i0 = min(i0, 4094)
        if ti >= 1:
            set_bits(A, PAD, wA, ti, i0)
        else:
            # a negative index reads bits before the stream: just let the random bytes decide
            pass
        # derive i0 from what the stream really contains
        bp = (ti - 1) * wA
        byte = bp >> 3
        off = bp & 7
        v = (A[PAD + byte + 1] << 16) | (A[PAD + byte + 2] << 8) | A[PAD + byte + 3]
        v = (v << 8) & 0xffffffff
        sv = v - (1 << 32) if v & 0x80000000 else v
        sh = (32 - off - wA) & 31
        i0 = ((sv >> sh) & ((1 << wA) - 1))
        if i0 > 4094:
            return None
        if i0:
            b0 = ti if (r.random() < 0.45 and 0 <= ti < (1 << wB)) else r.randrange(0, 1 << wB)
            set_bits(B, PAD, wB, i0, b0)
            bp = (i0 - 1) * wB
            byte = bp >> 3
            off = bp & 7
            v = (B[PAD + byte + 1] << 16) | (B[PAD + byte + 2] << 8) | B[PAD + byte + 3]
            v = (v << 8) & 0xffffffff
            sv = v - (1 << 32) if v & 0x80000000 else v
            sh = (32 - off - wB) & 31
            b0 = (sv >> sh) & ((1 << wB) - 1)
    Aa = e.alloc(len(A), 4)
    e.wbytes(Aa, bytes(A))
    Ba = e.alloc(len(B), 4)
    e.wbytes(Ba, bytes(B))
    NT = 4100
    tab = bytearray()
    for _ in range(NT * 4):
        tab += struct.pack('<h', r.choice([0, 1, -1, 32767, -32768, 16256, -16256, 32512, r.randrange(-32768, 32768)]))
    Ta = e.alloc(len(tab), 4)
    e.wbytes(Ta, bytes(tab))
    out = e.alloc(16, 4)
    e.wbytes(out, bytes(r.getrandbits(8) for _ in range(16)))
    this = rnd(c, 0x20)

    def ret_8b70(emu, k):
        emu.calllog.append(('8b70', emu.arg32(1)))
        return (r.choice([ti + r.choice([-1, 0, 1, 2, 5, 100]), b0, b0 + 1, r.getrandbits(8)])) & 0xffffffff
    hook_rec(c, 0x4e8b70, 2, pop=8, this=True, ret=ret_8b70)

    def side_df040(emu, k):
        emu.calllog.append(('df040', emu.reg('edx'), bytes(emu.rbytes(emu.reg('ecx'), 16)), bytes(emu.rbytes(emu.arg32(0), 16))))
    hook_rec(c, 0x4df040, 2, pop=8, this=True, nullflag=(0,), side=side_df040)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, out, F(t), n, Aa + PAD, Ba + PAD, Ta]


def _g(c):
    for _ in range(100):
        a = g4e87b0(c)
        if a is not None:
            return a
    raise RuntimeError('no case')


S(0x4e87b0, 'track_sampler', 'thiscall', None, ret=None, gen=_g)
