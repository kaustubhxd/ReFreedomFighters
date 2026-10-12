"""specs_s607.py - band 0x421000-0x441000, batch 607: CConfiguration volume setters (0x433370, 0x433490, 0x4334e0, 0x433530).
The notify helper 0x431410 is hooked by address (thiscall, two arguments, recorded). The sound object at [[0x70039c]+0x1a9f]
is a fake object whose slot 0x104 records (kind, value, 2); the object is absent in some cases (the exe skips the call).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402

SYS_GLOBAL = 0x70039c
SND_OFF = 0x1a9f


def _setup(c):
    r = c.rng
    cfg = c.emu.alloc(0x200, 16)
    c.emu.wbytes(cfg, bytes(r.getrandbits(8) for _ in range(0x200)))
    # the stored volumes: each one is set to the argument half the time (no change) and otherwise random
    for off in (0xe8, 0xec, 0xf0, 0xf4):
        c.emu.w32(cfg + off, r.getrandbits(8))
    sys_ = c.emu.alloc(0x1b00, 16)
    c.emu.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0x1b00)))
    c.emu.w32(SYS_GLOBAL, sys_)

    def notify(e, rr):
        e.calllog.append(('cfg.notify', 0x431410, e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(argbytes=8)
    c.emu.hook(0x431410, notify)

    def slot104(e, rr):
        e.calllog.append(('snd.104', 0x104, e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=12)
    snd = c.emu.fake_object('snd', 0x40, nslots=0x110, slots={0x104: slot104}) if r.random() < 0.8 else 0
    c.emu.w32(sys_ + SND_OFF, snd)
    return cfg


def _gen_for(off_stored):
    def gen(c):
        cfg = _setup(c)
        r = c.rng
        cur = c.emu.r32(cfg + off_stored)
        v = cur if r.random() < 0.4 else r.getrandbits(32)
        return [cfg, v]
    return gen


S(0x433370, 'CConfiguration::SetIntroMusicVolume', 'thiscall', None, ret=None, gen=_gen_for(0xf0))
S(0x433490, 'CConfiguration::SetMusicVolume', 'thiscall', None, ret=None, gen=_gen_for(0xec))
S(0x4334e0, 'CConfiguration::SetSfxVolume', 'thiscall', None, ret=None, gen=_gen_for(0xe8))
S(0x433530, 'CConfiguration::SetSpeechVolume', 'thiscall', None, ret=None, gen=_gen_for(0xf0))
