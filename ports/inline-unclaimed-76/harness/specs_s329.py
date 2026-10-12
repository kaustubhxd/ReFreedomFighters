"""specs_s329.py - gap band, batch 329: 0x605100 (fastcall-style in the port: ECX passes through to the pushed argument). The exe helper
0x603e40 is hooked by address (recorded: its ECX and its one stack argument). The incoming ECX and the stack words are random."""
from pilot import S


def _rec(em, r):
    # 0x603e40 (thiscall, one stack argument, ret 4): recorded by address
    em.calllog.append(('h603e40', 0, em.reg('ecx'), (em.arg32(0),)))
    em.ret(eax=0x5a5a5a5a, argbytes=4)


def _gen(c):
    e = c.emu
    e.hook(0x603e40, _rec)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]   # ECX (the incoming value), a, b


S(0x605100, 'fwd605100 (GUESS)', 'thiscall', None, ret='eax', gen=_gen, note='batch329; ret 8; helper 0x603e40 hooked')
