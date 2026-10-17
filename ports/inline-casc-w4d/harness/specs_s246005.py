"""specs_s246005.py - w4d batch 246005: 0x493980."""
import pe_emu
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g493980(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    em = c.emu
    st = lambda emu: emu.r32(emu.r32(pe_emu.TEB) + 8)
    sr = [seh_record(c, 2) for _ in range(10)]

    def log(emu, k, tag, j, *extra):
        emu.calllog.append((tag, st(emu)) + extra)
        sr[j](emu, k)

    THIS = rnd(c, 0x1d00)
    VT = rnd(c, 0x200)
    em.w32(THIS, VT)
    TBL = rnd(c, 0x40)
    fresh = r.random() < 0.5
    em.wbytes(THIS + 0x1c55, (0 if fresh else TBL).to_bytes(4, 'little'))
    em.wbytes(THIS + 0x1c59, r.randrange(0, 0x40).to_bytes(4, 'little'))
    BLK = rnd(c, 0x40)
    nullalloc = r.random() < 0.2
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: 0 if nullalloc else BLK, pop=0, side=lambda emu, k: log(emu, k, 'alloc', 0, emu.arg32(0)))
    hook_rec(c, 0x4e6780, 1, ret=lambda emu, k: 0, pop=4, this=True,
             side=lambda emu, k: log(emu, k, 'c6780', 1, emu.reg('ecx') - BLK, emu.arg32(0)))
    hook_rec(c, 0x48cf50, 0, ret=lambda emu, k: 0, pop=0, this=True,
             side=lambda emu, k: log(emu, k, 'c8cf50', 2, emu.reg('ecx') - BLK, emu.r32(BLK), emu.r32(BLK + 0x18), emu.r32(BLK + 0x1c)))
    em.w32(VT + 0x114, pystub(c, 4, ret=lambda emu, k: 0, pop=16, this=True,
                              side=lambda emu, k: log(emu, k, 'v114', 3, emu.reg('ecx') - THIS, emu.r32(THIS + 0x1c55) - BLK if emu.r32(THIS + 0x1c55) else 0,
                                                      emu.arg32(0), emu.arg32(1), emu.arg32(2), emu.arg32(3))))
    heaps = []

    def s630(emu, k):
        obj = emu.reg('ecx'); src = emu.arg32(0)
        t = emu.rbytes(src, 100).split(b'\0')[0] + b'\0'
        emu.calllog.append(('asg', t.hex()))
        if r.random() < 0.5 and len(t) <= 0x70:
            nb = obj + 4
        else:
            nb = rnd(c, 0x90); heaps.append(nb)
        emu.wbytes(nb, t)
        emu.w32(obj, nb)
        sr[4](emu, k)
    hook_rec(c, 0x4cc630, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', stackmark=(0,), side=s630)
    hook_rec(c, 0x634273, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, stackmark=(0,),
             side=lambda emu, k: (emu.calllog.append(('free', heaps.index(emu.arg32(0)) if emu.arg32(0) in heaps else -1, emu.arg32(1))), sr[5](emu, k)))
    REC = rnd(c, 0x10)
    found = r.random() < 0.35

    def s880(emu, k):
        p = emu.r32(emu.arg32(0))
        log(emu, k, 'f880', 6, emu.reg('ecx') - BLK if emu.reg('ecx') >= BLK and emu.reg('ecx') < BLK + 0x40 else emu.reg('ecx'),
            emu.rbytes(p, 100).split(b'\0')[0].hex())
    hook_rec(c, 0x48f880, 1, ret=lambda emu, k: REC if found else 0, pop=4, this=True, stackmark=(0,), side=s880)
    GO = rnd(c, 0x20)
    GVT = rnd(c, 0x200)
    em.w32(GO, GVT)
    em.w32(0x70039c, GO)
    bufs = []

    def sf8(emu, k):
        b = rnd(c, 0x80)
        bufs.append(b)
        log(emu, k, 'gf8', 7, emu.reg('ecx') - GO, emu.arg32(0))
        return b
    em.w32(GVT + 0xf8, pystub(c, 1, ret=sf8, pop=4, this=True))

    def s3820(emu, k):
        eb = emu.arg32(0)
        buf = emu.r32(eb)
        log(emu, k, 'r3820', 8, emu.reg('ecx') - BLK if emu.reg('ecx') >= BLK and emu.reg('ecx') < BLK + 0x40 else emu.reg('ecx'),
            eb - THIS, emu.arg32(1), emu.arg32(2), bufs.index(buf) if buf in bufs else -1, emu.rbytes(buf, 100).split(b'\0')[0].hex())
    hook_rec(c, 0x493820, 3, ret=lambda emu, k: r.getrandbits(32), pop=12, this=True, side=s3820)
    n = r.choice([0, 1, 3, 8, 20, 40])
    alpha = b'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@[`{0123456789_.'
    NAME = rnd(c, 0x60)
    em.wbytes(NAME, bytes(r.choice(alpha) for _ in range(n)) + b'\0')
    a1 = r.choice([0, 0, 1, 5, 0x20, 0x80, 0xff, 0x100, r.randrange(0, 0x100)])
    return [THIS, NAME, a1, r.getrandbits(32), r.getrandbits(32)]


S(0x493980, 'GUESS FUN_493980', 'thiscall', None, ret='ax', gen=g493980, note='batch246005')
