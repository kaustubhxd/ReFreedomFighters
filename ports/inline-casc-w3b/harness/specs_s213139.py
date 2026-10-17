"""specs_s213139.py - batch 213139: active-entry switch with speed statistics of five tracked entities, Sonnet-w3b."""
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


def g47b8d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    crt(c, 0x634d7c, math.sqrt, 'sqrt')

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))

    def wf(addr, v):
        e.wbytes(addr, struct.pack('<f', f32(v)))
    base = rnd(c, 0x800)
    tab = rnd(c, 0x80)
    w32u(tab + 0x44, base)
    eng = rnd(c, 0x100)
    w32u(eng + 0x9b, tab)
    e.w32(0x70039c, eng)
    recs = {}
    for idx, h in ((3, 0x100), (4, 0x200), (5, 0x300), (8, 0x400), (12, 0x500)):
        for off in (0x70, 0x74, 0x78):
            wf(base + h + off, r.choice([0.0, 1.0, -2.0, 0.5, r.uniform(-9, 9)]))
        w32u(base + h + 0x6c, r.choice([0, 1, 5, 100, 0xfffffff0]))
        w32u(base + h + 0x60, r.choice([0, 3, 10, 100]))
        w32u(base + h + 0x64, r.choice([0, 3, 10, 20, 0xffffffff, 0xfffffff0]))
        if r.random() < 0.8:
            R = e.alloc(16, 4)
            w32u(R, h)
            recs[idx] = R
        else:
            recs[idx] = 0
    a = r.choice([0, 1, 2, 3, 4, 5, 6])
    flag = r.choice([0, 0, 1, 0x100, 0x101])
    this = obj(c, 0x800, {0x5a8: pystub(c, 1, this=True, ret=lambda emu, k: recs.get(emu.arg32(0), 0))}, nslots=0x180)
    w32u(this + 0x4ae, a if r.random() < 0.5 else r.choice([0, 1, 2, 3]))
    w32u(this + a * 4 + 0x49a, rb() | 1 if r.random() < 0.85 else 0)
    w32u(this + 0x650, rb() | 1 if r.random() < 0.7 else 0)
    wf(this + 0x755, r.choice([0.0, 1.0, 2.5]))
    for off in (0x712, 0x716, 0x71a, 0x71e, 0x75d, 0x761, 0x765):
        wf(this + off, r.choice([0.0, 1.0, 5.0]))

    def s477(emu, k):
        emu.wbytes(emu.reg('ecx') + 0x755, struct.pack('<f', f32(r.uniform(-5, 5))))
    hook_rec(c, 0x477740, 2, pop=8, this=True, side=s477)
    return [this, a, flag]


S(0x47b8d0, 'switch_active_entry', 'thiscall', None, ret='al', gen=g47b8d0)
