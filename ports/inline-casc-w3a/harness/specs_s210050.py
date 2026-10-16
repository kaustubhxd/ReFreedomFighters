"""specs_s210050.py - Sonnet-w3a: /GS token classifier. The cursor callback [a+0x3c] (cdecl, 5 args) writes the end cursor and a pointer into the stack buffer; the hooks log the first dword of the buffer so the NUL store is observable. The /GS check hook preserves EAX (the real one does)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _log(tag): return lambda emu, k: emu.calllog.append((tag,))


def g628a70(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, side=_log('gs'))
    cval = c.rng.choice([0, 1, 5, 100, _r(c)])
    match = c.rng.random() < 0.6
    k = c.rng.randrange(0, 4)
    bad = (cval + c.rng.choice([1, 0xffffffff])) & 0xffffffff

    def cb(emu, n):
        emu.w32(emu.arg32(1), cval if match else bad)
        buf = emu.r32(emu.arg32(3))
        emu.w32(buf, 0x41424344)
        emu.w32(emu.arg32(3), buf + k)
    cbp = pystub(c, 5, ret=_r(c), pop=0, stackmark=(1, 3, 4), side=cb)

    def d(emu, kk):
        emu.calllog.append(('buf', emu.r32(emu.arg32(0))))
    r1 = c.rng.choice([0, 1, 0x100])
    r2 = c.rng.choice([0xffffffff, 0, 1, 3, 7])
    hook_rec(c, 0x62c5b0, 2, ret=r1, pop=0, stackmark=(0,), side=d)
    hook_rec(c, 0x628c10, 1, ret=r2, pop=0, stackmark=(0,), side=d)
    for i in range(8): c.emu.w32(0x6f4408 + 4 * i, _r(c))
    a = rnd(c, 0x60); c.emu.w32(a + 0x3c, cbp); c.emu.w32(a + 0x44, c.rng.choice([0, 2, 2, 3]))
    return [a, c.rng.choice([0, 1, 7, _r(c)]), cval]


S(0x628a70, 'gs_token_classifier', 'cdecl', None, ret='eax', gen=g628a70, note='batch210050')
