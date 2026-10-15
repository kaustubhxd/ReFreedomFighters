"""specs_c115.py - climb thread batch 115: ZFFHERO::DisplayUseAction (0x591190)."""
import struct
from pilot import S
from ckit import obj, rnd, cstr, crt_setup

_NAMES = [b'PickUp', b'RaiseFlag', b'CancelRaiseFlag', b'UseMachineGun', b'LeaveMachineGun', b'Recruit', b'Talk',
          b'OpenGate', b'CancelOpenGate', b'OpenSewer', b'CancelOpenSewer', b'AccessSewer', b'PlaceC4',
          b'CancelPlaceC4', b'GiveHealth', b'ClimbLadder']


def _due(c):
    r = c.rng
    e = c.emu
    crt_setup(e)
    hero = rnd(c, 0xa00)
    cur = r.choice(list(range(0, 18)) + [0x12, 0x20, 0xffffffff, r.getrandbits(32)])
    e.w32(hero + 0x9d7, cur)
    e.w32(hero + 0x9d3, cur if r.random() < 0.4 else r.getrandbits(32))
    stored = cstr(e, r.choice(_NAMES)) if r.random() < 0.5 else 0
    e.w32(hero + 0x9df, stored)
    osd = rnd(c, 0x2000)
    e.w32(hero + 0x852, osd)

    def acts_slot0(e, t, a):
        cat, name = bytes(e.rbytes(a[0], 16)).split(b'\0')[0], bytes(e.rbytes(a[1], 32)).split(b'\0')[0]
        ret = a[1] if r.random() < 0.85 else 0   # a null result means "nothing to show"
        return (ret, None, (cat, name))
    acts = obj(e, 'acts', 0x40, {0: (2, acts_slot0)})
    eng = rnd(c, 0x1000)
    e.w32(eng + 0xae4, acts)
    sys_ = rnd(c, 0x100)
    e.w32(sys_ + 0x9b, eng)
    e.w32(0x70039c, sys_)

    def setHelp(e, res):
        # the flag is a dword on the stack whose high bytes are the caller's leftover ebx; the callee reads one byte
        e.calllog.append(('SetHelpMessage', e.reg('ecx'), e.arg32(0), e.arg32(1) & 0xff))
        e.ret(argbytes=8)
    e.hook(0x59a860, setHelp)
    return [hero]


S(0x591190, 'ZFFHERO::DisplayUseAction', 'thiscall', None, ret=None, gen=_due,
  note='c115; SetHelpMessage is a hook (its flag logged as one byte); the actions object is a logging fake')
