"""specs_s1138.py - collision thread batch 1138 (GUESS name): 0x55c5b0. The list at [arg+4] has type [L+8] in 3..6 (the count the
accessor 0x5003d0 checks) and entries of 8 bytes; entry 1's byte +4 is the second type (3, 4 or other). The hook 0x7003b0 and
the logger 0x700390 (slot 0x20 opens a stream; slot 0x2c is cdecl) are recording fakes, set per case. The render manager's slot
0x114 (five stack words; the fifth is a pointer to a local dword, not logged, its content written) returns a per-case word.
Fake objects: entry 1's object (slot 0x34 returns a per-case value), this+0x1c (slot 0x134 records two arguments)."""
import struct
from pilot import S, F


def _tree(c):
    e, r = c.emu, c.rng
    ret34 = r.getrandbits(32)
    ret114 = r.getrandbits(16)

    # hook (cdecl, no arguments) and logger
    def hook(em, rr):
        em.calllog.append(('hook',))
        em.ret(argbytes=0)
    h = e.stub_fn('hook_7003b0_55c5b0', hook)
    e.w32(0x7003b0, h)

    def slot2c(em, rr):
        em.calllog.append(('2c', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(argbytes=0)
    svt = e.fake_vtable('stream_55c5b0', 0x30, {0x2c: slot2c})
    stream = e.alloc(0x40, 4)
    e.w32(stream, svt)

    def slot20(em, rr):
        em.calllog.append(('20', em.arg32(0), em.arg32(1)))
        em.ret(eax=stream, argbytes=8)
    lvt = e.fake_vtable('logger_55c5b0', 0x30, {0x20: slot20})
    logger = e.alloc(0x40, 4)
    e.w32(logger, lvt)
    e.w32(0x700390, logger)

    # entry 1's object: slot 0x34 (thiscall, no arguments) returns a per-case value
    def slot34(em, rr):
        em.ret(eax=ret34, argbytes=0)
    ovt = e.fake_vtable('obj34_55c5b0', 0x20, {0x34: slot34})
    obj1 = e.alloc(0x40, 4)
    e.w32(obj1, ovt)

    # this+0x1c: slot 0x134 (thiscall, two arguments) records them
    def slot134(em, rr):
        em.calllog.append(('134', em.reg('ecx') & 0xffffffff, em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)
    Ovt = e.fake_vtable('O_55c5b0', 0x60, {0x134: slot134})
    O = e.alloc(0x40, 4)
    e.w32(O, Ovt)

    # render manager: slot 0x114 (five words); writes the dword behind the fifth argument, returns a per-case word
    def slot114(em, rr):
        ptr = em.arg32(4)
        em.calllog.append(('114', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.wbytes(ptr, struct.pack('<I', ret114))
        em.ret(eax=ret114, argbytes=0x14)
    rvt = e.fake_vtable('rm_55c5b0', 0x60, {0x114: slot114})
    rm = e.alloc(0x40, 4)
    e.w32(rm, rvt)
    sysobj = e.alloc(0xc0, 16)
    e.wbytes(sysobj, bytes(r.getrandbits(8) for _ in range(0xc0)))
    e.w32(sysobj + 0x9b, rm)
    e.w32(0x70039c, sysobj)

    # the list: count t in 3..6, elements of 8 bytes at data (offset 0), entry 1 carries the second type byte
    t = r.choice([3, 4, 5, 6])
    bt = r.choice([3, 4, 5, 9])
    data = e.alloc(0x100, 16)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(0x100)))
    e.w32(data + 8 * 0, r.getrandbits(32))              # entry 0
    e.w32(data + 8 * 1, obj1)                           # entry 1: dword = the object (types 3 and 4 use it)
    e.wbytes(data + 8 * 1 + 4, bytes([bt]))
    e.w32(data + 8 * 2, r.getrandbits(32))              # entry 2: the value V
    base = e.alloc(0x20, 4)
    e.w32(base, data)
    e.w32(base + 8, 16)
    L = e.alloc(0x20, 4)
    e.w32(L, base)
    e.w32(L + 4, 0)
    e.w32(L + 8, t)
    arg = e.alloc(0x20, 4)
    e.w32(arg + 4, L)
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(self_ + 0x1c, O)
    return [self_, arg]


S(0x55c5b0, 'list-entry branches, logger and hook, render slot 0x114, then slot 0x134 of this+0x1c (name GUESS)', 'thiscall',
  None, gen=_tree, note='batch1138')
