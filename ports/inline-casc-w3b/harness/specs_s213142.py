"""specs_s213142.py - batch 213142: entity ring setup (gather up to 6 via engine table, filter by kind/flag, ring link via vcalls), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5698b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    hook_rec(c, 0x561400, 0, pop=0, this=True)
    hook_rec(c, 0x563400, 0, pop=0, this=True, ret=lambda emu, k: (rb() & ~0xff) | (1 if r.random() < 0.3 else 0))
    hook_rec(c, 0x5618b0, 2, pop=8, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    m = r.choice([0, 1, 2, 2, 3, 3, 4, 5, 6, 6, 6])
    ids = [rb() | 1 for _ in range(6)]
    ents = []
    emap = {}
    kinds = [0x378, 0x378, 0xff0000, 0xff1234, 0xfe0000, 0x1ff0000, 0x370, 0, rb(), 0x379, 0x378]
    for i in range(m):
        kd = r.choice(kinds)

        def lg(emu, k, tag):
            emu.calllog.append((tag, emu.arg32(0), emu.arg32(1) if tag == 'v31c' else 0))
        E = obj(c, 0x40, {
            0x310: pystub(c, 0, this=True, ret=lambda emu, k, kd=kd: kd),
            0xbc: pystub(c, 1, this=True, side=lambda emu, k: lg(emu, k, 'vbc')),
            0x31c: pystub(c, 2, this=True, side=lambda emu, k: lg(emu, k, 'v31c')),
        }, nslots=0x180)
        P = rnd(c, 0x40)
        w32u(P + 0x3c, r.choice([0, 0x400, 0x400, 0xffffffff, rb(), 0x3ff, 0x800]))
        w32u(E + 8, P)
        ents.append(E)
        emap[ids[i]] = E
    # stale tail: ids beyond m map to nothing

    def tbl58(emu, k):
        v = emu.arg32(0)
        emu.calllog.append(('t58', v))
        return emap.get(v, 0)

    def q90(emu, k):
        emu.calllog.append(('q90', emu.arg32(0)))
        emu.wbytes(emu.arg32(1), bytes([r.choice([0, 0, 0, 1, 0x80, 0xff])]))
    Rq = obj(c, 0x20, {0x90: pystub(c, 2, this=True, stackmark=(1,), side=q90)}, nslots=0x40)
    T = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=tbl58), 0x134: pystub(c, 0, this=True, ret=lambda emu, k: Rq)}, nslots=0x180)
    eng = rnd(c, 0x2000)
    w32u(eng + 0x9b, T)
    e.w32(0x70039c, eng)

    def own_cur(emu, k):
        return r.choice(ents + [0, rb() & ~3, ents[0] if ents else 0] if ents else [0, rb() & ~3])
    Own = obj(c, 0x20, {
        0x2e0: pystub(c, 0, this=True, ret=own_cur),
        0x2e4: pystub(c, 1, this=True),
    }, nslots=0x180)
    mode = rnd(c, 0x80)
    pool = [bytes(e.rbytes(0x6a7808, 16)), bytes(e.rbytes(0x6a7810, 16)), bytes(e.rbytes(0x6a7818, 16))]
    cs = []
    for p in pool:
        cs.append(p.split(b'\0')[0])
    ch = r.random()
    if ch < 0.5:
        s = r.choice(cs)
    elif ch < 0.65:
        b = bytearray(r.choice(cs) or b'a')
        b[-1] ^= r.choice([1, 0x20, 2])
        s = bytes(b)
    elif ch < 0.75:
        s = r.choice(cs) + b'x'
    elif ch < 0.8:
        s = r.choice(cs)[:-1]
    else:
        s = bytes(r.randrange(97, 123) for _ in range(r.randrange(0, 8)))
    e.wbytes(mode + 0x48, s + b'\0' * 16)
    self_ = rnd(c, 0x200)
    for i in range(6):
        w32u(self_ + 0x19c + 4 * i, ids[i])
    w32u(self_ + 0x94, mode)
    w32u(self_ + 0x44, Own)
    return [self_]


S(0x5698b0, 'entity_ring', 'thiscall', None, ret=None, gen=g5698b0)
