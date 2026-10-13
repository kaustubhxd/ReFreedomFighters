"""specs_s82.py - inline session batch 82 (2026-10-12, docs/41): ZFFHeroMovementCloseCombat::GotControl (0x5e4980).
The hero, its held item, the entity tracker, the targets, the render manager and the log are heap recorder stubs; the
tracker returns up to five characters (sometimes the hero itself) and then 0. The vector helpers (vneg, vdist2, d = a - b,
vcross, vnorm, createmat, vaddscalar) and 0x595510 run as exe code. Stubs record values, never stack addresses: pointer
arguments to the stack are recorded by their contents."""
import struct
from pilot import S
import specs_s53 as k53

_rnd, _stub, _obj, _vec = k53._rnd, k53._stub, k53._obj, k53._vec


def _rec(c, nargs, rets=(0,), skip=(), copies=()):
    """thiscall/stdcall stub: per call (eight slots) records the arguments not in skip and the dwords of the structs
    copies = [(argidx, ndwords)] point to; returns rets[call] (the last one repeats); ret 4 * nargs."""
    rets = list(rets) + [rets[-1]] * (8 - len(rets))
    tab = c.emu.alloc(32, 4)
    c.emu.wbytes(tab, b''.join(struct.pack('<I', v & 0xffffffff) for v in rets[:8]))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(8 * 64, 4)
    P = lambda v: struct.pack('<I', v)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x07\x6b\xc0\x40\x05' + P(log)
    off = 0
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x50' + bytes([off])
        off += 4
    for ai, n in copies:
        code += b'\x8b\x4c\x24' + bytes([4 + 4 * ai])
        for j in range(n):
            code += b'\x8b\x51' + bytes([4 * j]) + b'\x89\x50' + bytes([off])
            off += 4
    assert off <= 64
    code += b'\xa1' + P(cnt) + b'\x83\xe0\x07\x8b\x04\x85' + P(tab)
    code += b'\xff\x05' + P(cnt) + b'\xc2' + struct.pack('<H', 4 * nargs)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _f(c, v):
    a = c.emu.alloc(16, 4)
    for j, x in enumerate(v):
        c.emu.wf32(a + 4 * j, x)
    return a


def _gc(c):
    r = c.rng
    old = c.emu.r32(0x70039c)
    sysobj = _rnd(c, 0x1ab0)
    c.emu.wbytes(sysobj, bytes(c.emu.mu.mem_read(old, 0xa0)))
    now = r.choice((r.randint(0, 1 << 22), r.randint(1 << 22, 1 << 30), r.getrandbits(32) & 0x7fffffff))
    c.emu.w32(sysobj + 0x40, now)
    c.emu.w32(0x70039c, sysobj)

    # render manager: handle (0x4c), object from handle (0x58), event id (0x114)
    target_obj = _obj(c, 0x20, {0x128: _stub(c, 1)})
    rm = _obj(c, 0x40, {0x4c: _stub(c, 1, ret=r.choice((0, r.getrandbits(32), r.getrandbits(32)))),
                        0x58: _stub(c, 1, ret=target_obj),
                        0x114: _rec(c, 6, rets=(r.getrandbits(32),), skip=(4,), copies=((4, 1),))})
    c.emu.w32(sysobj + 0x9b, rm)

    # log (only without a tracker)
    out = _obj(c, 0x20, {0x30: _stub(c, 0)})
    logo = _obj(c, 0x40, {0x20: _stub(c, 2, ret=out)})
    c.emu.w32(0x700390, logo)

    hero = None
    pos = [r.uniform(-500.0, 500.0) for _ in range(3)]
    fwd = [r.uniform(-1.0, 1.0) for _ in range(3)]
    if r.random() < 0.1:
        fwd = [0.0, 0.0, 0.0]

    # held item: a weapon (+0xc -> +0x23 == 0x1007d2) whose template answers slots 0x300 / 0x330 and names itself at +4
    name = r.choice((0x6ad8b4, 0x6ad8b4, 0, 0x67c8e8, 0x6a5cf0))
    if r.random() < 0.15:
        s = c.emu.alloc(16, 4)
        c.emu.wbytes(s, r.choice((b'MonkeyWrenc\0', b'MonkeyWrench2\0', b'monkeyWrench\0', b'\0')))
        name = s
    tpl = _obj(c, 0x20, {0x300: _stub(c, 0, ret=r.choice((2, 2, 0, r.getrandbits(32)))),
                         0x330: _stub(c, 0, ret=r.choice((0xa, 0xa, 1, r.getrandbits(32))))})
    c.emu.w32(tpl + 4, name)
    ti = _rnd(c, 0x30)
    if r.random() < 0.8:
        c.emu.w32(ti + 0x23, 0x1007d2)
    item = _obj(c, 0x40, {0x350: _stub(c, 0, ret=tpl)})
    c.emu.w32(item + 0xc, ti)

    team = _rnd(c, 0x20)
    hero = _obj(c, 0x900, {
        0x3dc: _stub(c, 0),
        0x4b4: _stub(c, 5),
        0x504: _stub(c, 0, ret=item if r.random() < 0.8 else 0),
        0x80: _stub(c, 2, fills=((0, _f(c, fwd), 3), (1, _f(c, pos), 3)), skip=(0, 1)),
        0x228: _stub(c, 5),
        0x238: _rec(c, 3, skip=(0, 1), copies=((0, 9), (1, 3))),
    })
    c.emu.w32(hero + 0x54, team)
    c.emu.w32(hero + 0x417, r.getrandbits(32) & r.choice((0xffffffff, 0x20000400, 0x400, 0, 0x20000000)))
    c.emu.wf32(hero + 0x813, r.choice((0.0, 0.0, r.uniform(0.0, 100.0))))

    # targets the tracker returns, then 0
    ents = []
    for _ in range(r.choice((0, 1, 2, 3, 5))):
        if r.random() < 0.1:
            ents.append(hero)
            continue
        if r.random() < 0.7:
            t = [pos[j] + r.uniform(-250.0, 250.0) for j in range(3)]
        else:
            t = [pos[j] + r.choice((0.0, r.uniform(-10.0, 10.0))) for j in range(3)]
        if r.random() < 0.05:
            t = list(pos)
        ents.append(_obj(c, 0x20, {0x438: _stub(c, 0, ret=r.getrandbits(32) & (0xffffff00 if r.random() < 0.8 else 0xffffffff)),
                                   0x84: _stub(c, 1, fills=((0, _f(c, t), 3),), skip=(0,))}))
    tracker = _obj(c, 0x20, {0x84: _rec(c, 4, rets=ents + [0], skip=(0, 2), copies=((0, 3), (2, 1)))})
    mgr = _obj(c, 0x200, {0x100: _stub(c, 1, ret=tracker if r.random() < 0.7 else 0)})
    holder = _rnd(c, 0x4b0)
    c.emu.w32(holder + 0x4ac, mgr)
    c.emu.w32(0x7003b8, holder)

    self = _rnd(c, 0x620)
    c.emu.w32(self + 0x36d, hero)
    c.emu.w32(self + 0x608, tracker if r.random() < 0.6 else 0)
    t_last = now / 1024.0 + r.choice((r.uniform(-0.5, 0.1), -0.2, -0.19, r.uniform(-100.0, 100.0)))
    c.emu.wf32(self + 0x5b1, t_last)
    c.emu.wbytes(self + 0x610, bytes([r.choice((0, 1, r.randint(0, 255)))]))
    c.emu.w32(self + 0x5d2, r.choice((0, 1, r.getrandbits(32))))
    c.emu.w32(self + 0x60c, r.choice((0, 1, 2, r.getrandbits(32))))
    for off in (0x54c, 0x558):
        if r.random() < 0.85:
            clip = _rnd(c, 0x80)
            c.emu.w32(clip + 0x6c, r.choice((r.randint(1, 120), 0, 25, r.getrandbits(32))))
            c.emu.w32(self + off, clip)
        else:
            c.emu.w32(self + off, 0)
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x5e4980, 'ZFFHeroMovementCloseCombat::GotControl', 'thiscall', None, gen=_gc,
  note='batch82; wrench tree; vector helpers and 0x595510 as exe code; hero, tracker, targets, render manager stubs')
