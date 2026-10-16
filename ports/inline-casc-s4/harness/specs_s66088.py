"""specs_s66088.py - cascade s4 batch 66088: 0x57b610 (prepare, slot 0x350 child call, then slot 0x74 of the engine object; the return value keeps the upper EAX bits of slot 0x74)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g57b610(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x562e90, 2, this=True, pop=8, ret=r.getrandbits(32),
             side=lambda emu, k: emu.calllog.append(('prepare', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    # slot 0x350 takes (stack local zeroed by the function, [this+0x44], 0x10000) and pops 12; args are (0x10000, 0, [this + 0x44])
    tail = obj(c, 0x20, {0x350: pystub(c, 3, this=True, pop=12,
                                       side=lambda emu, k: emu.calllog.append(('child-call', emu.reg('ecx'), emu.arg32(0), emu.arg32(1), emu.arg32(2))))}, nslots=0x351 // 4)
    me = obj(c, 0x60, {0x84: pystub(c, 0, ret=tail, this=True, pop=0)}, nslots=0x85 // 4)
    final = obj(c, 0x20, {0x74: pystub(c, 0, ret=r.getrandbits(32), this=True, pop=0,
                                       side=lambda emu, k: emu.calllog.append(('finish', emu.reg('ecx'))))})
    sysobj(c, slots={0xbc: pystub(c, 0, ret=final, this=True, pop=0,
                                  side=lambda emu, k: emu.calllog.append(('engine', emu.reg('ecx'))))}, table_size=0x20)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x57b610, 'GUESS prepare and dispatch nested engine objects', 'thiscall', None, ret='eax', gen=_g57b610, note='batch66088')
