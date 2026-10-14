"""specs_s829.py - animation layer thread, batch 829: ZIKLNKOBJ copy and frame forwarders. The callees (base copy,
DBLK::NextBlock, base frame update) are hooked and logged; the forwarders themselves are what is checked."""
from pilot import S
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _cdb(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x462040: logged_fn('ZLNKOBJ::CopyDataBlock', 1),
                   0x4e1b30: logged_fn('DBLK::NextBlock', 0, ret=lambda e, a: r.getrandbits(32))})
    o = rnd(c, 0x200)
    return [o, r.getrandbits(32)]


def _cfu(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x461c40: logged_fn('ZLNKOBJ::ClassFrameUpdate', 0)})
    o = vt_object(c, 0x200, {0x410: vslot('vt410', 0)}, nslots=0x110, name='ziklnk')
    return [o]


S(0x466340, 'ZIKLNKOBJ::CopyDataBlock', 'thiscall', None, ret='eax', gen=_cdb, note='batch829')
S(0x465fb0, 'ZIKLNKOBJ::ClassFrameUpdate', 'thiscall', None, gen=_cfu, note='batch829')
