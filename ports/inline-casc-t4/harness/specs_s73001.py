from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    hook_rec(c, 0x467410, 6, this=True)
    opaque = rnd(c, 0x20)
    table = sysobj(c, table_slots={0x4c: pystub(c, 1, ret=opaque, this=True)})
    state = rnd(c, 0x100)
    e.w32(state + 0x31, 0)
    e.w32(state + 0x35, 0)
    e.w32(state + 0x39, 0)
    for off in (0x3d, 0x41, 0x45, 0x49):
        e.w32(state + off, 0)
    state_obj = obj(c, 0x40, {0x08: pystub(c, 2, this=True, pop=0)})
    caller_obj = obj(c, 0x40, {0x2d0: pystub(c, 2, this=True, pop=0)})
    me = rnd(c, 0x20)
    e.w32(me + 8, opaque)
    e.w32(me + 0xc, r.getrandbits(32))
    e.w32(me + 0x10, state)
    # Keep nested state virtual callbacks separate from the state storage.
    e.w32(state + 0, e.r32(state_obj))
    e.w32(me + 8, caller_obj)
    # Slot 0x4c argument is opaque; the sys table is reached through [sys+0x9b].
    return [me]


S(0x486020, 'GUESS update state and emit two commands', 'thiscall', None, ret='al', gen=gen)
