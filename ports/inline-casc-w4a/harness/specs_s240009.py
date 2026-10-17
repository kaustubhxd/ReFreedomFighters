"""specs_s240009.py - Sonnet-w4a: atexit machinery start-up."""
import pe_emu
import pilot as pilot_mod
import recruits_util
from pilot import S
from recruits_util import clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _cell(c, cell, nargs, ret):
    e = c.emu
    a = e.r32(cell)

    def h(em, res):
        em.calllog.append(('imp', cell, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret(em), argbytes=4 * nargs)
    e.stubs[a] = (e.stubs[a][0], h)


def _g634432(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fn = pystub(c, 0, ret=lambda em, k: _w(c))
    mode = r.random()
    _cell(c, 0x676060, 1, lambda em: 0 if r.random() < 0.1 else _w(c) | 1)
    seq = {'n': 0}

    def gp(em):
        seq['n'] += 1
        if seq['n'] % 3 == 1:
            return fn if mode < 0.8 else r.choice([0, fn])
        return r.choice([0, _w(c) | 1, _w(c) | 1])
    _cell(c, 0x6760b4, 2, gp)
    _cell(c, 0x676064, 4, lambda em: r.choice([0, _w(c) | 1]))
    hook_rec(c, 0x634d46, 3, pop=0, ret=lambda em, k: _w(c))
    hook_rec(c, 0x634aae, 1, this=True, pop=4, ret=lambda em, k: _w(c))
    hook_rec(c, 0x6344f2, 1, pop=0, ret=lambda em, k: _w(c))
    hook_rec(c, 0x633f0f, 1, pop=0, ret=lambda em, k: _w(c))

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
    e.w32(0x7257f4, _w(c)); e.w32(0x7257f8, _w(c)); e.w32(0x7257fc, _w(c))
    return []


S(0x634432, 'GUESS atexit machinery init', 'cdecl', None, ret='eax', gen=_g634432, note='batch240009')
