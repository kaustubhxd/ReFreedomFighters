"""specs_u69_41.py - area 69, group 41 (slice 8). GUESS stubs: 0x5706f0, 0x563a50, 0x5709d0 (other areas, thiscall, no args, ret 0).
The stubs log whether ECX is the spec's object (a boolean). The byte at self+0x1a3 decides whether 0x563a50 is called."""
from pilot import S
from ckit import rnd


def _gen(c):
    o = rnd(c, 0x200)
    c.emu.w32(o + 0x1a0, c.rng.choice([0, 0x01000000, 0x00000000, 0xff000000]))  # byte +0x1a3 is zero or non-zero
    for addr, tag, eax in ((0x5706f0, 't5706f0', 0x21), (0x563a50, 't563a50', 0x32), (0x5709d0, 't5709d0', 0x43)):
        c.emu.hook(addr, (lambda tg, ev: (lambda e, res: (e.calllog.append((tg, int(e.reg('ecx') == ev))), e.ret(eax=eax, argbytes=0))))(tag, o))
    return [o]


S(0x570880, 'chain570880 (CSoundMenu::Init-like chain; calls 0x5706f0, 0x563a50 if byte +0x1a3, then 0x5709d0)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 41; three GUESS stubs (other areas)')
