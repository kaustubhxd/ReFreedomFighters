"""specs_s35195.py - 0x4a77b0 (thiscall(s) ret 4, ret='al', nan_heap). this: 0x140 random bytes. s: stream object whose slots 0x3c, 0x44, 0x4c, 0x54, 0x60, 0x68, 0x70 are Python handlers (1 arg each, logged in the call log with the slot name, so every one of the 26 calls is compared). 0x4e74d0 hooked (thiscall, 1 arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g4a77b0(c):
    clear_hooks(c)
    e = c.emu

    def mk(name):
        def h(em, res_):
            em.calllog.append((name, em.reg('ecx'), em.arg32(0)))
            em.ret(argbytes=4)
        return e.stub_fn(name, h)
    s = obj(c, 0x20, {off: mk('slot%x' % off) for off in (0x3c, 0x44, 0x4c, 0x54, 0x60, 0x68, 0x70)}, nslots=0x1d)
    hook_rec(c, 0x4e74d0, 1, this=True, pop=4)
    return [rnd(c, 0x140), s]


S(0x4a77b0, 'GUESS write object fields through a stream', 'thiscall', None, ret='al', gen=_g4a77b0, nan_heap=True, note='batch35195')
