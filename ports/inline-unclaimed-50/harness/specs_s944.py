"""specs_s944.py - area 50 batch 944: 0x557b20 (thiscall, no args, plain ret, returns st0 = float [this]). The byte at this+4 is drawn 0, 2 (early exit)
or another value (the logger calls run). The engine logger (install_logger) and the sink's cdecl printf log their words; the engine hook at 0x7003b0 is
set to a stand-in that logs. The float at this is drawn finite."""
import struct
from pilot import S, F
from anim_common import only_hooks, rnd, install_logger


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    install_logger(c, nargs=3)
    self = rnd(c, 0x40)
    e.w32(self, struct.unpack('<I', struct.pack('<f', r.uniform(-100.0, 100.0)))[0])
    st = r.choice([0, 2, 1, 3, 7])
    e.wbytes(self + 4, bytes([st]))
    def hook(e, rr):          # always installed: with a null hook the original traps (int3), which is a fault, not a passing case
        e.calllog.append(('hook.7003b0',))
        e.ret(eax=0, argbytes=0)
    e.w32(0x7003b0, e.stub_fn('hook7003b0', hook))
    return [self]


S(0x557b20, 'log then return float (no name in map)', 'thiscall', None, ret='st0', gen=_gen, note='area50 batch944 (label D)')
