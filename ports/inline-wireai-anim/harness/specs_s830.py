"""specs_s830.py - animation layer thread, batch 830: ZIKLNKOBJ scalar deleting dtor and CopyData(ZGEOM*).
The base destructor, the geometry delete, the leak hook and the base CopyData are hooked and logged."""
from pilot import S
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _cdecl_log(name, nargs):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name,) + args)
        e.ret(eax=0, argbytes=0)   # cdecl: caller pops
    return h


def _dtor(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x465660: logged_fn('ZIKLNKOBJ::~base', 0),
                   0x45c510: _cdecl_log('ZGEOM::operator delete', 1),
                   0x4690b0: _cdecl_log('leak.hook', 2)})
    o = rnd(c, 0x200)
    return [o, r.choice([0, 1, 3, 4, 5, 6, 7, r.getrandbits(32)])]


def _cd(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x45d5b0: logged_fn('ZGEOM::CopyData', 1)})
    g = vt_object(c, 0x40, {0x1e0: vslot('geom.IsClass', 1, ret=r.choice([0, 1]))}, name='geom')
    o = vt_object(c, 0x200, {0x2e4: vslot('self.Copy2e4', 1)}, nslots=0x180, name='ziklnk')
    return [o, g]


S(0x465720, 'ZIKLNKOBJ::~ZIKLNKOBJ (scalar deleting)', 'thiscall', None, ret='eax', gen=_dtor, note='batch830')
S(0x462000, 'ZIKLNKOBJ::CopyData', 'thiscall', None, gen=_cd, note='batch830')
