"""specs_s887.py - area 50, batch 887: 0x4daed0 (GUESS name Forward4daed0), thiscall, one stack arg (flag, tested by its low byte),
ret 4, void. this+0x54 is a sub-object (vt slot 0xc8: thiscall, one argument, logs its arg and ECX identity) or null. When it is
null and the flag is set, the engine hook at 0x7003b0 runs (a stub that logs and sets the object at +0x54 to a fresh object, so
the re-read after the hook is exercised). The flag values are 0, 1, 0x100 (low byte zero, nonzero dword) and 0xff."""
from pilot import S
from anim_common import rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x100)
    flag = r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)])
    sub_null = r.random() < 0.4
    sub = vt_object(c, 0x40, {0xc8: lambda e, rr: (e.calllog.append(('sub.c8', e.reg('ecx') == sub_addr[0], e.arg32(0))), e.ret(eax=0, argbytes=4))},
                    nslots=0x100, name='sub')
    sub_addr = [sub]
    fresh = vt_object(c, 0x40, {0xc8: lambda e, rr: (e.calllog.append(('fresh.c8', e.arg32(0))), e.ret(eax=0, argbytes=4))},
                      nslots=0x100, name='fresh')

    def hook(e, rr):
        e.calllog.append(('hook.7003b0', e.reg('ecx') == self))
        e.w32(self + 0x54, fresh)
        e.ret(eax=0, argbytes=0)

    h = e.stub_fn('hook7003b0', hook)
    e.w32(0x7003b0, h)
    e.w32(self + 0x54, 0 if sub_null else sub)
    return [self, flag]


S(0x4daed0, 'Forward4daed0 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch887')
