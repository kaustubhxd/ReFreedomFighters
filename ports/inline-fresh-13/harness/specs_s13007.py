"""specs_s13007.py - fresh-13 batch 7: 0x517050 GUESS ctor. Thiscall, 3 stack args (ret 0xc), returns this. Base ctor
0x514940 (3 args) and member ctor 0x5249c0 are logged hooks; RegisterZMsg (engine db slot 0x114, 4 args) is a logged
stub returning a random 32-bit id (the port keeps the word)."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=8)
    rid = r.getrandbits(32)
    db = vobj(c, 0x40, {0x114: logstub(c, log, 4, 3, ret=rid)})
    sysobj = rnd(c, 0x100)
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(0x70039c, sysobj)
    loghook(c, log, 0x514940, 3, 1)
    loghook(c, log, 0x5249c0, 0, 2)
    me = rnd(c, 0x1660)
    flush(c)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x517050, 'GUESS ctor 0x517050 (vtable 0x69ec64)', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13007; base/member ctors and RegisterZMsg logged')
