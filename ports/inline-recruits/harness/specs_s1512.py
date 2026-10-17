"""specs_s1512.py - recruits thread batch 1512: CFormationControl::ControlMembers.
Exe code: vector/matrix helpers (mreset, subtract, add, scale, mcpy, vnorm, vneg, createmat, vmmul), CRT sqrt (pe_emu
stand-in). Recorders: leader/member matrix+position calls (write fixed values), path finder (slot 0x5d0 -> slot
0x220, records the target by content), event queue find/add, profiling."""
import math
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks, sysobj, reftab
from unicorn.x86_const import UC_X86_REG_EDX


def _fl(c, p, vals):
    for i, v in enumerate(vals):
        c.emu.wf32(p + 4 * i, v)


def _mover(c, pos, yaw, extra=None):
    m = [math.cos(yaw), 0.0, math.sin(yaw), 0.0, 1.0, 0.0, -math.sin(yaw), 0.0, math.cos(yaw)]

    def mp(em, k):
        _fl(c, em.arg32(0), m)
        _fl(c, em.arg32(1), pos)
    slots = {0x80: pystub(c, 2, nullflag=(0, 1), side=mp)}
    slots.update(extra or {})
    return obj(c, 0x700, slots)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stamp = r.getrandbits(64)

    def setedx(em, k):
        em.mu.reg_write(UC_X86_REG_EDX, (stamp >> 32) + k)
    objs = {}

    def look(em, rr):
        em.ret(objs.get(em.arg32(0), 0), 4)
    so = sysobj(c, slots={0x1c8: pystub(c, 2, ret=stamp & 0xffffffff, side=setedx),
                          0x178: pystub(c, 3), 0x17c: pystub(c, 3)},
                table_slots={0x58: e.stub_fn('id->obj', look)})
    e.wf32(so + 0x9c7, r.choice([0.0, 1.0]))
    e.wf32(so + 0x9c3, r.choice([0.0, 1.0]))
    e.wf32(so + 0x48, r.choice([1 / 30, 1 / 60, 0.0, r.uniform(0, 0.1)]))
    now = r.randint(0, 1 << 20)
    e.w32(so + 0x40, now)
    f = rnd(c, 0xa0)
    anchor = [r.uniform(-500, 500), r.uniform(-10, 10), r.uniform(-500, 500)]
    _fl(c, f + 0x4c, anchor)
    k = r.random()
    if k < 0.3:
        lp = anchor[:]
    elif k < 0.6:
        lp = [anchor[0] + r.uniform(-60, 60), anchor[1], anchor[2] + r.uniform(-60, 60)]
    else:
        lp = [anchor[0] + r.uniform(-300, 300), anchor[1], anchor[2] + r.uniform(-300, 300)]
    _fl(c, f + 0x40, [lp[i] + (r.uniform(-3, 3) if r.random() < 0.5 else 0.0) for i in range(3)])
    h = r.choice([[0.0, 0.0, 0.0], [0.6, 0.0, 0.8], [r.uniform(-1, 1), 0.0, r.uniform(-1, 1)]])
    _fl(c, f + 0x58, h)
    yaw = r.uniform(0, 2 * math.pi)
    _fl(c, f + 0x64, [math.cos(yaw), 0.0, math.sin(yaw), 0.0, 1.0, 0.0, -math.sin(yaw), 0.0, math.cos(yaw)])
    e.wf32(f + 0x88, r.choice([0.0, 0.5, 0.99, 1.0, 2.0]))
    e.wf32(f + 0x8c, r.choice([0.0, 1.0, 3.0, -1.0]))
    e.w8(f + 0x90, r.choice([0, 0, 1, 7]))
    for i in range(12):
        e.w32(f + 0xc + 4 * i, r.choice([0, 1]))
    lid = r.getrandbits(32) | 1
    L = _mover(c, lp, r.uniform(0, 2 * math.pi))
    e.w32(L + 0x417, r.getrandbits(32))
    objs[lid] = L
    e.w32(f, lid)
    mems = []
    for i in range(r.randint(0, 5)):
        mid = r.getrandbits(32) | 1
        pf = obj(c, 0x20, {0x220: pystub(c, 1, ret=r.choice([0, 1, 1]), deref={0: 3})})
        sp = r.choice([400, 400, 150])   # close members land near the 100-unit order threshold
        ap = [lp[0] + r.uniform(-sp, sp), lp[1], lp[2] + r.uniform(-sp, sp)]
        A = _mover(c, ap, r.uniform(0, 6), {0x5d0: pystub(c, 0, ret=0 if r.random() < 0.2 else pf)})
        e.w32(A + 0x691, r.choice([0, 0, 0, 1, -1]) & 0xffffffff)
        objs[mid] = A
        m = rnd(c, 0x18)
        e.w32(m, mid)
        e.w32(m + 4, r.randint(0, 11))
        e.w32(m + 8, r.randint(0, 4))
        e.w32(m + 0xc, r.choice([0, r.randint(0, 11), 12, 13]))
        e.wf32(m + 0x11, r.choice([-1.0, (now - r.randint(0, 2048)) / 1024.0]))
        mems.append(m)
    e.w32(f + 4, reftab(c, mems) if r.random() < 0.95 else 0)
    # event queue: find -> existing entry (id + data) for some ids, add -> fresh record (or null)
    ents = {}
    for m in mems:
        if r.random() < 0.4:
            ent = rnd(c, 0x24)
            ents[e.r32(m)] = ent

    def fnd(em, rr):
        em.ret(ents.get(em.arg32(0), 0), 4)
    newrec = 0 if r.random() < 0.1 else rnd(c, 0x20)
    q = obj(c, 0x20, {0x2c: e.stub_fn('queue find', fnd), 4: pystub(c, 1, ret=newrec)})
    e.w32(f + 8, q)
    return [rnd(c, 0x60), f]


S(0x5b6110, 'CFormationControl::ControlMembers', 'thiscall', gen=_gen, note='batch1512', max_insns=2000000)
