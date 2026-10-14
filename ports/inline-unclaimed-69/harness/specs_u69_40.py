"""specs_u69_40.py - area 69, group 40 (slice 8). Four GUESS stubs: 0x564e40, 0x56bd90, 0x562440, 0x571f20 (other areas, thiscall, no args, ret 0).
Each stub logs whether ECX is the spec's object (a boolean), never the pointer."""
from pilot import S
from ckit import rnd


def _stub(addr, tag, o, eax):
    return (addr, lambda e, res: (e.calllog.append((tag, int(e.reg('ecx') == o))), e.ret(eax=eax, argbytes=0)))


def _gen(a_addr, a_tag, b_addr, b_tag):
    def g(c):
        o = rnd(c, 0x100)
        for addr, fn in (_stub(a_addr, a_tag, o, 0x11), _stub(b_addr, b_tag, o, 0x2b)):
            c.emu.hook(addr, fn)
        return [o]
    return g


S(0x56bd80, 'chain56bd80 (CLoadMenu::Load2 per GC map; calls 0x564e40, then 0x56bd90)', 'thiscall', None, ret='eax',
  gen=_gen(0x564e40, 't564e40', 0x56bd90, 't56bd90'), note='u69 group 40; 0x564e40 and 0x56bd90 are GUESS stubs')
S(0x571f00, 'chain571f00 (CSoundMenu::Init per GC map; calls 0x562440, then 0x571f20)', 'thiscall', None, ret='eax',
  gen=_gen(0x562440, 't562440', 0x571f20, 't571f20'), note='u69 group 40; 0x562440 and 0x571f20 are GUESS stubs')
