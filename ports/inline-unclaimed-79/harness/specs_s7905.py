"""specs_s7905.py - unclaimed-79 batch 5 (docs/20-unclaimed-79.md): ZParamAnim::Command (0x4a28e0). The object has logging fake
vtable slots (0x3c, 0x64, 0x68) and a +0x44 object with slot +0x2c. The system interface global's +0x40 holds a random dword. The
command is one of the eight words (0x401, 0x400, the word at +0x11a, and the globals 0x7002e8..0x7002f4) or random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cmd(c):
    self_ = _rnd(c, 0x200)
    sub = _rnd(c, 0x100)
    c.emu.w32(sub, c.emu.fake_vtable('ZParamAnim-sub', 0x10, {0x2c: logged_slot('ZParamAnim::sub2c', eax=0, argbytes=0)}))
    c.emu.w32(self_ + 0x44, sub)
    vs = c.emu.fake_vtable('ZParamAnim', 0x40, {
        0x3c: logged_slot('ZParamAnim::slot3c', eax=0, argbytes=0),
        0x64: logged_slot('ZParamAnim::slot64', eax=0, argbytes=4),
        0x68: logged_slot('ZParamAnim::slot68', eax=0, argbytes=8),
    })
    c.emu.w32(self_, vs)
    c.emu.w8(self_ + 0x11c, c.rng.choice([0, 1]))
    c.emu.w16(self_ + 0x11a, c.rng.getrandbits(16))
    for w in (0x7002e8, 0x7002ec, 0x7002f0, 0x7002f4):
        c.emu.w16(w, c.rng.getrandbits(16))
    cmd = c.rng.choice([0x401, 0x400, c.rng.getrandbits(16)])
    words = [0x7002e8, 0x7002ec, 0x7002f0, 0x7002f4]
    if c.rng.random() < 0.7:
        pick = c.rng.random()
        if pick < 0.2:
            c.emu.w16(self_ + 0x11a, cmd)
        else:
            c.emu.w16(c.rng.choice(words), cmd)
    sys_ = _rnd(c, 0x100)
    c.emu.w32(sys_ + 0x40, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, sys_)
    return [self_, cmd, c.rng.getrandbits(32)]


S(0x4a28e0, 'ZParamAnim::Command(unsigned short, void*) thiscall', 'thiscall', None, ret='eax', gen=_cmd,
  note='unclaimed-79 batch 5; command dispatch over 0x401, 0x400, +0x11a and four globals; always returns 0')
