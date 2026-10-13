"""specs_s13021.py - fresh-13 batch 21: 0x44b310 ZSNDOBJ::ZSNDOBJ. Thiscall (info, name, geom), ret 0xc, returns this.
Base ctor 0x43de40 (3 args) and SetControl 0x4dc630 (2 args) are logged hooks; db slots 0x114 (4 args, random 32-bit
result), 0x2c (random bool, 0x100 = al 0), 0x4c (1 arg) logged; sound system sys+0x1a9f is 0 in 15% of inputs, its
slot 0x44 returns a random 0x90-byte record (or, rarely, `this` itself so the re-addressing through +0x18 matters)."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=16, width=6)
    loghook(c, log, 0x43de40, 3, 1)
    loghook(c, log, 0x4dc630, 2, 2)
    db = vobj(c, 0x120, {0x114: logstub(c, log, 4, 3, ret=r.getrandbits(32)),
                         0x2c: logstub(c, log, 0, 4, ret=r.choice([0, 0, 0, 1, 0x100])),
                         0x4c: logstub(c, log, 1, 5, ret=r.getrandbits(32))})
    me = rnd(c, 0x100)
    rec = rnd(c, 0x90)
    snd = vobj(c, 0x50, {0x44: logstub(c, log, 0, 6, ret=r.choice([rec, rec, rec, rec, me]))})
    sysobj = c.emu.alloc(0x1aa8, 4)
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(sysobj + 0x1a9f, 0 if r.random() < 0.15 else snd)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(me + 8, r.getrandbits(32))
    flush(c)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x44b310, 'ZSNDOBJ::ZSNDOBJ', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13021; base ctor, SetControl, db and sound slots logged')
