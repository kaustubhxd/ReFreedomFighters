"""specs_s34135.py - 0x4d5ba0: hooked 0x4d6520 (3 args, ret 0xc; the buffer argument is a stack local, marked) filling 0x1c bytes with prepared dwords at +0xa and +0xe (equal in a third) and returning low byte 0/1 (success in three quarters); /GS check 0x633654 an argument-less recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))  # the real check leaves eax (the result) alone
    v = [r.getrandbits(32) for _ in range(4)]
    if r.random() < 0.5:
        v[2], v[3] = v[0], v[1]
    elif r.random() < 0.5:
        v[2] = v[0]
    elif r.random() < 0.5:
        v[3] = v[1]
    st = {'n': 0}

    def fill(em, k):
        i = st['n'] % 2
        st['n'] += 1
        buf = em.arg32(1)
        em.wbytes(buf + 0xa, v[2 * i + 1].to_bytes(4, 'little') + v[2 * i].to_bytes(4, 'little'))

    ok = [r.random() < 0.75, r.random() < 0.8]
    hook_rec(c, 0x4d6520, 3, this=True, ret=lambda em, k: (r.getrandbits(24) << 8 | 1) if ok[min(k, 1)] else (r.getrandbits(24) << 8), stackmark=(1,), side=fill)
    me = rnd(c, 0x20)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x4d5ba0, 'GUESS compare two parsed entries', 'thiscall', None, ret='al', gen=_g, note='batch34135')
