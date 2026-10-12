"""specs_s6351.py - unclaimed-63 gap-band batch 51: 0x4d3b30 (C-set; thiscall, three stack arguments s, o, c, ret 0xc).
Fakes per case (the image is restored between runs):
  * the search value c is one of the 18 type dwords of the table at 0x6e7a38 (read from the image), so the record is always found
    (a miss would fault in the original, and in the port alike);
  * o: a fake object with a count (+0x14), and a walk (+0x4c resets; +0x5c writes 1 to its flag argument while items remain, 0 at the
    end, and returns the next item): n is 0 to 3 items, and the walk makes n+1 calls;
  * the logger 0x700390 is a fake whose slot +0x24 is cdecl and records its arguments (three when the format is 0x6963cc, two for
    0x696404);
  * this: its vtable slot +0xac (caller-cleaned, plain ret) records ECX and its five arguments. A stack-looking argument (the saved
    buffer pointer, or the buffer itself) is recorded as 'stk' and not as its address; the callee is passed contents only;
  * s is a random NUL-terminated string (0 to 8 characters)."""
from pilot import S


def _gen_3b30(c):
    e = c.emu
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(0x40))
    k = c.rng.randrange(0, 18)
    tv = e.r32(0x6e7a38 + 20 * k)
    n = c.rng.randint(0, 3)
    items = [c.rng.getrandbits(32) for _ in range(n)]
    pos = [0]
    flag = [0]

    def slot14(em, a):
        em.calllog.append(('O.count', 0x14, em.reg('ecx'), ()))
        em.ret(eax=n, argbytes=0)

    def slot4c(em, a):
        em.calllog.append(('O.reset', 0x4c, em.reg('ecx'), ()))
        pos[0] = 0
        em.ret(eax=0, argbytes=4)

    def slot5c(em, a):
        em.calllog.append(('O.next', 0x5c, em.reg('ecx'), ()))
        if pos[0] < len(items):
            item = items[pos[0]]
            pos[0] += 1
            em.w32(em.arg32(0), 1)
            em.ret(eax=item, argbytes=4)
        else:
            em.w32(em.arg32(0), 0)
            em.ret(eax=0, argbytes=4)
    o = e.alloc(0x40, 4)
    e.w32(o, e.fake_vtable('O', 0x100 // 4, {0x14: slot14, 0x4c: slot4c, 0x5c: slot5c}))

    def logfn(em, a):
        nargs = 3 if em.arg32(1) == 0x6963cc else 2
        em.calllog.append(('log.24', 0x24, None, tuple(em.arg32(k2) for k2 in range(nargs))))
        em.ret(eax=0, argbytes=0)
    lg = e.alloc(0x40, 4)
    e.w32(lg, e.fake_vtable('lg', 0x100 // 4, {0x24: logfn}))
    e.w32(0x700390, lg)

    def mask(em, v):
        return 'stk' if abs(v - em.reg('esp')) < 0x4000 else v

    def callee(em, a):
        em.calllog.append(('this.ac', 0xac, em.reg('ecx'), tuple(mask(em, em.arg32(k2)) for k2 in range(5))))
        em.ret(eax=0, argbytes=0)
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(0x40))
    e.w32(this, e.fake_vtable('this', 0x100 // 4, {0xac: callee}))
    s_len = c.rng.randint(0, 8)
    s = e.alloc(s_len + 4, 4)
    e.wbytes(s, bytes([c.rng.randint(1, 255) for _ in range(s_len)]) + b'\x00')
    e.mu.ctl_flush_tb()
    return [this, s, o, tv]


S(0x4d3b30, 'unnamed C-set 0x4d3b30 thiscall', 'thiscall', None, ret=None, gen=_gen_3b30,
  note='unclaimed-63 band batch 51; 0x633654 cookie check not reproduced')
