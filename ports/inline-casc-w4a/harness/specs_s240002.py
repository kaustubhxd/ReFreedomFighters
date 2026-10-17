"""specs_s240002.py - Sonnet-w4a: PE section lookup, startup info, security cookie check."""
import struct
import pe_emu
import pilot as pilot_mod
import recruits_util
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g633cbc(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x400)
    lf = r.choice([0x40, 0x80, 0xc0, 0x100])
    e.w32(base + 0x3c, lf)
    nopt = r.choice([0, 0x60, 0xe0, 0xf0, 2 * r.randrange(0x70)])
    nsec = r.choice([0, 1, 2, 3, 5, 8])
    nt = base + lf
    e.wbytes(nt + 0x14, struct.pack('<H', nopt))
    e.wbytes(nt + 6, struct.pack('<H', nsec))
    sec = nt + 0x18 + nopt
    va = r.randrange(0x1000, 0x4000, 0x1000)
    spans = []
    for i in range(nsec):
        vs = r.choice([0, 0x10, 0x800, 0x1000, 0x1800, _w(c) & 0xfff])
        if r.random() < 0.1:
            va0 = r.choice([0xfffff000, 0xffffff00, _w(c)])
        else:
            va0 = va
        e.w32(sec + 8, vs)
        e.w32(sec + 0xc, va0)
        spans.append((va0, vs))
        sec += 0x28
        va += r.choice([0x1000, 0x2000, 0x800])
    if spans and r.random() < 0.85:
        va0, vs = r.choice(spans)
        rva = (va0 + r.choice([-1, 0, 1, vs - 1, vs, vs + 1, r.randrange(max(vs, 1))])) & 0xffffffff
    else:
        rva = r.choice([0, 0xfff, 0x1000, _w(c), 0xffffffff])
    return [base, rva]


def _g634994(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634d10, 3, pop=0, stackmark=(0,), ret=lambda em, k: _w(c))

    def h(em, res):
        p = em.arg32(0)
        em.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x44)))
        if r.random() < 0.5:
            em.w32(p + 0x2c, em.r32(p + 0x2c) | 1)
        else:
            em.w32(p + 0x2c, em.r32(p + 0x2c) & ~1)
        em.ret(eax=_w(c), argbytes=4)
    a = e.r32(0x676050)
    e.stubs[a] = (e.stubs[a][0], h)
    return []


def _fatal(c, nargs_stack, tag):
    def fatal(em, res):
        em.calllog.append((tag, em.reg('ecx')))
        em.mu.reg_write(pe_emu.REGS['eax'], _w(c))
        for k, v in pilot_mod.SENTINELS.items():
            em.mu.reg_write(pe_emu.REGS[k], v)
        em.mu.reg_write(pe_emu.REGS['ebp'], pe_emu.STACK_TOP - 0x80)
        em.mu.reg_write(pe_emu.REGS['esp'], pe_emu.STACK_TOP - 0x200)
        em.mu.reg_write(pe_emu.UC_X86_REG_EIP, em.RET_ADDR)
    return fatal


def _g633654(c):
    clear_hooks(c)
    r = c.rng
    ck = _w(c)
    c.emu.w32(0x6f5630, ck)
    c.emu.hook(0x633f4c, _fatal(c, 0, 'fatal'))
    recruits_util._HOOKED.add(0x633f4c)
    return [ck if r.random() < 0.5 else (ck ^ (1 << r.randrange(32)) if r.random() < 0.5 else _w(c))]


S(0x633cbc, 'GUESS PE section lookup by rva', 'cdecl', None, ret='eax', gen=_g633cbc, note='batch240002')
S(0x634994, 'GUESS startup show window', 'cdecl', None, ret='eax', gen=_g634994, note='batch240002')
S(0x633654, 'GUESS security cookie check', 'fastcall', None, ret=None, gen=_g633654, note='batch240002')
