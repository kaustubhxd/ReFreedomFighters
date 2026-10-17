"""specs_s240019.py - Sonnet-w4a: 0x63379b CRT main sequence."""
import pe_emu
import pilot as pilot_mod
import recruits_util
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub, seh_chain, STACK_LO, STACK_HI


def _w(c):
    return c.rng.getrandbits(32)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x6f5630, _w(c))
    head0 = seh_chain(c, r.choice([0, 1, 2]))

    def sr(em, k):
        a = em.r32(pe_emu.TEB)
        if a == 0xffffffff:
            em.calllog.append(('seh', 'end'))
        else:
            nxt = em.r32(a)
            em.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, em.r32(a + 4), em.r32(a + 8), em.r32(a + 0xc)))

    def end_run(em, tag):
        em.calllog.append((tag, em.arg32(0)))
        em.w32(pe_emu.TEB, head0)    # the run ends here: the dead frame's record is unlinked on both sides
        em.mu.reg_write(pe_emu.REGS['eax'], _w(c))
        for k, v in pilot_mod.SENTINELS.items():
            em.mu.reg_write(pe_emu.REGS[k], v)
        em.mu.reg_write(pe_emu.REGS['ebp'], pe_emu.STACK_TOP - 0x80)
        em.mu.reg_write(pe_emu.REGS['esp'], pe_emu.STACK_TOP - 0x200)
        em.mu.reg_write(pe_emu.UC_X86_REG_EIP, em.RET_ADDR)

    def fatal(em, res):
        sr(em, 0)
        end_run(em, 'fatal')
    c.emu.hook(0x634879, fatal)
    recruits_util._HOOKED.add(0x634879)

    def exitf(em, res):
        sr(em, 0)
        end_run(em, 'exit')
    c.emu.hook(0x634d5e, exitf)
    recruits_util._HOOKED.add(0x634d5e)

    ok = lambda p: (lambda em, k: 1 if r.random() < p else 0)
    # entry state of the run-once flag: 0 first start, 1 re-entry (fatal), 2 or other = already initialised
    e.w32(0x725490, r.choice([0, 0, 0, 1, 2, 2, _w(c)]))
    hook_rec(c, 0x633d35, 1, pop=0, side=sr, ret=lambda em, k: 1 if r.random() < 0.9 else r.choice([0, 0x100]))
    hook_rec(c, 0x633d00, 0, pop=0, side=sr, ret=lambda em, k: r.choice([0, 1, 0x101, _w(c)]))
    hook_rec(c, 0x634e3c, 2, pop=0, side=sr, ret=lambda em, k: r.choice([0, 0, 0, 5]))
    hook_rec(c, 0x634e36, 2, pop=0, side=sr, ret=lambda em, k: _w(c))
    def h8f(em, res):    # only the low byte of the argument is defined (the exe pushes a dword whose upper bytes are stack junk)
        sr(em, 0)
        em.calllog.append(('h633e8f', em.arg32(0) & 0xff))
        em.ret(eax=_w(c), argbytes=0)
    c.emu.hook(0x633e8f, h8f)
    recruits_util._HOOKED.add(0x633e8f)
    hold = [rnd(c, 4), rnd(c, 4)]
    fn = pystub(c, 3, pop=12, side=sr, ret=lambda em, k: _w(c))
    for h in hold:
        e.w32(h, r.choice([0, fn, fn]))
    hook_rec(c, 0x63486d, 0, pop=0, ret=lambda em, k: hold[0])
    hook_rec(c, 0x634873, 0, pop=0, ret=lambda em, k: hold[1])
    hook_rec(c, 0x633e05, 1, pop=0, side=sr, ret=lambda em, k: r.choice([0, 1, 1, 0x101]))
    hook_rec(c, 0x634aae, 0, this=True, pop=0, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x634e54, 1, pop=0, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x634994, 0, pop=0, side=sr, ret=lambda em, k: r.choice([0, 1, 5, 10, _w(c)]))
    hook_rec(c, 0x634e30, 0, pop=0, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x41c9c0, 4, pop=16, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x6349c7, 0, pop=0, side=sr, ret=lambda em, k: r.choice([0, 1, 1, 0x100]))
    hook_rec(c, 0x634e48, 0, pop=0, side=sr, ret=lambda em, k: _w(c))
    hook_rec(c, 0x633eac, 2, pop=0, side=sr, ret=lambda em, k: _w(c))
    return []


S(0x63379b, 'GUESS CRT main sequence', 'cdecl', None, ret='eax', gen=_gen, note='batch240019')
