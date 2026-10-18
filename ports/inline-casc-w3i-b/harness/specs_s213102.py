"""specs_s213102.py - batch 213102: record-ring consumer with state flags and timestamp refresh, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g52c000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x90)
    A = rnd(c, 0x20)
    e.w32(this + 0x18, A if r.random() < 0.8 else 0)
    St = rnd(c, 0x240)
    e.w32(this + 0x1c, St)
    # entry E
    e0 = r.choice([0, 1000, r.getrandbits(32), 0xfffffff0])
    e4 = r.choice([0, 5, 100, r.getrandbits(8)])
    E = rnd(c, 0x20)
    e.w32(E, e0)
    e.w32(E + 4, e4)
    e.wbytes(E + 0x10, bytes([0 if r.random() < 0.3 else r.choice([1, 2, 0xff])]))
    e.w32(St + 0x44, E if r.random() < 0.8 else 0)
    e.wbytes(St + 0x48, bytes([0 if r.random() < 0.5 else r.choice([1, 2, 0xff])]))
    e.w32(St + 0x49, r.choice([0, 0, 1, 2, r.getrandbits(32)]))
    e.w32(St + 0x4d, r.choice([0, 1, 2, r.getrandbits(32)]))
    e.wbytes(St + 0x99, bytes([0 if r.random() < 0.5 else 1]))
    e.wbytes(St + 0x230, bytes([r.getrandbits(8)]))
    e.w32(St + 0x202, r.choice([0, 0, 1, r.getrandbits(32)]))
    # ring
    N = r.choice([1, 2, 3, 5])
    buf = e.alloc(0x32 * N + 8, 4)
    for i in range(N):
        rec = bytearray(r.getrandbits(8) for _ in range(0x32))
        if r.random() < 0.55:
            rec[4:8] = b'\0\0\0\0'
        elif rec[4:8] == b'\0\0\0\0':
            rec[4] = 1
        e.wbytes(buf + 0x32 * i, bytes(rec))
    Rr = rnd(c, 0x20)
    head = r.randrange(N)
    tail = head if r.random() < 0.2 else r.randrange(N)
    e.w32(Rr, buf)
    e.w32(Rr + 4, N)
    e.w32(Rr + 8, head)
    e.w32(Rr + 0xc, tail)
    e.w32(this + 0x79, Rr)
    # engine slot 0x1c8: timestamp near E[0] + E[4]
    eng = obj(c, 0x100, {0x1c8: pystub(c, 2, this=True, ret=lambda emu, k: (e0 + e4 + r.choice([-1, 0, 1, 2, 5, -1000, 100000])) & 0xffffffff)}, nslots=0x80)
    e.w32(0x70039c, eng)
    hook_rec(c, 0x52cf00, 1, pop=4, this=True, ret=lambda emu, k: r.getrandbits(32))
    hook_rec(c, 0x52cf10, 0, pop=0, this=True)
    hook_rec(c, 0x52cf40, 0, pop=0, this=True)

    def ret_b0c0(emu, k):
        return r.getrandbits(32) & (0xffffff00 if r.random() < 0.5 else 0xffffffff)
    hook_rec(c, 0x52b0c0, 0, pop=0, this=True, ret=ret_b0c0)

    def side_c6e0(emu, k):
        emu.calllog.append(('c6e0', bytes(emu.rbytes(emu.arg32(0), 0x32))))
    hook_rec(c, 0x52c6e0, 2, pop=8, this=True, side=side_c6e0)
    arg = r.getrandbits(32) if r.random() < 0.5 else r.choice([0, 1, 0x100, 0xff, 0x01])
    return [this, arg]


S(0x52c000, 'ring_consumer', 'thiscall', None, ret=None, gen=g52c000)
