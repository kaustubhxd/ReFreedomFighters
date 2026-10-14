"""specs_u69_67.py - area 69, group 67 (slice 8): 0x65e300 (ZGeometryDecal::AddPrimArray wrapper). The helper 0x65e350 is a GUESS stub:
thiscall, two stack args, ret 8. It logs its ECX as an offset from the object and its two args (small ints), and writes its first arg at ECX."""
from pilot import S
from ckit import rnd


def _ap(c):
    e = c.emu
    r = c.rng
    o = rnd(c, 0x200)
    cnt = r.choice([0, 1, 5, 15, 16, r.randrange(0, 17)])
    e.w32(o + 0xc8, cnt)
    a = r.getrandbits(16)
    b = r.getrandbits(16)
    def stub(e, res):
        e.calllog.append(('t65e350', (e.reg('ecx') - o) & 0xffffffff, e.arg32(0), e.arg32(1)))
        e.w32(e.reg('ecx'), e.arg32(0))
        e.w32(o + 0xc8, (e.r32(o + 0xc8) + 1) & 0xffffffff)   # the helper changes the count, so the re-read after the call matters
        e.ret(argbytes=8)

    e.hook(0x65e350, stub)
    return [o, a, b]


S(0x65e300, 'addPrim65e300 (thiscall, two args, ret 8)', 'thiscall', None, ret='eax', gen=_ap,
  note='u69 group 67; helper 0x65e350 is a GUESS stub (thiscall, two args, ret 8)')
