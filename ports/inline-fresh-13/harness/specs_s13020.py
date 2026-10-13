"""specs_s13020.py - fresh-13 batch 20: 0x5c5010 GUESS timed-object updater. Thiscall (pos, planes), ret 8.
0..5 records (count sometimes -1 or 0), start times around now - 0x1400 (signed), done bytes random, objects with
logged slot 0x28 and custom hooks for 0x80 (writes a per-object matrix and position into the caller's buffers) and 0x7c
(logs the position and two matrix words by value). this+0x44 -> +0x18 slot 0x30 (1 arg) maps ids to handles, db slot
0x58 maps handles to holders whose slot 0x8c moves q by a per-holder offset (logged by value) and whose geom has half
sizes in [0, 300]. this+0x54 cursor in range or not, this+0x60 0 / 1, planes and pos random. 0x451890 / 0x43e920 run
as exe code."""
import struct
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=40, width=6)

    def _code(fn):
        a = c.emu.alloc(16, 16)
        c.emu.wbytes(a, b'\xc3' * 16)
        HOOKED.add(a)
        c.emu.hook(a, fn)
        return a

    def F(a, b):
        return struct.unpack('<f', struct.pack('<f', r.uniform(a, b)))[0]
    now = r.getrandbits(32)
    s28 = logstub(c, log, 0, 1)
    objv = {}

    def _get(e, rr):
        sp = e.reg('esp')
        mp, pp = e.r32(sp + 4), e.r32(sp + 8)
        m, p = objv[e.reg('ecx')]
        e.wbytes(mp, struct.pack('<12f', *m))
        e.wbytes(pp, struct.pack('<3f', *p))
        log.put(e, [2, e.reg('ecx')])
        e.ret(eax=0, argbytes=8)

    def _set(e, rr):
        sp = e.reg('esp')
        mp, pp = e.r32(sp + 4), e.r32(sp + 8)
        log.put(e, [3, e.reg('ecx'), e.r32(pp), e.r32(pp + 4), e.r32(pp + 8), e.r32(mp + 4) ^ e.r32(mp + 0x2c)])
        e.ret(eax=0, argbytes=8)
    a80, a7c = _code(_get), _code(_set)
    holders = {}

    def _xf(e, rr):
        qp = e.r32(e.reg('esp') + 4)
        off = holders[e.reg('ecx')]
        q = struct.unpack('<3f', bytes(e.mu.mem_read(qp, 12)))
        log.put(e, [4, e.reg('ecx')] + [e.r32(qp + 4 * k) for k in range(3)])
        e.wbytes(qp, struct.pack('<3f', *[q[k] + off[k] for k in range(3)]))
        e.ret(eax=0, argbytes=4)
    a8c = _code(_xf)
    hmap = {}
    for k in range(3):
        hd = vobj(c, 0x10, {0x8c: a8c})
        g = rnd(c, 0x50)
        for j in range(3):
            c.emu.wf32(g + 0x40 + 4 * j, r.choice([F(0, 300), 0.0, 100.0]))
        c.emu.w32(hd + 8, g)
        holders[hd] = [r.choice([F(-600, 600), F(-100, 100), 0.0]) for _ in range(3)]
        hmap[r.getrandbits(32)] = hd
    hkeys = list(hmap)
    n = r.choice([0, 1, 2, 3, 4, 5, 5, -1])
    recs = rnd(c, 0x19 * max(n, 1) + 8)
    ids = {}
    for i in range(max(n, 0)):
        rec = recs + 0x19 * i
        done = r.random() < 0.15
        c.emu.w8(rec + 0x18, r.choice([1, 0x80]) if done else 0)
        dt = r.choice([r.randint(0, 0x2000), 0x1400, 0x1401, 0x13ff, r.randint(0, 0x1000)])
        c.emu.w32(rec, (now - dt) & 0xffffffff)
        if done or dt > 0x1400:
            o = r.choice([0, vobj(c, 0x10, {0x28: s28})])
        else:
            o = vobj(c, 0x10, {0x28: s28, 0x80: a80, 0x7c: a7c})
            objv[o] = ([F(-1, 1) for _ in range(12)], [F(-500, 500) for _ in range(3)])
        c.emu.w32(rec + 4, o)
        idv = r.getrandbits(32)
        ids[idv] = r.choice(hkeys)
        c.emu.w32(rec + 8, idv)
        for j in range(3):
            c.emu.wf32(rec + 0xc + 4 * j, F(-50, 50))
    t = vobj(c, 0x40, {0x30: logstub(c, log, 1, 5, ret=lambda e: ids.get(e.r32(e.reg('esp') + 4), hkeys[0]))})
    t44 = rnd(c, 0x20)
    c.emu.w32(t44 + 0x18, t)
    db = vobj(c, 0x60, {0x58: logstub(c, log, 1, 6, ret=lambda e: hmap.get(e.r32(e.reg('esp') + 4), 0))})
    sysobj = rnd(c, 0xa0)
    c.emu.w32(sysobj + 0x40, now)
    c.emu.wf32(sysobj + 0x48, r.choice([F(0, 0.1), 0.0, 1.0]))
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(0x70039c, sysobj)
    me = rnd(c, 0x70)
    c.emu.w32(me + 0x44, t44)
    c.emu.w32(me + 0x4c, recs)
    c.emu.w32(me + 0x50, n & 0xffffffff)
    c.emu.w32(me + 0x54, r.choice([r.randint(0, max(n - 1, 0)), r.randint(0, max(n - 1, 0)), n & 0xffffffff, 7]))
    c.emu.w32(me + 0x60, r.choice([0, 1]))
    pos = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.wf32(pos + 4 * j, F(-500, 500))
    pl = c.emu.alloc(24, 4)
    zero = r.choice([None, None, 0, 1])   # one plane all zero: its dot product is exactly 0
    for j in range(6):
        c.emu.wf32(pl + 4 * j, 0.0 if zero is not None and j // 3 == zero else F(-1, 1))
    flush(c)
    return [me, pos, pl]


S(0x5c5010, 'FUN_005c5010 (GUESS timed-object updater)', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13020; object / holder slots are custom hooks logging values, never stack addresses')
