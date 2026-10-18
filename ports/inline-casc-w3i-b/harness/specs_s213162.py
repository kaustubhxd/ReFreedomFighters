"""specs_s213162.py - batch 213162: packed model record reader (counted arrays copied into allocated/preallocated buffers), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g531270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def copy(emu, k):
        d, s_, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        if 0 < n <= 0x400:
            emu.wbytes(d, emu.rbytes(s_, n))
    hook_rec(c, 0x634d22, 3, ret=lambda emu, k: emu.arg32(0), pop=0, side=copy)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda emu, k: emu.alloc(max(4, min(emu.arg32(0), 0x1000)), 4))
    e.wbytes(0x701b5d, bytes([r.choice([0, 1, 1])]))

    def mh(em, res_):
        em.calllog.append(('mlog', em.reg('ecx'), tuple(em.arg32(i) for i in range(3 if em.arg32(1) == 0x6a1538 else 8))))
        em.ret(eax=0, argbytes=0)
    M = obj(c, 0x30, {0x2c: e.stub_fn('mlog', mh)}, nslots=0x20)
    Lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, Lg)

    def fl():
        return struct.pack('<f', r.choice([0.0, 1.0, -1.0, 0.5, r.uniform(-100, 100)]))
    c2a = r.choice([0, 1, 2, 3, 4])
    def w(n):
        return struct.pack('<H', n)
    def blob(n):
        return bytes(r.getrandbits(8) for _ in range(n))
    b = struct.pack('<I', rb()) + w(c2a)
    c52 = r.randrange(5)
    b += w(c52) + blob(c52 * 0x16)
    c58 = r.randrange(5)
    b += w(c58) + blob(c58 * 12)
    c70 = r.randrange(5)
    b += w(c70) + blob(c70 * c2a * 4)
    c5e = r.randrange(5)
    b += w(c5e) + blob(c5e * 4)
    c64 = r.randrange(5)
    b += w(c64) + blob(c64 * 10)
    c86 = r.randrange(5)
    b += w(c86) + blob(c86 * 12)
    f4 = r.choice([0, 1])
    f5 = r.choice([0, 1])
    if f4:
        b += blob(c86 * 4)
        if f5:
            b += blob(c86 * 24)
    c6a = r.randrange(5)
    b += w(c6a) + blob(c6a * 4)
    c76 = r.randrange(5)
    b += w(c76) + blob(c76 * 11)
    c80 = r.randrange(6)
    b += w(c80) + blob(c80)
    b += b''.join(fl() if r.random() < 0.8 else blob(4) for _ in range(17))
    src = e.alloc(len(b) + 16, 4)
    e.wbytes(src, b + blob(16))
    this = rnd(c, 0x100)
    e.wbytes(this + 4, bytes([f4, f5]))
    mode = r.choice([1, 1, 1, 0, 2])
    if mode != 1:
        for off in (0x54, 0x5a, 0x72, 0x60, 0x66, 0x88, 0x8c, 0x90, 0x6c, 0x78, 0x7c, 0x82):
            e.w32(this + off, e.alloc(0x200, 4))
    return [this, src, mode, rb()]


S(0x531270, 'model_record_read', 'thiscall', None, ret='eax', gen=g531270, stack_arg_bytes=12)
