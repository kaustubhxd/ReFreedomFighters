"""specs_s213.py - ladder thread batches 213 (ZIKLNKOBJ dispatcher forwarders) and 214 (ZActionDispatcher)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _action(c, name='action'):
    r = c.rng
    a = K.rnd(c, 0x20)
    rets = {o: r.getrandbits(32) & (0xff if r.random() < 0.3 else 0xffffffff) for o in (4, 8, 0xc, 0x10, 0x14)}
    for o in (8, 0xc, 0x10):
        if r.random() < 0.4:
            rets[o] = rets[o] & ~0xff        # AL = 0: "failed"
    slots = {0: (1, lambda e2, a_: (0x1234, None, None))}
    for o in (4, 8, 0xc, 0x10, 0x14):
        slots[o] = (0, lambda e2, a_, o=o: (rets[o], None, None))
    c.emu.w32(a, K.vt(c, name, slots, nslots=8))
    return a


def _dispatcher(c, fake=True):
    r = c.rng
    d = K.rnd(c, 0x10)
    if fake:
        ret = {o: r.getrandbits(32) for o in range(0, 0x18, 4)}
        c.emu.w32(d, K.vt(c, 'dispatcher', {o: (1 if o in (0, 4) else 0, lambda e2, a_, o=o: (ret[o], None, None))
                                            for o in range(0, 0x18, 4)}, nslots=8))
    c.emu.w32(d + 4, _action(c) if r.random() < 0.75 else 0)
    return d


def _ik(c):
    s = K.rnd(c, 0x200)
    c.emu.w32(s + 0x1ce, _dispatcher(c))
    return s


def _create(c):
    e, r = c.emu, c.rng

    def new(e2, res):
        n = e2.arg32(0)
        p = 0 if r.random() < 0.15 else K.rnd(c, max(n, 4))
        e2.calllog.append(('new', n, p))
        e2.ret(eax=p)
    e.hook(0x41e290, new)
    return [K.rnd(c, 0x200)]


def _dhooks(c):
    def dl(e2, res):
        e2.calllog.append(('delete', e2.arg32(0), e2.arg32(1)))
        e2.ret()
    c.emu.hook(0x634273, dl)


def _self_disp(c):
    _dhooks(c)
    return _dispatcher(c)


S(0x466380, 'ZIKLNKOBJ::CreateActionDispatcher', 'thiscall', None, ret=None, gen=_create, note='batch213')
S(0x4675d0, 'ZIKLNKOBJ::RemoveCurrentLnkAction', 'thiscall', None, ret='eax', gen=lambda c: [_ik(c)], note='batch213')
S(0x467cf0, 'ZIKLNKOBJ::UpdateCurrentLnkAction', 'thiscall', None, ret='eax', gen=lambda c: [_ik(c)], note='batch213')
S(0x465a70, 'ZIKLNKOBJ::CallBackLnkActionTarget', 'thiscall', None, ret='eax', gen=lambda c: [_ik(c)], note='batch213')
S(0x465a60, 'ZIKLNKOBJ::CallBackLnkActionBone', 'thiscall', None, ret='al',
  gen=lambda c: [_ik(c)] + [c.rng.getrandbits(32) for _ in range(4)], note='batch213')
S(0x466400, 'ZIKLNKOBJ::CurrentLnkActionId', 'thiscall', None, ret='eax', gen=lambda c: [_ik(c)], note='batch213')
S(0x47fb10, 'ZActionDispatcher::ctor', 'thiscall', None, ret='eax', gen=lambda c: [K.rnd(c, 0x10), c.rng.getrandbits(32)], note='batch214')
S(0x47fb30, 'ZActionDispatcher::scalar deleting dtor', 'thiscall', None, ret='eax',
  gen=lambda c: [_self_disp(c), c.rng.getrandbits(32)], note='batch214')
S(0x47fb70, 'ZActionDispatcher::CallBack', 'thiscall', None, ret=None, gen=lambda c: [_dispatcher(c)], note='batch214')
S(0x47fb90, 'ZActionDispatcher::DropAction', 'thiscall', None, ret=None, gen=lambda c: [_dispatcher(c)], note='batch214')
S(0x47fba0, 'ZActionDispatcher::Execute', 'thiscall', None, ret='al', gen=lambda c: [_dispatcher(c), _action(c, 'new action')], note='batch214')
S(0x47fbe0, 'ZActionDispatcher::RemoveCurrentAction', 'thiscall', None, ret=None, gen=lambda c: [_dispatcher(c)], note='batch214')
S(0x47fc10, 'ZActionDispatcher::Update', 'thiscall', None, ret=None, gen=lambda c: [_dispatcher(c)], note='batch214')
