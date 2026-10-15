"""specs_c1032.py - camera batch 1032: ZCamHelper scalar deleting destructor."""
from pilot import S
from camgen import rnd, Log, handler


def _dd(c):
    r = c.rng
    log = Log(c, 256)
    c.emu.hook(0x5cd450, handler(log, 0x5cd450, 0))

    def empty(e, res):  # cdecl: the caller pops the two arguments, so this stub does not pop
        log.put(0x4690b0, e.arg32(0), e.arg32(1))
        e.ret(argbytes=0)
    c.emu.hook(0x4690b0, empty)
    hook = c.emu.stub_fn('deletehook', handler(log, 0x7003b0, 0)) if r.random() < 0.9 else 0
    c.emu.w32(0x7003b0, hook)
    h = rnd(c, 0x40)
    return [h, r.getrandbits(3)]


S(0x5cd4e0, 'ZCamHelper deleting dtor', 'thiscall', gen=_dd)
