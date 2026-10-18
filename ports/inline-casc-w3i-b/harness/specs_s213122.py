"""specs_s213122.py - batch 213122: pick-list builder (candidate ids via engine hit queries with a preferred id moved to the front), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g4d9f90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pool = [0x1111, 0x2222, 0x3333, 0x4444, 0x5555, 0x6666]
    st = {}

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    def lgarr(emu, name, addr, n):
        emu.calllog.append((name, tuple(emu.r32(addr + 4 * i) for i in range(n))))

    def fill(emu, addr, n, vals):
        for i in range(n):
            emu.w32(addr + 4 * i, vals())
    this = rnd(c, 0x80)
    flags = r.getrandbits(32) & ~0x200c00
    if r.random() < 0.2:
        flags |= r.choice([0x200000, 0x400, 0x800, 0x200c00, 0x201000])
    e.w32(this + 0x3c, flags)
    dx = r.choice([0, 0, 1, 7, 0x1234])
    e.w16(this + 0x5c, dx) if hasattr(e, 'w16') else e.wbytes(this + 0x5c, struct.pack('<H', dx))
    for off in (0x30, 0x34, 0x38, 0x40, 0x44, 0x48):
        e.wbytes(this + off, struct.pack('<f', r.uniform(-9, 9)))
    pid = lambda: r.choice(pool)
    n24 = r.choice([0, 1, 2, 3, 5, 9])
    n28 = r.choice([0, 1, 2, 3, 4, 6, 9])

    def sM(emu, k):
        emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(0x24)))
    hook_rec(c, 0x4de7a0, 0, pop=0, this='mark', side=sM)

    def s600(emu, k):
        lg(emu, 'M600', emu.arg32(0), 0x24)
        lg(emu, 'O600', emu.arg32(1), 12)
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(0x24)))
    hook_rec(c, 0x4db600, 2, pop=8, this=True, stackmark=(0, 1), side=s600)
    hook_rec(c, 0x4dae60, 0, pop=0, this=True)

    def s970(emu, k):
        n = emu.arg32(2)
        lgarr(emu, 'b970', emu.arg32(0), n)
        lgarr(emu, 'a970', emu.arg32(1), n)
    hook_rec(c, 0x4d9970, 3, pop=12, this=True, stackmark=(0, 1), side=s970)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def s24(emu, k):
        lg(emu, 'M24', emu.arg32(1), 0x24)
        lg(emu, 'O24', emu.arg32(3), 12)
        lg(emu, 'D24', emu.arg32(4), 12)
        fill(emu, emu.arg32(0), n24, pid)

    def s28(emu, k):
        cn = emu.arg32(3)
        lg(emu, 'f28', emu.arg32(0), 1)
        lgarr(emu, 'a28', emu.arg32(1), cn)
        lg(emu, 'M28', emu.arg32(2), 0x24)
        lg(emu, 'O28', emu.arg32(8), 12)
        lg(emu, 'D28', emu.arg32(9), 12)
        lg(emu, 'M28b', emu.arg32(7), 0x24)
        emu.w32(emu.arg32(0), 0) if False else None
        fill(emu, emu.arg32(1), n28, pid)
        fill(emu, emu.arg32(4), n28, lambda: r.getrandbits(32))
        fill(emu, emu.arg32(5), n28, lambda: r.getrandbits(32))

    def s2c(emu, k):
        lgarr(emu, 'a2c', emu.arg32(1), emu.arg32(3))
        lgarr(emu, 'x2c', emu.arg32(4), emu.arg32(3))
        lgarr(emu, 'y2c', emu.arg32(5), emu.arg32(3))
        lg(emu, 'M2c', emu.arg32(2), 0x24)
        lg(emu, 'O2c', emu.arg32(7), 12)
        fill(emu, emu.arg32(0), emu.arg32(3), lambda: r.getrandbits(32))
    H = obj(c, 0x40, {0x24: pystub(c, 5, this=True, stackmark=(0, 1, 2, 3, 4), side=s24, ret=n24),
                      0x28: pystub(c, 10, this=True, stackmark=tuple(range(10)), side=s28, ret=n28, pop=40),
                      0x2c: pystub(c, 8, this=True, stackmark=tuple(range(8)), side=s2c, pop=32)}, nslots=0x40)
    # R object returned for the id
    if r.random() < 0.7:
        R = rnd(c, 0x40)
        e.w32(R + 0x18, r.choice([0, 0, pid()]))
        e.wbytes(R + 0x1c, bytes([r.choice([0, 1, 0x80])]))
        e.w32(R, r.choice([pid(), 0x9999]))
    else:
        R = 0
    Tn = obj(c, 0x20, {0x5c: pystub(c, 1, this=True, ret=R)}, nslots=0x40)
    tab = obj(c, 0x20, {}, nslots=4)
    e.w32(tab + 8, Tn)
    X = rnd(c, 0x40)
    e.w32(X + 0x1c, H)
    eng = obj(c, 0x2000, {}, nslots=4)
    e.w32(eng + 0x9b, tab)
    e.w32(eng + 0x1aa3, X)
    e.w32(0x70039c, eng)
    return [this]


S(0x4d9f90, 'pick_list_build', 'thiscall', None, ret=None, gen=g4d9f90)
