"""specs_s73.py - wire-hero-combat run 12: ZFFHeroMovementRaiseFlag::GotControl 0x5e5950 (lift: inline-herocombat batch73,
copied unchanged into this folder's src). The earlier run (inline-batch45 doc45 chunk 07) was exact but faulted on random
pointers (about 290 of 1000 cases); this spec gives every object it touches:
  - the engine global 0x70039c: +0x40 the tick clock, +0x9b the render manager (slot 0x114 RegisterZMsg, 4 words, logs);
  - [0x70038c] (the flag manager): slot 0xcc(handle) -> the flag (always one);
  - the flag: +0x44 its geometry (slot 0x128 SendCommand, 3 words, logs; slot 0x80 GetMatPos writes a frame and a point),
    +0x106 raised (0 / 1), +0x48 team;
  - self: +4 the owner, +0x36d the hero (slot 0x59c writes the hero's frame and position; +0x9e7 the meter flag, +0x852
    the OSD), +0x569 the flag handle.
Callees run by address are hooked (logging, the exe's own ret N): ZFFHERO::SetRaisingFlag 0x594fb0 (ret 8), StashItem
0x595440 (ret 8), ZGameOSD::ProgressValue 0x59a6b0 (ret 4), the meter switch 0x59a6a0 (ret 4) and CEnemyFlag::FlagPole
0x5c1650 (ret 0; returns the pole, or 0 so the flag geometry is used). All five are strict on their own. The vector math
(0x43e920, 0x4e09b0, 0x4de040, 0x443ef0, 0x451890) runs as exe code on both sides."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from pe_emu import f32
import ladder_kit as K


def _hook(c, addr, name, nargs, eax_fn=lambda: 0):
    def h(e, r):
        args = tuple(K.nostack(e.arg32(k)) for k in range(nargs))
        e.calllog.append((name, K.nostack(e.reg('ecx')), args))
        e.ret(eax=eax_fn(), argbytes=4 * nargs)
    c.emu.hook(addr, h)


def _writer(vals_mat, vals_pos):
    def fn(e, args):
        for i, v in enumerate(vals_mat):
            e.wf32(args[0] + 4 * i, v)
        for i, v in enumerate(vals_pos):
            e.wf32(args[1] + 4 * i, v)
        return 0, None, None
    return fn


def _gc(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    e.w32(eng + 0x40, r.getrandbits(31))
    word = r.getrandbits(16)
    rm = K.rnd(c, 0x40)
    e.w32(rm, K.vt(c, 'rm', {0x114: (4, lambda e2, a: (word, None, None))}, 0x120))
    e.w32(eng + 0x9b, rm)
    # the hero's frame / position and the pole's (flat-ish, near each other, sometimes the same point)
    hpos = [f32(c.fv(-2000.0, 2000.0)), f32(c.fv(-200.0, 400.0)), f32(c.fv(-2000.0, 2000.0))]
    hmat = [f32(c.fv(-1.0, 1.0)) for _ in range(9)]
    if r.random() < 0.05:
        ppos = list(hpos)
    else:
        ppos = [f32(hpos[0] + c.fv(-300.0, 300.0)), f32(hpos[1] + c.fv(-50.0, 50.0)), f32(hpos[2] + c.fv(-300.0, 300.0))]
    pmat = [f32(c.fv(-1.0, 1.0)) for _ in range(9)]
    gvt = K.vt(c, 'flag-geom', {0x128: (3, lambda e2, a: (0, None, None)), 0x80: (2, _writer(pmat, ppos))}, 0x140)
    g = K.rnd(c, 0x60); e.w32(g, gvt)
    flag = K.rnd(c, 0x120)
    e.w32(flag + 0x44, g)
    e.w8(flag + 0x106, r.choice([0, 0, 1]))
    pole = K.rnd(c, 0x60); e.w32(pole, K.vt(c, 'pole', {0x80: (2, _writer(pmat, ppos))}, 0x90))
    pole_ret = 0 if r.random() < 0.3 else pole
    mgr = K.rnd(c, 0x40); e.w32(mgr, K.vt(c, 'flag-mgr', {0xcc: (1, lambda e2, a: (flag, None, None))}, 0xd0))
    e.w32(0x70038c, mgr)
    hero = K.rnd(c, 0xa00)
    e.w32(hero, K.vt(c, 'hero', {0x59c: (2, _writer(hmat, hpos))}, 0x5a0))
    e.w8(hero + 0x9e7, r.choice([0, 1]))
    self_ = K.rnd(c, 0x600)
    e.w32(self_ + 0x36d, hero)
    e.w32(self_ + 4, K.rnd(c, 0x40))
    _hook(c, 0x594fb0, 'SetRaisingFlag', 2)
    _hook(c, 0x595440, 'StashItem', 2)
    _hook(c, 0x59a6b0, 'ProgressValue', 1)
    _hook(c, 0x59a6a0, 'MeterOn', 1)
    _hook(c, 0x5c1650, 'FlagPole', 0, lambda: pole_ret)
    e.mu.ctl_flush_tb()
    return [self_]


S(0x5e5950, 'ZFFHeroMovementRaiseFlag::GotControl', 'thiscall', None, ret=None, gen=_gc, nan_heap=True,
  note='wire-hero-combat run 12; batch73 (copy); objects for every pointer, five callees hooked (each strict)')


def _ga(c):
    """GetActiveAnim 0x5e3920: the raise movement's per-frame clock. Flag via [0x70038c] slot 0xcc (handle +0x569); the
    flag's +0x111 (flag object handle), +0x106 (raised), +0x44 geometry (slot 0x128 SendCommand logs); three animation
    pointers +0x559 / +0x55d / +0x561 (sometimes null) to records with first/last frame (+0x60 / +0x64) and rate +0x6c;
    the hero (+0x36d): slot 0x5c8 state word (bit 0x40000), +0x9e3 use time, +0x9e7 meter flag, +0x852 the OSD. Callees
    hooked: flag Activate 0x5c1d10, raised-by 0x5c21c0, empty 0x4690b0, ProgressValue 0x59a6b0 (each strict)."""
    e, r = c.emu, c.rng
    eng = K.engine(c)
    now = r.getrandbits(20)
    e.w32(eng + 0x40, now)
    rm = K.rnd(c, 0x40)
    e.w32(rm, K.vt(c, 'rm', {0x114: (4, lambda e2, a: (r.getrandbits(16), None, None))}, 0x120))
    e.w32(eng + 0x9b, rm)
    g = K.rnd(c, 0x60); e.w32(g, K.vt(c, 'flag-geom', {0x128: (3, lambda e2, a: (0, None, None))}, 0x140))
    flag = K.rnd(c, 0x130)
    e.w32(flag + 0x44, g)
    e.w8(flag + 0x106, r.choice([0, 1]))
    e.w32(flag + 0x111, r.choice([0, 0, 0x1234]))
    mgr = K.rnd(c, 0x40); e.w32(mgr, K.vt(c, 'flag-mgr', {0xcc: (1, lambda e2, a: (flag, None, None))}, 0xd0))
    e.w32(0x70038c, mgr)

    def anim():
        if r.random() < 0.08:
            return 0
        a = K.rnd(c, 0x80)
        first = r.randrange(0, 20)
        e.w32(a + 0x60, first)
        e.w32(a + 0x64, first + r.choice([0, 10, 30, 60, 80, 120, r.randrange(0, 200)]))
        e.w32(a + 0x6c, r.choice([1, 24, 30, 30, 30, r.randrange(1, 90)]))
        return a
    hero = K.rnd(c, 0xa00)
    state = r.choice([0, 0, 0, 0x40000, 0x40001, r.getrandbits(20)])
    e.w32(hero, K.vt(c, 'hero', {0x5c8: (0, lambda e2, a: (state, None, None))}, 0x5d0))
    # use time: zero or a float
    e.wf32(hero + 0x9e3, r.choice([0.0, 0.0, f32(c.fv(0.1, 50.0))]))
    e.w8(hero + 0x9e7, r.choice([0, 1]))
    e.w32(hero + 0x852, K.rnd(c, 0x40))
    self_ = K.rnd(c, 0x600)
    e.w32(self_ + 0x36d, hero)
    e.w32(self_ + 0x569, 0x4321)
    for off in (0x559, 0x55d, 0x561):
        e.w32(self_ + off, anim())
    if r.random() < 0.5:   # the first / 45 / 60 latches sometimes already set
        for off in (0x551, 0x552, 0x553):
            e.w8(self_ + off, r.choice([0, 1]))
    e.w8(self_ + 0x550, 1)
    # start time: the elapsed seconds spread over where the thresholds fall (rate up to ~90, n up to ~200 frames)
    if r.random() < 0.1:
        start = now / 1024.0
    else:
        start = max(0.0, now / 1024.0 - c.fv(0.0, 8.0)) if r.random() < 0.9 else c.fv(0.0, 2000.0)
    a559 = e.r32(self_ + 0x559)
    if a559 and r.random() < 0.4:
        # land t exactly on (or just either side of) a threshold: 0, 45, 60, the frame count
        nfr = e.r32(a559 + 0x64) - e.r32(a559 + 0x60) + 1
        T = r.choice([45.0, 45.0, 60.0, 60.0, float(nfr), float(nfr), 44.5, 45.5, 59.5, 60.5, nfr - 0.5, nfr + 0.5])
        rate = r.choice([1, 2, 4, 8, 16, 32, 64])
        e.w32(a559 + 0x6c, rate)
        ticks = int(round(T * 1024.0 / rate))
        if ticks <= now:
            start = (now - ticks) / 1024.0
    e.wf32(self_ + 0x555, f32(start))
    out = K.rnd(c, 8)
    _hook(c, 0x5c1d10, 'FlagActivate', 0)
    _hook(c, 0x5c21c0, 'RaisedBy', 1)
    _hook(c, 0x4690b0, 'FlagEmpty', 0)
    _hook(c, 0x59a6b0, 'ProgressValue', 1)
    e.mu.ctl_flush_tb()
    return [self_, out, 0, 0, 0, 0]


S(0x5e3920, 'ZFFHeroMovementRaiseFlag::GetActiveAnim', 'thiscall', None, ret='st0', gen=_ga, nan_heap=True,
  note='wire-hero-combat run 13; batch73 (copy); flag / hero / anim objects, four callees hooked (each strict)')


def _wc(c):
    """WantControl 0x5e8d40 (a, pos, c): self +0x550 active, +0x36d hero, +0x565 the "FlagList" handle, +0x569 the flag
    handle. Render manager (eng +0x9b): slot 0x58 handle -> object (the list, poles), 0x138 -> database (slot 0x88 writes
    the list handle), 0x114 register. The list +0x18 iterator (slot 0x4c begin, 0x5c next), [0x70038c] slot 0xcc handle ->
    flag; the flag: +0x44 geometry (slot 0x80 frame + point, 0x128 SendCommand writes a response), +0x48 team, +0x115 pole
    handle. Hero: slots 0x5a4 (may raise), 0x5b4 (height, st0); +0x54 -> +4 team; +0x9d3, +0x66c. The log (global 0x700390
    slot 0x20 -> slot 0x2c). SetUseAction 0x5950c0 hooked (strict); the vector helpers and FlagPole run as exe code."""
    e, r = c.emu, c.rng
    eng = K.engine(c)
    pos = K.rnd(c, 16)
    P = [float(round(r.uniform(-1500.0, 1500.0))), float(round(r.uniform(-100.0, 300.0))), float(round(r.uniform(-1500.0, 1500.0)))]
    for i in range(3):
        e.wf32(pos + 4 * i, P[i])
    objs = {}
    hero_team = r.choice([1, 2, 3, 7])
    resp_val = r.choice([0, 0, 0, 1, 5])
    height = float(round(r.uniform(0.0, 200.0)))

    def flag_obj(near):
        g = K.rnd(c, 0x60)
        if near and r.random() < 0.35:   # on the limits: 100 in height, flat distance exactly 100 (or just inside / outside)
            dx, dz = r.choice([(100, 0), (0, 100), (60, 80), (-80, 60), (100, 1), (99, 0), (-100, 0), (0, -99), (70, 70)])
            dy = r.choice([100, -100, 101, -101, 99, 0, 100])
            fp = [P[0] + dx, P[1] - height + dy, P[2] + dz]
        elif near:
            fp = [f32(P[0] + c.fv(-140.0, 140.0)), f32(P[1] - height + c.fv(-130.0, 130.0)), f32(P[2] + c.fv(-140.0, 140.0))]
        else:
            fp = [f32(c.fv(-1500.0, 1500.0)), f32(c.fv(-100.0, 300.0)), f32(c.fv(-1500.0, 1500.0))]
        fm = [f32(c.fv(-1.0, 1.0)) for _ in range(9)]

        def send(e2, a):
            if a[1] and r.random() < 2:  # response written only by the flag's flag_resp
                e2.w32(a[1], flag_resp[g])
            return 0, None, None
        e.w32(g, K.vt(c, 'flag-geom', {0x80: (2, _writer(fm, fp)), 0x128: (3, send)}, 0x140))
        fl = K.rnd(c, 0x130)
        e.w32(fl + 0x44, g)
        e.w32(fl + 0x48, r.choice([hero_team, hero_team, r.randrange(0, 8)]))
        e.w32(fl + 0x115, 0)
        flag_resp[g] = r.choice([0, 0, resp_val])
        if r.random() < 0.15:     # a pole of its own
            pg = K.rnd(c, 0x60)
            pp = [f32(fp[0] + c.fv(-20.0, 20.0)), f32(fp[1] + c.fv(-20.0, 20.0)), f32(fp[2] + c.fv(-20.0, 20.0))]
            e.w32(pg, K.vt(c, 'pole', {0x80: (2, _writer(fm, pp))}, 0x90))
            ph = 0x7000 + len(objs)
            objs[ph] = pg
            e.w32(fl + 0x115, ph)
        return fl
    flag_resp = {}
    count = r.choice([0, 1, 1, 2, 3, 5])
    handles = [0x100 + k for k in range(count)]
    flags = {}
    for hnd in handles:
        if r.random() < 0.1:
            continue                       # a handle with no flag
        flags[hnd] = flag_obj(r.random() < 0.55)
    END = r.choice([0, 0, 0xffff, 0x555])
    st = {'idx': 0}

    def begin(e2, a):
        e2.w32(a[0], count)
        st['idx'] = 0
        return 0, None, None

    def nxt(e2, a):
        i = st['idx']
        h = handles[i] if i < count else END
        e2.w32(a[0], count - i if i < count else 0)
        st['idx'] = i + 1
        return h, None, None
    it = K.rnd(c, 0x40); e.w32(it, K.vt(c, 'iter', {0x4c: (1, begin), 0x5c: (1, nxt)}, 0x70))
    lst = K.rnd(c, 0x40)
    e.w32(lst + 0x18, 0 if r.random() < 0.05 else it)
    list_h = r.choice([0x61, 0x62])
    objs[list_h] = lst if r.random() < 0.93 else 0
    db_h = r.choice([list_h, list_h, 0])
    db = K.rnd(c, 0x40); e.w32(db, K.vt(c, 'db', {0x88: (2, lambda e2, a: (e2.w32(a[1], db_h) or 0, None, None))}, 0x90))
    rm = K.rnd(c, 0x40)
    e.w32(rm, K.vt(c, 'rm', {0x58: (1, lambda e2, a: (objs.get(a[0], 0), None, None)),
                             0x138: (0, lambda e2, a: (db, None, None)),
                             0x114: (4, lambda e2, a: (r.getrandbits(16), None, None))}, 0x140))
    e.w32(eng + 0x9b, rm)
    mgr = K.rnd(c, 0x40)
    e.w32(mgr, K.vt(c, 'flag-mgr', {0xcc: (1, lambda e2, a: (flags.get(a[0], 0), None, None))}, 0xd0))
    e.w32(0x70038c, mgr)
    lg = K.rnd(c, 0x40)
    lo = K.rnd(c, 0x40)

    def logprint(e2, r2):   # cdecl: (obj, fmt), the caller cleans the stack
        e2.calllog.append(('logobj', 0x2c, K.nostack(e2.arg32(0)), K.nostack(e2.arg32(1))))
        e2.ret(eax=lo, argbytes=0)
    e.w32(lo, e.fake_vtable('logobj', 0x30, {0x2c: logprint}))
    e.w32(lg, K.vt(c, 'log', {0x20: (2, lambda e2, a: (lo, None, None))}, 0x24))
    e.w32(0x700390, lg)
    hero = K.rnd(c, 0xa00)
    may = r.choice([1, 1, 1, 0])
    e.w32(hero, K.vt(c, 'hero', {0x5a4: (0, lambda e2, a: (may, None, None)),
                                 0x5b4: (0, lambda e2, a: (0, height, None))}, 0x5c0))
    ht = K.rnd(c, 0x20); e.w32(ht + 4, hero_team)
    e.w32(hero + 0x54, ht)
    e.w32(hero + 0x9d3, r.choice([2, 2, 1, 0]))
    e.w8(hero + 0x66c, r.choice([0, 1, 1]))
    self_ = K.rnd(c, 0x600)
    e.w32(self_ + 0x36d, hero)
    e.w8(self_ + 0x550, r.choice([0, 0, 0, 1]))
    e.w32(self_ + 0x565, r.choice([0, 0, list_h, 0x77]))
    e.w32(self_ + 0x569, r.choice([0, 0x100, 0x999]))
    _hook(c, 0x5950c0, 'SetUseAction', 3)
    e.mu.ctl_flush_tb()
    return [self_, K.rnd(c, 16), pos, K.rnd(c, 16)]


S(0x5e8d40, 'ZFFHeroMovementRaiseFlag::WantControl', 'thiscall', None, ret='al', gen=_wc, nan_heap=True,
  note='wire-hero-combat run 13; batch73 (copy); list / iterator / flag / pole / hero objects, SetUseAction hooked')


# ---------------------------------------------------------------- run 20: OpenGate GotControl 0x5e5460 / GetActiveAnim 0x5e2f20 (batch72, copied unchanged)
def _hookf(c, addr, name, nargs, st0_fn):
    def h(e, r):
        args = tuple(K.nostack(e.arg32(k)) for k in range(nargs))
        e.calllog.append((name, K.nostack(e.reg('ecx')), args))
        e.ret(eax=0, argbytes=4 * nargs, st0=st0_fn())
    c.emu.hook(addr, h)


def _logger(c):
    e = c.emu
    lo = K.rnd(c, 0x40)

    def logprint(e2, r2):   # cdecl: (obj, fmt), the caller cleans the stack
        e2.calllog.append(('logobj', 0x2c, K.nostack(e2.arg32(0)), K.nostack(e2.arg32(1))))
        e2.ret(eax=lo, argbytes=0)
    e.w32(lo, e.fake_vtable('logobj', 0x30, {0x2c: logprint}))
    lg = K.rnd(c, 0x40)
    e.w32(lg, K.vt(c, 'log', {0x20: (2, lambda e2, a: (lo, None, None))}, 0x24))
    e.w32(0x700390, lg)


def _gg(c):
    """OpenGate GotControl 0x5e5460: self +0x36d hero (slot 0x59c frame + point, slot 0x5b4 height st0, +0x852 OSD), +0x55b gate
    (+0x50 door handle, +0x25a locked byte); render manager slot 0x58 maps the handle to the door (slot 0x98 writes the walk-to
    frame / point, slot 0x128 SendCommand) or 0, slot 0x114 registers. mreset 0x4de7a0, vneg 0x4e09b0 run as exe code; SetTempItem
    0x595010, ProgressValue 0x59a6b0 and the meter 0x59a6a0 hooked (each strict)."""
    e, r = c.emu, c.rng
    eng = K.engine(c)
    e.w32(eng + 0x40, r.getrandbits(24))
    door = K.rnd(c, 0x60)
    wm = [f32(c.fv(-1.0, 1.0)) for _ in range(9)]
    wp = [f32(c.fv(-2000.0, 2000.0)), f32(c.fv(-200.0, 400.0)), f32(c.fv(-2000.0, 2000.0))]
    e.w32(door, K.vt(c, 'door', {0x98: (2, _writer(wm, wp)), 0x128: (3, lambda e2, a: (0, None, None))}, 0x140))
    # the first lookup (before slot 0x98) is never null in the exe's use (no null test); the second may be
    second_null = r.random() < 0.1
    calls = [0]

    def door_for(e2, a):
        calls[0] += 1
        return (0 if (second_null and calls[0] > 1) else door), None, None
    rm = K.rnd(c, 0x40)
    e.w32(rm, K.vt(c, 'rm', {0x58: (1, door_for),
                             0x114: (4, lambda e2, a: (r.getrandbits(16), None, None))}, 0x120))
    e.w32(eng + 0x9b, rm)
    gate = K.rnd(c, 0x270)
    e.w32(gate + 0x50, r.getrandbits(16))
    e.w8(gate + 0x25a, r.choice([0, 1]))
    hpos = [f32(c.fv(-2000.0, 2000.0)), f32(c.fv(-200.0, 400.0)), f32(c.fv(-2000.0, 2000.0))]
    hmat = [f32(c.fv(-1.0, 1.0)) for _ in range(9)]
    height = f32(c.fv(0.0, 200.0))
    hero = K.rnd(c, 0xa00)
    e.w32(hero, K.vt(c, 'hero', {0x59c: (2, _writer(hmat, hpos)), 0x5b4: (0, lambda e2, a: (0, height, None))}, 0x5c0))
    e.w32(hero + 0x852, K.rnd(c, 0x40))
    self_ = K.rnd(c, 0x600)
    e.w32(self_ + 0x36d, hero)
    e.w32(self_ + 0x55b, gate)
    _hook(c, 0x595010, 'SetTempItem', 1)
    _hook(c, 0x59a6b0, 'ProgressValue', 1)
    _hook(c, 0x59a6a0, 'MeterOn', 1)
    e.mu.ctl_flush_tb()
    return [self_]


S(0x5e5460, 'ZFFHeroMovementOpenGate::GotControl', 'thiscall', None, ret=None, gen=_gg, nan_heap=True,
  note='wire-hero-combat run 20; batch72 (copy); hero / door / gate objects, three callees hooked (each strict)')


def _ga2(c):
    """OpenGate GetActiveAnim 0x5e2f20: self +0x54c active, +0x54d done latch, +0x54e locked, +0x54f start time, +0x553 open animation,
    +0x557 locked animation (frames +0x60 / +0x64, rate +0x6c), +0x55b gate (+0x50 door handle), +0x36d hero (slot 0x438 cannot act,
    slot 0x5bc throw, +0x9e3 use time, +0x852 OSD); render manager slots 0x4c (handle of the hero), 0x58 (door), 0x114; the door's slot
    0x128 SendCommand; the log (cdecl). Hooked (each strict): ProgressValue 0x59a6b0, gate Activate broadcast 0x5c26f0, SetOpen
    0x5c2940, AdjustHitPoints 0x58b9c0 (returns a float in st0)."""
    e, r = c.emu, c.rng
    eng = K.engine(c)
    now = r.getrandbits(20)
    e.w32(eng + 0x40, now)
    door = K.rnd(c, 0x60)
    e.w32(door, K.vt(c, 'door', {0x128: (3, lambda e2, a: (0, None, None))}, 0x140))
    has_door = r.random() < 0.9
    rm = K.rnd(c, 0x40)
    e.w32(rm, K.vt(c, 'rm', {0x4c: (1, lambda e2, a: (r.getrandbits(16), None, None)),
                             0x58: (1, lambda e2, a: (door if has_door else 0, None, None)),
                             0x114: (4, lambda e2, a: (r.getrandbits(16), None, None))}, 0x120))
    e.w32(eng + 0x9b, rm)
    _logger(c)
    gate = K.rnd(c, 0x270)
    e.w32(gate + 0x50, r.getrandbits(16))

    def anim():
        if r.random() < 0.07:
            return 0
        a = K.rnd(c, 0x80)
        first = r.randrange(0, 20)
        e.w32(a + 0x60, first)
        e.w32(a + 0x64, first + r.choice([0, 10, 36, 60, 105, 140, 160, r.randrange(0, 250)]))
        e.w32(a + 0x6c, r.choice([1, 25, 25, 25, r.randrange(1, 90)]))
        return a
    hero = K.rnd(c, 0xa00)
    cannot = r.choice([0, 0, 0, 0, 1])
    e.w32(hero, K.vt(c, 'hero', {0x438: (0, lambda e2, a: (cannot, None, None)),
                                 0x5bc: (3, lambda e2, a: (0, None, None))}, 0x5c4))
    e.wf32(hero + 0x9e3, r.choice([0.0, 0.0, f32(c.fv(0.1, 50.0))]))
    e.w32(hero + 0x852, K.rnd(c, 0x40))
    self_ = K.rnd(c, 0x600)
    e.w32(self_ + 0x36d, hero)
    e.w32(self_ + 0x55b, gate)
    e.w8(self_ + 0x54c, 1)
    e.w8(self_ + 0x54d, r.choice([0, 0, 1]))
    e.w8(self_ + 0x54e, r.choice([0, 1]))
    e.w32(self_ + 0x553, anim())
    e.w32(self_ + 0x557, anim())
    start = max(0.0, now / 1024.0 - c.fv(0.0, 8.0)) if r.random() < 0.9 else c.fv(0.0, 2000.0)
    a_sel = e.r32(self_ + (0x557 if e.r8(self_ + 0x54e) else 0x553))
    if a_sel and r.random() < 0.4:
        nfr = e.r32(a_sel + 0x64) - e.r32(a_sel + 0x60) + 1
        T = r.choice([36.0, 36.0, 140.0, 140.0, float(nfr), float(nfr), 35.5, 36.5, 139.5, 140.5, nfr - 0.5, nfr + 0.5])
        rate = r.choice([1, 2, 4, 8, 16, 32, 64])
        e.w32(a_sel + 0x6c, rate)
        ticks = int(round(T * 1024.0 / rate))
        if ticks <= now:
            start = (now - ticks) / 1024.0
    e.wf32(self_ + 0x54f, f32(start))
    _hook(c, 0x59a6b0, 'ProgressValue', 1)
    _hook(c, 0x5c26f0, 'GateActivate', 0)
    _hook(c, 0x5c2940, 'SetOpen', 1)
    _hookf(c, 0x58b9c0, 'AdjustHitPoints', 3, lambda: r.choice([-5.0, 0.0, 50.0, -300.0]))
    e.mu.ctl_flush_tb()
    return [self_, K.rnd(c, 8), 0, 0, 0, 0]


S(0x5e2f20, 'ZFFHeroMovementOpenGate::GetActiveAnim', 'thiscall', None, ret='st0', gen=_ga2, nan_heap=True,
  note='wire-hero-combat run 20; batch72 (copy); hero / gate / door / animation objects, four callees hooked (each strict)')


# ---------------------------------------------------------------- run 21: ZLNKWHANDS::ReloadItem 0x4750b0 (inline-weapons batch501, copied unchanged)
def _ri(c):
    """ReloadItem(item): self slots 0x560 (spare ammo for the item) and 0x564 (set spare); item slots 0x364 (clip size), 0x35c (rounds in
    the magazine), 0x360 (set the magazine), 0x358 (chamber a bullet); the log (global 0x700390: slot 0x20(file, line) -> a stream whose
    slot 0x2c is a cdecl printf(stream, fmt, n)). Every call is logged with its arguments."""
    e, r = c.emu, c.rng
    spare = r.choice([0, 1, 5, 30, 200, r.randrange(0, 1000), -r.randrange(1, 20), r.getrandbits(31)])
    clip = r.choice([1, 6, 8, 12, 30, 50, 100, r.randrange(0, 300), -r.randrange(1, 10)])
    cur = r.choice([0, 0, 1, 5, 6, 30, r.randrange(0, 300), r.randrange(0, max(1, abs(clip) + 1))])
    item = K.rnd(c, 0x40)
    e.w32(item, K.vt(c, 'item', {0x364: (0, lambda e2, a: (clip & 0xffffffff, None, None)),
                                 0x35c: (0, lambda e2, a: (cur & 0xffffffff, None, None)),
                                 0x360: (1, lambda e2, a: (0, None, None)),
                                 0x358: (1, lambda e2, a: (0, None, None))}, 0x370))
    self_ = K.rnd(c, 0x40)
    e.w32(self_, K.vt(c, 'hands', {0x560: (1, lambda e2, a: (spare & 0xffffffff, None, None)),
                                   0x564: (2, lambda e2, a: (0, None, None))}, 0x570))
    stream = K.rnd(c, 0x40)

    def printf(e2, r2):   # cdecl (stream, fmt, n): the caller cleans the stack
        e2.calllog.append(('printf', K.nostack(e2.arg32(0)), e2.arg32(1), e2.arg32(2)))
        e2.ret(eax=0, argbytes=0)
    e.w32(stream, e.fake_vtable('stream', 0x40, {0x2c: printf}))
    lg = K.rnd(c, 0x40)
    e.w32(lg, K.vt(c, 'log', {0x20: (2, lambda e2, a: (stream, None, None))}, 0x24))
    e.w32(0x700390, lg)
    e.mu.ctl_flush_tb()
    return [self_, item]


S(0x4750b0, 'ZLNKWHANDS::ReloadItem', 'thiscall', None, ret=None, gen=_ri,
  note='wire-hero-combat run 21; batch501 (copy of inline-weapons); self / item vtables and the log stream; every call logged')


# ---------------------------------------------------------------- run 25: ZTARGET::CallBackIfTime 0x465930 (inline-frameupdate batch403, copied unchanged)
def _cbt(c):
    """CallBackIfTime(obj): the target t (+0 enabled byte, +0x31 fade time d, +0x35 start time (negative = fading out), +0x3d callback as a
    16-byte member pointer {fn, this adjustment, -1 words}); the callback, when set, is the hooked exe function 0x58c2b0 and is logged with
    its `this` (obj + adjustment)."""
    e, r = c.emu, c.rng
    eng = K.engine(c)
    now = r.getrandbits(20)
    e.w32(eng + 0x40, now)
    t = K.rnd(c, 0x60)
    e.w8(t, r.choice([0, 1]))
    d = r.choice([0.0, 0.0, f32(c.fv(0.0, 5.0)), f32(c.fv(-1.0, 3.0)), 0.5, 1.0, 2.0])
    mag = r.choice([now / 1024.0 - r.choice([0.0, 0.25, 0.5, 1.0, 2.0, 5.0, 100.0]), f32(c.fv(0.0, 1000.0)), now / 1024.0])
    st = mag if r.random() < 0.5 else -mag
    if r.random() < 0.06:
        st = float('nan')
    e.wf32(t + 0x31, d)
    e.wf32(t + 0x35, f32(st))
    fn = 0x58c2b0 if r.random() < 0.8 else 0
    adj = r.choice([0, 0, 8, 0x30])
    for i, v in enumerate((fn, adj, 0xffffffff, 0xffffffff)):
        e.w32(t + 0x3d + 4 * i, v)
    obj = K.rnd(c, 0x80)

    def cb(e2, r2):
        e2.calllog.append(('callback', K.nostack(e2.reg('ecx')) - obj))
        e2.ret(eax=0, argbytes=0)
    e.hook(0x58c2b0, cb)
    e.mu.ctl_flush_tb()
    return [t, obj]


S(0x465930, 'ZTARGET::CallBackIfTime', 'thiscall', None, ret=None, gen=_cbt, nan_heap=True,
  note='wire-hero-combat run 25; batch403 (copy); target with a member-pointer callback hooked at 0x58c2b0')


# ---------------------------------------------------------------- run 25: ZTARGET weight 0x466b70 (batch519) and SetTime 0x467b00 (batch504), copied unchanged
def _tgt(c, boundary=True):
    """A ZTARGET with a fade: +0x31 duration, +0x35 start stamp (negative = blending out, NaN possible), +0x39 geom word; the engine clock
    eng +0x40. Elapsed time lands on the duration (and 0) often enough to hit the equality edges."""
    e, r = c.emu, c.rng
    eng = K.engine(c)
    now = r.getrandbits(20)
    e.w32(eng + 0x40, now)
    t = K.rnd(c, 0x60)
    d = r.choice([0.0, 0.0, 0.5, 1.0, 2.0, f32(c.fv(0.0, 5.0)), f32(c.fv(-1.0, 3.0))])
    el = r.choice([0.0, 0.25, d, d, f32(c.fv(0.0, 8.0)), 100.0]) if boundary else f32(c.fv(0.0, 8.0))
    stamp = f32(max(0.0, now / 1024.0 - el)) if r.random() < 0.85 else f32(c.fv(0.0, 2000.0))
    st = stamp if r.random() < 0.5 else -stamp
    if r.random() < 0.05:
        st = float('nan')
    e.wf32(t + 0x31, d)
    e.wf32(t + 0x35, st)
    e.w32(t + 0x39, r.getrandbits(32))
    e.mu.ctl_flush_tb()
    return t


def _wt(c):
    return [_tgt(c)]


S(0x466b70, 'ZTARGET::weight (name inferred)', 'thiscall', None, ret='st0', gen=_wt, nan_heap=True,
  note='wire-hero-combat run 25; batch519 (copy); fade fields and the engine clock')


def _st(c):
    t = _tgt(c)
    r = c.rng
    return [t, F(r.choice([0.0, 0.5, 1.0, 2.0, f32(c.fv(0.0, 5.0)), f32(c.fv(-1.0, 3.0))])), r.choice([0, 1, 1])]


S(0x467b00, 'ZTARGET::SetTime', 'thiscall', None, ret=None, gen=_st, nan_heap=True,
  note='wire-hero-combat run 25; batch504 (copy); fade fields and the engine clock')

# ---- run 26: vangpul 0x4e0130 (inline-mountedgun batch310, copied unchanged; spec from specs_s310.py)
import math




def _vec(c, base=None):
    r = c.rng
    k = r.random()
    if base and k < 0.15:
        v = list(base)                                          # same direction
    elif base and k < 0.25:
        v = [-x for x in base]                                  # opposite (NaN stays NaN)
    elif base and k < 0.4:
        s = r.uniform(0.5, 3)
        v = [max(-3.4e38, min(3.4e38, x * s + c.fv(-0.05, 0.05, 0))) for x in base]   # nearly parallel
    elif k < 0.45:
        v = [0.0, 0.0, 0.0]
    else:
        v = [c.fv(-5, 5) for _ in range(3)]
    a = c.emu.alloc(4 * 11, 4)
    for i in range(11):
        c.emu.wf32(a + 4 * i, v[i] if i < 3 else c.fv())
    return a, v


def _gen(c):
    r = c.rng
    a, av = _vec(c)
    b, _ = _vec(c, av)
    k = r.random()
    m = r.uniform(0, 0.5) if k < 0.6 else (r.uniform(0, math.pi) if k < 0.9 else c.fv())
    out = c.emu.alloc(4 * 11, 4)
    for i in range(11):
        c.emu.wf32(out + 4 * i, c.fv())
    return [out, a, b, F(m)]


S(0x4e0130, 'vangpul', 'fastcall', None, ret='al', gen=_gen, note='batch310; x87 normalise; CRT acos/sin/cos')
