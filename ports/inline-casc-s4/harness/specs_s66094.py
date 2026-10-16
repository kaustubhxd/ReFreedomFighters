"""specs_s66094.py - cascade s4 batch 66094: 0x5df176 (cold fragment of a /GS function). The spec builds the enclosing frame: ebp = STACK_TOP - 0x80 with the saved ebp, the return address and the cookie word, esi = the object, edi = a saved register."""
from pilot import S
import pe_emu
from recruits_util import rnd, clear_hooks, hook_rec


def _g5df176(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ebp = pe_emu.STACK_TOP - 0x80
    e.w32(ebp, ebp)                                   # saved ebp (restores the harness value)
    e.w32(ebp + 4, e.RET_ADDR)                        # the enclosing function's return address
    e.w32(ebp - 4, r.getrandbits(32))                 # cookie word: cookie ^ ebp, passed to the check
    for k in range(6):
        e.w32(ebp + 8 + 4 * k, r.getrandbits(32))     # the 0x18 bytes of arguments that `ret 0x18` pops
    e.w32(pe_emu.STACK_TOP - 0x200, r.getrandbits(32))  # the enclosing function's saved esi, popped after the call (the saved edi is the harness return address)
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))
    hook_rec(c, 0x5deb20, 3, this=True, pop=12, ret=r.getrandbits(32))   # (edi, 120.0, 300.0)
    obj_ = rnd(c, 0x40)
    return [obj_, r.getrandbits(32)]


S(0x5df176, 'GUESS cold fragment: call 0x5deb20 with two float constants', ('regs', ['esi', 'edi']), None, ret='eax', gen=_g5df176, note='batch66094')
