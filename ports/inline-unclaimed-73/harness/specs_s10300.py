"""specs_s10300.py - batch 103 helper caller.
0x52aae0 (stdcall, ret 8): calls 0x52a84c(a, b), returns 0
"""
from pilot import S

def _gen_52aae0(c):
    e = c.emu
    a = c.rng.getrandbits(32)
    b = c.rng.getrandbits(32)

    # Hook 0x52a84c
    def hook_52a84c(em, r):
        em.calllog.append(('52a84c', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    e.hook(0x52a84c, hook_52a84c)

    return [a, b]

S(0x52aae0, 'GUESS FUN_0052aae0 (unknown) stdcall', 'stdcall', 'eax', ret='eax', gen=_gen_52aae0,
  note='batch 103; calls 0x52a84c(a, b), returns 0')
