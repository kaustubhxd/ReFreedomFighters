"""specs_s390.py - gap band batch 390: 0x410a00, cdecl(a, b) = 0x410a20(a, b, 1). The stream struct and out come from the
generator of batch 389 (specs_s389); the flag is fixed at 1 by the forwarder."""
from pilot import S
import specs_s389 as S389


def _gen(c):
    p, out, _flag = S389._gen(c)
    return [p, out]


S(0x410a00, 'forwarder to 0x410a20 with flag 1 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 390; calls exe 0x410a20 (batch 389)')
