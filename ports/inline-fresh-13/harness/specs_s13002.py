"""specs_s13002.py - fresh-13 batch 2: 0x5b2550 ZActionControlMap::ZActionControlMap(). Thiscall, returns this. Every
callee is logged in one call log (fr13.Log): base ctor 0x469870 (this, no args), RegisterZMsg on *(0x70039c)+0x9b
slot 0x114 (4 args, ret 0x10, random 32-bit result of which the port keeps the low word), operator new 0x41e290 (cdecl,
1 arg; returns a heap block, or 0 in 30% of cases), 0x4d83b0 (thiscall, 3 args, random result), *(0x70039c) slot 0x1a4
(1 arg). *(0x7003b8) is random."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=32)
    ids = [r.getrandbits(32) for _ in range(8)]
    db = vobj(c, 0x40, {0x114: logstub(c, log, 4, 2, ret=lambda e: ids[(e.r32(log.base) - 1) % 8])})
    sysobj = vobj(c, 0x200, {0x1a4: logstub(c, log, 1, 5)})
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(0x7003b8, r.getrandbits(32))
    mem = rnd(c, 0x108) if r.random() < 0.7 else 0
    loghook(c, log, 0x469870, 0, 1)
    loghook(c, log, 0x41e290, 1, 3, ret=mem, this=False, pop=False)
    loghook(c, log, 0x4d83b0, 3, 4, ret=r.getrandbits(32))
    me = rnd(c, 0x280)
    flush(c)
    return [me]


S(0x5b2550, 'ZActionControlMap::ZActionControlMap', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13002; base ctor, 8 RegisterZMsg, new + 0x4d83b0, sys slot 0x1a4 logged')
