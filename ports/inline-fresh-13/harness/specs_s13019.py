"""specs_s13019.py - fresh-13 batch 19: 0x448c50 ZUSERLIGHT::CopyDataBlock(DBLK*). Thiscall, ret 4.
ZLIGHT::CopyDataBlock 0x448a30, SetPrim 0x4dcdf0 and DBLK::NextBlock 0x4e1b30 are logged hooks; DBLK::Get (u32 / float,
2 args) are hooks that write the next value of a per-input list into the target (type 0..3 mostly, sometimes 4 or
large; floats random). Light manager (sys+0x1aa3 -> +0x18): slot 0x7c (1 arg) returns a random id; slots 0x98 / 0xa0 /
0xa8 are custom hooks that log the handle and only the record words the exe fills for that type (the rest is stack
garbage). db +0x5d35 zero or not; this->vtbl[0] logged; assert hook 0x7003b0 logged."""
import struct
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=24, width=10)
    vals = [r.choice([0, 1, 2, 2, 1, 0, 3, 4, 0x80000001]), r.getrandbits(32), r.getrandbits(32)]
    vals += [struct.unpack('<I', struct.pack('<f', r.uniform(-400, 400)))[0] for _ in range(6)]
    cnt = {'n': 0}

    def _get(tag):
        def h(e, rr):
            sp = e.reg('esp')
            p = e.r32(sp + 4)
            v = vals[cnt['n'] % len(vals)]
            cnt['n'] += 1
            e.w32(p, v)
            log.put(e, [tag, e.reg('ecx'), p, e.r32(sp + 8)])
            e.ret(eax=0, argbytes=8)
        return h
    for a, t in ((0x4e12e0, 1), (0x4e12f0, 2)):
        HOOKED.add(a)
        c.emu.hook(a, _get(t))
    loghook(c, log, 0x448a30, 1, 3)
    loghook(c, log, 0x4e1b30, 0, 4)
    loghook(c, log, 0x4dcdf0, 1, 5)

    def _rec(tag, offs):
        def h(e, rr):
            sp = e.reg('esp')
            p = e.r32(sp + 8)
            log.put(e, [tag, e.reg('ecx'), e.r32(sp + 4)] + [e.r32(p + o) for o in offs])
            e.ret(eax=0, argbytes=8)
        a = c.emu.alloc(16, 16)
        c.emu.wbytes(a, b'\xc3' * 16)
        HOOKED.add(a)
        c.emu.hook(a, h)
        return a
    base = (0x10, 0x14, 0x18, 0x1c)
    mgr = vobj(c, 0x40, {0x7c: logstub(c, log, 1, 6, ret=r.getrandbits(32)),
                         0x98: _rec(7, base), 0xa0: _rec(8, base + (0x24, 0x28)),
                         0xa8: _rec(9, base + (0x24, 0x28, 0x38))})
    lm = rnd(c, 0x20)
    c.emu.w32(lm + 0x18, mgr)
    db = c.emu.alloc(0x5d40, 4)
    c.emu.w32(db + 0x5d35, r.choice([0, 0, 1, 0x100]))
    sysobj = c.emu.alloc(0x1aa8, 4)
    c.emu.w32(sysobj + 0x1aa3, lm)
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(0x7003b0, logstub(c, log, 0, 10, this=False))
    geom = rnd(c, 0x70)
    me = vobj(c, 0x40, {0: logstub(c, log, 0, 11)})
    c.emu.w32(me + 8, geom)
    blk = rnd(c, 0x10)
    flush(c)
    return [me, blk]


S(0x448c50, 'ZUSERLIGHT::CopyDataBlock', 'thiscall', None, ret=None, gen=_gen,
  note='fresh13 batch13019; DBLK readers write a value list; record slots log only the filled words')
