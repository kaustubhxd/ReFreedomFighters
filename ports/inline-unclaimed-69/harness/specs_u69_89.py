"""specs_u69_89.py - area 69, gameplay-core residue-8: 0x51b600 ZCarIf::opaqueCall (stdcall, one stack arg, ret 4).
Table: count at 0x701800, entries at 0x701808 (dwords). GUESS: the table entries point at three int3 bytes inside the image
(0x51b638..0x51b63d), which the spec hooks as stdcall targets (one arg, ret 4) that log whether the argument is the object
and return a random eax. The real code at those bytes never runs."""
from pilot import S
from ckit import rnd

TARGETS = [0x51b638, 0x51b639, 0x51b63a]
TARGETS2 = [0x51b63b, 0x51b63c, 0x51b63d]   # the out-of-range path jumps to the second dispatcher 0x51ad90 (count 0x701730, table 0x701738)


def _opaque(c):
    e = c.emu
    r = c.rng
    obj = rnd(c, 0x40)
    word = r.randint(0, 4)
    e.w16(obj + 0x10, word)
    n = r.randint(0, 3)
    e.w32(0x701800, n)
    for i in range(n):
        e.w32(0x701808 + 4 * i, TARGETS[i])
    m = r.randint(0, 3)
    e.w32(0x701730, m)
    for i in range(m):
        e.w32(0x701738 + 4 * i, TARGETS2[i])
    for tag, tg, cnt in (('op51b600', TARGETS, n), ('op51ad90', TARGETS2, m)):
        for i in range(cnt):
            val = r.getrandbits(32)

            def hook(e, res, i=i, val=val, tag=tag):
                e.calllog.append((tag, i, int(e.arg32(0) == obj)))
                e.ret(eax=val, argbytes=4)
            e.hook(tg[i], hook)
    # the second dispatcher's out-of-range path jumps to 0x51a7d0 (a further dispatcher, not modelled): GUESS stub, stdcall one arg, ret 4
    val7 = r.getrandbits(32)

    def hook7(e, res):
        e.calllog.append(('opA7d0', int(e.arg32(0) == obj)))
        e.ret(eax=val7, argbytes=4)
    e.hook(0x51a7d0, hook7)
    return [obj]


S(0x51b600, 'ZCarIf::opaqueCall (stdcall, one arg, ret 4)', ('regs', ['s']), None, ret='eax', gen=_opaque,
  note='u69 gameplay-core; table targets are hooked int3 bytes (GUESS)')
