"""specs_s827.py - animation layer thread, batch 827: ZIKLNKOBJ forwarders to the current link action."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, vslot


def _act(c, with_sub=True):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    sub = vt_object(c, 0x20, {4: vslot('sub.Id', 0, ret=r.getrandbits(32))}, name='sub')
    action = vt_object(c, 0x20, {0xc: vslot('act.CallBackTarget', 0), 0x10: vslot('act.Remove', 0),
                                 8: vslot('act.Update', 0)}, name='action')
    e.w32(action + 4, sub if (with_sub and r.random() < 0.7) else 0)
    o = vt_object(c, 0x200, {0x2a8: vslot('self.Ground', 2)}, nslots=0xc0, name='ziklnk')
    e.w32(o + 0x1ce, action)
    return [o]


def _disp(c):
    o = _act(c)[0]
    return [o, c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])]


S(0x465a70, 'ZIKLNKOBJ::CallBackLnkActionTarget', 'thiscall', None, gen=lambda c: _act(c), note='batch827')
S(0x4675d0, 'ZIKLNKOBJ::RemoveCurrentLnkAction', 'thiscall', None, gen=lambda c: _act(c), note='batch827')
S(0x467cf0, 'ZIKLNKOBJ::UpdateCurrentLnkAction', 'thiscall', None, gen=lambda c: _act(c), note='batch827')
S(0x466400, 'ZIKLNKOBJ::CurrentLnkActionId', 'thiscall', None, ret='eax', gen=lambda c: _act(c), note='batch827')
S(0x466480, 'ZIKLNKOBJ::DisplayGround', 'thiscall', None, gen=_disp, note='batch827')
