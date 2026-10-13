"""specs_s13012.py - fresh-13 batch 12: 0x4952d0 ZEngineGeomControl::UpdateMovedGeoms. Thiscall, no args.
System object *(0x70039c): floats +0x9c7 / +0x9c3 each 0 / non-zero / NaN; vtbl+0x1c8 (2 args, returns a random 64-bit
value in edx:eax via a Python stub), +0x178 / +0x17c (3 args) logged. Engine db (sys+0x9b): vtbl+0x54 (1 arg) maps
each id to a geom or 0 (40% misses), +0x70 (0 args) returns a random bool, logged. Geoms: +0x3c flags with the
0x200000 / 0x40000 bits random. Callees 0x4dc630 (2 args), 0x4dabe0 (0), 0x4d96d0 (1) logged; this->vtbl+0xc logged.
List count 0..8; byte +0xd0 random 0/1."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=48, width=6)
    n = r.choice([0, 1, 2, 3, 5, 8])
    ids = [r.getrandbits(32) for _ in range(n)]
    geoms = {}
    for i in ids:
        if r.random() < 0.6:
            g = rnd(c, 0x40)
            c.emu.w32(g + 0x3c, r.getrandbits(32) & ~0x240000 | r.choice([0, 0x200000, 0x40000, 0x240000]))
            geoms[i] = g
    bools = [r.choice([0, 1, 0x100, 0x101]) for _ in range(16)]
    cnt = {'b': 0}

    def _b(e):
        v = bools[cnt['b'] % 16]
        cnt['b'] += 1
        return v
    db = vobj(c, 0x80, {0x54: logstub(c, log, 1, 1, ret=lambda e: geoms.get(e.r32(e.reg('esp') + 4), 0)),
                        0x70: logstub(c, log, 0, 2, ret=_b)})
    tlo, thi = r.getrandbits(32), r.getrandbits(32)
    tstub = c.emu.alloc(16, 16)
    c.emu.wbytes(tstub, b'\xc3' * 16)

    def _t(e, rr):
        sp = e.reg('esp')
        log.put(e, [3, e.reg('ecx'), e.r32(sp + 4), e.r32(sp + 8)])
        e.mu.reg_write(__import__('unicorn').x86_const.UC_X86_REG_EDX, thi)
        e.ret(eax=tlo, argbytes=8)
    HOOKED.add(tstub)
    c.emu.hook(tstub, _t)
    sysobj = vobj(c, 0xa00, {0x1c8: tstub, 0x178: logstub(c, log, 3, 4), 0x17c: logstub(c, log, 3, 5)})
    for off in (0x9c7, 0x9c3):
        c.emu.wf32(sysobj + off, r.choice([0.0, 0.0, 1.0, -0.0, 2.5, float('nan')]))
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(0x70039c, sysobj)
    loghook(c, log, 0x4dc630, 2, 6)
    loghook(c, log, 0x4dabe0, 0, 7)
    loghook(c, log, 0x4d96d0, 1, 8)
    me = vobj(c, 0x100, {0xc: logstub(c, log, 0, 9)})
    for k, i in enumerate(ids):
        c.emu.w32(me + 4 + 4 * k, i)
    c.emu.w32(me + 0xcc, n)
    c.emu.w8(me + 0xd0, r.choice([0, 1, 1, 0x80]))
    flush(c)
    return [me]


S(0x4952d0, 'ZEngineGeomControl::UpdateMovedGeoms', 'thiscall', None, ret=None, gen=_gen,
  note='fresh13 batch13012; profiler slots, db lookups, three geom callees logged')
