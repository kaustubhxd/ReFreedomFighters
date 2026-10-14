"""specs_s869.py - area 50, batch 869: 0x584610 CHitpointControl::Load2 (thiscall). The table at [0x7003b8] is a 0x1000-byte block
(count at +0xb61, the list header at +0x4a0: cur at +4, end at +8). The render manager's vt +0x4c gives a value (logged); the
list growth 0x4301c0 is stood in (cdecl, logged; no memory change). The object's byte at +0x63 is set in most cases."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    grow_calls = {'n': 0}

    def grow(e, rr):
        e.calllog.append(('grow.4301c0', e.arg32(0)))
        e.ret(eax=0, argbytes=0)

    def m4c(e, rr):
        e.calllog.append(('mgr.4c', e.arg32(0)))
        e.ret(eax=tv, argbytes=4)

    tv = r.getrandbits(32)
    only_hooks(c, {0x4301c0: grow})
    mgr = vt_object(c, 0x40, {0x4c: m4c}, nslots=0x100, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    tbl = rnd(c, 0x1000)
    e.w32(0x7003b8, tbl)
    e.w32(tbl + 0xb61, r.randint(0, 6))
    buf = rnd(c, 0x100)
    cur = buf + 4 * r.randint(0, 4)
    end = buf + 4 * r.choice([4, 5, 8])
    e.w32(tbl + 0x4a0 + 4, cur)
    e.w32(tbl + 0x4a0 + 8, end)
    self = rnd(c, 0x100)
    e.w8(self + 0x63, r.choice([0, 1, 1, 1]))
    e.w32(self + 0x44, r.getrandbits(32))
    return [self]


S(0x584610, 'CHitpointControl::Load2', 'thiscall', None, gen=_gen, note='area50 batch869')
