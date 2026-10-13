"""specs_s13005.py - fresh-13 batch 5: 0x5faad0 GUESS constructor. Thiscall, returns this. 0x606220 (member ctor) and
0x6014a0 (CHostInterface::alloc, 1 arg, ret 4) are logged hooks; alloc returns a fresh random 16-byte block (its address
also differs per call, so a header written to the wrong node is caught)."""
from pilot import S
from fr13 import Log, loghook, rnd, clear_hooks, flush


def _gen(c):
    clear_hooks(c)
    log = Log(c, cap=8)
    nodes = [rnd(c, 16), rnd(c, 16)]
    loghook(c, log, 0x606220, 0, 1)
    loghook(c, log, 0x6014a0, 1, 2, ret=lambda e: nodes[min(1, sum(1 for i in range(e.r32(log.base)) if e.r32(log.base + 4 + 24 * i) == 2) - 1)])
    me = rnd(c, 0x140)
    flush(c)
    return [me]


S(0x5faad0, 'GUESS ctor 0x5faad0 (vtable 0x6b92a4)', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13005; member ctor and alloc logged')
