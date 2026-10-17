"""specs_s240006.py - Sonnet-w4a: CRT onexit table initialisation."""
import pe_emu
import pilot as pilot_mod
import recruits_util
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _g633d6e(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x6f5630, _w(c))
    for i in range(3):
        e.w32(0x725498 + 4 * i, _w(c))
        e.w32(0x7254a4 + 4 * i, _w(c))
    hook_rec(c, 0x634cb5, 0, pop=0, ret=lambda em, k: r.choice([0, 1, 1]))
    hook_rec(c, 0x634e72, 1, pop=0, ret=lambda em, k: r.choice([0, 0, 1, _w(c)]))

    def fatal(em, res):
        em.calllog.append(('fatal', em.arg32(0)))
        em.mu.reg_write(pe_emu.REGS['eax'], _w(c))
        for k, v in pilot_mod.SENTINELS.items():
            em.mu.reg_write(pe_emu.REGS[k], v)
        em.mu.reg_write(pe_emu.REGS['ebp'], pe_emu.STACK_TOP - 0x80)
        em.mu.reg_write(pe_emu.REGS['esp'], pe_emu.STACK_TOP - 0x204)
        em.mu.reg_write(pe_emu.UC_X86_REG_EIP, em.RET_ADDR)
    c.emu.hook(0x634879, fatal)
    recruits_util._HOOKED.add(0x634879)
    return [r.choice([0, 0, 1, 1, 2, 5, _w(c)])]


S(0x633d6e, 'GUESS onexit tables init', 'cdecl', None, ret='eax', gen=_g633d6e, note='batch240006')
