"""specs_u18_08.py - area 18, group 8 (unclaimed-18 thread)."""
import struct
from pilot import S
from ckit import obj, rnd, rvt


def _csi(c):
    r = c.rng
    out = rnd(c, 0x10)
    src = rnd(c, 0x10)
    return [out, src, r.getrandbits(32)]


S(0x661bd0, 'ZCollisionGC::CreateSubStripId', 'stdcall', None, ret=None, gen=_csi,
  note='u18; stdcall, three stack args (ret 0xc)')


def _cd(c):
    r = c.rng
    e = c.emu
    e.hook(0x4f9c60, lambda e, res: (e.calllog.append(('ZCONTROL::CopyData', e.reg('ecx'), e.arg32(0))), e.ret(argbytes=4)))
    self_ = rnd(c, 0x200)
    src = rnd(c, 0x200)
    return [self_, src]


S(0x4f7dd0, 'ZSlider::CopyData', 'thiscall', None, ret=None, gen=_cd, note='u18; ZCONTROL::CopyData is a logging hook')


def _ofl(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    e.w8(o + 0x6c, r.getrandbits(8))
    e.w32(o, rvt(e, 'control', {0x2ec: (1, lambda e, t, a: (r.getrandbits(32), None, (a[0],)))}, nslots=0x2f0 // 4))
    return [o, r.getrandbits(32)]


S(0x4fa350, 'ZCONTROL::OnFocusLost', 'thiscall', None, ret='al', gen=_ofl, note='u18')


def _rpr(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    target = rnd(c, 0x20)
    choice = r.choice(['null', 'ptr'])

    def get(e, t, a):
        return (0 if choice == 'null' else target, None, (a[0],))
    e.w32(o, rvt(e, 'reftab', {0x74: (1, get)}, nslots=0x78 // 4))
    return [o, rnd(c, 0x20)]


S(0x4cf3d0, 'REFTAB::RunPrevRef', 'thiscall', None, ret='eax', gen=_rpr, note='u18')
