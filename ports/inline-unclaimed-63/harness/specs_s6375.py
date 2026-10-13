"""specs_s6375.py - unclaimed-63 gap-band batch 75: 0x4d9bf0 (thiscall, no arguments) and 0x4dc840 (thiscall, one stack argument b,
ret 4). Both have an SEH frame and the 0x633654 cookie check, neither reproduced (tagged).
Fakes per case (the image is restored between runs; hooks set in gen):
  * logger 0x700390: slot +0x20 (file, line) returns the log object (thiscall, ret 8); the log object's slot +0x2c is a cdecl
    printf-like that records only the arguments its caller pushed (3 for 0x4d9bf0, 4 for 0x4dc840);
  * hook 0x4da2f0 (thiscall, ret 8): the first argument is the caller's stack buffer, so it is not recorded; the fake writes a heap
    pointer into the buffer's first dword, records ECX and the second argument, and returns the buffer;
  * hook 0x4cc1d0 (thiscall, no arguments) returns the first dword of its object plus 8 (a heap value); hook 0x4cbec0 records the first
    dword of its object (not the stack address);
  * hooks 0x4d9f90 (plain ret), 0x4d95f0 (ret 8; the float is recorded as bits) and 0x4dc970 (ret 4) record ECX and their arguments;
  * global 0x7003b0 is a cdecl stub that records its call (always set: the original breaks with int3 when it is null).
0x4d9bf0: this+0x50 heads a chain of 0 to 3 parents (through +0x50); each parent's +0x54 is 0 or a block whose +0xc chain has 0 to 3
entries with dword +0x23 drawn from 0x100021 and its neighbours.
0x4dc840: b is this in a fifth of the cases, a child in some, otherwise a separate object whose +0x54 is 0, a block with +4 zero or a
block with +4 set; this+0x54 is 0 or L (info +0x23 with or without 0x100000) whose +0x50 heads 0 to 2 children (through +0x60). The
recursion runs the original code; the children have +0x54 = 0."""
import struct
from pilot import S


def _blk(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(n))
    return a


def _common(c, nargs):
    e = c.emu

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=0, argbytes=0)
    logobj = _blk(c, 16)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _blk(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    hp = _blk(c, 32)
    e.wbytes(hp, bytes(c.rng.getrandbits(8) for _ in range(32)))

    def h2f0(em, a):
        buf = em.arg32(0)
        em.calllog.append(('h.4da2f0', None, em.reg('ecx'), (em.arg32(1),)))
        em.w32(buf, hp)
        em.ret(eax=buf, argbytes=8)
    e.hook(0x4da2f0, h2f0)
    e.hook(0x4cc1d0, lambda em, a: (em.calllog.append(('h.4cc1d0', None, None, (em.r32(em.reg('ecx')),))),
                                    em.ret(eax=em.r32(em.reg('ecx')) + 8)))
    e.hook(0x4cbec0, lambda em, a: (em.calllog.append(('h.4cbec0', None, None, (em.r32(em.reg('ecx')),))),
                                    em.ret(eax=0, argbytes=0)))
    e.hook(0x4d9f90, lambda em, a: (em.calllog.append(('h.4d9f90', None, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    e.hook(0x4d95f0, lambda em, a: (em.calllog.append(('h.4d95f0', None, em.reg('ecx'), (em.arg32(0), em.arg32(1)))),
                                    em.ret(eax=0, argbytes=8)))
    e.hook(0x4dc970, lambda em, a: (em.calllog.append(('h.4dc970', None, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4)))
    e.w32(0x7003b0, e.stub_fn('hook 0x7003b0', lambda em, a: (em.calllog.append(('hook.7003b0', None, None, ())),
                                                               em.ret(eax=0, argbytes=0))))


def _gen_9bf0(c):
    e = c.emu
    _common(c, 3)
    self_ = _blk(c, 0x100)
    fl = c.rng.getrandbits(32) & c.rng.choice([0, 0xffffffff, 0xffffbfff, 0x4000])
    e.w32(self_ + 0x3c, fl)
    prev = self_
    for _ in range(c.rng.choice([0, 1, 1, 2, 3])):
        p = _blk(c, 0x80)
        e.w32(prev + 0x50, p)
        if c.rng.random() < 0.8:
            blk = _blk(c, 0x40)
            e.w32(p + 0x54, blk)
            q = blk
            for _ in range(c.rng.choice([0, 1, 2, 3])):
                ent = _blk(c, 0x40)
                e.w32(ent + 0x23, c.rng.choice([0x100021, 0x100020, 0x100022, 0x100121, 0x000021,
                                                c.rng.getrandbits(32)]))
                e.w32(q + 0xc, ent)
                q = ent
        prev = p
    e.mu.ctl_flush_tb()
    return [self_]


def _gen_c840(c):
    e = c.emu
    _common(c, 4)

    def node():
        nd = _blk(c, 0x80)
        e.w32(nd + 0x3c, c.rng.getrandbits(32) & c.rng.choice([0, 0x40000, 0xffffffff, 0xfffbffff, 0x40040000]))
        return nd
    self_ = node()
    kids = []
    if c.rng.random() < 0.6:
        L = _blk(c, 0x80)
        info = _blk(c, 0x40)
        e.w32(info + 0x23, c.rng.choice([0x100000, 0x100000, 0x200002, 0x0fefffff, 0x100000 | c.rng.getrandbits(32)]))
        e.w32(L + 0xc, info)
        kids = [node() for _ in range(c.rng.choice([0, 1, 2, 2]))]
        for i, k in enumerate(kids):
            e.w32(k + 0x60, kids[i + 1] if i + 1 < len(kids) else 0)
        e.w32(L + 0x50, kids[0] if kids else 0)
        e.w32(self_ + 0x54, L)
    r = c.rng.random()
    if r < 0.2:
        b = self_
    elif r < 0.35 and kids:
        b = c.rng.choice(kids)
    else:
        b = _blk(c, 0x80)
        k = c.rng.choice([0, 1, 2])
        if k:
            pb = _blk(c, 0x20)
            if k == 2:
                e.w32(pb + 4, _blk(c, 0x10))
            e.w32(b + 0x54, pb)
    e.mu.ctl_flush_tb()
    return [self_, b]


S(0x4d9bf0, 'unnamed C-set 0x4d9bf0 thiscall', 'thiscall', None, ret=None, gen=_gen_9bf0,
  note='unclaimed-63 band batch 75; SEH frame not reproduced; cookie check not reproduced; helpers hooked')
S(0x4dc840, 'unnamed C-set 0x4dc840 thiscall', 'thiscall', None, ret=None, gen=_gen_c840,
  note='unclaimed-63 band batch 75; SEH frame not reproduced; cookie check not reproduced; recursion runs the original')
