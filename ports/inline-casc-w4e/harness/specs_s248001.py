"""specs_s248001.py - Sonnet-w4e hand specs."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain

def g43df70(c):
    clear_hooks(c)
    r = c.rng; em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    T = rnd(c, 0x40); P = rnd(c, 0x40)
    em.w32(T + 8, P)
    hook_rec(c, 0x4da1d0, 1, ret=R, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('h1d0', emu.reg('ecx'), emu.arg32(0))))
    return [T]

def g465650(c):
    clear_hooks(c)
    r = c.rng
    R = lambda emu, k: r.getrandbits(32)
    T = rnd(c, 0x40)
    hook_rec(c, 0x466220, 0, ret=R, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('h220', emu.reg('ecx'))))
    return [T]

S(0x43df70, 'tail-call wrapper 0x43df70', 'thiscall', None, ret='eax', gen=g43df70, note='batch248001')
S(0x465650, 'init wrapper 0x465650', 'thiscall', None, ret='eax', gen=g465650, note='batch248001')
