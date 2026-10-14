"""specs_s35004.py - 0x511ad0 (no arguments, 0x2fc8-byte frame). All callees except the 1-byte 0x4690b0 are hooked with recorders that log (callee, ECX relative to the
frame base, stack arguments) into the call log; the base is derived from the first buffer call (0x514940 at EBP-0x2dc) so port and original compare on frame layout."""
from pilot import S
from recruits_util import clear_hooks


def _g511ad0(c):
    clear_hooks(c)
    e = c.emu
    base = [None]

    def mk(addr, nargs):
        def h(em, rr):
            ecx = em.reg('ecx')
            if base[0] is None:
                base[0] = ecx + 0x2dc
            em.calllog.append(('c', addr, (ecx - base[0]) & 0xffffffff, tuple(em.arg32(i) for i in range(nargs))))
            em.ret(eax=0, argbytes=4 * nargs)
        e.hook(addr, h)
    for a in (0x514940, 0x517050, 0x51b790, 0x51f3e0, 0x520110):
        mk(a, 3)
    for a in (0x511950, 0x511a00, 0x512070, 0x51f4c0):
        mk(a, 0)
    return []


S(0x511ad0, 'GUESS construct/use/destroy five frame objects', 'cdecl', None, ret=None, gen=_g511ad0, note='batch35004')
