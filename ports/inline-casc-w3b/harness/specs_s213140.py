"""specs_s213140.py - batch 213140: per-frame update of timed nodes + record clocks with fmod, Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

FMOD = bytes.fromhex('d9c9d9f8dfe09e7af9ddd9c3')   # _CIfmod: fxch; fprem loop; fstp st1; ret


def g4650c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    fm = e.alloc(32, 16)
    e.wbytes(fm, FMOD)
    e.w32(0x676358, fm)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    eng = rnd(c, 0x100)
    w32u(eng + 0x40, r.choice([0, 1000, 5000, 100000, rb() & 0xffffff]))
    e.w32(0x70039c, eng)
    # nodes
    nn = r.choice([0, 1, 1, 2, 3])
    recs = []
    for i in range(nn):
        P = rnd(c, 0x100)
        N = P + 4
        w32u(N + 0x44, r.choice([5, 0, 3, 5, -1, -1, -2, 0x7fffffff]))
        wf(N + 8, r.choice([0.0, 1.0, 2.5, 10.0]))
        V = rnd(c, 0x90)
        w32u(V + 0x6c, r.choice([0, 1, 100, 1000, 0xffffff00]))
        w32u(V + 0x7c, rb())
        w32u(N + 0x70, V)
        wf(N + 0x28, r.choice([0.5, 1.0, 2.0, -1.0]))
        wf(N + 0x1c, r.choice([0.0, 1.0, 2.0, 50.0]))
        wf(N + 0x18, r.choice([0.0, 1.0, 5.0, 100.0, 1000.0]))
        w32u(N + 0xc, r.choice([0, 1, 2, 5, 3, 100]))
        recs.append(P)
    cnt = [0]

    def nxt(emu, k):
        i = cnt[0]
        cnt[0] += 1
        return recs[i] if i < len(recs) else 0
    I = obj(c, 0x40, {0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                      0x64: pystub(c, 1, this=True, stackmark=(0,), ret=nxt),
                      0x44: pystub(c, 1, this=True, stackmark=(0,))}, nslots=0x20)

    def s330(emu, k):
        N = emu.reg('ecx')
        emu.wbytes(N + 4, struct.pack('<f', f32(r.choice([0.0, 1.0, 2.0, 3.5, 50.0, 1000.0, 1.0e10, -1.0]))))
    hook_rec(c, 0x465330, 1, pop=4, this=True, side=s330)
    hook_rec(c, 0x462510, 1, pop=4, this=True)
    hook_rec(c, 0x463da0, 2, pop=8, this=True)
    hook_rec(c, 0x4de7a0, 0, pop=0, this=True, side=lambda emu, k: emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(36))))
    # records array
    nr = r.choice([0, 1, 2, 3])
    A = e.alloc(0x18 * 4 + 16, 4)
    for i in range(max(nr, 1)):
        q = rnd(c, 0x40)
        wf(q + 0x18, r.choice([0.0, 1.0, 2.5, 10.0, 7.0]))
        wf(q + 4, r.choice([0.0, 1.0, 2.5, 10.0, 7.5, 12.0]))
        w32u(q + 0xc, r.choice([1, 2, 3, 5, 7, 10, 0xfffffffd]))
        w32u(q + 0x14, r.choice([0, 0x200, 0x100, rb()]))
        e.wbytes(A + 0x18 * i, bytes(r.getrandbits(8) for _ in range(0x18)))
        w32u(A + 0x18 * i + 0x14, q)
        e.wbytes(A + 0x18 * i + 4, bytes([r.choice([0, 1, 2, 3, 4, 7])]))
    own = obj(c, 0x40, {0x5c: pystub(c, 3, this=True, ret=lambda emu, k: (rb() & ~0xff) | r.choice([0, 1, 5]))}, nslots=0x20)
    this = obj(c, 0x200, {0x26c: pystub(c, 0, this=True), 0x270: pystub(c, 2, this=True), 0x268: pystub(c, 2, this=True),
                          0x340: pystub(c, 2, this=True)}, nslots=0x1a0)
    w32u(this + 0x18, 0 if r.random() < 0.15 else I)
    w32u(this + 0x1c, A)
    w32u(this + 0x20, nr)
    w32u(this + 0x6c, own)
    w32u(this + 0x122, r.choice([0, 0, 1, 2, 3]))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x4650c0, 'node_update', 'thiscall', None, ret='al', gen=g4650c0)
