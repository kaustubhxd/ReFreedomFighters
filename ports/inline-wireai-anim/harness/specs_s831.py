"""specs_s831.py - animation layer thread, batch 831: ZLNKOBJ / ZIKLNKOBJ push and pop. ZLNKOBJ::PushState (0x4639f0) is hooked
and logged; the pop pair runs as real code (it is the function being ported)."""
from pilot import S
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _obj(c, ik):
    e, r = c.emu, c.rng
    o = vt_object(c, 0x200, {0x2f8: vslot('vt2f8', 1), 0x330: vslot('vt330', 0),
                             0x360: vslot('vt360', 0), 0x364: vslot('vt364', 0)}, nslots=0x140, name='lnk')
    e.w32(o + 0x136, (r.getrandbits(32) & 0xfffdffff) | (0x20000 if ik else 0))
    e.w32(o + 0x159, r.getrandbits(32))
    for off in (0x5c, 0x60, 0x64, 0x68, 0x72, 0x76, 0x7a, 0x7e):
        e.w32(o + off, r.getrandbits(32))
    return o


def _push(c):
    only_hooks(c, {0x4639f0: logged_fn('ZLNKOBJ::PushState', 0)})
    return [_obj(c, c.rng.random() < 0.5)]


def _pop(c):
    only_hooks(c, {})
    return [_obj(c, c.rng.random() < 0.5)]


S(0x4673d0, 'ZIKLNKOBJ::PushState', 'thiscall', None, gen=_push, note='batch831')
S(0x467390, 'ZIKLNKOBJ::PopState', 'thiscall', None, gen=_pop, note='batch831')
S(0x463940, 'ZLNKOBJ::PopState', 'thiscall', None, gen=_pop, note='batch831')
