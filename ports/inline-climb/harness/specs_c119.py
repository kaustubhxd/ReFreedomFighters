"""specs_c119.py - climb thread batch 119: ZOnScreenDisplay::HelpMessage, CMessageBasics SetAlpha, SetText, flag setter."""
import struct
from pilot import S, F
from ckit import obj, rnd, cstr, floats


def _msg(c):
    r = c.rng
    e = c.emu
    m = rnd(c, 0x100)
    e.w8(m + 0x6a, r.choice([0, 1, 0xff]))
    e.wf32(m + 0x7a, c.fv()) if hasattr(e, 'wf32') else None
    e.w8(m + 8, r.getrandbits(8))
    return m


def _ctx(c):
    e = c.emu
    r = c.rng

    def setText(e, res):
        e.calllog.append(('ReformatText/NoSymbols', e.reg('ecx'), cstr(e, b'') if False else None))
        e.ret(argbytes=4)
    e.hook(0x5abf00, lambda e, res: (e.calllog.append(('ReformatText', e.reg('ecx'), bytes(e.rbytes(e.arg32(0), 16)).split(b'\0')[0])), e.ret(argbytes=4)))
    e.hook(0x5ac140, lambda e, res: (e.calllog.append(('ReformatTextNoSymbols', e.reg('ecx'), bytes(e.rbytes(e.arg32(0), 16)).split(b'\0')[0])), e.ret(argbytes=4)))


def _setalpha(c):
    return [_msg(c), c.fv()]


S(0x5ac5b0, 'CMessageBasics::SetAlpha', 'thiscall', None, ret=None, gen=lambda c: [_msg(c), F(c.fv())], note='c119')
S(0x5acac0, 'CMessageBasics flag setter (guess)', 'thiscall', None, ret=None,
  gen=lambda c: [_msg(c), c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])], note='c119')


def _settext(c):
    _ctx(c)
    e = c.emu
    m = _msg(c)
    t = cstr(e, c.rng.choice([b'Hello', b'PickUp', b'', b'ClimbLadder'])) if c.rng.random() < 0.9 else 0
    return [m, t]


S(0x5ac940, 'CMessageBasics::SetText', 'thiscall', None, ret=None, gen=_settext,
  note='c119; ReformatText and ReformatTextNoSymbols are hooks')


def _hm(c):
    r = c.rng
    e = c.emu
    _ctx(c)
    self_ = rnd(c, 0x1000)
    msg = _msg(c)
    e.w32(self_ + 0x630, msg)
    last = cstr(e, b'Hello') if r.random() < 0.5 else 0
    e.w32(self_ + 0x650, last)
    e.w32(self_ + 0x374, r.getrandbits(32))
    txt = last if (last and r.random() < 0.3) else (cstr(e, r.choice([b'Hello', b'PickUp', b'ClimbLadder'])) if r.random() < 0.9 else 0)
    return [self_, txt]


S(0x5a84a0, 'ZOnScreenDisplay::HelpMessage', 'thiscall', None, ret=None, gen=_hm,
  note='c119; ReformatText and ReformatTextNoSymbols are hooks; the message object is a fake')
