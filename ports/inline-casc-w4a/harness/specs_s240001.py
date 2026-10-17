"""specs_s240001.py - Sonnet-w4a: small CRT helpers and funclets (callees hooked)."""
import pe_emu
import pilot as pilot_mod
import recruits_util
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g633170(c):
    clear_hooks(c)
    r = c.rng
    rec = rnd(c, 0x40)
    st = pystub(c, 2, pop=0, ret=lambda em, k: _w(c))
    c.emu.w32(rec + 0x24, st)
    return [_w(c), rec]


def _setck(c, ck):
    c.emu.w32(0x6f5630, ck)


def _g6344f2(c):
    clear_hooks(c)
    _setck(c, _w(c))
    return [_w(c)]


def _g633ed4(c):
    clear_hooks(c)
    r = c.rng
    ck = _w(c)
    if r.random() < 0.2:
        ck &= ~0x1f    # shift 0 case
    _setck(c, ck)
    # x == -1 iff cookie ^ [0x725498] == -1
    c.emu.w32(0x725498, (~ck & 0xffffffff) if r.random() < 0.5 else _w(c))
    hook_rec(c, 0x634e7e, 1, pop=0, ret=lambda em, k: r.choice([0, 0, _w(c)]))
    hook_rec(c, 0x634e78, 2, pop=0, ret=lambda em, k: r.choice([0, 0, _w(c)]))
    return [_w(c)]


def _g633f0f(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633ed4, 1, pop=0, ret=lambda em, k: r.choice([0, _w(c)]))
    return [_w(c)]


def _g633e8f(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x725494, _w(c))
    hook_rec(c, 0x634cb5, 0, pop=0, ret=lambda em, k: r.choice([0, 1, 1]))
    a = _w(c)
    if r.random() < 0.5:
        a &= ~0xff
    return [a]


def _g634823(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634e8a, 3, pop=0, ret=lambda em, k: r.choice([0, 0, 22, _w(c)]))
    # noreturn fatal handler: record the call, then END the run as if the function had returned (w3c technique)
    def fatal(em, res):
        em.calllog.append(('fatal', em.arg32(0)))
        em.mu.reg_write(pe_emu.REGS['eax'], _w(c))
        for k, v in pilot_mod.SENTINELS.items():
            em.mu.reg_write(pe_emu.REGS[k], v)
        em.mu.reg_write(pe_emu.REGS['ebp'], pe_emu.STACK_TOP - 0x80)
        em.mu.reg_write(pe_emu.REGS['esp'], pe_emu.STACK_TOP - 0x200)
        em.mu.reg_write(pe_emu.UC_X86_REG_EIP, em.RET_ADDR)
    c.emu.hook(0x634879, fatal)
    recruits_util._HOOKED.add(0x634879)
    return []


def _gfunclet(c):
    clear_hooks(c)
    e = c.emu
    ebp = pe_emu.STACK_TOP - 0x80
    q = rnd(c, 0x40)
    p = rnd(c, 0x40)
    e.w32(p + 0x10, q)
    e.w32(ebp - 0x10, p)
    e.w32(ebp + 8, _w(c))
    hook_rec(c, 0x4690b0, 2, pop=0, ret=lambda em, k: _w(c))
    return []


S(0x633170, 'GUESS call rec->fn(rec->arg, a)', 'cdecl', None, ret='eax', gen=_g633170, note='batch240001')
S(0x6344f2, 'GUESS cookie rotate encode', 'cdecl', None, ret='eax', gen=_g6344f2, note='batch240001')
S(0x633ed4, 'GUESS onexit table register', 'cdecl', None, ret='eax', gen=_g633ed4, note='batch240001')
S(0x633f0f, 'GUESS onexit registered bool', 'cdecl', None, ret='eax', gen=_g633f0f, note='batch240001')
S(0x633e8f, 'GUESS swap out global when flag', 'cdecl', None, ret='eax', gen=_g633e8f, note='batch240001')
S(0x634823, 'GUESS controlfp_s check fatal', 'cdecl', None, ret='eax', gen=_g634823, note='batch240001')
S(0x6665c0, 'GUESS funclet 4690b0 a', 'cdecl', None, ret='eax', gen=_gfunclet, note='batch240001')
S(0x666790, 'GUESS funclet 4690b0 b', 'cdecl', None, ret='eax', gen=_gfunclet, note='batch240001')
