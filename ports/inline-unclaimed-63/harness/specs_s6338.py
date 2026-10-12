"""specs_s6338.py - unclaimed-63 gap-band batch 38: 0x4d23d0 (C-set; thiscall, one flags argument, ret 4, returns this). SEH tagged: the
SEH frame and the cookie are not reproduced (see the source comment).
Fakes per case (the image is restored between runs; hooks are set each gen):
  * 0x4cee30 (thiscall, ret 8), 0x4cd180 (thiscall, ret 0) and 0x4ccf60 (thiscall, ret 0): hooks that record ECX and their stack
    arguments (the original code is not run);
  * the object at this+0x4008 has a fake vtable whose slot +0xc records ECX (ret 0);
  * 0x634273 (cdecl): a hook that records its two arguments.
this is a 0x4100-byte heap block, so +0x40b4, +0x4004, +0x4008 and +0x40c4 are inside it. flags is random, so the delete path runs
in half the cases."""
from pilot import S


def _gen_d3d0(c):
    e = c.emu
    self_ = e.alloc(0x4100, 4)
    e.wbytes(self_, bytes(0x4100))
    e.w32(self_ + 0x4004, c.rng.getrandbits(32))

    def rec(name, nargs, slot_args):
        def h(em, args):
            em.calllog.append((name, None, em.reg('ecx'), tuple(em.arg32(k) for k in range(nargs))))
            em.ret(eax=0, argbytes=slot_args)
        return h
    e.hook(0x4cee30, rec('pool.init', 2, 8))
    e.hook(0x4cd180, rec('helper.4cd180', 0, 0))
    e.hook(0x4ccf60, rec('helper.4ccf60', 0, 0))
    e.hook(0x634273, lambda em, a: (em.calllog.append(('deleter', None, None, (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=0)))
    obj = self_ + 0x4008
    vt = e.fake_vtable('obj', 4, {0xc: lambda em, a: (em.calllog.append(('obj.init', 0xc, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0))})
    e.w32(obj, vt)
    e.mu.ctl_flush_tb()
    return [self_, c.rng.getrandbits(32)]


S(0x4d23d0, 'unnamed C-set 0x4d23d0 thiscall', 'thiscall', None, ret='eax', gen=_gen_d3d0,
  note='unclaimed-63 band batch 38; SEH frame not reproduced')
