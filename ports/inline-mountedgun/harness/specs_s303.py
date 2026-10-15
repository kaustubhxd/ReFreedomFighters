"""specs_s303.py - mounted gun batch 303: setUser, SendMachineGunNoGood, FrameUpdate (nest_fixture)."""
from pilot import S
from mg_helpers import flush
from nest_fixture import nest, actor


def _setuser(c):
    r = c.rng
    n = nest(c)
    k = r.random()
    user = 0 if k < 0.25 else (n['cur'] if k < 0.4 else actor(c))
    flush(c)
    return [n['self'], user]


def _nogood(c):
    n = nest(c, cur_user=actor(c))
    flush(c)
    return [n['self']]


def _frame(c):
    n = nest(c)
    c.emu.w16(0x714380, c.rng.getrandbits(16))
    flush(c)
    return [n['self']]


S(0x5c9330, 'MGCG setUser (unnamed)', 'thiscall', None, gen=_setuser, note='batch303')
S(0x5c92a0, 'CMachinegunControlGroup::SendMachineGunNoGood', 'thiscall', None, gen=_nogood, note='batch303')
S(0x5c8d40, 'CMachinegunControlGroup::FrameUpdate', 'thiscall', None, gen=_frame, note='batch303')
