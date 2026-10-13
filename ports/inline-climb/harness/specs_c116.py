"""specs_c116.py - climb thread batch 116: ZGameOSD::SetHelpMessage (0x59a860)."""
import struct
from pilot import S, F
from ckit import obj, rnd, cstr, crt_setup, floats


def _shm(c):
    r = c.rng
    e = c.emu
    crt_setup(e)
    t0 = r.randint(0, 1 << 20)
    sys_ = rnd(c, 0x100)
    e.w32(sys_ + 0x40, t0)
    e.w32(0x70039c, sys_)
    osd = rnd(c, 0x2000)
    hud = rnd(c, 0x40) if r.random() < 0.85 else 0
    e.w32(osd + 0x1d0f, hud)
    last = (t0 - r.choice([0, 1, 0x5ff, 0x600, 0x601, 0x2000, r.randint(-100, 5000)])) / 1024.0
    e.mu.mem_write(osd + 0xe2, struct.pack('<f', last))
    text = cstr(e, r.choice([b'Hello', b'PickUp', b'', b'ClimbLadder'])) if r.random() < 0.9 else 0

    def h(e, res):
        e.calllog.append(('HelpMessage', e.reg('ecx'), e.arg32(0)))
        e.ret(argbytes=4)
    e.hook(0x5a84a0, h)

    def snd(e, res):
        e.calllog.append(('PlaySound', e.reg('ecx'), e.arg32(0)))
        e.ret(argbytes=4)
    e.hook(0x59a5e0, snd)
    return [osd, text, r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x59a860, 'ZGameOSD::SetHelpMessage', 'thiscall', None, ret=None, gen=_shm,
  note='c116; HelpMessage and PlaySound are hooks; the flag is a dword (any non-zero low byte means yes)')
