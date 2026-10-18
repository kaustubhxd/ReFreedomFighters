"""specs_s213126.py - batch 213126: node-list reader/writer transfer loop (jump table over node kind, _strnicmp import stubbed), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5fcd70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def cmpstub(em, res_):
        a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
        n = n & 0xffffffff
        if n > 0x40:
            n = 0x40
        sa, sb = em.rbytes(a, n), em.rbytes(b, n)
        em.calllog.append(('cmp', sa.lower(), sb.lower(), n))
        em.ret(eax=0 if sa.lower() == sb.lower() else (1 if sa.lower() > sb.lower() else 0xffffffff), argbytes=0)
    e.w32(0x676408, e.stub_fn('strnicmp', cmpstub))
    pat4 = e.rbytes(0x6b92d0, 4)
    pat6 = e.rbytes(0x6b87a8, 6)
    flag = lambda p: (lambda emu, k: rb() if r.random() < p else 0)
    fl = lambda: r.choice([0.0, -0.0, 1.5, -2.25, 3.0e10, r.uniform(-9, 9)])
    # reader C
    Cv = obj(c, 0x40, {0x10: pystub(c, 3, this=True, stackmark=(), ret=lambda emu, k: rb()),
                       0x0: pystub(c, 1, this=True, ret=lambda emu, k: rb()),
                       0x4: pystub(c, 1, this=True, st0=lambda emu, k: fl()),
                       0x8: pystub(c, 1, this=True, ret=lambda emu, k: rb()),
                       0x14: pystub(c, 1, this=True, ret=lambda emu, k: rb())}, nslots=0x10)
    D = rnd(c, 0x140)
    Bv = obj(c, 0xb00, {0x0: pystub(c, 2, this=True, ret=lambda emu, k: rb())}, nslots=0x10)
    w32u(Bv + 0x9e, D + 1)
    # node list
    n = r.choice([0, 1, 2, 3, 4, 5])
    kinds = [0x14, 0x15, 0x16, 0x24, 0x14, 0x15, 0x16, 0x24, 0x17, 0x13, 0x30, 0x25, 0x28]
    nodes = []
    for i in range(n):
        if r.random() < 0.06:
            nodes.append(0)
            continue
        nd = rnd(c, 0x60)
        e.w32(nd, r.choice(kinds))
        e.w32(nd + 8, r.choice([0, 4, 5, 8, 0x13, 0x20, 0x3c]))
        # text: 0..8 characters, often the tag
        tl = r.choice([4, 4, 6, 6, 3, 5, 7, 0, 8])
        base = r.choice([pat4, pat6])
        txt = bytearray(base if r.random() < 0.7 else r.randbytes(8))
        txt = (txt + r.randbytes(8))[:tl]
        if r.random() < 0.3:
            txt = bytearray(bytes(b ^ 0x20 if 0x41 <= (b | 0x20) <= 0x7a and r.random() < 0.5 else b for b in txt))
        sbuf = e.alloc(16, 4)
        e.wbytes(sbuf, bytes(txt) + bytes(16 - len(txt)))
        e.w32(nd + 0x20, sbuf)
        e.w32(nd + 0x24, sbuf + len(txt))
        nodes.append(nd)
    arr = e.alloc(4 * max(n, 1) + 4, 4)
    for i, nd in enumerate(nodes):
        e.w32(arr + 4 * i, nd)
    Ls = rnd(c, 0x10)
    e.w32(Ls, arr)
    e.w32(Ls + 8, n)
    A = rnd(c, 0x60)
    e.w32(A + 0x30, Ls)
    e.w32(A + 0x34, r.choice([0, 3, 99]))
    flagp = rnd(c, 4)
    e.wbytes(flagp, bytes([1 if r.random() < 0.1 else 0]))

    def s14(emu, k):
        emu.wbytes(emu.arg32(1), (b'msg%d' % (k % 7)) + bytes([0]))

    def sc(emu, k):
        p = emu.arg32(1)
        s = emu.rbytes(p, 16).split(b'\0')[0]
        emu.calllog.append(('log', s))
    Pv = obj(c, 0x40, {0x14: pystub(c, 4, this=True, pop=0, stackmark=(1,), side=s14),
                       0xc: pystub(c, 2, this=True, pop=0, stackmark=(1,), side=sc)}, nslots=0x10)
    e.w32(0x724270, Pv)
    hook_rec(c, 0x5fb8b0, 1, pop=4, this=True, ret=flag(0.5))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [flagp, A, Bv, Cv]


S(0x5fcd70, 'node_list_transfer', 'thiscall', None, ret=None, gen=g5fcd70)
