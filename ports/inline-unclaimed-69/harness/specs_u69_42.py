"""specs_u69_42.py - area 69, group 42 (slice 8). GUESS stubs: 0x436450, 0x4362f0, 0x4298b0 (other areas, thiscall, no args, ret 0).
The stubs log whether ECX is the spec's object (a boolean)."""
from pilot import S
from ckit import rnd


def _gen(c):
    o = rnd(c, 0x100)
    for addr, tag, eax in ((0x436450, 't436450', 0x51), (0x4362f0, 't4362f0', 0x62), (0x4298b0, 't4298b0', 0x73)):
        c.emu.hook(addr, (lambda tg, ev, ax: (lambda e, res: (e.calllog.append((tg, int(e.reg('ecx') == ev))), e.ret(eax=ax, argbytes=0))))(tag, o, eax))
    return [o]


S(0x42a480, 'chain42a480 (calls 0x436450, 0x4362f0, then 0x4298b0)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 42; three GUESS stubs (other areas)')
