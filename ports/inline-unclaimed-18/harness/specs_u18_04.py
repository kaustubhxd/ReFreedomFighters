"""specs_u18_04.py - area 18, group 4 (unclaimed-18 thread)."""
from pilot import S
from ckit import obj, rnd, cstr


def _log(name, pop):
    def h(e, res):
        e.calllog.append((name, e.reg('ecx'), tuple(e.arg32(i) for i in range(pop // 4))))
        e.ret(argbytes=pop)
    return h


def _hooks(e):
    e.hook(0x45f8c0, _log('ZGEOM::RequestCustomDraw', 0))
    e.hook(0x562440, _log('CBaseWindow::Init', 0))
    e.hook(0x563510, _log('SetBackGroundPicture', 4))
    e.hook(0x563610, _log('window563610', 4))
    e.hook(0x4cbe50, _log('MYSTR::MYSTR', 4))


def _rcd(c):
    r = c.rng
    e = c.emu
    _hooks(e)
    o = rnd(c, 0x100)
    sub = rnd(c, 0x40)
    e.w32(sub + 0x23, r.choice([0x200002, 0x200001, r.getrandbits(32)]))
    e.w32(o + 0xc, sub)
    return [o]


S(0x43e150, 'ZSTDOBJ::RequestCustomDraw', 'thiscall', None, ret=None, gen=_rcd,
  note='u18; ZGEOM::RequestCustomDraw is a logging hook (original 9 bytes not exercised)')


def _aui(c):
    _hooks(c.emu)
    return [rnd(c, 0x400)]


S(0x57c210, 'ZFFAutoSave::Init', 'thiscall', None, ret=None, gen=_aui, note='u18; CBaseWindow calls are hooks')


def _sip(c):
    _hooks(c.emu)
    return [rnd(c, 0x900), rnd(c, 0x20)]


S(0x42fc90, 'ZSysInterface::StreamIdxPath', 'thiscall', None, ret='eax', gen=_sip, note='u18; MYSTR constructor is a hook')
