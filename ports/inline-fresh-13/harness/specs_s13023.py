"""specs_s13023.py - fresh-13 batch 23: 0x54bfd0 GUESS DirectSound driver probe. Thiscall, no args, bool in al.
this->vtbl: 0xc (random bool, 0x100 = al 0), 0x40 (returns the device object), 0xb4, all logged. 0x54c3f0 is a hook
returning hardware drivers (0..5, or 130 to hit the 0x80 cap) then 0, then software drivers (0..4, or 70 for the 0x40
cap) then 0; drivers log slots 0x40 and 4. 0x713dfa random. Device slot 8 is a custom hook logging the format record
words the exe sets (word 6 is uninitialised in the exe) and returning true (false makes the exe read through null);
operator new 0x41e290 (cdecl) and the ctor 0x54e9d0 (installs a logged vtable 0 / 4 / 0xc) are hooks."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=320, width=14)

    def _code(fn):
        a = c.emu.alloc(16, 16)
        c.emu.wbytes(a, b'\xc3' * 16)
        HOOKED.add(a)
        c.emu.hook(a, fn)
        return a
    dvt = c.emu.alloc(0x48, 4)
    c.emu.w32(dvt + 0x40, logstub(c, log, 0, 1))
    c.emu.w32(dvt + 4, logstub(c, log, 1, 2))

    def drv():
        o = c.emu.alloc(8, 4)
        c.emu.w32(o, dvt)
        return o
    nh = r.choice([0, 0, 1, 2, 5, 130])
    ns = r.choice([0, 1, 4, 70])
    seq = [drv() for _ in range(nh)] + [0] + [drv() for _ in range(ns)] + [0]
    k = {'i': 0}

    def _enum(e):
        v = seq[k['i']] if k['i'] < len(seq) else 0
        k['i'] += 1
        return v
    loghook(c, log, 0x54c3f0, 0, 3, ret=_enum)

    def _fmt(e, rr):
        sp = e.reg('esp')
        p = e.r32(sp + 4)
        log.put(e, [4, e.reg('ecx'), e.r32(sp + 8)] + [e.r32(p + 4 * i) for i in range(12) if i != 6])
        e.ret(eax=r.choice([1, 0x101]), argbytes=8)
    dev = vobj(c, 0x63f0, {8: _code(_fmt), 0x40: logstub(c, log, 0, 5), 4: logstub(c, log, 1, 6)})
    ovt = c.emu.alloc(0x10, 4)
    c.emu.w32(ovt, logstub(c, log, 1, 7))
    c.emu.w32(ovt + 4, logstub(c, log, 2, 8, ret=r.choice([0, 1, 1])))
    c.emu.w32(ovt + 0xc, logstub(c, log, 0, 9, ret=r.choice([0, 1, 0x100])))
    mem = rnd(c, 0x50)
    loghook(c, log, 0x41e290, 1, 10, ret=mem, this=False, pop=False)

    def _ctor(e):
        e.w32(e.reg('ecx'), ovt)
        return e.reg('ecx')
    loghook(c, log, 0x54e9d0, 0, 11, ret=_ctor)
    me = c.emu.alloc(0xa280, 4)
    vt = c.emu.alloc(0xb8, 4)
    c.emu.w32(vt + 0xc, logstub(c, log, 0, 12, ret=r.choice([1, 1, 1, 0, 0x100, 0x12345601])))
    c.emu.w32(vt + 0x40, logstub(c, log, 0, 13, ret=dev))
    c.emu.w32(vt + 0xb4, logstub(c, log, 0, 14))
    c.emu.w32(me, vt)
    c.emu.w8(0x713dfa, r.choice([0, 1, 1]))
    c.emu.wbytes(0x713d81, bytes(r.randint(1, 255) for _ in range(15)))   # stale text after the name
    c.emu.w8(0x713df8, r.choice([0, 1]))
    flush(c)
    return [me]


S(0x54bfd0, 'FUN_0054bfd0 (GUESS DirectSound driver probe)', 'thiscall', None, ret='al', gen=_gen,
  note='fresh13 batch13023; driver enumerator, device, wrapper object all logged hooks')
