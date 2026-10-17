"""specs_s213143.py - batch 213143: typed-value forwarder (record lookup, flag check log, count by kind, table row), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def g4d24e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def instack(v):
        return 0x0fe00000 <= v < 0x0ff00000
    # kind table (zero in the image): 18 rows of 0x14 bytes, kind at +8
    tk = [r.choice([0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 5, 0, 1, 2, 3, 4, 6, 7, 8, 9, 0xa, 0xb, 0x12]) for _ in range(18)]
    if r.random() < 0.15:
        tk[17] = 0x11
    tb = bytearray(r.getrandbits(8) for _ in range(18 * 0x14))
    for i, k in enumerate(tk):
        tb[0x14 * i + 8:0x14 * i + 12] = struct.pack('<I', k)
    e.wbytes(0x6e7a30, bytes(tb))
    nlen = r.choice([0, 1, 3, 7, 12, 20])
    name = e.alloc(32, 4)
    e.wbytes(name, bytes(r.randrange(1, 256) for _ in range(nlen)) + b'\0' * (32 - nlen))
    kind = r.choice(tk + [0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 5, 0x13, 0x9])
    R = rnd(c, 0x40)
    w32u(R + 8, kind)
    flags = r.choice([0, 1, 2, 3, 0xff, rb()])
    mask = r.choice([1, 2, 4, 0x80, 0x100, 0xff, rb()])
    w32u(R + 0x10, flags)
    w32u(R + 0xc, r.choice([0, 0, 0, 5, 0x40, rb() & 0xffff]))
    cnt = r.choice([0, 0, 0, 4, 9, rb() & 0xffff])
    if kind in (0xc, 0xe):
        sl = r.choice([0, 1, 5, 10])
        vp = e.alloc(16, 4)
        e.wbytes(vp, bytes(r.randrange(1, 256) for _ in range(sl)) + b'\0' * (16 - sl))
        v = vp
    elif kind in (0xf, 0x11):
        vp = e.alloc(8, 4)
        w32u(vp, rb())
        v = vp
    else:
        v = r.choice([0, 1, rb()])

    def logh(em, res_):
        fmt = em.arg32(1)
        s = bytes(em.rbytes(em.arg32(2), 32)) if fmt == 0x6963cc else b''
        em.calllog.append(('log', em.reg('ecx'), em.arg32(0), fmt, s))
        em.ret(eax=0, argbytes=0)
    L = obj(c, 0x20, {0x24: e.stub_fn('log', logh)}, nslots=0x10)
    e.w32(0x700390, L)

    def fwd(em, res_):
        p = em.arg32(4)
        pv = bytes(em.rbytes(p, 4)) if instack(p) else p
        em.calllog.append(('fwd', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), pv))
        em.ret(eax=rb(), argbytes=0x14)
    O = obj(c, 0x40, {0xac: e.stub_fn('fwd', fwd)}, nslots=0x2c)
    hook_rec(c, 0x4d2c00, 1, ret=R, pop=4)
    return [O, name, mask, v, cnt]


S(0x4d24e0, 'typed_forward', 'thiscall', None, ret=None, gen=g4d24e0, stack_arg_bytes=16)
