"""specs_s13015.py - fresh-13 batch 15: 0x4fe410 CNewDialogCamera::Command. Thiscall (cmd, data), ret 8, returns 0.
The six message ids at +0x4d/+0x51/+0x53/+0x55/+0x57/+0x59 are distinct random u16s; cmd is one of them (or a miss)
with random high bits. Engine db (sys+0x9b): slot 0x58 (1 arg) maps ids to actor objects or 0, slot 0x138 (0 args)
returns a finder object whose vtbl[+0x88](class, out*) writes a random target (or 0) and is logged (the out word is
logged by value), slot 0x4c (1 arg), slot 0x114 RegisterZMsg (4 args, returns a random 32-bit value: only the low
word must reach the send). Actors answer vtbl[+0x1e0] with a random bool (0x100 = al 0). The +0x44 object logs slot
0x12c (3 args); sys+0x1907 object logs 0x70 / 0x74; this->vtbl[+0x3c] and CalcCameraPoses 0x4fefe0 logged. 0x48aad0
runs as exe code."""
import struct
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=24, width=6)
    ids = r.sample(range(0x10000), 7)
    a1, a2 = r.getrandbits(32), r.getrandbits(32)
    bools = [r.choice([0, 1, 1, 1, 0x100, 0x301]) for _ in range(4)]
    cb = {'b': 0, 'f': 0}

    def _b(e):
        v = bools[cb['b'] % 4]
        cb['b'] += 1
        return v
    s1e0 = logstub(c, log, 1, 1, ret=_b)
    actors = {a1: vobj(c, 0x10, {0x1e0: s1e0}) if r.random() < 0.85 else 0,
              a2: vobj(c, 0x10, {0x1e0: s1e0}) if r.random() < 0.85 else 0}
    targets = [r.choice([0, r.getrandbits(32), r.getrandbits(32)]) for _ in range(2)]

    def _find(e):
        sp = e.reg('esp')
        out = e.r32(sp + 8)
        e.w32(out, targets[cb['f'] % 2])
        cb['f'] += 1
        return 0
    finder = vobj(c, 0x10, {0x88: logstub(c, log, 2, 2, ret=_find, deref={1: 1})})
    regv = r.getrandbits(32)
    db = vobj(c, 0x40, {0x58: logstub(c, log, 1, 3, ret=lambda e: actors.get(e.r32(e.reg('esp') + 4), 0)),
                        0x138: logstub(c, log, 0, 4, ret=finder),
                        0x4c: logstub(c, log, 1, 5, ret=lambda e: e.r32(e.reg('esp') + 4) ^ 0x5a5a5a5a),
                        0x114: logstub(c, log, 4, 6, ret=regv)})
    m = vobj(c, 0x10, {0x70: logstub(c, log, 1, 7), 0x74: logstub(c, log, 1, 8)})
    sysobj = c.emu.alloc(0x1910, 4)
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(sysobj + 0x1907, m)
    c.emu.w32(0x70039c, sysobj)
    o44 = vobj(c, 0x10, {0x12c: logstub(c, log, 3, 9)})
    loghook(c, log, 0x4fefe0, 0, 10)
    me = vobj(c, 0xf0, {0x3c: logstub(c, log, 0, 11)})
    c.emu.w32(me + 0x44, o44)
    for off, v in zip((0x4d, 0x51, 0x53, 0x55, 0x57, 0x59), ids):
        c.emu.w16(me + off, v)
    c.emu.w8(me + 0x67, r.choice([0, 1, 0x80]))
    data = rnd(c, 8)
    c.emu.w32(data, a1)
    c.emu.w32(data + 4, a2)
    cmd = r.choice(ids) | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0)
    flush(c)
    return [me, cmd, data]


S(0x4fe410, 'CNewDialogCamera::Command', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13015; db / finder / sender slots logged; 0x48aad0 runs as exe code')
