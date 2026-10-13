"""specs_s4012.py - area 70 batch 4012: 0x5be810 (quad visibility test, GUESS name). The exe callees 0x591ae0, 0x4e0be0 and
0x43e960 run as original code. The two virtual calls are stubbed with fake vtables: slot 0x100 on the object at [obj+0x84e]
(the lazy cache source of 0x591ae0; skipped when [obj+0x85e] is already set) and slot 0x80 on the object at [o2+0x44]
(writes the three-float vector and the 4x3 matrix that the body uses)."""
from pilot import S, F


def _quad(c):
    e, r = c.emu, c.rng
    vals = [r.uniform(-1, 1) for _ in range(3)]
    if r.random() < 0.1:
        vals = [0.0, 0.0, 0.0]          # zero vector: both rotated vectors stay zero, so both dot products are exactly zero
    mats = [r.uniform(-1.5, 1.5) if r.random() < 0.8 else 0.0 for _ in range(12)]

    # raw stub handlers (no call log): the out-pointers are frame-local and differ between the two runs
    def h80(em, rr):
        for i, v in enumerate(vals):
            em.wf32(em.arg32(0) + 4 * i, v)
        for j, m in enumerate(mats):
            em.wf32(em.arg32(1) + 4 * j, m)
        em.ret(eax=0, argbytes=8)

    vt80 = e.fake_vtable('o44_5be810', 0x21, {0x80: h80})
    o44 = e.alloc(0x40, 4)
    e.w32(o44, vt80)
    o2 = e.alloc(0x60, 4)
    e.w32(o2 + 0x44, o44)

    def h100(em, rr):
        em.ret(eax=o2, argbytes=4)

    vt100 = e.fake_vtable('o84e_5be810', 0x41, {0x100: h100})
    o84e = e.alloc(0x40, 4)
    e.w32(o84e, vt100)
    obj = e.alloc(0x900, 4)
    e.w32(obj + 0x84e, o84e)
    if r.random() < 0.3:
        e.w32(obj + 0x85e, o2)           # cached: 0x591ae0 returns it without the slot-0x100 call
    self_ = e.alloc(0x940, 4)
    e.w32(self_ + 0x91a, obj)
    box = e.alloc(0x40, 4)
    for i in range(0x40 // 4):
        k = r.random()
        v = r.uniform(-40, 40) if k < 0.7 else (0.0 if k < 0.8 else r.uniform(-400, 400))
        e.wf32(box + 4 * i, v)
    if r.random() < 0.1:
        e.wbytes(box, bytes(0x40))       # all corners at the origin: both dot products are exactly zero
    if r.random() < 0.05:
        e.w32(self_ + 0x91a, 0)          # no receiver: returns 1 at once
    return [self_, box]


S(0x5be810, 'quad visibility test against two rotated planes (name GUESS)', 'thiscall', None, ret='al', gen=_quad,
  note='batch4012')
