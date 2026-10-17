"""specs_s240016.py - Sonnet-w4a: __report_gsfailure variant 0x633f4c."""
import pe_emu
import pilot as pilot_mod
import recruits_util
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _gen(c):
    clear_hooks(c)
    e = c.emu
    ebp = pe_emu.STACK_TOP - 0x80
    for off in (0, 4, 8, 0xc):
        e.w32(ebp + off, _w(c))
    for g in [0x725508, 0x6f5630, 0x6f562c] + list(range(0x7254b8, 0x7254e0, 4)) + list(range(0x725594, 0x7255d4, 4)):
        e.w32(g, _w(c))
    hook_rec(c, 0x663bc2, 1, pop=4, ret=lambda em, k: 0)   # the non-zero path is the int 0x29 process-termination trap: not exercised

    def fatal(em, res):
        eb = em.reg('ebp')    # log the two cookie words the function stored into its own frame
        em.calllog.append(('fatal', em.arg32(0), em.r32(eb - 8), em.r32(eb - 4)))
        em.mu.reg_write(pe_emu.REGS['eax'], _w(c))
        for k, v in pilot_mod.SENTINELS.items():
            em.mu.reg_write(pe_emu.REGS[k], v)
        em.mu.reg_write(pe_emu.REGS['ebp'], pe_emu.STACK_TOP - 0x80)
        em.mu.reg_write(pe_emu.REGS['esp'], pe_emu.STACK_TOP - 0x200)
        em.mu.reg_write(pe_emu.UC_X86_REG_EIP, em.RET_ADDR)
    c.emu.hook(0x633f24, fatal)
    recruits_util._HOOKED.add(0x633f24)
    return [_w(c), _w(c), _w(c), _w(c), _w(c), _w(c)]


S(0x633f4c, 'GUESS __report_gsfailure 2', ('regs', ['eax', 'ecx', 'edx', 'ebx', 'esi', 'edi']), None, ret=None, gen=_gen, note='batch240016')
