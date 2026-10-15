"""specs_s53001.py - u6 batch 53001: 0x4b7240 (flag-driven update through engine tables). Hooked: 0x467260, 0x43ec00, 0x441890 (recorders); 0x4dc130 runs as real code.
Vtable slots on this (0x64, 0x9c, 0x94), the table object [eng+0x9b] (0x58, 0x60), [eng+0x1a9f] (0x70) and the target object (0x1e0, 0x3f8) are recorder stubs."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g4b7240(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ev = r.choice([0, 1, 0x100, r.getrandbits(32) | 1])        # results returned in al

    def tgt():
        e2 = obj(c, 0x80, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 1, 0x100, 0x77]), this=True), 0x3f8: pystub(c, 1, this=True)})
        return e2
    t = tgt() if r.random() < 0.8 else 0
    # object returned by this.vslot 0x94: [+0x54] = t, [+0x50] = struct (or 0) for the real 0x4dc130
    o = rnd(c, 0x80)
    e.w32(o + 0x54, t)
    e.w32(o + 0x50, rnd(c, 0x80) if r.random() < 0.8 else 0)
    ent = rnd(c, 0x100)
    n_ret = r.getrandbits(32)
    mgr_slots = {0x58: pystub(c, 1, ret=r.choice([0, 1, 1, 1, 5]), this=True),
                 0x60: pystub(c, 1, ret=(ent if r.random() < 0.9 else 0), this=True)}
    so = sysobj(c, table_slots=mgr_slots)
    if r.random() < 0.9:
        e.w32(so + 0x1a9f, obj(c, 0x80, {0x70: pystub(c, 1, ret=r.choice([0, 1, 1, 0x100, 5]), this=True)}))
    else:
        e.w32(so + 0x1a9f, 0)
    me = obj(c, 0x190, {0x64: pystub(c, 1, this=True), 0x9c: pystub(c, 0, this=True), 0x94: pystub(c, 2, ret=o, this=True)})
    e.wbytes(me + 0x180, bytes([r.choice([0, 1, 1]), r.choice([0, 1])]))
    e.w32(me + 0x50, rnd(c, 0x10) if r.random() < 0.95 else 0)
    if e.r32(me + 0x50) == 0:
        e.w32(me + 0x50, rnd(c, 0x10))
    e.w32(me + 0x54, r.choice([0, 0, 1, 1, 2, r.getrandbits(32)]))
    e.w32(me + 0x58, r.choice([0, 1, 1, 2, r.getrandbits(32)]))
    e.w32(me + 0x5c, r.getrandbits(32))  # float passed to ext_441890
    e.w32(me + 0x60, r.getrandbits(32))  # stored in result objects at +0x88
    e.w32(me + 0x64, r.getrandbits(32))
    hook_rec(c, 0x467260, 3, this=True, pop=0xc, ret=n_ret)
    hook_rec(c, 0x43ec00, 6, this=True, pop=0x18, ret=r.getrandbits(32))
    hook_rec(c, 0x441890, 1, this=True, pop=4)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x4b7240, 'GUESS flag-driven update through engine tables', 'thiscall', None, ret=None, gen=g4b7240, nan_heap=True, note='batch53001')
