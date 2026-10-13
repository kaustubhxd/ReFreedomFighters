"""specs_s10400.py - batch 104 helper caller.
0x6014a0 (stdcall, ret 4): calls 0x5ff8f0(arg), returns 0
"""
from pilot import S

def _gen_6014a0(c):
    e = c.emu
    arg = c.rng.getrandbits(32)

    # Hook 0x5ff8f0
    def hook_5ff8f0(em, r):
        em.calllog.append(('5ff8f0', 0, None, (em.arg32(0),)))
        em.ret(argbytes=4)

    e.hook(0x5ff8f0, hook_5ff8f0)

    return [arg]

S(0x6014a0, 'GUESS FUN_006014a0 (unknown) stdcall', 'stdcall', 'eax', ret='eax', gen=_gen_6014a0,
  note='batch 104; calls 0x5ff8f0(arg), returns 0')
