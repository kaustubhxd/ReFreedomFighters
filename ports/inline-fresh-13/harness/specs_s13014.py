"""specs_s13014.py - fresh-13 batch 14: 0x65c050 GUESS view set-up. Thiscall, one argument (entry), ret 4.
ZViewBase::Clear 0x64a6b0 (1 arg) and the rect getter 0x65c530 (1 arg, returns a pointer to 4 floats) are logged hooks;
this->vtbl[+0x84] (1 arg) logged; device at this+0x10051 logs slot 0x134 (4 float args, bits logged) and 0x138 (2).
Frame counter sys+0x3c equals entry+0x74 in 20% of inputs. camera +0x30 in {0, 3, 4, 5} (mostly 4), +0x6c in
{0, 1, 2, 7}, +0x48 bit 0x8000 in 20%. Screen edges 0..2000 (sometimes right < left, so the width wraps). Rect floats
in [0, 1] with exact 0.5 steps sometimes. The CRT float -> unsigned helper 0x633910 runs as exe code."""
import struct
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=16, width=6)
    rect = c.emu.alloc(16, 4)
    for k in range(4):
        v = r.choice([r.random(), r.random(), r.randint(0, 4) / 4.0, r.uniform(0, 1.2)])
        c.emu.wf32(rect + 4 * k, v)
    loghook(c, log, 0x64a6b0, 1, 1)
    loghook(c, log, 0x65c530, 1, 2, ret=rect)
    dev = vobj(c, 0x20, {0x134: logstub(c, log, 4, 3), 0x138: logstub(c, log, 2, 4)})
    me = c.emu.alloc(0x10080, 4)
    vt = c.emu.alloc(0x90, 4)
    c.emu.w32(vt + 0x84, logstub(c, log, 1, 5))
    c.emu.w32(me, vt)
    c.emu.w32(me + 0x10051, dev)
    l, t = r.randint(0, 2000), r.randint(0, 2000)
    rr = l + r.randint(0, 2000) if r.random() < 0.9 else r.randint(0, 2000)
    bb = t + r.randint(0, 2000) if r.random() < 0.9 else r.randint(0, 2000)
    for off, v in ((0x10061, l), (0x10065, t), (0x10069, rr), (0x1006d, bb)):
        c.emu.w32(me + off, v)
    cam = rnd(c, 0x80)
    c.emu.w32(cam + 0x6c, r.choice([0, 1, 2, 7]))
    c.emu.w32(cam + 0x48, r.getrandbits(32) & ~0x8000 | (0x8000 if r.random() < 0.2 else 0))
    c.emu.w32(cam + 0x30, r.choice([0, 3, 4, 4, 4, 4, 5]))
    mid = rnd(c, 0x10)
    c.emu.w32(mid + 0xc, cam)
    entry = rnd(c, 0x80)
    c.emu.w32(entry + 0xc, mid)
    sysobj = rnd(c, 0x40)
    c.emu.w32(0x70039c, sysobj)
    now = r.getrandbits(32)
    c.emu.w32(sysobj + 0x3c, now)
    c.emu.w32(entry + 0x74, now if r.random() < 0.2 else r.getrandbits(32))
    flush(c)
    return [me, entry]


S(0x65c050, 'FUN_0065c050 (GUESS view viewport set-up)', 'thiscall', None, ret=None, gen=_gen,
  note='fresh13 batch13014; Clear and rect getter hooked, device slots logged; CRT float->uint runs as exe code')
