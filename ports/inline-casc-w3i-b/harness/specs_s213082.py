"""specs_s213082.py - batch 213082: stack strings from exe constants, formatted log line, child walk, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g567510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    cnt = [0]
    names = []

    def k0(emu, rr):
        k = cnt[0]
        cnt[0] += 1
        a0, a1 = emu.arg32(0), emu.arg32(1)
        if k == 0:
            ent = ('k0', k, emu.reg('ecx'), a0, bytes(emu.rbytes(a1, 0x1a)))
            ret = r.getrandbits(32)
        elif k == 1:
            ent = ('k0', k, emu.reg('ecx'), a0, a1)
            ret = r.getrandbits(32)
        else:
            ent = ('k0', k, emu.reg('ecx'), bytes(emu.rbytes(a0, 0x15)), a1)
            # the returned name: the same text as the argument, a different text or the default string
            s = bytes(emu.rbytes(a1, 0x20)).split(b'\0')[0]
            x = r.random()
            if x < 0.4:
                txt = s
            elif x < 0.7:
                txt = s + b'x'
            else:
                txt = r.choice([b'', b'abc', b'other name', s[:-1]])
            p = rnd(c, len(txt) + 1)
            emu.wbytes(p, txt + b'\0')
            ret = p
        emu.calllog.append(ent)
        emu.ret(eax=ret, argbytes=8)
    k0s = e.stub_fn('k0', k0)

    def f198(emu, rr):
        a = (emu.arg32(0), emu.arg32(2), emu.arg32(3), emu.arg32(4))
        emu.calllog.append(('f198', a))
        buf = emu.arg32(1)
        txt = bytes(r.getrandbits(8) | 1 for _ in range(r.randint(0, 0x30)))
        emu.wbytes(buf, txt.ljust(0x40, b'\0'))
        emu.ret(eax=r.getrandbits(32), argbytes=0)
    f198s = e.stub_fn('f198', f198)

    K = obj(c, 0x20, {0x0: k0s}, nslots=0x10)
    T = rnd(c, 0xaf0)
    e.w32(T + 0xae4, K)
    Z = obj(c, 0x20, {0x198: f198s}, nslots=0x100)
    G = obj(c, 0x20, {0x190: sl(0, Z)}, nslots=0x100)
    # engine object with fields: vtable at G, [G+0x9b] = T
    eng = G
    e.w32(eng + 0x9b - 0 if False else eng + 0x9b, T) if False else None
    e.w32(0x70039c, G)
    # G only has 0x20 bytes: use a bigger object
    G = obj(c, 0xa0, {0x190: sl(0, Z)}, nslots=0x100)
    e.w32(G + 0x9b, T)
    e.w32(0x70039c, G)
    this = rnd(c, 0x1a0)
    e.w32(this + 0x18c, r.getrandbits(32))
    nn = r.choice([0, 1, 2, 3, 4])
    nodes = []
    for i in range(nn):
        flagsp = rnd(c, 0x30)
        fl = r.choice([0, 0, 0, 0x100000, 0x200002, r.getrandbits(32) & ~0x100000, r.getrandbits(32)])
        e.wbytes(flagsp + 0x23, struct.pack('<I', fl))
        o = obj(c, 0x20, {0x1e0: sl(1, lambda emu, k: r.choice([0, 1, 1, 0x100, 0xff])), 0x284: sl(1)}, nslots=0x100)
        e.w32(o + 0xc, flagsp)
        if r.random() < 0.8:
            sp = rnd(c, 0x20)
            e.wbytes(sp, r.choice([b'item\0', b'\0', b'abc\0', b'a longer entry name\0']))
            e.w32(o + 4, sp)
        else:
            e.w32(o + 4, 0)
        n = rnd(c, 0x60)
        e.w32(n + 0x54, o)
        nodes.append(n)
    holder = rnd(c, 0x60)
    e.w32(holder + 0x54, nodes[0] if nodes else 0)
    e.w32(this + 0x194, 0 if r.random() < 0.1 else holder)
    seq = nodes[1:] + [0]
    hook_rec(c, 0x4db520, 0, this=True, ret=lambda emu, k: seq[min(k, len(seq) - 1)])
    hook_rec(c, 0x566f10, 0, this=True, ret=lambda emu, k: r.choice([0, 1, 2, 3, 0xffffffff, r.getrandbits(32)]))
    hook_rec(c, 0x5636c0, 2, this=True, deref={1: -0x40})
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x567510, 'format_and_walk_children', 'thiscall', None, ret=None, gen=g567510)
