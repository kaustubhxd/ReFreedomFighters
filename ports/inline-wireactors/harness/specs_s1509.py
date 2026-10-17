"""specs_s1509.py - recruits thread batch 1509: ZFFHERO::UpdateFollowers.
Exe code: vector helpers (subtract, add, scale, matrix-transpose multiply, squared distance), mreset; CRT cos/sin/
acos/sqrt are pe_emu's Python stand-ins (the same in both runs). Recorders: the hero's matrix+position call, the
path finder slot test, the level's blocking boxes' class test, the debug-draw calls (by content), the profiling
calls (time stamp returns EDX:EAX), each follower's position call and events (by content), PushFollower (exe
function, hooked). The exe statics 0x7142a0/0x7142a4[10] (debug circle handles) are compared as globals."""
import math
from pilot import S, F
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj
from unicorn.x86_const import UC_X86_REG_EDX


def _fl(c, p, vals):
    for i, v in enumerate(vals):
        c.emu.wf32(p + 4 * i, v)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0xf00)
    yaw = r.uniform(0, 2 * math.pi)
    M = [math.cos(yaw), 0.0, math.sin(yaw), 0.0, 1.0, 0.0, -math.sin(yaw), 0.0, math.cos(yaw)]
    if r.random() < 0.1:
        M[0] = r.choice([1.5, -1.5, 1.0, -1.0])
    P = [r.uniform(-500, 500), r.uniform(-20, 20), r.uniform(-500, 500)]

    def mp(em, k):
        _fl(c, em.arg32(0), M)
        _fl(c, em.arg32(1), P)
    vt = e.alloc(0x100, 4)
    e.w32(vt + 0x80, pystub(c, 2, nullflag=(0, 1), side=mp))
    e.w32(s, vt)
    fl = r.getrandbits(32)
    e.w32(s + 0x417, fl)
    _fl(c, s + 0xeb3, [P[i] + r.uniform(-5, 5) for i in range(3)])
    _fl(c, s + 0xebf, [r.uniform(-300, 300), r.uniform(-10, 10), r.uniform(-300, 300)])
    _fl(c, s + 0xed3, [r.choice([170.0, r.uniform(50, 300)]), r.uniform(0, 800), r.choice([550.0, r.uniform(100, 800)])])
    e.w32(s + 0xee3, r.choice([0, 1]))
    e.wf32(s + 0xee8, r.choice([0.0, 0.0, 1.0]))
    nf = r.randint(0, 8)
    e.w32(s + 0xa16, nf)
    ns = max(nf, 6)
    e.w32(s + 0xedf, r.randint(0, ns - 1))
    for k in range(ns):
        sl = s + 0xd4e + 0x15 * k
        e.w32(sl, 0 if r.random() < 0.5 else r.getrandbits(32))
        e.wf32(sl + 0x11, r.choice([1.0, r.uniform(0, 1.2)]))
    # followers
    for i in range(nf):
        rec = s + 0xa1a + 0x30 * i
        apos = [P[0] + r.uniform(-400, 400), P[1], P[2] + r.uniform(-400, 400)]
        adir = [r.uniform(-1, 1), 0.0, r.uniform(-1, 1)]

        def gp(em, k, apos=apos, adir=adir):
            _fl(c, em.arg32(0), adir)
            _fl(c, em.arg32(1), apos)
        evrec = e.alloc(4 * 8 * 4 + 4, 4)

        def ev(em, rr, evrec=evrec):
            k = em.r32(evrec + 4 * 32)
            row = evrec + 4 * 8 * min(k, 3)
            em.w32(row, em.arg32(0))
            p = em.arg32(1)
            n = 1 if em.arg32(0) == 0x7777 else 5
            for j in range(n):
                em.w32(row + 4 + 4 * j, em.r32(p + 4 * j))
            em.w32(evrec + 4 * 32, k + 1)
            em.ret(0, 12)
        a = obj(c, 0x40, {0x57c: pystub(c, 2, nullflag=(0,), side=gp), 0x128: e.stub_fn('follower event', ev)})
        e.w32(rec, a)
        _fl(c, rec + 4, [P[0] + r.uniform(-300, 300), P[1], P[2] + r.uniform(-300, 300)])
        e.w32(rec + 0x18, r.choice([0, 1, 2, 2]))
        e.wf32(rec + 0x1c, r.choice([0.0, 1.0]))
    e.w16(s + 0x7e8, 0x6666)
    e.w16(s + 0x7ea, 0x7777)
    # system object, collision/debug object, time
    now = r.randint(0, 1 << 20)
    stamp = r.getrandbits(64)

    def setedx(em, k):
        em.mu.reg_write(UC_X86_REG_EDX, (stamp >> 32) + k)
    coll = obj(c, 0x20, {0x218: pystub(c, 3, ret=r.getrandbits(32), deref={0: 3, 1: 3}),
                         0x21c: pystub(c, 4, deref={1: 3, 2: 3}),
                         0x238: pystub(c, 5, ret=r.getrandbits(32), deref={0: 9, 1: 3, 2: 3}),
                         0x23c: pystub(c, 6, deref={1: 9, 2: 3, 3: 3}),
                         0x240: pystub(c, 1)})
    so = sysobj(c, slots={0x1c8: pystub(c, 2, ret=stamp & 0xffffffff, side=setedx),
                          0x178: pystub(c, 3), 0x17c: pystub(c, 3)}, table_size=0xae0)
    e.w32(e.r32(so + 0x9b) + 0xadc, coll)
    e.wf32(so + 0x48, r.choice([1 / 30, 1 / 60, 0.0001, r.uniform(0, 0.1)]))
    e.w32(so + 0x40, now)
    e.wf32(so + 0x9c7, r.choice([0.0, 1.0]))
    e.wf32(so + 0x9c3, r.choice([0.0, 1.0]))
    for i in range(nf):
        rec = s + 0xa1a + 0x30 * i
        e.wf32(rec + 0x10, (now - r.randint(0, 2048)) / 1024.0)
        e.wf32(rec + 0x14, (now - r.randint(0, 2048)) / 1024.0)
    # path finder
    e.w32(s + 0xecb, 0 if r.random() < 0.2 else obj(c, 0x20, {0x220: pystub(c, 1, ret=r.choice([0, 1, 1]), deref={0: 3})}))
    # level blocking boxes
    g = rnd(c, 0x440)
    nb = r.randint(0, 4)
    e.w32(g + 0x41c, nb)
    for i in range(nb):
        if r.random() < 0.15:
            e.w32(g + 0x420 + 4 * i, 0)
            continue
        o = obj(c, 0x20, {0x1e0: pystub(c, 1, ret=r.choice([0, 0, 1]))})
        geo = rnd(c, 0x50)
        _fl(c, geo, [1, 0, 0, 0, 1, 0, 0, 0, 1])
        k = r.randrange(ns)
        ang = 2 * k * math.pi / ns
        _fl(c, geo + 0x24, [P[0] + math.cos(ang) * 200 + r.uniform(-50, 50), P[1] + 50, P[2] + math.sin(ang) * 200])
        _fl(c, geo + 0x40, [r.uniform(10, 300) for _ in range(3)])
        e.w32(o + 8, geo)
        e.w32(g + 0x420 + 4 * i, o)
    e.w32(0x7003b8, g)
    # PushFollower: hooked recorder
    hook_rec(c, 0x5941d0, 7, ret=lambda em, k: r.choice([0, 1]), this=True, deref={1: 3, 3: 3, 4: 3, 5: 9})
    # debug circle statics
    e.w32(0x7142a0, r.randint(0, 9))
    for i in range(10):
        e.w32(0x7142a4 + 4 * i, 0 if r.random() < 0.5 else r.getrandbits(32))
    return [s]


S(0x595800, 'ZFFHERO::UpdateFollowers', 'thiscall', gen=_gen, note='batch1509', max_insns=2000000)
