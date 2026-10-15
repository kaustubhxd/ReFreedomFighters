"""specs_s77000.py - t8 batch 77000: 0x420bb0 (string manipulation with permission checks)"""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g420bb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    eng = sysobj(c)

    permit1 = r.choice([0, 1])
    permit2 = r.choice([0, 1])

    def check_hook1(em, k):
        em.ret(al=permit1)

    def check_hook2(em, k):
        em.ret(al=permit2)

    def ret_none(em, k):
        em.ret()

    # Create engine vtable with permission check functions
    ev = obj(c, 0x100, {
        0xd4: pystub(c, 1, this=True, side=check_hook1),
        0xd8: pystub(c, 1, this=True, side=check_hook2),
        0x160: pystub(c, 2, this=True, side=ret_none),
    })
    e.w32(eng + 0x9b, ev)

    # Create test object - key fields for testing
    me = rnd(c, 0x3000)
    flag = r.choice([0, 1])
    e.w8(me + 0x1a9b, flag)
    # String with a '.' in it so strrchr finds something
    e.wbytes(me + 0x2346, b"config.txt\x00")

    # Set up this object's vtable
    vt = obj(c, 0x40, {
        0x160: pystub(c, 2, this=True, side=ret_none),
    })
    e.w32(me, vt)

    return [me]


S(0x420bb0, 'GUESS permission check + string manipulation', 'thiscall', None, ret=None, gen=_g420bb0, note='batch77000')
