"""specs_s4008.py - area 70 batch 4008: 0x440f10. The global 0x70039c holds a fake system object; its +0x9b is a fake render
manager whose slot 0x58 (GUESS stub) returns null or a heap block. The exe callee 0x65f4b0 (ret 0x14) runs as exe code.
The function is stdcall: five dword arguments on the stack, ECX unused."""
from pilot import S, F


def _vt(c, name, slots, nslots):
    e = c.emu
    hs = {}
    for off, (nargs, fn) in slots.items():
        def h(em, rr, off=off, nargs=nargs, fn=fn):
            args = [em.arg32(k) for k in range(nargs)]
            eax, logged = fn(em, args)
            em.calllog.append((name, off, em.reg('ecx'), logged))
            em.ret(eax=eax, argbytes=4 * nargs)
        hs[off] = h
    return e.fake_vtable(name, nslots, hs)


def _rm(c):
    e, r = c.emu, c.rng
    sysobj = e.alloc(0x1b00, 4)
    e.w32(0x70039c, sysobj)
    e._image_dirty = True
    rm = e.alloc(0x100, 4)
    e.w32(sysobj + 0x9b, rm)
    e.w32(rm + 0x14, r.getrandbits(32))
    blk = e.alloc(0x40, 4)
    e.wbytes(blk, bytes(r.getrandbits(8) for _ in range(0x40)))
    ret_blk = blk if r.random() < 0.7 else 0
    def s58(em, a):
        em.calllog.append(('s58', a[0] if a else 0))
        return ret_blk, ()
    e.w32(rm, _vt(c, 'rm58', {0x58: (1, s58)}, 0x5c // 4))
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x440f10, 'render slot 0x58 then no-op 0x65f4b0 (name GUESS)', 'stdcall', None, ret='al', gen=_rm, note='batch4008')
