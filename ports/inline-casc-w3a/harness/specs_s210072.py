"""specs_s210072.py - Sonnet-w3a: 0x6160e0. 0x60f040 takes ECX, EDX and one stack argument (recorded by a custom stub); 0x64de00 and 0x6097d0 are thiscall recorders."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _r(c): return c.rng.getrandbits(32)


def g6160e0(c):
    clear_hooks(c)
    e = c.emu

    def f040(emu, res):
        emu.calllog.append(('f040', emu.reg('ecx'), emu.reg('edx'), emu.arg32(0)))
        emu.ret(eax=0x1234, argbytes=4)
    e.hook(0x60f040, lambda emu, r: f040(emu, r))
    hook_rec(c, 0x64de00, 1, ret=_r(c), this=True)
    hook_rec(c, 0x6097d0, 4, ret=_r(c), this=True)
    a = rnd(c, 0x10080)
    e.wbytes(a + 0x10051, _r(c).to_bytes(4, 'little'))
    inner = rnd(c, 0x20)
    s = rnd(c, 0x120)
    e.w32(s + 0xc, inner)
    return [s, a]


S(0x6160e0, 'apply_transform', 'thiscall', None, ret='eax', gen=g6160e0, note='batch210072')
