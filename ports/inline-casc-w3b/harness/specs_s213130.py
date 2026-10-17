"""specs_s213130.py - batch 213130: attachment direction update (two position lookups, vector subtract, SSE length + x87 normalise, matrix, receiver loop), Sonnet-w3b."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def crt(c, addr, fn, name):
    def side(em, k):
        a = em.reg('xmm0') & ((1 << 64) - 1)
        x = struct.unpack('<d', struct.pack('<Q', a))[0]
        em.calllog.append((name, a))
        try:
            z = fn(x)
        except (ValueError, OverflowError):
            z = math.nan
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    hook_rec(c, addr, 0, side=side)


def g5b88f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    crt(c, 0x634d7c, math.sqrt, 'sqrt')

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    def fv():
        return f32(r.choice([0.0, 0.0, 1.0, -1.0, 2.0, 0.5, -0.5, 3.0, r.uniform(-9, 9), r.uniform(-1e-3, 1e-3), float('nan') if r.random() < 0.1 else 1.5]))

    def vec3():
        return struct.pack('<fff', fv(), fv(), fv())
    base = struct.pack('<fff', *[f32(r.choice([0.0, 1.0, -2.0, 0.5, r.uniform(-9, 9)])) for _ in range(3)])
    same = r.random() < 0.3

    def s80(emu, k):
        v = base if (same and k == 0) else vec3()
        if same and k == 1:
            v = base
        emu.wbytes(emu.arg32(1), v)
    A = obj(c, 0x40, {0x80: pystub(c, 2, this=True, stackmark=(0,), side=s80)}, nslots=0x40)
    B = obj(c, 0x40, {0x80: pystub(c, 2, this=True, stackmark=(0,), side=s80)}, nslots=0x40)
    X = obj(c, 0x40, {0x7c: pystub(c, 2, this=True, stackmark=(1,), side=lambda emu, k: (lg(emu, 'xm', emu.arg32(0), 36), lg(emu, 'xz', emu.arg32(1), 12)))}, nslots=0x40)
    ida, idb = 0x1111 + (rb() & 0xff), 0x5555 + (rb() & 0xff)
    T = obj(c, 0x40, {0x58: pystub(c, 1, this=True, ret=lambda emu, k: A if emu.arg32(0) == ida else (B if emu.arg32(0) == idb else X))}, nslots=0x60)
    E = obj(c, 0x100, {0x6c: pystub(c, 1, this=True), 0x84: pystub(c, 1, this=True, side=lambda emu, k: lg(emu, 'e84', emu.arg32(0), 12))}, nslots=0x60)
    O = obj(c, 0x100, {0x7c: pystub(c, 2, this=True, stackmark=(1,), side=lambda emu, k: (lg(emu, 'om', emu.arg32(0), 36), lg(emu, 'oz', emu.arg32(1), 12))),
                       0x88: pystub(c, 1, this=True, side=lambda emu, k: lg(emu, 'o88', emu.arg32(0), 12)),
                       0x8c: pystub(c, 1, this=True, side=lambda emu, k: lg(emu, 'o8c', emu.arg32(0), 12))}, nslots=0x60)
    nit = r.choice([0, 1, 2, 3])
    cnt = [0]

    def s5c(emu, k):
        cnt[0] += 1
        emu.w32(emu.arg32(0), 1 + (rb() & 0xff) if cnt[0] <= nit else 0)
    It = obj(c, 0x40, {0x4c: pystub(c, 1, this=True, stackmark=(0,), side=lambda emu, k: emu.w32(emu.arg32(0), 7)),
                       0x5c: pystub(c, 1, this=True, stackmark=(0,), side=s5c, ret=lambda emu, k: rb())}, nslots=0x60)
    this = rnd(c, 0x200)
    on = r.random() < 0.6
    w32u(this + 0xde, 1 if on else 0)
    w32u(this + 0xe6, 0 if (not on and r.random() < 0.3) else E)
    w32u(this + 0x7e, O)
    w32u(this + 0x4c, 0 if r.random() < 0.3 else It)
    w32u(this + 0x50, ida)
    w32u(this + 0x54, idb)
    eng = rnd(c, 0x100)
    w32u(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    hook_rec(c, 0x5b8d80, 0, pop=0, this=True)

    def sde(emu, k):
        lg(emu, 'de_dir', emu.reg('edx'), 12)
        lg(emu, 'de_up', emu.arg32(0), 12)
        emu.wbytes(emu.reg('ecx'), struct.pack('<9f', *[f32(r.uniform(-1, 1)) for _ in range(9)]))
    hook_rec(c, 0x4de040, 1, pop=4, this=True, stackmark=(0,), side=sde)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x5b88f0, 'attachment_dir_update', 'thiscall', None, ret=None, gen=g5b88f0)
