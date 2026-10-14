"""specs_s955.py - area 50 batch 955: 0x5196a0 (thiscall, one arg, ret 4, void). Stand-ins: 0x5003d0 (thiscall, one index arg; returns a block chosen at
gen time, logged), the object at this+0x14's slot +0x300 (no args; returns a float in st0; logged). The logger is install_logger; the hook at 0x7003b0 is
always installed (null traps in the original). The block's byte at +4 is drawn 0, 1, 2 or 3 so both branches run."""
import struct
from pilot import S
from anim_common import only_hooks, rnd, vt_object, install_logger


def _gen(c):
    e, r = c.emu, c.rng
    fval = r.uniform(-50.0, 50.0)

    def h300(e, rr):
        e.calllog.append(('obj.300',))
        e.ret(eax=0, argbytes=0, st0=fval)

    def h5003(e, rr):
        e.calllog.append(('5003d0', e.arg32(0), e.reg('ecx') != 0))
        e.ret(eax=blk, argbytes=4)

    only_hooks(c, {0x5003d0: h5003})
    install_logger(c, nargs=3)

    def hook(e, rr):
        e.calllog.append(('hook.7003b0',))
        e.ret(eax=0, argbytes=0)
    e.w32(0x7003b0, e.stub_fn('hook7003b0', hook))

    blk = rnd(c, 0x20)
    e.w32(blk, 0)
    e.wbytes(blk + 4, bytes([r.choice([0, 1, 2, 3])]))

    obj = vt_object(c, 0x40, {0x300: h300}, nslots=0x200, name='obj')
    self = rnd(c, 0x40)
    e.w32(self + 0x14, obj)
    a = rnd(c, 0x40)
    e.w32(a + 8, rnd(c, 0x20))
    return [self, a]


S(0x5196a0, 'store float or log (no name in map; 5003d0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch955 (residue-free claim)')
